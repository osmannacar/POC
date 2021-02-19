#include "asyncaudioinputhandler.h"

#include <QApplication>
#include <QAbstractEventDispatcher>

AsyncAudioInputHandler::AsyncAudioInputHandler(QObject *parent)
    : AThread(parent)
    , mInput(nullptr)
    , mDevice(nullptr)
{

}

void AsyncAudioInputHandler::mainLoop()
{

    QAudioFormat format;
    format.setSampleRate(128000);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    //If format isn't supported find the nearest supported
    QAudioDeviceInfo info(QAudioDeviceInfo::defaultInputDevice());
    if (!info.isFormatSupported(format))
        format = info.nearestFormat(format);
    mInput =  new QAudioInput(info, format);

    mDevice = mInput->start();
    QObject::connect(mDevice, &QIODevice::readyRead, this, &AsyncAudioInputHandler::readyToRead);

    while (isRunnning()) {
        if(QThread::currentThread()->eventDispatcher()->hasPendingEvents()){
            qApp->processEvents();
        }else {
            QThread::msleep(1);
        }
    }
    QObject::disconnect(mDevice, &QIODevice::readyRead, this, &AsyncAudioInputHandler::readyToRead);
    mDevice->close();
    mDevice->deleteLater();
    mInput->deleteLater();
}

void AsyncAudioInputHandler::readyToRead()
{
    emit onNewAudioInput(mDevice->readAll());
}
