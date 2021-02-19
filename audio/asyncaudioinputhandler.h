#ifndef ASYNCAUDIOINPUTHANDLER_H
#define ASYNCAUDIOINPUTHANDLER_H

#include <thread/athread.h>

#include <QIODevice>
#include <QtMultimedia/QAudioOutput>
#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudioFormat>

class AsyncAudioInputHandler : public AThread
{
    Q_OBJECT
public:
    explicit AsyncAudioInputHandler(QObject *parent = nullptr);
    void mainLoop() override;

signals:
    void onNewAudioInput(QByteArray pBuffer);

private slots:
    void readyToRead();
private:
    QAudioInput* mInput;
    QIODevice *mDevice;
};

#endif // ASYNCAUDIOINPUTHANDLER_H
