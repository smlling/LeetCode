/**

    66. 加一

    给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
    最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
    你可以假设除了整数 0 之外，这个整数不会以零开头。

    示例 1：
    输入：digits = [1,2,3]
    输出：[1,2,4]
    解释：输入数组表示数字 123。

    示例 2：
    输入：digits = [4,3,2,1]
    输出：[4,3,2,2]
    解释：输入数组表示数字 4321。

    示例 3：
    输入：digits = [0]
    输出：[1]
     
    提示：
    1 <= digits.length <= 100
    0 <= digits[i] <= 9

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/plus-one
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：4 ms, 在所有 C++ 提交中击败了51.75%的用户
    内存消耗：8.6 MB, 在所有 C++ 提交中击败了35.49%的用户

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::iterator begin   = digits.begin();
        vector<int>::iterator current = digits.end() - 1;

        // 从右往左遇9进位
        while (true) {
            if (*current != 9) {
                (*current)++;
                return digits;
            }
            (*current) = 0;
            current--;

            // 越界是在首部插入进位的1
            if (current < begin) {
                digits.insert(begin, 1);
                return digits;
            }
        }
    }
};

int main() {
    Solution    solution;
    vector<int> test = {1, 8, 8, 8};
    for (const auto& n : solution.plusOne(test)) {
        cout << n;
    }
    cout << endl;
}