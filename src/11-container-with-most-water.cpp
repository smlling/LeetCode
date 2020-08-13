/*

    11. 盛最多水的容器

    给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

    说明：你不能倾斜容器，且 n 的值至少为 2。

     ![image](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg)

    图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/container-with-most-water
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：740 ms, 在所有 C++ 提交中击败了5.18%的用户(拉垮)
    内存消耗：7.5 MB, 在所有 C++ 提交中击败了60.23%的用户

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    /**
     * 基本思路：
     * 找到最大的两个元素(最高的两个柱子)
     * 那么在这两个柱子之间的任意两个柱子围成的面积一定不可能是最大的
     * 那么只需要在这两个柱子两边进行遍历计算比较出面积最大值即可
    */
    int maxArea(vector<int>& height) {
        // 第一高的柱子的高
        int max = 0;
        // 第二大高度(可能和max相等)
        int mmax = 0;
        // 最大高度的索引
        int imax = 0;
        // 第二大高度的索引
        int immax = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] >= max) {
                immax = imax;
                mmax  = max;
                max   = height[i];
                imax  = i;
            } else if (height[i] >= mmax) {
                mmax  = height[i];
                immax = i;
            }
        }

        // 第一第二高的柱子中位于左边的那个柱子的索引，下称左柱
        int left = imax < immax ? imax : immax;
        // 第一第二高的柱子中位于右边的那个柱子的索引，下称右柱
        int right = imax > immax ? imax : immax;
        // 矩形长度，初始即为左右柱的距离
        int length = right - left;
        // 矩形宽度，初始即为第二高柱子的高度
        int width = mmax;
        // 当前所求矩形的面积
        int square = 0;
        // 返回值
        int ans = width * length;

        // 最终取得最大面积值时两个柱子的索引，用于调试
        int x = left;
        int y = right;

        // 左边从0开始遍历一直到左柱
        for (int l = 0; l <= left; l++) {
            // 右边从右柱开始遍历直到末尾
            for (int r = right; r < height.size(); r++) {
                // 当前矩形长度为左右索引差(柱子的距离)
                length = r - l;
                // 当前矩形高度为左右柱高度的最小值
                width  = min({height[l], height[r]});
                square = width * length;
                if (square > ans) {
                    ans = square;

                    // 用于调试
                    x = l;
                    y = r;
                }
            }
        }

        // 调试输出
        cout << "imax:" << imax + 1 << ",immax:" << immax + 1 << endl;
        cout << x + 1 << ":" << y + 1 << endl;

        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution            solution = Solution();
    vector<vector<int>> test     = {{2, 0}, {8, 10, 14, 0, 13, 10, 9, 9, 11, 11}, {9, 6, 14, 11, 2, 2, 4, 9, 3, 8}, {1, 8, 6, 2, 5, 4, 8, 3, 7}, {1, 2, 1}, {1, 2, 4, 3}};
    for (auto item : test) {
        cout << solution.maxArea(item) << endl;
    }
    return 0;
}
