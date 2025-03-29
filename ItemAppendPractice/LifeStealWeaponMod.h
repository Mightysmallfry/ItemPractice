#ifndef WEAPONMOD_LIFESTEAL_H
#define WEAPONMOD_LIFESTEAL_H


#include "IMod.h"

class LifeStealWeaponMod : public IMod
{
public:

    float LifeStealIncrease = 0.1f; //10% increase

    static LifeStealWeaponMod* GetInStance()
    {
        static LifeStealWeaponMod instance;
        return &instance;
    }

    std::string GetName() const override
    {
        return "Life Steal Mod Name";
    }

    void Apply(BaseItem& item) const override
    {
        float currentLifesteal = item.GetLifeSteal();
        item.SetLifeSteal(currentLifesteal += LifeStealIncrease);
    }

private:
    LifeStealWeaponMod() = default;
    LifeStealWeaponMod(const LifeStealWeaponMod&) = delete;
    LifeStealWeaponMod& operator=(const LifeStealWeaponMod&) = delete;
};


#endif