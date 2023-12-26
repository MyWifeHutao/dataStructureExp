#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e9;
int n, m;
vector<vector<int>> adjMatrix;
vector<bool> visited;

void addEdge(int u, int v, int w) {
    adjMatrix[u][v] = w;
    adjMatrix[v][u] = w; // 添加这行使图变为无向图
}

void BFS(int s) {
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        cout << u;
        q.pop();

        for(int v = 1; v <= n; v++) {
            if(adjMatrix[u][v] != MAX && !visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }

        if(!q.empty()) cout << ",";
    }
}

void DFS(int u) {
    visited[u] = true;
    cout << u;

    for(int v = 1; v <= n; v++) {
        if(adjMatrix[u][v] != MAX && !visited[v]) {
            cout << ",";
            DFS(v);
        }
    }
}

int shortestPath(int s, int t) {
    vector<int> dist(n+1, MAX);
    dist[s] = 0;
    for(int count = 0; count < n-1; count++) {
        for(int u = 1; u <= n; u++) {
            for(int v = 1; v <= n; v++) {
                if(adjMatrix[u][v] != MAX)
                    dist[v] = min(dist[v], dist[u] + adjMatrix[u][v]);
            }
        }
    }

    return (dist[t] == MAX ? 0 : dist[t]);
}

int main() {
    cout << "Input"<<endl;
    char t;
    cin >> n >> t >> m;
    adjMatrix.assign(n+1, vector<int>(n+1, MAX));

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> t >> v >> t >> w;
        addEdge(u, v, w);
    }
    cout << "Output" << endl;
    visited.assign(n+1, false);
    BFS(1);
    cout << endl;

    visited.assign(n+1, false);
    DFS(1);
    cout << endl;

    cout << shortestPath(1, n) << endl;
    cout << "End" << endl;
    return 0;
}
