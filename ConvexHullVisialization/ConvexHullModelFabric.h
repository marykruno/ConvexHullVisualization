#pragma once
#include "utilities.h"
#include "ConvexHullModelBase.h"

class ConvexHullModelFabric
{
public:
    static ConvexHullModelBase* CreateModel(eConvexHullAlg alg);
};

