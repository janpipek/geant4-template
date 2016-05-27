#ifndef PRIMARY_GENERATOR_ACTION_HH
#define PRIMARY_GENERATOR_ACTION_HH

#include <memory>
#include <G4VUserPrimaryGeneratorAction.hh>

class G4VPrimaryGenerator;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
	PrimaryGeneratorAction();

    void GeneratePrimaries(G4Event* anEvent) override;

private:
	// Remove if you want to implement the generator from scratch
	std::shared_ptr<G4VPrimaryGenerator> fGenerator;
};

#endif