/**

    41. 缺失的第一个正数

    给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
    请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

    示例 1：
    输入：nums = [1,2,0]
    输出：3

    示例 2：
    输入：nums = [3,4,-1,1]
    输出：2

    示例 3：
    输入：nums = [7,8,9,11,12]
    输出：1

    提示：
    1 <= nums.length <= 5 * 105
    -231 <= nums[i] <= 231 - 1

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/first-missing-positive
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：364 ms, 在所有 C++ 提交中击败了5.05%的用户
    内存消耗：129.5 MB, 在所有 C++ 提交中击败了6.45%的用户

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    private:
    int                      min    = 0x7fffffff;
    int                      minmin = 0x7fffffff;
    unordered_map<int, bool> map;

    public:
    int firstMissingPositive(vector<int>& nums) {
        // 如果只有一个数则判断是否为1，是1则返回2否则返回1
        if (nums.size() == 1) {
            if (nums[0] <= 0) {
                return 1;
            }

            return nums[0] == 1 ? 2 : 1;
        }

        // 为每个出现的数生成映射，并找出最小的两个正数
        for (const auto& n : nums) {
            if (n > 0) {
                if (n <= minmin) {
                    min    = minmin;
                    minmin = n;
                } else if (n < min) {
                    min = n;
                }
                map[n] = true;
            }
        }

        // 如果出现过的最小正数minmin大于1则所求的数一定在1~minmin之间
        if (minmin > 1) {
            for (int i = 1; i < minmin; i++) {
                if (!map[i]) {
                    return i;
                }
            }
        }

        // 如果最小的两个正数相同或者连续，那么所求的数一定还在后面
        if (min == minmin || min == minmin + 1) {
            for (int i = min; i < 0x7fffffff; i++) {
                if (!map[i]) {
                    return i;
                }
            }
        }

        // 如果最小的两个数非连续，则所求的数一定在这两个数之间之间
        for (int i = minmin; i < min; i++) {
            if (!map[i]) {
                return i;
            }
        }

        // 根据题设条件，以上条件都不满足的情况几率为0
        return 0;
    }
};

int main() {
    Solution    solution;
    vector<int> test = {1, 2, 0};
    cout << solution.firstMissingPositive(test) << endl;
}