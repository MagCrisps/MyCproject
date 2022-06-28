#include <iostream>
#include "String.h"
#define N 3
#define TRUE 1

typedef struct Student {
    char num[15];
    char name[15];
    char major[10];
    int classNo;
    int score[3];
}STU; 

typedef struct Stu{
    int num;
    char name[15];
    char major[10];
    int classNo;
    int score[3];
    struct Stu* next;
}stul;


STU stu[N], *stup;
FILE* f;
char flag = 0;
int ai = 0, ae = 0;
char cc = 0;
char* str = NULL;
char strt[32];
int swflag = 0;

//废案
//*********
void creat(stul* head,int length ) {
    stul* p = (stul*)malloc(sizeof(stul));
    if (p == NULL) { exit(0); }
    head->next = p;
    for (int i = 0; i < length/2; i++) {

        stul* pn = (stul*)malloc(sizeof(stul));
        if (pn == NULL) { exit(0); }
        p->next = pn;
        stul* p = (stul*)malloc(sizeof(stul));
        if (p == NULL) { exit(0); }
        pn->next = p;
    }
    p->next = NULL;
}
//********

void swi() {
    printf("1:linklist model 2:list model\n");
    scanf_s("%d", &swflag);
    if (swflag!=1&&swflag!=2){
        printf("wrong!\n");
        swi();
    }
}
stul* FcreatL() {
    stul* sp = (stul*)malloc(sizeof(stul));
    if (sp == NULL) { exit(0); }
    printf("\t请输入学生学号\n");
    scanf_s("%d", &sp->num);
    printf("\t请输入学生姓名\n");
    scanf_s("%s", sp->name, 15);
    printf("\t请输入学生专业\n");
    scanf_s("%s", sp->major, 10);
    printf("\t请输入学生班级\n");
    scanf_s("%d", &sp->classNo);
    printf("\t请输入学生成绩\n");
    for (int l = 0; l < 3; l++) {
        scanf_s("%d", &sp->score[l]);
    }
    sp->next = NULL;
    printf("done.\n");
    return sp;
}
stul* creatL(stul* head) {
    stul* sp = (stul*)malloc(sizeof(stul));
    if (sp == NULL) { exit(0); }
    printf("\t请输入学生学号\n");
    scanf_s("%d", &sp->num);
    printf("\t请输入学生姓名\n");
    scanf_s("%s", sp->name, 15);
    printf("\t请输入学生专业\n");
    scanf_s("%s", sp->major, 10);
    printf("\t请输入学生班级\n");
    scanf_s("%d", &sp->classNo);
    printf("\t请输入学生成绩\n");
    for (int l = 0; l < 3; l++) {
        scanf_s("%d", &sp->score[l]);
    }
    sp->next = NULL;
    head->next = sp;
    printf("done.\n");
    return sp;
}

void OutputL(stul* h) {
    if (h == NULL) {
        printf("失败");
        //exit(-2);//失败
    }
    else {
        printf("学号\t 姓名\t 专业\t 班级\t 成绩①\t 成绩②\t 成绩③\n");
        for (; h != NULL; h = h->next) {
            printf("%6d %6s %6s %6d %6d %6d %6d\n", h->num, h->name, h->major, h->classNo, h->score[0], h->score[1], h->score[2]);
        }
        printf("done.\n");
    }
    
}

void delet(stul* p) {
    if (p == NULL) {
        printf("失败");
        //exit(0);
    }
    for (; p == NULL; p = p->next) {
        stul* pt = p;
        free(pt);
    }
    printf("done.\n");
}
stul* storeL(){
    stul* hl = {}, * p;
    p = hl;
    for (int i = 0; i < N;i++) {
       //hl =  creatL(hl);
    }
    printf("done.\n");
    return p;
}
//void Search_major_subject_score(stul* head, char* major, )
void Search_major_subject_score(stul* sp, char major[], int scoreSum, int n) {
    if ((sp != NULL)&&(n <= 3)&&(n > 0)) {
        n--;
        for (; sp != NULL; sp = sp->next) {          
            if (!strcmp(sp->major, major)) {
                if (sp->score[n] < scoreSum) {
                    printf("%d\t", sp->num);
                    printf("%15s\t", sp->name);
                    printf("%s\t", sp->major);
                    printf("%d\t", sp->classNo);
                    for (int i = 0; i < 3; i++) {
                        printf("%d\t", sp->score[i]);
                    }//for score
                    putchar('\n');
                }//if <
            }//if major
        }//for sp!=NULL
        printf("finish.\n");
   }//if sp!=NULL
    else {
        printf("error!\n");
    }
   
}
/*
存储
*/
void SaveL(stul* head) {
    if (fopen_s(&f, "studentL.dat", "w")) {
        printf("新建文件失败！\n");
    }
    else {
        for (; head != NULL; head = head->next) {
            fprintf(f, "%d %s %s %d %d %d %d\n", head->num, head->name, head->major, head->classNo, head->score[0], head->score[1], head->score[2]);
        }
        fclose(f);
        printf("文件存储完毕\n");
    }
    
}
void FetchL(int num) {
    char c = 0;
    stul* stup = (stul*)malloc(sizeof(stul));
    if (fopen_s(&f, "studentL.dat", "r")) {
        printf("新建文件失败！\n");
    }
    else {
        for (int n = 0; n < num - 1; ) {
            fscanf_s(f, "%c", &c);
            if (c == '\n') {
                n++;
            }
        }
        fscanf_s(f, "%d %s %s %d %d %d %d", &stup->num, stup->name, 15, stup->major, 10, &stup->classNo, &stup->score[0], &stup->score[1], &stup->score[2]);
        stup->next = NULL;
        OutputL(stup);
        printf("查找完毕\n");
        fclose(f);
    }
}
stul* Delete_num(stul* head, int num) {
    stul* temp;
    stul* headF = head;

    if (head != NULL) {
        if (head->num == num) {
            temp = head;
            head = head->next;
            headF = head;
        }
        else {
            
            for (;(head != NULL) && (head->next != NULL) && (head->next->num != num) ; head = head->next);
                temp = head->next;
                head = head->next->next;
        }
        free(temp);
        printf("删除完成\n");
    }
    else {
        printf("error\n");
    }
    return headF;
}
void Delete_class_subject(stul* head, int classNo, int num, int n) {
    stul* temp  = NULL;
    if (head != NULL) {
        if ((head->score[n] < num)&&(head->classNo == classNo)) {
            temp = head;
            head = head->next;
            free(temp);
        }
        
        for (; (head->next != NULL) && (head->next->score[n] < num) && (head->next->classNo == classNo) && (head != NULL); head = head->next) {
             temp = head->next;
             head = head->next->next;
             free(temp);
        }
        printf("删除完成\n");
    }
    else {
        printf("error\n");
    }
}
/***************************/

stul* CreateList(stul* h) {
    stul* head = FcreatL(), * sp;
    sp = head;
    for (int i = 0; i < N-1; i++) {
        sp = creatL(sp);
    }
    printf("Creat_done.\n");
    return head;
}

/**************************/
stul* Search_num(stul* head, int num){
    if (head != NULL) {
        stul* temp = NULL;
        for (; (head != NULL) && (num != head->num); head = head->next);
        temp = head;
        printf("done.");
        return temp;
    }
    else {
        printf("erro\n");
        return NULL;
    }
  
}
void InsertList(stul* head) {
    stul* temp = NULL;
    temp = FcreatL();
    stul* tflag;
    if (head != NULL) {
        for (; (temp->num > head->num) && (temp->num < head->next->num) && (head != NULL);head = head->next );
        tflag = head->next;
        head->next = temp;
        temp->next = tflag;
        printf("插入完成\n");
    }
    else {
        printf("error\n");
    }
    
}
//废案
//******
stul* sortl(stul* Head,int n)
{
    stul* pfirst = NULL, * psecond = NULL, * pend = NULL;
    pfirst = Head;
    psecond = Head;
    int temp;
    while (pfirst != pend)          //外循环
    {							   //pfirst != pend 很有意思
        while (pfirst->next != pend)//内循环
        {
            if (pfirst->score[n] > pfirst->next->score[n])
            {
                temp = pfirst->score[n];
                pfirst->score[n] = pfirst->next->score[n];
                pfirst->next->score[n] = temp;
            }
            pfirst = pfirst->next;
        }
        pend = pfirst;//减少最后的已排好的循环
        pfirst = Head;
    }
    printf("done.\n");
    OutputL(Head);
    return Head;
}
//*********

void secL() { 

    int cn = 0, ss = 0, st = 0;
    char s = 0, senu = 0;
    char strl[32];
    stul* head = {};

    printf("************************************************************************************\n");
    printf("                           ***请输入对应数字来继续使用***\n");
    printf("\t1:CreateList\n");
    printf("\t2:Output\n");
    printf("\t3:Save\n");
    printf("\t4:Fetch\n");
    printf("\t5:Search_num\n");
    printf("\t6:InsertList\n");
    printf("\t7:Delete_num\n");
    printf("\t8:Search_major_subject_score\n");
    printf("\t9:Delete_class_subject\n");
    printf("\te:to exit\n");
    printf("************************************************************************************\n");

    while(TRUE){
        scanf_s("%c", &senu);
        if (senu == '\n') {
            continue;
        }
        switch (senu) {
        case '1': 
            printf("正在执行创建\n");
            head = CreateList(head);  break;
        case '2': OutputL(head); break;
        case '3': 
            printf("正在执行储存\n");
            SaveL(head); break;
        case '4': 
            //file
            printf("请输入查找文件的位次\n");
            scanf_s("%d", &cn);
            FetchL(cn); break;
        case '5':
            printf("请输入查找的学号\n");
            scanf_s("%d", &cn);
            Search_num(head, cn); break;
        case '6': 
            printf("正在执行插入\n");
            InsertList(head); break;
        case '7': 
            printf("请输入需要删除的学号\n");
            scanf_s("%d", &cn); 
            head = Delete_num(head, cn); break;
        case '8': 
            printf("请输入专业、课程序号和比较分数\n");
            scanf_s("%s", strl, 15);
            scanf_s("%d", &ss);
            scanf_s("%d", &cn);
            Search_major_subject_score(head,strl,cn,ss); break;
        case '9': 
            printf("请输入班级、课程序号和比较分数\n");
            scanf_s("%d", &st);
            scanf_s("%d", &ss);
            scanf_s("%d", &cn);
            Delete_class_subject(head,st,cn,ss); break;
        case 'e':
        case 'E':exit(0); break;
        default:printf("error");
        }
    }
    /*
    while (1) {
        scanf_s("%c", &senu);
        if (senu == '\n') { continue; }
        stul* st=NULL;
        switch (senu) {
        case'1': st = storeL();  break;
        case'2':
            if (st != NULL) {
                OutputL(st);
            }
            else printf("erro\n"); break;
        case'3': st = storeL();  break;
        case'4': if (st != NULL) {
            printf("请输入查询的学生专业、总分和条件\n");
            scanf_s("%s", str);
            scanf_s("%d", &ss);
            scanf_s("%c", &s);
            sear(st, str, ss, s);
        }
               else printf("erro\n");  break;
        case'5':  if (st != NULL) {
            printf("请输入需要排序的成绩序号\n");
            scanf_s("%d", &ss);
            sortl(st, ss);
        }
               else printf("erro\n");   break;
        case'e':
        case'E':exit(1); getchar(); break;
        default:printf("未知代号，请重新输入\n"); break;
        }
    */ 
}

int main(){
    int length = 0;
    //int j = 0, i = 0;
    void read();
    void welcome();
    void section();
    void Input(STU * p, int n);
    void Output(STU* p);
    STU Fetch(int studentIndex);
    void Search(STU* p, int classNo, char s, int scoreSum);
    int Max(STU* p, int scoreIndex);
    void Sort_select(STU* p);
    void Sort_buble(STU* p);
    void Sort_insert(STU* p, int n, char* major);
    void Savet(STU* p, int n);
    void store();

    welcome();
    swi();
    if (swflag == 1) {
        printf("linklist model ON\n");
        secL();
    }
    else if(swflag == 2) {
        printf("list model ON\n");
        store();
        section();
    }
    else {
        printf("erro!\n");
        exit(-2);//-2：未知错误
    }
    while (1) { 
        char c;
        scanf_s("%c", &c);
        if (c == '\n') { continue; }
        switch (c) {
        case '1':
            printf("请输入学生数量\n");
            scanf_s("%d", &length);
            //stu = (STU*)malloc(sizeof(STU) * length);
            printf("正在尝试新建文件......\n");
            Input(stu, length);
            /* while (j++ < 10)
              {
                  printf("这是第%d次输出------", j);
                  for (i = 0; i < 1000000000; i++);
                  printf("\r");
              }j = 0;*/; break;
        case '2':  Output(stu); ; break;
        case '3':
            printf("清输入要查询的学生位次\n");
            scanf_s("%d", &ai);
            STU st = Fetch(ai);
            printf("num:%s name:%s major:%s classNo:%d score:%d %d %d\n", st.num, st.name, st.major, st.classNo, st.score[0], st.score[1], st.score[2]);
            break;
        case '4':
            printf("请依次输入要查询学生的班级、条件（<、>）和用来比较的总分\n");
            scanf_s("%d", &ai);
            scanf_s("%c", &cc);
            scanf_s("%d", &ae);
            Search(stu, ai, cc, ae); 
            break;
        case '5':
            printf("清输入要查询的学生的学科序号（1-3）\n");
            scanf_s("%d", &ai);
            printf("目标学科最高分学生序号：%d", Max(stu, ai)); 
            break;
        case '6':
            printf("选择排序中...\n");
            Sort_select(stu); 
            break;
        case '7':
            printf("冒泡排序中...\n");
            Sort_buble(stu); 
            break;
        case '8':
            printf("请依次输入要排序学生的专业和学科序号\n");
            scanf_s("%s", strt, 32);
            scanf_s("%d", &ai);
            printf("插入排序中...\n");
            Sort_insert(stu, ai, str); 
            break;
        case '9':
            Savet(stu,ai); 
            break;
        case 'E':
        case 'e':exit(-1); break;
        case 'r':read(); break;
        default:putchar(c);  printf("unknow input!\n");
        }
    }
    return 0;
}
void read() {
    /*
    
    FILE * fp;
	if ((fp = fopen(filename, "r")) == NULL) return 0;
	//从文件读取信息 
	while (fscanf(fp, "%s %s %s %d %d %d %d ", &stu[j].StudentId, &stu[j].StudentName, &stu[j].StudentAge, &stu[j].StudentSex, &stu[j].score[0], &stu[j].score[1], &stu[j].score[2]) == 7) {
		j++;
	}
    
*/
    stup = (STU*)malloc(sizeof(STU));
    if (fopen_s(&f, "student.dat", "r")) {
        printf("erro\n");
    }
    else {
        while (!fscanf_s(f, "%s %s %s %d %d %d %d", stup->num, 15, stup->name, 15, stup->major, 10, &stup->classNo, &stup->score[0], &stup->score[1], &stup->score[2])) {
            stup++;
        }
        fclose(f);
        flag = 1;
        for (int n = 0; n < N; n++) {
            stu[n] = stup[n];
        }
    }
}
void store() {
    printf("                             *****请先录入学生信息*****\n");
    STU* sp = stu;
    for (; sp < stu + N; sp ++) {
        printf("\t请输入学生学号\n");
        scanf_s("%s", sp->num, 15);
        printf("\t请输入学生姓名\n");
        scanf_s("%s", sp->name, 15);
        printf("\t请输入学生专业\n");
        scanf_s("%s", sp->major, 10);
        printf("\t请输入学生班级\n");
        scanf_s("%d", &sp->classNo);
        printf("\t请输入学生成绩\n");
        for (int l = 0; l < 3; l ++) {
            scanf_s("%d", &sp->score[l]);
        }
    }
    printf("                                   ***录入完成***\n");
}
void welcome() {
    printf("****************************");
    printf("**欢迎使用学生信息录入系统**");
    printf("****************************\n");
}
void section() {
    printf("************************************************************************************\n");
    printf("                           ***请输入对应数字来继续使用***\n");
    printf("\t1:Input\n");
    printf("\t2:Output\n");
    printf("\t3:Fetch\n");
    printf("\t4:Search\n");
    printf("\t5:Max\n");
    printf("\t6:Sort_select\n");
    printf("\t7:Sort_buble\n");
   // printf("\t8:Sort_insert\n");
    printf("\t9:Savet\n");
    printf("\te:to exit\n");
    printf("************************************************************************************\n");

}
void Input(STU* p, int n) {
    
    STU* tp = p;
    if (fopen_s(&f, "student.dat", "r")) {
        printf("读取失败！\n");
    }
    else {
        for (; tp < p + n; tp++) {
            fscanf_s(f, "%d", tp->num);
            fscanf_s(f, "%s", tp->name);
            fscanf_s(f, "%s", tp->major);
            fscanf_s(f, "%d", tp->classNo);
            for (int k = 0; k < 3; k++) {
                fscanf_s(f, "%d", tp->score[k]);
            }
        }
        fclose(f);
        printf("读取完毕，请进行下一步操作\n");
    }
}
/*
 *将p所指的某个学生信息表格化屏幕输出。
 */
void Output(STU* p) {
    STU* sp = p; 
    printf("************************************************************************************\n");
    printf("student num:");
    for (; sp < p + N; sp++) {
        printf("%s\t", sp->num);
    }
    putchar('\n');
    printf("student name:");
    sp = p;
    for (;  sp < p + N; sp++) {
        printf("%s\t", sp->name);
    } 
    putchar('\n');
    sp = p; 
    printf("student major:");
    for (; sp < p + N; sp++) {
        printf("%s\t", sp->major);
    }
    putchar('\n');
    sp = p;
    printf("student classNo:");
    for (; sp < p + N; sp++) {
        printf("%d\t", sp->classNo);
    }
    putchar('\n');
    sp = p;
    for (int i = 0; i < 3; i++) {
        printf("student score:");
        for (; sp < p + N; sp++) {
            printf("%d\t", sp->score[i]);
        }
        putchar('\n');
        sp = p;
    }
    printf("************************************************************************************\n");
    printf("输出完毕\n");
    /*
    
    */
}
/*
*从文件中随机读取第studentIndex个(0<= studentIndex <=N-1)学生的信息
*/
STU Fetch(int studentIndex) { 
    STU ps = { "unknow", "admin", "unknow", -1, {0, 0, 0} };
    char ch = 0;
    if (flag) {
         if (fopen_s(&f, "student.dat", "r")) {
             printf("读取失败！\n");
         } else {
             for (int i = 1; i < studentIndex; i ++){
                 for (int in = 0; in < 7; ) {
                    if (EOF == fscanf_s(f, "%c", ch));
                    if (ch == '\n') {
                        in++;
                    }
                    }
                        
             }//for stuindex
         }//if else
         //从文件读取信息
         for(int y = 0;y <= studentIndex;y++)
         fscanf_s(f, "%s %s %s %d %d %d %d\n", ps.num,15, ps.name,15, ps.major,15, &ps.classNo, &ps.score[0], &ps.score[1], &ps.score[2]);
         /*
          fscanf_s(f, "%s", St.num);
         fscanf_s(f, "%s", St.name);
         fscanf_s(f, "%s", St.major);
         fscanf_s(f, "%d", &St.classNo); 
         for (int i = 0; i < 3; i++) {
            fscanf_s(f, "%d", St.num[i]);
         }
         */
        
    }
    else {
        printf("数据未存储\n");
        return ps;
    }
    return ps;
}
/*
*实现班级和成绩的综合查找（如1班，总分>240的同学）。
*/
void Search(STU* p, int classNo, char s, int scoreSum) {
    int index[N];
    STU* sp = p;
    int in = 0;
    for (; sp < p + N; sp++) {
        if (sp->classNo == classNo) {
            int tempSum = 0;
            for (int h = 0; h < 3; tempSum += sp->score[h++]);
            switch (s) {
            case '>': if (tempSum > scoreSum) { 
                    printf("%15s\t", sp->num);
                    printf("%15s\t", sp->name);
                    printf("%s\t", sp->major);
                    printf("%d\t", sp->classNo);
                for (int i = 0; i < 3; i++) {
                        printf("%d\t", sp->score[i]);
                    }
                    putchar('\n');
            }break;
            case '<':if (tempSum > scoreSum) {
                    printf("%15s\t", sp->num);
                    printf("%15s\t", sp->name);
                    printf("%s\t", sp->major);
                    printf("%d\t", sp->classNo);
                    for (int i = 0; i < 3; i++) {
                        printf("%d\t", sp->score[i]);
                    }
                    putchar('\n');
            }break;
            default:printf("出现错误\n");
            }
           
        }
    }
}
/*
*求所有学生、下标为scoreIndex的课程分数最高的学生序号（在数组中的下标），学生序号作为返回值。
*
    int h = 0;
    for (int i = 0; i < N - 1; i++) {
        int tempSum1 = 0, tempSum2 = 0;
        for (h = 0; tempSum1 += p->score[h]; h++);
        for ( h = 0; tempSum1 += (++p)->score[h]; h++);
        if (tempSum1 > tempSum2) {
            St = *(p - 1);
        }else {
            St = *p;
        }
    }*/
int Max(STU* p, int scoreIndex) {
    STU* stt = p;
    STU* St=(STU*)malloc(sizeof(STU));// = { "unknow", "admin", "unknow", -1, {0, 0, 0} };
    if (scoreIndex > 3) {
        printf("序号错误！\n");
        return -1;
    }
    else {
        for (; stt <p + N; stt++) {
                if (stt->score[scoreIndex-1] > (1+stt)->score[scoreIndex-1]) {
                    St = (stt );
                  //  printf("k%d\t", St->classNo);
                }else {
                    St = (stt+1);
                    //printf("kk%d\t", St->classNo);
                }
            }
        //printf("Sk%d\t", St->classNo);
        //return St->classNo;
    }
   
    if (St->classNo != -1&& St->classNo != 0) {
        return St->classNo;
    }else {
        printf("未知错误！\n");
        return -1;
    }
       
}
/*
*对所有学生，按平均成绩由低到高进行简单选择排序。
*/
void Sort_select(STU* p) {
    STU temp;
    int h = 0;
    for (int i = 0; i < N; i++) {
        int j = i;
        for (int k = i + 1; k < N - 1; k++) {
            int tempSum1 = 0, tempSum2 = 0;
            for (h = 0; h < 3; tempSum1 += p->score[h++]);
            for (h = 0; h < 3; tempSum1 += (++p)->score[h++]);
            if (tempSum1 > tempSum2) {
                j = k;
            }
        } 
            if (i != j) {
                 temp = p[i];
                 p[i] = p[j];
                 p[j] = temp;
            }
    }
    printf("选择排序完成！\n");
}
/*
*)对某个班级的学生，按平均成绩由高到低进行起泡排序。并调用Output输出。
*定义局部变量：
*STU stu_class_ave[N]; //按平均成绩排序后的某个班级的学生信息；
* //实际元素个数
*/
void Sort_buble(STU* p) {
    STU* stu_class_ave = p;
    int count;
    int i, j, k, h;
    STU temp;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N - i - 1; j++) {
            int tempSum1 = 0, tempSum2 = 0;
            for (h = 0; h<3; tempSum1 += p->score[h++]);
            for (h = 0; h<3; tempSum2 += (++p)->score[h++]);
            if (tempSum1 < tempSum2) {
                temp = stu_class_ave[j];
                stu_class_ave[j] = stu_class_ave[j + 1];
                stu_class_ave[j + 1] = temp;
            }
        }
    }
    printf("冒泡排序完成\n");
    Output(stu_class_ave);
}
/*
*对某个专业的学生，按某门课程成绩由低到高进行直接插入排序。并调用Output输出。
*定义局部变量：
*STU stu_class_ subject [N]; //按某门课程成绩排序后的某个专业的学生信息；
*int count; //实际元素个数
*/
void Sort_insert(STU* p, int n, char* major) {
    STU stu_class_subject[N];
    int count = 0;
    int i, j, k;
    STU temp;
    for(int ind = 0; ind < N; ind++, p++)
        if (p->classNo == n) {
            stu_class_subject[count++] = *p;
        }
    for (i = 1; i < N; i++) {
        temp = stu_class_subject[i];
        j = i;
        if (stu_class_subject[j - 1].score[n] > temp.score[n])
            while (j >= 1 && stu_class_subject[j - 1].score[n] > temp.score[n]) {
                stu_class_subject[j] = stu_class_subject[j - 1];
                j--;
            }
        stu_class_subject[j] = temp;
    }
    printf("插入排序完成\n");
    Output(stu_class_subject);
}
/*
*将学生信息存入文件。
*/ 
/*
         for (; !p; p++) {
            fputs(p->num, f);
            fputs("\n", f);
            fputs(p->name, f);
            fputs("\n", f);
            fputs(p->major, f);
            fputs("\n", f);
            fprintf(f, "%d", p->classNo);
            fputs("\n", f);
            for (int j = 0; j < 3; j++) {
                fprintf(f, "%d", p->score[j]);
                fputs("\n", f);
            }
        }
         */
void Savet(STU* p,int n) {
    STU* ps = p;
    if (fopen_s(&f, "student.dat", "w")) {
        printf("新建文件失败！\n");
    }
    else {
        for (; ps < p+N; ps++) {
            fprintf(f, "%s %s %s %d %d %d %d\n", ps->num, ps->name, ps->major, ps->classNo, ps->score[0], ps->score[1],ps->score[2]);
        } 
    }
    fclose(f);
    flag = 1;
    printf("数据存储完毕！\n");
}