#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isPalindrome(string str) {
        string rmSpaces;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                continue;
            } else {
                rmSpaces.push_back(tolower(str[i]));
            }
        }
        int left = 0;
        int right = rmSpaces.size() - 1;
        while (left < rmSpaces.size() / 2) {
            if (rmSpaces[left] != rmSpaces[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool isPermutationOfPalindrome(string str) {
        unordered_map<char, int> count;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') continue;
            char c = tolower(str[i]);
            count[c] = 1 - count[c];
        }
        int oddCount = 0;
        for (auto &[_, val] : count) {
            if (val == 1) oddCount++;
            if (oddCount > 1) return false;
        }
        return true;
    }
};

int main() {
    string str;
    getline(cin, str);
    Solution sol;
    bool result = sol.isPermutationOfPalindrome(str);
    cout << (result ? "true" : "false") << endl;
    return 0;
}