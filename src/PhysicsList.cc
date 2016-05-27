#include "PhysicsList.hh"

// Select some of the many physics constructors in Geant4
// These are just examples:
#include <G4HadronPhysicsFTFP_BERT.hh>
#include <G4EmStandardPhysics_option4.hh>

// You will probably want this:
#include <G4StepLimiterPhysics.hh>

PhysicsList::PhysicsList()
{
	// Here, you can (for example):

	//
	// a) add physics constructors
	RegisterPhysics(new G4HadronPhysicsFTFP_BERT());
	RegisterPhysics(new G4EmStandardPhysics_option4());
	RegisterPhysics(new G4StepLimiterPhysics());

	// b) set a reference physics list and use it
	// = create a pointer and reuse it in other methods
}

void PhysicsList::ConstructParticle()
{
	// Call parent method (using the constructors)
	G4VModularPhysicsList::ConstructParticle();
	
	// OR use the physics list
	// OR define some particles yourself
}

void PhysicsList::ConstructProcess()
{
	// Call parent method (using the constructors)
	G4VModularPhysicsList::ConstructProcess();

	// OR use the physics list
	// OR define some processes yourself
}

void PhysicsList::SetCuts()
{
	// Call parent method (using the constructors)
	G4VModularPhysicsList::SetCuts();
	
	// Add your specifics
}