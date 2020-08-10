/*

    696. 计数二进制子串

    给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。

    重复出现的子串要计算它们出现的次数。

    示例 1 :
    输入: "00110011"
    输出: 6
    解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。

    请注意，一些重复出现的子串要计算它们出现的次数。
    另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。

    示例 2 :
    输入: "10101"
    输出: 4
    解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
    注意：

    s.length 在1到50,000之间。
    s 只包含“0”或“1”字符。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/count-binary-substrings
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    /**
     * 执行用时：32 ms, 在所有 C++ 提交中击败了98.03%的用户
     * 内存消耗：10.8 MB, 在所有 C++ 提交中击败了17.48%的用户
    */
    int countBinarySubstrings(string s) {
        int len = s.length();
        if (len <= 1) {
            return 0;
        }

        // 前一个数是否为1
        bool isOne = s[0] == '1';
        // 当前一轮子串1的个数
        int oneCount = isOne ? 1 : 0;
        // 当前一轮子串0的个数
        int zeroCount = isOne ? 0 : 1;
        // 结果
        int ans = 0;
        // 回溯点（当前轮子串结束的位置）
        int back = 0;
        // 用于标志当前子串是否已经出现了01交替
        bool flag = false;

        int i = 1;

        while (i < len) {
            // 当前位的数字如果和前一位数字相同
            //      则表示当前仍为连续的数字，则计数器自增，指针位置后移
            // 若当前位数字和前一位不同，则表示出现01交替
            //      此时判断本轮子串是否已出现过01交替
            //          若已出现过则表示当前子串结束
            //              此时计算结果并回溯位置开启下一轮子串
            //          否则标记当前子串已出现交替
            //              此时记录当前位置，作为下一轮子串的起点
            if (isOne) {
                if ('1' == s[i]) {
                    oneCount++;
                    i++;
                } else {
                    if (flag) {
                        // 计算本轮子串满足条件的子子串数量
                        // 比如1110000  在一轮结束时oneCount=3,zeroCount=4
                        // 那么它一定有min(oneCount,zeroCount)个子子串满足条件，此处为111000，1100，10（即回文子串的个数）
                        ans += oneCount > zeroCount ? zeroCount : oneCount;
                        flag      = false;
                        i         = back + 1;
                        isOne     = s[back] == '1';
                        oneCount  = isOne ? 1 : 0;
                        zeroCount = isOne ? 0 : 1;
                    } else {
                        back      = i;
                        flag      = true;
                        zeroCount = 1;
                        isOne     = false;
                        i++;
                    }
                }
            } else {
                if ('0' == s[i]) {
                    zeroCount++;
                    i++;
                } else {
                    if (flag) {
                        ans += oneCount > zeroCount ? zeroCount : oneCount;
                        flag      = false;
                        i         = back + 1;
                        isOne     = s[back] == '1';
                        oneCount  = isOne ? 1 : 0;
                        zeroCount = isOne ? 0 : 1;
                    } else {
                        back     = i;
                        flag     = true;
                        isOne    = true;
                        oneCount = 1;
                        i++;
                    }
                }
            }

            if (i == len) {
                ans += oneCount > zeroCount ? zeroCount : oneCount;
                break;
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution       solution = Solution();
    vector<string> test     = {
        "10101",
        "00110011",
        "0000111110",
    };
    for (string item : test) {
        cout << item << ":" << solution.countBinarySubstrings(item) << endl;
    }
    return 0;
}