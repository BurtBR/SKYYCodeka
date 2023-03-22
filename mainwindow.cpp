#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    //Instantiate codeEditor (text area)
    try{
        codeEditor = new CodeEditor(this);
    }catch(...){
        throw "Erro ao instanciar o editor de código";
    }
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

    LoadConfigFile();
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

bool MainWindow::StartCompilerThread(){

    if(threadWorking)
        return false;

    WorkerCompiler *worker = nullptr;

    try{
        threadWorking = new QThread();
    }catch(...){
        return false;
    }

    try{
        worker = new WorkerCompiler();
    }catch(...){
        delete threadWorking;
        threadWorking = nullptr;
        return false;
    }

    worker->moveToThread(threadWorking);
    threadWorking->start();

    //Connect Signals and Slots
    connect(threadWorking, &QThread::finished, worker, &WorkerCompiler::deleteLater);
    connect(worker, &WorkerCompiler::Error, this, WorkerError);
    connect(worker, &WorkerCompiler::Done, this, WorkerDone);
    connect(this, WorkerCompile, worker, &WorkerCompiler::Compile);

    return true;
}

void MainWindow::LoadConfigFile(){

    QFile configfile("configuramento.skyy");

    if(!configfile.exists()){

        QTextStream IOStream(&configfile);

        if(!configfile.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        IOStream << "lastfile=";

        configfile.close();

    }else{

        if(!configfile.open(QIODevice::ReadOnly | QIODevice::Text)){
            ui->textMessages->append(QDateTime::currentDateTime().toString("hh:mm:ss") +
                                     " ERRO: Não foi possível abrir o arquivo de configuração!");
            return;
        }

        while(!configfile.atEnd()){
            ProcessConfiLine(configfile.readLine().trimmed());
        }

        configfile.close();

    }

}

void MainWindow::ProcessConfiLine(QString line){

    if(!line.size())
        return;

    QStringList config = line.split('=');

    if(config.size() != 2)
        return;

    if(!config[0].compare("lastfile")){
        OpenFile(config[1]);
    }

}

void MainWindow::SaveConfigParameter(QString parameter, QString value){

    QFile configfile("configuramento.skyy");
    QTextStream IOStream(&configfile);
    QString text, line;
    QStringList strlist;

    if(!configfile.exists()){
        text = parameter + "=" + value;
    }else{

        //Open File
        if(!configfile.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        while(!configfile.atEnd()){

            line = configfile.readLine().trimmed();
            strlist = line.split('=');

            //If the parameter is the same as the one read in the file
            if(!parameter.compare(strlist[0]))
                text.append(parameter + "=" + value + '\n');
            else
                text.append(line + "\n");

        }

        //CloseFile
        configfile.close();

        //Error redundancy
        if(!text.size())
            text = parameter + "=" + value;

    }

    //Open File
    if(!configfile.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    //Write to file
    IOStream << text;

    //Close File
    configfile.close();

}

void MainWindow::KillAllThreads(){

    if(threadWorking){
        threadWorking->quit();
        while(!threadWorking->wait());
        delete threadWorking;
        threadWorking = nullptr;
    }

    ui->labelGif->clear();

}

void MainWindow::NewFile(){

    codeEditor->clear();
    isSaved = true;
    this->setWindowTitle("SKYY Codka - (Salvo)");
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
        SaveConfigParameter("lastfile", currentFilePath);
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
        SaveConfigParameter("lastfile", currentFilePath);
        this->setEnabled(false);
        emit WorkerSave(codeEditor->toPlainText(), filepath);
    }else{
        ui->textMessages->append(QDateTime::currentDateTime().toString("hh:mm:ss") + " ERRO: Não foi possível iniciar nova thread");
    }
}

void MainWindow::Build(){
    ui->textMessages->append(QDateTime::currentDateTime().toString("hh:mm:ss") + " INFO: Compilando...");

    if(StartCompilerThread()){

        //Disable Main Window
        this->setEnabled(false);

        //Start gif
        QMovie *movie = nullptr;
        try{
            movie = new QMovie(":/Gifs/Working.gif");
            connect(threadWorking, &QThread::finished, movie , &QMovie::deleteLater);
            ui->labelGif->setMovie(movie);
            ui->labelGif->setScaledContents(true);
            movie->start();
        }catch(...){

        }

        emit WorkerCompile(codeEditor->toPlainText());

    }else{
        ui->textMessages->append(QDateTime::currentDateTime().toString("hh:mm:ss") + " ERRO: Não foi possível compilar");
    }

}

void MainWindow::RunCode(){

}

//---------------------------SLOTS---------------------------
void MainWindow::EditorTextEdited(){
    isSaved = false;
    this->setWindowTitle("SKYY Codka - (Não salvo)");
}

void MainWindow::WorkerError(int type, QString message, int errorline){

    KillAllThreads();

    QString errorMessage = QDateTime::currentDateTime().toString("hh:mm:ss") + " ERRO: ";

    switch(type){
    case 0: //Load File
        errorMessage.append(message);
        break;

    case 1: //Save File
        errorMessage.append(message);
        break;

    case 2: //Compiler Error
        errorMessage.append("Linha " + QString::number(errorline) + ": " + message);
        codeEditor->setTextCursor(QTextCursor(codeEditor->document()->findBlockByLineNumber(errorline)));
        break;

    case 3: //Run Error
        break;

    default: //Unknown Error
        errorMessage.append("Erro desconhecido!");
        break;
    }

    //Change text color to red
    QTextCharFormat charFormat = ui->textMessages->currentCharFormat();
    charFormat.setForeground(QBrush(Qt::yellow));
    ui->textMessages->setCurrentCharFormat(charFormat);
    ui->textMessages->append(errorMessage);

    this->setEnabled(true);

}

void MainWindow::WorkerDone(int type, QString /*message*/){

    KillAllThreads();

    //Change text color to white
    QTextCharFormat charFormat = ui->textMessages->currentCharFormat();
    charFormat.setForeground(QBrush(Qt::white));
    ui->textMessages->setCurrentCharFormat(charFormat);

    QString doneMessage = QDateTime::currentDateTime().toString("hh:mm:ss") + " INFO: ";

    switch(type){
    case 0: //Load File
        doneMessage.append("Arquivo carregado com sucesso! ");
        isSaved = true;
        this->setWindowTitle("SKYY Codka - (Salvo)");
        break;

    case 1: //Save File
        doneMessage.append("Arquivo salvo com sucesso! ");
        isSaved = true;
        this->setWindowTitle("SKYY Codka - (Salvo)");
        break;

    case 2: //Compiler
        doneMessage.append("Compilado com sucesso!");

        if(runCode)
            RunCode();

        break;

    case 3: //Run
        doneMessage.append("Executando...");
        break;

    default: //Unknown
        break;
    }

    this->setEnabled(true);

    //Show message
    ui->textMessages->append(doneMessage);

    if(type == 2 && runCode)
        RunCode();
}

void MainWindow::WorkerTextLoaded(QString message){
    codeEditor->appendPlainText(message);
}

void MainWindow::On_buttonNew_clicked(){

    if(!isSaved){
        if(!DialogPopup(1, "Camarada deseja apagar sem salvar?").exec())
            return;
    }

    NewFile();
}

void MainWindow::On_buttonOpen_clicked(){

    if(!isSaved){
        if(!DialogPopup(1, "Camarada deseja apagar sem salvar?").exec())
            return;
    }

    QString filepath = QFileDialog::getOpenFileName(this, "Abrir Arquivo", "", "Codeka Files (*.cdk)");

    if(filepath.size())
        OpenFile(filepath);

}

void MainWindow::On_buttonSave_clicked(){

    if(isSaved){
        DialogPopup(0, "Camarada o arquivo está salvo!").exec();
        return;
    }

    SaveFile(currentFilePath);
}

void MainWindow::On_buttonSaveAs_clicked(){
    SaveFile(QString());
}

void MainWindow::On_buttonBuild_clicked(){
    runCode = false;
    Build();
}

void MainWindow::On_buttonBuildRun_clicked(){
    runCode = true;
    Build();
}
//---------------------------SLOTS---------------------------
