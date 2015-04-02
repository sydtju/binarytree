#ifndef BINARYTREE_H
#define BINARYTREE_H
typedef struct node{
	int data;
	node* leftchild;
	node* rightchild;
}node; 
void fronttra(node *root);
void middletra(node *root);
void backtra(node *root);
void layertra(node* root);
node *create_binarytree(const unsigned int count);
#endif
