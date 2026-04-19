#include "reader.h"
#include <QDebug>
#include <QSerialPortInfo>


reader::reader(QObject * parent):QObject(parent)
{
    qDebug("Reader luotu");
    port = new QSerialPort(this);
}

reader::~reader()
{
    qDebug("Reader tuhottu");
}

void reader::readInfo()
{
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &portInfo : serialPortInfos) {
        qDebug() << "\n"
                 << "Port:" << portInfo.portName() << "\n"
                 << "Location:" << portInfo.systemLocation() << "\n"
                 << "Description:" << portInfo.description() << "\n"
                 << "Manufacturer:" << portInfo.manufacturer() << "\n"
                 << "Serial number:" << portInfo.serialNumber() << "\n"
                 << "Vendor Identifier:"
                 << (portInfo.hasVendorIdentifier()
                         ? QByteArray::number(portInfo.vendorIdentifier(), 16)
                         : QByteArray()) << "\n"
                 << "Product Identifier:"
                 << (portInfo.hasProductIdentifier()
                         ? QByteArray::number(portInfo.productIdentifier(), 16)
                         : QByteArray());
    }
    qDebug("infon lopussa");
}


bool reader::open()
{
    qDebug() << "open funktiossa";
    bool returnValue = false;
    const auto ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : ports)
    {
        qDebug() << "Tarkistetaan portti:" << info.portName();
        if (info.serialNumber() == "OL415CF004C5387")
        {
            qDebug() << "Laite löytyi" << info.portName();
            port->setPort(info);
            returnValue = port->open(QIODeviceBase::ReadOnly);
            if (returnValue)
            {
                connect(port, &QSerialPort::readyRead,
                        this, &reader::handleInterrupt);
            }

            break;
        }
    }

    qDebug() << "returnValue =" << returnValue;
    qDebug() << "open funktion lopussa";

    return returnValue;
}

void reader::handleInterrupt()
{
    QByteArray luettu = port->readAll();
    qDebug()<<(QString::fromUtf8(luettu));
    emit sendSerialData(luettu);

}
