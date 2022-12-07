#include "ConvexHullModelBase.h"
#include "ConvexHullRendrer.h"

ConvexHullRenderer::ConvexHullRenderer()
{
    points_color = QColor(0, 0, 0);
    convex_hull_color = QColor(255, 0, 0);
    background_color = QColor(255, 255, 255);
    p_observer = nullptr;

}

ConvexHullRenderer::~ConvexHullRenderer()
{

}


void ConvexHullRenderer::DrawPoints(QGraphicsScene& scene, const ConvexHullModelBase& model)
{
	if (model.getNumPoints() == 0)
        return;

    QBrush points_brush(points_color, Qt::SolidPattern);

    PointIterator iter(model, eIteratorType::THROUGH_ALL_POINTS);
    Point2D prev_pnt = iter.GetCurValue();
    scene.addEllipse(prev_pnt.x-points_rad, prev_pnt.y-points_rad, points_rad*2.0, points_rad*2.0, QPen(points_color),
                     points_brush);
	iter.MoveNext();
	while (iter.HasMoreElements())
	{
        Point2D cur_pnt = iter.GetCurValue();
        scene.addEllipse(cur_pnt.x-points_rad, cur_pnt.y-points_rad, points_rad*2.0, points_rad*2.0, QPen(points_color),
                         points_brush);
		prev_pnt = cur_pnt;
		iter.MoveNext();
	}
	
}


void ConvexHullRenderer::DrawConvexHull(QGraphicsScene& scene, const ConvexHullModelBase& model)
{
	if (model.getNumConvexHullPoints() <= 1)
		return;
    PointIterator iter(model, eIteratorType::THROUGH_CONVEX_POINTS);
	if (model.getNumConvexHullPoints() == 2)
	{
        QPen convex_hull_pen(convex_hull_color, 2, Qt::PenStyle::SolidLine);
		Point2D first = iter.GetCurValue();
		iter.MoveNext();
		Point2D second = iter.GetCurValue();

        scene.addLine(first.x,
                      first.y,
                      second.x,
                      second.y,
                      convex_hull_pen);
		return;
	}
	
    QBrush convex_hull_brush(convex_hull_color, Qt::SolidPattern);

    QPolygonF polygon;
    polygon.reserve(model.getNumConvexHullPoints());

    while (iter.HasMoreElements()) {
        Point2D cur_pnt = iter.GetCurValue();
        polygon.append(QPointF(cur_pnt.x, cur_pnt.y));
        iter.MoveNext();
    }
    scene.addPolygon(polygon, QPen(Qt::PenStyle::SolidLine), convex_hull_brush);
}

void ConvexHullRenderer::DrawBackground(QGraphicsScene& scene)
{
    QBrush bcg_brush(background_color);
    scene.setBackgroundBrush(bcg_brush);
}

void ConvexHullRenderer::Draw(QGraphicsScene& scene, const ConvexHullModelBase& model)
{ 
    DrawBackground(scene);
    DrawConvexHull(scene, model);
    DrawPoints(scene, model);
}

void ConvexHullRenderer::resetColors(){
    SetBackgroundColor(QColor(255, 255, 255));
    SetPointsColor(QColor(0, 0, 0));
    SetConvexHullColor(QColor(255, 0, 0));
}

