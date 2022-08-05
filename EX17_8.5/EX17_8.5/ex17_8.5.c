#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//写代码把test.txt文件拷贝一份，生成test2.txt文件
int main()
{
	FILE* pfread = fopen("test.txt", "r");
	if (NULL == pfread)
	{
		return 1;
	}
	FILE* pfwrite = fopen("test2.txt", "w");
	if (NULL == pfwrite)
	{
		fclose(pfread);
		pfread = NULL;
		return 1;
	}

	//两个文件都打开成功
	//读写文件
	int ch = 0;
	while ((ch = fgetc(pfread)) != EOF);  //如果读的文件不是结束标志，则写入数据（一个一个写）
	{
		//写文件
		fputc(ch, pfwrite);
	}

	//关闭文件
	fclose(pfread);
	pfread = NULL;
	fclose(pfwrite);
	pfwrite = NULL;
	return 0;
}

//——————————————————————————————————————————————————————————————————————————————————————

//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	fwrite(&a, sizeof(int), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main()  //fseek()函数 文件的随机读写，指定文件指针的位置来读写数据
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//读取文件
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//调整文件指针
//	fseek(pf, 2, SEEK_CUR);
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	fseek(pf, -2, SEEK_END);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	int ret = ftell(pf); //ftell() 返回文件指针相对于起始位置的偏移量
//	printf("%d\n", ret);
//
//	//让文件指针回到起始位置
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//——————————————————————————————————————————————————————————————————————————————————————

//struct S
//{
//	char arr[10];
//	int num;
//	float sc;
//
//};
//
//int main()
//{
//	struct S s = { "hello",20,5.5f };
//	struct S tmp = { 0 };
//
//	char buf[100] = { 0 };
//	//sprintf 把一个格式化的数据，转化为字符串
//	sprintf(buf, "%s %d %f", s.arr, s.num, s.sc);
//	printf("%s\n", buf);
//
//	//从buf字符串中还原一个结构体数据
//	sscanf(buf, "%s %d %f", tmp.arr, &(tmp.num), &(tmp.sc));
//	printf("%s %d %f\n", tmp.arr, tmp.num, tmp.sc);
//	return 0;
//}

//————————————————————————————————————

//int main() //二进制的读写
//{
//	struct S s = { "ABCDE",10,5.5f };
//	//二进制的形式写
//	FILE* pf = fopen("data.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	fwrite(&s, sizeof(struct S), 1, pf); //以二进制的形式写入的内容是看不懂的东西
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//——————————————————————————————————————————————————————————————————————————————————————

//int main()
//{
//	char arr[10] = { 0 };
//	FILE* pf = fopen("data.txt", "r");  //相对路径
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//读文件
//	int ret = fgetc(pf);   //字符输入函数，在屏幕中显示所读到的信息，从文件流中读取一个字符
//	printf("%c\n", ret);
//
//	fgets(arr, 3, pf);    // 字符串输入函数，在屏幕中显示目标文件里所读到的字符串信息
//	printf("%s\n", arr);
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//—————————————————————————————————————————————————————————————————————————————————————

//int main()
//{
//	fputc('A', stdout);  //标准输出流。 直接在屏幕上打印出来‘ABC'
//	fputc('B', stdout);
//	fputc('C', stdout);    //输出helloworld的不同写法啦
//	return 0;
//}

//—————————————————————————————————————————————————————————————————————————————————————

//int main()
//{
//	FILE* pf = fopen("data.txt","w");  //相对路径
//	// FILE* pf = fopen("D:\\VS-xiang_mu\\EX_xiangmu\\EX17_8.5\\data.txt"," w");  //绝对路径，不过要记得加  \  的转义字符
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//写文件
//	fputc('A', pf);       //在目标文件里写入一个字符。
//	fputc('\n', pf);
//	fputs("ABCDEF\n", pf);   //在目标文件里写入一行字符串
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}