%{

	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	int result;
	typedef char *YYSTYPE ;

%}

%token SYMBOL

%left '+' '-'
%left '*' '/'
%left '^'

%%

start : expr '\n' { //result = $1 ;
      			//printf("res is %d\n",result);
			exit (1);
      		    //return result;
			}
	;

expr : expr '+' expr { printf("+");  }
       | expr '-' expr { printf("-");  }
       | expr '*' expr { printf("*");  }
       | expr '/' expr { printf("/");  }
       | '(' expr ')'  {   }
       | SYMBOL		{ 
				printf("%s",$1);				
			  }
       | expr '^' expr { printf("^");  }
       ;

%%

yyerror()
{

	printf("Error\n");

}

int main()
{

	yyparse();
	//printf("%d\n",res);
	return 1;

}
