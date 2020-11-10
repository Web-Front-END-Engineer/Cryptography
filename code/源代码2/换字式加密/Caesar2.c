// Powered by 鱼C工作室www.fishc.com -- 小甲鱼

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f1, *f2, *f3;
    char key[52];
    char ch;
    int i;

    printf("********************************************\n");
    printf("** 该加密方案为凯撒加密的变形: 换字式加密 **\n");
    printf("** 原理分析请参考小甲鱼 《密码学》 第二讲 **\n");
    printf("********************************************\n");
    printf("***** Power by www.fishc.com -- 小甲鱼 *****\n");
    printf("********************************************\n");

    // 获取密匙
    if((f1=fopen("key.txt", "r")) == NULL)
    {
        printf("打开key.txt文件的时候发生错误！\n");
        getch();
        exit(1);
    }

    // 将密匙存进key数组
    for( i=0; i < 52; i++ )
    {
        key[i] = fgetc(f1);
    }

    // 打开待加密的明文
    if((f2=fopen("plain.txt", "r")) == NULL)
    {
        printf("打开plain.txt文件的时候发生错误！\n");
        getch();
        exit(1);
    }

    // 打开存放密文的文件
    if((f3=fopen("cipher.txt", "wt+")) == NULL)
    {
        printf("打开cipher.txt文件的时候发生错误！\n");
        getch();
        exit(1);
    }

    // 根据密匙加密并存放到cipher.txt文件中
    ch = fgetc(f2);
    while( ch != EOF )
    {
        // 大写字母转换为key的前26位索引，小写字母后26位
        if( ch>='A' && ch<='Z')
        {
            ch -= 65;
            ch = key[ch];
        }
        else if( ch>='a' && ch<= 'z' )
        {
            ch -= 71;  // ch = ch - 97 + 26
            ch = key[ch];
        }

        fputc(ch, f3);
        ch = fgetc(f2);
    }

    printf("\n成功加密, 加密后的内容存放在cipher.txt文件中。\n\n");
    printf("输入c浏览文件，其他输入自动退出程序: ");

    if( 'c' == getchar() )
    {
        printf("\n密文如下：\n");

        // 记得要用fseek函数来设置文件指针指向文件头
        fseek(f3, 0, SEEK_SET);
        ch = fgetc(f3);

        while( ch != EOF )
        {
            putchar(ch);
            ch = fgetc(f3);
        }
    }

    getch();

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
}
