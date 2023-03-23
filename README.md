# TIPOS DE DADOS
**em C**  | **SKYY**
:------|:----------
int     | intsky
char    | charovsky
float   | floatsky
bool    | bolichisky
void    | chernobyl
string  | palavrovka

# BLOCOS DE CÓDIGO
**em C**  | **SKYY**
:------|:----------
main    | motherland
while   | 
for     | forevisky
if      |
else    |
return  | yebat

# OPERAÇÕES
**em C**  | **SKYY**
:------|:----------
$+$ | $+$
$-$ | $-$
$*$ | $*$
*/* | */*
*=* | *=*
*==* | *==*
!*=* | !*=*
*>=* | *>=*
*<=* | *<=*
!(not) | niet
&& | &&
\|\| | \|\|

# OUTROS
**em C**  | **SKYY**
:------|:----------
EOL | ;

# NÃO NECESSÁRIOS
**em C** | **SKYY**
:------|:----------
\#define  | 
true      | ivandrago \| nosso
false     | rocky \| meu

# PALAVRAS
**Palavra**  | **Significado**
:------|:----------
tchekutchka   |
pollitra      |
stolichnaya   | Marca de vodka
za zdorôvie!  | brinde(bebida)

# ENBF
**Símbolo**  | **Digivolve para**
:------|:----------
\<program\> | {\<var_declaration\> \| \<function\>} \<main\> {\<var_declaration\> \| \<function\>}
\<main\> | \<var_type\> \<main_id\> \<arguments\> \<begin_code\> [\<code\>] \<return_statement\> \<end_code\>
\<return_statement\> | \<return\> \<value\> \<eol\>
\<function\> | \<return_function\> | \<void_function\>
\<return_function\> | \<var_type\> \<identifier\> \<arguments\> \<begin_code\> [\<code\>] \<return_statement\> \<end_code\>
\<void_function\> | \<void\> \<identifier\> \<arguments\> \<block\>
\<arguments\> | \<begin_arg\> [\<arg_list\>] \<end_arg\>
\<block\> | \<begin_code\> [\<code\>] \<end_code\>
\<code\> | {\<var_declaration\> \| \<loop_block\> | \<ifelse_statement\> \| \<attribution\>}
\<ifelse_statement\> | \<if\> \<begin_arg\> \<operation\> \<end_arg\> \<block\> [\<else_statement\>]
\<else_statement\> | \<else\> (\<ifelse_statement\> \| \<block\> [\<else_statement\>])
\<loop_block\> | \<for_statement\> \| \<while_statement\>
\<for_statement\> | \<for\> \<begin_arg\> [\<var_declaration\> {\<separator\> \<var_declaration\>}] \<eol\> \<operation\> \<eol\> \<attribution\> \<end_arg\> \<block\>
\<while_statement\> | \<while\> \<begin_arg\> \<operation\> \<end_arg\> \<block\>
\<value\> | \<identifier\> \| \<number\> \| \<operation\>
\<identifier\> | \<letter\> {\<character\>}
\<var_declaration\> | \<var_type\> \<var_list\> \<eol\>
\<var_list\> | (\<identifier\> \| \<attribution\>) {\<separator\> \<var_list\>}
\<attribution\> | ( \<identifier\> \<equal\> (\<value\> \| \<attribution\>) ) \| ( [\<identifier\> \<equal\>] \<increment\>) \| ([\<identifier\> \<equal\>] \<decrement\>)
\<character\> | \<letter\> \| \<digit\> \| \<underline\>
\<number\> | \<digit_nonzero\> {\<digit\>}
\<operation\> | (\<value\> \<operator\> \<value\>) \| (\<begin_arg\> \<operation\> \<end_arg\>)
\<increment\> | \<preincrement\> \| \<postincrement\>
\<preincrement\> | \<plusplus\> \<identifier\>
\<postincrement\> | \<identifier\> \<plusplus\>
\<decrement\> | \<predecrement\> \| \<postdecrement\>
\<predecrement\> | \<minusminus\> \<identifier\>
\<postdecrement\> | \<identifier\> \<minusminus\>
\<main_id\> | "motherland"
\<if\> | ""
\<else\> | ""
\<for\> | ""
\<while\> | ""
\<var_type\> | "intsky" \| "charovsky" \| "floatsky" \| "bolichisky" \| "palavrovka"
\<void\> | "chernobyl"
\<underline\> | "_"
\<begin_arg\> | "("
\<end_arg\> | ")"
\<begin_code\> | "{"
\<end_code\> | "}"
\<eol\> | ";"
\<separator\> | ","
\<letter\> | "a" \| "b" \| "c" \| "d" \| "e" \| "f" \| "g" \| "h" \| "i" \| "j" \| "k" \| "l" \| "m" \| "n" \| "o" \| "p" \| "q" \| "r" \| "s" \| "t" \| "u" \| "v" \| "w" \| "x" \| "y" \| "z" \| "A" \| "B" \| "C" \| "D" \| "E" \| "F" \| "G" \| "H" \| "I" \| "J" \| "K" \| "L" \| "M" \| "N" \| "O" \| "P" \| "Q" \| "R" \| "S" \| "T" \| "U" \| "V" \| "W" \| "X" \| "Y" \| "Z"
\<digit_nonzero\>  | "1" \| "2" \| "3" \| "4" \| "5" \| "6" \| "7" \| "8" \| "9"
\<digit\> | "0" \| \<digit_nonzero\>
\<operator\> | "+" \| "-" \| "*" \| "/" \| "&&" \| "\|\|" \| "==" \| "!=" \| ">=" \| "<=" \| "<" \| ">"
\<equal\> | "="
\<plusplus\> | "++"
\<minusminus\> | "--"
\<not\> | "niet"
\<return\> | "yebat"
