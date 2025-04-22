#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> turnToZero(vector<vector<int>> v) {
        int rows = v.size();
        int cols = v[0].size();

        vector<bool> zeroRows(rows, false);
        vector<bool> zeroCols(cols, false);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (v[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (zeroRows[i] || zeroCols[j]) {
                    v[i][j] = 0;
                }
            }
        }

        return v;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> vec(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> vec[i][j];
        }
    }

    Solution sol;

    vector<vector<int>> result = sol.turnToZero(vec);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}