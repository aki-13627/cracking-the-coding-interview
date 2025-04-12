#include <bits/stdc++.h>
using namespace std;


class Solution {
    public: 
        string compress(string str) {
            if(str.size() == 0) return str;
            char current = str[0];
            char prev = str[0];
            int count = 1;
            string result = "";
            for (int i = 1; i < str.size(); i++) {
                current = str[i];
                if (prev != current) {
                    result.push_back(prev);
                    result.push_back('0' + count);
                    count = 1;
                    prev = current;
                } else {
                    count ++;
                }
            }
            result.push_back(current);
            result.push_back('0' + count);
            return result.size() > str.size() ? str : result;
        }
};

int main() {
    string str;
    cin >> str;
    Solution sol;
    string result = sol.compress(str);
    cout << result << endl;
    return 0;
}