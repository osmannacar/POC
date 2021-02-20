#ifndef IFileIO_H
#define IFileIO_H

#include <QByteArray>

class IFileIO
{
public:
    virtual bool write(QString path, QByteArray data) = 0;
    virtual QByteArray read(QString path) = 0;

};

#endif // IFileIO_H
