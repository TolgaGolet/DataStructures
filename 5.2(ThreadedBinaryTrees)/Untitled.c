#include <stdio.h>
#include <stdlib.h>

struct n{
 int info;
 struct n * left;
 struct n * right;
};
typedef struct n node;

node * ekle(node *agac,int x)
{
	if(agac==NULL)
	{
		node * root=(node *)malloc(sizeof(node));
		root->left=NULL;
		root->right=NULL;
		root->info=x;
		return root;
	}
	if(agac->info<x)
	{
		agac->right=ekle(agac->right,x);
		return agac;
	}
	agac->left=ekle(agac->left,x);
	return agac;
}

void dolas(node *agac){
	node * iter;
	node *iter2;
	iter2=iter=agac;
	if(agac==NULL)
	return;
	
	do
	{
		agac=agac->left;
		if(agac->left==NULL)
			{
				printf("%d ",agac->info);
				if(agac->right!=NULL)
				printf("%d",agac->left);
				while(iter->left->info!=agac->info){
					iter=iter->left;
				}
				
				printf("%d ",iter->info);
				printf("%d ",iter->right->info);
			}
	}while(agac->left !=NULL);
	
	printf("%d ",iter2->info);
	iter=agac=iter2;						/////
	do
	{
		agac=agac->right;
		if(agac->right==NULL)
			{
				printf("%d ",agac->info);
				if(agac->left!=NULL)
				printf("%d",agac->left);
				while(iter->right->info!=agac->info){
					iter=iter->right;
				}
				printf("%d ",iter->info);
				printf("%d ",iter->left->info);
			}
	}while(agac->right !=NULL);
	
}

int main() 
{
	node * agac=NULL;
	agac=ekle(agac,9);
	agac=ekle(agac,7);
	agac=ekle(agac,12);
	agac=ekle(agac,3);
	agac=ekle(agac,8);
	dolas(agac);
	return 0;
}
