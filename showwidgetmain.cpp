#include "showwidgetmain.h"
#include "ui_showwidgetmain.h"
#include "mainwindow.h"


ShowWidgetMain::ShowWidgetMain(QVariantMap ShowMap,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowWidgetMain)
{
    ui->setupUi(this);
    showMap = ShowMap;
    settingUi();

}

ShowWidgetMain::~ShowWidgetMain()
{
    delete ui;
}

void ShowWidgetMain::settingUi(){

    //showInfo(showMap);
    //Checking if poster_path is from custom form or tmdb
    if(showMap["poster_path"].toString().contains("https://")){

        getImage(showMap["poster_path"].toString());

    }
    else{

        getCustomImage(showMap["poster_path"].toString());

    }
    //qDebug() << "poster path: " + showMap["poster_path"].toString();
    //poster_image -> loadFromData(poster);

    ui->label_type_6->setText(showMap["media_type"].toString());
    ui->label_date_6->setText(showMap["release_date"].toString());
    ui->label_title_6->setText(showMap["title"].toString());
    ui->label_rating_6->setText(showMap["vote_average"].toString());
    ui->plainTextEdit_description->setPlainText(showMap["overview"].toString());


}

void ShowWidgetMain::getImage(QString URL){
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    connect(nam, &QNetworkAccessManager::finished, this, &ShowWidgetMain::downloadFinished);
    const QUrl url = QUrl(URL);
    QNetworkRequest request(url);
    nam->get(request);

}

void ShowWidgetMain::getCustomImage(QString path){

    QPixmap pix(path);
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}


void ShowWidgetMain::downloadFinished(QNetworkReply* reply){

    QPixmap pm;
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();

    pm.loadFromData(reply->readAll());
    ui->label_pic->setPixmap(pm.scaled(w,h,Qt::KeepAspectRatio));
}


void ShowWidgetMain::showInfo(QVariantMap showInfo){
    showMap = showInfo;

}

void ShowWidgetMain::dataBaseConnection(){

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:\\studia\\ProjektC++\\MyWatchedList\\mwl_database.sqlite");
    QFileInfo checkFile("mwl_database.sqlite");

    if(checkFile.isFile())
    {
        if(!db.open())
        {
            QMessageBox::information(this,"Database","Database connection failed");
        }
    }
    db.open();
}


void ShowWidgetMain::on_pushButtont_Delete_clicked()
{
    dataBaseConnection();


    QSqlQuery q;
    QString query_command = "DELETE from show WHERE title=:title";
    q.prepare(query_command);
    q.bindValue(":title",showMap["title"]);
    q.exec();
    db.close();
}

