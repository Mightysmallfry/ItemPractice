#ifndef BASEITEM_H
#define BASEITEM_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "IMod.h"

class IMod;

enum class WeaponType {
    None,
    Sword,
    Bow,
    Staff,
    SwordAndShield,
    Polearm,
    Daggers,
    Hammer
};

struct BaseItemStats {
    std::string Name = "Centurion";
    int Damage = 0;
    float CriticalChance = 0.0f;  // Chance for critical hit
    float CriticalDamageMultiplier = 2.0f;  // Multiplier for critical hits
    float StatusChance = 0.0f;  // Chance for status effects (e.g., burn, freeze)
    float LifeSteal = 0.0f;
};

class BaseItem {
protected:

    BaseItemStats Stats;
    WeaponType WeaponTypeValue = WeaponType::None;
    std::unordered_map<std::string, int> MinorEffects;
    std::vector<IMod*> Mods;


public:
    BaseItem(std::string name, int damage);
    BaseItem(
        std::string name,
        WeaponType type,
        int damage,
        float criticalChance,
        float criticalDamageMultiplier,
        float statusChance,
        float lifeSteal);
    void AddProperty(const std::string& name, int value);
    void DisplayProperties() const;
    WeaponType GetWeaponType() const { return WeaponTypeValue; }


    void AddMod(IMod* mod);
    void ApplyMods();

    // Getter and Setter for Name
    std::string GetName() const { return Stats.Name; }
    void SetName(const std::string& name) { Stats.Name = name; }

    // Getter and Setter for Damage
    int GetDamage() const { return Stats.Damage; }
    void SetDamage(int damage) { Stats.Damage = damage; }

    // Getter and Setter for CriticalChance
    float GetCriticalChance() const { return Stats.CriticalChance; }
    void SetCriticalChance(float criticalChance) { Stats.CriticalChance = criticalChance; }

    // Getter and Setter for CriticalDamageMultiplier
    float GetCriticalDamageMultiplier() const { return Stats.CriticalDamageMultiplier; }
    void SetCriticalDamageMultiplier(float multiplier) { Stats.CriticalDamageMultiplier = multiplier; }

    // Getter and Setter for StatusChance
    float GetStatusChance() const { return Stats.StatusChance; }
    void SetStatusChance(float statusChance) { Stats.StatusChance = statusChance; }

    // Getter and Setter for LifeSteal
    float GetLifeSteal() const { return Stats.LifeSteal; }
    void SetLifeSteal(float lifeSteal) { Stats.LifeSteal = lifeSteal; }

};


#endif

