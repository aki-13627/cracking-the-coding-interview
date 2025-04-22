#include <bits/stdc++.h>
using namespace std;

class SetOfStack {
   private:
    int capacity = 20;
    vector<vector<int>> stacks;

   public:
    SetOfStack() {}
    void pop() {
        if (stacks.size() == 0) throw runtime_error("Stacks is empty");
        if (stacks.back().size() == 0) {
            stacks.pop_back();
        }
        stacks.back().pop_back();
    }

    void push(int value) {
        if (stacks.size() == 0 || stacks.back().size() == capacity) {
            stacks.push_back(vector<int>());
        }
        stacks.back().push_back(value);
    }

    int top() const {
        if (stacks.size() == 0) throw runtime_error("Stacks is empty");
        return stacks.back().back();
    }

    bool empty() const {
        for (int i = 0; i < stacks.size(); i++) {
            if (!stacks[i].empty()) return false;
        }
        return true;
    }
};

int main() {
    SetOfStack s;
    for (int i = 1; i <= 50; i++) {
        s.push(i);
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
    return 0;
}
