#include <bits/stdc++.h>
using namespace std;

class MyQueue {
   private:
    stack<int> s1;
    stack<int> s2;

   public:
    MyQueue() {}

    void push(int value) { s1.push(value); }
    void pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }
    int top() {
        if (s1.empty() && s2.empty()) throw runtime_error("queue is empty");
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top = s2.top();
        return top;
    }
    bool empty() const { return s1.empty() && s2.empty(); }

    int size() const { return s1.size() + s2.size(); }
};

int main() {
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.top() << endl;   // 10
    cout << q.size() << endl;  // 3
    q.pop();

    cout << q.top() << endl;  // 20
    q.pop();

    cout << q.top() << endl;  // 30
    q.pop();

    cout << boolalpha << q.empty() << endl;  // true
}