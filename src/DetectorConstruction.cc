#include "DetectorConstruction.hh"

#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4NistManager.hh>
#include <G4SystemOfUnits.hh>
#include <G4VisAttributes.hh>

#include <G4Box.hh>
// #include <G4Tubs.hh>
// #include <G4Sphere.hh>
// #include <G4Orb.hh>

G4VPhysicalVolume* DetectorConstruction::Construct() 
{
	// You have to implement this
	auto nist = G4NistManager::Instance();

	// Example world construction
	G4double worldSizeX = 10 * m;
	G4double worldSizeY = 10 * m;
	G4double worldSizeZ = 10 * m;

	auto worldBox = new G4Box("world", worldSizeX / 2, worldSizeY / 2, worldSizeZ / 2);
	auto worldLog = new G4LogicalVolume(worldBox, nist->FindOrBuildMaterial("G4_AIR"), "world");
	auto worldPhys = new G4PVPlacement(nullptr, {}, worldLog, "world", nullptr, false, 0);

	// Return the world volume
	return worldPhys;
}

// Implement the following only if you have fields / sensitive detector
/*
void DetectorConstruction::ConstructSDandField()
{

}
*/