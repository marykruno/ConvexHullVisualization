#if !defined _CONVEXHULL_MODELQUICK_H
#define _CONVEXHULL_MODELQUICK_H
#include "ConvexHullModelVectorContainers.h"

class ConvexHullModelQuick : public ConvexHullModelVectorContainer
{
public:

	ConvexHullModelQuick(){};
	virtual ~ConvexHullModelQuick(){};
protected:
	virtual void RecalculateModel();
};



#endif