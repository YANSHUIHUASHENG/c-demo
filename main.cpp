//#include"main.hpp"


//int main()
//{
//
//    class_fun();
//    printf("helloworld--�������\n\n");
//    return 0;
//}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//��β������ϵͳ�Ǵ�˻���С��ģʽ
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



