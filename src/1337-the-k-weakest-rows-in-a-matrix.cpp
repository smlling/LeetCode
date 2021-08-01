/*

    1337. 矩阵中战斗力最弱的 K 行

    给你一个大小为 m * n 的矩阵 mat，矩阵由若干军人和平民组成，分别用 1 和 0 表示。
    请你返回矩阵中战斗力最弱的 k 行的索引，按从最弱到最强排序。
    如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于 j，那么我们认为第 i 行的战斗力比第 j 行弱。
    军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。

    示例 1：
    输入：mat = 
    [[1,1,0,0,0],
    [1,1,1,1,0],
    [1,0,0,0,0],
    [1,1,0,0,0],
    [1,1,1,1,1]], 
    k = 3
    输出：[2,0,3]
    解释：
    每行中的军人数目：
    行 0 -> 2 
    行 1 -> 4 
    行 2 -> 1 
    行 3 -> 2 
    行 4 -> 5 
    从最弱到最强对这些行排序后得到 [2,0,3,1,4]

    示例 2：
    输入：mat = 
    [[1,0,0,0],
     [1,1,1,1],
     [1,0,0,0],
     [1,0,0,0]], 
    k = 2
    输出：[0,2]
    解释： 
    每行中的军人数目：
    行 0 -> 1 
    行 1 -> 4 
    行 2 -> 1 
    行 3 -> 1 
    从最弱到最强对这些行排序后得到 [0,2,3,1]
     
    提示：
    m == mat.length
    n == mat[i].length
    2 <= n, m <= 100
    1 <= k <= m
    matrix[i][j] 不是 0 就是 1

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/the-k-weakest-rows-in-a-matrix
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：12 ms, 在所有 C++ 提交中击败了86.08%的用户
    内存消耗：10.2 MB, 在所有 C++ 提交中击败了76.65%的用户

*/
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<tuple<int, int>> vec;
        vector<int>             ans;
        ans.reserve(k);

        // 计算每行的战力并以二元组(行号, 战力值)的形式存储
        for (int i = 0; i < mat.size(); i++) {
            int ce = 0;
            for (auto ele : mat[i]) {
                if (ele) {
                    ce++;
                } else {
                    break;
                }
            }
            vec.push_back({i, ce});
        }

        // 对生成的二元组列表进行排序
        sort(vec.begin(), vec.end(), [](tuple<int, int> t1, tuple<int, int> t2) {
            // 如果战力值相同，比较行号，行号小的放前面
            // 否则战力值小的放前面
            return get<1>(t1) == get<1>(t2) ? get<0>(t1) < get<0>(t2) : get<1>(t1) < get<1>(t2);
        });

        // 取排序后的战力表前k个行号返回
        for (auto ele : vec) {
            if (--k < 0) {
                break;
            }
            ans.push_back(get<0>(ele));
        }
        return ans;
    }
};

int main() {
    // vector<vector<int>> mat1 = {{1, 1, 0, 0, 0},
    //                            {1, 1, 1, 1, 0},
    //                            {1, 0, 0, 0, 0},
    //                            {1, 1, 0, 0, 0},
    //                            {1, 1, 1, 1, 1}};
    vector<vector<int>> mat2 = {{1, 0, 0, 0},
                                {1, 1, 1, 1},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0}};
    Solution            solution;
    cout << "[";
    for (int i : solution.kWeakestRows(mat2, 3)) {
        cout << i << ",";
    }
    cout << "]" << endl;
    return 0;
}