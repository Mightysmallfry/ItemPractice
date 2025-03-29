#include "BaseItem.h"

BaseItem::BaseItem(std::string name, int damage) {
    Stats.Name = name;
    Stats.Damage = damage;
}

BaseItem::BaseItem(std::string name, 
    WeaponType type, 
    int damage,
    float criticalChance,
    float criticalDamageMultiplier, 
    float statusChance,
    float lifeSteal) {

    Stats.Name = name;
    Stats.Damage = damage;
    Stats.CriticalChance = criticalChance;
    Stats.CriticalDamageMultiplier = criticalDamageMultiplier;
    Stats.StatusChance = statusChance;
    Stats.LifeSteal = lifeSteal;
    WeaponTypeValue = type;
}


void BaseItem::AddProperty(const std::string& name, int value)
{
    MinorEffects[name] = value;
}
void BaseItem::DisplayProperties() const {
    std::cout << "Weapon Name: " << Stats.Name << "\n";
    std::cout << "Weapon Type: ";
    switch (WeaponTypeValue) {
    case WeaponType::None: std::cout << "None"; break;
    case WeaponType::Sword: std::cout << "Sword"; break;
    case WeaponType::Bow: std::cout << "Bow"; break;
    case WeaponType::Staff: std::cout << "Staff"; break;
    case WeaponType::SwordAndShield: std::cout << "Sword and Shield"; break;
    case WeaponType::Polearm: std::cout << "Polearm"; break;
    case WeaponType::Daggers: std::cout << "Daggers"; break;
    case WeaponType::Hammer: std::cout << "Hammer"; break;
    }
    std::cout << "\n";

    std::cout << "Base Stats:\n";
    std::cout << "Damage: " << Stats.Damage << "\n";
    std::cout << "Critical Chance: " << Stats.CriticalChance * 100 << "%\n";
    std::cout << "Critical Damage Multiplier: " << Stats.CriticalDamageMultiplier << "x\n";
    std::cout << "Status Chance: " << Stats.StatusChance * 100 << "%\n";

    if (!MinorEffects.empty()) {
        std::cout << "Additional Properties:\n";
        for (const auto& prop : MinorEffects) {
            std::cout << prop.first << ": +" << prop.second << "\n";
        }
    }


    if (!Mods.empty()) {
        std::cout << "Mods Applied:\n";
        for (const auto& mod : Mods) {
            std::cout << mod->GetName() << "\n";  // Print the mod name using GetName
        }
    }
}


void BaseItem::AddMod(IMod* mod) {
    Mods.push_back(mod);  // Add mod to the list
}

void BaseItem::ApplyMods() {
    for (IMod* mod : Mods) {
        mod->Apply(*this);  // Apply each mod to the item
    }
}
