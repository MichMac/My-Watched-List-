#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QListWidget>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_pushButton_clicked();
    void setShow(QString Title, QString Type, QString Episodes,
                 QString Status, QString Rating, QString Description, QString Picfile);

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
