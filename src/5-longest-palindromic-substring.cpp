/*

    5. 最长回文子串

    给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

    示例 1：
    输入: "babad"
    输出: "bab"
    注意: "aba" 也是一个有效答案。

    示例 2：
    输入: "cbbd"
    输出: "bb"

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-palindromic-substring
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    // 查找奇长度回文子串
    string longestPalindromeOdd(string s) {
        int len = s.length();
        // 对称点数组（如adcbcacbba的对称点数组为【3,5】及cbc的b和cac的a的位置）
        vector<int> flagIndex = vector<int>();

        // 寻找对称点
        for (int i = 1; i < len - 1; i++) {
            if (s[i - 1] == s[i + 1]) {
                flagIndex.push_back(i);
            }
        }

        // 没有找到对称点说明字符串不存在回文子串，则直接返回第一个字符
        if (0 == flagIndex.size()) {
            return string(1, s[0]);
        }

        // 最大回文子串半长（不包括对称点）
        int maxHalfLen = 1;
        // 最长回文子串对称点位置
        int maxFlag = flagIndex[0];
        // 当前回文子串半长（不包括中心点）
        int curHalfLen = maxHalfLen;

        // 遍历对称点
        for (auto curFlag : flagIndex) {
            // 以对称点为中心计算最大对称长度
            for (int i = 2;; i++) {
                // 对称点左右有一边已越界或出现不对称字符时，表示以该对称点为中心点回文子串长度计算完毕
                if (curFlag + i >= len || curFlag - i < 0 || s[curFlag - i] != s[curFlag + i]) {
                    break;
                }
                curHalfLen++;
            }

            // 如果当前回文子串点长度比先前记录点最长回文子串还要长则取代之
            if (curHalfLen > maxHalfLen) {
                maxHalfLen = curHalfLen;
                maxFlag    = curFlag;
            }

            // 一个回文子串计算完毕后初始化半长，初始为1是因为在找对称点时已经确定了对称点左右至少有一个对称字符
            curHalfLen = 1;
        }

        // 截取最长回文子串
        return s.substr(maxFlag - maxHalfLen, 2 * maxHalfLen + 1);
    }

    // 查找偶长度回文子串
    string longestPalindromeEven(string s) {
        int                 len       = s.length();
        vector<vector<int>> flagIndex = vector<vector<int>>();

        for (int i = 0; i < len - 1; i++) {
            if (s[i] == s[i + 1]) {
                flagIndex.push_back({i, i + 1});
            }
        }

        if (0 == flagIndex.size()) {
            return string(1, s[0]);
        }

        // 最大半长（包括对称点）
        int maxHalfLen = 1;
        // 与奇长度回文子串不同的是偶长度的子串的对称点是两个（如abba，其对称点就是中间的两个b），因此考虑用一个数组来存储这两个位置
        vector<int> maxFlag    = flagIndex[0];
        int         curHalfLen = maxHalfLen;

        for (auto curFlag : flagIndex) {
            for (int i = 1;; i++) {
                if (curFlag[1] + i >= len || curFlag[0] - i < 0 || s[curFlag[0] - i] != s[curFlag[1] + i]) {
                    break;
                }
                curHalfLen++;
            }
            if (curHalfLen > maxHalfLen) {
                maxHalfLen = curHalfLen;
                maxFlag    = curFlag;
            }
            curHalfLen = 1;
        }

        return s.substr(maxFlag[0] - maxHalfLen + 1, maxHalfLen * 2);
    }
    string longestPalindrome(string s) {
        if (0 == s.length()) {
            return "";
        }
        string odd  = longestPalindromeOdd(s);
        string even = longestPalindromeEven(s);

        return odd.length() >= even.length() ? odd : even;
    }
};

int main(int argc, char* argv[]) {
    Solution       solution = Solution();
    vector<string> test     = {"ababababa", "babad", "aaaa", ""};
    for (auto item : test) {
        cout << item << ":" << solution.longestPalindrome(item) << endl;
    }
    return 0;
}