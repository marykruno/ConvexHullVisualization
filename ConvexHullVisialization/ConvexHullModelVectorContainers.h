#if !defined _ConvexHullMODELVECTORCONTAINERS_H
#define _ConvexHullMODELVECTORCONTAINERS_H
#include "ConvexHullModelBase.h"
#include <vector>
using namespace std;


class ConvexHullModelVectorContainer : public ConvexHullModelBase
{
protected:
	vector<Point2D> pts;
	vector<int> convex_idx;
public:
	ConvexHullModelVectorContainer(){}
	virtual ~ConvexHullModelVectorContainer();

public:
	virtual size_t GetNumPoints() const
	{
		return pts.size();
	}

	virtual size_t GetNumConvexHullPoints() const
	{
		return convex_idx.size();
	}

protected:
	virtual void RecalculateModel() = 0;
	virtual void AddPointInternal(const Point2D& pnt)
	{
		pts.push_back(pnt);
		RecalculateModel();
	}
	virtual void ClearAllInternal()
	{
		pts.clear();
		convex_idx.clear();
	}
	virtual PointIteratorInterface* CreateAllPointsInternalIterator() const;
	virtual PointIteratorInterface* CreateConvexHullPointsInternalIterator()  const;

	
};

#endif