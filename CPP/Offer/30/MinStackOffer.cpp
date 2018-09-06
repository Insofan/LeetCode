//
// Created by Insomnia on 2018/9/6.
//

#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;

class MyStack {
public:
    MyStack(){

    }
    void pop() {
        minStack.pop();
        dataStack.pop();
    }
    void push(int x) {
        if (minStack.empty()) {
            minStack.push(x);
        } else {
            if (x > minStack.top()) {
               minStack.push(minStack.top());
            } else {
                minStack.push(x);
            }
        }
        dataStack.push(x);
    }

    int min() {
        return minStack.top();
    }
    int top() {
        return dataStack.top();
    }
    int getMin() {
        return minStack.top();
    }


private:
    stack<int> dataStack;
    stack<int> minStack;
};


int main() {
    MyStack minStack;
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
