%{
	
	#include<stdio.h>
	#include<stdlib.h> 
  	#include"exptree_6.h"
	//int yylex(void);
	FILE *yyin;
	void yyerror(char *);
	int evaltree(struct tnode *nd);
	int glob_type ;
	
%}

%token DECL
%token ENDDECL
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
%token EQU
%token LT GT LE GE NE

%nonassoc ID
%nonassoc "[" "]"
%nonassoc '=' 
%nonassoc LT GT GE LE EQU NE
%left '+' '-'
%left '*' '/'



%%

Start : global Slist  {evaltree($2);exit(1);}

	;

Slist	:  Slist stmt {$$=(struct tnode *)malloc(sizeof(struct tnode));
			$$->nodetype=6;
			$$->ptr1=$1;
			$$->ptr3=$2;}	  	 
					 
	  |stmt		{$$=$1;}
	  ;

stmt	:	ID '='	expr ';'	{ //printf("ch_assgn %s\n",$1->name);
						$1->gentry = glookup($1->name);
						if($1->gentry == NULL )
						{
							yyerror("syntax error1");

						}
						$1->type = $1->gentry->type;
						if(gettype($1) != gettype($3))
							yyerror("syntax error2");			
						$2->ptr1=$1;$2->ptr3=$3;$$=$2;
						
					}


		| ID '[' expr ']' '=' expr ';'	{ 
						$1->gentry = glookup($1->name);
						if($1->gentry == NULL )
						{
							yyerror("syntax error3");

						}
						$1->type = $1->gentry->type;
						if(gettype($1) != gettype($6))
							yyerror("syntax error4");
						if(gettype($3) != 0)
							yyerror("syntax error25");
						$1->ptr1 = $3; $1->ptr3 = NULL;			
						$5->ptr1=$1;$5->ptr3=$6;$$=$5;
						//printf("arr_assgn\n");
						
					}

		| READ '(' ID ')' ';'   { 	
						//printf("in read token\n");
						$3->gentry = glookup($3->name);
						if($3->gentry == NULL )
						{
							yyerror("syntax error5");

						}
						$3->type = $3->gentry->type;
						if(gettype($3) != 0)
							yyerror("syntax error6");			
						
						$1->ptr1=$3;$1->ptr3=NULL;$$=$1;
					}

		| READ '(' ID '[' expr ']' ')' ';'   	{ 	
								//printf("in read token\n");
								$3->gentry = glookup($3->name);
								if($3->gentry == NULL )
								{
								yyerror("syntax error7");

								}
							$3->type = $3->gentry->type;
							if(gettype($3) != 0)
								yyerror("syntax error8");
							$3->ptr1 = $5; 
							$3->ptr3 = NULL;			
						
							$1->ptr1=$3;$1->ptr3=NULL;$$=$1;
					}

		| WRITE '(' expr ')' ';'  { 	//printf("ch1\n");
						if(gettype($3) != 0)
						{	//printf("gettype %d\n",gettype($3));
							yyerror("syntax error9");			
						}
						$1->ptr1=$3;$1->ptr3=NULL;$$=$1;
						//printf("ch1\n");
					}

		| IF '(' expr ')' THEN Slist ENDIF ';'	{$1->ptr1=$3;$1->ptr3=$6;$$=$1;}

		| WHILE '(' expr ')' DO Slist ENDWHILE ';'	{$1->ptr1=$3;$1->ptr3=$6;$$=$1;}

	

		;

global	:	DECL glist ENDDECL

		|	 

		;

glist	:	glist gstmt

		| 

		;

gstmt	:	 gdecl ';' 

		;

gdecl	:	gdecl ',' gid

		|gid

		;

gid	: 	ID '[' DIGIT ']'	{ 	
						$1->type =  1 ;
						ginstall($1->name,$1->type,$3->value);
					}

		| ID			{ 	
						$1->type = 0 ;
						//printf("type %d\n",$1->type);
						ginstall($1->name,$1->type,1);
						//printf("chk_glob_id %s\n",$1->name);
					}

		;


expr	:	DIGIT 			{
						$$=$1;
						//printf("chk_dig\n");
					}

		| '(' expr ')' 		{$$=$2;}

		| expr '+' expr 	{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("syntax error10");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}
 
		| expr '-' expr 	{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("syntax error11");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr '*' expr 	{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("syntax error12");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr '/' expr 	{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("syntax error13");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr GT expr 		{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("syntax error14");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr LT expr		{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("syntax error15");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr LE expr		{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("syntax error16");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr GE expr		{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("syntax error17");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr NE expr		{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("syntax error18");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr EQU expr 	{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("syntax error19");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}
		
		| ID			{	//printf("expr_ID %s\n",$1->name);
						$1->gentry = glookup($1->name);
						if($1->gentry == NULL )
						{
							yyerror("syntax error24");

						}
						$1->type = $1->gentry->type;
						
						$$ = $1;
					}

		| ID '[' expr ']'	{
						$1->gentry = glookup($1->name);
						if($1->gentry == NULL )
						{
							yyerror("syntax error25");

						}
						$1->type = $1->gentry->type;

						if(gettype($3)!=0)
							yyerror("syntax error20");

						$1->ptr1 = $3;
						$1->ptr3 = NULL;
						$$ = $1;
					}


		;

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int evaltree(struct tnode *nd){

	if(nd->nodetype==0){
		return nd->value;
	}
	if((nd->type==0 || nd->type == 2) && nd->nodetype ==2 )
		return (nd->gentry->binding[0]) ;

	if((nd->type==1 || nd->type == 3) && nd->nodetype ==2 )
		return (nd->gentry->binding[evaltree(nd->ptr1)]) ;

	if(nd->nodetype==1){
		if(strcmp(nd->name,"=") == 0)

		   {
			if(nd->ptr1->type == 0 || nd->ptr1->type == 2)
			{
		     		nd->ptr1->gentry->binding[0]=evaltree(nd->ptr3);
		     		return 1;
			}
			//printf("=\n");

			if(nd->ptr1->type == 1 || nd->ptr1->type == 3)
			{
				//printf("=\n");
		     		nd->ptr1->gentry->binding[evaltree(nd->ptr1->ptr1)]=evaltree(nd->ptr3);
		     		return 1;
			}

		   }	
	
		if(strcmp(nd->name,"+") == 0)
			return (evaltree(nd->ptr1)+evaltree(nd->ptr3));
		else if(strcmp(nd->name,"-") == 0)
			return (evaltree(nd->ptr1) - evaltree(nd->ptr3));
		else if(strcmp(nd->name,"*") == 0)
			return (evaltree(nd->ptr1) * evaltree(nd->ptr3));
		else if(strcmp(nd->name,"/") == 0)
			return (evaltree(nd->ptr1) / evaltree(nd->ptr3));
	}
	if(nd->nodetype==3)
	{ int c;
		scanf("%d",&c);
			if(nd->ptr1->type == 0 )
			{
		     		nd->ptr1->gentry->binding[0]=c;
		     		return 1;
			}

			if(nd->ptr1->type == 1)
			{
		     		nd->ptr1->gentry->binding[evaltree(nd->ptr1->ptr1)]=c;
		     		return 1;
			}
		 
	}

	if(nd->nodetype==4)
	{	
			//printf("ch_write\n");
		     		printf("%d\n",evaltree(nd->ptr1));
		     		return 1;
			

	}

	if(nd->nodetype==6)
	{ evaltree(nd->ptr1);
	  evaltree(nd->ptr3);
	 return 1;
	}

	if(nd->type == 0 && nd->nodetype==5){
				
		if(strcmp (nd->name,"<") == 0)
			return (evaltree(nd->ptr1) < evaltree(nd->ptr3));
		if(strcmp (nd->name,">") == 0)
			return (evaltree(nd->ptr1) > evaltree(nd->ptr3));
		if(strcmp (nd->name,"<=") == 0)
			return (evaltree(nd->ptr1) <= evaltree(nd->ptr3));
		if(strcmp (nd->name,">=") == 0)
			return (evaltree(nd->ptr1) >= evaltree(nd->ptr3));
		if(strcmp (nd->name,"!=") == 0)
			return (evaltree(nd->ptr1) != evaltree(nd->ptr3));
		
	}

	if(nd->nodetype==7)
	{
		if(evaltree(nd->ptr1))
			evaltree(nd->ptr3) ;
		return 1;

	}

	if(nd->nodetype==8)
	{
		while(evaltree(nd->ptr1))
			evaltree(nd->ptr3) ;
		return 1;

	}

	if(nd->nodetype==9)
	{

		
		return (evaltree(nd->ptr1) == evaltree(nd->ptr3));
	}

}

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
	}
	yyparse();
	return 0;
}

