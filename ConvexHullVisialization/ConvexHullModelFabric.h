#if !defined _CONVEXHULL_MODEL_FABRIC_H

#define _CONVEXHULL_MODEL_FABRIC_H
#include "ConvexHullModelBase.h"

enum ConvexHullAlg {
	GRAHAM = 0, 
	JARVIS = 1,
	QUICK = 2,
	LAST_VALUE = 3
};

class ConvexHullModelFabric
{
public:
	static ConvexHullModelBase* CreateModel(ConvexHullAlg alg);
};


#endif