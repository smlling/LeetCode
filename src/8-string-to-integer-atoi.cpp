/*

    8. 字符串转换整数 (atoi)

    请你来实现一个 atoi 函数，使其能将字符串转换成整数。

    首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：

    如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
    假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
    该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
    注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。

    在任何情况下，若函数不能进行有效的转换时，请返回 0 。

    提示：
    本题中的空白字符只包括空格字符 ' ' 。
    假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−2^31,  2^31−1]。如果数值超过这个范围，请返回  INT_MAX (2^31−1) 或 INT_MIN (−2^31) 。

    示例 1:
    输入: "42"
    输出: 42

    示例 2:
    输入: "   -42"
    输出: -42
    解释: 第一个非空白字符为 '-', 它是一个负号。
         我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。

    示例 3:
    输入: "4193 with words"
    输出: 4193
    解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。

    示例 4:
    输入: "words and 987"
    输出: 0
    解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
        因此无法执行有效的转换。
        
    示例 5:
    输入: "-91283472332"
    输出: -2147483648
    解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
         因此返回 INT_MIN (−2^31) 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/string-to-integer-atoi
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：4 ms, 在所有 C++ 提交中击败了80.95%的用户
    内存消耗：7.3 MB, 在所有 C++ 提交中击败了10.53%的用户(优化空间非常大)

*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    public:
    int myAtoi(string str) {
        // 字符串长度
        int len = str.length();
        // 用于存储每一位数字
        stack<int> num = stack<int>();
        // 当前操作的字符
        char cur = 0;
        // 是否已经开始匹配有效数字（即是否出现了第一个有效字符 + - 0-9）
        bool numStart = false;
        // 是否已经开始记录数字（即是否开始记录有效数字，用于排除头部连续0）
        bool recStart = false;
        // 是否位正数
        bool positive = true;
        // 结果
        long ans = 0;
        // 位数
        int size = 0;

        // 遍历字符串
        for (int i = 0; i < len; i++) {
            cur = str[i];
            // 如果没有开始匹配有效数字则匹配第一个有效字符
            if (!numStart) {
                // 匹配到空格则直接跳过
                if (' ' == cur) {
                    continue;
                }
                // 匹配到-则将正数标志置为false
                if ('-' == cur) {
                    positive = false;
                    numStart = true;
                } else if ('+' == cur) {
                    numStart = true;
                } else if ('0' <= cur && '9' >= cur) {
                    // 匹配到数字
                    // 如果是非零数字则当作有效数字入栈并开启记录标志
                    if ('0' != cur) {
                        num.push(cur - '0');
                        size++;
                        recStart = true;
                    }
                    numStart = true;
                } else {
                    return 0;
                }
            } else {
                if ('0' <= cur && '9' >= cur) {
                    // 如果还未开启记录标志则需要判断当前字符是否为0
                    // 如果是零则无意义继续跳过
                    // 如果不是零则当作有效数字入栈并开始记录标志
                    if (!recStart) {
                        if ('0' == cur) {
                            continue;
                        } else {
                            recStart = true;
                        }
                    }
                    // 否则已开启记录标志时直接将数字入栈
                    num.push(cur - '0');
                    size++;
                    // 如果入栈后位数超过了10位则表示已经溢出，可以直接根据正负号提前返回了
                    if (size > 10) {
                        return positive ? INT_MAX : INT_MIN;
                    }
                } else {
                    break;
                }
            }
        }

        // 数字循环出栈计算结果
        // 出栈时的顺序是低位先出栈因此幂方从1开始步进10倍
        // 需要注意的是虽然上面保证了数字的位数最多为10位，即幂方i最多到1000000000，但是由于for循环的特性，
        // 在第10次循环结束后i仍然会乘以10从而导致i的大小超过int范围，因此此处将i定义为long
        for (long i = 1; !num.empty(); i *= 10) {
            ans += num.top() * i;
            num.pop();
        }

        if (!positive) {
            ans = -ans;
        }

        return (INT_MIN <= ans && INT_MAX >= ans) ? ans : (positive ? INT_MAX : INT_MIN);
    }
};

int main(int argc, char* argv[]) {
    Solution       solution = Solution();
    vector<string> test     = {"0-1", "2147483646", "-000000000000001",
                           "  0000000000012345678",
                           "    +123456789555",
                           "-456456454600", "    asd1325465", "   123asd", "123"};
    for (auto item : test) {
        cout << item << ":" << solution.myAtoi(item) << endl;
    }
    return 0;
}