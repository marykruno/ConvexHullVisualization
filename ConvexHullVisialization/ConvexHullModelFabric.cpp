#include "stdafx.h"
#include "ConvexHullModelFabric.h"
#include "ConvexHullModelGraham.h"
#include "ConvexHullModelJarvis.h"
#include "ConvexHullModelQuick.h"



ConvexHullModelBase* ConvexHullModelFabric::CreateModel(ConvexHullAlg alg)
{
	if (alg == GRAHAM)
	return new ConvexHullModelGraham();
	if (alg == JARVIS)
		return new ConvexHullModelJarvis();
	if (alg == QUICK)
		return new ConvexHullModelQuick();
	return NULL;
}

