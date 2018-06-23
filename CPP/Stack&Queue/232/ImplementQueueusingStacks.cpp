//
// Created by Insomnia on 2018/6/23.
//


#include <iostream>
#include <stack>


class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        std::stack<int > tempStack;
        while (!_data.empty()) {
            tempStack.push(_data.top());
            _data.pop();
        }

        tempStack.push(x);

        while (!tempStack.empty()) {
            _data.push(tempStack.top());
            tempStack.pop();
        }
    }

    int pop() {
        int x = _data.top();
        _data.pop();
        return x;
    }
    //返回头部元素即 front
    int peek() {
        return _data.top();
    }

    bool empty() {
        return _data.empty();
    }

private:
    std::stack<int> _data;
};

int main() {
    MyQueue Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);

    std::cout << "queue with stack "<< Q.peek() << std::endl;
    Q.pop();
    std::cout << "queue with stack " << Q.peek() << std::endl;
    return 0;
}