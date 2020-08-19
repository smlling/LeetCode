/*

    647. 回文子串

    给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

    具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

     

    示例 1：
    输入："abc"
    输出：3
    解释：三个回文子串: "a", "b", "c"

    示例 2：
    输入："aaa"
    输出：6
    解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
     

    提示：
    输入的字符串长度不会超过 1000 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/palindromic-substrings
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：4 ms, 在所有 C++ 提交中击败了98.75%的用户
    内存消耗：6.4 MB, 在所有 C++ 提交中击败了68.75%的用户

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int countSubstrings(string s) {
        return s.length() + countPalindromeOdd(s) + countPalindromeEven(s);
    }

    private:
    // 计算长度为奇数的回文子串数,中心扩散
    // aabcc 返回2 分别为abc,aabcc
    int countPalindromeOdd(string s) {
        int len = s.length();
        int ans = 0;

        for (int i = 1; i < len - 1; i++) {
            int n = 1;
            while (i - n >= 0 && i + n < len) {
                if (s[i - n] == s[i + n]) {
                    ans++;
                    n++;
                } else {
                    break;
                }
            }
        }
        return ans;
    }

    // 计算长度为偶数的回文子串数，中心扩散
    int countPalindromeEven(string s) {
        int len = s.length();
        int ans = 0;

        for (int i = 0; i < len; i++) {
            int n = 0;
            while (i - n >= 0 && i + 1 + n < len) {
                if (s[i - n] == s[i + 1 + n]) {
                    ans++;
                    n++;
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution       solution = Solution();
    vector<string> test     = {"bbccaacacdbdbcbcbbbcbadcbdddbabaddbcadb", "aaa"};
    for (auto item : test) {
        cout << item << ":" << solution.countSubstrings(item) << endl;
    }
    return 0;
}