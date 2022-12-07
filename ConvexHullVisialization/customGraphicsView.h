#pragma once
#include <QGraphicsView>
#include <QMouseEvent>
#include "utilities.h"
#include "ConvexHullModelBase.h"
#include "ConvexHullRendrer.h"

class customGraphicsView : public QGraphicsView, public IViewObserver, public IRenderStyleObserver
{
    Q_OBJECT
public:
    explicit customGraphicsView(QWidget *parent = 0);
    ~customGraphicsView();
    virtual void onModelChanged(const ConvexHullModelBase* p_model_) override;
    virtual void onRenderStyleChanged(const ConvexHullRenderer* p_renderer_) override;
    eConvexHullAlg getCurrentAlgorithm() const {
        return cur_alg_type;
    }
     void on_algorithmChanged(eConvexHullAlg alg);
public slots:
    void on_optionsClearAll();
    void on_colorChanged(eColoredObjectType type, QColor& color);
protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
private:
    ConvexHullModelBase* p_model;
    ConvexHullRenderer renderer;
    QGraphicsScene* scene;
    eConvexHullAlg cur_alg_type;
private:
    void immediateViewUpdate();
};
