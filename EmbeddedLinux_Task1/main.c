#include <stdio.h>
#include <stdlib.h>
#include "HeaderFiles/addition.h"
#include "HeaderFiles/division.h"
#include "HeaderFiles/multiplication.h"
#include "HeaderFiles/subtraction.h"
#include "HeaderFiles/modulus.h"

int main (void)
{
	float n1,n2,result;
	char op;
	printf("Please enter the operation: ");
	scanf("%c",&op);
	printf("Please enter two numbers: ");
	scanf("%f%f",&n1,&n2);
	switch (op)
	{
		case '+':
			result=sum(n1,n2);
			break;
		case '-':
			result=sub(n1,n2);
			break;
		case '*':
			result=mult(n1,n2);
			break;
		case '/':
			result=divide(n1,n2);
			break;
		case '%':
			result=(float)modulus(n1,n2);
			break;
		default:
			break;
	}
	printf("The result = %.3lf\n",result);

	return 0;
}
