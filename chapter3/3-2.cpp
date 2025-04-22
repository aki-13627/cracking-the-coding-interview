#include <bits/stdc++.h>
using namespace std;

class StackWithMin {
   private:
    vector<int> stack;
    vector<int> minStack;

   public:
    StackWithMin() {}
    void push(int value) {
        stack.push_back(value);
        if (minStack.empty() || value <= minStack.back()) {
            minStack.push_back(value);
        }
    }
    void pop() {
        if (stack.empty()) return;
        int topVal = stack.back();
        stack.pop_back();
        if (topVal == minStack.back()) {
            minStack.pop_back();
        }
    }
    int top() const {
        if (stack.empty()) throw runtime_error("Stack is empty");
        return stack.back();
    }
    int getMin() const {
        if (minStack.empty()) throw runtime_error("Stack is empty");
        return minStack.back();
    }
    bool empty() const { return stack.empty(); }
};