#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//结构体大小的计算
//struct stu
//{
//
//	double a;
//	char b;
//	double c;
//};
//struct st
//{
//	double a;
//	double b;
//	char c;
//	
//};
//int main()
//{
//	struct stu s = { 0 };
//	struct st t = { 0 };
//	printf("%d\n", sizeof(s));//24
//	printf("%d\n", sizeof(t));//24 虽然结果相同 但内存排列不同 有空间的浪费
//	return 0;
//}
//当前vs编译器默认对齐数为8 可通过#pragma pack(n) 来改变
//struct stu
//{
//	char a;
//	char b;
//	double c;
//};
//#pragma pack(4)//将默认对齐数改为4
//struct st
//{
//	char a;
//	char b;
//	double c;
//};
//#pragma pack(1)//将默认对齐数改为1
//struct std
//{
//	char a;
//	char b;
//	double c;
//};
//#pragma pack()//恢复默认对齐数
//int main()
//{
//	struct stu s = { 0 };
//	struct st t = { 0 };
//	struct std d = { 0 };
//	printf("%d\n", sizeof(s));//16
//	printf("%d\n", sizeof(t));//12
//	printf("%d\n", sizeof(d));//10
//	return 0;
//}
//offsetof (type,member)//计算函数偏移量(变量首元素相对于函数首元素的偏移量)
//#include<stddef.h>
//struct stu
//{
//	int a;
//	char b;
//	double c;
//};
//int main()
//{
//	printf("%d\n", offsetof(struct stu, a));//0
//	printf("%d\n", offsetof(struct stu, b));//4
//	printf("%d\n", offsetof(struct stu, c));//8
//	return 0;
//}
//通过构建函数给结构体变量赋值
//struct stu
//{
//	int a;
//	char b;
//	float c;
//};
//void init(struct stu* s)
//{
//	s->a = 100;
//	s->b = 'w';
//	s->c = 3.14;
//}
//void print1(struct stu s)
//{
//	printf("%d,%c,%0.2f\n", s.a, s.b, s.c);//100,w,3.14
//}
//void print2(struct stu* s)
//{
//	printf("%d,%c,%0.2f\n", s->a, s->b, s->c);//100,w,3.14
//}
//int main()
//{
//	struct stu s;
//	init(&s);
//	//printf("%d,%c,%0.2f", s.a, s.b, s.c);
//	//把s传给打印函数进行打印
//	print1(s);
//	//把s的地址传给打印函数进行打印（这种更为推荐，传值过程中压栈小）
//	print2(&s);
//	return 0;
//}
//位段
//struct stu
//{
//	int a : 10;
//	int b : 2;
//	int c : 3;
//};
//int main()
//{
//	struct stu c = { 0 };
//	printf("%d\n", sizeof(c));//4  相当于给a分配了10个比特位，要申请3个字节，余下2个比特位刚好可以给b，然后c又可以申请1个字节，余下一个比特位，如果c后还有变量
//	//申请的字节大于一，则会另外开辟一个字节，余下的一个比特位将浪费，但申请的比特位不得超过32
//	return 0;
//}
//位段使用内存分析
//struct stu
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//int main()
//{
//	struct stu s = { 0 };//调试时调试窗口的值：22 03 04
//	s.a = 10;
//	s.b = 20;
//	s.c = 3;
//	s.d = 4;
//	printf("%d %d %d %d", s.a, s.b, s.c, s.d);//2 2 3 4 因为有的比特位放不下该数字 比如3个比特位放不下10（1010：四个比特位）
//	return 0;
//}————————————————————————————————————
//枚举:enum
//enum color
//{
//	red,
//	green,
//	yellow
//};
//int main()
//{
//	enum color y = yellow;
//	enum color r = red;
//	enum color g = green;
//	//enum color b = blue;//不行  b只能定义为上方包含的颜色
//	printf("%d\n", r);//0
//	printf("%d\n", g);//1
//	printf("%d\n", y);//2 
//	return 0;
//}
//enum color
//{
//	red,
//	green=3,
//	blue
//};
//int main()
//{
//	enum color r = red;
//	enum color g = green;
//	enum blue b = blue;
//	printf("%d\n", r);//0
//	printf("%d\n", g);//3
//	printf("%d\n", b);//4  第一个不定义则为0 若其中一个定义了则后面的再此基础上加一
//	return 0;
//}——————————————————————————————————————————————
//联合  union
//union un
//{
//	int i;
//	char m;
//};
//int main()
//{
//	union un s = { 0 };
//	printf("%d\n", sizeof(s));//4
//	printf("%p\n", &s);//005EFB2C
//	printf("%p\n", &(s.i));//005EFB2C
//	printf("%p\n", &(s.m));//005EFB2C  一样 说明i和m共占一段空间  不过int类型比char类型大 但公用了一部分
//	return 0;
//}——————————————————————————————
//写一段代码判断机器的大小端
//法一
//int main()
//{
//	int a = 1;
//	if (*(char*)&a == 1)//&号别忘了
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}
//法二
//int judge()
//{
//	int a = 1;
//	return *(char*)&a;
//}
//int main()
//{
//	int ret = judge();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}
//法三
//int judge()
//{
//	union
//	{
//		int a ;//此处a不可赋值？
//		char b;
//	}u;
//	u.a = 1;
//	return u.b;
//}
//int main()
//{
//	int ret = judge();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}————————————————————————————
//union un
//{
//	int a;
//	char b[5] ;
//};
//int main()
//{
//	union un m;
//	printf("%d\n", sizeof(m));//8 m的大小必须是最大类型数的整数倍 int占四个字节 char占1个字节 所以m的大小为四的整数倍 又有b[5]占5个字节 所以四的最小倍数为8
//	return 0;
//}
