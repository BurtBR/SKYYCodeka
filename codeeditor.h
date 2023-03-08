#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>
#include <QTextBlock>
#include <QWidget>
#include <QList>
#include <QColor>
#include <QPainter>
//#include "linenumberarea.h"

class CodeEditor : public QPlainTextEdit{
    //Q_OBJECT macro needs to be used with QT as indicated
    //in the QObject class documentation:
    //The Q_OBJECT macro must appear in the private section of a class
    //definition that declares its own signals and slots or that uses
    //other services provided by Qt's meta-object system.
    Q_OBJECT

private:
    //Private Attributes
    QWidget *lineNumberArea;

protected:
    void resizeEvent(QResizeEvent *event) override; //Override QPlainTextEdit method resizeEvent

public:
    CodeEditor(QWidget *parent = nullptr); //Constructor

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &rect, int dy);
};

#endif // CODEEDITOR_H
