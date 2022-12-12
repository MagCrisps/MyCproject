//制作者：【38_董占胜】【学号：2220212612】【计科2021-1班】
//上机测验2022-2023-1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef  struct  LNode   //定义单链表结点结构
{
    int     data;          //数据域
    struct  LNode* next;   //指针域
} LNode, * Link;

void Create(Link& L);//创建链表函数
void Output(Link L);//输出链表函数
void QxP(Link& L, int x);//实现本题功能

void main()
//制作者：【38_董占胜】【学号：2220212612】【计科2021-1班】
{
	Link L;
	Create(L);
	Output(L);
	QxP(L, 1);
	printf("奇数模式\n");
	Output(L);

	printf("------------------------\n");
	Create(L);
	//Output(L);
	QxP(L, 2);
	printf("偶数模式\n");
	Output(L);
}

void Create(Link& L)//创建链表函数
//制作者：【38_董占胜】【学号：2220212612】【计科2021-1班】
{
	FILE* fp;
	Link h;
	fopen_s(&fp, "data.txt", "r");
	L = (Link)malloc(sizeof(LNode));
	if (!L) {
		exit(-1);
	}
	L->next = NULL;
	while (!feof(fp)) {

		Link hp = (Link)malloc(sizeof(LNode));
		fscanf_s(fp, "%d", &hp->data);
		hp->next = L->next;
		L->next = hp;
	}
	//printf("READ OVER.\n");
}


void Output(Link L)//输出链表函数
//制作者：【38_董占胜】【学号：2220212612】【计科2021-1班】
{
	Link p = L->next;

	printf("***********************\n");
	printf("制作者：【38_董占胜】【学号：2220212612】【计科2021-1班】\n");
	while (p) {
		printf("%d\n", p->data);
		p = p->next;
	}

	printf("***********************\n");
}

void QxP(Link& L, int x)//实现本题功能
//制作者：【38_董占胜】【学号：2220212612】【计科2021-1班】
{
	int flag = 0;
	Link hp = (Link)malloc(sizeof(LNode));
	if (!hp) {
		exit(-1);
	}
	Link t = NULL, r = t, ou = L;
	hp->data = x;
	hp->next = NULL;
	Link p = L->next;
	if (x % 2) {
		flag = 1;
	}
	if (flag) {
		while (p) {

			if (p->data % 2) {
				if (t) {
					r->next = p;
				}
				else {
					t = p;
				}
				r = p;
			}
			else {
				ou->next = p;
				ou = p;
			}
			p = p->next;
		}//x=1
		ou->next = NULL;
		r->next = L->next;
		L->next = hp;
		hp->next = t;
		//t->next = ou;
	}
	else {
		while (p) {

			if (!(p->data % 2)) {
				if (t) {
					r->next = p;
				}
				else {
					t = p;
				}
				r = p;

			}
			else {
				ou->next = p;
				ou = p;
			}
			p = p->next;
		}
		
		r->next = L->next;
		L->next = t;
		ou->next = hp;
	}//x=0
}
	
//制作者：【38_董占胜】【学号：2220212612】【计科2021-1班】