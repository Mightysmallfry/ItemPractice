#ifndef MODSYSTEM_H
#define MODSYSTEM_H

#include <memory>

#include "EntityManager.h"
#include "IMod.h"


class ModSystem
{
public:

    void ProcessMods(EntityManager& entityManager);

};

#endif