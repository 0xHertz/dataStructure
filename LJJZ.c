# include<stdio.h>


# define MaxN 100
typedef struct{
    /* data */
    char v[MaxN];         //存储顶点, 实践中可以省略
    int e[[MaxN][MaxN]];  //邻接矩阵
    int nowv, nowe;       //当前图的节点数和边数
}Graph;

int main(){
    Graph G;
    scanf("input your v: %d", &G.nowv);
    scanf("input your e: %d", &G.nowe);
    return 0;
}