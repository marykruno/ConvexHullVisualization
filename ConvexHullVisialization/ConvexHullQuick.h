#include <vector>
#include <cmath>

using namespace std;

const double eps = 1e-8;


double Fabs(double a)
{
	if (a < 0)
		return -a;
	return a;
}

double IsEqual(double a, double b)
{
	return Fabs(a - b) <= eps;
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
		return Fabs(a*point.x + b*point.y + c) / sqrt(double(a*a) + b*b);
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


template <class T> void GetPointsLeftByLine(const vector<T> &ar_pts, const vector<int> &set_pts,
	Line<T> &ln, vector<int> &left_set_pts)
{
	for (size_t i = 0; i<set_pts.size(); i++)
	{
		if (ln.IsLeftFromLine(ar_pts[set_pts[i]]))
			left_set_pts.push_back(set_pts[i]);
	}
}

template <class T> void QuickHullHelper(const vector<T>& ar_pts, vector<int>& convex_hull_ind,
	int leftPos, int rightPos, const vector<int> &set_pts)
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

	vector<int> S11;
	Line<T> LT = Line<T>(ar_pts[leftPos], ar_pts[topPos]);
	//Form set of points, that lays on the left of line LT
	GetPointsLeftByLine(ar_pts, set_pts, LT, S11);
	QuickHullHelper(ar_pts, convex_hull_ind, leftPos, topPos, S11);

	vector<int> S12;
	Line<T> TR = Line<T>(ar_pts[topPos], ar_pts[rightPos]);
	//Form set of points, that lays on the left of line TR
	GetPointsLeftByLine(ar_pts, set_pts, TR, S12);
	QuickHullHelper(ar_pts, convex_hull_ind, topPos, rightPos, S12);
}

template <class T> void BuildConvexHullQuick(const vector<T>& ar_pts, vector<int>& convex_hull_ids)
{
	convex_hull_ids.clear();
	if (ar_pts.size() <= 2)
	{
		for (size_t i = 0; i < ar_pts.size(); ++i)
			convex_hull_ids.push_back(i);
		return;
	}

	// finding the leftmost and rightmost point
	int leftPos = 0, rightPos = 0;
	for (size_t i = 1; i<ar_pts.size(); i++)
	{
		if (Less(ar_pts[i].x, ar_pts[leftPos].x))
			leftPos = i;
		else if (Less(ar_pts[rightPos].x, ar_pts[i].x))
			rightPos = i;
	}

	Line<T> LR(ar_pts[leftPos], ar_pts[rightPos]);
	vector<int> S1; // points above line LR
	vector<int> S2; // points below line LR
	for (size_t i = 0; i<ar_pts.size(); i++)
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

