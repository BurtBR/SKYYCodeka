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

void MainWindow::NewFile(){

    codeEditor->clear();
    isSaved = true;
    currentFilePath.clear();
}

void MainWindow::OpenFile(QString filepath){

    QFileInfo fileInfo = QFileInfo(filepath);
    QFile file(filepath);
    QTextStream in;

    if(!fileInfo.exists()){
        ui->textMessages->append(QDateTime::currentDateTime().toString("hh:mm:ss") + " ERRO: O arquivo não existe!");
        return;
    }else if(QString::compare(fileInfo.suffix(),"cdk")){
        ui->textMessages->append(QDateTime::currentDateTime().toString("hh:mm:ss") + " ERRO: O arquivo não é compatível!");
        return;
    }

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        ui->textMessages->append(QDateTime::currentDateTime().toString("hh:mm:ss") + " ERRO: Não foi possível abrir o arquivo");
        return;
    }

    NewFile();

    in.setDevice(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        codeEditor->appendPlainText(line);
    }

    file.close();
    isSaved = true;
    ui->textMessages->append(QDateTime::currentDateTime().toString("hh:mm:ss") + " INFO: Arquivo carregado com sucesso");
}

void MainWindow::SaveFile(QString filepath){

    if(isSaved){
        DialogPopup(0, "O arquivo está salvo!").exec();
        return;
    }

    QFile file(filepath);
    QTextStream out(&file);

    if(filepath.size()){ //Save path known

    }else{ //Save AS...
        QFileDialog fileDialog;
        fileDialog.setFileMode(QFileDialog::AnyFile);

        filepath = fileDialog.getSaveFileName(this, "Abrir Arquivo", "", "Codeka Files (*.cdk)");
        if(!filepath.size())
            return;

        file.setFileName(filepath);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            ui->textMessages->append(QDateTime::currentDateTime().toString("hh:mm:ss") + " ERRO: Não foi possível abrir o arquivo");
            return;
        }



        file.close();
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
