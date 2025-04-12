#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isSameString(string str1, string str2) {
            if(str1.size()  != str2.size()) return false;
            unordered_map<char, int> charEncountedCount;
            for (int i = 0; i < str1.size(); i++ ) {
                charEncountedCount[str1[i]] ++;
            }
            for (int i = 0; i < str2.size(); i++) {
                charEncountedCount[str2[i]] --;
                if(charEncountedCount[str2[i]] < 0) {
                    return false;
                }
            }
            return true;
        }
};

int main () {
    string str1, str2;
    cin >> str1 >> str2;
    Solution sol;
    bool result = sol.isSameString(str1, str2);
    cout << (result ? "true" : "false") << endl;
    return 0;
}