typedef struct tnode
  {

	int val;
	int flag;
	char op;
	struct tnode *left;
	struct tnode *right;

  }node;

#define YYSTYPE node *
