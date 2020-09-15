#if !defined(_CONVEXHULL_MODEL_GRAHAM_H)
#define _CONVEXHULL_MODEL_GRAHAM_H
#include "ConvexHullModelVectorContainers.h"



class ConvexHullModelGraham : public ConvexHullModelVectorContainer
{
public:

	ConvexHullModelGraham(){};
	virtual ~ConvexHullModelGraham(){};
protected:
	virtual void RecalculateModel();
};

#endif