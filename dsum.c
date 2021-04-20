# include<stdio.h>
struct node * CreateTree(int);
struct node * NLR(struct node *);
void visit(struct node * str);

struct node{
    int data;
    struct node * lstr;
    struct node * rstr;
};

// typedef struct node node;

int main(){
    printf("Begin!!!\n");
    struct node * str;
    str = CreateTree(3);
    NLR(str);
    return 0;
}

struct node * CreateTree(int h){
    if (h == 1){
        struct node *str1, *str2, *head;
        int data, data2;

        str1 = (struct node * )malloc(sizeof(struct node));
        str2 = (struct node * )malloc(sizeof(struct node));
        head = (struct node * )malloc(sizeof(struct node));

        printf("input data\n");
        scanf("input data: %d", &data);
        str1->data = data;
        printf("done\n");

        printf("input data\n");
        scanf("input data: %d", &data2);
        str2->data = data2;
        printf("done!\n");

        head->lstr = str1;
        head->rstr = str2;
        return head;
    }
    else{
        CreateTree(h-1);
    }
}
void NLR(struct node * str){
    if (str == NULL){
        return 0；
    }
    else{
        visit(str);
        NLR(str->lstr);
        NLR(str->rstr);
    }
}

void LNR(struct node * str){
    if (str ==NULL){
        return 0;
    }
    else{
        LNR(str->lstr);
        visit(str);
        LNR(str->rstr);
    }
} 

void LRN(struct node * str){
    if (str ==NULL){
        return 0;
    }
    else{
        LRN(str->lstr);
        LRN(str->rstr);
        visit(str);
    }
} 
void visit(struct node * str){
    printf("%d", str->data);
}