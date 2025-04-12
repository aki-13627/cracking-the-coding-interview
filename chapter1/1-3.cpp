#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string replaceSpace(string str) {
            string result;
            for (int i = 0; i < str.size(); i++) {
                if(str[i] == ' ') {
                    result += "%20";
                } else {
                    result.push_back(str[i]);
                }
            }
            return result;
        }
};

int main() {
    string str;
    getline(cin, str);
    Solution sol;
    string result = sol.replaceSpace(str);
    cout << result<< endl;
    return 0;
}