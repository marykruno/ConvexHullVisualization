#include "ConvexHullModelVectorContainers.h"

class AllPointsIterator : public ConvexHullModelBase::PointIteratorInterface
{
private:
    const std::vector<Point2D>& ar_pts;
	size_t ind;
public:
    AllPointsIterator(const std::vector<Point2D>& ar_pts_) : ar_pts(ar_pts_), ind(0) {}
	virtual ~AllPointsIterator(){}
	virtual Point2D getCurValue() const
	{
		Point2D ret;
		if (ind < ar_pts.size())
			ret = ar_pts[ind];

		return ret;
	}
	virtual bool hasMoreElements() const
	{
		return ind < ar_pts.size();
	}
	virtual void moveNext()
	{
		if (ind < ar_pts.size())
			++ind;
	}

};
class ConvexHullPointsIterator : public ConvexHullModelBase::PointIteratorInterface
{
private:
    const std::vector<Point2D>& ar_pts;
    const std::vector<int>& ar_idx;
	size_t ind;
public:
    ConvexHullPointsIterator(const std::vector<Point2D>& ar_pts_, const std::vector<int>& ar_idx_) : ar_pts(ar_pts_), ar_idx(ar_idx_), ind(0) {}
	virtual ~ConvexHullPointsIterator(){}
	virtual Point2D getCurValue() const
	{
		Point2D ret;
		if (ind < ar_idx.size())
			ret = ar_pts[ar_idx[ind]];

		return ret;
	}
	virtual bool hasMoreElements() const
	{
		return ind < ar_idx.size();
	}
	virtual void moveNext()
	{
		if (ind < ar_idx.size())
			++ind;
	}


};


ConvexHullModelBase::PointIteratorInterface* ConvexHullModelVectorContainer::CreateAllPointsInternalIterator() const
{
	return new AllPointsIterator(pts);
}
ConvexHullModelBase::PointIteratorInterface* ConvexHullModelVectorContainer::CreateConvexHullPointsInternalIterator()  const
{
	return new ConvexHullPointsIterator(pts, convex_idx);
}

ConvexHullModelVectorContainer::~ConvexHullModelVectorContainer()
{

}
