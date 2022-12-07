#pragma once
#include <QGraphicsScene>

class ConvexHullModelBase;
class ConvexHullRenderer;

class IRenderStyleObserver
{
public:
	IRenderStyleObserver() {};
	virtual ~IRenderStyleObserver() {};
    virtual void onRenderStyleChanged(const ConvexHullRenderer* p_renderer) = 0;
};

class ConvexHullRenderer
{
public:
	ConvexHullRenderer();
	virtual ~ConvexHullRenderer();
    void Draw(QGraphicsScene& scene, const ConvexHullModelBase& model);
    void resetColors();
    QColor GetPointsColor() const
	{
		return points_color;
	}

    QColor GetConvexHullColor() const
	{
		return convex_hull_color;
	}

    QColor GetBackgroundColor() const
	{
		return background_color;
	}

    void SetPointsColor(QColor color)
	{
		points_color = color;
		if (p_observer != NULL)
            p_observer->onRenderStyleChanged(this);
	}

    void SetConvexHullColor(QColor color)
	{
		convex_hull_color = color;
		if (p_observer != NULL)
            p_observer->onRenderStyleChanged(this);
	}

    void SetBackgroundColor(QColor color)
	{
		background_color = color;
		if (p_observer != NULL)
            p_observer->onRenderStyleChanged(this);
	}


	void SetObserver(IRenderStyleObserver* p_observer_)
	{
		p_observer = p_observer_;
	}

private:
    QColor points_color, convex_hull_color, background_color;
	IRenderStyleObserver* p_observer;
    const double points_rad = 6.0;

private:
    void DrawPoints(QGraphicsScene& scene, const ConvexHullModelBase& model);
    void DrawConvexHull(QGraphicsScene& scene, const ConvexHullModelBase& model);
    void DrawBackground(QGraphicsScene& scene);
};
