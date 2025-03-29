#ifndef WEAPONMOD_CRITCHANCE_H
#define WEAPONMOD_CRITCHANCE_H


#include "IMod.h"

class CritChanceWeaponMod : public IMod
{
public:

    float CriticalChanceIncrease = 0.1f;

    static CritChanceWeaponMod* GetInstance()
    {
        static CritChanceWeaponMod instance;
        return &instance;
    }

    std::string GetName() const override
    {
        return "Crit Chance Mod Name";
    }

    void Apply(BaseItem& item) const override
    {
        float currentCritChance = item.GetCriticalChance(); //Increase critical chance by 10%
        item.SetCriticalChance(currentCritChance += CriticalChanceIncrease);
    }

private:
    CritChanceWeaponMod() = default;
    CritChanceWeaponMod(const CritChanceWeaponMod&) = delete;
    CritChanceWeaponMod& operator=(const CritChanceWeaponMod&) = delete;
};


#endif
