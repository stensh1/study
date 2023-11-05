// Orshak Ivan, gr. 7362, 28.10.2018

#include "func.h"
#include <stdlib.h>

Node* AddToList(Node *Top, int Position, Tree* Value, int *SizeOfList)
{
	Node *p = NULL;
	Node *Tmp = Top;
	int i = 0;

	if (Position < 0 || Position > *SizeOfList)
	{
		printf("False position!\n");
		return Top;
	}

	if (Tmp == NULL)
	{
		if ((Top = (Node*)malloc(sizeof(Node))) == NULL)
		{
			printf("Error allocation!\n");
			return Top;
		}
		Top->Next = Top->Prev = NULL;
		Top->N = Value;
		(*SizeOfList)++;
		return Top;
	}
	else
	{
		if ((p = (Node*)malloc(sizeof(Node))) == NULL)
		{
			printf("Error allocation!\n");
			return Top;
		}
		p->N = Value;
		p->Next = p->Prev = NULL;

		if (Position == 0)
		{
			Top->Prev = p;
			p->Next = Top;
			Top = p;
		}

		if (Position == *SizeOfList)
		{
			while (Tmp->Next != NULL)
				Tmp = Tmp->Next;

			p->Prev = Tmp;
			Tmp->Next = p;
		}
		else
		{
			while (i++ < Position)
				Tmp = Tmp->Next;

			Tmp->Prev->Next = p;
			p->Next = Tmp;
			p->Prev = Tmp->Prev;
			Tmp->Prev = p;
		}

		(*SizeOfList)++;
	}

	return Top;
}

Node* DeleteFromList(Node *Top, int Position, int *SizeOfList)
{
	int i = 0;
	Node *Tmp = Top, *p;

	if (Position < 0 || Position >= *SizeOfList)
	{
		printf("False position!\n");
		return Top;
	}

	if (*SizeOfList == 1)
	{
		free(Top);
		Top = NULL;
		(*SizeOfList)--;
		return Top;
	}

	if (Position == 0)
	{
		Tmp = Tmp->Next;
		Tmp->Prev = NULL;
		free(Top);
		Top = Tmp;
		(*SizeOfList)--;
		return Top;
	}

	if (Position == *SizeOfList - 1)
	{
		while (Tmp->Next != NULL)
			Tmp = Tmp->Next;

		p = Tmp;
		Tmp = Tmp->Prev;
		Tmp->Next = NULL;
		(*SizeOfList)--;
		free(p);
		return Top;
	}

	while (i++ < Position)
		Tmp = Tmp->Next;

	Tmp->Prev->Next = Tmp->Next;
	Tmp->Next->Prev = Tmp->Prev;

	free(Tmp);
	(*SizeOfList)--;

	return Top;
}

int InfixBypass(Tree *Root)
{
	if (Root != NULL) 
	{
		InfixBypass(Root->Left);
		printf("%d ", Root->Num);
		InfixBypass(Root->Right);
	}

	return 0;
}

int PrefixBypass(Tree *Root)
{
	if (Root != NULL)
	{
		printf("%d ", Root->Num);
		InfixBypass(Root->Left);
		InfixBypass(Root->Right);
	}

	return 0;
}

int PostfixBypass(Tree *Root)
{
	if (Root != NULL)
	{
		InfixBypass(Root->Left);
		InfixBypass(Root->Right);
		printf("%d ", Root->Num);
	}

	return 0;
}

int BFS(Tree *Root)
{
	int SizeOfList = 0;
	int Position = 0;
	Node *Top = NULL;

	Top = AddToList(Top, Position++, Root, &SizeOfList);

	while (Top != NULL)
	{
		printf("%d ", Top->N->Num);

		if (Top->N->Left != NULL)
			Top = AddToList(Top, Position++, Top->N->Left, &SizeOfList);
		if (Top->N->Right != NULL)
			Top = AddToList(Top, Position++, Top->N->Right, &SizeOfList);

		Top = DeleteFromList(Top, 0, &SizeOfList);
		Position--;
	}

	return 0;
}

int AddElement(Tree** Root, int Num)
{
	Tree *p = NULL;
	Tree *tmp = *Root;

	if (*Root == NULL)
	{
		if ((*Root = (Tree*)malloc(sizeof(Tree))) == NULL)
		{
			printf("Error allocation!\n");
				return 0;
		}
		(*Root)->Left = (*Root)->Right = (*Root)->Parent = NULL;
		(*Root)->Num = Num;
	}
	else
	{
		if ((p = (Tree*)malloc(sizeof(Tree))) == NULL)
		{
			printf("Error allocation!\n");
			return 0;
		}
		p->Left = p->Right = NULL;
		p->Num = Num;

		while (tmp != NULL)
		{
			if (Num > tmp->Num) 
				if (tmp->Left != NULL)
					tmp = tmp->Left;
				else
				{
					tmp->Left = p;
					p->Parent = tmp;
					return 0;
				}
			else if (Num <= tmp->Num) 
				if (tmp->Right != NULL)
					tmp = tmp->Right;
				else
				{
					tmp->Right = p;
					p->Parent = tmp;
					return 0;
				}
		}
	}

	return 0;
}

int DeleteElement(Tree** Root, int Num)
{
	Tree *tmp = *Root, *tmp1, *tmp2, *tmp3;

	if (tmp != NULL)
	{
		while (1)
		{
			if (tmp->Num == Num)
				break;
			else if (tmp->Num > Num)
				tmp = tmp->Right;
			else
				tmp = tmp->Left;
		}

		if (tmp->Left == NULL)
		{
			tmp1 = tmp;
			tmp = tmp->Right;
			tmp->Parent = tmp1->Parent;

			if (tmp1->Parent->Right == tmp1)
				tmp1->Parent->Right = tmp;
			else
				tmp->Parent->Left = tmp;

			free(tmp1);
			
		}
		else
		{
			tmp1 = tmp->Left;

			if (tmp1->Right == NULL)
			{
				tmp1->Right = tmp->Right;
				tmp1->Parent = tmp->Parent;

				if (tmp->Parent->Right == tmp)
					tmp->Parent->Right = tmp1;
				else
					tmp->Parent->Left = tmp1;

				free(tmp);
			}
			else
			{
				tmp1 = tmp;
				tmp2 = tmp->Left;
				tmp3 = tmp2->Right;

				while (tmp3 != NULL)
				{
					tmp1 = tmp2;
					tmp2 = tmp3;
					tmp3 = tmp2->Right;
				}

				if (tmp1 != tmp)
				{
					tmp1->Right = tmp2->Left;
					tmp2->Left = tmp->Left;
					tmp2->Right = tmp->Right;
				}

				if (tmp->Parent == NULL)
					(*Root) = tmp2;
				else if (tmp == tmp->Parent->Right)
					tmp->Parent->Right = tmp2;
				else
					tmp->Parent->Left = tmp2;

				free(tmp);
			}
		}
	}

	return 0;
}

int SearchElement(Tree* Root, int Num)
{
	int cnt = 0;

	if (Root != NULL)
	{
		if (Root->Num == Num)
			cnt++;
		cnt += SearchElement(Root->Left, Num);
		cnt += SearchElement(Root->Right, Num);
	}

	return cnt;
}

int DeleteTree(Tree *Root)
{
	if (Root != NULL)
	{
		DeleteTree(Root->Left);
		DeleteTree(Root->Right);
		free(Root);
	}

	return 0;
}