#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//д�����test.txt�ļ�����һ�ݣ�����test2.txt�ļ�
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

	//�����ļ����򿪳ɹ�
	//��д�ļ�
	int ch = 0;
	while ((ch = fgetc(pfread)) != EOF);  //��������ļ����ǽ�����־����д�����ݣ�һ��һ��д��
	{
		//д�ļ�
		fputc(ch, pfwrite);
	}

	//�ر��ļ�
	fclose(pfread);
	pfread = NULL;
	fclose(pfwrite);
	pfwrite = NULL;
	return 0;
}

//����������������������������������������������������������������������������������������������������������������������������������������������������������������������������

//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//д�ļ�
//	fwrite(&a, sizeof(int), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main()  //fseek()���� �ļ��������д��ָ���ļ�ָ���λ������д����
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//��ȡ�ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//�����ļ�ָ��
//	fseek(pf, 2, SEEK_CUR);
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	fseek(pf, -2, SEEK_END);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	int ret = ftell(pf); //ftell() �����ļ�ָ���������ʼλ�õ�ƫ����
//	printf("%d\n", ret);
//
//	//���ļ�ָ��ص���ʼλ��
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//����������������������������������������������������������������������������������������������������������������������������������������������������������������������������

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
//	//sprintf ��һ����ʽ�������ݣ�ת��Ϊ�ַ���
//	sprintf(buf, "%s %d %f", s.arr, s.num, s.sc);
//	printf("%s\n", buf);
//
//	//��buf�ַ����л�ԭһ���ṹ������
//	sscanf(buf, "%s %d %f", tmp.arr, &(tmp.num), &(tmp.sc));
//	printf("%s %d %f\n", tmp.arr, tmp.num, tmp.sc);
//	return 0;
//}

//������������������������������������������������������������������������

//int main() //�����ƵĶ�д
//{
//	struct S s = { "ABCDE",10,5.5f };
//	//�����Ƶ���ʽд
//	FILE* pf = fopen("data.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//д�ļ�
//	fwrite(&s, sizeof(struct S), 1, pf); //�Զ����Ƶ���ʽд��������ǿ������Ķ���
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//����������������������������������������������������������������������������������������������������������������������������������������������������������������������������

//int main()
//{
//	char arr[10] = { 0 };
//	FILE* pf = fopen("data.txt", "r");  //���·��
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//���ļ�
//	int ret = fgetc(pf);   //�ַ����뺯��������Ļ����ʾ����������Ϣ�����ļ����ж�ȡһ���ַ�
//	printf("%c\n", ret);
//
//	fgets(arr, 3, pf);    // �ַ������뺯��������Ļ����ʾĿ���ļ������������ַ�����Ϣ
//	printf("%s\n", arr);
//	
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//��������������������������������������������������������������������������������������������������������������������������������������������������������������������������

//int main()
//{
//	fputc('A', stdout);  //��׼������� ֱ������Ļ�ϴ�ӡ������ABC'
//	fputc('B', stdout);
//	fputc('C', stdout);    //���helloworld�Ĳ�ͬд����
//	return 0;
//}

//��������������������������������������������������������������������������������������������������������������������������������������������������������������������������

//int main()
//{
//	FILE* pf = fopen("data.txt","w");  //���·��
//	// FILE* pf = fopen("D:\\VS-xiang_mu\\EX_xiangmu\\EX17_8.5\\data.txt"," w");  //����·��������Ҫ�ǵü�  \  ��ת���ַ�
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//д�ļ�
//	fputc('A', pf);       //��Ŀ���ļ���д��һ���ַ���
//	fputc('\n', pf);
//	fputs("ABCDEF\n", pf);   //��Ŀ���ļ���д��һ���ַ���
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}