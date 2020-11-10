// Powered by 鱼C工作室www.fishc.com -- 小甲鱼

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f1;
    int num = 0;       // 存放统计后的字符总数,不包括标点符号
    int i, j;
    char ch;
    int letter[26];     // 统计密文各字母频数。为了方便理解，这里假设密文全为大写哦^_^
    char top_char[26];
    int top_num[26];

    printf("********************************************\n");
    printf("** 利用字母频数破译换字式加密。。。。。。 **\n");
    printf("** 原理分析请参考小甲鱼 《密码学》 第二讲 **\n");
    printf("********************************************\n");
    printf("***** Power by www.fishc.com -- 小甲鱼 *****\n");
    printf("********************************************\n");

    // 打开密文
    if((f1=fopen("cipher.txt", "r")) == NULL)
    {
        printf("打开cipher.txt文件的时候发生错误！\n");
        getch();
        exit(1);
    }

    // 初始化字符数组
    for( i=0; i < 26; i++ )
    {
        letter[i] = 0;
        top_num[i] = 0;
    }

    // 统计字符数和各个字符出现频数
    while( (ch=fgetc(f1)) != EOF )
    {
        if( ch >= 'A' && ch <= 'Z' )
        {
            letter[ch-65]++;      // 统计各个字符频数
            num++;
        }
    }

    printf("\n不包含标点符号，总字符数为: %d\n", num);

    printf("\n各个字符出现的频数: \n");
    for( i=0; i < 26; i++ )
    {
        printf("%c: %d\n", i+65, letter[i]);
    }

    getch();

    fclose(f1);

    return 0;
}
