#include <vector>

// Select a proper single-/multithreaded run manager
#ifdef G4MULTITHREADED
    #include <G4MTRunManager.hh>
    using RunManager = G4MTRunManager;
#else
    #include <G4RunManager.hh>
    using RunManager = G4RunManager;
#endif

#ifdef G4VIS_USE
    #include <G4VisExecutive.hh>
#endif

#ifdef G4UI_USE
    #include <G4UIExecutive.hh>
#endif

#include <G4String.hh>
#include <G4UImanager.hh>
#include <G4ScoringManager.hh>

#include "ActionInitialization.hh"
#include "DetectorConstruction.hh"
#include "PhysicsList.hh"

using namespace std;

int main(int argc, char** argv)
{
    vector<G4String> macros;    
    bool interactive = false;

    // Parse command line arguments
    if  (argc == 1)
    {
        interactive = true;
    }   
    else
    {
        for (int i = 1; i < argc; i++)
        {
            G4String arg = argv[i];
            if (arg == "-i" || arg == "--interactive")
            {
                interactive = true;
                continue;
            }
            else
            {
                macros.push_back(arg);
            }                      
        }
    }

    auto runManager = new RunManager();

    #ifdef G4VIS_USE
        G4VisManager* visManager = new G4VisExecutive("quiet");
        visManager->SetVerboseLevel(0);    // Default, you can always override this using macro commands
        visManager->Initialize();
    #endif  

    runManager->SetUserInitialization(new PhysicsList());
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(new ActionInitialization());

    // If you want to use scoring, uncomment the following line:
    /* G4ScoringManager::GetScoringManager() */

    #ifdef G4UI_USE
        G4UIExecutive* ui;
        if (interactive)
        {
            ui = new G4UIExecutive(argc, argv);
        }
    #endif

    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    for (auto macro : macros)
    {
        G4String command = "/control/execute ";
        UImanager->ApplyCommand(command + macro);
    }    

    #ifdef G4UI_USE
        if (interactive)
        {
            ui->SessionStart();
            delete ui;
        }
    #endif

    delete runManager;
    return 0;
}