# include<stdio.h>
struct node{
    int data;
    struct node *lstr, *rstr;
    int ltag, rtag;
};

void LNRindex(struct node *, struct node*);
void NLRindex(struct node *, struct node*);
void LRNindex(struct node *, struct node*);
struct node * CreateTree();
int main(){
    struct node * Head, * pre=NULL, * p;
    Head = CreateTree();
    /**
     * 中序线索化
     * */
    LNRindex(Head, pre);
    pre->rstr = NULL;
    pre->rtag=1;

    /**
     * 先序线索化
     **/
    NLRindex(Head, pre);
    pre->rstr = NULL;
    pre->rtag=1;
    /**
     * 后序线序化
     **/
    LRNindex(Head, pre);
    pre->rstr = NULL;
    pre->rtag=1;
    
    return 0;
}
void LNRindex(struct node * p , struct node* pre) {
    if(p == NULL){
        return 0;
    }
    else{
        LNRindex(p->lstr, pre);
        if(p->lstr == NULL){
            p->lstr = pre;
            p->ltag = 1;
        }
        if(pre != NULL && pre->rstr == NULL){
            pre->rstr = p;
            pre->rtag = 1;
        }
        LNRindex(p->rstr, pre);
    }
}
void NLRindex(struct node *, struct node*){
    if(p == NULL){
        return 0;
    }
    else{
        if(p->lstr == NULL){
            p->lstr = pre;
            p->ltag = 1;
        }
        if(pre != NULL && pre->rstr == NULL){
            pre->rstr = p;
            pre->rtag = 1;
        }
        NLRindex(p->lstr, pre);
        NLRindex(p->rstr, pre);
    }
}
void LRNindex(struct node *, struct node*){
    if(p == NULL){
        return 0;
    }
    else{
        LRNindex(p->lstr, pre);
        LRNindex(p->rstr, pre);
        if(p->lstr == NULL){
            p->lstr = pre;
            p->ltag = 1;
        }
        if(pre != NULL && pre->rstr == NULL){
            pre->rstr = p;
            pre->rtag = 1;
        }
    }
}