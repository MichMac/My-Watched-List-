#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"


LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:\\studia\\ProjektC++\\MyWatchedList\\mwl_database.sqlite");
    QFileInfo checkFile("mwl_database.sqlite");

    if(checkFile.isFile())
    {
        if(db.open())
        {
            ui->label_status->setText("Connected to Database");
        }
    }
    else{
        ui->label_status->setText("Database File doesnt't exist");
    }
    db.open();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_Login_Button_clicked()
{

    username = ui->Username_lineEdit->displayText();
    password = ui->Password_lineEdit->displayText();

    if(!db.isOpen()){
        qDebug()<<"No connection to database";
    }

    QSqlQuery q;
    QString execute ="SELECT username,password FROM users WHERE username = :username AND password = :password ";
    q.prepare(execute);
    q.bindValue(":username", username);
    q.bindValue(":password", password);
    q.exec();
    /*
    qDebug()<<"Executed query: " <<q.executedQuery();
    qDebug()<<"Last query: " <<q.lastQuery();
    qDebug()<< q.lastError().text();
    qDebug() << q.boundValue(":username");
    qDebug() << q.boundValue(":password");
    qDebug() << q.exec();
    */

    if(q.exec())
    {
        if(q.next())
        {
            QMessageBox::information(this, "Login", "Login successfull");
            this -> hide();
            MainWindow *w = new MainWindow();
            //w->setAttribute(Qt::WA_DeleteOnClose);
            w->show();

        }else{
            ui->label_status->setText("Wrong Username or Password");
        }

    }

}
