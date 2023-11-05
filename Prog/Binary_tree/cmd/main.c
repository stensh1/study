// Orshak Ivan, gr. 7362, 28.10.2018

#include "func.h"
#include <conio.h>
#include <Windows.h>

void Menu()
{
	printf("________________________________________________________\n"
		   "|1. Add element   2. Delete element   3. Search element|\n"
		   "|4. Infix bypass   5. Prefix bypass   6. Postfix bypass|\n"
		   "|           7. Breadth-first bypass   0. Exit          |\n"
		   "|______________________________________________________|\n");

	return;
}

int Handler(int Handle, Tree** Root)
{
	int(*Action[2])(Tree** Root, int Num) = { AddElement, DeleteElement };
	int(*Bypass[4])(Tree *Root) = { InfixBypass, PrefixBypass, PostfixBypass, BFS };
	int Buff;

	switch (Handle)
	{
	case 1:
	case 2:
		printf("Enter the number:");
		scanf("%d", &Buff);
		Action[Handle - 1](Root, Buff);
		break;
	case 3:
		printf("Enter the number:");
		scanf("%d", &Buff);
		printf("%d elements <%d> found", SearchElement(*Root, Buff), Buff);
		break;
	case 4:
	case 5:
	case 6:
	case 7:
		Bypass[Handle - 4](*Root);
		break;
	case 0:
		DeleteTree(*Root);
		exit(0);
	default:
		printf("Undefined instruction!\n");
	}

	return 0;
}

int main()
{
	int Handle;
	Tree *Root = NULL;

	SetDbgMemHooks();
	
	while (1)
	{
		Menu();

		scanf("%d", &Handle);
		Handler(Handle, &Root);

		_getch();
		system("cls");
	}

	return 0;
}
