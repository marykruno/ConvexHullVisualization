#include "algorithmSelectionDialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

algorithmSelectionDialog::algorithmSelectionDialog( QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Available algorithms: ");
    QVBoxLayout *vbox = new QVBoxLayout(this);
    QHBoxLayout *hbox = new QHBoxLayout();

    buttonGroup = new QButtonGroup(this);

    int alg_count = (int)eConvexHullAlg::LAST_VALUE;
    for(int i = 0; i < alg_count; ++i){
        eConvexHullAlg alg = (eConvexHullAlg)i;
        QString description = QString::fromStdString(getAlgorithmDescriptionString(alg));
        QRadioButton* rad = new QRadioButton(description, this);
        vbox->addWidget(rad);
        buttonGroup->addButton(rad);
    }
    connect(buttonGroup, SIGNAL(buttonToggled(QAbstractButton*,bool)), this, SLOT(on_buttonToggled(QAbstractButton*,bool)));

    okButton = new QPushButton("Ok", this);
    cancelButton = new QPushButton("Cancel", this);

    hbox->addWidget(okButton, 1, Qt::AlignRight);
    hbox->addWidget(cancelButton, 0);

    vbox->addStretch(1);
    vbox->addLayout(hbox);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
}

algorithmSelectionDialog::~algorithmSelectionDialog(){

}

void algorithmSelectionDialog::on_buttonToggled(QAbstractButton* button, bool flag){
    if(flag){
        for(const auto& cur_button: buttonGroup->buttons())
        {
            if(cur_button == button){
                auto alg = getAlgorithmFromDescriptionString(button->text().toStdString());
                cur_alg = alg;
            }
        }
    }

}

void algorithmSelectionDialog::setCurrentAlgorithm(eConvexHullAlg alg){
    for(auto& cur_button: buttonGroup->buttons())
    {
         auto alg_ = getAlgorithmFromDescriptionString(cur_button->text().toStdString());
        if(alg_ == alg){
            cur_alg = alg;
            cur_button->setChecked(true);
         }
    }
}
