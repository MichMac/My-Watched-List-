#include "showwidget.h"
#include "ui_showwidget.h"
#include "mainwindow.h"

ShowWidget::ShowWidget(QVariantMap ShowMap,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowWidget)
{
    ui->setupUi(this);
    showMap = ShowMap;
    settingUi();

}

ShowWidget::~ShowWidget()
{
    delete ui;
}

void ShowWidget::settingUi(){

    //showInfo(showMap);

    getImage(showMap["poster_path"].toString());
    //qDebug() << "poster path: " + showMap["poster_path"].toString();
    //poster_image -> loadFromData(poster);

    ui->label_type->setText(showMap["media_type"].toString());
    ui->label_date->setText(showMap["release_date"].toString());
    ui->label_title->setText(showMap["title"].toString());
    ui->label_rating->setText(showMap["vote_average"].toString());
    ui->plainTextEdit_description->setPlainText(showMap["overview"].toString());


}

void ShowWidget::getImage(QString URL){
    poster = "https://image.tmdb.org/t/p/w600_and_h900_bestv2" + URL;
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

void ShowWidget::on_pushButton_add_clicked()
{
    //MainWindow* m = new MainWindow;
    qDebug() << "widget user id: " + user_id;
    dataBaseConnection();
    QSqlQuery q;
    QString execute ="INSERT INTO show (title,media_type,release_date,vote_average,description,poster_path,user_id) VALUES (:title,:media_type,:release_date,:vote_average,:description,:poster_path,:user_id)";
    q.prepare(execute);
    //binding values to send to database
    q.bindValue(":media_type", showMap["media_type"]);
    if(showMap["media_type"].toString()=="Film"){
        q.bindValue(":title",showMap["original_title"]);
        q.bindValue(":release_date",showMap["release_date"]);
    }
    else{
        q.bindValue(":title",showMap["original_name"]);
        q.bindValue(":release_date",showMap["first_air_date"]);
    }
    q.bindValue(":vote_average", showMap["vote_average"]);
    q.bindValue(":description", showMap["overview"]);
    q.bindValue(":poster_path", poster);
    q.bindValue(":user_id", user_id);
    q.exec();
    db.close();

}

void ShowWidget::showInfo(QVariantMap showInfo){
    showMap = showInfo;

}

void ShowWidget::dataBaseConnection(){

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
/*
void ShowWidget::getUserInfo(QString user_ID){

    userInfo(user_ID);
    qDebug() << "widget user id w slocie: " + user_id;

}

void ShowWidget::userInfo(QString userID){
    user_id = userID;

}
*/


