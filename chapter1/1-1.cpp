#include <bits/stdc++.h>
using namespace std;

// Make sure the string is ASCII
class Solution {
    public: 
        bool noDuplicates(string str) {
            if(str.size() > 128) return false;
            map<char, int> exists;
            for(int i = 0; i < str.size(); i++) {
                if(exists.count(str[i])) return false;
                exists[str[i]] = 1;
            }
            return true;
        }
    };

int main() {
    string str;
    cin >> str;
    Solution sol;
    bool result =  sol.noDuplicates(str);
    cout << (result ? "true" : "false") << endl;
}