#pragma once
#include <cstdlib>

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
    virtual void onModelChanged(const ConvexHullModelBase* p_model) = 0;
};

class ConvexHullModelBase
{
public:

    ConvexHullModelBase(){ my_observer = nullptr; };
	virtual ~ConvexHullModelBase(){
	
	};
	void setObserver(IViewObserver* observer)
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
		virtual Point2D getCurValue() const = 0;
		virtual bool hasMoreElements() const = 0;
		virtual void moveNext() = 0;
	protected:
		PointIteratorInterface(){}
	};

protected:
	virtual void addPointInternal(const Point2D& pnt) = 0;
	virtual void clearAllInternal() = 0;
	virtual PointIteratorInterface* CreateAllPointsInternalIterator() const = 0;
	virtual PointIteratorInterface* CreateConvexHullPointsInternalIterator()  const = 0;
public:

	void addPoint(const Point2D& pnt)
	{
		addPointInternal(pnt);
        if (my_observer != nullptr)
            my_observer->onModelChanged(this);
	}

	void clearAll()
	{
		clearAllInternal();
        if (my_observer != nullptr)
            my_observer->onModelChanged(this);
	}


	virtual size_t getNumPoints() const = 0;

	virtual size_t getNumConvexHullPoints() const = 0;

	friend class PointIterator;
};

enum class eIteratorType
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
	Point2D GetCurValue() const { return p_impl->getCurValue(); }
	bool HasMoreElements() const { return p_impl->hasMoreElements(); }
	void MoveNext() { p_impl->moveNext(); }
    PointIterator(const ConvexHullModelBase& model, eIteratorType iter_type)
    {
        if (iter_type == eIteratorType::THROUGH_ALL_POINTS)
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

