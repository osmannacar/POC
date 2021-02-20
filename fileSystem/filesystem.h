#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include "IFileIO.h"

class FileSystem : public QObject, public IFileIO
{
    Q_OBJECT
public:
    explicit FileSystem(QObject *parent = nullptr);

signals:

public slots:

    // IFileIO interface
public:
    bool write(QString path, QByteArray data) override;
    QByteArray read(QString path) override;
};

#endif // FILESYSTEM_H
