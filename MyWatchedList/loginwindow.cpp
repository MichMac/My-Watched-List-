#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_Login_Button_clicked()
{
    username = ui->Username_lineEdit->displayText();
    password = ui->Password_lineEdit->displayText();

    if(username == "test" && password == "test"){
        QMessageBox::information(this, "Login", "Login Successful");
        this -> hide();
        MainWindow *w = new MainWindow();
        //w->setAttribute(Qt::WA_DeleteOnClose);
        w->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Login Failed");
    }
}
