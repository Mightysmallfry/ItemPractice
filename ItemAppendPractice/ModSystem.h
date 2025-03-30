#ifndef MODSYSTEM_H
#define MODSYSTEM_H

#include <memory>

#include "EntityManager.h"
#include "IMod.h"

//Processes mod effects and applies them throughout the world etc.
class ModSystem
{
public:

    void ProcessMods(EntityManager& entityManager);

};

#endif