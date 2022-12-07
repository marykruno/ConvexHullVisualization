#include "customGraphicsView.h"
#include "ConvexHullModelFabric.h"

customGraphicsView::customGraphicsView(QWidget *parent) :
    QGraphicsView(parent) {
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1024, 768);
    setScene(scene);
    scene->setParent(this);
    cur_alg_type = eConvexHullAlg::GRAHAM;
    p_model = ConvexHullModelFabric::CreateModel(cur_alg_type);
    p_model->setObserver(this);
    renderer.SetObserver(this);
}

customGraphicsView::~customGraphicsView() {
    delete p_model;
}


void customGraphicsView::onModelChanged(const ConvexHullModelBase* p_model_) {
    if (p_model_ == p_model) {
        immediateViewUpdate();
    }
}

void customGraphicsView::onRenderStyleChanged(const ConvexHullRenderer* p_renderer_) {
    if (p_renderer_ == &renderer) {
        immediateViewUpdate();
    }
}

void customGraphicsView::paintEvent(QPaintEvent *event) {
    renderer.Draw(*scene, *p_model);
    QGraphicsView::paintEvent(event);
}

void customGraphicsView::mouseDoubleClickEvent(QMouseEvent *event) {
    QPointF pt = mapToScene(event->pos());
    Point2D point2d = Point2D(pt.x(), pt.y());
    p_model->addPoint(point2d);

    QGraphicsView::mouseDoubleClickEvent(event);
}

void customGraphicsView::on_optionsClearAll() {
    p_model->clearAll();
    QBrush bcg_brush(renderer.GetBackgroundColor());
    scene->setBackgroundBrush(bcg_brush);
}

void customGraphicsView::immediateViewUpdate() {
    scene->clear();
}

void customGraphicsView::on_colorChanged(eColoredObjectType type, QColor& color){
    if(type == eColoredObjectType::BACKGROUND){
        renderer.SetBackgroundColor(color);
    }
    else if(type == eColoredObjectType::POINTS){
        renderer.SetPointsColor(color);
    }
    else if(type == eColoredObjectType::CONVEXHULL){
        renderer.SetConvexHullColor(color);
    }
    else{
        return;
    }
}

void customGraphicsView::on_algorithmChanged(eConvexHullAlg alg){
    if(cur_alg_type != alg){
        p_model->clearAll();
        delete p_model;
        p_model = nullptr;
        cur_alg_type = alg;
        p_model = ConvexHullModelFabric::CreateModel(cur_alg_type);
        p_model->setObserver(this);
    }
}
