%{
	
	#include<stdio.h>
	#include<stdlib.h> 
  	#include"exptree_7.h"
	//int yylex(void);
	FILE *yyin, *fp;
	void yyerror(char *);
	int machinecode(struct tnode *tree);
	int glob_type ;
	int codegen(struct tnode *);
	int getlabel(void);
	int getreg(void);
	void freereg(int );
	int getbind(struct tnode *);
	int reg_count = -1;
	int lab_count = 0;
	
%}


%token AND
%token OR
%token NOT
%token TRUE
%token FALSE
%token BOOLEAN
%token INTEGER
%token DECL
%token ENDDECL
%token READ
%token WRITE
%token ID
%token DIGIT
%token IF
%token THEN ELSE
%token ENDIF
%token WHILE
%token DO
%token ENDWHILE
%token EQU
%token LT GT LE GE NE

%nonassoc ID
%nonassoc "[" "]"
%nonassoc '='
%left OR AND  
%right NOT 
%nonassoc LT GT GE LE EQU NE
%left '+' '-'
%left '*' '/'



%%

Start : global Slist  {machinecode($2);exit(1);}

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
							yyerror("variable not declared");

						}
						$1->type = $1->gentry->type;
						if(gettype($1) != gettype($3))
							yyerror("type conflicts in assignment");

						if($1->type == 1 || $1->type == 3 )
							yyerror("variable declared is an array");			
						$2->ptr1=$1;$2->ptr3=$3;$$=$2;
						
					}


		| ID '[' expr ']' '=' expr ';'	{ 
						$1->gentry = glookup($1->name);
						if($1->gentry == NULL )
						{
							yyerror("variable not declared");

						}
						$1->type = $1->gentry->type;
						if(gettype($1) != gettype($6))
							yyerror("type conflicts in assignment");
						if( ($1->type == 0) || ($1->type == 2) )
							yyerror("variable is not an array");
						if(gettype($3) != 0)
							yyerror("array index is not an integer");
						$1->ptr1 = $3; $1->ptr3 = NULL;			
						$5->ptr1=$1;$5->ptr3=$6;$$=$5;
						//printf("arr_assgn\n");
						
					}

		| READ '(' ID ')' ';'   { 	
						//printf("in read token\n");
						$3->gentry = glookup($3->name);
						if($3->gentry == NULL )
						{
							yyerror("variable not declared");

						}
						$3->type = $3->gentry->type;
						if(gettype($3) != 0)
							yyerror("variable used in READ is not int type");
						if($3->type == 1 || $3->type == 3 )
							yyerror("variable declared is an array");			
						
						$1->ptr1=$3;$1->ptr3=NULL;$$=$1;
					}

		| READ '(' ID '[' expr ']' ')' ';'   	{ 	
								//printf("in read token\n");
								$3->gentry = glookup($3->name);
								if($3->gentry == NULL )
								{
								yyerror("variable not declared");

								}
							$3->type = $3->gentry->type;
							if(gettype($3) != 0 )
								yyerror("variable used in READ is not int type");

							if( ($3->type == 0) || ($3->type == 2) )
								yyerror("variable is not an array");

							if(gettype($5) != 0 )
								yyerror("array index type is not int");
							$3->ptr1 = $5; 
							$3->ptr3 = NULL;			
						
							$1->ptr1=$3;$1->ptr3=NULL;$$=$1;
					}

		| WRITE '(' expr ')' ';'  { 	//printf("ch1\n");
						if(gettype($3) != 0)
						{	//printf("gettype %d\n",gettype($3));
							yyerror("expression in READ is not int type");			
						}
						$1->ptr1=$3;$1->ptr3=NULL;$$=$1;
						//printf("ch1\n");
					}

		| IF '(' expr ')' THEN Slist cond ENDIF ';'	{$1->ptr1=$3;$1->ptr2=$6;$1->ptr3=$7;$$=$1;}

		| WHILE '(' expr ')' DO Slist ENDWHILE ';'	{$1->ptr1=$3;$1->ptr3=$6;$$=$1;}

	

		;

cond	:	ELSE Slist		{$$ = $2;}

		|			{$$ = NULL;}
		
		;

global	:	DECL glist ENDDECL

		|	 

		;

glist	:	glist gstmt

		| 

		;

gstmt	:	type gdecl ';' 

		;

gdecl	:	gdecl ',' gid

		|gid

		;

type	:	INTEGER		{	glob_type = 0;
					//printf("chk_int\n");
				}

		| BOOLEAN	{glob_type = 2;}

		;

gid	: 	ID '[' DIGIT ']'	{ 	
						$1->type = glob_type + 1 ;
						ginstall($1->name,$1->type,$3->value);
					}

		| ID			{ 	
						$1->type = glob_type + 0 ;
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
							yyerror("type conflicts in addition operation");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}
 
		| expr '-' expr 	{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("type conflicts in subtraction operation");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr '*' expr 	{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("type conflicts in multiplication operation");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr '/' expr 	{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("type conflicts in division operation");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr GT expr 		{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("type conflicts in relational operation");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr LT expr		{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("type conflicts in relational operation");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr LE expr		{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("type conflicts in relational operation");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr GE expr		{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("type conflicts in relational operation");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr NE expr		{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("type conflicts in relational operation");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr EQU expr 	{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("type conflicts in relational operation");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}
		
		| ID			{	//printf("expr_ID %s\n",$1->name);
						$1->gentry = glookup($1->name);
						if($1->gentry == NULL )
						{
							yyerror("variable not declared");

						}
						$1->type = $1->gentry->type;
						
						if($1->type == 1 || $1->type == 3 )
							yyerror("variable declared is an array");
						
						$$ = $1;
					}

		| ID '[' expr ']'	{
						$1->gentry = glookup($1->name);
						if($1->gentry == NULL )
						{
							yyerror("variable not declared");

						}
						$1->type = $1->gentry->type;

						if( ($1->type == 0) || ($1->type == 2) )
							yyerror("variable is not an array");

						if(gettype($3)!=0)
							yyerror("array index is not an integer");

						$1->ptr1 = $3;
						$1->ptr3 = NULL;
						$$ = $1;
					}

		| TRUE			{$$=$1;}

		| FALSE			{$$=$1;}

		| expr AND expr 	{
						if(gettype($1) != 2  || gettype($3) != 2)
							yyerror("type conflicts in logical operation");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| expr OR expr 		{
						if(gettype($1) != 2  || gettype($3) != 2)
							yyerror("type conflicts in logical operation");
						$2->ptr1=$1;
					 	$2->ptr3=$3;
					 	$$=$2;
					}

		| NOT expr 		{
						if(gettype($2) != 2)
							yyerror("type conflicts in logical operation");
						$1->ptr1=$2;
					 	$1->ptr3=NULL;
					 	$$=$1;
					}

		;

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
	exit(0);
}

int machinecode(struct tnode *tree)
{
	fp = fopen("mach.asm","w+");
	fprintf(fp,"START\n");
	codegen(tree);
	fprintf(fp,"HALT\n");
	fclose(fp);

}

int codegen(struct tnode *nd){
	int r, r1, r2, l,l1,l2;
	int loc ;

	if(nd->nodetype==0)
	{
		r = getreg();
		fprintf(fp,"MOV R%d, %d\n",r,nd->value);
		return r;
		//return nd->value;
	}

	if((nd->type==0 || nd->type == 2) && nd->nodetype ==2 )
	{
		r = getreg();
		loc = getbind(nd) ;
		fprintf(fp,"MOV R%d, [%d]\n",r,loc);
		return r;
		//return (nd->gentry->binding[0]) ;
	}

	if((nd->type==1 || nd->type == 3) && nd->nodetype ==2 )
	{
		r1 = getreg();
		loc = getbind(nd) ;
		r2 = codegen(nd->ptr1);
		r = getreg();
		fprintf(fp,"MOV R%d, %d\n",r,loc);
		fprintf(fp,"ADD R%d, R%d\n",r2,r);
		freereg(r);
		fprintf(fp,"MOV R%d, [R%d]\n",r1,r2);
		freereg(r2);
		return r1;
		//return (nd->gentry->binding[evaltree(nd->ptr1)]) ;
	}

	if(nd->nodetype==1){
		if(strcmp(nd->name,"=") == 0)

		   {
			if(nd->ptr1->type == 0 || nd->ptr1->type == 2)
			{
				r = codegen(nd->ptr3);
				loc = getbind(nd->ptr1) ;
				fprintf(fp,"MOV [%d], R%d\n",loc,r);
				freereg(r);
				return 1;

		     		//nd->ptr1->gentry->binding[0]=evaltree(nd->ptr3);
		     		
			}
			//printf("=\n");

			if(nd->ptr1->type == 1 || nd->ptr1->type == 3)
			{
				//printf("=\n");
				r1 = codegen(nd->ptr3);
				r2 = codegen(nd->ptr1->ptr1);
				loc = getbind(nd->ptr1) ;
				r = getreg();
				fprintf(fp,"MOV R%d, %d\n",r,loc);
				fprintf(fp,"ADD R%d, R%d\n",r2,r);
				freereg(r);
				fprintf(fp,"MOV [R%d], R%d\n",r2,r1);
				freereg(r2);
				freereg(r1);
				return 1;

		     		//nd->ptr1->gentry->binding[evaltree(nd->ptr1->ptr1)]=evaltree(nd->ptr3);
		     	
			}

		   }	
	
		if(strcmp(nd->name,"+") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"ADD R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1)+evaltree(nd->ptr3));
		}

		else if(strcmp(nd->name,"-") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"SUB R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) - evaltree(nd->ptr3));
		}
		else if(strcmp(nd->name,"*") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"MUL R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) * evaltree(nd->ptr3));
		}
		else if(strcmp(nd->name,"/") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"DIV R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) / evaltree(nd->ptr3));
		}
	}
	if(nd->nodetype==3)
	{ 
		if(nd->ptr1->type == 0 )
		{
			r = getreg();
			loc = getbind(nd->ptr1);
			fprintf(fp,"IN R%d\n",r);
			fprintf(fp,"MOV [%d], R%d\n",loc,r);
			freereg(r);	     		
	     		return 1;
		}

		if(nd->ptr1->type == 1)
		{
			r1 = getreg();
			r2 = codegen(nd->ptr1->ptr1);
			loc = getbind(nd->ptr1);
			fprintf(fp,"IN R%d\n",r1);
			r = getreg();
			fprintf(fp,"MOV R%d, %d\n",r,loc);
			fprintf(fp,"ADD R%d, R%d\n",r2,r);
			freereg(r);
			fprintf(fp,"MOV [R%d], R%d\n",r2,r1);
			freereg(r1);
			freereg(r2);	     		
	     		return 1;
	     		//nd->ptr1->gentry->binding[evaltree(nd->ptr1->ptr1)]=c;
	     	
		}
		 
	}

	if(nd->nodetype==4)
	{	
		r = codegen(nd->ptr1);
		fprintf(fp,"OUT R%d\n",r);
		freereg(r);		
	     //printf("%d\n",evaltree(nd->ptr1));
		return 1;
			

	}

	if(nd->nodetype==6)
	{ codegen(nd->ptr1);
	  codegen(nd->ptr3);
	 return 1;
	}

	if(nd->type == 2 && nd->nodetype==10){
				
		if(strcmp (nd->name,"<") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"LT R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) < evaltree(nd->ptr3));
		}

		if(strcmp (nd->name,">") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"GT R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) > evaltree(nd->ptr3));
		}

		if(strcmp (nd->name,"<=") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"LE R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) <= evaltree(nd->ptr3));
		}
		if(strcmp (nd->name,">=") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"GE R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) >= evaltree(nd->ptr3));
		}
		if(strcmp (nd->name,"!=") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"NE R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) != evaltree(nd->ptr3));
		}
		
	}

	if(nd->type == 2 && nd->nodetype==5){
				
		if(strcmp (nd->name,"AND") == 0)
		{
			r1 = codegen(nd->ptr1);
			l1 = getlabel() ;
			fprintf(fp,"JZ R%d, L%d\n",r1,l1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"JZ R%d, L%d\n",r2,l1);
			l2 = getlabel() ;
			fprintf(fp,"MOV R%d, 1\n",r1);
			fprintf(fp,"JMP L%d\n",l2);
			freereg(r2);
			fprintf(fp,"L%d:\n",l1);
			fprintf(fp,"MOV R%d, 0\n",r1);
			fprintf(fp,"L%d:\n",l2);
			return r1;
			//return (evaltree(nd->ptr1) && evaltree(nd->ptr3));
		}
		if(strcmp (nd->name,"OR") == 0)
		{
			r1 = codegen(nd->ptr1);
			l1 = getlabel() ;
			fprintf(fp,"JNZ R%d, L%d\n",r1,l1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"JNZ R%d, L%d\n",r2,l1);
			l2 = getlabel() ;
			fprintf(fp,"MOV R%d, 0\n",r1);
			fprintf(fp,"JMP L%d\n",l2);
			freereg(r2);
			fprintf(fp,"L%d:\n",l1);
			fprintf(fp,"MOV R%d, 1\n",r1);
			fprintf(fp,"L%d:\n",l2);
			return r1;
			//return (evaltree(nd->ptr1) || evaltree(nd->ptr3));
		}

		if(strcmp (nd->name,"NOT") == 0)
		{
			r = codegen(nd->ptr1);
			l1 = getlabel();
			fprintf(fp,"JZ R%d, L%d\n",r,l1);
			fprintf(fp,"MOV R%d, 0\n",r);
			l2 = getlabel() ;
			fprintf(fp,"JMP L%d\n",l2);
			fprintf(fp,"L%d:\n",l1);
			fprintf(fp,"MOV R%d\n, 1",r);
			fprintf(fp,"L%d:\n",l2);
			return r;
		}
		
	}

	if(nd->nodetype==7)
	{
	  if(nd->ptr3 != NULL )
	  {
		r = codegen(nd->ptr1);
		l1 = getlabel();
		l2 = getlabel();
		fprintf(fp,"JZ R%d, L%d\n",r,l1);
		freereg(r);
		r = codegen(nd->ptr2);
		fprintf(fp,"JMP L%d\n",l2);
		fprintf(fp,"L%d:\n",l1);
		r = codegen(nd->ptr3);
		fprintf(fp,"L%d:\n",l2);
		
	  }

	  else
	  {

		r = codegen(nd->ptr1);
		l1 = getlabel();
		//l2 = getlabel();
		fprintf(fp,"JZ R%d, L%d\n",r,l1);
		freereg(r);
		r = codegen(nd->ptr2);
		fprintf(fp,"L%d:\n",l1);

	  }
		/*if(evaltree(nd->ptr1))
			evaltree(nd->ptr2) ;
		else if(nd->ptr3 != NULL)
			evaltree(nd->ptr3) ;*/
		return 1;

	}

	if(nd->nodetype==8)
	{
		l1 = getlabel();
		fprintf(fp,"L%d:\n",l1);
		r = codegen(nd->ptr1);
		l2 = getlabel();
		fprintf(fp,"JZ R%d, L%d\n",r,l2);
		freereg(r);
		r = codegen(nd->ptr3);
		fprintf(fp,"JMP L%d\n",l1);

		fprintf(fp,"L%d:\n",l2);
		/*while(evaltree(nd->ptr1))
			evaltree(nd->ptr3) ;*/
		return 1;

	}

	if(nd->nodetype==9)
	{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"EQ R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
		
		//return (evaltree(nd->ptr1) == evaltree(nd->ptr3));
	}

}

int getlabel(void)
{
	lab_count += 1;
}

int getreg(void)
{
	reg_count += 1;
	return reg_count;
}

void freereg(int free_count)
{

	reg_count -= 1 ;
	return ;
}

int getbind(struct tnode *addr)
{
	return(addr->gentry->binding[0]);

}

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		FILE *fin = fopen(argv[1], "r");
		if(fin)
			yyin = fin;
	}
	yyparse();
	return 0;
}

