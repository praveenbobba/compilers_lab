%{

  #include<stdio.h>
  #include<stdlib.h>
  #include"exptree.h"
  #include"y.tab.h"
  void yyerror(char *);

%}



%%

[0-9]+ {yylval = (node *)malloc(sizeof(node));
	yylval->flag = 0;	
	yylval->val = atoi(yytext);
	//printf("%d\n",yylval->val);
	yylval->left = NULL;
	yylval->right = NULL ;
	return DIGIT ;
	}

[-|+|/|*|=] {yylval = (node *)malloc(sizeof(node));
	yylval->flag = 1;	
	yylval->op = *yytext;
	//printf("%c\n",yylval->op);
	yylval->left = NULL;
	yylval->right = NULL ;
	return *yytext ;
	}

[a-z] {yylval = (node *)malloc(sizeof(node));
	yylval->flag = 2;	
	yylval->index = (*yytext)-('a');
	//printf("%d\n",yylval->index);
	yylval->left = NULL;
	yylval->right = NULL ;
	return ID ;
	}

"read"	{yylval = (node *)malloc(sizeof(node));
	yylval->flag = 3;
	//printf("read\n");
	return READ ;
	}

"write" {yylval = (node *)malloc(sizeof(node));
	yylval->flag = 4;
	//printf("write\n");
	return WRITE ;
	}

"if" {yylval = (node *)malloc(sizeof(node));
	yylval->flag = 7;
	//printf("write\n");
	return IF ;
	}

"then" {//yylval = (node *)malloc(sizeof(node));
	//yylval->flag = 4;
	//printf("write\n");
	return THEN ;
	}

"else" {
		return ELSE;
	}

"endif" {//yylval = (node *)malloc(sizeof(node));
	//yylval->flag = 4;
	//printf("write\n");
	return ENDIF ;
	}

"while" {yylval = (node *)malloc(sizeof(node));
	yylval->flag = 8;
	//printf("write\n");
	return WHILE ;
	}

"do" {//yylval = (node *)malloc(sizeof(node));
	//yylval->flag = 4;
	//printf("write\n");
	return DO ;
	}

"endwhile" {//yylval = (node *)malloc(sizeof(node));
	//yylval->flag = 4;
	//printf("write\n");
	return ENDWHILE ;
	}

[<|>|] {yylval = (node *)malloc(sizeof(node));
	yylval->flag = 5;	
	yylval->op = *yytext;
	//printf("%c\n",yylval->op);
	yylval->left = NULL;
	yylval->right = NULL ;
	return *yytext ;
	}

"==" {yylval = (node *)malloc(sizeof(node));
	yylval->flag = 9;	
	
	//printf("%c\n",yylval->op);
	yylval->left = NULL;
	yylval->right = NULL ;
	return EQU ;
	}

[();] 	{
		//printf("%c\n",*yytext);
		return *yytext;
	}

[\n] 	{
		//printf("newline\n");
		return *yytext;
	}

[ \t] {
		//printf("%ctabrspace\n",*yytext);
	}

. yyerror("invalid"); 	
	
%%


int yywrap(void)
{
	return 1;

}
