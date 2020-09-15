#if !defined _CONVEXHULL_MODEL_JARVIS_H
#define _CONVEXHULL_MODEL_JARVIS_H
#include "ConvexHullModelVectorContainers.h"

class ConvexHullModelJarvis : public ConvexHullModelVectorContainer
{
public:

	ConvexHullModelJarvis(){};
	virtual ~ConvexHullModelJarvis(){};
protected:
	virtual void RecalculateModel();
};

#endif