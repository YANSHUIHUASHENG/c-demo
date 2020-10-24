//#include"main.hpp"


//int main()
//{
//
//    class_fun();
//    printf("helloworld--你好世界\n\n");
//    return 0;
//}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//如何测试你的系统是大端还是小端模式
int CheckSystem()
{
    int a = 1;
    if(*((char *)(&a))==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void test()
{
    printf("this is test...");
}

void test2()
{
    printf("this is test...");
}

void test3()
{
    printf("this is test...");
}

int main ()
{
    char num= 0xf1;

    printf("123456 %s",num);
    printf("git add new...");
    printf("add test fun");

    return 0;
}



