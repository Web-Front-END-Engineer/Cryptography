#include <stdio.h>

int main()
{
	char m[100];
	char c[100];
	int i, k;

	printf("请输入明文：");
	gets(m);
	printf("请输入移动位数：");
    scanf("%d", &k);

	for(i=0; m[i] != '\0'; i++)
    {
        if( m[i] >= 'A' && m[i] <= 'Z' )
            c[i] = (m[i]+k-'A')%26 + 'A';
        else if( m[i] >= 'a' && m[i] <= 'z' )
            c[i] = (m[i]+k-'a')%26 + 'a';
        else
            c[i] = m[i];
    }

	c[i] = '\0';

	printf("密文是：%s\n", c);
	getch();
}
