/**

    453. 最小操作次数使数组元素相等

    给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。返回让数组所有元素相等的最小操作次数。

    示例 1：
    输入：nums = [1,2,3]
    输出：3
    解释：
    只需要3次操作（注意每次操作会增加两个元素的值）：
    [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

    示例 2：
    输入：nums = [1,1,1]
    输出：0

    提示：
    n == nums.length
    1 <= nums.length <= 105
    -109 <= nums[i] <= 109
    答案保证符合 32-bit 整数

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：48 ms, 在所有 C++ 提交中击败了21.03%的用户
    内存消耗：27.6 MB, 在所有 C++ 提交中击败了57.94%的用户

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
//              1234
// +(4-1)       4564
// +(6-4)       6766
// +(7-6)       7777
class Solution {
    public:
    int minMoves(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        // 先对数据进行排序
        sort(nums.begin(), nums.end());

        // 所求结果
        uint32_t count = 0;

        // 最小值的位置
        vector<int>::iterator minPos = nums.begin();
        // 最大值的位置
        vector<int>::iterator maxPos = nums.end() - 1;

        // 如果最小值=最大值则说明达成条件可退出循环
        while (*minPos != *maxPos) {
            // 最小值需要加到最大值
            count += (*maxPos - *minPos);
            // 加完之后最尾部的元素跟头部元素相同
            maxPos--;
        }

        return count;
    }
};

int main() {
    Solution    solution;
    vector<int> test = {1, 8, 8, 8};
    cout << solution.minMoves(test) << endl;
}