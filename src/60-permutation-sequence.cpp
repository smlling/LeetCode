/*

    60.第k个排列

    给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
    按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
    "123"
    "132"
    "213"
    "231"
    "312"
    "321"
    给定 n 和 k，返回第 k 个排列。

    说明：
    给定 n 的范围是 [1, 9]。
    给定 k 的范围是[1,  n!]。

    示例 1:
    输入: n = 3, k = 3
    输出: "213"
    
    示例 2:
    输入: n = 4, k = 9
    输出: "2314"

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/permutation-sequence
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
    内存消耗：6 MB, 在所有 C++ 提交中击败了72.00%的用户

*/

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
    private:
    // 数字索引数组
    int* num;
    // 数组大小(数字个数)
    int numSize;
    // 计算n的阶乘,即n!
    int factorial(int n) {
        if (n > 1) {
            return n * factorial(n - 1);
        }
        return 1;
    }
    // 获取剩下的数字中排第orderNumber位的数字
    char getNum(int orderNumber) {
        char ret = 0;
        for (int i = 0, n = 0; i < numSize; i++) {
            if (num[i] == 0) {
                continue;
            }
            if (++n == orderNumber || orderNumber == 0) {
                ret    = '0' + num[i];
                num[i] = 0;
                break;
            }
        }
        return ret;
    }

    public:
    string getPermutation(int n, int k) {
        num     = new int[n];
        numSize = n;
        // 初始化数字数组
        for (int i = 0; i < n; i++) {
            num[i] = i + 1;
        }

        // 结果字符串
        string ans;

        int   fact;
        short division;
        short mod;
        // n位数字,从左到右循环n轮
        while (n--) {
            // 当前位及左边固定时,右边其他位总共可以表示的不同的数的个数
            fact     = factorial(n);
            division = k / fact;
            mod      = k % fact;

            cout << "n = " << n << ", k = " << k << ", fact = " << fact << ", division = " << division << ", mod = " << mod << endl;

            if (division) {
                if (mod) {
                    ans.push_back(getNum(division + 1));
                    k -= division * fact;
                } else {
                    ans.push_back(getNum(division));
                    k -= (division - 1) * fact;
                }
            } else {
                ans.push_back(getNum(1));
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution            solution = Solution();
    vector<vector<int>> test     = {
        {3, 1},
        {3, 2},
        {3, 3},
        {3, 4},
        {3, 5},
        {3, 6},
        {4, 9},
        {9, 8},
    };
    for (auto item : test) {
        cout << "n = " << item[0] << ", k = " << item[1] << " ans = " << endl
             << solution.getPermutation(item[0], item[1]) << endl;
    }
    return 0;
}