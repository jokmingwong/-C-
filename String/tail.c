#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 256
int main(int argc, char *argv[])
{
    unsigned int line;
    char *filename;
    if (argc == 2)
    {
        line = 10;
        filename = argv[1];
    }
    else if (argc == 3)
    {
        filename = argv[2];
        //arg[0][1] is "-" notation;
        int len = strlen(argv[1]);
        //Transform string to int
        int i;
        line = 0;
        for (i = len - 1; i >= 1; i--)
        {
            //exclude the first one
            line += (argv[1][i] - '0') * pow(10, len - i - 1);
        }
    }
    FILE *f = fopen(filename, "r");
    fseek(f, -1, SEEK_END); // SEEK_END位置是一个无效的位置，对于文件而言，SEEK_END的前一个位置是文件中最后的那个数据的位置
    unsigned int num = 0;
    while (1)
    {
        if (fgetc(f) == '\n')
            ++num;
        if (num > line)
            break;
        if (fseek(f, -2, SEEK_CUR) != 0) // 当读取好一个字符串后，文件的指针会移动到下一个位置上，所以要倒序读取，此时文件的指针需要向前移动2个字节
        {
            fseek(f, 0, SEEK_SET); // 如果fseek返回值不是零，说明已经到达的文件的头部，该文件需要从头全部输出
            break;
        }
    }

    char buffer[BUFSIZE];
    while (fgets(buffer, BUFSIZE, f)) // 此处没有用feof判断，因为用feof判断会导致最后一行输出两次，feof是在文件指针失效后，还要读取一次才判断为真
    {
        printf("%s", buffer);
    }
    fclose(f);
    return 0;
}