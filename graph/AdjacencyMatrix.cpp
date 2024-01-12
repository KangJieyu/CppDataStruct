#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

/**
 * 无向图邻接矩阵的实现
*/

/* 基于邻接矩阵实现的无向图结构体*/
typedef struct {
    int vertices[MAX_SIZE]; // 顶点集
    int adjMat[MAX_SIZE][MAX_SIZE]; // 边集
    int size; // 顶点个数
} GraphAdjMat;

/* 构造函数 */
GraphAdjMat *newGraphAdjMat() {
    GraphAdjMat *graph = (GraphAdjMat *) malloc(sizeof(GraphAdjMat));
    graph->size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            graph->adjMat[i][j] = 0;
        }
    }
    return graph;
}


void delGraphAdjMat(GraphAdjMat *graph) {
    free(graph);
}

/* 添加顶点 */
void addVertex(GraphAdjMat *graph, int val) {
    if (graph->size == MAX_SIZE) {
        printf("%s\n", "图的顶点数量已达最大！");
        return ;
    }
    int n = graph->size; // 添加第 n 个顶点
    graph->vertices[n] = val; // 顶点值
    for (int i = 0; i <= n; i++) {
        graph->adjMat[n][i] = graph->adjMat[i][n] = 0; // 将第 n 行和列置 0
    }
    graph->size++;
}

/* 删除索引为 index 的顶点 */
void removeVertex(GraphAdjMat *graph, int index) {
    if (index < 0 || index >= graph->size) {
        printf("%s\n", "删除的顶点不存在！");
        return ;
    }
    // 在顶点集中移除 index 的顶点
    for (int i = index; i < graph->size-1; i++) {
        graph->vertices[i] = graph->vertices[i+1];
    }
    // 在边集中删除对应的行 
    for (int i = index; i < graph->size-1; i++) {
        for (int j = 0; j < graph->size; j++) {
            graph->adjMat[i][j] = graph->adjMat[i+1][j];
        }
    }
    // 在边集中删除对应的列
    for (int i = index; i < graph->size-1; i++) {
        for (int j = 0; j < graph->size; j++) {
            graph->adjMat[j][i] = graph->adjMat[j][i+1];
        }
    }
    graph->size--; // 顶点个数少一
}

/* 添加边 */
// i、j 分别为顶点的索引
void addEdge(GraphAdjMat *graph, int i, int j) {
    if (i < 0 || j < 0 || i >= graph->size || j >= graph->size) {
        printf("%s\n", "添加边连接的顶点不存在或相等！");
        return ;
    }
    graph->adjMat[i][j] = 1;
    graph->adjMat[j][i] = 1;
}

/* 删除边 */
// i、j 分别为顶点的索引
void removeEdge(GraphAdjMat *graph, int i, int j) {
    if (i < 0 || j < 0 || i >= graph->size || j >= graph->size || i == j) {
        printf("%s\n", "删除边连接的顶点不存在或相等！");
        return ;
    }
    graph->adjMat[i][j] = 0;
    graph->adjMat[j][i] = 0;
}

/* 打印数组 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

/* 输出邻接矩阵信息 */
void printMat(GraphAdjMat *graph) {
    printf("%s\n", "顶点集合：");
    printArray(graph->vertices, graph->size);
    printf("邻接矩阵：\n");
    for (int i = 0; i < graph->size; i++) {
        printArray(graph->adjMat[i], graph->size);
    }
}

int main(int argc, char const *argv[])
{
    GraphAdjMat *graph = newGraphAdjMat();
    addVertex(graph, 1); // 0
    addVertex(graph, 2); // 1
    addVertex(graph, 3); // 2
    addVertex(graph, 4); // 3
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);

    printMat(graph);
    
    // removeEdge(graph, 0, 2);
    // printf("\n\n");
    // printMat(graph);

    removeVertex(graph, 1); // 删除索引为0的顶点
    printf("\n\n");
    printMat(graph);

    return 0;
}
