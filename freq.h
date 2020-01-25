#ifndef _FREQ_H_
#define _FREQ_H_

#define LETTERS 26

	typedef struct Node Node;

	Node* CreateNode(char c);

	Node* insert(Node *n ,char letter);

	void incremental(Node* n);

	void cleanTrie(Node *ndRoot);

	void printTrie(Node* ndRoot, char *str, int n);

	void printTrieR(Node* ndRoot, char *str, int n);	

#endif