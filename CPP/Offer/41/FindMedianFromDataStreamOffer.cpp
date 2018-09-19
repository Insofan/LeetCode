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
        fir.push(num);
        sec.push(fir.top());
        if (fir.size() < sec.size()) {
            fir.push(sec.top());
        }
    }

    double findMedian() {
        return fir.size() > sec.size() ? fir.top() : (fir.top() + sec.top()) / 2.0;
    }
private:
    priority_queue<int, vector<int>> fir;
    priority_queue<int, vector<int>, greater> sec;
};

int main() {
    MedianFinder medianFinder;

     medianFinder.addNum(1);
    medianFinder.addNum(2);
    double  res = medianFinder.findMedian();
    cout << res << endl;
    medianFinder.addNum(3);
    res = medianFinder.findMedian();
    cout << res << endl;
    /*
    medianFinder.addNum(-1);
    medianFinder.addNum(-2);
    medianFinder.addNum(-3);
    medianFinder.addNum(-4);
    medianFinder.addNum(-5);
    double res = medianFinder.findMedian();
    cout << res << endl;
     */
    return 0;
}
