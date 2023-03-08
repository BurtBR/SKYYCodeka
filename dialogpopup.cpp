#include "dialogpopup.h"
#include "ui_dialogpopup.h"

//Constructor
DialogPopup::DialogPopup(char dialogType,
                         QString dialogMessage,
                         QPixmap dialogImage,
                         QWidget *parent
                         ) : QDialog(parent), ui(new Ui::DialogPopup){
    //Setup UI
    ui->setupUi(this);

    switch(dialogType){
        case 0: //Information Dialog
            ui->LabelImage->setPixmap(dialogImage.scaled(150, 150, Qt::KeepAspectRatio));
            ui->TextEditMessage->setText(dialogMessage);
            ui->ButtonNo->hide();
            ui->ButtonYes->setGeometry(0, 230, 700, 70);
            ui->ButtonYes->setText("Ok");
            this->setWindowIcon(QIcon(":/Icons/Nuclear.png"));
            break;

        case 1: //Question Dialog
            ui->LabelImage->setPixmap(QPixmap(":/Icons/Question.png").scaled(150, 150, Qt::KeepAspectRatio));
            ui->TextEditMessage->setText(dialogMessage);
            this->setWindowIcon(QIcon(":/Icons/Question.png"));
            break;

        default:
            break;
    }

    //Remove "?" from window upper bar
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    //Connect buttons to signals
    connect(ui->ButtonYes, &QToolButton::clicked, this, On_ButtonYes_clicked);
    connect(ui->ButtonNo, &QToolButton::clicked, this, On_ButtonNo_clicked);
}

//Destructor
DialogPopup::~DialogPopup(){
    delete ui;
}

void DialogPopup::On_ButtonYes_clicked(){
    this->accept();
}

void DialogPopup::On_ButtonNo_clicked(){
    this->reject();
}

void DialogPopup::keyPressEvent(QKeyEvent *event){

    //If the key pressed is Enter, the dialog will be accepted (works like clicking Yes)
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        this->accept();
    else
        return QDialog::keyPressEvent(event);
}
