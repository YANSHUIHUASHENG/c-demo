#include"test.hpp"
#include"time.h"



void user_fun(void)
{
    int ptr=12345;
    int date[10]={1,3,5,7,9,11,13,15,17,19};
    int *p,*p1;

    cout << "ptr  ���ݣ�" << ptr << endl;
    cout << "ptr  ��ַ��" << &ptr << endl<< endl;
    cout << "date ���ݣ�" << date << endl;
    cout << "date ��ַ��" << &date << endl<< endl;
    p = &ptr;
    cout << "p    ���ݣ�" << *p << endl;
    cout << "p    ��ַ��" << p << endl<< endl;
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
        cout << i << " :p1  ���ݣ�"  << *p1 << endl;
        cout << i << " :p1  ��ַ��"  << p1 << endl<< endl;
        p1++;
    }
}


void time0_fun()
{
   // ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
   time_t now = time(0);

   // �� now ת��Ϊ�ַ�����ʽ
   char* dt = ctime(&now);

   cout << "�������ں�ʱ�䣺" << dt << endl;

   // �� now ת��Ϊ tm �ṹ
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "UTC ���ں�ʱ�䣺"<< dt << endl;
}

void time1_fun()
{
   // ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
   time_t now = time(0);

   cout << "1970 ��Ŀǰ��������:" << now << endl;

   tm *ltm = localtime(&now);

   // ��� tm �ṹ�ĸ�����ɲ���
   cout << "��: "<< 1900 + ltm->tm_year << endl;
   cout << "��: "<< 1 + ltm->tm_mon<< endl;
   cout << "��: "<<  ltm->tm_mday << endl;
   cout << "ʱ��: "<< ltm->tm_hour << ":";
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}

void time_fun()
{
  time_t seconds;

  //seconds = time(NULL);
  time(&seconds);
  printf("�� 1970-01-01 ���Сʱ�� = %ld\n", seconds/3600);

}

void ctime_fun()
{
   time_t curtime;

   time(&curtime);

   printf("��ǰʱ�� = %s", ctime(&curtime));

}

void localtime_fun()
{
   time_t rawtime;
   struct tm *info;

   time( &rawtime );

   info = localtime( &rawtime );
   printf("��ǰ�ı���ʱ������ڣ�%s", asctime(info));
}


void clock_fun()
{
   clock_t start_t, end_t;
   double total_t;
   int i;

   start_t = clock();
   printf("����������start_t = %ld\n", start_t);

   printf("��ʼһ����ѭ����start_t = %ld\n", start_t);
   for(i=0; i< 10000000; i++)
   {
   }
   end_t = clock();
   printf("��ѭ��������end_t = %ld\n", end_t);

   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("CPU ռ�õ���ʱ�䣺%f\n", total_t  );
   printf("�����˳�...\n");
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
   /* ��ȡ GMT ʱ�� */
   info = gmtime(&rawtime );

   printf("��ǰ������ʱ�ӣ�\n");
   printf("�׶أ�%2d:%02d\n", (info->tm_hour+BST)%24, info->tm_min);
   printf("�й���%2d:%02d\n", (info->tm_hour+CCT)%24, info->tm_min);

}


void mktime_fun()
{
    time_t rawtime;
    struct tm * timeinfo;
    int year, month ,day;
    const char * weekday[] = { "����", "��һ","�ܶ�", "����","����", "����", "����"};

    /* �û��������� */
    printf ("��: "); fflush(stdout); scanf ("%d",&year);
    printf ("��: "); fflush(stdout); scanf ("%d",&month);
    printf ("��: "); fflush(stdout); scanf ("%d",&day);

    /* ��ȡ��ǰʱ����Ϣ�����޸��û������������Ϣ */
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;

    /* ���� mktime: timeinfo->tm_wday  */
    mktime ( timeinfo );

    printf ("��һ���ǣ�%s\n", weekday[timeinfo->tm_wday]);
}


void difftime_fun()
{
   time_t start_t, end_t;
   double diff_t;

   printf("��������...\n");
   time(&start_t);

   printf("���� 2 ��...\n");
   sleep(2);

   time(&end_t);
   diff_t = difftime(end_t, start_t);

   printf("ִ��ʱ�� = %f\n", diff_t);
   printf("�����˳�...\n");
}


void strftime()
{
   time_t rawtime;
   struct tm *info;
   char buffer[80];

   time( &rawtime );

   info = localtime( &rawtime );

   strftime(buffer, 80, "%Y-%m-%d %H:%M:%S:%a", info);
   printf("��ʽ�������� & ʱ�� : |%s|\n", buffer );
}

void cin_fun()
{
   char name[50];

   cout << "�������������ƣ� ";
   cin >> name;
   //scanf("%s", name);
   cout << "���������ǣ� " << name << endl;

}


// ����һ���ṹ������ Books
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

void struct_fun()
{
   Books Book1;        // ����ṹ������ Books �ı��� Book1
   Books Book2;        // ����ṹ������ Books �ı��� Book2

   // Book1 ����
   strcpy( Book1.title, "C++ �̳�");
   strcpy( Book1.author, "Runoob");
   strcpy( Book1.subject, "�������");
   Book1.book_id = 12345;

   // Book2 ����
   strcpy( Book2.title, "CSS �̳�");
   strcpy( Book2.author, "Runoob");
   strcpy( Book2.subject, "ǰ�˼���");
   Book2.book_id = 12346;

   // ��� Book1 ��Ϣ
   cout << "��һ������� : " << Book1.title <<endl;
   cout << "��һ�������� : " << Book1.author <<endl;
   cout << "��һ������Ŀ : " << Book1.subject <<endl;
   cout << "��һ���� ID : " << Book1.book_id <<endl;

   // ��� Book2 ��Ϣ
   cout << "�ڶ�������� : " << Book2.title <<endl;
   cout << "�ڶ��������� : " << Book2.author <<endl;
   cout << "�ڶ�������Ŀ : " << Book2.subject <<endl;
   cout << "�ڶ����� ID : " << Book2.book_id <<endl;

}




int struct2_fun( )
{
   Books Book1;        // ����ṹ������ Books �ı��� Book1
   Books Book2;        // ����ṹ������ Books �ı��� Book2

    // Book1 ����
   strcpy( Book1.title, "C++ �̳�");
   strcpy( Book1.author, "Runoob");
   strcpy( Book1.subject, "�������");
   Book1.book_id = 12345;

   // Book2 ����
   strcpy( Book2.title, "CSS �̳�");
   strcpy( Book2.author, "Runoob");
   strcpy( Book2.subject, "ǰ�˼���");
   Book2.book_id = 12346;

   // ��� Book1 ��Ϣ
   printBook( Book1 );

   // ��� Book2 ��Ϣ
   printBook( Book2 );

   return 0;
}
void printBook( struct Books book )
{
   cout << "����� : " << book.title <<endl;
   cout << "������ : " << book.author <<endl;
   cout << "����Ŀ : " << book.subject <<endl;
   cout << "�� ID : " << book.book_id <<endl;
}



class printdate{
public:
    void printf(int i){
        cout << "����Ϊ��"<< i << endl;
    }
    void printf(double f){
        cout << "������Ϊ��"<< f << endl;
    }
    void printf(char c[]){
        cout << "�ַ���Ϊ��"<< c << endl;
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
