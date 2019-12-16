#include "newform.h"
#include "ui_newform.h"
#include "mainwindow.h"



newForm::newForm(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::newForm)
{
    ui->setupUi(this);
    QPixmap pix("E:/studia/projekt c++/MyWatchedList/pics/noimage.jpg");
    pix.scaled(321,201);
    ui->label_pic->setPixmap(pix);}

newForm::~newForm()
{
    delete ui;
}

void newForm::on_Dodaj_accepted()
{
    title = ui->Title_form->toPlainText();
    type = ui->Type_form->toPlainText();
    episodes = ui->Episodes_form->toPlainText();
    status = ui->Status_form->toPlainText();
    rating = ui->Rating_form->toPlainText();
    description = ui->Description_form->toPlainText();

    emit passValue(title,type,episodes,status,rating,description,currentPicFile);


    //QListWidgetItem *item = new QListWidgetItem(Title,Type,Episodes,Status);

}


void newForm::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the picture file");
    QFile file(filename);
    currentPicFile = filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
    }
    QPixmap pix(filename);
    pix.scaled(229,324);
    ui->label_pic->setPixmap(pix);
}
