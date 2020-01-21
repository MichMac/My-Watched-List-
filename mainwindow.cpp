#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "showwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    newForm NewForm;
    NewForm.setModal(true);
    //qRegisterMetaType< QList<QString> >( "QList<QString>" );
    connect(&NewForm, SIGNAL(passValue(QString,QString,QString,QString,QString,QString,QString)), this,
            SLOT(setCustomShow(QString,QString,QString,QString,QString,QString,QString)));

    NewForm.exec();
}


void MainWindow::setCustomShow(QString Title, QString Type, QString Episodes,
             QString Status, QString Rating, QString Description, QString Picfile)
{
    title = Title;
    type = Type;
    episodes = Episodes;
    status = Status;
    rating = Rating;
    description = Description;
    picFile = Picfile;

    //QListWidgetItem *item = new QListWidgetItem(Title,Type,Episodes,Status);

}


void MainWindow::on_pushButton_tmdb_clicked()
{
    tmdb NewTmdb;
    //qDebug() <<  "user id w mainwindow: " + user_id;
    NewTmdb.setModal(true);
    NewTmdb.exec();
}

void MainWindow::userInfo(QString user_ID){

    user_id = user_ID;
    ShowWidget sw;
    connect(this, SIGNAL(passUserInfo(QString)), &sw,
            SLOT(getUserInfo(QString)));
    emit passUserInfo(user_id);
}
/*
QString MainWindow::getUserId(){

    return user_id;
}
*/
void MainWindow::on_pushButton_3_clicked()
{

}
