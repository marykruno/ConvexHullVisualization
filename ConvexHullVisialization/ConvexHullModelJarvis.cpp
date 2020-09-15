#include "stdafx.h"
#include "ConvexHullJarvis.h"
#include "ConvexHullModelJarvis.h"

void ConvexHullModelJarvis::RecalculateModel()
{
	BuildConvexHullJarvis<Point2D>(pts, convex_idx);
}
