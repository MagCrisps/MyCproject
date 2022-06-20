#include <iostream>
#define N 1

typedef struct Student {
    char num[15];
    char name[15];
    char major[10];
    int classNo;
    int score[3];
}STU; 

STU stu[N];
FILE* f;
char flag = 0;
int ai = 0, ae = 0;
char cc = 0;
char* str = NULL;

int main(){
    int length = 0;
    //int j = 0, i = 0;

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
    store();
    section();
   
    while (1) { 
        getchar();
        char c = getchar();
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
              }j = 0;*/getchar(); break;
        case '2':  Output(stu); getchar(); break;
        case '3':
            printf("清输入要查询的学生位次\n");
            scanf_s("%d", &ai);
            Fetch(ai); getchar();
            break;
        case '4':
            printf("请依次输入要查询学生的班级、条件（<、>）和用来比较的总分\n");
            scanf_s("%d", &ai);
            scanf_s("%c", &cc);
            scanf_s("%d", &ae);
            Search(stu, ai, cc, ae); getchar();
            break;
        case '5':
            printf("清输入要查询的学生的学科序号（1-3）\n");
            scanf_s("%d", &ai);
            printf("目标学科最高分学生序号：%d", Max(stu, ai)); getchar();
            break;
        case '6':
            printf("选择排序中...\n");
            Sort_select(stu); getchar();
            break;
        case '7':
            printf("冒泡排序中...\n");
            Sort_buble(stu); getchar();
            break;
        case '8':
            printf("请依次输入要排序学生的专业和学科序号\n");
            scanf_s("%s", &str);
            scanf_s("%d", &ai);
            printf("插入排序中...\n");
            Sort_insert(stu, ai, str); getchar();
            break;
        case '9':
            Savet(stu,ai); getchar();
            break;
        case 'E':
        case 'e':exit(-1); break;
        default:putchar(c);  printf("unknow input!\n");getchar();
        }
    }
    return 0;
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
    printf("\t8:Sort_insert\n");
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
        printf("%15s\t", sp->num);
    }
    putchar('\n');
    printf("student name:");
    for (;  sp < p + N; sp++) {
        printf("%15s\t", sp->name);
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
    STU St = { "unknow", "admin", "unknow", -1, {0, 0, 0} };
    char ch = 0;
    if (flag) {
         if (fopen_s(&f, "student.dat", "r")) {
             printf("读取失败！\n");
         } else {
             for (int i = 1; i < studentIndex; i ++){
                 for (int in = 0; in < 7 ; ) {
                    if (EOF == fscanf_s(f, "%c", ch));
                    if (ch == '\n') {
                        in++;
                    }
                    }
                        
             }//for stuindex
         }//if else
         fscanf_s(f, "%s", St.num);
         fscanf_s(f, "%s", St.name);
         fscanf_s(f, "%s", St.major);
         fscanf_s(f, "%d", &St.classNo); 
         for (int i = 0; i < 3; i++) {
            fscanf_s(f, "%d", St.num[i]);
         }
    }
    else {
        printf("数据未存储\n");
        return St;
    }
    return St;
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
            for (int h = 0; tempSum += sp->score[h]; h++);
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
*/
int Max(STU* p, int scoreIndex) {
    STU St = { "unknow", "admin", "unknow", -1, {0, 0, 0} };
    if (scoreIndex > 3) {
        printf("序号错误！\n");
        return -1;
    }
    else {
        for (int i = 0; i < N - 1; i++) {
                if (p->score[scoreIndex-1] > (++p)->score[scoreIndex-1]) {
                    St = *(p - 1);
                }else {
                    St = *p;
                }
            }
    }
    
    
    /*
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
    if (St.classNo != -1) {
        return St.classNo;
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
            for (h = 0; tempSum1 += p->score[h]; h++);
            for (h = 0; tempSum1 += (++p)->score[h]; h++);
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
            for (h = 0; tempSum1 += p->score[h]; h++);
            for (h = 0; tempSum1 += (++p)->score[h]; h++);
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
void Savet(STU* p,int n) {
    if (fopen_s(&f, "student.dat", "w")) {
        printf("新建文件失败！\n");
    }
    else {
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
    }
    fclose(f);
    flag = 1;
    printf("数据存储完毕！\n");
}