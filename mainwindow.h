#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "newform.h"
#include "tmdb.h"
#include "show.h"
#include "showwidgetmain.h"

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
    void clearList();
    void getFromDatabase();
    QString user_id;
    QSqlDatabase db;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void passUserInfo(QString);

public slots:
    void update_List();
    void on_pushButton_clicked();
    void setCustomShow(QString Title, QString Type, QString Date,
                       QString Rating, QString Description, QString Picfile);
    //void userInfo(QString);

private slots:
    void on_pushButton_tmdb_clicked();
    void on_pushButton_refresh_clicked();
    //void on_textFilter_textChanged();
    void on_pushButton_Filtruj_clicked();

    void on_pushButton_Sort_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    void fillShows(Show* show);
    void dataBaseConnection();
    QString records;

};
#endif // MAINWINDOW_H
