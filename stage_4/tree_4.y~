%{
	
	#include<stdio.h>
	#include<stdlib.h>
	#include "lex.yy.c" 
	//int yylex(void);
	void yyerror(char *);
	int evaltree(node *);
	int array[26];
%}

%token EQU
%token READ
%token WRITE
%token ID
%token DIGIT
%token IF
%token THEN
%token ENDIF
%token WHILE
%token DO
%token ENDWHILE
%nonassoc '<' '>'
%nonassoc EQU
%right '='
%left '+' '-'
%left '*' '/'
%%

Start : Slist '\n'  {evaltree($1);exit(1);}
	;

Slist	:  Slist stmt {$$=(node *)malloc(sizeof(node));
			$$->flag=6;
			$$->left=$1;
			$$->right=$2;}	  	 
					 
	  |stmt		{$$=$1;}
	  ;

stmt	:	ID '='	expr ';'	{ $2->left=$1;$2->right=$3;$$=$2;}

		| READ '(' ID ')' ';'   { $1->left=$3;$1->right=NULL;$$=$1;}

		| WRITE '(' expr ')' ';' {$1->left=$3;$1->right=NULL;$$=$1;}

		| IF '(' expr ')' THEN Slist ENDIF ';'	{$1->left=$3;$1->right=$6;$$=$1;}

		| WHILE '(' expr ')' DO Slist ENDWHILE ';'	{$1->left=$3;$1->right=$6;$$=$1;}

		;

expr	:	DIGIT 		{$$=$1;}

		| '(' expr ')' 		{$$=$2;}

		| expr '+' expr 	{$2->left=$1;
					 $2->right=$3;
					 $$=$2;}
 
		| expr '-' expr 	{$2->left=$1;
					 $2->right=$3;
					 $$=$2;}

		| expr '*' expr 	{$2->left=$1;
					 $2->right=$3;
					 $$=$2;}

		| expr '/' expr 	{$2->left=$1;
					 $2->right=$3;
					 $$=$2;}

		| expr '>' expr 	{$2->left=$1;
					 $2->right=$3;
					 $$=$2;}

		| expr '<' expr		{$2->left=$1;
					 $2->right=$3;
					 $$=$2;} 

		| expr EQU expr 	{$2->left=$1;
					 $2->right=$3;
					 $$=$2;}
		
		| ID			{$$=$1;}
		;

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int evaltree(node *nd){
	if(nd->flag==0){
		return nd->val;
	}
	if(nd->flag==2)
		return array[nd->index];
	if(nd->flag==1){
		if(nd->op=='=')
		   { array[nd->left->index]=evaltree(nd->right);return 1;}		
		if(nd->op=='+')
			return (evaltree(nd->left)+evaltree(nd->right));
		else if(nd->op=='-')
			return (evaltree(nd->left) - evaltree(nd->right));
		else if(nd->op== '*')
			return (evaltree(nd->left) * evaltree(nd->right));
		else if(nd->op=='/')
			return (evaltree(nd->left) / evaltree(nd->right));
	}
	if(nd->flag==3)
	{ int c;
		scanf("%d",&c);
	  array[nd->left->index]=c;
		 return 1;
	}
	if(nd->flag==4)
	{
		printf("%d\n",evaltree(nd->left));
		return 1;
	}
	if(nd->flag==6)
	{ evaltree(nd->left);
	  evaltree(nd->right);
	 return 1;
	}

	if(nd->flag==5){
				
		if(nd->op=='<')
			return (evaltree(nd->left) < evaltree(nd->right));
		else if(nd->op=='>')
			return (evaltree(nd->left) > evaltree(nd->right));
		
	}

	if(nd->flag==7)
	{
		if(evaltree(nd->left))
			evaltree(nd->right) ;
		return 1;

	}

	if(nd->flag==8)
	{
		while(evaltree(nd->left))
			evaltree(nd->right) ;
		return 1;

	}

	if(nd->flag==9)
	{

		
		return (evaltree(nd->left) == evaltree(nd->right));
	}

}

int main(void) {
	yyparse();
	return 0;
}

