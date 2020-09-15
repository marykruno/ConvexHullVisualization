#include "stdafx.h"
#include "ConvexHullModelBase.h"
#include "ConvexHullRendrer.h"

using namespace std;


ConvexHullRenderer::ConvexHullRenderer()
{
	points_color = RGB(0, 0, 0);
	convex_hull_color = RGB(255, 0, 0);
	background_color = RGB(255, 255, 255);
	p_observer = NULL;

}

ConvexHullRenderer::~ConvexHullRenderer()
{

}


void ConvexHullRenderer::DrawPoints(CDC& dc, const ConvexHullModelBase& model)
{
	if (model.GetNumPoints() == 0)
		return;
	CRgn marker;
	marker.CreateEllipticRgn(-6, -6, 6, 6);
	CBrush points_brush(points_color);
	PointIterator iter(model, THROUGH_ALL_POINTS);
	Point2D prev_pnt = iter.GetCurValue();
	marker.OffsetRgn(prev_pnt.x, prev_pnt.y);
	dc.FillRgn(&marker, &points_brush);
	iter.MoveNext();
	while (iter.HasMoreElements())
	{
		Point2D cur_pnt = iter.GetCurValue();
		marker.OffsetRgn(cur_pnt.x - prev_pnt.x, cur_pnt.y - prev_pnt.y);
		dc.FillRgn(&marker, &points_brush);
		prev_pnt = cur_pnt;
		iter.MoveNext();
	}
	
}


void ConvexHullRenderer::DrawConvexHull(CDC& dc, const ConvexHullModelBase& model)
{
	if (model.GetNumConvexHullPoints() <= 1)
		return;
	PointIterator iter(model, THROUGH_CONVEX_POINTS);
	if (model.GetNumConvexHullPoints() == 2)
	{
		CPen pn(PS_SOLID, 2, convex_hull_color);
		CPen* oldPen = dc.SelectObject(&pn);
		Point2D first = iter.GetCurValue();
		iter.MoveNext();
		Point2D second = iter.GetCurValue();

		dc.MoveTo(first.x, first.y);
		dc.LineTo(second.x, second.y);
		dc.SelectObject(oldPen);
		return;
	}
	
	CRgn convex_hull;
	CBrush convex_hull_brush(convex_hull_color);
	CPoint* array = new CPoint[model.GetNumConvexHullPoints()];
	int i = 0;
	while (iter.HasMoreElements())
	{
		Point2D cur_pnt = iter.GetCurValue();
		array[i].x = cur_pnt.x;
		array[i].y = cur_pnt.y;

		++i;
		iter.MoveNext();
	}
	convex_hull.CreatePolygonRgn(&array[0], model.GetNumConvexHullPoints(), ALTERNATE);
	dc.FillRgn(&convex_hull, &convex_hull_brush);
	delete[] array;
}

void ConvexHullRenderer::DrawBackground(CDC& dc, const CRect& cli_rect)
{
	CBrush bcg_brush(background_color);
	CBrush* oldBrush = dc.SelectObject(&bcg_brush);
	//stuff
	dc.FillRect(&cli_rect, &bcg_brush);

	dc.SelectObject(oldBrush);
}

void ConvexHullRenderer::Draw(CDC& dc, const CRect& cli_rect, const ConvexHullModelBase& model)
{ 
	DrawBackground(dc, cli_rect);
	DrawConvexHull(dc, model);
	DrawPoints(dc, model);
}