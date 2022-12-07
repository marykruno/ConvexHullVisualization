#pragma once
#include "ConvexHullModelVectorContainers.h"

class ConvexHullModelJarvis : public ConvexHullModelVectorContainer
{
public:

	ConvexHullModelJarvis(){};
	virtual ~ConvexHullModelJarvis(){};
protected:
	virtual void RecalculateModel();
};
