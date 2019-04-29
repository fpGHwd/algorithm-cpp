//
// Created by suzumiya on 4/7/19.
//


#include <iostream>
#include <ctime>
using namespace std;

int G[5][5];
int visited[5][5];
int vis[5][5];
int n = 5;
void euler(int u) {
    for (int v = 0; v < n; v++) {
        if (G[u][v] && ! visited[u][v]) {
            cout << u << "->" << v << endl;
            visited[u][v] = visited[v][u] = 1;
            euler(v);
        }
    }
}

void euler0(int u){
    for(int v = 0; v < n; v++)
        if(G[u][v] && !vis[u][v]){
            vis[u][v] = vis[v][u] = 1;
            euler(v);
            printf("%d %d\n", u , v);
        }
}

/**
 * 00000
 * 00110
 * 01001
 * 01001
 * 00110
 *
 * @return
 */
int main() {
    G[1][2] = G[2][1] = G[1][3] = G[3][1] = 1;
    G[2][4] = G[4][2] = G[3][4] = G[4][3] = 1;
    euler(1);
    return 0;
}