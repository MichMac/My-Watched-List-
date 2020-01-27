#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "userID konstruktorze: " + user_id;
    dataBaseConnection();
    getFromDatabase();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    newForm NewForm;
    NewForm.setModal(true);
    //qRegisterMetaType< QList<QString> >( "QList<QString>" );
    connect(&NewForm, SIGNAL(passValue(QString,QString,QString,QString)), this,
            SLOT(setCustomShow(QString,QString,QString,QString,QString)));

    NewForm.exec();
}


void MainWindow::setCustomShow(QString Title, QString Type, QString Date,
                               QString Rating, QString Description, QString Picfile)
{
    /*
    title = Title;
    type = Type;
    date = Date;
    rating = Rating;
    description = Description;
    picFile = Picfile;
    */
    Show customShow(Title,Type,Date,Rating,Description,Picfile);

}


void MainWindow::on_pushButton_tmdb_clicked()
{
    tmdb NewTmdb;
    //qDebug() <<  "user id w mainwindow: " + user_id;
    NewTmdb.setModal(true);
    NewTmdb.exec();
}
/*
void MainWindow::userInfo(QString user_ID){

    user_id = user_ID;
    ShowWidget sw;
    connect(this, SIGNAL(passUserInfo(QString)), &sw,
            SLOT(getUserInfo(QString)));
    emit passUserInfo(user_id);
}
*/
/*
QString MainWindow::getUserId(){

    return user_id;
}
*/

void MainWindow::dataBaseConnection(){

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

void MainWindow::fillShows(Show* Show){

    ShowWidgetMain* showWidgetMain = new ShowWidgetMain(Show->getShowMap());

    QListWidgetItem* item = new QListWidgetItem(ui->listWidget);

    item->setForeground(QColor("white"));
    //item->set
    item->setText(Show->getTitle());

    QSize size (showWidgetMain->width(),showWidgetMain->height());
    item->setSizeHint(size);

    ui->listWidget->setItemWidget(item,showWidgetMain);

}


void MainWindow::on_pushButton_refresh_clicked()
{
    update_List();

}


void MainWindow::getFromDatabase(){

    qDebug() << "userID konstruktorze: " + user_id;
    dataBaseConnection();

    QSqlQuery count_q,shows_q;

    //QString execute_count ="SELECT COUNT(*) FROM show";
    QString execute_shows = "SELECT * FROM show";

    //count_q.prepare(execute_count);
    //count_q.exec();

    /*
    qDebug()<<"Executed query: " <<q.executedQuery();
    qDebug()<<"Last query: " <<q.lastQuery();
    qDebug()<< q.lastError().text();
    qDebug() << q.boundValue(":username");
    qDebug() << q.boundValue(":password");
    qDebug() << q.exec();
    */
    /*
    if(count_q.exec())
    {
        if(count_q.next())
        {
            records = count_q.value(0).toString();
            qDebug() << "ilosc rekordow: " + records;
        }
        else{
            QMessageBox::warning(this, "Error", "Query didn't pass");
            db.close();
        }

    }*/

    shows_q.prepare(execute_shows);
    shows_q.exec();
    qDebug()<< shows_q.lastError().text();

    if(shows_q.exec())
    {
        while(shows_q.next())
        {
            // Dodac jako qvariantmap i przeslac do metody ktora stworzy widok?
            QString title = shows_q.value("title").toString();
            QString media = shows_q.value("media_type").toString();
            QString release_date = shows_q.value("release_date").toString();
            QString vote_average = shows_q.value("vote_average").toString();
            QString description = shows_q.value("description").toString();
            QString poster_path = shows_q.value("poster_path").toString();
            Show show(title,media,release_date,vote_average,description,poster_path);
            fillShows(&show);
            //qDebug() << "showMap title: " + show.getTitle();

        }
    }
    else{
        QMessageBox::warning(this, "Error", "Query didn't pass");
        db.close();
    }


}
/*
void MainWindow::on_textFilter_textChanged()
{
    //qDebug() << "filter: " + text;
    QString currentText = ui->textFilter->toPlainText();
    qDebug() << "filter: " + currentText;
    QList<QListWidgetItem *> items = ui->listWidget->findItems(currentText,Qt::MatchContains);

    ui->listWidget->clear();

    if (items.size() > 0) {
        qDebug() << "items size: ";
        qDebug() << items.size();
        int rowCount = ui->listWidget->count();

        for(int i = 0; i < items.count(); i++){
           QListWidgetItem* item = items[i];
           item->setHidden(false);

        }



    }


}
*/



void MainWindow::on_pushButton_Filtruj_clicked()
{

    QString currentText = ui->textFilter->toPlainText();
    qDebug() << currentText;

    QList<QListWidgetItem *> items = ui->listWidget->findItems(currentText,Qt::MatchContains);
    QSize size (500,150);

    qDebug() << items.size();
    if (items.size() > 0) {
        qDebug() << "items size: ";
        qDebug() << items.size();
        //ui->listWidget->clear();
        for(int i = 0; i < items.size(); i++){
           QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
           item = items[i];
           item->setSizeHint(size);
           ShowWidgetMain* widget = qobject_cast<ShowWidgetMain*>(ui->listWidget->itemWidget(item));
           ui->listWidget->setItemWidget(item,widget);
        }
    }
}



void MainWindow::on_pushButton_Sort_clicked(bool checked)
{
    if(checked){
        ui->listWidget->sortItems(Qt::AscendingOrder);
    }
    else
        ui->listWidget->sortItems(Qt::DescendingOrder);
}

void MainWindow::clearList(){

    ui->listWidget->clear();
}

void MainWindow::update_List(){

   //Usuwanie poprzedniego stanu listy
    clearList();

    //Dodanie zauktualiwanej bazy

    getFromDatabase();
}
