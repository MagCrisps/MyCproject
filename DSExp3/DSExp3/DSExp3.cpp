// DSExp3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//数据结构实验三 二叉树

#include <iostream>

typedef struct node{
    char data;
    struct node* lch,* rch;
}BinNode,*Bintree;
typedef struct bone {
    Bintree* base;
    int front; 
    int rear;
}qqueue;
void menu();
int Binbuilt(Bintree& T);
void preorder(Bintree& T);
void midorder(Bintree& T);
void postorder(Bintree& T);
void floororder(Bintree& T);
void findpath(Bintree& T,char x);

int flag = 0;

int main()
{
    Bintree T = NULL;
    char cr = 0;
    char x = 0;
    menu();
    while (cr = getchar()) {
        switch (cr) {
        case '0':exit(0); break;
        case '1':
            if (Binbuilt(T))
                printf("\nbintree has been built\n");
            else
                printf("error\n");
            break;
        case '2':preorder(T);
            printf("\npreorder has finished\n");
            break;
        case '3':midorder(T);
            printf("\nmidorder has finished\n"); 
            break;
        case '4':postorder(T);
            printf("\npostorder has finished\n"); 
            break;
        case '5':floororder(T); 
            printf("\nfloororder has finished\n"); 
            break;
        case '6':
            printf("please enter the char you want to find:\n");
            x = getchar();
            if (x == '\n') {
                x = getchar();
            }
            findpath(T,x);
            printf("\nfindpath has finished and the result is:");
            if (flag) {
                printf("\tfound!\n");
            }
            else {
                printf("\thad not found\n");
            }
            flag = 0;
            break;
        }
        
    }
}

//ABC##DE#G##F###
void push(qqueue& qe,Bintree e) {
    if ((qe.rear + 1) % 15 == qe.front)exit(-1);
    qe.base[qe.rear] = e;
    qe.rear = (qe.rear + 1) % 15;
}
void pop(qqueue& qe,Bintree& e) {
    if (qe.front == qe.rear)exit(-1);
    e = qe.base[qe.front];
    qe.front = (qe.front + 1) % 15;

}
void menu() {
    for (int i = 0; i < 64; i++) {
        printf("*");
    }
    putchar('\n');
    printf("\t0 >>>>> EXIT \n");
    printf("\t1 >>>>> Establish binary tree storage structure\n");
    printf("\t2 >>>>> Find the preorder traversal of binary tree\n");
    printf("\t3 >>>>> Find the middle order traversal of binary tree\n");
    printf("\t4 >>>>> Post order traversal of binary tree\n");
    printf("\t5 >>>>> Find the hierarchical traversal of binary tree\n");
    printf("\t6 >>>>> Find the path of a given node\n");//
    for (int i = 0; i < 64; i++) {
        printf("*");
    }
    putchar('\n');
}
int Binbuilt(Bintree& T) {
    
    char ch = getchar();
    if (ch == '\n') {
        ch = getchar();
    }
    if (ch == '#') {
        T = NULL;
    }else if (ch == '^') {
        return 2;
    }
    else {
        T = (Bintree)malloc(sizeof(BinNode));
        if (!T)exit(-1);
        T->data = ch;
        Binbuilt(T->lch);
        Binbuilt(T->rch);

    }
    return 1;
    //please add a attation to reminder people that the tree has finished.
}
void preorder(Bintree& T) {
    if (T) {
        printf("%c\t", T->data);
        preorder(T->lch); 
        preorder(T->rch);
    }

}
void midorder(Bintree& T) {
    if (T) {
       
        midorder(T->lch);
        printf("%c\t", T->data);
        midorder(T->rch);
    }

}
void postorder(Bintree& T) {
    if (T) {
      
        postorder(T->lch);
        postorder(T->rch);
        printf("%c\t", T->data);
    }
}
void floororder(Bintree& T) {
    Bintree queue[15];
    Bintree e;
    int front = 0, rear = 0;
    qqueue qe;
    qe.base=(Bintree*)malloc(sizeof(BinNode)*15);
    qe.front = qe.rear = 0;
    push(qe, T);
    while (qe.front!=qe.rear) {
        pop(qe, e);
        if(e->lch)
            push(qe, e->lch);
        if(e->rch)
            push(qe, e->rch);
    }
    qe.front = 0;
    while (qe.front != qe.rear) {
        pop(qe, e);
        printf("%c\t", e->data);
    }  
}
void findpath(Bintree& T,char x) {
    if (!T);
    else 
        if (T->data == x) {
            printf("%c\t", T->data);
            flag = 1;
    }
    else
    {
            printf("%c\t", T->data);
            if (T->lch) {
                findpath(T->lch, x);
        }
            if (T->rch) {
                findpath(T->rch, x);
            }
    }
}
