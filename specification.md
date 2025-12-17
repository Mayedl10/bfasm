# Instruction Specifications

## Preface

`var` refers to any byte or index pointer    
`const` refers to a constant at compile time (can only be a number outside of `:text` section)    
`str` refers to a constant string defined in `:text`    
`stat` refers to a static array    
`dyn` refers to a dynamic array    
`sub` refers to a subroutine name    
`args` refers to one or more argument provided to a subroutine

## Math and Logic
- `++` `var` - increment
- `--` `var` - decrement
- `+` `var` `var/const` `var/const` - add
- `-` `var` `var/const` `var/const` - subtract
- `*` `var` `var/const` `var/const` - multiply
- `/` `var` `var/const` `var/const` - divide (integer division)
- `%` `var` `var/const` `var/const` - modulo
- `>` `var` `var/const` `var/const` - greater than
- `>=` `var` `var/const` `var/const` - greater than or equal to
- `<` `var` `var/const` `var/const` - less than
- `<=` `var` `var/const` `var/const` - less than or equal to
- `==` `var` `var/const` `var/const` - is equal to
- `!=` `var` `var/const` `var/const` - is not equal to
- `&` `var` `var/const` `var/const` - boolean AND
- `|` `var` `var/const` `var/const` - boolean OR
- `!` `var` `var/const` - boolean NOT
- `^` `var` `var/const` `var/const` - boolean XOR

## IO
- `printV_c` `var/const` - prints a character from a variable
- `printV_n` `var/const` - prints a number from a variable
- `printS` `str` - prints a string (:text)
- `readV_c` `var`- read a single character
- `readV_n` `var` - read a single DECIMAL DIGIT
- `readSA_c` `stat` `const` - reads a constant number of characters into a static array  (does not overwrite past the nth element)
- `readSA_n` `stat` `const` - reads a constant number of DECIMAL DIGITS into a static array (does not overwrite past the nth element)
- `readDA_c` `dyn` `const` - reads a constant number of characters into a dynamic array  (does not overwrite past the nth element) (VERY EXPENSIVE!)
- `readDA_n` `dyn` `const` - reads a constant number of DECIMAL DIGITS into a dynamic array (does not overwrite past the nth element) (VERY EXPENSIVE!)

## Flow Control
- `if` `var` `..code..` `endIf` - if var != 0, execute code
- `if` `var` `..code..` `else` `..code..` `endIf` - if var != 0, execute if-code, otherwise execute else-code
- `while` `var` `..code..` `endWhile` -  Brainfuck's `[]`, while var != 0, repeat code
- `call` `sub` `args` - calls a subroutine
- `call` `sub` - calls a subroutine with all arguments defaulting to 0

## Memory
- `clear` `var/dyn/stat` - sets (all values of) the passed argument to zero
- `set` `var/dyn/stat` `var/const` - sets (all values of) the passed argument to a specific value
- `collapse` `var` - `var = (var > 0) ? 1 : 0` 

## Other
- `include` `filename` - tells the compiler to look for a certain file in the include-directories. if found, insert file contents.