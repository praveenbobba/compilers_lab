typedef struct tnode
  {

	int val;
	int flag;
	int index;
	char op;
	struct tnode *left;
	struct tnode *right;
	struct tnode *middle;

  }node;

#define YYSTYPE node *
