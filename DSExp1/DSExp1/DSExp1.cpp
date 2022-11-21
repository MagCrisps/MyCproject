// DSExp1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define ERROR -1

typedef struct HNode {
	char roomN[7];
	float Price;
	float PriceL;
	int Beds;
	char State[5];
	struct HNode* next;
}Hotel, * HLink;

void Build(HLink& H);
void Exp(HLink H);
int Find(HLink& H, char* roomN);
void updateH(HLink& H, int beds, char* state);
void ADD(HLink& H);
HLink FirstH(HLink& H);
void MoveK1(HLink &H, int k);
void ReverseN2(HLink& H);
void SortPriceL(HLink& H);
void upBed(HLink& H, int beds);


int main(int argc, char* argv[])
{
	HLink H;
	Build(H);
	Exp(H);
	char str[] = "KF3";
	char str2[] = "满员";
	printf("the location is %d\n", Find(H, str));
	updateH(H, 3, str2);
	Exp(H);
	ADD(H);
	Exp(H);
	MoveK1(H, 3);
	Exp(H);
	ReverseN2(H);
	Exp(H);
	SortPriceL(H);
	Exp(H);
	upBed(H, 5);
	Exp(H);
	return 0;
}

void Build(HLink& H) {
	FILE* fp;
	HLink h;
	fopen_s(&fp,"data1.txt", "r");
	H = (HLink)malloc(sizeof(Hotel));
	if (!H) {
		exit(-1);
	}
	H->next = NULL;
	while ( !feof(fp) ) {

		HLink hp = (HLink)malloc(sizeof(Hotel));
		fscanf_s(fp, "%s %f %d", hp->roomN,7, &hp->Price, &hp->Beds);
		hp->PriceL = 0.8 * hp->Price;
		strcpy_s(hp->State, "空闲");
		hp->next = H->next;
		H->next = hp;
	}
	printf("READ OVER.\n");
}
void Exp(HLink H) {
	HLink p = H->next;

	printf("***********************\n");
	while (p) {

		printf("客房名称：%7s 标准价格：%5f 入住价格：%5f 床位数：%3d 入住状态：%s\n", p->roomN, p->Price, p->PriceL, p->Beds, p->State);
		p = p->next;
	}

	printf("***********************\n");
}

int Find(HLink& H, char* roomN) {
	HLink p = H->next;
	int count = 1;
	while (p&&strcmp(p->roomN, roomN)) {
		p = p->next;
		++count;
	}
	if (!p) {
		return ERROR;
	}
	else { 
		return count;
	}
}

void updateH(HLink& H, int beds, char* state) {
	HLink p = H->next;
	while (p) {
		if (p->Beds == beds) {
			strcpy_s(p->State, state);
		}
		p = p->next;
	}
	printf("STATE SWITCH FINISH\n");
}
void ADD(HLink& H) {
	HLink p = H->next;
	while (p) {
		if (!strcmp(p->State, "空闲")) {
			p->PriceL = p->PriceL * 1.2;
		}
		p = p->next;
	}
	printf("\tADD FINISH\n");
}void MoveK1(HLink &H,int k){
	HLink p = H->next, lp = p;
	int n = 0,i = 1;
	while (p) {
		p = p->next;
		n++;
	}
	i = n - k - 1;
	if (i < 0) {
		printf("WRONG INPUT!\n");
		exit(-1);
	}
	p = H->next;
	/*
	while (p&&p->next&&p->next->next&&i) {
		lp = p;
		p = p->next->next->next;
	}//find out the last but not least node
	*/
	while (i && p && p->next) {
		p = p->next;
		i--;
	}//p has reach to the fore point node.
	HLink temp = p->next;
	p->next = p->next->next;
	temp->next = H->next;
	H->next = temp;
	/*
	
	H->next = p->next;
	H->next->next = temp;
	//p->next;
	p->next = p->next->next;

	*/

}
void ReverseN2(HLink& H) {
	HLink p1 = H->next, p2 = H->next;
	int count = 0;
	while (p2&&p2->next) {
		p1 = p1->next;
		p2 = p2->next->next;
		count++;
	}//find out the middle node,p2 is the last node(not null).
	HLink store1 = p1,check = p1,store2 = p1;
	count--;
	while (check&&count>0) {

		while (p1&&p1->next&&p1->next->next) {
			p1 = p1->next;
		}
		store1 = p1->next;
		p1->next = p1->next->next;
		store1->next = store2->next;
		store2->next = store1;

		/*
		p1->next = NULL;
		store2 = check->next;
		check->next = p1;
		p1->next = store2;
		*/
		check = check->next;
		p1 = check;
		//make the last node to the 'middle'
		count--;
	}
	printf("reverse has finished\n");
}

void SortPriceL(HLink& H) {
	HLink p1 = H,pnext,p = NULL,pre = NULL;
	int count = 0;
	while (p1&&p1->next) {
		p1 = p1->next;
		count++;
	}
	count = count*(count-1)/2;
	//printf("!!%d!!\n", count);
	while (count--) {
		p = H->next;
		pre = H;
		//printf("$$%s **\n", p->roomN);
		while (p&&p->next&&pre)
		{
			int change = 0;
			pnext = p->next;
			//printf("^^%s **\n", p->roomN);
			if (p->PriceL > pnext->PriceL) {
				pre->next = pnext;
				p->next = pnext->next;
				pnext->next = p;
				change = 1;
			}
			if (change) {
				pre = pre->next;
				p = pre->next;
			}
			else {
				p = p->next;
				pre = pre->next;
			}
			
			//printf("%s **\n", p->roomN);
		}
		//printf("!!%d!!\n", count);
	}
	printf("sort has finished\n");
}
void upBed(HLink& H, int beds) {
	HLink newNode = (HLink)malloc(sizeof(Hotel));
	char str1[] = "空闲";
	if (!newNode) {
		exit(-1);
	}
	HLink p = H->next,temp = p;
	printf("please enter roomname and price\n");
	scanf_s("%7s %f", newNode->roomN,7, &newNode->Price);
	newNode->PriceL = newNode->Price * 0.7;
	strcpy_s(newNode->State, str1);
	newNode->Beds = beds;
	while (p&&p->next) {
		if ((newNode->Beds > p->Beds) && (newNode->Beds <= p->next->Beds)) {
			newNode->next = p->next;
			p->next = newNode;
		}
		p = p->next;
	}
}

