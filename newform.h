#ifndef NEWFORM_H
#define NEWFORM_H

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDialog>
#include <QPixmap>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

namespace Ui {
class newForm;
}

class newForm : public QDialog
{
    Q_OBJECT

public:
    explicit newForm(QWidget *parent = nullptr);
    ~newForm();

private slots:
    void on_Dodaj_accepted();
    void on_pushButton_clicked();

signals:
    void passValue(QString Title, QString Type, QString Date,
                   QString Rating, QString Description, QString Picfile);

private:
    Ui::newForm *ui;
    QSqlDatabase db;
    void dataBaseConnection();
    QString title;
    QString type;
    QString date;
    QString description;
    QString rating;
    QString filename;

};

#endif // NEWFORM_H
