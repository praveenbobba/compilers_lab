#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"exptree_7.h"
int bind_count = 0;

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

	newentry->binding = (int *)malloc(1*sizeof(int));
	newentry->binding[0] = bind_count;
	bind_count += size;
	
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
