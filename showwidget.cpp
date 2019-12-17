#include "showwidget.h"
#include "ui_showwidget.h"

ShowWidget::ShowWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowWidget)
{
    ui->setupUi(this);
    //ui->label_type->setText("dupa");
    //ui->label_title->setText("wielka");
    //ui->label_description->setText("gefdbbrbtrebtrbbgrbrgbtrbtrbtrbtbrtrbtrbtrbtrbtrbt");
    //tmdb newTmdb;
   // connect(&newTmdb, SIGNAL(passShowInfo(QVariantMap)), this,
           // SLOT(getShowFromDatabase(QVariantMap)));
    //qDebug()<<"Wartosc w show: " + rating;
}

ShowWidget::~ShowWidget()
{
    delete ui;
}

void ShowWidget::settingUi(QVariantMap mapShow){


    getImage(mapShow["poster_path"].toString());
    //poster_image -> loadFromData(poster);

    ui->label_type->setText(mapShow["media_type"].toString());
    if(mapShow["media_type"].toString()=="Film"){
        ui->label_title->setText(mapShow["original_title"].toString());
        ui->label_date->setText(mapShow["release_date"].toString());
    }
    else{
        ui->label_title->setText(mapShow["original_name"].toString());
        ui->label_date->setText(mapShow["first_air_date"].toString());
    }
    ui->label_rating->setText(mapShow["vote_average"].toString());
    ui->plainTextEdit_description->setPlainText(mapShow["overview"].toString());


}

void ShowWidget::getImage(QString URL){
    QString poster = "https://image.tmdb.org/t/p/w600_and_h900_bestv2" + URL;
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    connect(nam, &QNetworkAccessManager::finished, this, &ShowWidget::downloadFinished);
    const QUrl url = QUrl(poster);
    QNetworkRequest request(url);
    nam->get(request);

}

void ShowWidget::downloadFinished(QNetworkReply* reply){

    QPixmap pm;
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();

    pm.loadFromData(reply->readAll());
    ui->label_pic->setPixmap(pm.scaled(w,h,Qt::KeepAspectRatio));
}
