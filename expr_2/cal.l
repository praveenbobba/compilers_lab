%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "y.tab.h"
%}

alpha [a-z]+

%%

{alpha} {yylval = yytext;return SYMBOL;}
	
[-|+|/|*|(|)|\n|^] {return *yytext;}

%%

yywrap()
{
	return 1;
}

