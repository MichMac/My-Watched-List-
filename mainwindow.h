#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    QSqlDatabase db;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_pushButton_clicked();
    void setShow(QString Title, QString Type, QString Episodes,
                 QString Status, QString Rating, QString Description, QString Picfile);

private slots:
    void on_pushButton_3_clicked();

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
