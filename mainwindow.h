#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "newform.h"
#include "tmdb.h"

#include <QMainWindow>
#include <QListWidgetItem>
#include <QListWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString user_id;
    QSqlDatabase db;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void passUserInfo(QString);

public slots:
    void on_pushButton_clicked();
    void setCustomShow(QString Title, QString Type, QString Episodes,
                 QString Status, QString Rating, QString Description, QString Picfile);
    void userInfo(QString);

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_tmdb_clicked();

private:
    Ui::MainWindow *ui;
    QString title;
    QString type;
    QString episodes;
    QString status;
    QString rating;
    QString description;
    QString picFile;

};
#endif // MAINWINDOW_H
