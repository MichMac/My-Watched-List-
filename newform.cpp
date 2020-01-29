#include "newform.h"
#include "ui_newform.h"
#include "mainwindow.h"



newForm::newForm(QString &user_ID,QWidget *parent) :

    QDialog(parent),
    ui(new Ui::newForm)
{
    ui->setupUi(this);
    user_id = user_ID;
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
    date = ui->Date_form->toPlainText();
    rating = ui->Rating_form->toPlainText();
    description = ui->Description_form->toPlainText();
    emit passValue(title,type,date,rating,description,filename);

    //qDebug() << "widget user id: " + user_id;
    dataBaseConnection();
    QSqlQuery q;
    QString execute ="INSERT INTO show (user_id,title,media_type,release_date,vote_average,description,poster_path) VALUES (:user_id,:title,:media_type,:release_date,:vote_average,:description,:poster_path)";
    q.prepare(execute);
    //binding values to send to database
    q.bindValue(":user_id", user_id);
    q.bindValue(":title",title);
    q.bindValue(":media_type", type);
    q.bindValue(":release_date",date);
    q.bindValue(":vote_average", rating);
    q.bindValue(":description", description);
    q.bindValue(":poster_path", filename);
    q.exec();
    //qDebug() << "excecuted query: "+ q.executedQuery();
    db.close();


    //QListWidgetItem *item = new QListWidgetItem(Title,Type,Episodes,Status);

}


void newForm::on_pushButton_clicked()
{
    filename = QFileDialog::getOpenFileName(this, "Open the picture file");
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
    }
    QPixmap pix(filename);
    pix.scaled(229,324);
    ui->label_pic->setPixmap(pix);
}

void newForm::dataBaseConnection(){

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:\\studia\\ProjektC++\\MyWatchedList\\mwl_database.sqlite");
    QFileInfo checkFile("mwl_database.sqlite");

    if(checkFile.isFile())
    {
        if(!db.open())
        {
            QMessageBox::information(this,"Database","Database connection failed");
        }
    }
    db.open();
}
