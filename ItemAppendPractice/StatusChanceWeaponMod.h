#ifndef WEAPONMOD_STATUSCHANCE_H
#define WEAPONMOD_STATUSCHANCE_H


#include "IMod.h"

class StatusChanceWeaponMod : public IMod
{
public:
    static StatusChanceWeaponMod* GetInstance()
    {
        static StatusChanceWeaponMod instance;
        return &instance;
    }


    std::string GetName() const override
    {
        return "Status Chance Mod Name";
    }

    void Apply(ItemStatsDefinition& itemStats) const override
    {
        itemStats.StatusChance += StatusChanceIncrease;
    }


private:
    const float StatusChanceIncrease = 0.3f;
    StatusChanceWeaponMod() = default;
    StatusChanceWeaponMod(const StatusChanceWeaponMod&) = delete;
    StatusChanceWeaponMod& operator=(const StatusChanceWeaponMod&) = delete;

};

#endif
