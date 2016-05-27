#include "PrimaryGeneratorAction.hh"

// Select one of the two header files (or keep them both)
#include <G4ParticleGun.hh>
#include <G4GeneralParticleSource.hh>

using namespace std;

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
	// Select your implementation here:

	// 1. GPS (no further commands necessary or recommended)
	fGenerator = make_shared<G4GeneralParticleSource>();

	// 2. ParticleGun
	// fGenerator = make_shared<G4ParticleGun>();
	// You can also set some parameters here.
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
	// By default, use the wrapped internal generator
	fGenerator->GeneratePrimaryVertex(anEvent);

	// Otherwise, implement your own...
}