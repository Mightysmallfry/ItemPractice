#ifndef WEAPONMOD_CRITCHANCE_H
#define WEAPONMOD_CRITCHANCE_H


#include "IMod.h"

class CritChanceWeaponMod : public IMod
{
public:
    static CritChanceWeaponMod* GetInstance()
    {
        static CritChanceWeaponMod instance;
        return &instance;
    }

    std::string GetName() const override
    {
        return "Crit Chance Mod Name";
    }

    void Apply(ItemStatsDefinition& itemStats) const override
    {
        itemStats.CriticalChance += CriticalChanceIncrease;
    }

private:
    const float CriticalChanceIncrease = 0.1f;

    CritChanceWeaponMod() = default;
    CritChanceWeaponMod(const CritChanceWeaponMod&) = delete;
    CritChanceWeaponMod& operator=(const CritChanceWeaponMod&) = delete;
};


#endif
