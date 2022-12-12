// DSExp2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
串模式匹配实验
*/
#include <iostream>

void Titlem();
void BFalgorithm(char* str, char* mod, int loc);
void KMPalogrithm(char* str, char* mod, int loc,int* next);
void KMPplusAlogrithm(char* str, char* mod, int loc,int* nextval);
void next(char* mod,int next[]);
void nextv(char* mod,int nextval[]);

int sizestr = 32, sizemod = 8;

int main()
{
    char flag = 1;
    int loc = 0;
    bool fl = 0;
    char str[] = "asdasghjkszjhsbxhsnsmsnxhskajzsn";
    char mod[] = "jhsbxhsn";
    Titlem();
    int n[8];
    while (flag) {
        switch (getchar()) {
        case '0':flag = 0; break;
        case '1':
            printf("Enter the first location of the string:\t");
            scanf_s("%d", &loc);
            loc--;
            fl = 1; printf("Please enter number to choose the funcation\n"); break;
        case '2':if (fl) {
            BFalgorithm(str, mod, loc);
        }
                else {
            printf("loc is needed\n");
        }; printf("Please enter number to choose the funcation\n"); break;
        case '3':if (fl) {
            next(mod, n);
            KMPalogrithm(str, mod, loc, n);
        }
                else {
            printf("loc is needed");
        } printf("Please enter number to choose the funcation\n"); break;
        case '4':if (fl) {
            nextv(mod, n);
            KMPalogrithm(str, mod, loc, n);
        }
                else {
            printf("loc is needed");
        }; printf("Please enter number to choose the funcation\n"); break;
        }
        getchar();//eat the keyborad
    }
    if(!flag){
        printf("the application has exited succefully\n");
        exit(0);
    }
    else {
        printf("An unknown error has occured!The application has exited in a wrong way.\n");
        exit(-2);
    }

}
void next(char* mod,int next[]) {
    int j = -1, co = 0, nu = 0;//co* figure out whether the alogrithm is done.
    next[0] = -1;
    while (nu < sizemod - 1) {
        if (j == -1 || mod[nu] == mod[j]) {
            nu++;
            j++;
            next[nu] = j;
        }
        else {
            j = next[j];
        }
    }
    printf("the next array generated\n");
    for (int x = 0; x < 8;x++) {
        printf("%d,", next[x]);
    }
    putchar('\n');
}
void nextv(char* mod, int nextval[]) {
    int i = -1, p = 0;//p fast ;i slow
    nextval[0] = -1;
    while (p < sizemod - 1) {
        if (i == -1 || mod[p] == mod[i]) {
            p++;
            i++;
            if (mod[i] != mod[p]) {

                nextval[p] = i;
            }
            else {
                nextval[p] = nextval[i];
            }
        }
        else {
            i = nextval[i];
        }
    }
    printf("the next array generated\n");
    for (int x = 0; x < 8; x++) {
        printf("%d,", nextval[x]);
    }
    putchar('\n');
}
void Titlem() {

    for (int coun = 0; coun < 64; coun++) {
        printf("*");
    }
    putchar('\n');
    putchar('\n');
    //*****
    printf("\t1 >>>>> Enter the first location of the string\n");
    printf("\t2 >>>>> Native pattern matching algorithm\n");
    printf("\t3 >>>>> KMP algorithm\n");
    printf("\t4 >>>>> KMP improved algorithm\n");
    printf("\t0 >>>>> EXIT\n");
    putchar('\n');
    for (int coun = 0; coun < 64; coun++) {
        printf("*");
    }
    putchar('\n');
    printf("Please enter number to choose the funcation\n");
    //*****
}
void BFalgorithm(char* str, char* mod,int loc) {
    int sizeS = sizestr;
    int i = 0, k = 0;
    int count = 0;
    if (loc < 0 || loc>sizeS) {
        printf("loc is illegality\n");
        exit(-1);
    }
    for (i = loc; i < sizeS&& k < sizemod; i++, k++) {
        count++;
            if (str[i] == mod[k]) {
                printf("str->> %c || mod->> %c\n",str[i],mod[k]);
            }
            else {
                printf("str->> %c || mod->> %c\n", str[i], mod[k]);
                i = i - k + 1;
                k = 0;
        }
        
    }

    if (k == sizemod) {
        printf("the location has successfully been found!\n");
        printf("the location is %d\n", i-k+1 );
        printf("the times are %d\n", count);

    }

}
void KMPalogrithm(char* str, char* mod, int loc,int next[]) {
    if (loc < 0 || loc>sizestr) {
        printf("loc is illegality\n");
        exit(-1);
    }
    int co = 0, i = 0;//co* figure out whether the alogrithm is done.
    while ( i < sizestr && co < sizemod-1 ) {
            if (str[i] == mod[co]||co == -1) {//attention that co can be zero
                if (co != -1) { 
                    printf("str->> %c || mod->> %c\n", str[i], mod[co]); 
                }
                else {
                    printf("str->> %c || mod->> %c\n", str[i], mod[co+1]);
                }//if 1
                co++;
                i++;
            }//if 2
            else {
                co = next[co];
            }
        
    }//while 
    if (co == sizemod - 1) {
        printf("the location has successfully been found!\n");
        printf("the location is %d\n", i - co + 1);
        printf("the times are %d\n", i);
    }

}
void KMPplusAlogrithm(char* str, char* mod, int loc,int* nextval) {
    if (loc < 0 || loc>sizestr) {
        printf("loc is illegality\n");
        exit(-1);
    }
    int is = 0, cos = -1;
    while( is < sizestr &&cos < sizemod - 1) {
            if (str[is] == mod[cos] || cos == -1) {//attention that co can be zero
                if (cos != -1) {
                    printf("str->> %c || mod->> %c\n", str[is], mod[cos]);
                }
                else {
                    printf("str->> %c || mod->> %c\n", str[is], mod[cos+1]);
                }
                cos++;
                is++;
            }
            else {
                //printf("test %d\t", cos);
                cos = nextval[cos];
            }
            //nextval[p]);
         if (cos == sizemod - 1) {
            printf("the location has successfully been found!\n");
            printf("the location is %d\n", is - cos + 1);
            printf("the times are %d\n", is);
            break;
        }//if
        
           
    }
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
