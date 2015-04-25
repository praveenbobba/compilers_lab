%{

  #include<stdio.h>
  #include<stdlib.h>
  #include"exptree.h"
  #include"y.tab.h"
  void yyerror(char *);

%}



%%

[0-9]+ {yylval = (node *)malloc(sizeof(node));
	yylval->flag = 0;	
	yylval->val = atoi(yytext);
	yylval->left = NULL;
	yylval->right = NULL ;
	return DIGIT ;
	}

[-|+|/|*] {yylval = (node *)malloc(sizeof(node));
	yylval->flag = 1;	
	yylval->op = *yytext;
	yylval->left = NULL;
	yylval->right = NULL ;
	return *yytext ;
	}

[()] return *yytext;

[\n] return *yytext;

[ \t] ; 

. yyerror("invalid"); 	
	
%%


int yywrap(void)
{
	return 1;

}
