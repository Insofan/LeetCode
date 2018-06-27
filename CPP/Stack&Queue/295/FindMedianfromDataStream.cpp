//
// Created by Insomnia on 2018/6/27.
//

#include <iostream>
#include <queue>
#include <vector>

class MedianFinder {
public:
    MedianFinder() {

    }

    void addNum(int num) {

        if (bigQueue.empty()) {
            bigQueue.push(num);
            return;
        }

        if (bigQueue.size() == smallQueue.size()) {
            if (num < bigQueue.top()) {
                bigQueue.push(num);
            } else {
                smallQueue.push(num);
            }
        } else if (bigQueue.size() > smallQueue.size()) {
            if (num < bigQueue.top()) {
                smallQueue.push(bigQueue.top());
                bigQueue.pop();
                bigQueue.push(num);
            } else {
                smallQueue.push(num);
            }
        } else {
            if (num < smallQueue.top()) {
                bigQueue.push(num);
            } else {
                bigQueue.push(smallQueue.top());
                smallQueue.pop();
                smallQueue.push(num);
            }
        }
    }

    double findMedian() {
        int size = smallQueue.size() + bigQueue.size();
        if (size  % 2 == 0) {
            return (smallQueue.top() + bigQueue.top()) / 2.0;
        } else if (bigQueue.size()> smallQueue.size()) {
            return bigQueue.top();
        } else {
            return smallQueue.top();
        }
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> smallQueue;
    std::priority_queue<int> bigQueue;

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
