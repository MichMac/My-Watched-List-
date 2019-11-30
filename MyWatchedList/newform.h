#ifndef NEWFORM_H
#define NEWFORM_H

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDialog>
#include <QPixmap>

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
    void passValue(QString Title, QString Type, QString Episodes,
                   QString Status, QString Rating, QString Description, QString Picfile);

private:
    Ui::newForm *ui;
    QString title;
    QString type;
    QString episodes;
    QString status;
    QString rating;
    QString description;
    QString currentPicFile = "";

};

#endif // NEWFORM_H
