//
// Created by Insomnia on 2018/6/27.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class MedianFinder {
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (rightQ.size() == 0) {
            rightQ.push(num);
        } else if (rightQ.size() > leftQ.size()) {
            if (num < rightQ.top()) {
                leftQ.push(rightQ.top());
                rightQ.pop();
                rightQ.push(num);
            } else {
                leftQ.push(num);
            }
        } else if (leftQ.size() > rightQ.size()) {
            if (num < leftQ.top()) {
                rightQ.push(num);
            } else {
                rightQ.push(leftQ.top());
                leftQ.pop();
                leftQ.push(num);
            }
        } else {
            if (num < rightQ.top()) {
                rightQ.push(num);
            } else {
                leftQ.push(num);
            }
        }
    }

    double findMedian() {
        int len = leftQ.size() + rightQ.size();
        if (len % 2 == 0) {
            return (leftQ.top() + rightQ.top()) / 2.0;
        }
        return leftQ.size() > rightQ.size() ? leftQ.top() : rightQ.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> leftQ;
    priority_queue<int, vector<int>> rightQ;
};

int main() {
    MedianFinder M;
    M.addNum(2);
    M.addNum(1);
    std::cout << M.findMedian() << std::endl;
    M.addNum(4);
    std::cout << M.findMedian() << std::endl;
    M.addNum(3);
    std::cout << M.findMedian() << std::endl;

    return 0;
}
