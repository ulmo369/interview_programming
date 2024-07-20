#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isBipartite(int n, vector<int> graph[]) {
    int color[n];
    queue<int> q;

    for (int i = 0; i < n; i++) color[i] = -1;
    color[0] = 0;
    q.push(0);

    while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto node : graph[u]) {

                if (color[node] == -1) {
                    color[node] = !color[u];
                    q.push(node);
                } 

                else if (color[node] == color[u]) {
                    return false;
                }

            }
    }

    return true;
}

int main() {
    int n;

    while (cin >> n && n != 0) {
        int m;
        cin >> m;
        vector<int> graph[n];

        for (int i = 0; i < m; i++) {
            int u;
            int v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if (isBipartite(n, graph)) {
            cout << "BICOLORABLE." << endl;
        } 

        else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }

    return 0;
}