/********************************************************************************
** Form generated from reading UI file 'dodaj.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DODAJ_H
#define UI_DODAJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_addForm
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *addForm)
    {
        if (addForm->objectName().isEmpty())
            addForm->setObjectName(QString::fromUtf8("addForm"));
        addForm->resize(400, 300);
        buttonBox = new QDialogButtonBox(addForm);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(addForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), addForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(addForm);
    } // setupUi

    void retranslateUi(QDialog *addForm)
    {
        addForm->setWindowTitle(QCoreApplication::translate("addForm", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addForm: public Ui_addForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DODAJ_H
