#ifndef SHOW_H
#define SHOW_H

#include <QObject>
#include <QVariantMap>

class Show : public QObject
{
    Q_OBJECT
public:
    explicit Show(QString title, QString media, QString release_date, QString vote_average,
                  QString description, QString poster_path, QObject *parent = nullptr);

    QString getTitle() const;
    void setTitle(const QString &value);

    QString getMedia() const;
    void setMedia(const QString &value);

    QString getRelease_date() const;
    void setRelease_date(const QString &value);

    QString getVote_average() const;
    void setVote_average(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    QString getPoster_path() const;
    void setPoster_path(const QString &value);

    QVariantMap getShowMap() const;
    void setElementShowMap(const QString &value , QString &key);

private:
    QString title;
    QString media;
    QString release_date;
    QString vote_average;
    QString description;
    QString poster_path;
    QVariantMap showMap;

signals:

public slots:

};

#endif // SHOW_H
