#include <vector>
#include <algorithm>

using namespace std;

template <class T> class PolarAngleComparator
{
private:
	T origin;
	const vector<T> & ar_pts;
	// typedef  typename T::x tmp;

public:
	PolarAngleComparator(T origin_, const vector<T> & ar_pts_)
		: origin(origin_), ar_pts(ar_pts_)
	{}

	bool operator()(int first_ind, int second_ind)
	{
		T first = ar_pts[first_ind];
		first.x -= origin.x;
		first.y -= origin.y;

		T second = ar_pts[second_ind];
		second.x -= origin.x;
		second.y -= origin.y;

		if (first.x == 0 && first.y == 0)
			return true;
		if (second.x == 0 && second.y == 0)
			return false;
		//typedef typename T::CoorType cor_type;
		auto vect_prod = first.x*second.y - first.y*second.x;
		if (vect_prod > 0)
			return true;
		if (vect_prod < 0)
			return false;

		return (first.x*first.x + first.y*first.y) < (second.x*second.x + second.y*second.y);
	}

};

template <class T> bool RightRotation(T a, T b, T c)
{
	return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) <= 0;
};

template <class T> void BuildConvexHullGraham(const vector<T> & ar_pts, vector<int> & convex_hull_ind)
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
	for (size_t i = 1; i < ar_pts.size(); ++i)
	{
		if (ar_pts[i].y < left_bottom_pnt.y || (ar_pts[i].y == left_bottom_pnt.y && ar_pts[i].x < left_bottom_pnt.x))
		{
			ind_left_bottom = i;
			left_bottom_pnt = ar_pts[i];
		}
	}
	// so now this is index of most left bottom point ind_left_bottom
	vector<int> ar_ids(ar_pts.size());
	for (size_t i = 0; i < ar_pts.size(); ++i)
	{
		ar_ids[i] = i;
	}
	ar_ids[0] = ind_left_bottom;
	ar_ids[ind_left_bottom] = 0;
	PolarAngleComparator<T> polar_comp(left_bottom_pnt, ar_pts);
	vector<int>::iterator itr = ar_ids.begin();
	++itr;
	sort(itr, ar_ids.end(), polar_comp);

	convex_hull_ind.push_back(ar_ids[0]);
	convex_hull_ind.push_back(ar_ids[1]);

	for (size_t i = 2; i < ar_ids.size(); ++i)
	{
		while (convex_hull_ind.size() >= 2 && RightRotation<T>(
			ar_pts[*(convex_hull_ind.end() - 2)],
			ar_pts[*(convex_hull_ind.end() - 1)],
			ar_pts[ar_ids[i]]
			)
			)
		{
			convex_hull_ind.erase(convex_hull_ind.end() - 1);
		}
		convex_hull_ind.push_back(ar_ids[i]);
	}
}
