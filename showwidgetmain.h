#ifndef SHOWWIDGETMAIN_H
#define SHOWWIDGETMAIN_H

#include <QWidget>

#include <QWidget>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>

namespace Ui {
class ShowWidgetMain;
}

class ShowWidgetMain : public QWidget
{
    Q_OBJECT

public:
    void showInfo(QVariantMap showInfo);
    explicit ShowWidgetMain(QVariantMap ShowMap,QWidget *parent = nullptr);
    ~ShowWidgetMain();

signals:


private slots:


    void on_pushButtont_Delete_clicked();

private:
    Ui::ShowWidgetMain *ui;
    void settingUi();
    QString rating;
    QSqlDatabase db;
    QVariantMap showMap;
    QString poster;
    QString user_id;
    void dataBaseConnection();
    void getImage(QString url);
    void getCustomImage(QString path);
    void downloadFinished(QNetworkReply* reply);

};

#endif // SHOWWIDGETMAIN_H
