#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <sys/stat.h> //_statͷ�ļ�

#if 0
//FILE �ļ�
//fopen,fclose ��,�ر��ļ�
//fread,fwrite
//fgetc,fputc
int main(){
	FILE *fpr = NULL, *fpw = NULL;
	char c;
	fpr = fopen("C:\\Users\\hm\\Desktop\\1.txt","r");
	fpw = fopen("C:\\Users\\hm\\Desktop\\3.txt","w");
	if (fpr == NULL){
		printf("open fail\n");
		return 0;
	}
	if (fpw == NULL){
		printf("open fail\n");
		return 0;
	}
	while ((c = fgetc(fpr)) != EOF)//�����ļ�����
	{
		putchar(c);
		fputc(c, fpw);
	}
	fclose(fpr);//�ر��ļ�,������Ҫ����ѭ����
	fpr = NULL;
	fclose(fpw);//�ر��ļ�,������Ҫ����ѭ����
	fpw = NULL;
	system("pause");
	return 0;
}
#endif

#if 0
int main(){
	char c;
	while ((c = getchar()) != '\n'){
		putchar(c);
	}
	system("pause");
	return 0;
}
#endif

#if 0
int main(){
	char *buf = NULL;
	FILE *fpr = fopen("C:\\Users\\hm\\Desktop\\1.txt", "r");
	FILE *fpw = fopen("C:\\Users\\hm\\Desktop\\2.txt", "w");
	int n = 0;
	if (fpr == NULL){
		printf("open fail\n");
		return 0;
	}
	if (fpw == NULL){
		printf("open fail\n");
		return 0;
	}
	while (fgetc(fpr) != EOF){
		n++;
	}
	printf("n = %d\n", n);
	buf = (char*)malloc(sizeof(char)*n + 1);
	rewind(fpr);
	fgets(buf, n + 1, fpr);
	fputs(buf, fpw);
	//fgets(buf, 5, fpr);//��ȡ�����ַ������Զ��ں����\0������ʾ���ַ���ֻ��n-1�
	//puts(buf);
	//fputs("\nnihao\n", fpw);
	//puts("\nnihao\n");
	fclose(fpr);//�ر��ļ�,������Ҫ����ѭ����
	fpr = NULL;
	fclose(fpw);//�ر��ļ�,������Ҫ����ѭ����
	fpw = NULL;
	free(buf);
	buf = NULL;
	system("pause");
	return 0;
}
#endif

#if 0
int main(){
	FILE *fpr = fopen("C:\\Users\\hm\\Desktop\\1.txt", "r");
	FILE *fpw = fopen("C:\\Users\\hm\\Desktop\\2.txt", "w");
	int a, b, c;
	if (fpr == NULL){
		printf("open fail\n");
		return 0;
	}
	if (fpw == NULL){
		printf("open fail\n");
		return 0;
	}
	//scanf("%2d%3d%1d", &a, &b, &c);
	//printf("a=%d,b=%d,c=%d", a, b, c);
	fscanf(fpr,"%2d%3d%1d", &a, &b, &c);
	//fprintf(fpw,"a = %d,b = %d,c = %d", a, b, c);
	fprintf(fpw, "hello world");
	fclose(fpr);//�ر��ļ�,������Ҫ����ѭ����
	fpr = NULL;
	fclose(fpw);//�ر��ļ�,������Ҫ����ѭ����
	fpw = NULL;
	system("pause");
	return 0;
}
#endif

#if 0
//��ʼλ�ã�SEEK_SET(0),SEEK_CUR(1),SEEK_END(2),
int main(){
	FILE *fpr = fopen("C:\\Users\\hm\\Desktop\\1.txt", "rb");
	FILE *fpw = fopen("C:\\Users\\hm\\Desktop\\2.txt", "w");
	char *buf = NULL;
	int n;
	char c;
	if (fpr == NULL){
		printf("open fail\n");
		return 0;
	}
	if (fpw == NULL){
		printf("open fail\n");
		return 0;
	}
	//�����Ʒ�ʽ��
	//n = fread(buf, 10, 1, fpr);//fpr�ļ��ж���1�Σ�һ�ζ�10��
	//puts(buf);
	//printf("n = %d\n", n);
	//fseek(fpr, 2, 0);//��ǰλ������2
	//fseek(fpr, -2, 1);//��ǰλ������2
	fseek(fpr, 0, 2);
	n = ftell(fpr);
	rewind(fpr);
	printf("%d\n", n);
	buf = (char*)malloc(sizeof(char)*n);
	fread(buf, n, 1, fpr);//fpr�ж�1�Σ�һ�ζ�n�����������ķ���buf�У�
	fwrite(buf, n, 1, fpw);
	//c = fgetc(fpr);
	//printf("%c\n", c);
	fclose(fpr);	
	fclose(fpw); 
	fpr = NULL;
	fpw = NULL;
	free(buf);
	buf = NULL;
	system("pause");
	return 0;
}
#endif

#if 0
typedef struct data{
	char name[20];
	char age[3];
	//int age;
	char sex[3];
}Data;
//�ַ���--fread,fwrite,fgets
//��ʽ�����ݽṹ��--1��������    fread,fwrite
//                  2�������������  fgets,fputs
int main(){
	Data t = {"zhangsan", "5", "m"};
	FILE *fpw = fopen("C:\\Users\\hm\\Desktop\\1.txt", "wb");
	fprintf(fpw, "%s %d %c", t.name, t.age, t.sex);
	fwrite(&t, sizeof(Data), 1, fpw);
	fclose(fpw);
	fpw = NULL;
	system("pause");
	return 0;
}
#endif

#if 0
int main(){
	struct _stat buf;
	int n;
	_stat("C:\\Users\\hm\\Desktop\\1.txt",&buf);
	n = buf.st_size;//���ļ���С
	printf("n = %d\n", n);
	system("pause");
	return 0;
}
#endif

#if 1
typedef struct data{
	char name[20];
	int age;
}Data;
int main(){
	Data t = { "bitekeji", 8 };
	Data s;
	char str[20];
	//fprintf(FILE*, "%s &d", t.name, t.age);
	//printf("%s %d", t.name, t.age);
	sprintf(str, "%s %d", t.name, t.age);
	//puts(str);
	sscanf(str, "%s %d", s.name, &s.age);
	printf("%s %d\n", s.name, s.age);
	system("pause");
	return 0;
}
#endif