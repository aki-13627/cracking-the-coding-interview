#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isSubstring(const string& s1, const string& s2) {
        return s1.find(s2) != string::npos;
    }

    bool isRotated(const string& s1, const string& s2) {
        if (s1.length() != s2.length() || s1.empty()) return false;
        return isSubstring(s1 + s1, s2);
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    bool res = sol.isRotated(s1, s2);
    cout << (res ? "true" : "false") << endl;
    return 0;
}