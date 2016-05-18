#ifndef PHYSICS_LIST_HH
#define PHYSICS_LIST_HH

#include <G4VModularPhysicsList.hh>

class PhysicsList : public G4VModularPhysicsList
{
public:
	PhysicsList();

    void ConstructParticle() override;

    void ConstructProcess() override;

    void SetCuts() override;
};

#endif