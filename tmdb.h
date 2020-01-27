#ifndef TMDB_H
#define TMDB_H

#include "showwidget.h"

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QLabel>
#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QSize>
#include <QStackedLayout>

namespace Ui {
class tmdb;
}

class tmdb : public QDialog
{
    Q_OBJECT

public:
    explicit tmdb(QWidget *parent = nullptr);
    ~tmdb();

private slots:
    void managerFinished(QNetworkReply* reply);
    void on_pushButton_search_clicked();

signals:
    void passShowInfo(QVariantMap);

private:
    Ui::tmdb *ui;
    QString URL;
    QString api_key;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QString show_request;
    QString show_category_request;
    QString answer;
    QVariantMap mapShow;
    void setShowData(QVariantMap);
};

#endif // TMDB_H
