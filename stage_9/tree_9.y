%{
	
	#include<stdio.h>
	#include<stdlib.h> 
  	#include"exptree_9.h"
	//int yylex(void);
	FILE *yyin, *fp;
	void yyerror(char *);
	int machinecode(struct tnode *tree);
	int glob_type ;
	int arg_glob_type ;
	int codegen(struct tnode *);
	int getlabel(void);
	int getreg(void);
	void freereg(int );
	int getbind(struct tnode *);
	int getlocbind(struct tnode *);
	int reg_count = -1;
	int lab_count = 0;
	struct tnode *arg_head = NULL, *arg_tail = NULL;
	void arg_make(struct tnode *arg_entry);
	int typecheck(struct tnode *arg1, struct tnode *arg2);
	void param_check(struct tnode *arg1,struct tnode *arg2);
	int func_params_count = 0;
	int file_open = 0;
	int loc_bind_count = 1;
	struct lsymbol *lfirst = NULL, *llast = NULL, *ltemp,*ltemp2 ;
	int loc_type = 0;
	extern int bind_count;	
	struct tnode *call_head = NULL,*call_tail = NULL;
	void make_call_list(struct tnode *newnode);
	
	
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
%token RETURN BEGINN END MAIN

%nonassoc ID
%nonassoc "[" "]"
%nonassoc '='
%left OR AND  
%right NOT 
%nonassoc LT GT GE LE EQU NE
%left '+' '-'
%left '*' '/' '%'



%%

Start 	: 	global funclist mainblock  {exit(1);}

	;

global	:	DECL glist ENDDECL {printf("global decl\n"); }

		|	 

		;

glist	:	glist gstmt

		| 

		;

gstmt	:	type gdecl ';' 

		;

type	:	INTEGER		{	glob_type = 0;
					//printf("chk_int\n");
				}

		| BOOLEAN	{glob_type = 2;}

		;

gdecl	:	gdecl ',' gid

		|gid

		;

gid	: 	ID '[' DIGIT ']'	{ 	
						$1->type = glob_type + 1 ;
						ginstall($1->name,$1->type,$3->value,NULL,"-2");
					}

		| ID			{ 	
						$1->type = glob_type + 0 ;
						//printf("type %d\n",$1->type);
						ginstall($1->name,$1->type,1,NULL,"-2");
						//printf("chk_glob_id %s\n",$1->name);
					}

		| ID '(' arglist ')'	{
						$1->type = glob_type + 0;
						$1->arglist = arg_head;
						ginstall($1->name,$1->type,0,arg_head,$1->name);
						arg_head = NULL;
						arg_tail = NULL;
					}
		
		| ID '(' ')'		{
						$1->type = glob_type + 0;
						$1->arglist = NULL;
						ginstall($1->name,$1->type,0,NULL,$1->name);
						arg_head = NULL;
						arg_tail = NULL;
					}

		;

arglist	:	arglist ';' arg_stmt
	
		| arg_stmt


		;

arg_stmt	:	arg_type arg_decl

		;


arg_type:	INTEGER		{	arg_glob_type = 0;
					//printf("chk_int\n");
				}

		| BOOLEAN	{arg_glob_type = 2;}

		;

arg_decl	:	arg_decl ',' arg_id

			| arg_id

			;

arg_id	:	ID		{
					$1->type = arg_glob_type;
					$1->is_pointer = 0;
					arg_make($1);
					
				}

		| '&' ID	{
					$2->type = arg_glob_type;
					$2->is_pointer = 1;
					arg_make($2);
				}

		;

funclist	:	| funclist funcdef

			;

funcdef		:	type func_name '(' arglist2 ')' '{' local_def body '}'	{
									  $2->gentry = glookup($2->name);
									  if($2->gentry == NULL)
										yyerror("function not declared");
									  $2->type = $2->gentry->type;
									  if($2->gentry->func_redef == 1)
										yyerror("function redefined");
									  else if($2->gentry->func_redef == 0)
										$2->gentry->func_redef = 1;
									  if( gettype($2) != glob_type )
									    yyerror("function return type not matched in decln nd defn");

									   
									   $2->arglist = arg_head;
									   $2->nodetype = 12;
									  if( typecheck($2->arglist,$2->gentry->garg_list) == 0)
									    yyerror("No of arguments are not matched in fn dec n def");
										$2->ptr1 = $8;
										
									  machinecode($2);
										printf("funcdef\n");
									  loc_bind_count = 1;
									  arg_head = NULL;
									  arg_tail = NULL;
									  lfirst = NULL; llast = NULL; //loc symb head n tail
							
									}

		|	type func_name '('  ')' '{' local_def body '}'	{
									  $2->gentry = glookup($2->name);
									  if($2->gentry == NULL)
										yyerror("function not declared");
									  $2->type = $2->gentry->type;
									  if( gettype($2) != glob_type )
									    yyerror("function return type not matched in decln nd defn");

									   
									   $2->arglist = arg_head;
									   $2->nodetype = 12;
									   if( typecheck($2->arglist,$2->gentry->garg_list) == 0)
									    yyerror("No of arguments are not matched in fn dec n def");
										$2->ptr1 = $7;
										
									  machinecode($2);
										printf("funcdef\n");
									  loc_bind_count = 1;
									  arg_head = NULL;
									  arg_tail = NULL;
									  lfirst = NULL; llast = NULL; //loc symb head n tail
							
									}
	
		;

func_name	:	ID		{
						$1->gentry = glookup($1->name);
						if($1->gentry == NULL)
								yyerror("function not declared");
						struct tnode *find_count = glookup($1->name)->garg_list;
						func_params_count = 0;
						while(find_count != NULL)
						{
							func_params_count += 1;
							find_count = find_count->arg_next;
						}
						loc_bind_count = -2+(-1*func_params_count);
						$$ = $1;
					}


		;

mainblock	:	type_main MAIN '(' ')' '{' local_def body '}'	{ ginstall($2->name,0,0,NULL,"-1");
									  $2->gentry = glookup($2->name);
									  $2->type = $2->gentry->type;
									  if( gettype($2) != glob_type )
									    yyerror("function return type not matched in decln nd defn");

									   printf("in main\n");
									   $2->arglist = arg_head;
									   $2->nodetype = 12;
										$2->ptr1 = $7;
										
									  machinecode($2);
									  loc_bind_count = 1;
									  arg_head = NULL;
									  arg_tail = NULL;
									  lfirst = NULL; llast = NULL; //loc symb head n tail
									}

			;

type_main	: INTEGER	{glob_type = 0;
					printf("main type\n");				
				}

		;


arglist2:	arglist2 ';' arg_stmt2
	
		| arg_stmt2


		;

arg_stmt2	:	arg_type2 arg_decl2

		;


arg_type2:	INTEGER		{	arg_glob_type = 0;
					printf("arg_type2\n");
				}

		| BOOLEAN	{arg_glob_type = 2;}

		;

arg_decl2	:	arg_decl2 ',' arg_id2

			| arg_id2

			;

arg_id2	:	ID		{
					$1->type = arg_glob_type;
					$1->is_pointer = 0;
					arg_make($1);
					linstall($1->name,$1->type,$1->is_pointer);
				}

		| '&' ID	{
					$2->type = arg_glob_type;
					$2->is_pointer = 1;
					arg_make($2);
					linstall($2->name,$2->type,$2->is_pointer);
				}

		;


local_def	:	DECL lc_list ENDDECL	{printf("local def\n");}

		;

lc_list	:	lc_list lstmt	{printf("lilist\n");}

		|	{printf("empty lclist\n");}

		;

lstmt	:	ltype ldecl ';' {printf("lstmt\n");}

		;

ltype	:	INTEGER		{	loc_type = 0;
					//printf("chk_int\n");
				}

		| BOOLEAN	{loc_type = 2;}

		;


ldecl	:	ldecl ',' lid

		|lid

		;

lid	: 	ID 		{ 	
					$1->type = loc_type + 0 ;
					$1->is_pointer = 0;
					
					linstall($1->name,$1->type,$1->is_pointer);
					printf("in local id\n");
					
		
				}

		;

body	:	BEGINN BSlist retstmt END	{ printf("body\n");
							$$ = (struct tnode *)malloc(sizeof(struct tnode));
					  $$->nodetype = 14;
					  $$->ptr1 = $2;
					  $$->ptr2 = NULL; $$->ptr3 = $3;
					  //machinecode($$);	
					}

		;

BSlist	:	Slist		{$$=$1;}

		|	{$$=NULL;}

		;

retstmt	:	RETURN expr ';'	{
					if(gettype($2) != glob_type)
						yyerror("return type not matched");
					$1->ptr1 = $2;$$ = $1;
				}

		;

Slist	:  Slist stmt {$$=(struct tnode *)malloc(sizeof(struct tnode));
			$$->nodetype=6;
			$$->ptr1=$1;
			$$->ptr3=$2;}	  	 
					 
	  |stmt		{$$=$1;}
	  ;

stmt	:	ID '='	expr ';'	{ printf("ch_assgn %s\n",$1->name);
						$1->lentry = llookup($1->name);
						 printf("assgn\n");
						
						printf("type\n");
						if($1->lentry == NULL )
						{
							$1->gentry = glookup($1->name);
							if($1->gentry == NULL )
							{
								yyerror("variable not declared");

							}
							else if($1->gentry->func_redef == 1)
								yyerror("assigning variable is a function");
							$1->type = $1->gentry->type;

						}
						else
							$1->type = $1->lentry->type;
						
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
						else if($1->gentry->func_redef == 1)
								yyerror("assigning variable is a function");
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
						$3->lentry = llookup($3->name);
						
						if($3->lentry == NULL )
						{
							$3->gentry = glookup($3->name);
							if($3->gentry == NULL )
							{
								yyerror("variable not declared");

							}
							else if($3->gentry->func_redef == 1)
								yyerror("reading variable is a function");
							$3->type = $3->gentry->type;

						}
						else
							$3->type = $3->lentry->type;
						if(gettype($3) != 0)
							yyerror("variable used in READ is not int type");
						if($3->type == 1 || $3->type == 3 )
							yyerror("variable declared is an array");			
						
						$1->ptr1=$3;$1->ptr3=NULL;$$=$1;
					}

		| READ '(' ID '[' expr ']' ')' ';'   	{ 	
								//printf("in read token\n");
								
							
								$3->gentry = glookup($3->name);
							
								if($3->gentry == NULL)
									yyerror("variable not declared");
								else if($3->gentry->func_redef == 1)
									yyerror("reading variable is a function");

								else
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

		| WRITE '(' expr ')' ';'  { 	printf("ch1\n");
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

		| expr '%' expr 	{
						if(gettype($1) != 0  || gettype($3) != 0)
							yyerror("type conflicts in modulo operation");
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
		
		| ID			{	printf("expr_ID %s\n",$1->name);
						$1->lentry = llookup($1->name);
						
						if($1->lentry == NULL )
						{
							$1->gentry = glookup($1->name);
							
							if($1->gentry == NULL)
								yyerror("variable not declared");
							else if($1->gentry->func_redef == 1)
								yyerror("passing function format is wrong");
							else
								$1->type = $1->gentry->type;

						}
						
						else
							$1->type = $1->lentry->type;
						
						if($1->type == 1 || $1->type == 3 )
							yyerror("variable declared is an array");
						
						$$ = $1;
					}

		| ID '[' expr ']'	{
						
							$1->gentry = glookup($1->name);
							
							if($1->gentry == NULL)
								yyerror("variable not declared");
							else if($1->gentry->func_redef == 1)
								yyerror("passing function format is wrong");

							else
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

		| ID '(' expr_list ')'	{	
						$1->gentry = glookup($1->name);
						if($1->gentry == NULL )
						{
							yyerror("function not declared");

						}
						$1->type = $1->gentry->type;
						$1->nodetype = 15;
						if( ($1->type == 1) || ($1->type == 3) )
							yyerror("function name is declared as an array type");
						$3->arg_previous = NULL;
						param_check($3,$1->gentry->garg_list);
						printf("func call1\n");
						$1->ptr1 = $3;
						$1->ptr3 = NULL;
						$$ = $1;
						call_head = NULL; call_tail = NULL;
						
						
					}

		| ID '(' ')'	{
						$1->gentry = glookup($1->name);
						if($1->gentry == NULL )
						{
							yyerror("function not declared");

						}
						$1->type = $1->gentry->type;
						$1->nodetype = 15;
						if( ($1->type == 1) || ($1->type == 3) )
							yyerror("function name is declared as an array type");

						if($1->gentry->garg_list != NULL)
							yyerror("no of arguments not matched in fuction call");

						$1->ptr1 = NULL;
						$1->ptr3 = NULL;
						$$ = $1;
					}

		;

expr_list	: expr_list ',' expr 	{	//make_call_list($3);
						
        
        						$3->arg_next = $1;
       							 $1->arg_previous = $3;$1 = $3;
        						$$= $1;
   						 
						printf("expr_list1\n");
					}

		| expr			{
						//make_call_list($1);
						$1->arg_next = NULL;
						$1->arg_previous = NULL;
						$$ = $1;
						printf("expr_list2\n");
					}

		;

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
	exit(0);
}

int machinecode(struct tnode *tree)
{
    int r,r1;
    if(file_open == 0)
	{
		fp = fopen("mach.asm","w+");
		fprintf(fp,"START\n");
		fprintf(fp,"MOV SP, %d\n",bind_count-1);
		fprintf(fp,"MOV BP, SP\n");
		r = getreg();
		fprintf(fp,"PUSH R%d\n",r);
		freereg(r);
		fprintf(fp,"CALL MAIN\n");
		r = getreg();
		fprintf(fp,"POP R%d\n",r);
		freereg(r);
		fprintf(fp,"HALT\n");
		file_open = 1;
	}
	printf("machcode\n");
     codegen(tree);
     if( strcmp(tree->name, "main") == 0 )
	{
		
		fclose(fp);
		exit(0);
	}

	return 0;

}

int codegen(struct tnode *nd){
	int r, r1, r2, l,l1,l2,loc_var_count=0, i=0, call_var_count = 0, param_count =0,ret_reg;
	int loc ;
	struct tnode *find_count;
	struct lsymbol *find_count2;

	if(nd->nodetype == 12)
	{
	   	if( strcmp(nd->name, "main") == 0 )
			fprintf(fp,"MAIN:\n");
		else
			fprintf(fp,"L%s:\n",nd->gentry->func_label);
		fprintf(fp,"PUSH BP\n");
		fprintf(fp,"MOV BP, SP\n");
		
		find_count2 = lfirst;
		while(find_count2 != NULL)
		{
			loc_var_count += 1;
			find_count2 = find_count2->next;
		}

		find_count = nd->gentry->garg_list;
		func_params_count =0;
		while(find_count != NULL)
		{
			func_params_count += 1;
			find_count = find_count->arg_next;
		}

		printf("func_params_count %d\n",func_params_count);
		loc_var_count = loc_var_count - func_params_count ; 
		r = getreg();
		r1 = getreg();
		fprintf(fp,"MOV R%d, %d\n",r1,loc_var_count);
		fprintf(fp,"MOV R%d, SP\n",r);
		fprintf(fp,"ADD R%d, R%d\n",r,r1);
		fprintf(fp,"MOV SP, R%d\n",r);
		freereg(r1);
		freereg(r);
		
		r = codegen(nd->ptr1);
		printf("node 12\n");

	}

	if(nd->nodetype == 14)
	{	if(nd->ptr1 != NULL)
			codegen(nd->ptr1);
		//printf("node 14\n");
		if(nd->ptr3 != NULL)
			codegen(nd->ptr3);
		return 1;
	}

	if(nd->nodetype == 11)
	{	printf("node 11\n");
		r = codegen(nd->ptr1);
		r1 = getreg();
		r2 = getreg();
		fprintf(fp,"MOV R%d, BP\n",r1);
		fprintf(fp,"MOV R%d, 2\n",r2);
		fprintf(fp,"SUB R%d, R%d\n",r1,r2);
		freereg(r2);
		fprintf(fp,"MOV [R%d], R%d\n",r1,r);
		freereg(r1);
		freereg(r);
		fprintf(fp,"MOV SP, BP\n");
		fprintf(fp,"POP BP\n");
		fprintf(fp,"RET\n");
		return 1;
		//for return
	}

	if(nd->nodetype == 15)
	{
		for(i=0; i <= reg_count ; i++)
			fprintf(fp,"PUSH R%d\n",i);

		if(nd->ptr1 != NULL)
		{
			struct tnode *push_params = nd->ptr1;
			struct tnode *temp;
			while(push_params->arg_next != NULL)
			{
				temp = push_params;
				push_params = push_params->arg_next;
				push_params->arg_previous = temp;

			}
			
		   while(push_params != NULL)
		   {
			if(push_params->refer_pointer == 1)
			{
				loc = getbind(push_params);
				if(push_params->lentry != NULL)
				{
					r2 = getreg();
					r1 = getreg();
				
					fprintf(fp,"MOV R%d, %d\n",r1,loc);
					fprintf(fp,"MOV R%d, BP\n",r2);
					fprintf(fp,"ADD R%d, R%d\n",r2,r1);
					if(push_params->lentry->pointer_type == 1)
					{
						fprintf(fp,"MOV R%d, [R%d]\n",r1,r2);
						fprintf(fp,"PUSH R%d\n",r1);
					}
					else
						fprintf(fp,"PUSH R%d\n",r2);
					freereg(r1);
					freereg(r2);
				}

				else
				{
				   if(push_params->ptr1 == NULL) // normal id
				   {	r1 = getreg();
					fprintf(fp,"MOV R%d, %d\n",r1,loc);
					fprintf(fp,"PUSH R%d\n",r1);
					freereg(r1);
				   }

				   else 			// array id
				   {	r1 = getreg();
					r2 = codegen(push_params->ptr1);
					fprintf(fp,"MOV R%d, %d\n",r1,loc);
					fprintf(fp,"ADD R%d, R%d\n",r1,r2);
					fprintf(fp,"PUSH R%d\n",r1);
					freereg(r1);
					freereg(r2);
				   }	
			
				}
				
			}

			else
			{	
				r = codegen(push_params);
				fprintf(fp,"PUSH R%d\n",r);
				freereg(r);
			}

			push_params = push_params->arg_previous;
		  }
		}
		
		r = getreg();
		fprintf(fp,"PUSH R%d\n",r);  //space for return value
		freereg(r);
		fprintf(fp,"CALL L%s\n",nd->gentry->func_label);
		r= getreg();
		fprintf(fp,"POP R%d\n",r);
		ret_reg = r;
		find_count = nd->gentry->garg_list;
		while(find_count != NULL)
		{
			param_count += 1;
			find_count = find_count->arg_next;
		}
		
		r = getreg();
		r1 = getreg();
		fprintf(fp,"MOV R%d, %d\n",r1,param_count);
		fprintf(fp,"MOV R%d, SP\n",r);
		fprintf(fp,"SUB R%d, R%d\n",r,r1);
		fprintf(fp,"MOV SP, R%d\n",r);
		freereg(r1);
		freereg(r);

		for(i=reg_count-1; i >= 0 ; i--)    //reg_count-1 is because 1 reg we added for ret val
			fprintf(fp,"POP R%d\n",i);

		return ret_reg; // equals to reg_count only
		
		//func call
	}

	if(nd->nodetype==0)
	{
		r = getreg();
		fprintf(fp,"MOV R%d, %d\n",r,nd->value);
		printf("node digit\n");
		return r;
		//return nd->value;
	}

	if((nd->type==0 || nd->type == 2) && nd->nodetype ==2 )
	{
		r = getreg();
		loc = getbind(nd) ;
		if(nd->lentry != NULL)
		{
			
			r1 = getreg();
			r2 = getreg();
			fprintf(fp,"MOV R%d, %d\n",r2,loc);
			fprintf(fp,"MOV R%d, BP\n",r1);
			fprintf(fp,"ADD R%d, R%d\n",r1,r2);
			fprintf(fp,"MOV R%d, [R%d]\n",r,r1);
			if(nd->lentry->pointer_type == 1)
			{
				fprintf(fp,"MOV R%d, [R%d]\n",r2,r);
				fprintf(fp,"MOV R%d, R%d\n",r,r2);
			}
			
			freereg(r1);
			freereg(r2);
			return r;
				
		}
		else
			fprintf(fp,"MOV R%d, [%d]\n",r,loc);

		printf("node norm id\n");
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
		printf("node array id\n");
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
				if(nd->ptr1->lentry != NULL)
				{	
					r1 = getreg();
					r2 = getreg();
					fprintf(fp,"MOV R%d, %d\n",r2,loc);
					fprintf(fp,"MOV R%d, BP\n",r1);
					fprintf(fp,"ADD R%d, R%d\n",r1,r2);

					//fprintf(fp,"MOV R%d, [R%d]\n",r,r1);
					if(nd->ptr1->lentry->pointer_type == 1)
					{
						fprintf(fp,"MOV R%d, [R%d]\n",r2,r1);
						fprintf(fp,"MOV [R%d], R%d\n",r2,r);
					}
					else
						fprintf(fp,"MOV [R%d], R%d\n",r1,r);
						
					freereg(r1);
					freereg(r2);
					
				}
				else
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
			printf("node assgn\n");

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

		else if(strcmp(nd->name,"%") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"MOD R%d, R%d\n",r1,r2);
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
			if(nd->ptr1->lentry != NULL)
			{
				r1 = getreg();
				r2 = getreg();
				fprintf(fp,"MOV R%d, %d\n",r2,loc);
				fprintf(fp,"MOV R%d, BP\n",r1);
				fprintf(fp,"ADD R%d, R%d\n",r1,r2);
				fprintf(fp,"MOV [R%d], R%d\n",r1,r);
				freereg(r2);
				freereg(r1);
			}
			else
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
		printf("node 4 write\n");
		return 1;
			

	}

	if(nd->nodetype==6)
	{ 	
		codegen(nd->ptr1);
		printf("node 6\n");
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

	if(addr->lentry != NULL)
		return(addr->lentry->binding[0]);
	else
		return(addr->gentry->binding[0]);

}

void arg_make(struct tnode *arg_entry)
{
	struct tnode *arg_temp;
	if(arg_head == arg_tail && arg_head == NULL)
	{
		arg_head = arg_entry;
		arg_tail = arg_entry;
		arg_head->arg_next = NULL;
		arg_tail->arg_next = NULL;
	}

	else
	{
		arg_temp = arg_head;
		arg_head = arg_entry;
		arg_head->arg_next = arg_temp;
	}

	return;
}

int typecheck(struct tnode *arg1, struct tnode *arg2)
{
	while( (arg1 != NULL) && (arg2 != NULL))
	{
		if(arg1->type != arg2->type)
			yyerror("argmnts type not matched in function decln and defn");
		if( strcmp(arg1->name, arg2->name) !=0 )
		{
			printf("argnames %s %s\n",arg1->name,arg2->name);
			yyerror("argmnts name not matched or no of args not equal in function decln and defn ");
		}
		printf("argnames %s %s\n",arg1->name,arg2->name);
		if(arg1->is_pointer != arg2->is_pointer)
			yyerror("pointer argmnts  name not matched in function decln and defn");
		arg1 = arg1->arg_next;
		arg2 = arg2->arg_next;
	}

	if((arg1 == NULL) && (arg2 == NULL))	//----- both are null
		return 1;
	else
		return 0;
}

void param_check(struct tnode *arg1,struct tnode *arg2)
{
	while(arg1 != NULL && arg2 != NULL)
	{
		if( gettype(arg1) != gettype(arg2) )
			
		{	printf("gettype %d %d\n",gettype(arg1),gettype(arg2));
			yyerror("argments passing types not matched or unequal args are passing in fuction call");
			
			//printf("paramcheck %d %d\n",arg1->ptr3->type,arg2->type);
		}
		printf("param name %s %s\n",arg1->name,arg2->name);

		if( arg2->is_pointer == 1 )
		{
			if(arg1->nodetype != 2)
				yyerror("pass by reference not matched in function call");

			arg1->refer_pointer = 1;
			
		}

		arg1 = arg1->arg_next;
		arg2 = arg2->arg_next;
	}

	if(arg1 != NULL || arg2 != NULL)
		yyerror("number of argmnts not matched in function call ");
	return;
}

void make_call_list(struct tnode *newnode)
{
    if (call_head == NULL)
    {
        
        call_head = newnode;
        call_tail = call_head;
    }
    else
    {
        
        newnode->arg_next = call_head;
        call_head->arg_previous = newnode;
        call_head = newnode;
    }
    return;
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

