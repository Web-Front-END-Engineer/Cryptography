#include <stdio.h>
#include <string.h>

void Caesar(char *m, char *c, int k, int n);

int main()
{
    char m[100];
    char c[100];
    int i, j, k, n, t;

    printf("********************************************\n");
    printf("** 加密方案为凯撒加密的变形: 多表替代加密 **\n");
    printf("** 原理分析请参考小甲鱼 《密码学》 第二讲 **\n");
    printf("********************************************\n");
    printf("***** Power by www.fishc.com -- 小甲鱼 *****\n");
    printf("********************************************\n");

    printf("请输入明文：");
    gets(m);
    printf("\n请问需要多少个字符为一组: ");
    scanf("%d", &i);
    printf("\n");

    n = strlen(m);
    t = n%i;         // 考虑是否有余数，有余数就是要加多一组哦
    n /= i;          // n 这里得到划分为多少组

    j = 1;
    while( j <= n )
    {
        printf("第%2d组移动字符数：", j);
        scanf("%d", &k);
        Caesar( &m[(j-1)*i], c, k, i );
        j++;
    }

    if( t )
    {
        printf("第%2d组移动字符数：", j);
        scanf("%d", &k);
        Caesar( &m[(j-2)*i+t], c, k, i );
    }

    c[n*i+t] = '\0';
    printf("\n加密后的密文是：%s", c);

    getch();

    return 0;
}

void Caesar(char *m, char *c, int k, int n)
{
	int i;
    static int j = 0;

	for(i=0; i < n; i++,j++)
    {
        if( m[i] >= 'A' && m[i] <= 'Z' )
            c[j] = (m[i]+k-'A')%26 + 'A';
        else if( m[i] >= 'a' && m[i] <= 'z' )
            c[j] = (m[i]+k-'a')%26 + 'a';
        else
            c[j] = m[i];
    }
}
