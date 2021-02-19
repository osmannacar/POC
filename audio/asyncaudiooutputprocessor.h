#ifndef ASYNCAUDIOOUTPUTPROCESSOR_H
#define ASYNCAUDIOOUTPUTPROCESSOR_H

#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudioOutput>

#include "thread/athread.h"

class AsyncAudioOutputProcessor : public AThread
{
    Q_OBJECT
public:
    explicit AsyncAudioOutputProcessor(QObject *parent = nullptr);
    void mainLoop() override;

public slots:
    void newAudioOutput(QByteArray pBuffer);

 private:
    QAudioOutput *mOutput;
    QIODevice *mDevice;
};

#endif // ASYNCAUDIOOUTPUTPROCESSOR_H
