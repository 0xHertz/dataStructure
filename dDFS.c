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

void DFS(Graph * , int);
visit(int);
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
    for(i=0; i<head.numv; i++){
        if(!visited[i])
            DFS(head, i);
    }
    return 0;
}
/**
 * 主要是这两个函数， 其他函数的都是辅助， 省略不写
 * 递归算法
 * */
void DFS(Graph * G, int v){
    Vex w;
    visit(v);
    visited[v] = 1;
    for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w)){
        if(!visited[w]){
            DFS(G, w);
        }
    }
}
void visit(int v){
    printf("you have visited : %d", v);
}