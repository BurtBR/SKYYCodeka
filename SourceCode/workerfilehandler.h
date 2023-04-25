#ifndef WORKERFILEHANDLER_H
#define WORKERFILEHANDLER_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class WorkerFileHandler : public QObject{
    //Q_OBJECT macro needs to be used with QT as indicated
    //in the QObject class documentation:
    //The Q_OBJECT macro must appear in the private section of a class
    //definition that declares its own signals and slots or that uses
    //other services provided by Qt's meta-object system.
    Q_OBJECT
public:
    WorkerFileHandler(QObject *parent = nullptr);

public slots:
    void LoadFile(QString filepath);
    void SaveFile(QString text, QString filepath);

signals:
    void Error(int type, QString message = QString(), int errorline = -1);
    void Done(int type, QString message = QString());
    void TextLoaded(QString text);
};

#endif // WORKERFILEHANDLER_H
