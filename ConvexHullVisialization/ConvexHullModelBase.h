#if !defined _CONVEXHULL_MODEL_BASE_H
#define _CONVEXHULL_MODEL_BASE_H

#include "stdio.h"

class ConvexHullModelBase;
class PointIterator;
struct Point2D
{
	int x, y;
	Point2D() : x(0), y(0) {}
	Point2D(int x_, int y_) : x(x_), y(y_) {}
};

class IViewObserver
{
public:
	IViewObserver() {};
	virtual ~IViewObserver() {};
	virtual void OnModelChanged(const ConvexHullModelBase* p_model) = 0;
};

class ConvexHullModelBase
{
public:

	ConvexHullModelBase(){ my_observer = NULL; };
	virtual ~ConvexHullModelBase(){
	
	};
	void SetObserver(IViewObserver* observer)
	{
		my_observer = observer;
	}
private:
	IViewObserver* my_observer;
public:
	class PointIteratorInterface
	{
	public:
		virtual ~PointIteratorInterface(){}
		virtual Point2D GetCurValue() const = 0;
		virtual bool HasMoreElements() const = 0;
		virtual void MoveNext() = 0;
	protected:
		PointIteratorInterface(){}


	};




protected:
	virtual void AddPointInternal(const Point2D& pnt) = 0;
	virtual void ClearAllInternal() = 0;
	virtual PointIteratorInterface* CreateAllPointsInternalIterator() const = 0;
	virtual PointIteratorInterface* CreateConvexHullPointsInternalIterator()  const = 0;
public:

	void AddPoint(const Point2D& pnt)
	{
		AddPointInternal(pnt);
		if (my_observer != NULL)
			my_observer->OnModelChanged(this);
	}

	void ClearAll()
	{
		ClearAllInternal();
		if (my_observer != NULL)
			my_observer->OnModelChanged(this);
	}


	virtual size_t GetNumPoints() const = 0;

	virtual size_t GetNumConvexHullPoints() const = 0;

	friend class PointIterator;
};

enum IteratorType
{
	THROUGH_ALL_POINTS = 0,
	THROUGH_CONVEX_POINTS = 1
};

class PointIterator
{
public:
	~PointIterator(){
		delete p_impl;
	}
	Point2D GetCurValue() const { return p_impl->GetCurValue(); }
	bool HasMoreElements() const { return p_impl->HasMoreElements(); }
	void MoveNext() { p_impl->MoveNext(); }
	PointIterator(const ConvexHullModelBase& model, IteratorType iter_type)
	{
		if (iter_type == THROUGH_ALL_POINTS)
			p_impl = model.CreateAllPointsInternalIterator();
		else
			p_impl = model.CreateConvexHullPointsInternalIterator();
	}
	
private:
	
	PointIterator& operator = (const PointIterator& other);
	PointIterator(const PointIterator& other);

protected:
	ConvexHullModelBase::PointIteratorInterface* p_impl;


};



#endif

