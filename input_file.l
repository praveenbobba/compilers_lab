%option noyywrap
/*auxialiary declaration */

%{
	#include<stdio.h>
	#include <stdlib.h>
%}

/* regular declaration */
number [0-9]+
op [-|+|*|/|^|=]
alpha [a-z|A-Z]+

/* end of reg. decl. */

/* rules */

%%
{alpha} {printf("its alphabet");}
{number} {if ((atoi(yytext)) %2 == 0) printf("yes");else printf("no"); }
{op} {printf("its operator");}
%%


int main(int argc,char *argv[])
{
	if( argc > 1)
	{
		FILE *fp = fopen (argv[1],"r");
		if(fp)
			yyin = fp ;
	}
	yylex();
	return 0;
}


