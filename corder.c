# include<stdio.h>

struct node
{
    /* data */
    int data;
    struct node * lstr;
    struct node * rstr;
};
int * InitQueue();
bool IsEmpty(int * );
void EnQueue(int * , struct node * );
void DeQueue(int * , struct node * );

struct node * CreateTree();

void visit(struct node * str);

int main(){
    struct ndoe * Head, *p;
    int * Q;
    Q = InitQueue();
    Head = CreateTree();

    /**
     * 
     * */
    EnQueue(Q, Head);
    while (! IsEmpty(Q)){
        DeQueue(Q, p);
        visit(p);
        if(p->lstr != NULL){
            EnQueue(Q, p->lstr);
        }
        if(p->rstr != NULL){
            EnQueue(Q, p->rstr);
        }
    }
    
    return 0;
}