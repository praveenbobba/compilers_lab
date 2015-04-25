typedef struct tnode
  {

	int val;
	int flag;
	int index;
	char op;
	struct tnode *left;
	struct tnode *middle;
	struct tnode *right;

  }node;

#define YYSTYPE node *
