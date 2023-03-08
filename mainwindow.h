#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogpopup.h"
#include "codeeditor.h"

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
    Ui::MainWindow *ui;
    CodeEditor *codeEditor;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
