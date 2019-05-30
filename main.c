#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_SIZE 100			//MAX vertex numbers
#define MAX_EDGE_SIZE 500			//MAX edge numbers


typedef struct edge {
    int src, des;
    int weight;
}edge;								//struct for edge

edge* graph[MAX_EDGE_SIZE];			//original graph data is stored in here
int set[MAX_VERTEX_SIZE];			//set data stored(used to check if loop happens in tree)
edge* kruskalGraph[MAX_EDGE_SIZE];	//MST data stored in here

void addNode(int, int, int);		//add node into graph[]
void sort();						//sort edges in ascending order
int find(int);						//find root node of input graph
void unionSet(int, int);			//union operation for graph
void kruskal(int);					//kruskal function


int graphcnt = 0;					//total edges in graph

int main() {
    int vercnt = 0;					//total vertices in graph
    int cnt = 0;

    for (int i = 0; i < MAX_VERTEX_SIZE + 1; i++)
        set[i] = -1;				//initializing



    printf("Enter number of vertexes. Index of vertex starts from 0.: ");
    scanf("%d", &vercnt);

    for (int i = 0; i < vercnt; i++)
        set[i] = i;					//initializing vertices with meaningful value

    for (int i = 0; i < vercnt; i++) {
        int edge = 0, weight = 0;
        printf("Enter edges connected to vertex %d and weights: ", i);
        while (1) {
            scanf("%d %d", &edge, &weight);
            if (edge == -1)			//if -1 -1 is given as input, we consider all edges connected to higher vertices were considered
                break;              //and move to next edges. ALL input should be written once, from "lower vertice" to "higher vertice"
                                    //for example, if 1<->3(weight 5) is in graph, we should input 3 5 in vertex 1 input, and ignore in vertex 3 input.
            addNode(i, edge, weight);
        }
    }

    printf("Input Graph: \n");
    for (int i = 0; i < graphcnt; i++) {
        printf("%d <-> %d, %d\n", graph[i]->src, graph[i]->des, graph[i]->weight);		//displays input graph information
    }
    sort();		//sort input edges in ascending order

    kruskal(vercnt);		//kruskal algorithm
}

void addNode(int idx, int edge1, int weight1){
    edge* temp = malloc(sizeof(edge));

    temp->src = idx;
    temp->des = edge1;
    temp->weight = weight1;
    graph[graphcnt++] = temp;
}

void sort() {
    int i, j, min;
    edge* temp;
    for (i = 0; i < graphcnt - 1; i++) {
        min = i;
        for (j = i + 1; j < graphcnt; j++) {
            if (graph[j]->weight < graph[min]->weight)
                min = j;
        }
        temp = graph[i];
        graph[i] = graph[min];
        graph[min] = temp;
    }
}

int find(int i) {
    for (; i != set [i]; i = set[i]);
    return i;
}

void unionSet(int i, int j) {
    find(i);
    set[i] = j;
}

void kruskal(int vercnt) {
    int tempcnt = vercnt;
    int kruscnt = 0;
    int cnt = -1;
    while (kruscnt < vercnt - 1 && graphcnt > 0) {			//kruskal algorithm's iteration condition
        edge* temp = graph[0];
        cnt++;
        for (int i = 0; i < graphcnt - 1; i++) {
            graph[i] = graph[i + 1];
        }
        graphcnt--;

        if (find(temp->des) != find(temp->src)) {			//if adding temp to spanning tree does not form a loop, add it
            kruskalGraph[kruscnt] = temp;
            unionSet(temp->des, temp->src);
            kruscnt++;
        }
    }

    if (kruscnt < tempcnt - 1)								//no possible spanning tree from given graph
        printf("No Spanning Tree.\n");
    else {
        printf("Constructed Spanning Tree :\n");
        for (int i = 0; i < kruscnt; i++)
            printf("%d <-> %d, weight : %d\n", kruskalGraph[i]->src, kruskalGraph[i]->des, kruskalGraph[i]->weight);
    }


}
