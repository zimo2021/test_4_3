#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//�ṹ���С�ļ���
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
//	printf("%d\n", sizeof(t));//24 ��Ȼ�����ͬ ���ڴ����в�ͬ �пռ���˷�
//	return 0;
//}
//��ǰvs������Ĭ�϶�����Ϊ8 ��ͨ��#pragma pack(n) ���ı�
//struct stu
//{
//	char a;
//	char b;
//	double c;
//};
//#pragma pack(4)//��Ĭ�϶�������Ϊ4
//struct st
//{
//	char a;
//	char b;
//	double c;
//};
//#pragma pack(1)//��Ĭ�϶�������Ϊ1
//struct std
//{
//	char a;
//	char b;
//	double c;
//};
//#pragma pack()//�ָ�Ĭ�϶�����
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
//offsetof (type,member)//���㺯��ƫ����(������Ԫ������ں�����Ԫ�ص�ƫ����)
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
//ͨ�������������ṹ�������ֵ
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
//	//��s������ӡ�������д�ӡ
//	print1(s);
//	//��s�ĵ�ַ������ӡ�������д�ӡ�����ָ�Ϊ�Ƽ�����ֵ������ѹջС��
//	print2(&s);
//	return 0;
//}
//λ��
//struct stu
//{
//	int a : 10;
//	int b : 2;
//	int c : 3;
//};
//int main()
//{
//	struct stu c = { 0 };
//	printf("%d\n", sizeof(c));//4  �൱�ڸ�a������10������λ��Ҫ����3���ֽڣ�����2������λ�պÿ��Ը�b��Ȼ��c�ֿ�������1���ֽڣ�����һ������λ�����c���б���
//	//������ֽڴ���һ��������⿪��һ���ֽڣ����µ�һ������λ���˷ѣ�������ı���λ���ó���32
//	return 0;
//}
//λ��ʹ���ڴ����
//struct stu
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//int main()
//{
//	struct stu s = { 0 };//����ʱ���Դ��ڵ�ֵ��22 03 04
//	s.a = 10;
//	s.b = 20;
//	s.c = 3;
//	s.d = 4;
//	printf("%d %d %d %d", s.a, s.b, s.c, s.d);//2 2 3 4 ��Ϊ�еı���λ�Ų��¸����� ����3������λ�Ų���10��1010���ĸ�����λ��
//	return 0;
//}������������������������������������������������������������������������
//ö��:enum
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
//	//enum color b = blue;//����  bֻ�ܶ���Ϊ�Ϸ���������ɫ
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
//	printf("%d\n", b);//4  ��һ����������Ϊ0 ������һ���������������ٴ˻����ϼ�һ
//	return 0;
//}��������������������������������������������������������������������������������������������
//����  union
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
//	printf("%p\n", &(s.m));//005EFB2C  һ�� ˵��i��m��ռһ�οռ�  ����int���ͱ�char���ʹ� ��������һ����
//	return 0;
//}������������������������������������������������������������
//дһ�δ����жϻ����Ĵ�С��
//��һ
//int main()
//{
//	int a = 1;
//	if (*(char*)&a == 1)//&�ű�����
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0;
//}
//����
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
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0;
//}
//����
//int judge()
//{
//	union
//	{
//		int a ;//�˴�a���ɸ�ֵ��
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
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0;
//}��������������������������������������������������������
//union un
//{
//	int a;
//	char b[5] ;
//};
//int main()
//{
//	union un m;
//	printf("%d\n", sizeof(m));//8 m�Ĵ�С����������������������� intռ�ĸ��ֽ� charռ1���ֽ� ����m�Ĵ�СΪ�ĵ������� ����b[5]ռ5���ֽ� �����ĵ���С����Ϊ8
//	return 0;
//}
