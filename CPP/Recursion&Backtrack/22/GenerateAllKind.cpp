//
// Created by Insomnia on 2018/7/4.
//
/**
 * 生成所有可能性
 */
#include <vector>
#include <iostream>
#include <string>

using namespace std;

void generate(string item, int n, vector<string> &result) {
    if (item.length() == 2 * n) {
        result.push_back(item);
        return;
    }
    generate(item + '(', n, result);
    generate(item + ')', n, result);

}

int main() {
    vector<string> result;
    generate("", 2, result);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i].c_str() << endl;
    }


    return 0;
}
