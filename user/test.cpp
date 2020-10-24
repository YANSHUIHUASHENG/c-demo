#include"test.hpp"
#include"time.h"



void user_fun(void)
{
    int ptr=12345;
    int date[10]={1,3,5,7,9,11,13,15,17,19};
    int *p,*p1;

    cout << "ptr  数据：" << ptr << endl;
    cout << "ptr  地址：" << &ptr << endl<< endl;
    cout << "date 数据：" << date << endl;
    cout << "date 地址：" << &date << endl<< endl;
    p = &ptr;
    cout << "p    数据：" << *p << endl;
    cout << "p    地址：" << p << endl<< endl;
}

void user_fun1(void)
{
    int par;
    int date[10]={1,3,5,7,9,11,13,15,17,19};
    test1_fun(date,10);
}


void test1_fun(int *p,int size1)
{
    int *p1;
    p1 = p;
    for(int i=0;i<size1;i++)
    {
        cout << i << " :p1  数据："  << *p1 << endl;
        cout << i << " :p1  地址："  << p1 << endl<< endl;
        p1++;
    }
}


void time0_fun()
{
   // 基于当前系统的当前日期/时间
   time_t now = time(0);

   // 把 now 转换为字符串形式
   char* dt = ctime(&now);

   cout << "本地日期和时间：" << dt << endl;

   // 把 now 转换为 tm 结构
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "UTC 日期和时间："<< dt << endl;
}

void time1_fun()
{
   // 基于当前系统的当前日期/时间
   time_t now = time(0);

   cout << "1970 到目前经过秒数:" << now << endl;

   tm *ltm = localtime(&now);

   // 输出 tm 结构的各个组成部分
   cout << "年: "<< 1900 + ltm->tm_year << endl;
   cout << "月: "<< 1 + ltm->tm_mon<< endl;
   cout << "日: "<<  ltm->tm_mday << endl;
   cout << "时间: "<< ltm->tm_hour << ":";
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}

void time_fun()
{
  time_t seconds;

  //seconds = time(NULL);
  time(&seconds);
  printf("自 1970-01-01 起的小时数 = %ld\n", seconds/3600);

}

void ctime_fun()
{
   time_t curtime;

   time(&curtime);

   printf("当前时间 = %s", ctime(&curtime));

}

void localtime_fun()
{
   time_t rawtime;
   struct tm *info;

   time( &rawtime );

   info = localtime( &rawtime );
   printf("当前的本地时间和日期：%s", asctime(info));
}


void clock_fun()
{
   clock_t start_t, end_t;
   double total_t;
   int i;

   start_t = clock();
   printf("程序启动，start_t = %ld\n", start_t);

   printf("开始一个大循环，start_t = %ld\n", start_t);
   for(i=0; i< 10000000; i++)
   {
   }
   end_t = clock();
   printf("大循环结束，end_t = %ld\n", end_t);

   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("CPU 占用的总时间：%f\n", total_t  );
   printf("程序退出...\n");
}


void asctime()
{
   struct tm t;

   t.tm_sec    = 10;
   t.tm_min    = 10;
   t.tm_hour   = 6;
   t.tm_mday   = 25;
   t.tm_mon    = 2;
   t.tm_year   = 89;
   t.tm_wday   = 6;

   puts(asctime(&t));

}


#define BST (+1)
#define CCT (+8)
void gmtime()
{

   time_t rawtime;
   struct tm *info;

   time(&rawtime);
   /* 获取 GMT 时间 */
   info = gmtime(&rawtime );

   printf("当前的世界时钟：\n");
   printf("伦敦：%2d:%02d\n", (info->tm_hour+BST)%24, info->tm_min);
   printf("中国：%2d:%02d\n", (info->tm_hour+CCT)%24, info->tm_min);

}


void mktime_fun()
{
    time_t rawtime;
    struct tm * timeinfo;
    int year, month ,day;
    const char * weekday[] = { "周日", "周一","周二", "周三","周四", "周五", "周六"};

    /* 用户输入日期 */
    printf ("年: "); fflush(stdout); scanf ("%d",&year);
    printf ("月: "); fflush(stdout); scanf ("%d",&month);
    printf ("日: "); fflush(stdout); scanf ("%d",&day);

    /* 获取当前时间信息，并修改用户输入的输入信息 */
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;

    /* 调用 mktime: timeinfo->tm_wday  */
    mktime ( timeinfo );

    printf ("那一天是：%s\n", weekday[timeinfo->tm_wday]);
}


void difftime_fun()
{
   time_t start_t, end_t;
   double diff_t;

   printf("程序启动...\n");
   time(&start_t);

   printf("休眠 2 秒...\n");
   sleep(2);

   time(&end_t);
   diff_t = difftime(end_t, start_t);

   printf("执行时间 = %f\n", diff_t);
   printf("程序退出...\n");
}


void strftime()
{
   time_t rawtime;
   struct tm *info;
   char buffer[80];

   time( &rawtime );

   info = localtime( &rawtime );

   strftime(buffer, 80, "%Y-%m-%d %H:%M:%S:%a", info);
   printf("格式化的日期 & 时间 : |%s|\n", buffer );
}

void cin_fun()
{
   char name[50];

   cout << "请输入您的名称： ";
   cin >> name;
   //scanf("%s", name);
   cout << "您的名称是： " << name << endl;

}


// 声明一个结构体类型 Books
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

void struct_fun()
{
   Books Book1;        // 定义结构体类型 Books 的变量 Book1
   Books Book2;        // 定义结构体类型 Books 的变量 Book2

   // Book1 详述
   strcpy( Book1.title, "C++ 教程");
   strcpy( Book1.author, "Runoob");
   strcpy( Book1.subject, "编程语言");
   Book1.book_id = 12345;

   // Book2 详述
   strcpy( Book2.title, "CSS 教程");
   strcpy( Book2.author, "Runoob");
   strcpy( Book2.subject, "前端技术");
   Book2.book_id = 12346;

   // 输出 Book1 信息
   cout << "第一本书标题 : " << Book1.title <<endl;
   cout << "第一本书作者 : " << Book1.author <<endl;
   cout << "第一本书类目 : " << Book1.subject <<endl;
   cout << "第一本书 ID : " << Book1.book_id <<endl;

   // 输出 Book2 信息
   cout << "第二本书标题 : " << Book2.title <<endl;
   cout << "第二本书作者 : " << Book2.author <<endl;
   cout << "第二本书类目 : " << Book2.subject <<endl;
   cout << "第二本书 ID : " << Book2.book_id <<endl;

}




int struct2_fun( )
{
   Books Book1;        // 定义结构体类型 Books 的变量 Book1
   Books Book2;        // 定义结构体类型 Books 的变量 Book2

    // Book1 详述
   strcpy( Book1.title, "C++ 教程");
   strcpy( Book1.author, "Runoob");
   strcpy( Book1.subject, "编程语言");
   Book1.book_id = 12345;

   // Book2 详述
   strcpy( Book2.title, "CSS 教程");
   strcpy( Book2.author, "Runoob");
   strcpy( Book2.subject, "前端技术");
   Book2.book_id = 12346;

   // 输出 Book1 信息
   printBook( Book1 );

   // 输出 Book2 信息
   printBook( Book2 );

   return 0;
}
void printBook( struct Books book )
{
   cout << "书标题 : " << book.title <<endl;
   cout << "书作者 : " << book.author <<endl;
   cout << "书类目 : " << book.subject <<endl;
   cout << "书 ID : " << book.book_id <<endl;
}



class printdate{
public:
    void printf(int i){
        cout << "整数为："<< i << endl;
    }
    void printf(double f){
        cout << "浮点数为："<< f << endl;
    }
    void printf(char c[]){
        cout << "字符串为："<< c << endl;
    }
    int c,p;
    void test_c(int i)
    {
        c = i;
    }
        void test_p(int x)
        {
            p = x;
        }

};


void class_fun()
{
    printdate pd;

    pd.printf(18);
    pd.printf(18.8);
    pd.printf("18.8");
}
