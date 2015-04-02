#include<iostream>
#include<cstdlib>
#include"binarytree.h"
#include<list>
#include<stack>
using namespace std;
//创建完全二叉树 数据大小按节点递减
node *create_binarytree(const unsigned int count){
	list<node*>  temp_vector;
	list<node*>::iterator  it;
	unsigned int temp_count=count;
	node * root=NULL;
	node *ltemp=NULL;
	node *rtemp=NULL;
	node *root_temp=NULL;
	if(0==count) return NULL;
	try{ 
	root=new node;
	}
	catch(bad_alloc){
		throw "memory is not enough!";
		return NULL;
	}
	root->data=temp_count--;
	root->leftchild=NULL;
	root->rightchild=NULL;
	temp_vector.push_back(root);
	while(!temp_vector.empty()){
		if(temp_count>0){
			root_temp=temp_vector.front();
			temp_vector.pop_front();
			try{
				ltemp=new node;
			}
			catch(bad_alloc){
				throw "memory is not enough!";
				return NULL;
			}
			ltemp->data=temp_count--;
			ltemp->leftchild=NULL;
			ltemp->rightchild=NULL;
			root_temp->leftchild=ltemp;
			temp_vector.push_back(ltemp);
			if(temp_count<=0) break;
			try{
				rtemp=new node;
			}
			catch(bad_alloc){
				throw "memory is not enough!";
				return NULL;
			}
			rtemp->data=temp_count--;
			rtemp->leftchild=NULL;
			rtemp->rightchild=NULL;
			root_temp->rightchild=rtemp;
			temp_vector.push_back(rtemp);
		}
		else
		{
			break;
		}
	}
	return root;
}
void fronttra(node *root){
	if (NULL!=root){
		cout<<"  "<<root->data;
		fronttra(root->leftchild);
		fronttra(root->rightchild);
	}
	else
		return ;
}
void middletra(node *root){
	if (NULL!=root){
		middletra(root->leftchild);
		cout<<" "<<root->data;
		middletra(root->rightchild);
	}
	else
		return ;
}
void backtra(node *root){
	if (NULL!=root){
		backtra(root->leftchild);
		backtra(root->rightchild);
		cout<<" "<<root->data;
	}
	else
		return ;
}
void layertra(node* root){
	list<node*> temp_s;
	node*temp=NULL;
	temp_s.push_back(root);
	while(!temp_s.empty()){
		temp=temp_s.front();
		temp_s.pop_front();
		cout<<" "<<temp->data;
		if(NULL!=temp->leftchild) temp_s.push_back(temp->leftchild);
		if(NULL!=temp->rightchild) temp_s.push_back(temp->rightchild);
	}
}
