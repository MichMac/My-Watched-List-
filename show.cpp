#include "show.h"

Show::Show(QString Title, QString Media, QString Release_date, QString Vote_average,
           QString Description, QString Poster_path, QObject *parent) : QObject(parent)
{
    title = Title;
    media = Media;
    release_date = Release_date;
    vote_average = Vote_average;
    description = Description;
    poster_path = Poster_path;

    showMap["title"] = title;
    showMap["media_type"] = media;
    showMap["release_date"] = release_date;
    showMap["vote_average"] = vote_average;
    showMap["overview"] = description;
    showMap["poster_path"] = poster_path;

}

QString Show::getTitle() const
{
    return title;
}

void Show::setTitle(const QString &value)
{
    title = value;
}

QString Show::getMedia() const
{
    return media;
}

void Show::setMedia(const QString &value)
{
    media = value;
}

QString Show::getRelease_date() const
{
    return release_date;
}

void Show::setRelease_date(const QString &value)
{
    release_date = value;
}

QString Show::getVote_average() const
{
    return vote_average;
}

void Show::setVote_average(const QString &value)
{
    vote_average = value;
}

QString Show::getDescription() const
{
    return description;
}

void Show::setDescription(const QString &value)
{
    description = value;
}

QString Show::getPoster_path() const
{
    return poster_path;
}

void Show::setPoster_path(const QString &value)
{
    poster_path = value;
}

QVariantMap Show::getShowMap() const
{
    return showMap;
}

void Show::setElementShowMap(const QString &value, QString &key)
{
    showMap[key] = value;
}



