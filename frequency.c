#include <stdio.h>
#include <stdlib.h>
#include "freq.h"
#define Zero 0

#define NUM_LETTERS 26

typedef struct Node{
	char letter;
	long unsigned int count;
	struct Node* children[NUM_LETTERS];
	char vec[NUM_LETTERS];
	}Node;

// Constructor
Node* CreateNode(char c)
{
	Node *nd = (Node*)malloc(sizeof(Node));
	nd->letter=c;
	nd->count=Zero;
	for (int i=Zero; i<NUM_LETTERS; i++)
		nd->vec[i] = Zero;
	return nd;
}

// creates node and add to trie
Node* insert(Node *node, char letter)
{
	if(node->vec[letter-'a'] == Zero)
	{
			Node *new_nd = CreateNode(letter);
			node->vec[letter-'a'] = 1;
			node->children[letter-'a'] = new_nd;
			return new_nd;
	}
	return (node->children[letter-'a']);
}

// if end of word increment the counter
void incremental(Node* n) {n->count++;}

// return 1 node no Childrens else return 0
int noChildrens(Node* n)
{
	for (int i=Zero; i<NUM_LETTERS; i++)
	{
		if (n->vec[i]==1)
		    return Zero;
	}
	return 1;
}

// free all the allocated nodes in the tree
void cleanTrie(Node* ndRoot)
{
	if (ndRoot==NULL) 
	    return;
	
	if (noChildrens(ndRoot))
	{ 
		free(ndRoot);
		return;
	}
	else
	{
		for (int i=Zero; i<NUM_LETTERS; i++)
		{
			if (ndRoot->vec[i]==1)
				cleanTrie(ndRoot->children[i]);
		}
		free(ndRoot);
	}
}

// normal print
void printTrie(Node* ndRoot, char *str, int n)
{
	if (noChildrens(ndRoot))
	{
		str[n] = '\0';
		printf("%s\t%ld\n", str, ndRoot->count);
		return;
	}
	if (ndRoot->count > Zero)
	{
		str[n] = '\0';
		printf("%s\t%ld\n", str, ndRoot->count);
	}
	for (int i=Zero; i<NUM_LETTERS; i++)
	{
		if (ndRoot->vec[i]==1)
		{
			str[n] = ndRoot->children[i]->letter;
			printTrie(ndRoot->children[i], str, n+1);
		}
	}
}

// reverse print
void printTrieR(Node* ndRoot, char *str, int n)
{
	if (noChildrens(ndRoot))
	{
		str[n] = '\0';
		printf("%s\t%ld\n", str, ndRoot->count);
		return;
	}
	if (ndRoot->count > Zero)
	{
		str[n] = '\0';
		printf("%s\t%ld\n", str, ndRoot->count);
	}
	for (int i=NUM_LETTERS-1; i>=Zero; i--)
	{
		if (ndRoot->vec[i]==1)
		{
			str[n] = ndRoot->children[i]->letter;
			printTrieR(ndRoot->children[i], str, n+1);
		}
	}
}
    

