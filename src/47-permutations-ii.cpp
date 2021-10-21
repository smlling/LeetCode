/**

    47. 全排列II

    给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

    示例 1：
    输入：nums = [1,1,2]
    输出：
    [
        [1,1,2],
        [1,2,1],
        [2,1,1]
    ]

    示例 2：
    输入：nums = [1,2,3]
    输出：
    [
        [1,2,3],
        [1,3,2],
        [2,1,3],
        [2,3,1],
        [3,1,2],
        [3,2,1]
    ]
     
    提示：
    1 <= nums.length <= 8
    -10 <= nums[i] <= 10

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/permutations-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：28 ms, 在所有 C++ 提交中击败了11.36%的用户
    内存消耗：15.9 MB, 在所有 C++ 提交中击败了5.01%的用户

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 1) {
            return vector<vector<int>>({nums});
        }
        vector<int>::const_iterator flag  = nums.begin();
        vector<int>::const_iterator begin = nums.begin();
        vector<int>::const_iterator end   = nums.end();
        vector<vector<int>>         result;
        unordered_map<int, bool>    flagMap;

        while (flag != end) {
            // 当前标杆元素已经排列过直接跳过
            if (flagMap[*flag]) {
                flag++;
                continue;
            }

            flagMap[*flag] = true;

            // 生成不包含当前标杆元素的数组
            vector<int> numsWithoutFlag;
            for (vector<int>::const_iterator it = begin; it != end; it++) {
                if (it == flag) {
                    continue;
                }
                numsWithoutFlag.push_back(*it);
            }

            // 对无标杆元素的数组进行递归求解其全排列
            vector<vector<int>> tmpPre = permuteUnique(numsWithoutFlag);

            // 将每个全排列加上当前标杆
            for (auto& vec : tmpPre) {
                vec.push_back(*flag);
                result.push_back(vec);
            }

            flag++;
        }

        return result;
    }
};

int main() {
    Solution    solution;
    vector<int> test = {1, 2, 3};
    solution.permuteUnique(test);
}