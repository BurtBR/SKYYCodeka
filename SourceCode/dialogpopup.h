#ifndef DIALOGPOPUP_H
#define DIALOGPOPUP_H

#include <QDialog>      //Class from which DialogPopup inherits
#include <QKeyEvent>    //Class QKeyEvent used in keyPressEvent method

namespace Ui { class DialogPopup; }

class DialogPopup : public QDialog{
    //Q_OBJECT macro needs to be used with QT as indicated
    //in the QObject class documentation:
    //The Q_OBJECT macro must appear in the private section of a class
    //definition that declares its own signals and slots or that uses
    //other services provided by Qt's meta-object system.
    Q_OBJECT

public:
    //Constructor
    DialogPopup(char dialogType = 0,
                QString dialogMessage = QString(),
                QPixmap dialogImage = QPixmap(":/Icons/Exclamation.png"),
                QWidget *parent = nullptr);
    //Destructor
    ~DialogPopup();

private slots:
    void On_ButtonYes_clicked();    //Called when ButtonYes is clicked
    void On_ButtonNo_clicked();     //Called when ButtonNo is clicked

private:
    //Private Attributes
    Ui::DialogPopup *ui;    //UI

    //Private Methods
    void keyPressEvent(QKeyEvent *event);   //Called when a button is pressed and this widget is in focus
};

#endif // DIALOGPOPUP_H
