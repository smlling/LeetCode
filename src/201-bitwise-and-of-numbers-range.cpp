/*

    201. 数字范围按位与

    给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

    示例 1: 
    输入: [5,7]
    输出: 4
    示例 2:

    输入: [0,1]
    输出: 0

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/bitwise-and-of-numbers-range
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：12 ms, 在所有 C++ 提交中击败了63.32%的用户
    内存消耗：6 MB, 在所有 C++ 提交中击败了18.54%的用户

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n) {
            return m;
        }

        if (0 == m) {
            return 0;
        }

        short bit  = 1;
        short seek = 0;
        int   mm   = m;
        // 当前位进位后的数
        unsigned int carry = 0;

        int ans = 0;

        while (mm > 0) {
            // 取出当前m最低位，如果为0，那么结果的当前对应位一定为0
            // 否则
            //     如果当前位进位后的数小于等于n
            //        那么表示在m到n的区间内一定会有当前位为0的数，那么最终结果该位也一定为0
            //        否则结果中该位为0
            if (0 == (mm & 1)) {
                ans += (0 & bit);
            } else {
                carry = (mm + 1) << seek;
                if (n >= carry) {
                    ans += (0 & bit);
                } else {
                    ans += (INT_MAX & bit);
                }
            }
            bit = bit << 1;
            mm  = mm >> 1;
            seek++;
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution            solution = Solution();
    vector<vector<int>> test     = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 6},
        {6, 7},
        {7, 8},
        {4000000, 2147483646},
        {2147483645, 2147483646},
    };

    for (auto item : test) {
        cout << item[0] << ":" << item[1] << ":" << solution.rangeBitwiseAnd(item[0], item[1]) << endl;
    }

    return 0;
}