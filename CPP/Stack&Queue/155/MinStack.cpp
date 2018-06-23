//
// Created by Insomnia on 2018/6/23.
//
#include <stack>
#include <iostream>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        _data.push(x);
        if (min.empty()) {
            min.push(x);
        } else {
            if (x >min.top()) {
                x = min.top();
            }
            min.push(x);
        }
    }

    void pop() {
        _data.pop();
        min.pop();
    }

    int top() {
        return _data.top();
    }

    int getMin() {

        return min.top();
    }

private:
    std::stack<int> _data;
    std::stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

using namespace std;
int main() {
    MinStack minStack;
    minStack.push(-2);
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    minStack.push(0);
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    minStack.push(-5);
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    return 0;
}