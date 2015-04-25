%{

	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	int result;

%}

%token DIGIT

%left '+' '-'
%left '*' '/'
%left '^'

%%

start : expr '\n' { result = $1 ;
      			//printf("res is %d\n",result);
			//exit (1);
      		    return result;
			}
	;

expr : expr '+' expr { $$ = $1 + $3 ;  }
       | expr '-' expr { $$ = $1 - $3 ;  }
       | expr '*' expr { $$ = $1 * $3 ;  }
       | expr '/' expr { $$ = $1 / $3 ;  }
       | '(' expr ')'  { $$ = $2 ;  }
       | DIGIT		{ $$ = $1 ;  }
       | expr '^' expr { $$ = pow($1,$3);  }
       ;

%%

yyerror()
{

	printf("Error\n");

}

int main()
{

	int res = yyparse();
	printf("%d\n",res);
	return 1;

}
