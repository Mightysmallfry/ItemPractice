#ifndef IMOD_H
#define IMOD_H

#include <string>

#include "ItemStatsDefinition.h"


class IMod
{
public:
    virtual ~IMod() = default;
    virtual std::string GetName() const = 0;
    virtual void Apply(ItemStatsDefinition& itemStats) const = 0;
};

#endif


