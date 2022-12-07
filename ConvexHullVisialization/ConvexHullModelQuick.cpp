#include "ConvexHullModelQuick.h"
#include "ConvexHullQuick.h"

void ConvexHullModelQuick::RecalculateModel()
{
	BuildConvexHullQuick<Point2D>(pts, convex_idx);
}
