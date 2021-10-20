/**

    42. 接雨水

    给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

    示例 1：
    输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
    输出：6
    解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

    示例 2：
    输入：height = [4,2,0,3,2,5]
    输出：9

    提示：
    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/trapping-rain-water
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：8 ms, 在所有 C++ 提交中击败了72.56%的用户
    内存消耗：15.2 MB, 在所有 C++ 提交中击败了67.45%的用户

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
    int trap(vector<int>& height) {
        // 左柱位置
        int left = 0;
        // 右柱位置
        int right = 0;
        // 遍历结束位置
        int endPos = height.size() - 1;
        // 当前遍历一开始标志
        bool isStart = false;
        // 所求的接水总量
        int sum = 0;

        // 第一次遍历，从左到右
        for (int i = left; i <= endPos; i++) {
            // 寻找第一个非零的柱子作为左柱，找不到则一直接不到水
            if (!isStart) {
                if (height[i] > 0) {
                    isStart = true;
                    left    = i;
                }
                continue;
            }

            right = i;
            if (height[right] >= height[left]) {
                // 找到第一个比左柱高或齐平的柱子作为右柱
                // 这个时候就可以计算一波了，因为在此之后无论柱子再高，那么接的水也不可能更多(木桶效应)
                sum = sum + (right - left - 1) * min(height[right], height[left]);
                for (int j = left + 1; j < right; j++) {
                    sum -= height[j];
                }
                left = right;
            }
        }

        // 在经过上面的计算后可能碰到找不到比左柱齐平或更高的柱子，如示例一中的后半部分
        // 即在左柱右边的柱子全都比它矮
        // 那么我们可以反过来，从右到左遍历

        right   = endPos;
        endPos  = left;
        left    = right;
        isStart = false;

        for (int i = right; i >= endPos; i--) {
            if (!isStart) {
                if (height[i] > 0) {
                    isStart = true;
                    right   = i;
                }
                continue;
            }

            left = i;
            if (height[left] >= height[right]) {
                sum = sum + (right - left - 1) * min(height[right], height[left]);
                for (int j = left + 1; j < right; j++) {
                    sum -= height[j];
                }
                right = left;
            }
        }

        return sum;
    }
};

int main() {
    Solution    solution;
    vector<int> test = {5, 4, 1, 2, 2, 3, 1, 3};
    cout << solution.trap(test) << endl;
}