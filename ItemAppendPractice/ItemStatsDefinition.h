#ifndef ITEMSTATSDEFINITION_H
#define ITEMSTATSDEFINITION_H

#include <string>

struct ItemStatsDefinition
{
    std::string Name;
    int Damage;
    float CriticalChance; // Chance for critical hit
    float CriticalDamageMultiplier;  // Multiplier for critical hits
    float StatusChance;  // Chance for status effects (e.g., burn, freeze)
    float LifeSteal; //Percentage of the damage that becomes additional healing

    ItemStatsDefinition(std::string name, int damage, float critChance, float critMultiplier, float statusChance, float lifeSteal)
        : Name(name), Damage(damage), CriticalChance(critChance), CriticalDamageMultiplier(critMultiplier),
    StatusChance(statusChance), LifeSteal(lifeSteal) {}
};


#endif