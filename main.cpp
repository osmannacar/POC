#include <QApplication>

#include "udp/asyncudptransmitter.h"
#include "audio/asyncaudioinputhandler.h"

#include "audio/asyncaudiooutputprocessor.h"
#include "udp/asyncudpreceiver.h"

#include "serilization/imagereceiverserilization.h"
#include "serilization/filereceiverserilization.h"
#include "fileSystem/filesystem.h"

#include <QBuffer>
#include <QTimer>
#include <QStandardPaths>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    //  File test
//    AsyncUdpReceiver *receiver = new AsyncUdpReceiver(1234, QHostAddress("127.0.0.1"));
//    AsyncUdpTransmitter *transmitter = new AsyncUdpTransmitter(1234, QHostAddress("127.0.0.1"));
//    IFileIO *fileSystem = new FileSystem();

//    FileReceiverSerilization *serilization = new FileReceiverSerilization(receiver);
//    QObject::connect(receiver, &AsyncUdpReceiver::onNewMessage, serilization, &FileReceiverSerilization::newFileData);

//    QObject::connect(serilization, &FileReceiverSerilization::onNewFile, serilization, [fileSystem](QString fileName, QByteArray fileData){
//        QString path = (QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)) + "/" + fileName;
//        qDebug() << "IFileIO write result:" << fileSystem->write(path, fileData);

//    });


//    receiver->start();
//    transmitter->start();
//    QTimer::singleShot(1000, transmitter, [transmitter, fileSystem](){
//        QString path = "/home/oscar/Desktop/Proje/a.txt";
//        QStringList parts = path.split("/");
//        QString filename = parts.at(parts.size() - 1);
//        QByteArray data = fileSystem->read(path);
//        if(!data.isEmpty()){
//            qDebug() << "Start send a file:" << filename;
//            transmitter->send(filename.toUtf8());
//            transmitter->send(data);
//            transmitter->send(FileReceiverSerilization::END_OF_FILE);
//            qDebug() << "Finished send a file";
//        }else {
//            qDebug() << "IFileIO cannot readed";
//        }

//    });



    ////  Image test
    //    AsyncUdpReceiver *receiver = new AsyncUdpReceiver(1234, QHostAddress("127.0.0.1"));
    //    AsyncUdpTransmitter *transmitter = new AsyncUdpTransmitter(1234, QHostAddress("127.0.0.1"));

    //    ImageReceiverSerilization *serilization = new ImageReceiverSerilization(receiver);
    //    QObject::connect(receiver, &AsyncUdpReceiver::onNewMessage, receiver,[serilization](QByteArray buffer){
    //        serilization->newImageData(buffer);
    //    });

    //    QObject::connect(serilization, &ImageReceiverSerilization::onNewImage, receiver, [serilization](QImage img){
    //       qDebug() << "new img" << img;
    //    });


    //    receiver->start();
    //    transmitter->start();
    //    QTimer::singleShot(1000, transmitter, [transmitter](){
    //        QImage img("/home/oscar/Downloads/EmiliaClarke-1.jpg");
    //        QByteArray arr;
    //        QBuffer buffer(&arr);
    //        buffer.open(QIODevice::WriteOnly);
    //        img.save(&buffer, "JPEG");
    //        qDebug() << "send image" << img;
    //        transmitter->send(arr);
    //    });



    ////  audio test
    //    AsyncAudioOutputProcessor *processor = new AsyncAudioOutputProcessor();
    //    AsyncUdpReceiver *receiver = new AsyncUdpReceiver(1234, QHostAddress("127.0.0.1"));
    //    QObject::connect(receiver, &AsyncUdpReceiver::onNewMessage, processor, &AsyncAudioOutputProcessor::newAudioOutput);
    //    processor->start();

    //    receiver->start();

    //    AsyncUdpTransmitter *transmitter = new AsyncUdpTransmitter(1234, QHostAddress("127.0.0.1"));
    //    AsyncAudioInputHandler *handler = new AsyncAudioInputHandler();

    //    QObject::connect(handler, &AsyncAudioInputHandler::onNewAudioInput, transmitter, &AsyncUdpTransmitter::send);
    //    transmitter->start();
    //    handler->start();

    return app.exec();
}
