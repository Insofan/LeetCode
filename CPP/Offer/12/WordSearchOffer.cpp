// 
// @ClassName WordSearchOffer
// @Description 同leetcode 79 word search
// @Date 18-11-13 下午7:38
// @Created by Insomnia
//


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
               if (helper(board, word, i, j, 0)) {
                   return true;
               }
            }
        }
        return false;
    }

private:
    bool helper(vector<vector<char>> &board, string word, int i, int j, int index) {
        //所有index全部符合
        if (index == word.size()) {
            return true;
        }

        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1) {
            return false;
        }

        if (board[i][j] != word[index]) {
            return false;
        }

        //将搜索过的内容, 变为*, 防止重复搜索
        board[i][j] = '*';

        bool furtherSearch = helper(board, word, i + 1, j, index + 1) || //down
                helper(board, word, i - 1, j, index + 1) || // up
            helper(board, word, i, j + 1, index + 1) || //right
            helper(board, word, i, j - 1, index + 1); //left

        //修正
        board[i][j] = word[index];
        return furtherSearch;

    }
};
int main() {
    vector<char> ch1 = {'A', 'B', 'C', 'E'};
    vector<char> ch2 = {'S', 'F', 'C', 'S'};
    vector<char> ch3 = {'A', 'D', 'E', 'E'};
    vector<vector<char>> vec;
    vec.push_back(ch1);
    vec.push_back(ch2);
    vec.push_back(ch3);

    string s1 = "ABCCED";
    string s2 = "SEE";
    string s3 = "ABCB";

    Solution solution;

    cout << boolalpha << solution.exist(vec, s1) << endl;
    cout << boolalpha << solution.exist(vec, s2) << endl;
    cout << boolalpha << solution.exist(vec, s3) << endl;
    return 0;
}