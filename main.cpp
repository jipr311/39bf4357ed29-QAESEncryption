#include <QCoreApplication>
#include <QTest>
#include <QCryptographicHash>

#include "unit_test/aestest.h"
#include "qaesencryption.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    AesTest test1;
//    QTest::qExec(&test1);
    QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::ECB, QAESEncryption::Padding::PKCS7);

    QString inputStr("HelloWorld");
    QString inputStrs("a");
    QString key("AmARobot!");

    QByteArray hashKey = QCryptographicHash::hash(key.toLocal8Bit(), QCryptographicHash::Sha256);

    QByteArray encodeText = encryption.encode(inputStr.toLocal8Bit(), hashKey);
    QByteArray decodedText = encryption.removePadding(encryption.decode(encodeText, hashKey));
    qDebug() << "s: " << inputStrs;
    qDebug() << "inputStr: " << inputStr;
    qDebug() << "encodeText: " << encodeText;
    qDebug() << "decodedText: " << decodedText;

    return 0;
}


