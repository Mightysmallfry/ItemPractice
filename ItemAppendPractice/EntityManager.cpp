#include "EntityManager.h"

Entity EntityManager::CreateEntity()
{
    Entity entity(nextEntityId++);
    entities.emplace(entity.Id(),entity);
    return entity;
}

void EntityManager::AddWeaponStats(Entity entity,std::string name, int damage, float critChance, float critMultiplier, float statusChance, float lifeSteal)
{
    entityStats.emplace(entity.Id(), ItemStatsDefinition(name, damage, critChance, critMultiplier, statusChance, lifeSteal));
}

void EntityManager::AddWeaponMods(Entity entity, const IMod* mod)
{
    //If the modlist already exists just add it, no need to make a new modlist for the entities that already have one.
    auto it = entityMods.find(entity.Id());
    if (it != entityMods.end())
    {
        it->second.AddMod(mod);
    }
    else
    {
        WeaponModDefinition newModDef;
        newModDef.AddMod(mod);
        entityMods.emplace(entity.Id(), std::move(newModDef));
    }
}

ItemStatsDefinition* EntityManager::GetEntityStats(uint32_t entityId)
{
    auto it = entityStats.find(entityId);
    if (it != entityStats.end())
    {
        return &it->second;
    }
    return nullptr;
}

WeaponModDefinition* EntityManager::GetEntityMods(uint32_t entityId)
{
    auto it = entityMods.find(entityId);
    if (it != entityMods.end())
    {
        return &it->second;
    }
    return nullptr;
}

void EntityManager::DisplayEntity(uint32_t entityId)
{
    auto stats = GetEntityStats(entityId);
    if (!stats)
    {
        std::cout << "Entity " << entityId << " has no stats.\n";
        return;
    }

    std::cout << "Entity ID: " << entityId << "\n";
    std::cout << "  Name: " << stats->Name << "\n";
    std::cout << "  Damage: " << stats->Damage << "\n";
    std::cout << "  Crit Chance: " << stats->CriticalChance << "\n";
    std::cout << "  Crit Multiplier: " << stats->CriticalDamageMultiplier << "\n";
    std::cout << "  Status Chance: " << stats->StatusChance << "\n";
    std::cout << "  Life Steal: " << stats->LifeSteal << "\n";

    auto mods = GetEntityMods(entityId);
    if (mods && !mods->mods.empty())
    {
        std::cout << "  Mods:\n";
        for (const auto* mod : mods->mods)
        {
            std::cout << "    - " << mod->GetName() << "\n";
        }
    }
    else
    {
        std::cout << "  Mods: None\n";
    }
}
