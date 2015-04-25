#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"exptree_8.h"

struct gsymbol *first = NULL, *last = NULL, *temp,*temp2 ;

void ginstall(char *gname, int type, int size)
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
	
	if(type == 0 || type == 2)
		{			//------- integer or boolean
			newentry->binding = (int *)malloc(1*sizeof(int));
			//printf("ginstall1\n");
		}

	if(type == 1 || type == 3)		//--- integer array or boolean array
		{	
			//printf("ginstall2\n");	
			newentry->binding = (int *)malloc(size*(sizeof(int)));
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
