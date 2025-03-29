#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>

class Entity
{
public:
    explicit Entity(uint32_t id) : Id_(id) {}
    uint32_t Id() const { return Id_; }

private:
    uint32_t Id_;
};

#endif

