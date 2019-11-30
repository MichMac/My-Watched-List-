/********************************************************************************
** Form generated from reading UI file 'newform.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFORM_H
#define UI_NEWFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newForm
{
public:
    QDialogButtonBox *Dodaj;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QTextEdit *Description_form;
    QLabel *label_pic;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout;
    QTextEdit *Title_form;
    QTextEdit *Type_form;
    QTextEdit *Episodes_form;
    QTextEdit *Status_form;
    QTextEdit *Rating_form;

    void setupUi(QDialog *newForm)
    {
        if (newForm->objectName().isEmpty())
            newForm->setObjectName(QString::fromUtf8("newForm"));
        newForm->resize(797, 533);
        Dodaj = new QDialogButtonBox(newForm);
        Dodaj->setObjectName(QString::fromUtf8("Dodaj"));
        Dodaj->setGeometry(QRect(550, 480, 201, 32));
        Dodaj->setOrientation(Qt::Horizontal);
        Dodaj->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        pushButton = new QPushButton(newForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 310, 111, 51));
        verticalLayoutWidget_3 = new QWidget(newForm);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(30, 400, 391, 131));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);

        verticalLayout_3->addWidget(label_7);

        Description_form = new QTextEdit(verticalLayoutWidget_3);
        Description_form->setObjectName(QString::fromUtf8("Description_form"));

        verticalLayout_3->addWidget(Description_form);

        label_pic = new QLabel(newForm);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        label_pic->setGeometry(QRect(20, 10, 201, 291));
        widget = new QWidget(newForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(300, 10, 441, 361));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setLineWidth(1);

        verticalLayout_2->addWidget(label);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        verticalLayout_2->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        Title_form = new QTextEdit(widget);
        Title_form->setObjectName(QString::fromUtf8("Title_form"));
        Title_form->setFrameShape(QFrame::StyledPanel);

        verticalLayout->addWidget(Title_form);

        Type_form = new QTextEdit(widget);
        Type_form->setObjectName(QString::fromUtf8("Type_form"));

        verticalLayout->addWidget(Type_form);

        Episodes_form = new QTextEdit(widget);
        Episodes_form->setObjectName(QString::fromUtf8("Episodes_form"));

        verticalLayout->addWidget(Episodes_form);

        Status_form = new QTextEdit(widget);
        Status_form->setObjectName(QString::fromUtf8("Status_form"));

        verticalLayout->addWidget(Status_form);

        Rating_form = new QTextEdit(widget);
        Rating_form->setObjectName(QString::fromUtf8("Rating_form"));

        verticalLayout->addWidget(Rating_form);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(newForm);
        QObject::connect(Dodaj, SIGNAL(accepted()), newForm, SLOT(accept()));
        QObject::connect(Dodaj, SIGNAL(rejected()), newForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(newForm);
    } // setupUi

    void retranslateUi(QDialog *newForm)
    {
        newForm->setWindowTitle(QCoreApplication::translate("newForm", "New Form", nullptr));
        pushButton->setText(QCoreApplication::translate("newForm", "Prze\305\233lij", nullptr));
        label_7->setText(QCoreApplication::translate("newForm", "Opis", nullptr));
        label_pic->setText(QString());
        label->setText(QCoreApplication::translate("newForm", "Tytu\305\202", nullptr));
        label_3->setText(QCoreApplication::translate("newForm", "Rodzaj", nullptr));
        label_4->setText(QCoreApplication::translate("newForm", "Odcinki", nullptr));
        label_5->setText(QCoreApplication::translate("newForm", "Status", nullptr));
        label_6->setText(QCoreApplication::translate("newForm", "Ocena", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newForm: public Ui_newForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFORM_H
