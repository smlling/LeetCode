/*

    13. 罗马数字转整数

    罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

    字符          数值
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

    通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

    I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
    X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
    C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
    给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

    示例 1:
    输入: "III"
    输出: 3

    示例 2:
    输入: "IV"
    输出: 4

    示例 3:
    输入: "IX"
    输出: 9

    示例 4:
    输入: "LVIII"
    输出: 58
    解释: L = 50, V= 5, III = 3.

    示例 5:
    输入: "MCMXCIV"
    输出: 1994
    解释: M = 1000, CM = 900, XC = 90, IV = 4.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/roman-to-integer
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：24 ms, 在所有 C++ 提交中击败了63.32%的用户
    内存消耗：7.9 MB, 在所有 C++ 提交中击败了60.46%的用户

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
    int romanToInt(string s) {
        int                      ans = 0;
        int                      len = s.length();
        unordered_map<char, int> map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        // 当前位罗马数字对应的阿拉伯数字
        int cur = 0;
        // 当前位的后一位罗马数字对应的阿拉伯数字
        int next = 0;

        for (int i = 0; i < len; i++) {
            cur = map[s[i]];
            // 如果当前位的后一位有数，且其大小比当前位的大
            // 说明当前位与后一位是一个整体
            // 且这个整体的值位后一位代表的阿拉伯数减当前位所代表的阿拉伯数
            // 如IV为4(5-1)、IX为9(10-1)、CM为900(1000-100)等
            if (i + 1 < len) {
                next = map[s[i + 1]];
                if (next > cur) {
                    ans += next - cur;
                    i++;
                    continue;
                }
            }
            ans += cur;
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution       solution = Solution();
    vector<string> test     = {
        "III",
        "IV",
        "LVIII",
        "MCMXCIV",
    };
    for (auto item : test) {
        cout << item << ":" << solution.romanToInt(item) << endl;
    }
    return 0;
}