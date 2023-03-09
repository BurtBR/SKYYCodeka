#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    codeEditor = new CodeEditor(this);
    codeEditor->setTabStopDistance(20);
    ui->layoutEditor->addWidget(codeEditor);
    codeEditor->setFocus();

    //Connect Signals And Slots
    //Buttons
    connect(ui->buttonNew, &QToolButton::clicked, this, On_buttonNew_clicked);
    connect(ui->buttonOpen, &QToolButton::clicked, this, On_buttonOpen_clicked);
    connect(ui->buttonSave, &QToolButton::clicked, this, On_buttonSave_clicked);
    connect(ui->buttonSaveAs, &QToolButton::clicked, this, On_buttonSaveAs_clicked);
    connect(ui->buttonBuild, &QToolButton::clicked, this, On_buttonBuild_clicked);
    connect(ui->buttonBuildRun, &QToolButton::clicked, this, On_buttonBuildRun_clicked);
    //Other
    connect(codeEditor, QPlainTextEdit::textChanged, this, EditorTextEdited);
}

MainWindow::~MainWindow(){
    KillAllThreads();
    delete ui;
    delete codeEditor;
}

void MainWindow::closeEvent(QCloseEvent *event){

    if(!isSaved){
        if(DialogPopup(1, "Deseja sair sem salvar?").exec())
            QMainWindow::closeEvent(event);
        else
            event->ignore();
    }else{
        QMainWindow::closeEvent(event);
    }
}

bool MainWindow::StartFileThread(){

    if(threadWorking)
        return false;

    WorkerFileHandler *worker = nullptr;

    try{
        threadWorking = new QThread();
    }catch(...){
        return false;
    }

    try{
        worker = new WorkerFileHandler();
    }catch(...){
        delete threadWorking;
        threadWorking = nullptr;
        return false;
    }

    //Connect Signals and Slots
    connect(threadWorking, &QThread::finished, worker, &WorkerFileHandler::deleteLater);
    connect(worker, &WorkerFileHandler::Error, this, WorkerError);
    connect(worker, &WorkerFileHandler::Done, this, WorkerDone);
    connect(worker, &WorkerFileHandler::TextLoaded, this, WorkerTextLoaded);
    connect(this, WorkerLoad, worker, &WorkerFileHandler::LoadFile);
    connect(this, WorkerSave, worker, &WorkerFileHandler::SaveFile);

    worker->moveToThread(threadWorking);
    threadWorking->start();

    return true;
}

void MainWindow::KillAllThreads(){

    if(threadWorking){
        threadWorking->quit();
        while(!threadWorking->wait());
        delete threadWorking;
        threadWorking = nullptr;
    }

}

void MainWindow::NewFile(){

    codeEditor->clear();
    isSaved = true;
    currentFilePath.clear();
}

void MainWindow::OpenFile(QString filepath){

    QFileInfo fileInfo = QFileInfo(filepath);

    if(!fileInfo.exists()){
        ui->textMessages->append(QDateTime::currentDateTime().toString("hh:mm:ss") + " ERRO: O arquivo não existe!");
        return;
    }else if(QString::compare(fileInfo.suffix(),"cdk")){
        ui->textMessages->append(QDateTime::currentDateTime().toString("hh:mm:ss") + " ERRO: O arquivo não é compatível!");
        return;
    }

    NewFile();

    if(StartFileThread()){
        currentFilePath = filepath;
        this->setEnabled(false);
        emit WorkerLoad(filepath);
    }else{
        ui->textMessages->append(QDateTime::currentDateTime().toString("hh:mm:ss") + " ERRO: Não foi possível iniciar nova thread");
    }

}

void MainWindow::SaveFile(QString filepath){

    if(!filepath.size()){ //Save path unknown (Save As...)

        filepath = QFileDialog::getSaveFileName(this, "Abrir Arquivo", "", "Codeka Files (*.cdk)");
        if(!filepath.size())
            return;

    }

    if(StartFileThread()){
        currentFilePath = filepath;
        this->setEnabled(false);
        emit WorkerSave(codeEditor->toPlainText(), filepath);
    }else{
        ui->textMessages->append(QDateTime::currentDateTime().toString("hh:mm:ss") + " ERRO: Não foi possível iniciar nova thread");
    }
}

void MainWindow::Build(){

}

void MainWindow::Run(){

}

//---------------------------SLOTS---------------------------
void MainWindow::EditorTextEdited(){
    isSaved = false;
}

void MainWindow::WorkerError(int type, QString message){

    QString errorMessage = "ERRO: ";

    switch(type){
    case 0: //Load File
        errorMessage.append(message);
        break;

    case 1: //Save File
        errorMessage.append(message);
        break;

    default: //Unknown Error
        errorMessage.append("Erro desconhecido!");
        break;
    }

    KillAllThreads();
    DialogPopup(0, errorMessage).exec();

    this->setEnabled(true);

}

void MainWindow::WorkerDone(int type, QString message){

    QString doneMessage = QDateTime::currentDateTime().toString("hh:mm:ss") + " INFO: ";

    switch(type){
    case 0: //Load File
        doneMessage.append("Arquivo carregado com sucesso! " + message);
        isSaved = true;
        break;

    case 1: //Save File
        doneMessage.append("Arquivo salvo com sucesso! " + message);
        isSaved = true;
        break;

    default: //Unknown
        break;
    }

    KillAllThreads();
    this->setEnabled(true);

    ui->textMessages->append(doneMessage);
}

void MainWindow::WorkerTextLoaded(QString message){
    codeEditor->appendPlainText(message);
}

void MainWindow::On_buttonNew_clicked(){

    if(!isSaved){
        if(!DialogPopup(1, "Deseja apagar sem salvar?").exec())
            return;
    }

    NewFile();
}

void MainWindow::On_buttonOpen_clicked(){

    if(!isSaved){
        if(!DialogPopup(1, "Deseja apagar sem salvar?").exec())
            return;
    }

    QString filepath = QFileDialog::getOpenFileName(this, "Abrir Arquivo", "", "Codeka Files (*.cdk)");

    if(filepath.size())
        OpenFile(filepath);

}

void MainWindow::On_buttonSave_clicked(){

    if(isSaved){
        DialogPopup(0, "O arquivo está salvo!").exec();
        return;
    }

    SaveFile(currentFilePath);
}

void MainWindow::On_buttonSaveAs_clicked(){
    SaveFile(QString());
}

void MainWindow::On_buttonBuild_clicked(){

}

void MainWindow::On_buttonBuildRun_clicked(){

}
//---------------------------SLOTS---------------------------
