// ItemAppendPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "CritChanceWeaponMod.h"
#include "Entity.h"
#include "EntityManager.h"
#include "LifeStealWeaponMod.h"
#include "ModSystem.h"
#include "StatusChanceWeaponMod.h"


int main() {

    EntityManager entityManager;
    ModSystem modSystem;
    Entity entity = entityManager.CreateEntity();
    std::cout << "Created entity with ID: " << entity.Id() << "\n";
    Entity entityTwo = entityManager.CreateEntity();
    std::cout << "Created entity with ID: " << entityTwo.Id() << "\n";

    entityManager.AddWeaponStats(entity, "Incursio", 50, 0.1f, 2.0f, 0.35f, 0.0f);
    entityManager.AddWeaponStats(entityTwo, "Gladiox", 15, 0.5f, 2.5f, 0.32f, 0.0f);


    entityManager.DisplayEntity(entity);


    //Currently must always process after adding, otherwise they will be added and not have their effects applied
    entityManager.AddWeaponMods(entity, CritChanceWeaponMod::GetInstance());
    entityManager.AddWeaponMods(entity, LifeStealWeaponMod::GetInstance());
    entityManager.AddWeaponMods(entityTwo, StatusChanceWeaponMod::GetInstance());

    modSystem.ProcessMods(entityManager);

    for (auto entityPair : entityManager.GetEntities())
    {
        entityManager.DisplayEntity(entityPair.second);
    }


}

