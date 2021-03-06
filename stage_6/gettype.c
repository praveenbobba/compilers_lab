#include<stdio.h>
#include<stdlib.h>
#include"exptree_6.h"

int gettype(struct tnode *nd)
{
	
	if(nd->nodetype == 0 && nd->type == 0 )  //digit
		return 0;

	if(nd->nodetype == 0 && nd->type == 2 )  // boolean diit
		return 2;

	if((nd->type == 0 || nd->type == 1)&& nd->nodetype== 2)  // integer identifier
	{
		return 0;
		//printf("int idntifier\n");
	}

	if((nd->type == 2 || nd->type == 3)&& nd->nodetype== 2)		// boolean identifier
		return 2;	

	if(nd->type == 0 && nd->nodetype== 1)		// for +,-,*,/
	{
		if(gettype(nd->ptr1) == 0 && gettype(nd->ptr3) == 0)
			return 0;
		else
			yyerror("syntax error");
	}
	
	
	if(nd->type == 2 && nd->nodetype== 5 && (strcmp(nd->name,"NOT") != 0 ))		// for AND,OR
	{
		if(gettype(nd->ptr1) == 2 && gettype(nd->ptr3) == 2)
			return 2;
		else
			yyerror("syntax error");
	}

	if(nd->type == 2 && nd->nodetype== 5 && (strcmp(nd->name,"NOT") == 0 ))		// for NOT
	{
		if(gettype(nd->ptr1) == 2)
			return 2;
		else
			yyerror("syntax error");
	}

	if(nd->type == 0 && nd->nodetype== 5)		// <,>,<=,>=,!=
	{
		if(gettype(nd->ptr1) == 0 && gettype(nd->ptr3) == 0)
			return 2;
		else
			yyerror("syntax error");
	}

	if(nd->type == 0 && nd->nodetype== 9)		// for AND,OR
	{
		if(gettype(nd->ptr1) == 0 && gettype(nd->ptr3) == 0)
			return 2;
		else
			yyerror("syntax error");
	}
}
