%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "y.tab.h"
%}

number [0-9]+

%%

{number} {yylval = atoi(yytext);return DIGIT;}
	
[-|+|/|*|(|)|\n|^] {return *yytext;}

%%

yywrap()
{
	return 1;
}

