#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int menu()
{
	static char bFlag = 0;
	if(bFlag)
		system("pause > nul");
	else
		bFlag = 1;
	system("cls");
	printf("+--------------------------------------------------------------------+\n");
	printf("| MENU for Practicle Exam  Name: Tran Viet Dang Quang - ID: DE170014 |\n");
	printf("+--------------------------------------------------------------------+\n");
	printf("| 1 -                                                                |\n");
	printf("| 2 -                                                                |\n");
	printf("| 3 -                                                                |\n");
	printf("| 4 -                                                                |\n");
	printf("| 5 - Quit                                                           |\n");
	printf("+--------------------------------------------------------------------+\n");
	printf("+- Your Choice -> ");
	int choice;
	scanf("%d", &choice);
	return choice;
}

int main()
{
	while(1)
	{
		int choice = menu();
		switch (choice)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			exit(0);
			break;
		}
	}
	return 0;
}
