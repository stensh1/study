// Orshak Ivan, gr. 7362, 28.10.2018

#ifndef FUNC_H
#define FUNC_H

	#define _CRT_SECURE_NO_WARNINGS

	#include <stdio.h>

		/* Debug memory allocation support */
	#ifdef _DEBUG 
	#include <crtdbg.h> 
	#define _CRTDBG_MAP_ALLOC 
	#define SetDbgMemHooks() \
		_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | \
			_CRTDBG_CHECK_ALWAYS_DF | \
			_CRTDBG_ALLOC_MEM_DF | \
			_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
	#else /* _DEBUG */ 
	# define SetDbgMemHooks() ((VOID)0) 
	#endif /* _DEBUG */ 

	typedef struct Tree Tree;
	struct Tree
	{
		int Num;
		Tree *Right;
		Tree *Left;
		Tree *Parent;
	};

	typedef struct Node Node;
	struct Node
	{
		Tree* N;
		Node *Next;
		Node *Prev;
	};

	Node* AddToList(Node *Top, int Position, Tree* Value, int *SizeOfList);
	Node* DeleteFromList(Node *Top, int Position, int *SizeOfList);
	int InfixBypass(Tree *Root);
	int PrefixBypass(Tree *Root);
	int PostfixBypass(Tree *Root);
	int BFS(Tree *Root);
	int AddElement(Tree** Root, int Num);
	int DeleteElement(Tree** Root, int Num);
	int SearchElement(Tree* Root, int Num);
	int DeleteTree(Tree *Root);

#endif /* FUNC_H */