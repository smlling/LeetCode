/*

    7. 整数反转

    给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

    示例 1:
    输入: 123
    输出: 321

    示例 2:
    输入: -123
    输出: -321

    示例 3:
    输入: 120
    输出: 21
    
    注意:
    假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31−1]。-2147483648 ~2147483647 请根据这个假设，如果反转后整数溢出那么就返回 0。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reverse-integer
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：4 ms, 在所有 C++ 提交中击败了51.69%的用户
    内存消耗：7.1 MB, 在所有 C++ 提交中击败了5.02%的用户 (难受)

*/

#include <deque>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
    public:
    int reverse(int x) {
        // 是否为正书
        bool positive = x >= 0;
        x             = abs(x);
        // 循环队列，用于记录每一位数字
        deque<int> num = deque<int>();
        // 最后一位数字
        int mod = x % 10;
        // 幂方数
        int power = 1;
        // 结果
        int ans = 0;
        // 是否可能溢出
        bool possibleOverflow = false;
        // 中间变量，用于存储当前操作的数字
        int val = 0;
        x /= 10;
        num.push_back(mod);
        // 循环将每一位数字放入队列
        while (x) {
            mod = x % 10;
            x /= 10;
            num.push_back(mod);
        }

        // 如果位数为10位则反转后有可能产生溢出
        if (10 == num.size()) {
            possibleOverflow = true;
        }

        // 从队列头部（对应x的最后一位数字）开始遍历
        while (!num.empty()) {
            // 当前位的数字需要乘上10的幂方数
            power = num.size() - 1;
            // 当前位数字的值
            val = num.front();
            // 判断溢出
            if (possibleOverflow) {
                // 如果当某一位于最值的对应位相等则仍有溢出可能
                // 如果小于则一定不会溢出，可以将可能溢出标志置为false，这样后续位的计算中就不需要再判断溢出了
                // 如果大于则已经溢出，可以直接返回了
                switch (num.size()) {
                    case 10:
                        if (val > 2) {
                            return 0;
                        } else if (val < 2) {
                            possibleOverflow = false;
                        }
                        break;
                    case 9:
                        if (val > 1) {
                            return 0;
                        } else if (val < 1) {
                            possibleOverflow = false;
                        }
                        break;
                    case 8:
                        if (val > 4) {
                            return 0;
                        } else if (val < 4) {
                            possibleOverflow = false;
                        }
                        break;
                    case 7:
                        if (val > 7) {
                            return 0;
                        } else if (val < 7) {
                            possibleOverflow = false;
                        }
                        break;
                    case 6:
                        if (val > 4) {
                            return 0;
                        } else if (val < 4) {
                            possibleOverflow = false;
                        }
                        break;
                    case 5:
                        if (val > 8) {
                            return 0;
                        } else if (val < 8) {
                            possibleOverflow = false;
                        }
                        break;
                    case 4:
                        if (val > 3) {
                            return 0;
                        } else if (val < 3) {
                            possibleOverflow = false;
                        }
                        break;
                    case 3:
                        if (val > 6) {
                            return 0;
                        } else if (val < 6) {
                            possibleOverflow = false;
                        }
                        break;
                    case 2:
                        if (val > 4) {
                            return 0;
                        } else if (val < 4) {
                            possibleOverflow = false;
                        }
                        break;
                    case 1:
                        // 注意正负数的最值最后一位不同
                        if ((positive && val > 7) || (!positive && val > 8)) {
                            return 0;
                        }
                        break;
                    default:
                        break;
                }
            }
            ans += (val * pow(10, power));
            num.pop_front();
        }

        return positive ? ans : -ans;
    }
};

int main(int argc, char* argv[]) {
    Solution    solution = Solution();
    vector<int> test     = {-2147483412, 1563847412, 456, 0, 1, -99, -1, -2147483647, 2147483647};
    for (auto item : test) {
        cout << item << ":" << solution.reverse(item) << endl;
    }
    return 0;
}