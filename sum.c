# include<stdio.h>

struct node
{
    /* data */
    int data;
    struct node * lstr;
    struct node * rstr;
};
int * InitStack();
void Push(int*, struct node *);
void Pop(int*, struct node *);
bool IsEmpty(int *S);
struct node * CreateTree();
void visit(struct node * str);

int main(){
    struct node * Head, *p;
    int * S;
    S = InitStack();
    Head = CreateTree();
    p = Head;
    /**
     * 这就是主要的部分
     *  1. 沿着根入栈左孩子,(先序在这里访问) 直到左孩子为空
     *  2. 栈顶元素出栈(中序在这里访问)
     *  3. 入栈出栈元素的右孩子, 有的话继续1, 没有的话继续2
     * 
     * 后序的非递归遍历比较困难
     * */
    while(p || ! IsEmpty(S)){
        if(p){
            Push(S, p);
            visit(p);        //先序遍历把visit放在这
            p = p->lstr;
        }
        else{
            Pop(S, p);
            visit(p);        //中序遍历把visit放在这
            p = p->rstr;

        }
    }
    return 0;
}

int * InitStack(){
    int S[80]={-1, 0};
    return S
}

void Push(int * S, struct node * x){
    S = S+1;
    *(S) = x;
}
void Pop(int * S, struct node * x){
    *x = *S;
    S = S-1;
}
bool IsEmpty(int * S){
    if(*S == -1){
        return 1;
    }
    else{
        return 0;
    }
} 
struct node * Createtree(){
    struct node * hstr;
    return hstr;
}
void visit(struct node * str){
    printf("%d", str->data);
}