" Vim syntax file
" Language: Poryscript
" Maintainer: cornixsenex
" Latest Revision: 4/21/22


if exists("b:current_syntax")
	finish
endif


"syn region poryString oneline start='"' end='"' contained

"syn keyword poryTopWords script text movement mapscripts raw const

syn keyword poryScript script
syn keyword poryText text
syn keyword poryMovement movement
syn keyword poryMapscripts mapscripts
syn keyword poryRaw raw
syn keyword poryConst const

"syn keyword poryConditional if elif else switch while
"syn keyword poryFlagVars flag var defeated


syn match poryComment "//.*$"


let b:current_syntax = "poryscript"


"Comment = Blue
"Statement, Label, Repeat, Conditional = orange
"number, Constant = red
"Special, Macro = pink
"Error = red highlight
"Structure, Type = green
"Function = cyan

hi def link poryComment    Comment
hi def link poryScript     Statement
hi def link poryText       Function
hi def link poryMovement   Structure
hi def link poryMapscripts Statement
hi def link poryRaw        Constant
hi def link poryConst      Statement
"hi def link poryConditional Conditional
"hi def link poryFlagVars    number
"hi def link poryString      String

