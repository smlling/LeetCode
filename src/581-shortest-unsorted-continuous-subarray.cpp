/*

    581. 最短无序连续子数组

    给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
    请你找出符合题意的 最短 子数组，并输出它的长度。

    示例 1：
    输入：nums = [2,6,4,8,10,9,15]
    输出：5
    解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。

    示例 2：
    输入：nums = [1,2,3,4]
    输出：0

    示例 3：
    输入：nums = [1]
    输出：0
     
    提示：
    1 <= nums.length <= 104
    -105 <= nums[i] <= 105

    进阶：你可以设计一个时间复杂度为 O(n) 的解决方案吗？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：24 ms, 在所有 C++ 提交中击败了93.02%的用户
    内存消耗：25.8 MB, 在所有 C++ 提交中击败了78.25%的用户

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 标识是否已经开始构造子数组
        bool start = false;

        // 首个满足后者小于子数组中最大元素的位置
        int firstBiggerPos = -1;
        // 最后一个满足后者小于子数组中最大元素的位置
        int lastBiggerPos = -1;
        // 子数组中最大元素
        int max = -10E5 - 1;
        // 子数组中最小元素
        int min = 10E5 + 1;
        for (int i = 1; i < nums.size(); i++) {
            if (start && nums[i] == nums[i - 1] && nums[i] < max) {
                lastBiggerPos = i;
            }

            if (nums[i] < nums[i - 1]) {
                if (!start) {
                    firstBiggerPos = i - 1;
                    lastBiggerPos  = i;
                    start          = true;
                } else {
                    lastBiggerPos = i;
                }

                if (nums[i - 1] > max) {
                    max = nums[i - 1];
                }

                if (nums[i] < min) {
                    min = nums[i];
                }
            }

            if (start && nums[i] > nums[i - 1] && nums[i] < max) {
                lastBiggerPos = i;
            }
        }

        // 找出前缀长度，即firstBiggerPos之前的首个大于子数组中最小数的数到firstBiggerPos的长度
        // 如 1, 10, 11, 12, 13, 7, 9, 8, 16
        // 前面步骤完成后，子数组为[13, 7, 9, 8]，最小值为7，可见在13之前的10，11，12也应该纳入子数组，因为它们必定需要被排序
        int prefix = 0;
        for (int i = 0; i < firstBiggerPos; i++) {
            if (nums[i] > min) {
                prefix = firstBiggerPos - i;
                break;
            }
        }

        cout << "prefix: " << prefix << "\tmin: " << min << "\tmax: " << max << "\tfirst: " << firstBiggerPos << "\tlast: " << lastBiggerPos << endl;
        // 无需排序
        if (firstBiggerPos == -1 && lastBiggerPos == -1) {
            return 0;
        }

        return lastBiggerPos - firstBiggerPos + 1 + prefix;
    }
};

int main() {
    Solution    solution;
    vector<int> test =
        // {2, 6, 4, 3, 8, 10, 9, 15};
        // {1, 3, 2, 4, 5};
        // {1, 3, 2, 2, 2};
        // {1, 3, 2, 3, 3};
        // {2, 3, 3, 2, 4};
        // {1, 2, 4, 5, 3};
        {2, 6, 4, 8, 10, 9, 15, 6, 8, 111, 34, 0, 0, 0, 0, 0, 88, -1, 105, 999};
    cout << solution.findUnsortedSubarray(test) << endl;
    return 0;
}