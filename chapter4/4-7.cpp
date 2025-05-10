#include <bits/stdc++.h>

#include "./treeNode.hpp"
using namespace std;

/*
プロジェクトリストと依存関係のリストが与えられる。実行可能なプロジェクトの順序を見つけてください。
*/

class Solution {
   public:
    // dependencyMapはprojects[0]がprojects[1]に依存しているならば(dependencyMap[0][1]
    // == 1)
    vector<char> findBuildOrder(vector<char> projects,
                                vector<pair<char, char>> dependencies) {
        int n = projects.size();
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inDegree;

        vector<char> result;

        for (char p: projects) {
            inDegree[p] = 0;
        }

        for (auto &[before, after] : dependencies) {
            graph[before].push_back(after);
            inDegree[after] ++;
        }

        queue<char> q;
        for(auto& [project, deg]: inDegree) {
            if(deg == 0) q.push(project);
        }

        vector<char> order;
        while(!q.empty()) {
            char current = q.front();
            q.pop();
            order.push_back(current);
            for(char neighbor : graph[current]) {
                inDegree[neighbor] --;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if(order.size() != projects.size()) {
            throw runtime_error("循環依存が存在します");
        }
        return order;
    }
};


void printOrderOrError(vector<char> projects, vector<pair<char, char>> deps) {
    Solution sol;
    try {
        vector<char> order = sol.findBuildOrder(projects, deps);
        cout << "Build order: ";
        for (char c : order) cout << c << " ";
        cout << endl;
    } catch (const runtime_error& e) {
        cout << "エラー: " << e.what() << endl;
    }
}

int main() {
    // ✅ 正常な依存関係
    vector<char> projects1 = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<pair<char, char>> deps1 = {
        {'a', 'd'}, {'f', 'b'}, {'b', 'd'}, {'f', 'a'}, {'d', 'c'}
    };
    printOrderOrError(projects1, deps1);

    // ❌ 循環依存あり（例：a→b→c→a）
    vector<char> projects2 = {'a', 'b', 'c'};
    vector<pair<char, char>> deps2 = {
        {'a', 'b'}, {'b', 'c'}, {'c', 'a'}
    };
    printOrderOrError(projects2, deps2);

    return 0;
}