# Kruskal
Third Assignment for Data Structure class, COSE213-01, 2019 Spring Semester.

Kruskal Algorithm in C

Given a graph as input, this program prints MST(Minimum Spanning Tree) using Kruskal's Algorithm.
When giving an input graph to program, you should input
1. # of vertices
2. edge information from vertice i to 'higher' vertice.

For example, if you have edge whose weight is 10 between vertice 1 and vertice 3, you should input
3 10 while program is getting 'vertice 1' informations. You should ignore the edge when program is getting
'vertice 3' information.

Giving input -1 -1 means you have given all nodes connected to current node to higher node, and program moves into 
next vertice input.

Sample Input
7
1 28
5 10
-1 -1
2 16
6 14
-1 -1
3 12
-1 -1
4 22
6 18
-1 -1
5 25
6 24
-1 -1
-1 -1
-1 -1

Sample Output
Input Graph: 
0 <-> 1, 28
0 <-> 5, 10
1 <-> 2, 16
1 <-> 6, 14
2 <-> 3, 12
3 <-> 4, 22
3 <-> 6, 18
4 <-> 5, 25
4 <-> 6, 24
Constructed Spanning Tree :
0 <-> 5, weight : 10
2 <-> 3, weight : 12
1 <-> 6, weight : 14
1 <-> 2, weight : 16
3 <-> 4, weight : 22
4 <-> 5, weight : 25
