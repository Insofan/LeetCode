//
// Created by Insomnia on 2018/6/24.
//
//1- n 数字序列， 按顺序入栈， 每个数字入栈后即可出战， 也可以在栈中停留， 等待后面的数字入栈后出栈，
//该数字再出栈， 求该数字序列的出栈是否合法。选自 poj 1363

#include <iostream>
#include <stack>
#include <queue>

bool check_is_valid_order(std::queue<int> &order) {
    std::stack<int> S;
    int n = order.size();

    for (int i = 1; i <= n; i++) {
        S.push(i);
        while (!S.empty() && order.front() == S.top()) {
            S.pop();
            order.pop();
        }
    }

    if (!S.empty()) {
        return false;
    }

    return true;
}

int main() {
    int n;
    int train;
    scanf("%d", &n);
    while (n) {
        scanf("%d", &train);
        while (train) {
            std::queue<int> order;
            for (int i = 1; i < n; ++i) {
                scanf("%d", train);
                order.push(train);
            }

            if (check_is_valid_order(order)) {
                std::cout << "Yes" << std::endl;
            } else {
                std::cout << "No" << std::endl;
            }
            scanf("%d", &train);
        }
        std::cout << std::endl;
        scanf("%d", &n);
    }

    return 0;
}

