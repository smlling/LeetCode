/*

    557. 反转字符串中的单词 III

    给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

     

    示例：

    输入："Let's take LeetCode contest"
    输出："s'teL ekat edoCteeL tsetnoc"
     

    提示：

    在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：52 ms, 在所有 C++ 提交中击败了17.20%的用户
    内存消耗：10.9 MB, 在所有 C++ 提交中击败了40.70%的用户

*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    public:
    string reverseWords(string s) {
        stack<char> st = stack<char>();
        string      ans;
        for (char c : s) {
            if (' ' == c) {
                while (!st.empty()) {
                    ans.push_back(st.top());
                    st.pop();
                }
                ans.push_back(' ');
            } else {
                st.push(c);
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution       solution = Solution();
    vector<string> test     = {
        "Let's take LeetCode contest",
        "",
        "a",
    };
    for (string item : test) {
        cout << item << ":" << solution.reverseWords(item) << endl;
    }
    return 0;
}