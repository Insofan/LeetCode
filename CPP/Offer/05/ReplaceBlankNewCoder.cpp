// 
// @ClassName ReplaceBlankNewCoder
// @Description TODO
// @Date 18-10-30 下午8:46
// @Created by Insomnia
//

#include <iostream>
#include <string>
using namespace std;
class Solution1 {
public:
        void replaceSpace(char *str,int length) {
            if (length == 0 || str == nullptr) {
                return;
            }

            int count = 0;
            for (int i = 0; i < length; i++) {
                if (str[i] == ' ') {
                    count++;
                }
            }

            int newLength = length + count * 2 - 1;

            for (int i = length - 1; i >= 0; i--) {
                if (str[i] == ' ') {
                    str[newLength--] = '0';
                    str[newLength--] = '2';
                    str[newLength--] = '%';
                } else {
                    str[newLength--] = str[i];
                }
            }
        }
};

class Solution2 {
public:
    void replaceSpace(char *str,int length) {
        string s = str;
        string res;
        for (int i= 0; i < length; i++) {
            if (s[i] == ' ') {
                res += "%20";
            } else {
                res.push_back(s[i]);
            }
        }

        /*
        for (int i = 0; i < res.length(); i++) {
            str[i] =  res[i];
        }
         */

        int newLength = res.length() - 1;
        for (int i = length - 1; i >= 0; i--) {
            if (str[i] == ' ') {
                str[newLength--] = '0';
                str[newLength--] = '2';
                str[newLength--] = '%';
            } else {
                str[newLength--] = str[i];
            }
        }
    }
};
int main(){
    string str1 = "Replace string wtf!";
    Solution1 solution1;
    char *arg1 = const_cast<char *>(str1.c_str());
     solution1.replaceSpace(arg1, str1.length());
     cout << arg1 << endl;

    string str2 = "Replace string wtf!";
     Solution2 solution2;
     char *arg2 = const_cast<char *>(str2.c_str());
     solution2.replaceSpace(arg2, str2.length());
     cout << arg2 << endl;
    return  0;
}