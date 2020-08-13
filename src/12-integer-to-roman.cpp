/*

    12. 整数转罗马数字

    罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
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
    给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

    示例 1:
    输入: 3
    输出: "III"
    
    示例 2:
    输入: 4
    输出: "IV"

    示例 3:
    输入: 9
    输出: "IX"

    示例 4:
    输入: 58
    输出: "LVIII"
    解释: L = 50, V = 5, III = 3.

    示例 5:
    输入: 1994
    输出: "MCMXCIV"
    解释: M = 1000, CM = 900, XC = 90, IV = 4.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/integer-to-roman
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
    内存消耗：6.3 MB, 在所有 C++ 提交中击败了69.36%的用户

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    string intToRoman(short num, short pow) {
        // 特殊数字直接静态返回(4,9,40,90,400,900)
        if (4 == num) {
            switch (pow) {
                case 1:
                    return "IV";
                    break;
                case 10:
                    return "XL";
                    break;
                case 100:
                    return "CD";
                    break;
                default:
                    break;
            }
        }
        if (9 == num) {
            switch (pow) {
                case 1:
                    return "IX";
                    break;
                case 10:
                    return "XC";
                    break;
                case 100:
                    return "CM";
                    break;
                default:
                    break;
            }
        }

        string ans  = "";
        char   base = 0;
        // 根据当前数字的位置(千位、百位、十位、个位)来确定当前数字对应的罗马数字基底
        switch (pow) {
            case 1:
                base = 'I';
                break;
            case 10:
                base = 'X';
                break;
            case 100:
                base = 'C';
                break;
            case 1000:
                base = 'M';
                break;
            default: break;
        }

        // 当num小于5时(不包括4，4算特殊情况在上面已被处理)
        // 直接返回num个基底(如300中的3是CCC)
        if (num < 5) {
            for (int i = 0; i < num; i++) {
                ans += base;
            }
        } else {
            // 否则当num大于5时(不包括9，9算特殊情况在上面已被处理)
            // 要将num分解为5+n的形式
            // 其中5用对应基底的罗马5表示，n则用n个基底表示
            // 如700中的7分解为5+2，5在以100为基底的罗马数字中表示为D即500
            // 然而2则用两个C表示
            // 因此700表示为DCC
            switch (pow) {
                case 1:
                    ans = "V";
                    break;
                case 10:
                    ans = "L";
                    break;
                case 100:
                    ans = "D";
                    break;
                default:
                    break;
            }
            for (int i = 5; i < num; i++) {
                ans += base;
            }
        }

        return ans;
    }
    string intToRoman(int num) {
        string roman = "";
        short  n     = 0;
        // 题目说过num范围为1～3999,那么此处取每位数字时最多取到千位即可
        for (int i = 1000; i >= 1; i /= 10) {
            n = num / i;
            roman += intToRoman(n, i);
            num %= i;
        }
        return roman;
    }
};

int main(int argc, char* argv[]) {
    Solution    solution = Solution();
    vector<int> test     = {3, 4, 9, 58, 484, 1994};
    for (auto item : test) {
        cout << item << ":" << solution.intToRoman(item) << endl;
    }
    return 0;
}