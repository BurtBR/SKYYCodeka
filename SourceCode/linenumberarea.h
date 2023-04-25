#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H

#include <QWidget>
#include "codeeditor.h"

class CodeEditor;

class LineNumberArea : public QWidget{
    //Q_OBJECT macro needs to be used with QT as indicated
    //in the QObject class documentation:
    //The Q_OBJECT macro must appear in the private section of a class
    //definition that declares its own signals and slots or that uses
    //other services provided by Qt's meta-object system.
    Q_OBJECT

private:
    CodeEditor *codeEditor;

protected:
    void paintEvent(QPaintEvent *event) override;

public:
    LineNumberArea(CodeEditor *editor); //Constructor

    QSize sizeHint() const override;
};

#endif // LINENUMBERAREA_H
