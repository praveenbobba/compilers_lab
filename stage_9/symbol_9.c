#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"exptree_9.h"
int bind_count = 0;
extern int loc_bind_count ;
extern struct lsymbol *lfirst , *llast , *ltemp,*ltemp2 ;

struct gsymbol *first = NULL, *last = NULL, *temp,*temp2 ;



void ginstall(char *gname, int type, int size, struct tnode *garg_list,char *label)
{

	struct gsymbol *nameconflict = glookup(gname);
	if(nameconflict != NULL)
	{
		printf("variable name conflicts\n");
		exit(0);
	}
//printf("ginstall\n");
	struct gsymbol *newentry = (struct gsymbol *)malloc(sizeof(struct gsymbol));
	newentry->name = (char *)malloc(sizeof(gname));
	strcpy(newentry->name,gname);
	//printf("name in ginstall %s\n",newentry->gname);
	newentry->type = type;
	newentry->size = size;
	newentry->func_label = (char *)malloc(sizeof(label));
	strcpy(newentry->func_label,label);
	newentry->garg_list = garg_list;
	newentry->func_redef = 0;	

   	if(size !=0) // for functions size = 0
	{
		newentry->binding = (int *)malloc(1*sizeof(int));
		newentry->binding[0] = bind_count;
		bind_count += size;
	}	

	if(last == first && first == NULL)
	{
		first = newentry;
		last = newentry;
		first->next = NULL;
		last->next = NULL;
	}

	else
	{
		temp = first;
		first = newentry;
		first->next = temp;
		//printf("ginstall1_node\n");
	}

	//printf("name in ginstall %s\n",newentry->name);
}


struct gsymbol *glookup(char *name)
{
	//printf("glook_name %s\n",name);
	if(first == NULL)
		return first ;
	
	
	for(temp2 = first ; temp2 != NULL ; temp2 = temp2->next)
	{
		if(strcmp(temp2->name,name) == 0)
		{
			
			break;
		}
		
	}
	//printf("glookup\n");
	return temp2;
	
}


//--------- local symbol table entry and local lookup

void linstall(char *lname, int type,int pointer_type)
{
	struct lsymbol *nameconflict = llookup(lname);
	if(nameconflict != NULL)
	{
		printf("local variable name conflicts\n");
		exit(0);
	}

	struct lsymbol *newentry = (struct lsymbol *)malloc(sizeof(struct lsymbol));
	newentry->name = (char *)malloc(sizeof(lname));
	strcpy(newentry->name,lname);
	newentry->type = type;
	newentry->pointer_type = pointer_type;

	newentry->binding = (int *)malloc(1*sizeof(int));
	if(loc_bind_count == -2)
		loc_bind_count = 1;
	newentry->binding[0] = loc_bind_count;
	loc_bind_count += 1;
	
	if(llast == lfirst && lfirst == NULL)
	{
		lfirst = newentry;
		llast = newentry;
		lfirst->next = NULL;
		llast->next = NULL;
	}

	else
	{
		ltemp = lfirst;
		lfirst = newentry;
		lfirst->next = ltemp;
		
	}


}

struct lsymbol *llookup(char *name)
{

	if(lfirst == NULL)
		return lfirst ;
	//printf("llookup\n");
	
	for(ltemp2 = lfirst ; ltemp2 != NULL ; ltemp2 = ltemp2->next)
	{
		if(strcmp(ltemp2->name,name) == 0)
		{
			//printf("llookup\n");
			break;
		}
		
	}

	return ltemp2;
}

