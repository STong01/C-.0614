#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <sys/stat.h> //_stat头文件

#if 0
//FILE 文件
//fopen,fclose 打开,关闭文件
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
	while ((c = fgetc(fpr)) != EOF)//读出文件内容
	{
		putchar(c);
		fputc(c, fpw);
	}
	fclose(fpr);//关闭文件,尽量不要放在循环中
	fpr = NULL;
	fclose(fpw);//关闭文件,尽量不要放在循环中
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
	//fgets(buf, 5, fpr);//获取的是字符串，自动在后面加\0，则显示的字符串只有n-1项；
	//puts(buf);
	//fputs("\nnihao\n", fpw);
	//puts("\nnihao\n");
	fclose(fpr);//关闭文件,尽量不要放在循环中
	fpr = NULL;
	fclose(fpw);//关闭文件,尽量不要放在循环中
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
	fclose(fpr);//关闭文件,尽量不要放在循环中
	fpr = NULL;
	fclose(fpw);//关闭文件,尽量不要放在循环中
	fpw = NULL;
	system("pause");
	return 0;
}
#endif

#if 0
//起始位置：SEEK_SET(0),SEEK_CUR(1),SEEK_END(2),
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
	//二进制方式读
	//n = fread(buf, 10, 1, fpr);//fpr文件中读了1次，一次读10个
	//puts(buf);
	//printf("n = %d\n", n);
	//fseek(fpr, 2, 0);//当前位置右移2
	//fseek(fpr, -2, 1);//当前位置左移2
	fseek(fpr, 0, 2);
	n = ftell(fpr);
	rewind(fpr);
	printf("%d\n", n);
	buf = (char*)malloc(sizeof(char)*n);
	fread(buf, n, 1, fpr);//fpr中读1次，一次读n个，读出来的放在buf中；
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
//字符串--fread,fwrite,fgets
//格式化数据结构体--1、二进制    fread,fwrite
//                  2、数据输入输出  fgets,fputs
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
	n = buf.st_size;//求文件大小
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