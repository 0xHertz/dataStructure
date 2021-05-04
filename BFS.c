# include<stdio.h>
# define MaxV 100

/**
 * 采用多重邻接表描述图
 * */
typedef struct{
    bool mark;
    int ivex, jvex;
    Edge ilink, jlink;
}Edge;

typedef struct{
    int index;
    Edge firstlink;
}Vex;

typedef struct{
    int numv, nume;
    Vex * str;
}Graph;

bool visited[MaxV];
int * Q;

Graph * createGraph(int , int);
void BFS(Graph *, int);
void visit(int);

int * InitQueue();
void EnQueue(int * , int);

int main(){
    int v, e;
    int i;

    Graph * head;
    printf("-----------------create-------------------");
    scanf("%d", &v);
    scanf("%d", &e);
    head = createGraph(v, e);
    printf("-------------------BFS--------------------");

    /**
     * 这里开始进行遍历
     * */
    for (i=0; i<head.numv; i++){
        visited[i] = 0;                //全部设置未未访问
    }
    Q = InitQueue();                   //初始化队列
    for(i=0; i<head.numv; i++){
        if(!visited[i])
            BFS(head, i);
    }

    return 0;
}
int * InitQueue(){
    int Q[100] = {0};
    return Q;
}
void EnQueue(int * Q, int i){
    *Q = i;
    Q++;
}
Graph * createGraph(int v, int e){
    Graph G;
    int i;
    Vex vex[v];
    G.nume = e;
    G.numv = v;
    //接下来就是声名边节点， 并把这些边节点的指针设置好， 不写了
}

/**
 * 主要是这两个函数， 上面的都是辅助
 * 使用到队列， 不是递归哦， 不要想成递归了
 * */

void BFS(Graph * G, int v){
    Vex w;
    visit(v);              //访问i节点
    visited[v] = 1;        //标记为访问过
    EnQueue(Q, v);         //顶点入队列
    while(!isEmpty(Q)){
        DeQueue(Q, v);
        for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w)){   //这个for循环用来检查v所有的邻接节点
            if(!visited[w]){
                visit(w);
                visited[w] = 1;
                EnQueue(Q, w);
            }//if
        }//for
    }//while
}
void visit(int i){
    print("you have visited : %d", i);
}