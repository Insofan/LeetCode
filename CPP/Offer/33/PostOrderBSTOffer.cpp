// 
// Created by Insomnia on 18-9-9.
//


#include <iostream>
#include "../TreeNode.h"
#include <vector>

using namespace std;

//有问题?
//class Solution {
//public:
//    bool vertifySeqOfBST(vector<int> seq) {
//        //0或者1时根据题目来确定布尔值
//
//        if(seq.size()==0)
//            return false;
//
//        if(seq.size()==1)
//            return true;
//
//        int start=0; //序列的起始位置
//        int end=seq.size()-1;  //序列的终止位
//        return helper(seq, 0, end);
//    }
//
//private:
//    bool helper(vector<int> seq, int start, int end) {
//        if (start == end || start > end) {
//            //无数据需要处理
//            return true;
//        }
//
//        int root = seq[end];
//
//        //左子树的终止位置
//                int i;
//        for (i = start; i < end ; i++) {
//            if (seq[i] > root) {
//                break;
//            }
//        }
//
//        int j = i;
//
//        //右子树
//        for (; j < end; j++) {
//            if (seq[j] < root) {
//                return false;
//            }
//        }
//
//        bool left = helper(seq, start, i - 1);
//        bool right = helper(seq, i, end - 1);
//        return left && right;
//    }
//};

//newcoder ac 代码
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return bfs(sequence, 0, sequence.size() - 1);
    }

private:
    bool bfs(vector<int> &seq, int begin, int end) {
        if (begin > end) {
            return false;
        }

        int i = 0;

        for (;i < end - 1; i++) {
            if (seq[i] > seq[end]) {
                break;
            }
        }

        int j = i;

        for (; j < end - 1; j++) {
            if (seq[j] < seq[end]) {
                return false;
            }
        }

        int left = true;

        if (i > 0) {
            left = bfs(seq, begin, i);
        }

        int right = true;
        if (j < end - 1) {
            right = bfs(seq, j , end - 1);
        }

        return left && right;
    }
};

int main () {
    int a[7] = {5, 7, 6, 9, 11, 10, 8};
    vector<int> vector1(&a[0], &a[7]);
    Solution solution;
   bool res =  solution.VerifySquenceOfBST(vector1);
   cout << "result 1 : " << boolalpha << res << endl;
    int b[4] = { 7, 4, 6, 5};
    vector<int> vector2(&b[0], &b[4]);
    bool res2 = solution.VerifySquenceOfBST(vector2);
    cout << "result 2 : " << boolalpha << res2 << endl;
    return 0;
}
