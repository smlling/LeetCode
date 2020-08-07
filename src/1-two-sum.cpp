/**

    1. 两数之和

    给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

    示例:
    给定 nums = [2, 7, 11, 15], target = 9
    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/two-sum
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
    vector<int> twoSum(vector<int>& nums, int target) {
        int n     = 0;
        int count = nums.size();
        for (int i = 0; i < count; i++) {
            n = target - nums[i];
            for (int j = i + 1; j < count; j++) {
                if (n == nums[j]) {
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }
};

int main(int argc, char* argv[]) {
    Solution solution = Solution();

    vector<int> data = {2, 5, 5, 11};
    vector<int> ans  = solution.twoSum(data, 10);

    cout << "[" << ans[0] << "," << ans[1] << "]" << endl;

    return 0;
}