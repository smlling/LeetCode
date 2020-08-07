/**

    3. 无重复字符的最长子串

    给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

    示例 1:
    输入: "abcabcbb"
    输出: 3 
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

    示例 2:
    输入: "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

    示例 3:
    输入: "pwwkew"
    输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

*/
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> index = map<char, int>();
        int            len   = s.length();
        // 最长不重复子串长度
        int max = 0;
        // 当前正在计算的不重复子串的长度
        int cur = 0;
        // 当前子串起始位置
        int start = 0;
        // 下一轮新子串起始位置
        int newStart = 0;
        // 冲突字符的上一次出现位置
        int lastIndex = 0;

        if (len <= 1) {
            return len;
        }

        for (int i = 0; i < len; i++) {
            if (index.find(s[i]) == index.end()) {
                // 当前字符还未被索引，则将当前字符添加至索引并增加计数
                cur++;
            } else {
                // 当前字符上次出现位置的索引
                lastIndex = index[s[i]];
                if (lastIndex < start) {
                    // 当上次出现当索引小于本轮子串当起始索引时，表示当前字符未在本轮出现，因此更新索引并增加计数
                    cur++;
                } else {
                    // 否则表示当前字符已在本轮子串出现，则本轮结束
                    // 结束时判断本轮当子串长度是否大于最长子串长度，是则更新
                    if (cur > max) {
                        max = cur;
                    }
                    // 初始化新一轮子串长度计算
                    // 新一轮子串起始位置设置为上一轮冲突字符位置的下一个位置
                    newStart = lastIndex + 1;
                    // 新一轮子串初始长度
                    cur   = i - newStart + 1;
                    start = newStart;
                }
            }
            // 更新索引
            index[s[i]] = i;
        }

        return cur > max ? cur : max;
    }
};

int main(int argc, char* argv[]) {
    Solution       solution = Solution();
    vector<string> test     = {"", "a", "dvdf", "pwwkew", "bbbbb", "abcabcbb", "abcddddddd12345678889aaa"};
    for (auto item : test) {
        cout << item << ":" << solution.lengthOfLongestSubstring(item) << endl;
    }
}