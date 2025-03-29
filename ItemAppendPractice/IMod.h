
#ifndef IMOD_H
#define IMOD_H

#include "BaseItem.h"
#include <string>

class BaseItem;

class IMod
{
public:
    virtual ~IMod() = default;
    virtual void Apply(BaseItem& item) const = 0;
    virtual std::string GetName() const = 0;
};

#endif


