#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include "tmdb.h"

#include <QWidget>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>


namespace Ui {
class ShowWidget;
}

class ShowWidget : public QWidget
{
    Q_OBJECT

public:
    void showInfo(QVariantMap showInfo);
    explicit ShowWidget(QWidget *parent = nullptr);
    ~ShowWidget();


private slots:
    void on_pushButton_add_clicked();
    void settingUi(QVariantMap showMap, QString user_ID);

private:
    Ui::ShowWidget *ui;
    QString rating;
    QSqlDatabase db;
    QVariantMap showMap;
    QString poster;
    QString user_id;
    void dataBaseConnection();
    void getImage(QString url);
    void downloadFinished(QNetworkReply* reply);

};

#endif // SHOWWIDGET_H
