#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    codeEditor = new CodeEditor(this);
    codeEditor->setTabStopDistance(20);
    ui->layoutEditor->addWidget(codeEditor);
    codeEditor->setFocus();
}

MainWindow::~MainWindow(){
    delete ui;
    delete codeEditor;
}

