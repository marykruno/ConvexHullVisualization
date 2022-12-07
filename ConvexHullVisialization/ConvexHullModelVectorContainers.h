#pragma once
#include "ConvexHullModelBase.h"
#include <vector>


class ConvexHullModelVectorContainer : public ConvexHullModelBase
{
protected:
    std::vector<Point2D> pts;
    std::vector<int> convex_idx;
public:
	ConvexHullModelVectorContainer(){}
	virtual ~ConvexHullModelVectorContainer();

public:
	virtual size_t getNumPoints() const
	{
		return pts.size();
	}

	virtual size_t getNumConvexHullPoints() const
	{
		return convex_idx.size();
	}

protected:
	virtual void RecalculateModel() = 0;
	virtual void addPointInternal(const Point2D& pnt)
	{
		pts.push_back(pnt);
		RecalculateModel();
	}
	virtual void clearAllInternal()
	{
		pts.clear();
		convex_idx.clear();
	}
	virtual PointIteratorInterface* CreateAllPointsInternalIterator() const;
	virtual PointIteratorInterface* CreateConvexHullPointsInternalIterator()  const;

	
};
