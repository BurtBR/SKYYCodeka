#include "linenumberarea.h"

LineNumberArea::LineNumberArea(CodeEditor *editor) : QWidget(editor), codeEditor(editor){

}

void LineNumberArea::paintEvent(QPaintEvent *event){
    codeEditor->lineNumberAreaPaintEvent(event);
}

QSize LineNumberArea::sizeHint() const{
    return QSize(codeEditor->lineNumberAreaWidth(), 0);
}
