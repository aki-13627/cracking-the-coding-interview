#include <bits/stdc++.h>
using namespace std;

class ThreeStacks {
   private:
    static const int STACK_COUNT = 3;
    static const int STACK_CAPACITY = 100;
    int data[STACK_COUNT * STACK_CAPACITY];
    int tops[STACK_COUNT];

   public:
    ThreeStacks() {
        for (int i = 0; i < STACK_COUNT; i++) {
            tops[i] = -1;
        }
    }

    void push(int stackNum, int value) {
        if (stackNum < 0 || stackNum >= STACK_COUNT) return;
        if (tops[stackNum] + 1 >= STACK_CAPACITY) {
            throw std::overflow_error("Stack overflow");
        }
        tops[stackNum]++;
        data[stackNum * STACK_CAPACITY + tops[stackNum]] = value;
    }

    void pop(int stackNum) {
        if (stackNum < 0 || stackNum >= STACK_COUNT) return;
        if (tops[stackNum] == -1) {
            throw std::underflow_error("Stack underflow");
        }
        tops[stackNum]--;
    }

    int top(int stackNum) const {
        if (stackNum < 0 || stackNum >= STACK_COUNT) return -1;
        if (tops[stackNum] == -1) {
            throw std::runtime_error("Stack is empty");
        }
        return data[stackNum * STACK_CAPACITY + tops[stackNum]];
    }

    bool empty(int stackNum) const { return tops[stackNum] == -1; }
};