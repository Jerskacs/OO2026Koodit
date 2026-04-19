#ifndef READER_H
#define READER_H

#include <QByteArray>
#include <QObject>
#include <QtSerialPort>

class reader : public QObject
{
    Q_OBJECT
public:
    reader(QObject * parent = nullptr);
    ~reader();
    void readInfo();
    bool open();
signals:
    void sendSerialData(QByteArray);

private slots:
    void handleInterrupt();

private:
    QSerialPort * port;

};

#endif // READER_H
