#include<stdio.h>
void TOH(int n, char s,char d,char a)
{
	if(n==1)
	printf(" move disc from %c to %c \n",s,d);
	else
	{
		TOH(n-1,s,a,d);
		TOH(1,s,d,a);
		TOH(n-1,a,d,s);
	}
}
int main()
{
	int n;
	printf("enter number of discs\n");
	scanf("%d",&n);
	TOH(n,'A','B','C');
	return 0;
}
