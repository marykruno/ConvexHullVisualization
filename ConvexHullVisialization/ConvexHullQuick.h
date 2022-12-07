#include <math.h>
#include <vector>
#include <limits>

double IsEqual(double a, double b)
{
    return fabs(a - b) <= std::numeric_limits<double>::epsilon();
}

bool Less(double a, double b)
{
	return !IsEqual(a, b) && a<b;
}

template <class T> struct Line
{
	int a, b, c;
	Line(){}
	Line(T point_1, T point_2)
	{
		a = point_2.y - point_1.y;
		b = point_1.x - point_2.x;
		c = -(a*point_1.x + b*point_1.y);
	}

	double dist(T point)
    {
        return fabs(a*point.x + b*point.y + c) / sqrt(double(a*a) + b*b);
	}

	bool IsLeftFromLine(T point)
	{
		return a*point.x + b*point.y + c < 0;
	}

	bool IsRightFromLine(T point)
	{
		return a*point.x + b*point.y + c > 0;
	}

};


template <class T> void GetPointsLeftByLine(const std::vector<T> &ar_pts, const std::vector<int> &set_pts,
                         Line<T> &ln, std::vector<int> &left_set_pts)
{
	for (size_t i = 0; i<set_pts.size(); i++)
	{
		if (ln.IsLeftFromLine(ar_pts[set_pts[i]]))
			left_set_pts.push_back(set_pts[i]);
	}
}

template <class T> void QuickHullHelper(const std::vector<T>& ar_pts, std::vector<int>& convex_hull_ind,
                     int leftPos, int rightPos, const std::vector<int> &set_pts)
{
	if (set_pts.size() == 0)
	{
		convex_hull_ind.push_back(rightPos);
		return;
	}
	Line<T> LR(ar_pts[leftPos], ar_pts[rightPos]);
	
	int topPos = set_pts[0];
	Line<T> topLine = Line<T>(ar_pts[leftPos], ar_pts[topPos]);
	double maxDist = LR.dist(ar_pts[topPos]);

	for (size_t i = 1; i<set_pts.size(); i++)
	{
		if (set_pts[i] != leftPos && set_pts[i] != rightPos)
		{
			double curDist = LR.dist(ar_pts[set_pts[i]]);
			if (IsEqual(maxDist, curDist))
			{
				if (topLine.IsLeftFromLine(ar_pts[set_pts[i]]))
				{
					topPos = set_pts[i];
					topLine = Line<T>(ar_pts[leftPos], ar_pts[topPos]);
				}
			}
			if (Less(maxDist, curDist))
			{
				maxDist = curDist;
				topPos = set_pts[i];
				topLine = Line<T>(ar_pts[leftPos], ar_pts[topPos]);
			}
		}
	}

    std::vector<int> S11;
	Line<T> LT = Line<T>(ar_pts[leftPos], ar_pts[topPos]);
	//Form set of points, that lays on the left of line LT
	GetPointsLeftByLine(ar_pts, set_pts, LT, S11);
	QuickHullHelper(ar_pts, convex_hull_ind, leftPos, topPos, S11);

    std::vector<int> S12;
	Line<T> TR = Line<T>(ar_pts[topPos], ar_pts[rightPos]);
	//Form set of points, that lays on the left of line TR
	GetPointsLeftByLine(ar_pts, set_pts, TR, S12);
	QuickHullHelper(ar_pts, convex_hull_ind, topPos, rightPos, S12);
}

template <class T> void BuildConvexHullQuick(const std::vector<T>& ar_pts, std::vector<int>& convex_hull_ids)
{
	convex_hull_ids.clear();
	if (ar_pts.size() <= 2)
	{
		for (int i = 0; i < (int)ar_pts.size(); ++i)
			convex_hull_ids.push_back(i);
		return;
	}

	// finding the leftmost and rightmost point
	int leftPos = 0, rightPos = 0;
	for (int i = 1; i < (int)ar_pts.size(); i++)
	{
		if (Less(ar_pts[i].x, ar_pts[leftPos].x))
			leftPos = i;
		else if (Less(ar_pts[rightPos].x, ar_pts[i].x))
			rightPos = i;
	}

    Line<T> LR(ar_pts[leftPos], ar_pts[rightPos]);
    std::vector<int> S1; // points above line LR
    std::vector<int> S2; // points below line LR
	for (int i = 0; i< (int)ar_pts.size(); i++)
	{
		if (i != leftPos && i != rightPos)
		{
			if (LR.IsLeftFromLine(ar_pts[i]))
				S1.push_back(i);
			else if (LR.IsRightFromLine(ar_pts[i]))
				S2.push_back(i);
		}
	}
	QuickHullHelper(ar_pts, convex_hull_ids, leftPos, rightPos, S1);
	QuickHullHelper(ar_pts, convex_hull_ids, rightPos, leftPos, S2);
}

