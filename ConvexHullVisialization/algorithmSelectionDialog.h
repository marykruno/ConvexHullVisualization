#pragma once
#include "utilities.h"
#include <QDialog>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>

class algorithmSelectionDialog : public QDialog
{
    Q_OBJECT
public:
    algorithmSelectionDialog( QWidget* parent = 0);
    ~algorithmSelectionDialog();
    void setCurrentAlgorithm(eConvexHullAlg alg);
    eConvexHullAlg getSelectedAlgorithm() const{
        return cur_alg;
    }
signals:
    void changeAlgorithm(eConvexHullAlg alg);
private slots:
    void on_buttonToggled(QAbstractButton* button,bool flag);
private:
    QPushButton* okButton;
    QPushButton* cancelButton;
    QButtonGroup* buttonGroup;
    eConvexHullAlg cur_alg = eConvexHullAlg::LAST_VALUE;
};
