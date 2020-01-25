#include <stdio.h> 
#include <ctype.h>
#include "freq.h"
#define Zero 0


int main(int argc, char const *argv[])
{
	Node *rootNode= CreateNode('\0');
	Node *tempNode = rootNode;
	char buff; // the input buffer
	char tempBuff;
	int wordLength=Zero; 
	int bigWord=Zero; //  longest word length
	char function = 'r'; // t for normal print , r for reverse print.

	// read input and insert to trie
	while ((buff=getc(stdin)) != EOF )
	{
	    tempBuff=buff;
		if ((buff <= 'z' && buff >= 'a') || (buff <= 'Z' && buff >= 'A'))
		{	
			tempNode = insert(tempNode, tolower(buff));
			wordLength++;
		}
		else if (buff == '\t' || buff == '\n' || buff == ' ')
		{
			incremental(tempNode); // increment end of word
			tempNode = rootNode;
			if (wordLength > bigWord)
			{
			    bigWord = wordLength; //save longest word length
			    wordLength=Zero;
			}
		}
		

	}
	// in case the text didnt finish with /n
	if(tempBuff=='.'){
	    buff='\n';
	    incremental(tempNode);
	    tempNode=rootNode;
	}
	
	char vec[bigWord+2]; // init an array of chars with the longest word length

	if(argc>1)// choose how to run
	    function=*argv[1];  
	    
	if(function == 't')
	    printTrie(rootNode, vec, Zero); // normal print
	else
	    printTrieR(rootNode, vec, Zero);  // reverse print

	cleanTrie(rootNode); // free allocated memory, leafs to root 

	return Zero;
}