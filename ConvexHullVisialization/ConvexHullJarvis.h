#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <iostream>

using namespace std;

template <class T> int SignOfAreaTriangle(T a, T b, T c)
{
	return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y);
};

template <class T> bool IsPointInRectangle(T point, T first, T last)
{
	return (first.x <= point.x) && (point.x <= last.x) && (first.y <= point.y) && (point.y <= last.y);
};


template <class T> void BuildConvexHullJarvis(const vector<T> & ar_pts, vector<int> & convex_hull_ind)
{
	convex_hull_ind.clear();
	if (ar_pts.size() <= 2)
	{
		for (int i = 0; i < int(ar_pts.size()); ++i)
			convex_hull_ind.push_back(i);
		return;
	}
	// we need to find most left bottom point

	int ind_left_bottom = 0;
	T left_bottom_pnt = ar_pts[0];
	for (int i = 1; i < int(ar_pts.size()); ++i)
	{
		if (ar_pts[i].y < left_bottom_pnt.y || (ar_pts[i].y == left_bottom_pnt.y && ar_pts[i].x < left_bottom_pnt.x))
		{
			ind_left_bottom = i;
			left_bottom_pnt = ar_pts[i];
		}
	}
	// so now this is index of most left bottom point ind_left_bottom


	int first_ind = ind_left_bottom;
	int cur_ind = ind_left_bottom;

	do{

		int next_ind = (cur_ind + 1) % int(ar_pts.size());
		for (int i = 0; i<int(ar_pts.size()); ++i)
		{
			int sign = SignOfAreaTriangle(ar_pts[cur_ind], ar_pts[next_ind], ar_pts[i]);
			if (sign < 0)
			{
				next_ind = i;
			}
			else if (sign == 0)
			{
				if (IsPointInRectangle(ar_pts[next_ind], ar_pts[cur_ind], ar_pts[i]))
					next_ind = i;
			}
		}
		cur_ind = next_ind;
		convex_hull_ind.push_back(next_ind);


	} while (cur_ind != first_ind);



}