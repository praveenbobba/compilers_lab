#include<stdio.h>
	#include<stdlib.h>
	int codegen(node *);
	int getlabel(void);
	int getreg(void);
	void freereg(int );
	int getbind(char *);
	int reg_count = -1;
	int lab_count = 0;
	FILE *fp ;

int machinecode(node *tree)
{
	fp = fopen("mach.asm","w+");
	fprintf(fp,"START\n");
	codegen(tree);
	fprintf(fp,"HALT\n");
	fclose(fp);

}

int codegen(node *nd){

	int r, r1, r2, l,l1,l2;
	int loc ;
	if(nd->nodetype==0)
	{
		r = getreg();
		fprintf(fp,"MOV R%d, %d\n",r,nd->val);
		return r;
		//return nd->val;
	}

	if(nd->flag==2)
	{
		r = getreg();
		loc = nd->index;
		fprintf(fp,"MOV R%d, [%d]\n",r,loc);
		return r;
		//return array[nd->index];
	}

	if(nd->flag==1)
	{
		if(nd->op=='=')
		{ 
			r = codegen(nd->right);
			loc = nd->left->index ;
			fprintf(fp,"MOV [%d], R%d\n",loc,r);
			freereg(r);
			return 1;
			//array[nd->left->index]=evaltree(nd->right);return 1;
		}		
		if(nd->op=='+')
		{
			r1 = codegen(nd->left);
			r2 = codegen(nd->right);
			fprintf(fp,"ADD R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->left)+evaltree(nd->right));
		}
		else if(nd->op=='-')
		{
			r1 = codegen(nd->left);
			r2 = codegen(nd->right);
			fprintf(fp,"SUB R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->left) - evaltree(nd->right));
		}
		else if(nd->op== '*')
		{
			r1 = codegen(nd->left);
			r2 = codegen(nd->right);
			fprintf(fp,"MUL R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->left) * evaltree(nd->right));
		}
		else if(nd->op=='/')
		{
			r1 = codegen(nd->left);
			r2 = codegen(nd->right);
			fprintf(fp,"DIV R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->left) / evaltree(nd->right));
		}
	}

	if(nd->flag==3)
	{ 
		r = getreg();
		fprintf(fp,"IN R%d\n",r);
		fprintf(fp,"MOV [%d], R%d\n",nd->left->index,r);
		freereg(r);
	  //array[nd->left->index]=c;
		 return 1;
	}
	if(nd->flag==4)
	{
		r = codegen(nd->left);
		fprintf(fp,"OUT R%d\n",r);
		freereg(r);
		//printf("%d\n",evaltree(nd->left));
		return 1;
	}

	if(nd->flag==6)
	{
		codegen(nd->left);
	 	codegen(nd->right);
	 	return 1;
	}

	if(nd->flag==5)
	{
				
		if(nd->op=='<')
		{
			r1 = codegen(nd->left);
			r2 = codegen(nd->right);
			fprintf(fp,"LT R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->left) < evaltree(nd->right));
		}
		else if(nd->op=='>')
		{
			r1 = codegen(nd->left);
			r2 = codegen(nd->right);
			fprintf(fp,"GT R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->left) > evaltree(nd->right));
		}
		
	}

	if(nd->flag==7)
	{
	
	  if(nd->right != NULL )
	  {
		r = codegen(nd->left);
		l1 = getlabel();
		l2 = getlabel();
		fprintf(fp,"JZ R%d, L%d\n",r,l1);
		freereg(r);
		r = codegen(nd->middle);
		fprintf(fp,"JMP L%d\n",l2);
		fprintf(fp,"L%d:\n",l1);
		r = codegen(nd->right);
		fprintf(fp,"L%d:\n",l2);
		
	  }

	  else
	  {

		r = codegen(nd->left);
		l1 = getlabel();
		//l2 = getlabel();
		fprintf(fp,"JZ R%d, L%d\n",r,l1);
		freereg(r);
		r = codegen(nd->middle);
		fprintf(fp,"L%d:\n",l1);

	  }
		/*if(evaltree(nd->right) != NULL )		
	
		if(evaltree(nd->left))
			evaltree(nd->middle) ;
		else if(evaltree(nd->right) != NULL )
			evaltree(nd->right);*/
		return 1;

	}

	if(nd->flag==8)
	{	
		l1 = getlabel();
		fprintf(fp,"L%d:\n",l1);
		r = codegen(nd->left);
		l2 = getlabel();
		fprintf(fp,"JZ R%d, L%d\n",r,l2);
		freereg(r);
		r = codegen(nd->right);
		fprintf(fp,"JMP L%d\n",l1);

		fprintf(fp,"L%d:\n",l2);
		
		/*while(evaltree(nd->left))
			evaltree(nd->right) ;*/
		return 1;

	}

	if(nd->flag==9)
	{
			r1 = codegen(nd->left);
			r2 = codegen(nd->right);
			fprintf(fp,"EQ R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
		
		//return (evaltree(nd->left) == evaltree(nd->right));
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


