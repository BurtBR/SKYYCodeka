# COMO FAZER DOWNLOAD E UTILIZAR
Vá para a página de releases: https://github.com/BurtBR/SKYYCodeka/releases/tag/Release
Faça o download do arquivo SKYYCodeka_Vx_x.zip
Extraia em alguma pasta no seu computador
Execute SKYYCodeka.exe

## Observação
O compilador gera alguns arquivos que têm a finalidade de visualização das etapas de compilação. Esses arquivos são gerados a cada compilação e são salvos na pasta "GENERATED FILES" com a extensão .skyy. Para visualizá-los, abra-os em um arquivo de edição de texto como o notepad++.

# PALAVRAS RESERVADAS
**Código** | **Descrição**
:---------|:---------
motherland 	| função principal (main)
moscow 		| definição de função com retorno
chernobyl 	| definição de função sem retorno
forevisky 	| bloco de repetição
tovarish 	| chamada de função
ikov 		| bloco condicional
kalashn 	| bloco condicional else
strongon 	| valor lógico verdadeiro
strongonoff | valor lógico falso
yebat 		| chamada de retorno da função
niet 		| operador lógico de negação
pow			| operador elevado a potência

# TIPOS DE DADOS
**Código** | **Descrição**
:--------|:--------
intsky | inteiro de 4 bytes
charovsky | caractere de 1 byte
floatsky | ponto flutuante de 4 bytes
bolichisky | valor lógico booleano
palavrovka | vetor de caracteres (string)

# OPERADORES
**Código** | **Descrição**
:---------|:---------
\+ 	| soma
\- 	| subtração
\* 	| multiplicação
/ 	| divisão
&& 	| operação lógica AND
\|\| 	| operação lógica OR
== 	| operação lógica IGUAL A
!= 	| operação lógica DIFERENTE DE
\>= 	| operação lógica MAIOR OU IGUAL
\<= 	| operação lógica MENOR OU IGUAL
\< 	| operação lógica MENOR
\> 	| operação lógica MAIOR
niet| operação lógica NOT
pow | elevado à potência

# CARACTERES ESPECIAIS
**Código** | **Descrição**
:---------|:---------
{ 	| inicio de bloco de código
} 	| fim de bloco de código
( 	| inicio de argumentos de função
) 	| fim de argumentos de função
" 	| inicio e fim de constantes do tipo vetor de caracteres (strings)
= 	| atribuição 
. 	| ponto flutuante
, 	| separador de argumentos
; 	| fim de instrução
\ 	| comentários

# ENBF
**Token**  | **Derivação**
:------|:----------
\<program\> | {\<beforemain\>} \<mainfunction\>
\<beforemain\> | \<var_declaration\> \| \<function_definition\>
\<mainfunction\> | \<main_id\> \<arguments\> \<code_block\>
\<arguments\> | \<begin_arg\> [\<arg_list\>] \<end_arg\>
\<arg_list\> | \<var_type\> \<identifier\> {\<more_arguments\>}
\<more_arguments\> | \<separator\> \<arg_list\>
\<code_block\> | \<begin_code\> [\<code\>] \<end_code\>
\<code_block_return\> | \<begin_code\> [\<code\>] \<return_statement\> \<end_code\>
\<code\> | {\<var_declaration\> \| \<loop_block\> \| \<ifelse_statement\> \| \<attribution\> \| \<function_call\>}
\<return_statement\> | \<return\> \<value\> \<eol\>
\<var_declaration\> | \<var_type\> \<identifier\> [\<more_declaration\>] \<eol\>
\<more_declaration\> | \<separator\> \<identifier\> {\<more_declaration\>}
\<loop_block\> | \<for\> \<begin_arg\> \<value\> \<end_arg\> \<code_block\>
\<ifelse_statement\> | \<if\> \<begin_arg\> \<value\> \<end_arg\> \<code_block\> [\<else_statement\>]
\<else_statement\> | \<else\> \<more_else\>
\<more_else\> | (\<ifelse_statement\> \| \<code_block\>)
\<attribution\> | \<identifier\> \<equal\> \<value\> \<eol\>
\<value\> | (\<identifier\> \| \<number\> \| \<logical\> \| \<string\> \| \<function_call\> \| (\<not\> \<value\>))  \<operation\>
\<operation\> | {\<operator\> \<value\>}
\<number\> | \<float\> \| \<integer\>
\<float\> | \<integer\> \<float_separator\> \<integer\>
\<integer\> | \<digit\> \| (\<digit_nonzero\> {\<digit\>})
\<function_call\> | \<call\> \<identifier\> \<arguments\> \<eol\>
\<function_definition\> | \<function_return\> \| \<function_void\>
\<function_return\> | \<newfunction\> \<return_type\> \<identifier\> \<arguments\> \<code_block_return\>
\<return_type\> | \<var_type\>
\<function_void\> | \<void\> \<identifier\> \<arguments\> \<code_block\>
\<identifier\> | \<letter\> {\<character\>}
\<character\> | \<letter\> \| \<digit\> \| \<underline\>
\<string\> | \<begin_str\> {(* any unicode char *)} \<end_str\>
\<newfunction\> | "moscow"
\<main_id\> | "motherland"
\<call\> | "tovarish"
\<for\> | "forevisky"
\<if\> | "ikov"
\<else\> | "kalashn"
\<logical\> | "strongon" \| "strongonoff"
\<return\> | "yebat"
\<not\> | "niet"
\<begin_code\> | "{"
\<end_code\> | "}"
\<begin_arg\> | "("
\<end_arg\> | ")"
\<begin_str\> | """
\<end_str\> | """
\<separator\> | ","
\<eol\> | ";"
\<equal\> | "="
\<underline\> | "_"
\<float_separator\> | "."
\<operator\> | "+" \| "-" \| "*" \| "/" \| "&&" \| "\|\|" \| "==" \| "!=" \| "\>=" \| "\<=" \| "\<" \| "\>" \| "pow"
\<var_type\> | "intsky" \| "charovsky" \| "floatsky" \| "bolichisky" \| "palavrovka"
\<void\> | "chernobyl"
\<digit\> | 	"0" \| \<digit_nonzero\>
\<digit_nonzero\> | "1" \| "2" \| "3" \| "4" \| "5" \| "6" \| "7" \| "8" \| "9"
\<letter\> | "a" \| "b" \| "c" \| "d" \| "e" \| "f" \| "g" \| "h" \| "i" \| "j" \| "k" \| "l" \| "m" \| "n" \| "o" \| "p" \| "q" \| "r" \| "s" \| "t" \| "u" \| "v" \| "w" \| "x" \| "y" \| "z" \| "A" \| "B" \| "C" \| "D" \| "E" \| "F" \| "G" \| "H" \| "I" \| "J" \| "K" \| "L" \| "M" \| "N" \| "O" \| "P" \| "Q" \| "R" \| "S" \| "T" \| "U" \| "V" \| "W" \| "X" \| "Y" \| "Z"

# Exemplos

## Exemplo 1

```
intsky copovisky;

chernobyl enchecopovisky(){
    ikov(copovisky < 100){
        copovisky = 100;
    }
}

moscow intsky beber(){
    intsky outrocopo;
    
    ikov(copovisky > 0){
        outrocopo = copovisky - 1;
    }kalashn ikov(copovisky == 0){
        outrocopo = 0;
    }
    
    yebat outrocopo;
}

motherland(){
    copovisky = 0;

    tovarish enchecopovisky();

    forevisky(copovisky > 0){
        tovarish beber();
    }
}
```

## Exemplo 2
```
motherland(){
    intsky a;
    a = 3;
}
```

```
<program>
    └<mainfunction>
        └<main_id>
        |   └"motherland"
        |
        └<arguments>
        |   └<begin_arg>
        |   |   └"("
        |   |
        |   └<arg_list>
        |   |   └"vazio"
        |   |
        |   └<end_arg>
        |       └")"
        |
        └<code_block>
            └<begin_code>
            |   └"{"
            |
            └<code>
            |   └<var_declaration>
            |   |   └<var_type>
            |   |   |   └"intsky"
            |   |   |
            |   |   └<identifier>
            |   |   |   └<letter>
            |   |   |       └"a"
            |   |   |
            |   |   └<eol>
            |   |       └";"
            |   |
            |   └<attribution>
            |       └<identifier>
            |       |   └<letter>
            |       |       └"a"
            |       |
            |       └<equal>
            |       |   └"="
            |       |
            |       └<value>
            |       |   └<number>
            |       |       └<integer>
            |       |           └<digit>
            |       |               └"3"
            |       |
            |       └<eol>
            |           └";"
            |
            └<end_code>
                └"}"
```
