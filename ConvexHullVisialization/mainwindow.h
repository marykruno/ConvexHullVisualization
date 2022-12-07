#pragma once
#include <QMainWindow>
#include <QGroupBox>
#include <QVBoxLayout>
#include "customGraphicsView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    Ui::MainWindow *ui;
    QGroupBox* group;
    QVBoxLayout* vLayout;
    customGraphicsView* view;
signals:
    void clearAll();
    void changeColor(eColoredObjectType type, QColor& color);
private slots:
    void on_actionExit_triggered();
    void on_actionclear_All_triggered();
    void on_actionbackground_color_triggered();
    void on_actionpoints_color_triggered();
    void on_actionconvex_hull_color_triggered();
    void on_actionchoose_algorithm_triggered();
private:
    void initToolBar();
    void callColorDialogWindow(eColoredObjectType type);
};
