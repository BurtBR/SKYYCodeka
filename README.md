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
while   | mickwhail
for     | forevisky
if      | ikov
else    | kalashn
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
*>* | *>*
*<* | *<*
*>=* | *>=*
*<=* | *<=*
!(not) | niet
&& | &&
\|\| | \|\|

# OUTROS
**em C**  | **SKYY**
:------|:----------
; (EOL) | ;

# NÃO NECESSÁRIOS
**em C** | **SKYY**
:------|:----------
\#define  | 
true      | strongon
false     | strongonoff 

# PALAVRAS
**Palavra**  | **Significado**
:------|:----------
tchekutchka   |
pollitra      |
stolichnaya   | Marca de vodka
za zdorôvie!  | brinde(bebida)
sergay        |
primakov      |
truotsky      |

# ENBF
**Símbolo**  | **Digivolve para**
:------|:----------
<program> | {<beforemain>} <mainfunction> {<aftermain>}
<beforemain> | {<var_declaration> \| <function_definition>}
<aftermain> | {<var_declaration> \| <function_definition>}
<mainfunction> | <main_id> <arguments> <code_block>
<arguments> | <begin_arg> <arg_list> <end_arg>
<arg_list> | <var_type> <identifier> {<more_arguments>}
<more_arguments> | <separator> <arg_list>
<code_block> | <begin_code> <code> <end_code>
<code> | {<var_declaration> \| <loop_block> \| <ifelse_statement> \| <attribution> \| <function_call>}
<var_declaration> | <var_type> <identifier> {<more_declaration>} <eol>
<more_declaration> | <separator> <var_declaration>
<loop_block> | <for> <begin_arg> <value> <end_arg> <code_block>
<ifelse_statement> | <if> <begin_arg> <value> <end_arg> <code_block> {<else_statement>}
<else_statement> | <else> (<ifelse_statement> \| <code_block>)
<attribution> | <identifier> <equal> <value> <eol>
<value> | <identifier> \| <number> \| <operation> \| <logical> \| <string> \| <function_call> \| (<not> <value>)
<operation> | <value> <operator> <value>
<number> | <float> \| <integer>
<float> | <integer> <float_separator> <integer>
<integer> | <digit> \| (<digit_nonzero> {<digit>})
<function_call> | <call> <identifier> <arguments> <eol>
<function_definition> | <newfunction> <identifier> <arguments> <code_block>
<identifier> | <letter> {<character>}
<character> | <letter> \| <digit> \| <underline>
<string> | <begin_str> {(* any unicode char *)} <end_str>
<newfunction> | "moscow"
<main_id> | "motherland"
<call> | "tovarish"
<for> | "forevisky"
<if> | "ikov"
<else> | "kalashn"
<logical> | "strongon" \| "strongonoff"
<not> | "niet"
<begin_code> | "{"
<end_code> | "}"
<begin_arg> | "("
<end_arg> | ")"
<begin_str> | """
<end_str>  """
<separator> | ","
<eol> | ";"
<equal> | "="
<underline> | "_"
<float_separator> | "."
<operator> | "+" \| "-" \| "*" \| "/" \| "&&" \| "\|\|" \| "==" \| "!=" \| ">=" \| "<=" \| "<" \| ">" \| "pow"
<var_type> | "intsky" \| "charovsky" \| "floatsky" \| "bolichisky" \| "palavrovka"
<digit> | 	"0" \| <digit_nonzero>
<digit_nonzero> | "1" \| "2" \| "3" \| "4" \| "5" \| "6" \| "7" \| "8" \| "9"
<letter> | "a" \| "b" \| "c" \| "d" \| "e" \| "f" \| "g" \| "h" \| "i" \| "j" \| "k" \| "l" \| "m" \| "n" \| "o" \| "p" \| "q" \| "r" \| "s" \| "t" \| "u" \| "v" \| "w" \| "x" \| "y" \| "z" \| "A" \| "B" \| "C" \| "D" \| "E" \| "F" \| "G" \| "H" \| "I" \| "J" \| "K" \| "L" \| "M" \| "N" \| "O" \| "P" \| "Q" \| "R" \| "S" \| "T" \| "U" \| "V" \| "W" \| "X" \| "Y" \| "Z"

# Exemplos

## Exemplo 1

```
intsky motherland(){
  
  charovisky c = 69;
  intsky i;
  
  forevisky(i=0; i<10 ;i++){
    c = c + 1;
  }

  yebat 0;
}
```
```
<program>
│
└─<main>
  │
  └─<var_type>
  | |
  | └─ intsky
  |
  └─<main_id>
  | |
  | └─ motherland
  |
  └─<arguments>
  | |
  | └─<begin_arg>
  | | |
  | | └─ (
  | |
  | └─<arg_list>
  | | |
  | | └─ {}
  | |
  | └─<end_arg>
  |   |
  |   └─ )
  |
  └─<begin_code>
  | |
  | └─ {
  |
  └─<code>
  | |
  | └─<var_declaration>
  | | |
  | | └─<var_type>
  | | | |
  | | | └─ charovsky
  | | |
  | | └─<var_list>
  | | | |
  | | | └─<attribution>
  | | |   |
  | | |   └─<identifier>
  | | |   | |
  | | |   | └─<letter>
  | | |   |   |
  | | |   |   └─ c
  | | |   |
  | | |   └─<equal>
  | | |   | |
  | | |   | └─ =
  | | |   |
  | | |   └─<value>
  | | |     |
  | | |     └─<number>
  | | |       |
  | | |       └─<digit_nonzero>
  | | |       | |
  | | |       | └─ 6
  | | |       |
  | | |       └─<digit>
  | | |         |
  | | |         └─ 9
  | | |
  | | └─<eol>
  | |   |
  | |   └─ ;
  | |
  | └─<var_declaration>
  | | |
  | | └─<var_type>
  | | | |
  | | | └─ intsky
  | | |
  | | └─<var_list>
  | | | |
  | | | └─<identifier>
  | | |   |
  | | |   └─<letter>
  | | |     |
  | | |     └─ i
  | | |
  | | └─<eol>
  | |   |
  | |   └─ ;
  | |
  | └─<loop_block>
  |   |
  |   └─<for_statement>
  |     |
  |     └─<for>
  |     | |
  |     | └─ forevisky
  |     |
  |     └─<begin_arg>
  |     | |
  |     | └─ (
  |     |
  |     └─<attribution>
  |     | |
  |     | └─<identifier>
  |     | | |
  |     | | └─<letter>
  |     | |   |
  |     | |   └─ i
  |     | |
  |     | └─<equal>
  |     | | |
  |     | | └─ =
  |     | |
  |     | └─<value>
  |     |   |
  |     |   └─<number>
  |     |     |
  |     |     └─<digit>
  |     |       |
  |     |       └─ 0
  |     |
  |     └─<eol>
  |     | |
  |     | └─ ;
  |     |
  |     └─<value>
  |     | |
  |     | └─<operation>
  |     |   |
  |     |   └─<value>
  |     |   | |
  |     |   | └─<identifier>
  |     |   |   |
  |     |   |   └─<letter>
  |     |   |     |
  |     |   |     └─ i
  |     |   |
  |     |   └─<operator>
  |     |   | |
  |     |   | └─ <
  |     |   |
  |     |   └─<value>
  |     |     |
  |     |     └─<numbber>
  |     |       |
  |     |       └─<digit_nonzero>
  |     |       | |
  |     |       | └─ 1
  |     |       |
  |     |       └─<digit>
  |     |         |
  |     |         └─ 0
  |     |
  |     └─<eol>
  |     | |
  |     | └─ ;
  |     |
  |     └─<attribution>
  |     | |
  |     | └─<increment>
  |     |   |
  |     |   └─<postincrement>
  |     |     |
  |     |     └─<identifier>
  |     |     | |
  |     |     | └─<letter>
  |     |     |   |
  |     |     |   └─i
  |     |     |
  |     |     └─<plusplus>
  |     |       |
  |     |       └─ ++
  |     |
  |     └─<end_arg>
  |     | |
  |     | └─ )
  |     |
  |     └─<block>
  |       |
  |       └─<begin_code>
  |       | |
  |       | └─ {
  |       |
  |       └─<code>
  |       | |
  |       | └─<attribution>
  |       | | |
  |       | | └─<identifier>
  |       | | | |
  |       | | | └─<letter>
  |       | | |   |
  |       | | |   └─ c
  |       | | |
  |       | | └─<equal>
  |       | | | |
  |       | | | └─ =
  |       | | |
  |       | | └─<value>
  |       | |   |
  |       | |   └─<operation>
  |       | |     |
  |       | |     └─<value>
  |       | |     | |
  |       | |     | └─<identifier>
  |       | |     |   |
  |       | |     |   └─<letter>
  |       | |     |     |
  |       | |     |     └─ c
  |       | |     |
  |       | |     └─<operator>
  |       | |     | |
  |       | |     | └─ +
  |       | |     |
  |       | |     └─<value>
  |       | |       |
  |       | |       └─<number>
  |       | |         |
  |       | |         └─<digit>
  |       | |           |
  |       | |           └─ 1
  |       | |
  |       | └─<eol>
  |       |   |
  |       |   └─ ;
  |       |
  |       └─<end_code>
  |         |
  |         └─ }
  |
  └─<return_statement>
  | |
  | └─<return>
  | | |
  | | └─ yebat
  | |
  | └─<value>
  | | |
  | | └─<number>
  | |   |
  | |   └─<digit>
  | |     |
  | |     └─ 0
  | |
  | └─<eol>
  |   |
  |   └─ ;
  |
  └─<end_code>
    |
    └─ }
```

## Exemplo 2

```
palavrovka camarada;

bolichisky verifica(){
  
  ikov(camarada == "Boris"){
    yebat strongon;
  }kalashn ikov(camarada == "Kalashnikov"){
    yebat strongon;
  }
  
  yebat strongonoff;
}

intsky motherland{

  camarada = "Boris";
  
  verifica();

  yebat 0;
}
```

```
<program>
|
└─<var_declaration>
| |
| └─<var_type>
| | |
| | └─ palavrovka
| |
| └─<var_list>
| | |
| | └─<identifier>
| |   |
| |   └─<letter>
| |   | |
| |   | └─ c
| |   |
| |   └─<character>
| |   | |
| |   | └─<letter>
| |   |   |
| |   |   └─ a
| |   |
| |   └─<character>
| |   | |
| |   | └─<letter>
| |   |   |
| |   |   └─ m
| |   |
| |   └─<character>
| |   | |
| |   | └─<letter>
| |   |   |
| |   |   └─ a
| |   |
| |   └─<character>
| |   | |
| |   | └─<letter>
| |   |   |
| |   |   └─ r
| |   |
| |   └─<character>
| |   | |
| |   | └─<letter>
| |   |   |
| |   |   └─ a
| |   |
| |   └─<character>
| |   | |
| |   | └─<letter>
| |   |   |
| |   |   └─ d
| |   |
| |   └─<character>
| |     |
| |     └─<letter>
| |       |
| |       └─a
| |
| └─<eol>
|   |
|   └─ ;
|
└─<function>
| |
| └─<return_function>
|   |
|   └─<var_type>
|   | |
|   | └─ bolichisky
|   |
|   └─<identifier>
|   | |
|   | └─<letter>
|   | | |
|   | | └─ v
|   | |
|   | └─<character>
|   | | |
|   | | └─<letter>
|   | |   |
|   | |   └─ e
|   | |
|   | └─<character>
|   | | |
|   | | └─<letter>
|   | |   |
|   | |   └─ r
|   | |
|   | └─<character>
|   | | |
|   | | └─<letter>
|   | |   |
|   | |   └─ i
|   | |
|   | └─<character>
|   | | |
|   | | └─<letter>
|   | |   |
|   | |   └─ f
|   | |
|   | └─<character>
|   | | |
|   | | └─<letter>
|   | |   |
|   | |   └─ i
|   | |
|   | └─<character>
|   | | |
|   | | └─<letter>
|   | |   |
|   | |   └─ c
|   | |
|   | └─<character>
|   |   |
|   |   └─<letter>
|   |     |
|   |     └─ a
|   |
|   └─<arguments>
|   | |
|   | └─<begin_arg>
|   | | |
|   | | └─ (
|   | |
|   | └─<end_arg>
|   |   |
|   |   └─ )
|   |
|   └─<begin_code>
|   | |
|   | └─ {
|   |
|   └─<code>
|   | |
|   | └─<ifelse_statement>
|   |   |
|   |   └─<if>
|   |   | |
|   |   | └─ ikov
|   |   |
|   |   └─<begin_arg>
|   |   | |
|   |   | └─ (
|   |   |
|   |   └─<operation>
|   |   | |
|   |   | └─<value>
|   |   | | |
|   |   | | └─<identifier>
|   |   | |   |
|   |   | |   └─<letter>
|   |   | |   | |
|   |   | |   | └─ c
|   |   | |   |
|   |   | |   └─<character>
|   |   | |   | |
|   |   | |   | └─<letter>
|   |   | |   |   |
|   |   | |   |   └─ a
|   |   | |   |
|   |   | |   └─<character>
|   |   | |   | |
|   |   | |   | └─<letter>
|   |   | |   |   |
|   |   | |   |   └─ m
|   |   | |   |
|   |   | |   └─<character>
|   |   | |   | |
|   |   | |   | └─<letter>
|   |   | |   |   |
|   |   | |   |   └─ a
|   |   | |   |
|   |   | |   └─<character>
|   |   | |   | |
|   |   | |   | └─<letter>
|   |   | |   |   |
|   |   | |   |   └─ r
|   |   | |   |
|   |   | |   └─<character>
|   |   | |   | |
|   |   | |   | └─<letter>
|   |   | |   |   |
|   |   | |   |   └─ a
|   |   | |   |
|   |   | |   └─<character>
|   |   | |   | |
|   |   | |   | └─<letter>
|   |   | |   |   |
|   |   | |   |   └─ d
|   |   | |   |
|   |   | |   └─<character>
|   |   | |     |
|   |   | |     └─<letter>
|   |   | |       |
|   |   | |       └─ a
|   |   | |
|   |   | └─<operator>
|   |   | | |
|   |   | | └─ ==
|   |   | |
|   |   | └─<value>
|   |   |   |
|   |   |   └─<string>
|   |   |     |
|   |   |     └─<begin_str>
|   |   |     | |
|   |   |     | └─ "
|   |   |     |
|   |   |     └─<character>
|   |   |     | |
|   |   |     | └─<letter>
|   |   |     |   |
|   |   |     |   └─ B
|   |   |     |
|   |   |     └─<character>
|   |   |     | |
|   |   |     | └─<letter>
|   |   |     |   |
|   |   |     |   └─ o
|   |   |     |
|   |   |     └─<character>
|   |   |     | |
|   |   |     | └─<letter>
|   |   |     |   |
|   |   |     |   └─ r
|   |   |     | 
|   |   |     └─<character>
|   |   |     | |
|   |   |     | └─<letter>
|   |   |     |   |
|   |   |     |   └─ i
|   |   |     |
|   |   |     └─<character>
|   |   |     | |
|   |   |     | └─<letter>
|   |   |     |   |
|   |   |     |   └─ s
|   |   |     |
|   |   |     └─<end_str>
|   |   |       |
|   |   |       └─ "
|   |   |
|   |   └─<end_arg>
|   |   | |
|   |   | └─ )
|   |   |
|   |   └─<block>
|   |   | |
|   |   | └─<begin_code>
|   |   | | |
|   |   | | └─ {
|   |   | |
|   |   | └─<code>
|   |   | | |
|   |   | | └─<return_statement>
|   |   | |   |
|   |   | |   └─<return>
|   |   | |   | |
|   |   | |   | └─ yebat
|   |   | |   |
|   |   | |   └─<value>
|   |   | |   | |
|   |   | |   | └─<logical>
|   |   | |   |   |
|   |   | |   |   └─ strongon
|   |   | |   |
|   |   | |   └─<eol>
|   |   | |     |
|   |   | |     └─ ;
|   |   | |
|   |   | └─<end_code>
|   |   |   |
|   |   |   └─ }
|   |   |
|   |   └─<else_statement>
|   |     |
|   |     └─<else>
|   |     | |
|   |     | └─ kalashn
|   |     |
|   |     └─<ifelse_statement>
|   |       |
|   |       └─<if>
|   |       | |
|   |       | └─ ikov
|   |       |
|   |       └─<begin_arg>
|   |       | |
|   |       | └─ (
|   |       |
|   |       └─<operation>
|   |       | |
|   |       | └─<value>
|   |       | | |
|   |       | | └─<identifier>
|   |       | |   |
|   |       | |   └─<letter>
|   |       | |   | |
|   |       | |   | └─ c
|   |       | |   |
|   |       | |   └─<character>
|   |       | |   | |
|   |       | |   | └─<letter>
|   |       | |   |   |
|   |       | |   |   └─ a
|   |       | |   └─<character>
|   |       | |   | |
|   |       | |   | └─<letter>
|   |       | |   |   |
|   |       | |   |   └─ m
|   |       | |   └─<character>
|   |       | |   | |
|   |       | |   | └─<letter>
|   |       | |   |   |
|   |       | |   |   └─ a
|   |       | |   └─<character>
|   |       | |   | |
|   |       | |   | └─<letter>
|   |       | |   |   |
|   |       | |   |   └─ r
|   |       | |   └─<character>
|   |       | |   | |
|   |       | |   | └─<letter>
|   |       | |   |   |
|   |       | |   |   └─ a
|   |       | |   └─<character>
|   |       | |   | |
|   |       | |   | └─<letter>
|   |       | |   |   |
|   |       | |   |   └─ d
|   |       | |   └─<character>
|   |       | |     |
|   |       | |     └─<letter>
|   |       | |       |
|   |       | |       └─ a
|   |       | |
|   |       | └─<operator>
|   |       | | |
|   |       | | └─ ==
|   |       | |
|   |       | └─<value>
|   |       |   |
|   |       |   └─<string>
|   |       |     |
|   |       |     └─<begin_str>
|   |       |     | |
|   |       |     | └─ "
|   |       |     |
|   |       |     └─<character>
|   |       |     | |
|   |       |     | └─<letter>
|   |       |     |   |
|   |       |     |   └─ K
|   |       |     └─<character>
|   |       |     | |
|   |       |     | └─<letter>
|   |       |     |   |
|   |       |     |   └─ a
|   |       |     └─<character>
|   |       |     | |
|   |       |     | └─<letter>
|   |       |     |   |
|   |       |     |   └─ l
|   |       |     └─<character>
|   |       |     | |
|   |       |     | └─<letter>
|   |       |     |   |
|   |       |     |   └─ a
|   |       |     └─<character>
|   |       |     | |
|   |       |     | └─<letter>
|   |       |     |   |
|   |       |     |   └─ s
|   |       |     └─<character>
|   |       |     | |
|   |       |     | └─<letter>
|   |       |     |   |
|   |       |     |   └─ h
|   |       |     └─<character>
|   |       |     | |
|   |       |     | └─<letter>
|   |       |     |   |
|   |       |     |   └─ n
|   |       |     └─<character>
|   |       |     | |
|   |       |     | └─<letter>
|   |       |     |   |
|   |       |     |   └─ i
|   |       |     └─<character>
|   |       |     | |
|   |       |     | └─<letter>
|   |       |     |   |
|   |       |     |   └─ k
|   |       |     └─<character>
|   |       |     | |
|   |       |     | └─<letter>
|   |       |     |   |
|   |       |     |   └─ o
|   |       |     └─<character>
|   |       |     | |
|   |       |     | └─<letter>
|   |       |     |   |
|   |       |     |   └─ v
|   |       |     |
|   |       |     └─<end_str>
|   |       |       |
|   |       |       └─ "
|   |       |
|   |       └─<end_arg>
|   |       | |
|   |       | └─ )
|   |       |
|   |       └─<block>
|   |         |
|   |         └─<begin_code>
|   |         | |
|   |         | └─ {
|   |         |
|   |         └─<code>
|   |         | |
|   |         | └─<return_statement>
|   |         |   |
|   |         |   └─<return>
|   |         |   | |
|   |         |   | └─ yebat
|   |         |   |
|   |         |   └─<value>
|   |         |   | |
|   |         |   | └─<logical>
|   |         |   |   |
|   |         |   |   └─<strongon>
|   |         |   |
|   |         |   └─<eol>
|   |         |     |
|   |         |     └─ ;
|   |         |
|   |         └─<end_code>
|   |           |
|   |           └─ }
|   |
|   └─<return_statement>
|   | |
|   | └─<return>
|   | | |
|   | | └─ yebat
|   | |
|   | └─<value>
|   | | |
|   | | └─<logical>
|   | |   |
|   | |   └─ strongonoff
|   | |
|   | └─<eol>
|   |   |
|   |   └─ ;
|   |
|   └─<end_code>
|     |
|     └─ }
|
└─<main>
  |
  └─<var_type>
  | |
  | └─ intsky
  |
  └─<main_id>
  | |
  | └─ motherland
  |
  └─<arguments>
  | |
  | └─<begin_arg>
  | | |
  | | └─ (
  | |
  | └─<end_arg>
  |   |
  |   └─ )
  |
  └─<begin_code>
  | |
  | └─ {
  |
  └─<code>
  | |
  | └─<attribution>
  | | |
  | | └─<identifier>
  | | | |
  | | | └─<letter>
  | | | | |
  | | | | └─ c
  | | | |
  | | | └─<character>
  | | | | |
  | | | | └─<letter>
  | | | |   |
  | | | |   └─ a
  | | | └─<character>
  | | | | |
  | | | | └─<letter>
  | | | |   |
  | | | |   └─ m
  | | | └─<character>
  | | | | |
  | | | | └─<letter>
  | | | |   |
  | | | |   └─ a
  | | | └─<character>
  | | | | |
  | | | | └─<letter>
  | | | |   |
  | | | |   └─ r
  | | | └─<character>
  | | | | |
  | | | | └─<letter>
  | | | |   |
  | | | |   └─ a
  | | | └─<character>
  | | | | |
  | | | | └─<letter>
  | | | |   |
  | | | |   └─ d
  | | | └─<character>
  | | |   |
  | | |   └─<letter>
  | | |     |
  | | |     └─ a
  | | |
  | | └─<equal>
  | | | |
  | | | └─ =
  | | |
  | | └─<value>
  | |   |
  | |   └─<string>
  | |     |
  | |     └─<begin_str>
  | |     | |
  | |     | └─ "
  | |     |
  | |     └─<character>
  | |     | |
  | |     | └─<letter>
  | |     |   |
  | |     |   └─ B
  | |     └─<character>
  | |     | |
  | |     | └─<letter>
  | |     |   |
  | |     |   └─ o
  | |     └─<character>
  | |     | |
  | |     | └─<letter>
  | |     |   |
  | |     |   └─ r
  | |     └─<character>
  | |     | |
  | |     | └─<letter>
  | |     |   |
  | |     |   └─ i
  | |     └─<character>
  | |     | |
  | |     | └─<letter>
  | |     |   |
  | |     |   └─ s
  | |     |
  | |     └─<end_str>
  | |       |
  | |       └─ "
  | |
  | └─<eol>
  | | |
  | | └─ ;
  | |
  | └─<function_call>
  | | |
  | | └─<identifier>
  | | | |
  | | | └─<letter>
  | | | | |
  | | | | └─ v
  | | | |
  | | | └─<character>
  | | | | |
  | | | | └─<letter>
  | | | |   |
  | | | |   └─ e
  | | | └─<character>
  | | | | |
  | | | | └─<letter>
  | | | |   |
  | | | |   └─ r
  | | | └─<character>
  | | | | |
  | | | | └─<letter>
  | | | |   |
  | | | |   └─ i
  | | | └─<character>
  | | | | |
  | | | | └─<letter>
  | | | |   |
  | | | |   └─ f
  | | | └─<character>
  | | | | |
  | | | | └─<letter>
  | | | |   |
  | | | |   └─ i
  | | | └─<character>
  | | | | |
  | | | | └─<letter>
  | | | |   |
  | | | |   └─ c
  | | | └─<character>
  | | |   |
  | | |   └─<letter>
  | | |     |
  | | |     └─ a
  | | |
  | | └─<arguments>
  | |   |
  | |   └─<begin_arg>
  | |   | |
  | |   | └─ (
  | |   |
  | |   └─<end_arg>
  | |     |
  | |     └─ )
  | |
  | └─<eol>
  |   |
  |   └─ ;
  |
  └─<return_statement>
  | |
  | └─<return>
  | | |
  | | └─ yebat
  | |
  | └─<value>
  | | |
  | | └─<number>
  | |   |
  | |   └─<digit>
  | |     |
  | |     └─ 0
  | |
  | └─<eol>
  |   |
  |   └─ ;
  |
  └─<end_code>
    |
    └─ }
```
