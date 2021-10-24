/**

    32. 最长有效括号

    给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

    示例 1：
    输入：s = "(()"
    输出：2
    解释：最长有效括号子串是 "()"

    示例 2：
    输入：s = ")()())"
    输出：4
    解释：最长有效括号子串是 "()()"

    示例 3：
    输入：s = ""
    输出：0

    提示：
    0 <= s.length <= 3 * 104
    s[i] 为 '(' 或 ')'

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/longest-valid-parentheses
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：4 ms, 在所有 C++ 提交中击败了86.00%的用户
    内存消耗：7.2 MB, 在所有 C++ 提交中击败了47.00%的用户

*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    public:
    // 遇到左括号时将当前的有效长度压栈
    // 如果字符串扫描结束后,栈非空,则说明字符串中有未被匹配的左括号
    //      结束时栈中剩余元素的个数+1即为字符串中符合条件的最长字串的个数
    //      求出每一段最长字串中的最大值即可
    //                      ( ) ( ( )
    //      round           0 2 2 2 4
    //      stack           0   2 2
    //      结束时栈中剩了个一个2,说明字符串中包含两段符合条件的字串,长度分别为4-2=2和2-0=2,那么最大值也为2
    int longestValidParentheses(string s) {
        stack<int> st;
        int        maxMatch = 0;
        int        round    = 0;
        for (string::iterator itInner = s.begin(); itInner != s.end(); itInner++) {
            switch (*itInner) {
                case '(':
                    st.push(round);
                    break;
                case ')':
                    if (st.empty()) {
                        maxMatch = maxMatch > round ? maxMatch : round;
                        round    = 0;
                    } else {
                        st.pop();
                        round += 2;
                    }
                    break;
                default:
                    break;
            }
        }

        while (!st.empty()) {
            int flag = st.top();
            st.pop();
            maxMatch = max(maxMatch, round - flag);
            round    = flag;
        }

        return max(maxMatch, round);
    }
};

int main() {
    Solution solution;
    cout << solution.longestValidParentheses("()((()()") << endl;
}