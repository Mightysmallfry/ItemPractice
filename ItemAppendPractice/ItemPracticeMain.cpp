// ItemAppendPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "CritChanceWeaponMod.h"
#include "Entity.h"
#include "EntityManager.h"
#include "LifeStealWeaponMod.h"
#include "ModSystem.h"


int main() {

    EntityManager entityManager;
    ModSystem modSystem;
    Entity entity = entityManager.CreateEntity();
    std::cout << "Created entity with ID: " << entity.Id() << "\n";

    entityManager.AddWeaponStats(entity, "Incursio", 50, 0.1f, 2.0f, 0.35f, 0.0f);

    entityManager.DisplayEntity(entity);


    //Currently must always process after adding.
    entityManager.AddWeaponMods(entity, CritChanceWeaponMod::GetInstance());
    entityManager.AddWeaponMods(entity, LifeStealWeaponMod::GetInstance());
    modSystem.ProcessMods(entityManager);


    entityManager.DisplayEntity(entity);

}

