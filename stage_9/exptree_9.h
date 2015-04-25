#ifndef _EXPTREE_6_H_
#define _EXPTREE_6_H_

struct gsymbol 
{

	char *name; 
	int type; 
	int size; 
	int *binding; 
	char *func_label;
	int func_redef ;
	struct tnode *garg_list;
	struct gsymbol *next; 
};

struct tnode 
{

	int type;
	int nodetype;
	char* name; 
	int value;
	int is_pointer;
	int refer_pointer;
	//tnode *arglist;
	struct tnode *ptr1, *ptr2, *ptr3, *arglist, *arg_next;
	struct tnode *arg_previous ;
	struct gsymbol *gentry; 
	struct lsymbol *lentry; 

};

#define YYSTYPE struct tnode *

//struct Tnode *TreeCreate(TYPE,NODETYPE,VALUE,NAME,ArgList,Ptr1, Ptr2, Ptr3);


struct gsymbol *glookup(char *name); 

void ginstall(char *name,int  type,int size,struct tnode *garg_list,char *label); 

//struct tnode *treecreate(int type,int nodetype,int value,char *name,struct tnode *ptr1,struct tnode *ptr2,struct tnode *ptr3);

struct lsymbol 
{

	char *name; 
	int pointer_type;
	int type; 
	//int size; 
	int *binding; 
	//ArgStruct *ARGLIST;
	struct lsymbol *next;	

};

struct lsymbol *llookup(char *name);

void linstall(char *name,int type,int pointer_type);

 #endif
