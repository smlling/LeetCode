/*

    88. 合并两个有序数组

    给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

    说明:
    初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
    你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
     
    示例:
    输入:
    nums1 = [1,2,3,0,0,0], m = 3
    nums2 = [2,5,6],       n = 3
    输出: [1,2,2,3,5,6]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/merge-sorted-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：4 ms, 在所有 C++ 提交中击败了84.53%的用户
    内存消耗：9.2 MB, 在所有 C++ 提交中击败了39.05%的用户

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    // 根据所给的两个数组生成一个汇总的有序数组,最后依次替换掉原来数组的每个元素
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int*                  nums = new int[m + n];
        vector<int>::iterator it1  = nums1.begin();
        vector<int>::iterator it2  = nums2.begin();
        int                   i    = 0;

        while (it1 != (nums1.begin() + m) && it2 != nums2.end()) {
            if (*it1 <= *it2) {
                nums[i++] = *(it1++);
            } else {
                nums[i++] = *(it2++);
            }
        }

        while (it1 != (nums1.begin() + m)) {
            nums[i++] = *(it1++);
        }

        while (it2 != nums2.end()) {
            nums[i++] = *(it2++);
        }

        i = 0;

        while (i < m + n) {
            nums1[i] = nums[i];
            i++;
        }
    }
};

int main(int argc, char* argv[]) {
    Solution    solution = Solution();
    vector<int> nums1    = {1, 2, 3, 0, 0, 0};
    vector<int> nums2    = {2, 5, 6};
    solution.merge(nums1, 3, nums2, 3);
    for (int x : nums1) {
        cout << x << ",";
    }
    cout << endl;
    return 0;
}