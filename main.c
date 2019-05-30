#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_SIZE 100			//±◊∑°«¡¿« √÷¥Î ¡§¡° ∞≥ºˆ
#define MAX_EDGE_SIZE 500			//±◊∑°«¡¿« √÷¥Î ∞£º± ∞≥ºˆ


typedef struct edge {
    int src, des;
    int weight;
}edge;								//∞£º± «œ≥™¿« ¡§∫∏∏¶ ≥™≈∏≥ª¥¬ ±∏¡∂√º

edge* graph[MAX_EDGE_SIZE];			//±◊∑°«¡ ¡§∫∏(∞£º± ¡§∫∏)∏¶ ¿˙¿Â«œ¥¬ πËø≠
int set[MAX_VERTEX_SIZE];			//∞¢ ¡§¡°¿« ¡˝«’∞¸∞Ë∏¶ ¿˙¿Â«œ¥¬ πËø≠(find, union ø¨ªÍø° ªÁøÎ)
edge* kruskalGraph[MAX_EDGE_SIZE];	//∞ËªÍµ» spanning tree ¡§∫∏∏¶ ¿˙¿Â«œ¥¬ πËø≠

void addNode(int, int, int);		//±◊∑°«¡ø° node∏¶ √ﬂ∞°«œ¥¬ «‘ºˆ
void sort();						//¿˙¿Âµ» node∏¶ ø¿∏ß¬˜º¯¿∏∑Œ ¡§∑ƒ«œ¥¬ «‘ºˆ
int find(int);						//ø¯º“∞° º”«ÿ¿÷¥¬ tree¿« root∏¶ √£¥¬ «‘ºˆ
void unionSet(int, int);			//«— ¡˝«’¿ª ¥Ÿ∏• ¡˝«’¿« ∫Œ∫–¡˝«’¿∏∑Œ ∏∏µÂ¥¬ «‘ºˆ
void kruskal(int);					//kruskal æÀ∞Ì∏Æ¡Ú¿ª Ω««‡«œ¥¬ «‘ºˆ


int graphcnt = 0;					//±◊∑°«¡ø° ¿˙¿Âµ» ∞£º± ∞≥ºˆ∏¶ ≥™≈∏≥ª¥¬ ∫Øºˆ

int main() {
    int vercnt = 0;					//±◊∑°«¡¿« ¡§¡° ∞≥ºˆ∏¶ ¿˙¿Â«œ¥¬ ∫Øºˆ
    int cnt = 0;

    for (int i = 0; i < MAX_VERTEX_SIZE + 1; i++)
        set[i] = -1;				//¡˝«’¿ª √ ±‚»≠«‘



    printf("Enter number of vertexes. Index of vertex starts from 0.: ");
    scanf("%d", &vercnt);

    for (int i = 0; i < vercnt; i++)
        set[i] = i;					//¿«πÃ¿÷¥¬ ∞™¿∏∑Œ √ ±‚»≠

    for (int i = 0; i < vercnt; i++) {
        int edge = 0, weight = 0;
        printf("Enter edges connected to vertex %d and weights: ", i);
        while (1) {
            scanf("%d %d", &edge, &weight);
            if (edge == -1)			//¡§¡° index∑Œ -1¿Ã ¿‘∑¬µ«∏È «ÿ¥Á ¡§¡°ø° ø¨∞·µ» ∏µÁ edge∏¶ ¿‘∑¬πﬁæ“¥Ÿ∞Ì ∞°¡§, break «—¥Ÿ
                break;
            addNode(i, edge, weight);
        }
    }

    printf("Input Graph: \n");
    for (int i = 0; i < graphcnt; i++) {
        printf("%d <-> %d, %d\n", graph[i]->src, graph[i]->des, graph[i]->weight);		//¿‘∑¬µ» ±◊∑°«¡ ¡§∫∏∏¶ ∫∏ø©¡‹
    }
    sort();		//¿‘∑¬µ» ±◊∑°«¡¿« ∞£º±¿ª weightø° µ˚∏• ø¿∏ß¬˜º¯¿∏∑Œ ¡§∑ƒ

    kruskal(vercnt);		//kruskal æÀ∞Ì∏Æ¡Ú Ω««‡
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
    while (kruscnt < vercnt - 1 && graphcnt > 0) {			//kruskal algorithmø°º≠¿« iterate ¡∂∞«
        edge* temp = graph[0];
        cnt++;
        for (int i = 0; i < graphcnt - 1; i++) {
            graph[i] = graph[i + 1];
        }
        graphcnt--;

        if (find(temp->des) != find(temp->src)) {			//temp∏¶ ¿ÃπÃ ª˝º∫µ» spanning treeø° √ﬂ∞°«ÿµµ loop∞° ª˝±‚¡ˆ æ ¥¬¥Ÿ∏È
            kruskalGraph[kruscnt] = temp;
            unionSet(temp->des, temp->src);
            kruscnt++;
        }
    }

    if (kruscnt < tempcnt - 1)								//¡÷æÓ¡¯ ±◊∑°«¡ø°º≠ Spanning Tree ª˝º∫ ∫“∞°
        printf("No Spanning Tree.\n");
    else {
        printf("Constructed Spanning Tree :\n");
        for (int i = 0; i < kruscnt; i++)
            printf("%d <-> %d, weight : %d\n", kruskalGraph[i]->src, kruskalGraph[i]->des, kruskalGraph[i]->weight);
    }


}
