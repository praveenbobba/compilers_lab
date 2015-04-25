#ifndef _EXPTREE_6_H_
#define _EXPTREE_6_H_

struct gsymbol 
{

	char *name; 
	int type; 
	int size; 
	int *binding; 
	//ArgStruct *ARGLIST;
	struct gsymbol *next; 
};

struct tnode 
{

	int type;
	int nodetype;
	char* name; 
	int value;
	//tnode *arglist;
	struct tnode *ptr1, *ptr2, *ptr3;
	struct gsymbol *gentry; 
	struct lsymbol *lentry; 

};

#define YYSTYPE struct tnode *

//struct Tnode *TreeCreate(TYPE,NODETYPE,VALUE,NAME,ArgList,Ptr1, Ptr2, Ptr3);


struct gsymbol *glookup(char *name); 

void ginstall(char *name,int  type,int size); 

//struct tnode *treecreate(int type,int nodetype,int value,char *name,struct tnode *ptr1,struct tnode *ptr2,struct tnode *ptr3);

struct lsymbol 
{

	char *name2; 
	int type2; 
	//int size; 
	int *binding2; 
	//ArgStruct *ARGLIST;
	struct lsymbol *next2;	

};

//struct lsymbol *llookup(name);

//void linstall(name, type);

 #endif
