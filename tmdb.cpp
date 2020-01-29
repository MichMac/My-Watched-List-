#include "tmdb.h"
#include "ui_tmdb.h"


tmdb::tmdb(QString &user_ID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tmdb)
{
    ui->setupUi(this);
    user_id = user_ID;

    QFile file("E:\\studia\\ProjektC++\\MyWatchedList\\apikey.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Nie ma pliku";
    }

    while (!file.atEnd()) {
        api_key = file.readLine();
    }
    manager = new QNetworkAccessManager();
    //connect to signal when its done
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(managerFinished(QNetworkReply*)));
}

tmdb::~tmdb()
{
    delete ui;
}

void tmdb::on_pushButton_search_clicked()
{

    show_category_request = ui->comboBox_wybor->currentText();
    show_request = ui->textEdit_request->toPlainText();
    //qDebug()<<"Current Text: " << show_category_request;
    //adding string if request have more than one word
    if (show_request.contains(" ")){
        show_request.replace(" ","%20");
        //qDebug()<<show_request;
    }

    //Choosing url format for diffrent search method
    if(show_category_request == "Filmy"){
        show_category_request = "Film";
        URL = "https://api.themoviedb.org/3/search/movie?api_key="+ api_key +"&language=pl-PL&query="+ show_request +"&page=1&include_adult=false";
        //qDebug()<<"Wybrales film";

    }
    else{
        show_category_request = "Serial";
        URL = "https://api.themoviedb.org/3/search/tv?api_key="+ api_key +"&language=pl-PL&query="+ show_request +"&page=1";
        //qDebug()<<"Wybrales serial";
    }
    QUrl serviceUrl = QUrl(URL);
    //setting url request
    request.setUrl(serviceUrl);
    //setting get method for request
    manager->get(request);

    //ui->listWidget->addItem(map["original_name"].toString());


}


void tmdb::managerFinished(QNetworkReply *reply) {
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }
    answer = reply->readAll();
    //json parser
    QJsonDocument doc = QJsonDocument::fromJson(answer.toUtf8());
    QJsonObject obj = doc.object();
    QVariantMap mainMap = obj.toVariantMap();
    QVariantList localList = mainMap["results"].toList();
    //asking for value
    mapShow = localList[0].toMap();
    mapShow.insert("media_type",show_category_request);
    setShowData(mapShow);

    ShowWidget* showWidget = new ShowWidget;

    //connect with widget class
    connect(this, SIGNAL(passShowInfo(QVariantMap,QString)), showWidget,
            SLOT(settingUi(QVariantMap,QString)));
    //signal
    emit passShowInfo(mapShow,user_id);

    reply->deleteLater();

    QStackedWidget* stackedWidget = new QStackedWidget();
    QVBoxLayout* layout = new QVBoxLayout;

    stackedWidget -> addWidget(showWidget);
    layout -> addWidget(stackedWidget);
    setLayout(layout);



    //firstPageWidget->show();

    /*
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
    QSize size (showWidget->width(),showWidget->height());
    item -> setSizeHint(size);
    ui -> listWidget ->setSizeIncrement(size);
    ui -> listWidget -> setItemWidget(item, showWidget);
    qDebug() << ui->listWidget->count();
    if(ui->listWidget->count() > 1){
        ui -> listWidget -> takeItem(ui->listWidget->row);
        delete item;
    }
    */
}

void tmdb::setShowData(QVariantMap data){

    mapShow = data;

}



