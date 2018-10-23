// 
// @ClassName QueueUsingStackOffer
// @Description 实现一个队列, 要求max, push_back和pop_front的时间复杂度都是O 1
// @Date 18-10-23 下午7:50
// @Created by Insomnia
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MaxQueue {
public:
    MaxQueue() {}

    void push_back(int x) {
        stack<int> tmpStack;
       if (_dataStack.empty()) {
           _dataStack.push(x);
           _maxStack.push(x);
       } else {
           while (!_dataStack.empty()) {
               tmpStack.push(_dataStack.top());
               _dataStack.pop();
           }
           _dataStack.push(x);

           while (!tmpStack.empty()) {
               _dataStack.push(tmpStack.top());
               tmpStack.pop();
           }

           if (x < _maxStack.top()) {
               _maxStack.push(_maxStack.top());
           } else {
               _maxStack.push(x);
           }
       }
    }

    void pop_front(){
        _dataStack.pop();
        _maxStack.pop();
    }
    int max() {
        return _maxStack.top();
    }

private:
    stack<int> _dataStack;
    stack<int> _maxStack;
};

int main() {
    //int         a[] = {2, 3, 4, 2, 6, 2, 5, 1};
    //vector<int> vec(&a[0], &a[8]);
    MaxQueue q;
    q.push_back(2);
    cout << "max: "<< q.max() << endl;
    q.push_back(3);
    cout << "max: "<< q.max() << endl;
    q.push_back(4);
    cout << "max: "<< q.max() << endl;
    q.push_back(2);
    cout << "max: "<< q.max() << endl;
    q.pop_front();
    cout << "after pop max: " << q.max() << endl;
    q.pop_front();
    cout << "after pop max: " << q.max() << endl;
    q.pop_front();
    cout << "after pop max: " << q.max() << endl;
    return 0;
}