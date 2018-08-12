// 
// Created by Insomnia on 18-8-12.
//


#include <iostream>
#include <stack>


using namespace std;
class MyQueue {
public:
    MyQueue() {

    }
    void pushBack(int x) {

        stack<int> tempStack;
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

    void pop() {
        _data.pop();
    }
    int front(){
        int x = _data.top();
        return x;
    }
    bool empty() {
        return _data.empty();
    }

private:
    stack<int> _data;
};

int main ()  {

    MyQueue myQueue;
    myQueue.pushBack(1);
    myQueue.pushBack(2);
    myQueue.pushBack(3);
    myQueue.pushBack(4);
    myQueue.pushBack(5);

    myQueue.pop();
    myQueue.pushBack(6);

    while (!myQueue.empty()) {
        cout << myQueue.front() <<  " " ;
        myQueue.pop();
    }
    cout << endl;
    return  0;
}