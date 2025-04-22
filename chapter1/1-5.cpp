#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool oneEditAway(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        if (abs(n - m) > 1) return false;

        if (n > m) return oneEditAway(str2, str1);

        bool foundDifference = false;
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (str1[i] != str2[j]) {
                if (foundDifference) return false;
                foundDifference = true;
                if (n == m) {
                    i++;
                }
            } else {
                i++;
            }
            j++;
        }

        return true;
    }
};

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    Solution sol;
    bool result = sol.oneEditAway(str1, str2);
    cout << (result ? "true" : "false") << endl;
}
