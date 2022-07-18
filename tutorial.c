#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int checkTriangle(double a, double b, double c)
{
        //return (a >= b + c) || (b >= a + c) || (c >= a + b);
	// chị check điều kiện như ni được không?
	return (a + b > c) && (a + c > b) && (b + c > a);
}

double triangleArea(double a, double b, double c)
{
	if(!checkTriangle(a, b, c) || a < 0 || b < 0 || c < 0)
		return -1;
	double p = (a + b + c) / 2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

int checkPadlindrom(char *str)
{
	char *rev = malloc(strlen(str) * sizeof(char));
	strcpy(rev, str);
	strrev(rev);
	int res = !strcmp(str, rev);
	return res;
}

double arthSeq(double e)
{
	int i, sign = 1;
	double sum = 0;
	for(i = 1; 1; i++)
	{
		double elem = ((double)sign) / i;
		if(fabs(elem) <= e)
			break;
		sum += elem;
		sign = -sign;
	}
	return sum;
}

int* generate(int k, int m, int n)
{
	int *arr = calloc(k, sizeof(int));
	int i;
	for(i = 0; i < k; i++)
	{
		arr[i] = m + rand() % (n - m + 1);
	}
	return arr;
}

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
	printf("| 1 - Calculating the area of the triangle                           |\n");
	printf("| 2 - Check padlindrom                                               |\n");
	printf("| 3 - Calculating the sum of arithmetic sequence                     |\n");
	printf("| 4 - Generate an array with the values between m and n              |\n");
	printf("| 5 - Quit                                                           |\n");
	printf("+--------------------------------------------------------------------+\n");
	printf("+- Your Choice -> ");
	int choice;
	scanf("%d", &choice);
	fflush(stdin);
	return choice;
}

int main()
{
	double a, b, c;
	char str[100];
	int k, m, n, *arr;
	while(1)
	{
		int choice = menu();
		switch (choice)
		{
		case 1:
			printf("\nEnter three sides of triangle: ");
			scanf("%lf %lf %lf", &a, &b, &c);
			fflush(stdin);
			printf("\n-> The area of the triangle: %lf\n", triangleArea(a, b, c));
			break;
		case 2:
			printf("Enter the string: ");
			scanf("%[^\n]%*c", str);
			if(checkPadlindrom(str))
				printf("\n-> The string is a padlindrom.\n");
			else printf("\n-> The string is not a padlindrom.\n");
			break;
		case 3:
			printf("Enter the lower bound value: ");
			scanf("%lf%*c", &a);
			printf("\n-> Result of the arithmetic sequence: %lf\n", arthSeq(a));
			break;
		case 4:
			printf("Enter the number of elements in array: ");
			scanf("%d%*c", &k);
			printf("Enter the minimum value of array(m): ");
			scanf("%d%*c", &m);
			printf("Enter the maximum value of array(n): ");
			scanf("%d%*c", &n);
			arr = generate(k, m, n);
			printf("\n-> The generated array: ");
			for(n = 0; n < k; n++)
				printf("%d ", arr[n]);
			printf("\n");
			break;
		case 5:
			exit(0);
			break;
		}
	}
	return 0;
}
