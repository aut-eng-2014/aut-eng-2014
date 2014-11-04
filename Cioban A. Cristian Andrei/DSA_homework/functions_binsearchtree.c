#include "functions_binsearchtree.h"

nodeT* FindMin(nodeT *node)
{
	if (node == NULL)
	{
		/* There is no element in the tree */
		return NULL;
	}
	if (node->left) /* Go to the left sub tree to find the min element */
		return FindMin(node->left);
	else
		return node;
}

nodeT* FindMax(nodeT *node)
{
	if (node == NULL)
	{
		/* There is no element in the tree */
		return NULL;
	}
	if (node->right) /* Go to the left sub tree to find the min element */
		FindMax(node->right);
	else
		return node;
}


nodeT * Insert(nodeT *node, int data)
{
	if (node == NULL)
	{
		nodeT *temp = (nodeT *)malloc(sizeof(nodeT));
		temp->data = data;
		temp->left = temp->right = NULL;
		return temp;
	}

	if (data >(node->data))
	{
		node->right = Insert(node->right, data);
	}
	else if (data < (node->data))
	{
		node->left = Insert(node->left, data);
	}
	/* Else there is nothing to do as the data is already in the tree. */
	return node;

}

nodeT * Delete(nodeT *node, int data)
{
	nodeT *temp;
	if (node == NULL)
	{
		printf("Element Not Found");
	}
	else if (data < node->data)
	{
		node->left = Delete(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = Delete(node->right, data);
	}
	else
	{
		/* Now We can delete this node and replace with either minimum element
		in the right sub tree or maximum element in the left subtree */
		if (node->right && node->left)
		{
			/* Here we will replace with minimum element in the right sub tree */
			temp = FindMin(node->right);
			node->data = temp->data;
			/* As we replaced it with some other node, we have to delete that node */
			node->right = Delete(node->right, temp->data);
		}
		else
		{
			/* If there is only one or zero children then we can directly
			remove it from the tree and connect its parent to its child */
			temp = node;
			if (node->left == NULL)
				node = node->right;
			else if (node->right == NULL)
				node = node->left;
			free(temp); /* temp is longer required */
		}
	}
	return node;

}

nodeT * Find(nodeT *node, int data)
{
	if (node == NULL)
	{
		/* Element is not found */
		return NULL;
	}
	if (data > node->data)
	{
		/* Search in the right sub tree. */
		return Find(node->right, data);
	}
	else if (data < node->data)
	{
		/* Search in the left sub tree. */
		return Find(node->left, data);
	}
	else
	{
		/* Element Found */
		return node;
	}
}

void Preorder(nodeT *p, int level)
{


	int i;
	if (p != NULL)
	{
		for (i = 0; i <= level; i++)
			printf(" "); /* for nice listing */
		printf("%d\n", p->data);
		Preorder(p->left, level + 1);
		Preorder(p->right, level + 1);
	}

}

void Inorder(nodeT *p, int level)
{

	int i;
	if (p != NULL)
	{
		Inorder(p->left, level + 1);
		for (i = 0; i <= level; i++)
			printf(" "); /* for nice listing */
		printf("%d\n", p->data);
		Inorder(p->right, level + 1);
	}

}

void Postorder(nodeT *p, int level)
{

	int i;
	if (p != NULL)
	{
		Postorder(p->left, level + 1);
		Postorder(p->right, level + 1);
		for (i = 0; i <= level; i++)
			printf(" "); /* for nice listing */
		printf("%d\n", p->data);
	}

}


