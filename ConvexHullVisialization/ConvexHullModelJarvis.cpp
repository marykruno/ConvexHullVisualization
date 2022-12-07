#include "ConvexHullJarvis.h"
#include "ConvexHullModelJarvis.h"

void ConvexHullModelJarvis::RecalculateModel()
{
	buildConvexHullJarvis<Point2D>(pts, convex_idx);
}
