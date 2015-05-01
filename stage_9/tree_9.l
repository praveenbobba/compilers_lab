%{

  #include<stdio.h>
  #include<stdlib.h>
  #include"y.tab.h"
  #include"exptree_9.h"
  void yyerror(char *);


%}



%%

[\n] 	{
		
		
	}

[ \t] {
		
	}

[0-9]+ {//yylval = (struct tnode *)malloc(sizeof(struct tnode));
	yylval = treecreate(0,0,atoi(yytext),"$",NULL,NULL,NULL,NULL);
	//yylval->nodetype = 0;	
	//yylval->value = atoi(yytext);
	return DIGIT ;
	}

"iter"	{
		return ITER;
	}

"begin"	{
		return BEGINN;
	}

"end"	{
		return END ;
	}

"main"	{	
		yylval = treecreate(0,2,-1,yytext,NULL,NULL,NULL,NULL);
		return MAIN ;
	}

"AND"	{//yylval = (struct tnode *)malloc(sizeof(struct tnode));
		yylval = treecreate(2,5,-1,yytext,NULL,NULL,NULL,NULL);
		return AND;
	}

"OR"	{//yylval = (struct tnode *)malloc(sizeof(struct tnode));
		yylval = treecreate(2,5,-1,yytext,NULL,NULL,NULL,NULL);
		return OR;
	}

"NOT"	{//yylval = (struct tnode *)malloc(sizeof(struct tnode));
		yylval = treecreate(2,5,-1,yytext,NULL,NULL,NULL,NULL);
		return NOT;
	}

"decl"	{
	return DECL ;
	}

"enddecl" {
	   return ENDDECL ;
	  }

"integer" {
	    return INTEGER ;
	  }

"boolean"	{
	  return BOOLEAN ;
	}

"TRUE" {//yylval = (struct tnode *)malloc(sizeof(struct tnode));
	yylval = treecreate(2,0,1,"$",NULL,NULL,NULL,NULL);
	//yylval->nodetype = 0;	
	return TRUE ;
	}

"FALSE" {//yylval = (struct tnode *)malloc(sizeof(struct tnode));
	yylval = treecreate(2,0,0,"$",NULL,NULL,NULL,NULL);
	//yylval->nodetype = 0;	
	return FALSE ;
	}


"read"	{//yylval = (struct tnode *)malloc(sizeof(struct tnode));
		yylval = treecreate(0,3,-1,"$",NULL,NULL,NULL,NULL);
	//yylval->nodetype = 3;
	//printf("read\n");
	return READ ;
	}

"write" {//yylval = (struct tnode *)malloc(sizeof(struct tnode));
		yylval = treecreate(0,4,-1,"$",NULL,NULL,NULL,NULL);
	//yylval->nodetype = 4;
	//printf("write\n");
	return WRITE ;
	}

"if" {//yylval = (struct tnode *)malloc(sizeof(struct tnode));
		yylval = treecreate(-1,7,-1,"$",NULL,NULL,NULL,NULL);
	//yylval->nodetype = 7;
	//printf("write\n");
	return IF ;
	}

"then" {
	return THEN ;
	}

"endif" {
	return ENDIF ;
	}

"else" {
	return ELSE ;
	}

"while" {//yylval = (struct tnode *)malloc(sizeof(struct tnode));
		yylval = treecreate(-1,8,-1,"$",NULL,NULL,NULL,NULL);
	//yylval->nodetype = 8;
	//printf("write\n");
	return WHILE ;
	}

"do" {
	return DO ;
	}

"endwhile" {
	return ENDWHILE ;
	}

"return" {
		yylval = treecreate(-1,11,-1,"$",NULL,NULL,NULL,NULL);
		return RETURN ;
	}


"<=" {//yylval = (struct tnode *)malloc(sizeof(struct tnode));
		yylval = treecreate(2,10,-1,yytext,NULL,NULL,NULL,NULL);
	//yylval->nodetype = 5;	
	//yylval->name = *yytext;


		if( strcmp (yytext,"<=") == 0 )
			return LE ;

	}
">=" {//yylval = (struct tnode *)malloc(sizeof(struct tnode));
		yylval = treecreate(2,10,-1,yytext,NULL,NULL,NULL,NULL);
	//yylval->nodetype = 5;	
	//yylval->name = *yytext;

		if( strcmp (yytext,">=") == 0 )
			return GE ;

	}
"!=" {//yylval = (struct tnode *)malloc(sizeof(struct tnode));
		yylval = treecreate(2,10,-1,yytext,NULL,NULL,NULL,NULL);
	//yylval->nodetype = 5;	
	//yylval->name = *yytext;

		if( strcmp (yytext,"!=") == 0 )
			return NE ;
	}

"==" {//yylval = (struct tnode *)malloc(sizeof(struct tnode));
		yylval = treecreate(2,9,-1,"$",NULL,NULL,NULL,NULL);
	//yylval->nodetype = 9;	
	return EQU ;
	}

[<>] {//yylval = (struct tnode *)malloc(sizeof(struct tnode));
		yylval = treecreate(2,10,-1,yytext,NULL,NULL,NULL,NULL);
	//yylval->nodetype = 5;	
	//yylval->name = *yytext;
		if( strcmp (yytext,"<") == 0 )
			return LT ;

		if( strcmp (yytext,">") == 0 )
			return GT ;

	}

[();,] 	{
		//printf("%c\n",*yytext);
		return *yytext;
	}

"["	{
		//printf("%c\n",*yytext);
		return *yytext;
	}

"]" 	{
		//printf("%c\n",*yytext);
		return *yytext;
	}

"&"	{
		return *yytext;
	}

"{"	{
		return *yytext;
	}

"}"	{
		return *yytext;
	}


[-/+*=%] {//yylval = (struct tnode *)malloc(sizeof(struct tnode));
		yylval = treecreate(0,1,-1,yytext,NULL,NULL,NULL,NULL);
		//printf("reg expr ID %s\n ",yytext);
	//yylval->nodetype = 1;	
	//yylval->name = *yytext;
	return *yytext ;
	}



[a-z|A-Z][a-z|A-Z|0-9]* {	//printf("reg expr ID \n ");
				yylval = treecreate(-1,2,-1,yytext,NULL,NULL,NULL,NULL);
				//printf("reg expr ID \n ");
				return ID ;
			}


. yyerror("invalid"); 	
	
%%


int yywrap(void)
{
	return 1;

}
