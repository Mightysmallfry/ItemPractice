#ifndef WEAPONMODDEFINITION_H
#define WEAPONMODDEFINITION_H

#include "IMod.h"
#include "ItemStatsDefinition.h"

struct WeaponModDefinition
{
    WeaponModDefinition() = default;

    std::vector<const IMod*> mods;

    void AddMod(const IMod* mod) {
        mods.push_back(mod);
    }

    // Apply all mods to the WeaponComponent
    void ApplyMods(ItemStatsDefinition& itemStatsDefinition) const {
        for (const auto& mod : mods) {
            mod->Apply(itemStatsDefinition);
        }
    }
};

#endif