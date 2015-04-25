#include<stdio.h>
#include<stdlib.h>
#include"exptree_9.h"

int gettype(struct tnode *nd)
{
	
	if(nd->nodetype == 0 && nd->type == 0 )  //digit
		return 0;

	if(nd->nodetype == 0 && nd->type == 2 )  // boolean diit
		return 2;

	if((nd->type == 0 || nd->type == 1)&& ( nd->nodetype== 2 || nd->nodetype == 12) )  // integer identifier
	{
		return 0;
		//printf("int idntifier\n");
	}

	if((nd->type == 2 || nd->type == 3)&& ( nd->nodetype== 2 || nd->nodetype == 12))		// boolean identifier
		return 2;	

	if(nd->type == 0 && nd->nodetype== 1)		// for +,-,*,/
	{
		if(( (nd->ptr1->type == 0) || (nd->ptr1->type == 1)) && ( (nd->ptr3->type == 0) || (nd->ptr3->type == 1)))
			return 0;
		else
			return -5;
	}
	
	
	if(nd->type == 2 && nd->nodetype== 5 && (strcmp(nd->name,"NOT") != 0 ))		// for AND,OR
	{
		if(( (nd->ptr1->type == 2) || (nd->ptr1->type == 3)) && ( (nd->ptr3->type == 2) || (nd->ptr3->type == 3)))
			return 2;
		else
			return -5;
	}

	if(nd->type == 2 && nd->nodetype== 5 && (strcmp(nd->name,"NOT") == 0 ))		// for NOT
	{
		if(( (nd->ptr1->type == 2) || (nd->ptr1->type == 3)))
			return 2;
		else
			return -5;
	}

	if(nd->type == 2 && nd->nodetype== 10)		// <,>,<=,>=,!=
	{
		if(( (nd->ptr1->type == 0) || (nd->ptr1->type == 1)) && ( (nd->ptr3->type == 0) || (nd->ptr3->type == 1)))
			return 2;
		else
			return -5;
	}

	if(nd->type == 2 && nd->nodetype== 9)		// ==
	{
		if(( (nd->ptr1->type == 0) || (nd->ptr1->type == 1)) && ( (nd->ptr3->type == 0) || (nd->ptr3->type == 1)))
			return 2;
		else
			return -5;
	}

	
}
