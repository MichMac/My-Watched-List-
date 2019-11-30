#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newform.h"

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
            SLOT(setShow(QString,QString,QString,QString,QString,QString,QString)));

    NewForm.exec();
}


void MainWindow::setShow(QString Title, QString Type, QString Episodes,
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



