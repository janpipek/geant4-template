#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"

void ActionInitialization::Build() const
{
    // Add your actions

    // Add the primary generator (mandatory)
    SetUserAction(new PrimaryGeneratorAction());
}

void ActionInitialization::BuildForMaster() const
{
    // By default, don't do anything
}
