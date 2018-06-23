//
// Created by Insomnia on 2018/6/23.
//
#include <iostream>
#include <queue>

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        std::queue<int> tempQueue;
        tempQueue.push(x);
        while (!_data.empty()) {
            tempQueue.push(_data.front());
            _data.pop();
        }

        while (!tempQueue.empty()) {
            _data.push(tempQueue.front());
            tempQueue.pop();
        }
    }

    int pop() {
        int x = _data.front();
        _data.pop();
        return x;
    }

    int top() {
        return _data.front();
    }

    bool empty() {
        return _data.empty();
    }

private:
    std::queue<int> _data;
};

int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    std::cout  << "Top " << myStack.top() << std::endl;
    myStack.pop();
    std::cout  << "Top " << myStack.top() << std::endl;
    myStack.push(5);
    std::cout  << "Top " << myStack.top() << std::endl;
    return 0;
}


