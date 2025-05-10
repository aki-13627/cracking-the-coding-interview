#include <bits/stdc++.h>
using namespace std;

// N*Nの行列を0,1で有向グラフを表す

class Solution {
    public:
        bool isRoute(vector<vector<int>> graph, int node1, int  node2) {
            if(node1 == node2) {
                return true;
            }
            queue<int> q;
            q.push(node1);
            vector<bool> visited(graph.size(), false);
            visited[node1] = true;
            while(!q.empty()) {
                int current = q.front();
                q.pop();
                for (int i = 0; i < graph.size(); i++) {
                    if(graph[current][i] == 1) {
                        if(i == node2) {
                            return true;
                        }
                        if(!visited[i]) {
                            q.push(i);
                            visited[i] = true;
                        }
                    }
                }
            }
            return false;
        }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            graph[i].push_back(x);
        }
    }
    int node1, node2;
    cin >> node1 >> node2;
    cout << sol.isRoute(graph, node1, node2) << endl;
}