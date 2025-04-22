#include <bits/stdc++.h>
using namespace std;

/*
最も小さい項目がtopにくるスタックを並べ替えるプログラムを書いてください。
別のスタックを1つ用意しても構いません。スタック構造にスタック上のデータをコピーしてはいけません。
またスタックはpush、pop、peek、emptyのみ使えます。
*/

class Solution {
   public:
    void sortStack(stack<int> &s) {
        stack<int> tmp;
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            while (!tmp.empty() && tmp.top() > cur) {
                s.push(tmp.top());
                tmp.pop();
            }
            tmp.push(cur);
        }
        while (!tmp.empty()) {
            s.push(tmp.top());
            tmp.pop();
        }
    }
};

int main() {
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);
    s.push(5);

    Solution sol;

    sol.sortStack(s);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}