#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include "tmdb.h"

#include <QWidget>
#include <QNetworkReply>
#include <QNetworkAccessManager>

namespace Ui {
class ShowWidget;
}

class ShowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShowWidget(QWidget *parent = nullptr);
    ~ShowWidget();

public slots:
    void settingUi(QVariantMap);

private:
    Ui::ShowWidget *ui;
    QString rating;
    void getImage(QString url);
    void downloadFinished(QNetworkReply* reply);

};

#endif // SHOWWIDGET_H
