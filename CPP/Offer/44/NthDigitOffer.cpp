// 
// Created by Insomnia on 18-10-7.
//

//同 leetcode 400
#include <iostream>
#include <math.h>


using namespace std;

class Solution {
public:
    int digitAtIndex(int index) {
        if (index < 0) {
            return  -1;
        }

        int digits = 1;
        while (true) {
            int numbers = countOfIntegers(digits);
            if (index < numbers * digits) {
                return digitAtIndex(index, digits);
            }
            index -= digits * numbers;
            digits++;
        }
    }

    private:
    int countOfIntegers(int digits) {
        if (digits == 1) {
            return  10;
        }

        int count = (int)pow(10, digits - 1);
        return 9 * count;
    }

    int digitAtIndex(int index, int digits) {
       int number = beginNumber(digits) + index / digits;
       int indexFromRight = digits - index % digits;
       for (int i = 1; i < indexFromRight; i++) {
          number /= 10;
       }

        return number % 10;
    }

    int beginNumber(int digits) {
        if (digits == 1) {
            return 0;
        }
        return (int)pow(10, digits - 1);
    }

};

int main() {
    Solution solution;
    cout << solution.digitAtIndex(11) << endl;
    cout << solution.digitAtIndex(3) << endl;
    return 0;
}