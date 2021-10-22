/**

    229. 求众数II

    给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
    
    示例 1：
    输入：[3,2,3]
    输出：[3]

    示例 2：
    输入：nums = [1]
    输出：[1]

    示例 3：
    输入：[1,1,1,3,3,2,2,2]
    输出：[1,2]

    提示：
    1 <= nums.length <= 5 * 104
    -109 <= nums[i] <= 109

    进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/majority-element-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：12 ms, 在所有 C++ 提交中击败了68.51%的用户
    内存消耗：15.5 MB, 在所有 C++ 提交中击败了20.01%的用户

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums;
        }

        if (n == 2) {
            return nums[0] == nums[1] ? vector<int>({nums[0]}) : nums;
        }
        vector<int> result;
        sort(nums.begin(), nums.end());
        int base = ceil(n / 3.0);
        int step = nums.size() % 3 == 0 ? base : base - 1;

        for (int i = 0; i < n;) {
            if (result.size() && *(result.end() - 1) == nums[i]) {
                i++;
                continue;
            }

            if (i + step >= n) {
                break;
            }
            if (nums[i] == nums[i + step]) {
                result.push_back(nums[i]);
                i += (step + 1);
            } else {
                i++;
            }
        }

        return result;
    }
};

int main() {
    Solution    solution;
    vector<int> test = {8, 8, 8, 8};
    for (const auto& n : solution.majorityElement(test)) {
        cout << n << " ";
    }
}
