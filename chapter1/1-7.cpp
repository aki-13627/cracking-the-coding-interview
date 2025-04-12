#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<vector<int>> rotatePicture(vector<vector<int>> pic) {
        for (int i = 0; i < pic.size() / 2; i ++) {
            for (int j = 0; j < pic.size(); j ++) {
                swap(pic[i][j], pic[pic.size() - 1 - i][j]);
            }
        }
        for (int i = 0; i < pic.size(); i++) {
            for (int j = i; j < pic.size(); j++) {
                swap(pic[i][j], pic[j][i]);
            }
        }
        return pic;
        }
};

int main() {
    int N;
    cin >> N;
    vector<vector<int>> pic(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j= 0; j < N; j++){
            cin >> pic[i][j];
        }
    }
    Solution sol;
    vector<vector<int>> result = sol.rotatePicture(pic);

    for (int i = 0; i < N; i++) {
        for (int j= 0; j < N; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}