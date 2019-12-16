#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>
#include <QSqlError>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_Login_Button_clicked();

private:
    Ui::LoginWindow *ui;
    QString username;
    QString password;
};

#endif // LOGINWINDOW_H
