#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <iostream>
#include <unordered_map>

#include "Entity.h"
#include "ItemStatsDefinition.h"
#include "WeaponModDefinition.h"


//Pairs stats, mods and entities together
class EntityManager
{
public:
    Entity CreateEntity();

    //This way we can use new
    void AddWeaponStats(Entity entity, std::string name, int damage, float critChance, float critMultiplier, float statusChance, float lifeSteal);
    void AddWeaponMods(Entity entity, const IMod* mod);

    ItemStatsDefinition* GetEntityStats(Entity entity) { return GetEntityStats(entity.Id()); }
    ItemStatsDefinition* GetEntityStats(uint32_t entityId);

    WeaponModDefinition* GetEntityMods(Entity entity) { return GetEntityMods(entity.Id()); }
    WeaponModDefinition* GetEntityMods(uint32_t entityId);

    std::unordered_map<uint32_t, Entity>& GetEntities() { return entities; }

    void DisplayEntity(Entity entity) { DisplayEntity(entity.Id()); }
    void DisplayEntity(uint32_t entityId);

private:
    uint32_t nextEntityId = 1;

    //These two maps are essentially a database of an entity and their respective properties
    std::unordered_map<uint32_t, ItemStatsDefinition> entityStats;
    std::unordered_map<uint32_t, WeaponModDefinition> entityMods;
    std::unordered_map<uint32_t, Entity> entities;

};


#endif


