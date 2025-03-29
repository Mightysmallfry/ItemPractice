#include "ModSystem.h"

#include <memory>

void ModSystem::ProcessMods(EntityManager& entityManager)
{
    for (auto& entityPair : entityManager.GetEntities())
    {
        const Entity& entity = entityPair.second;

        auto* itemStats = entityManager.GetEntityStats(entity.Id());
        if (!itemStats)
            continue;

        auto* itemMods = entityManager.GetEntityMods(entity.Id());
        if (!itemMods)
            continue;

        itemMods->ApplyMods(*itemStats);
    }
}


