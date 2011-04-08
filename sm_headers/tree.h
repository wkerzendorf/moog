#include "copyright.h"
#define INC_TREE_H			/* this file has been included */
#define NAMESIZE 80			/* longest allowed node name */

typedef struct tnode {
   char name[NAMESIZE + 1];
   int weight;				/* Weight of subtree */
   struct tnode *left,			/* Subtrees */
		*right;
   struct tnode *scope_list;		/* other nodes with same name in
					   a less restrictive scope */
   Void *rest;				/* Pointer to rest of properties */
} TNODE;

typedef struct {
   TNODE *root;				/* Root of tree */
   void (*kill)();			/* Kill the `rest' of a node */
   Void *(*make)();			/* Make the `rest' of a node */
} TREE;
