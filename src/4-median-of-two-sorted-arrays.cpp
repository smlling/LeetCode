/*

    4. 寻找两个正序数组的中位数

    给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
    请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
    你可以假设 nums1 和 nums2 不会同时为空。

     

    示例 1:
    nums1 = [1, 3]
    nums2 = [2]

    则中位数是 2.0
    示例 2:
    nums1 = [1, 2]
    nums2 = [3, 4]

    则中位数是 (2 + 3)/2 = 2.5

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i    = 0;
        int j    = 0;

        // 合并数组
        vector<int> merge;

        // 遍历nums1,nums2将他们按顺序填入合并数组直至任意一个数组被遍历完
        while (i < len1 && j < len2) {
            merge.push_back(nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
        }

        // 如果nums1数组有余项则依次填入合并数组
        while (i < len1) {
            merge.push_back(nums1[i++]);
        }

        // 如果nums2数组有余项则依次填入合并数组
        while (j < len2) {
            merge.push_back(nums2[j++]);
        }

        // 此时merge数组是一个有序的数组，直接按照数学方法计算中位数即可
        int merge_size = merge.size();
        if (merge_size % 2 == 0) {
            // 因为数组下标从0开始故要减一
            return (merge[merge_size / 2 - 1] + merge[merge_size / 2]) / 2.0;
        } else {
            return (double)merge[merge_size / 2];
        }
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums1 = {1}, nums2 = {0};
    Solution    solution = Solution();
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}