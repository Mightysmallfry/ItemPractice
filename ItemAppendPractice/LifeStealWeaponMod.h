#ifndef WEAPONMOD_LIFESTEAL_H
#define WEAPONMOD_LIFESTEAL_H

#include "IMod.h"

class LifeStealWeaponMod : public IMod
{
public:
    static LifeStealWeaponMod* GetInstance()
    {
        static LifeStealWeaponMod instance;
        return &instance;
    }


    std::string GetName() const override
    {
        return "Life Steal Mod Name";
    }

    void Apply(ItemStatsDefinition& itemStats) const override
    {
        itemStats.LifeSteal += LifeStealIncrease;
    }

private:
    float LifeStealIncrease = 0.25f;

    LifeStealWeaponMod() = default;
    LifeStealWeaponMod(const LifeStealWeaponMod&) = delete;
    LifeStealWeaponMod& operator=(const LifeStealWeaponMod&) = delete;
};


#endif
