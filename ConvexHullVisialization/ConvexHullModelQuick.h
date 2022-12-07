#pragma once
#include "ConvexHullModelVectorContainers.h"

class ConvexHullModelQuick : public ConvexHullModelVectorContainer
{
public:

	ConvexHullModelQuick(){};
	virtual ~ConvexHullModelQuick(){};
protected:
	virtual void RecalculateModel();
};
