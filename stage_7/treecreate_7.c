
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"exptree_7.h"

struct tnode *treecreate(int type,int nodetype,int value,char *name,struct tnode *ptr1,struct tnode *ptr2,struct tnode *ptr3)
{
	struct tnode *newnode = (struct tnode *)malloc(sizeof(struct tnode));
	newnode->type = type;
	newnode->nodetype = nodetype;
	newnode->value = value;
	newnode->name = (char *)malloc(sizeof(name));
		//printf("in treecreate\n");
	strcpy(newnode->name,name);
		//printf("in treecreate\n");
		//printf("treecreate name %s\n",newnode->name);
	newnode->ptr1 = ptr1;
	newnode->ptr2 = ptr2;
	newnode->ptr3 = ptr3;
	newnode->gentry = NULL;
	return (newnode) ; 
}
