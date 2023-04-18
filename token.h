#ifndef TOKEN_H
#define TOKEN_H

class Token{

private:
    //Private Attributes

public:
    Token();

    enum class TokenType{
        unidentified,   //0
        mainfunction,   //1
        keyword,        //2
        identifier,     //3
        constant,       //4
        operation,      //5
        begincode,      //6
        endcode,        //7
        beginargument,  //8
        endargument,    //9
        eol,            //10
        separator       //11
    };

    enum class Keywords{
        intsky,         //0
        charovsky,      //1
        floatsky,       //2
        bolichisky,     //3
        chernobyl,      //4
        palavrovka,     //5
        michwhail,      //6
        forevisky,      //7
        ikov,           //8
        kalashn,        //9
        niet,           //10
        yebat,          //11
        strongon,       //12
        strongonoff     //13
    };

    enum class Operations{
        plus,           //0
        minus,          //1
        times,          //2
        division,       //3
        attribution,    //4
        equalequal,     //5
        notequal,       //6
        bigger,         //7
        smaller,        //8
        biggerequal,    //9
        smallerequal,   //10
        and_op,         //12
        or_op,          //13
        plusplus,       //14
        minusminus      //15
    };

};

#endif // TOKEN_H
