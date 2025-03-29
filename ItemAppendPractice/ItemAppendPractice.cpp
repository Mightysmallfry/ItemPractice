// ItemAppendPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "BaseItem.h"
#include "CritChanceWeaponMod.h"


int main() {
    BaseItem sword(
        "Flaming Sword", 
        WeaponType::Sword,
        10,
        0.1f,
        2.0f,
        0.2f,
        0.0f);
    sword.DisplayProperties();  // Will show the base stats

    sword.AddMod(CritChanceWeaponMod::GetInstance());  // Adding a crit chance mod
    sword.ApplyMods();
    sword.DisplayProperties();  // Will show the mod names
    return 0;
}

