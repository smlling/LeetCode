/*

    6. Z 字形变换

    将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

    比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
    L   C   I   R
    E T O E S I I G
    E   D   H   N
    之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

    请你实现这个将字符串进行指定行数变换的函数：

    string convert(string s, int numRows);

    示例 1:
    输入: s = "LEETCODEISHIRING", numRows = 3
    输出: "LCIRETOESIIGEDHN"

    示例 2:
    输入: s = "LEETCODEISHIRING", numRows = 4
    输出: "LDREOEIIECIHNTSG"
    
    解释:
    L     D     R
    E   O E   I I
    E C   I H   N
    T     S     G

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/zigzag-conversion
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：12 ms, 在所有 C++ 提交中击败了94.31%的用户
    内存消耗：8.2 MB, 在所有 C++ 提交中击败了79.27%的用户

*/

#include <iostream>

using namespace std;

class Solution {
    public:
    string convert(string s, int numRows) {
        // 如果行数为1则不需要运算直接返回原字符串
        if (1 == numRows) {
            return s;
        }

        // 结果字符串
        string ans = "";
        // 串长
        int len = s.length();
        // 最大步长（首行或尾行的每两个元素之间相隔的距离）
        int maxStep = 2 * numRows - 2;
        // 反转flag
        bool flag = true;
        // 当前指针位置
        int cursor = 0;

        // 首行字符元素提取，每个元素相隔为最大步长
        for (int i = 0; i < len; i += maxStep) {
            ans += s[i];
        }

        // 循环提取首行尾行中间行的字符元素
        for (int i = 1; i <= numRows - 2; i++) {
            // 先将行首元素拼接
            ans += s[i];
            // 初始化指针位置
            cursor = i;
            // 初始化反转flag
            flag = true;
            // 循环提取本行剩余元素
            while (true) {
                if (flag) {
                    // 第偶数个元素的位置（以下公式通过画图找出）
                    cursor += (2 * numRows - 1) - (2 * i + 1);
                } else {
                    // 第奇数个元素的位置（以下公式通过画图找出）
                    cursor += maxStep - ((2 * numRows - 1) - (2 * i + 1));
                }
                // 位置越界则本行元素提取结束
                if (cursor >= len) {
                    break;
                }
                ans += s[cursor];
                flag = !flag;
            }
        }

        // 尾行元素提取，与首行一样每个元素也是相隔最大步长
        for (int i = numRows - 1; i < len; i += maxStep) {
            ans += s[i];
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution solution = Solution();
    cout << "A:1:" << solution.convert("A", 1) << endl;
    cout << "AB:1:" << solution.convert("AB", 1) << endl;
    cout << "LEETCODEISHIRING:3:" << solution.convert("LEETCODEISHIRING", 3) << endl;
    cout << "LEETCODEISHIRING:4:" << solution.convert("LEETCODEISHIRING", 4) << endl;
    return 0;
}