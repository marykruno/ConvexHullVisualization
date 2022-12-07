#pragma once
#include "ConvexHullModelVectorContainers.h"

class ConvexHullModelGraham : public ConvexHullModelVectorContainer
{
public:

	ConvexHullModelGraham(){};
	virtual ~ConvexHullModelGraham(){};
protected:
	virtual void RecalculateModel();
};
