/*

    10. 正则表达式匹配

    给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

    '.' 匹配任意单个字符
    '*' 匹配零个或多个前面的那一个元素
    所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

    说明:
    s 可能为空，且只包含从 a-z 的小写字母。
    p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

    示例 1:
    输入:
    s = "aa"
    p = "a"
    输出: false
    解释: "a" 无法匹配 "aa" 整个字符串。

    示例 2:
    输入:
    s = "aa"
    p = "a*"
    输出: true
    解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

    示例 3:
    输入:
    s = "ab"
    p = ".*"
    输出: true
    解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

    示例 4:
    输入:
    s = "aab"
    p = "c*a*b"
    输出: true
    解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
    
    示例 5:
    输入:
    s = "mississippi"
    p = "mis*is*p*."
    输出: false

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/regular-expression-matching
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：4 ms, 在所有 C++ 提交中击败了96.78%的用户
    内存消耗：7 MB, 在所有 C++ 提交中击败了51.77%的用户

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    /**
     * 对表达式进行精简，去除无用成分
    */
    string filter(string p) {
        if (p.length() <= 2) {
            return p;
        }

        string newp = "";
        int    seek = 0;
        for (int i = 0; i < p.length(); i++) {
            // 若当前的 x* 可以被前一个 x* 所替代，则当前这个 x* 就可以丢弃
            if (seek - 2 >= 0 && match(p[i], newp[seek - 2]) && '*' == p[i - 1] && i + 1 < p.length() && '*' == p[i + 1]) {
                continue;
                // 去除经过删减字符后的连续的多余的*号
            } else if (seek - 1 >= 0 && '*' == newp[seek - 1] && '*' == p[i]) {
                continue;
            } else {
                newp.push_back(p[i]);
                seek++;
            }
        }

        return newp;
    }
    /**
     * 当字符串被匹配完毕后判断表达式剩余部分是否是可以忽略，如果可以忽略表明成功匹配，否则匹配失败
    */
    bool canIgnore(string p, int offset) {
        // 判断剩下当部分是不是 x*y* 的格式，是则可忽略
        if ((p.length() - offset) % 2) {
            return false;
        } else {
            for (int i = offset + 1; i <= p.length() - 1; i += 2) {
                if ('*' != p[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    bool match(char c, char p) {
        return c == p || '.' == p;
    }
    bool match(string s, string p, int sSeek, int pSeek) {
        while (pSeek < p.length() && sSeek < s.length()) {
            if ('*' == p[pSeek]) {
                // 忽略首位的*
                if (0 == pSeek) {
                    pSeek++;
                    continue;
                }

                // 如果当前被匹配的字符与当前的表达式字符不匹配
                // 则表明当前的 x* 的使命结束，表达式指针后移
                if (!match(s[sSeek], p[pSeek - 1])) {
                    pSeek++;
                    continue;
                }

                // 递归判断字符串后半部分与表达式后半部分是否匹配
                if (match(s, p, sSeek, pSeek + 1)) {
                    return true;
                }

                // 若后半部分不匹配则将字符串指针后移
                sSeek++;

            } else {
                // 如果表达式下一位为*号则表示当前字符可有可无，则将指针后移一位
                if ((pSeek + 1) < p.length() && '*' == p[pSeek + 1]) {
                    pSeek++;
                    continue;
                }
                // 否则判断当前字符与表达式的当前字符是否匹配
                // 匹配则双双指针后移一位进行下一位的匹配
                if (!match(s[sSeek], p[pSeek])) {
                    return false;
                }
                sSeek++;
                pSeek++;
            }
        }

        // 匹配结束后
        // 如果字符串和表达式双双到达末尾则表示完美匹配
        if (sSeek == s.length()) {
            if (pSeek == p.length()) {
                return true;
            }

            // 如果表达式有剩余则分两种情况
            // 1.表达式结束于*号，则判断*号后面的部分是否可以被忽略
            // 如s="ab",p=".*c*s"结束时pSeek位于*头上, 则判断"c*s"是否可以被忽略
            if ('*' == p[pSeek]) {
                if (pSeek == p.length() - 1) {
                    return true;
                }
                return canIgnore(p, pSeek + 1);
            }
            // 2.表达式结束于普通字符，则判断从表达式匹配结束位到表达式末尾这部分子串是否可忽略
            // 如s="a", p="ab*"结束时pSeek位于b头上,判断 "b*"是否可被忽略
            if (p.length() - pSeek > 1) {
                return canIgnore(p, pSeek);
            }
        }

        return false;
    }
    bool isMatch(string s, string p) {
        p = filter(p);
        if (!s.length() && !p.length()) {
            return true;
        } else if (!s.length() && p.length()) {
            return canIgnore(p, 0);
        } else if (s.length() && !p.length()) {
            return false;
        }

        return match(s, p, 0, 0);
    }
};

int main(int argc, char* argv[]) {
    Solution               solution = Solution();
    vector<vector<string>> test     = {
        {"ab", ".*c"},
        {"a", "ab*"},
        {"ac", "aa*c*a*"},
        {"aabac", ".*aa*c*a*"},
        {"bcbabcaacacbcabac", "a*c*a*b*.*aa*c*a*a*"},
        {"ab", ".*.."},
        {"ba", ".*a*a"},
        {"bbbba", ".*a*a"},
        {"abbabaaaaaaacaa", "a*.*b.a.*c*b*a*c*"},
        {"a", "ab*"},
        {"aaa", "ab*a*c*a"},
        {"", ""},
        {"", "a*"},
        {"aa", ""},
        {"aa", "a"},
        {"aa", "a*"},
        {"ab", ".*"},
        {"ab", "***.*"},
        {"mississippi", "mis*is*p*."},
        {"acbfaaadea", "a.b*a*ea"},
        {"acbfaaadea", "a*.*.*.*dea"}};
    for (vector<string> item : test) {
        cout << item[0] << ":" << item[1] << ":" << solution.filter(item[1]) << ":" << (solution.isMatch(item[0], item[1]) ? "true" : "false") << endl;
        // cout << item[1] << ":" << solution.filter(item[1]) << endl;
    }
    return 0;
}
