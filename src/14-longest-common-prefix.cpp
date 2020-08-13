/*

    14. 最长公共前缀

    编写一个函数来查找字符串数组中的最长公共前缀。

    如果不存在公共前缀，返回空字符串 ""。

    示例 1:
    输入: ["flower","flow","flight"]
    输出: "fl"

    示例 2:
    输入: ["dog","racecar","car"]
    输出: ""
    解释: 输入不存在公共前缀。

    说明:
    所有输入只包含小写字母 a-z 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-common-prefix
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
    内存消耗：6.7 MB, 在所有 C++ 提交中击败了87.36%的用户

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    /**
     * 先遍历一遍所给的数组，找出其中最短的那个字符串
     * 然后用这个最短的字符串去匹配其他的每个字符串
     * 在匹配过程中,每当匹配完一个字符串就将匹配串截取掉不能匹配的部分
     * 
     * 如["flight","flower","flow"]
     * 找出最短的串为flow，先将它赋给ans
     * 然后用ans去分别与其他串匹配
     * flow与flight最长匹配为fl，匹配结束后就可以将ans截取为fl
     * 然后用fl与flow匹配，结束时最长匹配为fl
    */
    string longestCommonPrefix(vector<string>& strs) {
        if (0 == strs.size()) {
            return "";
        }

        // 最长匹配前缀
        string ans = "";
        // 最短串的索引
        int minIndex = 0;
        // 找出最短串的索引
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].length() < strs[minIndex].length()) {
                minIndex = i;
            }
        }

        ans = strs[minIndex];

        // 如果最短串的长度为0，那么最长匹配前缀直接就是空串
        if (0 == ans.length()) {
            return "";
        }

        // 开始匹配其他串
        for (int i = 0; i < strs.size(); i++) {
            // 如果当前被匹配的串就是最开始的最短串那么跳过
            if (i == minIndex) {
                continue;
            }
            // 如果在匹配过程中匹配串经过跟某一个串匹配后变为了空
            // 说明它跟某一个串完全不匹配
            // 那么就可以直接返回了，不需要继续匹配下去
            if (0 == ans.length()) {
                return "";
            }

            // 当前串的最长匹配长度
            int maxPrefixSize = 0;
            // 当前轮已匹配的长度
            int curPrefixSize = 0;
            // 被匹配串的当前位置
            int sseek = 0;
            // 匹配串的当前位置
            int pseek = 0;

            while (sseek < strs[i].length()) {
                while (pseek < ans.length()) {
                    // 被匹配串已遍历结束
                    if (sseek == strs[i].length()) {
                        break;
                    }
                    // 当前字符匹配
                    if (strs[i][sseek] == ans[pseek]) {
                        curPrefixSize++;
                        pseek++;
                        sseek++;
                    } else {
                        // 不匹配时更新最长匹配长度
                        if (curPrefixSize > maxPrefixSize) {
                            maxPrefixSize = curPrefixSize;
                        }
                        break;
                    }
                }
                // 如果匹配串的遍历结束时匹配串未被遍历完
                // 说明是被匹配的串先被遍历完
                // 那么此时maxPrefixSize有意义，则将匹配串更新为与当前串的最长匹配串
                if (sseek < ans.length()) {
                    ans = ans.substr(0, maxPrefixSize);
                }
                // 否则说明匹配串被完全匹配，那么匹配串不需要变动
                break;
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution               solution = Solution();
    vector<vector<string>> test     = {
        {"flower", "flow", "flight"},
        {"dog", "racecar", "car"},
    };

    for (auto item : test) {
        cout << solution.longestCommonPrefix(item) << endl;
    }
    return 0;
}