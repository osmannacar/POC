#ifndef FILERECEIVERSERILIZATION_H
#define FILERECEIVERSERILIZATION_H

#include <QObject>

class FileReceiverSerilization : public QObject
{
    Q_OBJECT
public:
    explicit FileReceiverSerilization(QObject *parent = nullptr);
    inline const static QByteArray END_OF_FILE = QByteArray::fromStdString("\n%%EOF\n");

signals:
    void onNewFile(QString fileName, QByteArray fileData);

public slots:
    void newFileData(QByteArray pBuffer);

private:
    void collectFileFromData();
private:
    QByteArray mBuffer;
    QString mFilename;
};

#endif // FILERECEIVERSERILIZATION_H
