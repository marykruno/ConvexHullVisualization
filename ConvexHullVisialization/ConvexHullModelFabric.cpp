#include "ConvexHullModelFabric.h"
#include "ConvexHullModelGraham.h"
#include "ConvexHullModelJarvis.h"
#include "ConvexHullModelQuick.h"

ConvexHullModelBase* ConvexHullModelFabric::CreateModel(eConvexHullAlg alg)
{
    if (alg == eConvexHullAlg::GRAHAM)
    return new ConvexHullModelGraham();
    if (alg == eConvexHullAlg::JARVIS)
        return new ConvexHullModelJarvis();
    if (alg == eConvexHullAlg::QUICK)
		return new ConvexHullModelQuick();
    return nullptr;
}

