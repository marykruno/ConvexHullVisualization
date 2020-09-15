#include "stdafx.h"
#include "ConvexHullModelGraham.h"
#include "ConvexHullGraham.h"

void ConvexHullModelGraham::RecalculateModel()
{
	BuildConvexHullGraham<Point2D>(pts, convex_idx);
}



