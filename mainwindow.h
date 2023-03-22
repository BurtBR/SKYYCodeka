#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QByteArray>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QDateTime>
#include <QThread>
#include <QMovie>
#include "dialogpopup.h"
#include "codeeditor.h"
#include "workerfilehandler.h"
#include "workercompiler.h"

//TEMPORARIO
#include <QDebug>
//TEMPORARIO

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    //Q_OBJECT macro needs to be used with QT as indicated
    //in the QObject class documentation:
    //The Q_OBJECT macro must appear in the private section of a class
    //definition that declares its own signals and slots or that uses
    //other services provided by Qt's meta-object system.
    Q_OBJECT

private:
    //Private Attributes
    Ui::MainWindow *ui;
    QThread *threadWorking = nullptr;
    CodeEditor *codeEditor;
    QString currentFilePath;
    bool isSaved = true;
    bool runCode = false;

    //Private Methods
    bool StartFileThread();
    bool StartCompilerThread();
    void LoadConfigFile();
    void ProcessConfiLine(QString line);
    void SaveConfigParameter(QString parameter, QString value);
    void KillAllThreads();
    void NewFile();
    void OpenFile(QString filepath);
    void SaveFile(QString filepath);
    void Build();
    void RunCode();
    void closeEvent(QCloseEvent *event) override;

public:
    MainWindow(QWidget *parent = nullptr); //Constructor
    ~MainWindow(); //Destructor

private slots:
    //Buttons
    void On_buttonNew_clicked();
    void On_buttonOpen_clicked();
    void On_buttonSave_clicked();
    void On_buttonSaveAs_clicked();
    void On_buttonBuild_clicked();
    void On_buttonBuildRun_clicked();
    //Other
    void DisplayMessage(QString text, int messagetype = 1);
    void EditorTextEdited();
    void WorkerError(int type, QString message, int errorline = -1);
    void WorkerDone(int type, QString message);
    void WorkerTextLoaded(QString message);

signals:
    void WorkerSave(QString text, QString filepath);
    void WorkerLoad(QString filepath);
    void WorkerCompile(QString code);

};
#endif // MAINWINDOW_H
