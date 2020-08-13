/*

    43. 字符串相乘

    给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

    示例 1:
    输入: num1 = "2", num2 = "3"
    输出: "6"

    示例 2:
    输入: num1 = "123", num2 = "456"
    输出: "56088"

    说明：
    num1 和 num2 的长度小于110。
    num1 和 num2 只包含数字 0-9。
    num1 和 num2 均不以零开头，除非是数字 0 本身。
    不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/multiply-strings
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：72 ms, 在所有 C++ 提交中击败了15.00%的用户 (啊这)
    内存消耗：13 MB, 在所有 C++ 提交中击败了9.68%的用户

*/

#include <iostream>

using namespace std;

class Solution {
    public:
    /**
     * 数字字符转short
    */
    short charToNum(char c) {
        return c - '0';
    }
    /**
     * short数字转数字字符
    */
    char numToChar(short n) {
        return '0' + n;
    }
    /**
     * 字符串相加
    */
    string add(string num1, string num2) {
        // 最终结果
        string ans = "";
        // 进位
        short carry = 0;
        // 局部和
        short sum = 0;
        // 当前运算位游标
        int seek1 = num1.length() - 1;
        int seek2 = num2.length() - 1;

        // 从右到左按位依次相加
        while (seek1 >= 0 && seek2 >= 0) {
            sum = charToNum(num1[seek1--]) + charToNum(num2[seek2--]) + carry;
            ans += numToChar(sum % 10);
            carry = sum / 10;
        }

        // 稍长的那一个数字串剩余部分进行处理
        while (seek1 >= 0) {
            sum = charToNum(num1[seek1--]) + carry;
            ans += numToChar(sum % 10);
            carry = sum / 10;
        }
        while (seek2 >= 0) {
            sum = charToNum(num2[seek2--]) + carry;
            ans += numToChar(sum % 10);
            carry = sum / 10;
        }

        // 如果仍有进位，则该进位直接加到末尾
        if (carry) {
            ans += numToChar(carry);
        }

        // 由于加的时候是从右到左加的，因此生成的结果也是反过来的
        // 对结果进行一次反转
        reverse(ans.begin(), ans.end());

        return ans;
    }
    /**
     * 计算xxx * y
    */
    string multiply(string num1, char times) {
        if ('0' == times) {
            return string(1, '0');
        }

        if ('1' == times) {
            return num1;
        }

        string ans     = "";
        short  num2    = charToNum(times);
        short  carry   = 0;
        short  product = 0;
        for (int i = num1.length() - 1; i >= 0; i--) {
            product = charToNum(num1[i]) * num2 + carry;
            ans += numToChar(product % 10);
            carry = product / 10;
        }

        if (carry) {
            ans += numToChar(carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        if ((1 == num1.length() && '0' == num1[0]) || (1 == num2.length() && '1' == num2[0])) {
            return num1;
        }

        if ((1 == num2.length() && '0' == num2[0]) || (1 == num1.length() && '1' == num1[0])) {
            return num2;
        }

        string ans = "0";

        // 以num1为基准，用它的每一位数去乘以num2
        for (int seek = 0; seek < num1.length(); seek++) {
            string tmp = "";
            tmp        = multiply(num2, num1[seek]);
            // 乘出来的结果要添加0
            // 如123*456，用1*456后要添加2个0
            for (int i = 1; i <= num1.length() - 1 - seek; i++) {
                tmp += '0';
            }
            ans = add(ans, tmp);
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution solution = Solution();

    cout << solution.multiply("123456", "456") << endl;

    return 0;
}