#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "dialogpopup.h"
#include "codeeditor.h"

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
    CodeEditor *codeEditor;
    QString currentFilePath;
    bool isSaved = true;

    //Private Methods
    void NewFile();
    void OpenFile(QString filepath);
    void SaveFile(QString filepath);
    void Build();
    void Run();
    void closeEvent(QCloseEvent *event) override;

public:
    MainWindow(QWidget *parent = nullptr); //Constructor
    ~MainWindow(); //Destructor

private slots:
    void On_buttonNew_clicked();
    void On_buttonOpen_clicked();
    void On_buttonSave_clicked();
    void On_buttonSaveAs_clicked();
    void On_buttonBuild_clicked();
    void On_buttonBuildRun_clicked();
    void EditorTextEdited();
};
#endif // MAINWINDOW_H
