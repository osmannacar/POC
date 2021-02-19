#include "filereceiverserilization.h"

FileReceiverSerilization::FileReceiverSerilization(QObject *parent)
    : QObject(parent)
    , mBuffer(0)
    , mFilename(QString())
{

}

void FileReceiverSerilization::newFileData(QByteArray pBuffer)
{
    if(pBuffer == END_OF_FILE){
        collectFileFromData();
    }else if (mFilename.size() == 0) {
        mFilename = pBuffer;
    }else {
        mBuffer.append(pBuffer);
    }
}

void FileReceiverSerilization::collectFileFromData()
{
    onNewFile(mFilename, mBuffer);
    mBuffer.clear();
    mFilename.clear();
}
