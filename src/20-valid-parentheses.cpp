/*

    20. 有效的括号

    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

    有效字符串需满足：
    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
    注意空字符串可被认为是有效字符串。

    示例 1:
    输入: "()"
    输出: true

    示例 2:
    输入: "()[]{}"
    输出: true

    示例 3:
    输入: "(]"
    输出: false

    示例 4:
    输入: "([)]"
    输出: false

    示例 5:
    输入: "{[]}"
    输出: true

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/valid-parentheses
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
    内存消耗：6.6 MB, 在所有 C++ 提交中击败了22.38%的用户

*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    public:
    bool isValid(string s) {
        // 空串直接返回true
        if (0 == s.length()) {
            return true;
        }
        // 如果串长为单数那么一定不会是匹配的
        if (1 == s.length() % 2) {
            return false;
        }
        stack<char> st = stack<char>();
        // 遍历串，碰到左括号就进栈
        // 碰到右括号就出栈，出栈时考虑两种情况
        //      1.栈已为空 2.栈顶的左括号与当前右括号不匹配
        //      这两种情况都表明匹配失败，可以直接返回false了
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    st.push(s[i]);
                    break;
                case ')':
                    if (0 == st.size() || '(' != st.top()) {
                        return false;
                    }
                    st.pop();
                    break;
                case ']':
                    if (0 == st.size() || '[' != st.top()) {
                        return false;
                    }
                    st.pop();
                    break;
                case '}':
                    if (0 == st.size() || '{' != st.top()) {
                        return false;
                    }
                    st.pop();
                    break;
                default:
                    return false;
            }
        }

        // 当串遍历完后栈中仍有元素，说明没有相应的右括号与这部分左括号匹配，返回false
        if (st.size()) {
            return false;
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    Solution       solution = Solution();
    vector<string> test     = {"", "}{", "()", "()[]{}", "(]", "([)]", "{[]}"};
    for (auto item : test) {
        cout << item << ":" << (solution.isValid(item) ? "true" : "false") << endl;
    }
    return 0;
}