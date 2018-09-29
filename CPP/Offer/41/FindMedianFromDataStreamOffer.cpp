//
// Created by Insomnia on 2018/9/19.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (largeQueue.size() == 0) {
            largeQueue.push(num);
        } else if (largeQueue.size() > smallQueue.size()) {
            if (num < largeQueue.top()) {
                int top = largeQueue.top();
                largeQueue.pop();
                largeQueue.push(num);

                smallQueue.push(top);
            } else {
                smallQueue.push(num);
            }
        } else if (smallQueue.size() > largeQueue.size()) {
            if (num < smallQueue.top()) {
                largeQueue.push(num);
            } else {
                largeQueue.push(smallQueue.top());
                smallQueue.pop();
                smallQueue.push(num);
            }
        } else {
            if (num < largeQueue.top()) {
                largeQueue.push(num);
            } else {
                smallQueue.push(num);
            }
        }
    }

    double findMedian() {
        int size = smallQueue.size() +largeQueue.size();
        if (size % 2 == 0) {
            return  (smallQueue.top() + largeQueue.top()) / 2.0;
        }
        return smallQueue.size() > largeQueue.size() ? smallQueue.top():largeQueue.top();
    }

private:
    //大堆
    priority_queue<int, vector<int>, greater<int>>          smallQueue;
    //小堆
    priority_queue<int, vector<int>> largeQueue;
};

int main() {
    MedianFinder medianFinder;

    /*
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    double res = medianFinder.findMedian();
    cout << res << endl;
    medianFinder.addNum(3);
    res = medianFinder.findMedian();
    cout << res << endl;
     */
    medianFinder.addNum(-1);
    medianFinder.addNum(-2);
    medianFinder.addNum(-3);
    medianFinder.addNum(-4);
    medianFinder.addNum(-5);
    double res = medianFinder.findMedian();
    cout << res << endl;
    return 0;
}
