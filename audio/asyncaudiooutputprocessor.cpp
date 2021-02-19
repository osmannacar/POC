#include "asyncaudiooutputprocessor.h"

#include <QApplication>
#include <QAbstractEventDispatcher>

AsyncAudioOutputProcessor::AsyncAudioOutputProcessor(QObject *parent)
    : AThread(parent)
    , mOutput(nullptr)
    , mDevice(nullptr)
{

}

void AsyncAudioOutputProcessor::mainLoop()
{
    QAudioFormat format;
    format.setSampleRate(128000);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if (!info.isFormatSupported(format))
        format = info.nearestFormat(format);

    mOutput = new QAudioOutput(format);
    mDevice = mOutput->start();

    while (isRunnning()) {
        if(QThread::currentThread()->eventDispatcher()->hasPendingEvents()){
            qApp->processEvents();
        }else {
            QThread::msleep(1);
        }
    }
    mDevice->close();
    mDevice->deleteLater();
    mOutput->deleteLater();
}

void AsyncAudioOutputProcessor::newAudioOutput(QByteArray pBuffer)
{
    if(mDevice)
        mDevice->write(pBuffer.data(), pBuffer.size());
}
