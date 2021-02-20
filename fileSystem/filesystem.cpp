#include "filesystem.h"

#include <QFile>
#include <QTextStream>

FileSystem::FileSystem(QObject *parent) : QObject(parent)
{

}

bool FileSystem::write(QString path, QByteArray data)
{
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream stream(&file);
    stream << data;
    file.close();

    return true;
}

QByteArray FileSystem::read(QString path)
{
    QFile file(path);
    QByteArray data;
    if(!file.open(QIODevice::ReadOnly)){
        return data;
    }

    QTextStream stream(&file);
    data = stream.readAll().toUtf8();
    file.close();

    return data;
}
