#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
struct Node *CreateNode(char k) 
{ 
    struct Node *node = (struct Node*)malloc(sizeof(struct Node)); 
    node->key = k; 
    node->right = node->left = NULL; 
    return node; 
} 
int Full (struct Node* root) 
{ 
    if (root == NULL) 
        return 1; 
    if (root->left == NULL && root->right == NULL) 
        return 1; 
    if ((root->left) && (root->right)) 
        return (Full(root->left) && Full(root->right));
    return 0; 
}
int CountNodes(struct Node* root) 
{ 
    if (root == NULL) 
        return 0; 
    return (1 + CountNodes(root->left) + CountNodes(root->right)); 
} 
int Complete (struct Node* root, int index, int count) 
{ 
    if (root == NULL) 
        return 1; 
    if (index >= count) 
        return 0; 
    return (Complete(root->left, 2*index + 1, count) && Complete(root->right, 2*index + 2, count)); 
}
void pre_order_traversal(struct Node* root)
{
	if(root != NULL)
	{
		printf("%c ",root->key);
		pre_order_traversal(root->left);
		pre_order_traversal(root->right);
	}
}
void inorder_traversal(struct Node* root)
{
	if(root != NULL)
	{
		inorder_traversal(root->left);
		printf("%c ",root->key);          
		inorder_traversal(root->right);
   	}
}
void post_order_traversal(struct Node* root)
{
	if(root != NULL)
	{
		post_order_traversal(root->left);
		post_order_traversal(root->right);
		printf("%c ", root->key);
   	}
}
int height(struct Node* node) 
{ 
    if (node==NULL) 
        return 0; 
    else
    { 
        int lheight = height(node->left); 
        int rheight = height(node->right); 
        if (lheight > rheight) 
            return(lheight+1); 
        else return(rheight+1); 
    } 
} 
void printGivenLevel(struct Node* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%c ", root->key); 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
}
void printLevelOrder(struct Node* root) 
{ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
}
 
int main() 
{ 
	struct Node* root = NULL; 
	root = CreateNode('A'); 
	root->left = CreateNode('B'); 
	root->right = CreateNode('C');  
	root->left->left = CreateNode('D');
	root->left->right = CreateNode('E');   
	root->right->right = CreateNode('F');  
	root->left->right->left = CreateNode('G'); 
	root->left->right->right = CreateNode('H');   
	if (Full(root)) 
		printf("The Binary Tree is full\n"); 
	else
		printf("The Binary Tree is not full\n"); 
	int count = CountNodes(root); 
	int index = 0;  
	if (Complete(root, index, count))
		printf("The Binary Tree is complete\n"); 
	else
		printf("The Binary Tree is not complete\n"); 
	printf("\nPreorder traversal: ");
	pre_order_traversal(root);
	printf("\nInorder traversal: ");
	inorder_traversal(root);
	printf("\nPost order traversal: ");
	post_order_traversal(root); 
	printf("\nLevel Order traversal: "); 
	printLevelOrder(root); 
	printf("\n");
	return 0; 
} 
