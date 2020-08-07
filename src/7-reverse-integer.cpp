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
        bool positive               = x >= 0;
        x                           = abs(x);
        deque<int> num              = deque<int>();
        int        mod              = x % 10;
        int        power            = 1;
        int        ans              = 0;
        bool       possibleOverflow = false;
        int        val              = 0;
        x /= 10;
        num.push_back(mod);
        while (x) {
            mod = x % 10;
            x /= 10;
            num.push_back(mod);
        }

        if (10 == num.size()) {
            possibleOverflow = true;
        }

        while (!num.empty()) {
            power = num.size() - 1;
            val   = num.front();
            if (possibleOverflow) {
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