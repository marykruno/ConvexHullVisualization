#if !defined _CONVEXHULL_RENDERER_H
#define _CONVEXHULL_RENDERER_H

class ConvexHullModelBase;
class ConvexHullRenderer;

class IRenderStyleObserver
{
public:
	IRenderStyleObserver() {};
	virtual ~IRenderStyleObserver() {};
	virtual void OnRenderStyleChanged(const ConvexHullRenderer* p_renderer) = 0;
};

class ConvexHullRenderer
{
public:
	ConvexHullRenderer();
	virtual ~ConvexHullRenderer();
	void Draw(CDC& dc, const CRect& cli_rect, const ConvexHullModelBase& model);

	COLORREF GetPointsColor() const
	{
		return points_color;
	}

	COLORREF GetConvexHullColor() const
	{
		return convex_hull_color;
	}

	COLORREF GetBackgroundColor() const
	{
		return background_color;
	}

	void SetPointsColor(COLORREF color)
	{
		points_color = color;
		if (p_observer != NULL)
			p_observer->OnRenderStyleChanged(this);
	}

	void SetConvexHullColor(COLORREF color)
	{
		convex_hull_color = color;
		if (p_observer != NULL)
			p_observer->OnRenderStyleChanged(this);
	}

	void SetBackgroundColor(COLORREF color)
	{
		background_color = color;
		if (p_observer != NULL)
			p_observer->OnRenderStyleChanged(this);
	}


	void SetObserver(IRenderStyleObserver* p_observer_)
	{
		p_observer = p_observer_;
	}

private:
	COLORREF points_color, convex_hull_color, background_color;
	IRenderStyleObserver* p_observer;

private:
	void DrawPoints(CDC& dc, const ConvexHullModelBase& model);
	void DrawConvexHull(CDC& dc, const ConvexHullModelBase& model);
	void DrawBackground(CDC& dc, const CRect& cli_rect);
};
#endif