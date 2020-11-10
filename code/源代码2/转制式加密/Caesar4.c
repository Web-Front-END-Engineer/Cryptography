#include <stdio.h>
#include <string.h>

int main()
{
    char m[100];
    char c[100];
    int i, j, k, n, t, p;

    printf("********************************************\n");
    printf("** 该加密方案为凯撒加密的变形: 转制式加密 **\n");
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
    t = n%i;         // 考虑是否有余数
    n /= i;          // n 这里得到划分为多少组


    for( j=0; j < i; j++ )
    {
        printf("第%2d个字符转变为第几个字符: ", j+1);
        scanf("%d", &k);

        p = 0;
        while( p < n )
        {
            c[p*i+k-1] = m[p*i+j];
            p++;
        }
    }

    c[n*i+t] = '\0';

    while( t )
    {
        c[n*i+t-1] = m[n*i+t-1];
        t--;
    }

    printf("\n加密后的密文是：%s", c);

    getch();

    return 0;
}
