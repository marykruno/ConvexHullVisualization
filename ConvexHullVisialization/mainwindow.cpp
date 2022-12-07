#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algorithmSelectionDialog.h"
#include <QDebug>
#include <QColorDialog>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view = new customGraphicsView();
    group = new QGroupBox();
    vLayout =new QVBoxLayout();
    vLayout->addWidget(view);
    group->setLayout(vLayout);
    setCentralWidget(group);
    connect(this, SIGNAL(clearAll()), view, SLOT(on_optionsClearAll()));
    connect(this, SIGNAL(changeColor(eColoredObjectType,QColor&)), view, SLOT(on_colorChanged(eColoredObjectType,QColor&)));
    setWindowTitle(QString::fromStdString(getAlgorithmDescriptionString(view->getCurrentAlgorithm())));
    initToolBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::callColorDialogWindow(eColoredObjectType type){
    QColorDialog w;
    if(!w.exec())return;
    QColor color = w.selectedColor();
    emit changeColor(type, color);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}


void MainWindow::on_actionclear_All_triggered()
{
    emit clearAll();
}


void MainWindow::on_actionbackground_color_triggered()
{
    callColorDialogWindow(eColoredObjectType::BACKGROUND);
}


void MainWindow::on_actionpoints_color_triggered()
{
    callColorDialogWindow(eColoredObjectType::POINTS);
}


void MainWindow::on_actionconvex_hull_color_triggered()
{
    callColorDialogWindow(eColoredObjectType::CONVEXHULL);
}


void MainWindow::on_actionchoose_algorithm_triggered()
{
    algorithmSelectionDialog dlg;
    dlg.setCurrentAlgorithm(view->getCurrentAlgorithm());
    if(auto result = dlg.exec(); result == QDialog::Accepted){
        auto alg = dlg.getSelectedAlgorithm();
        view->on_algorithmChanged(alg);
        setWindowTitle(QString::fromStdString(getAlgorithmDescriptionString(view->getCurrentAlgorithm())));
    }
}

void MainWindow::initToolBar(){
    QToolBar *mainToolbar  = new QToolBar("mainToolBar", this);
    mainToolbar->setWindowTitle(tr("Available actions"));
    addToolBar(mainToolbar);
    mainToolbar->setOrientation(Qt::Horizontal);
    mainToolbar->setMovable(false);
    for(auto& type: { eColoredObjectType::BACKGROUND, eColoredObjectType::POINTS, eColoredObjectType::CONVEXHULL, eColoredObjectType::INVALID }){
        QPushButton* cur_button = new QPushButton(this);
        std::string name = (type != eColoredObjectType::INVALID)?(getDescriptionFromColoredObjectType(type)):("Clear all");
        cur_button->setText(QString::fromStdString(name));
        connect(cur_button, &QPushButton::clicked, [this, type](){
            if(type != eColoredObjectType::INVALID)
                callColorDialogWindow(type);
            else
                emit clearAll();
        });
        mainToolbar->addWidget(cur_button);
    }
}
