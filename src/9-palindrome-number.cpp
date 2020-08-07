/*

    9. 回文数

    判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

    示例 1:
    输入: 121
    输出: true

    示例 2:
    输入: -121
    输出: false
    解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

    示例 3:
    输入: 10
    输出: false
    解释: 从右向左读, 为 01 。因此它不是一个回文数。
    
    进阶:
    你能不将整数转为字符串来解决这个问题吗？

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/palindrome-number
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

*/

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    /*
        执行用时：32 ms, 在所有 C++ 提交中击败了16.91%的用户
        内存消耗：15.4 MB, 在所有 C++ 提交中击败了5.06%的用户
    */
    bool isPalindrome(int x) {
        // 如果x为负数则其一定不可能是回文数
        if (x < 0) {
            return false;
        }
        // 用双队列存储数字
        deque<int> num = deque<int>();
        // 中间变量，用于表示当前操作的数字
        int tmp = 0;
        // 提取出每一位数字入队
        for (int i = 1000000000; i >= 1; i /= 10) {
            tmp = x / i;
            if (0 == tmp && num.empty()) {
                continue;
            }
            x -= tmp * i;
            num.push_back(tmp);
        }

        // 遍历队列
        while (!num.empty()) {
            // 如果队列中只剩一个数字则表示判断结束，是回文数
            if (1 == num.size()) {
                return true;
            }

            // 如果收尾数字不一样则不是回文数
            if (num.front() != num.back()) {
                return false;
            }

            // 收尾的元素出队进行下一轮的收尾比较
            num.pop_front();
            num.pop_back();
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    Solution    solution = Solution();
    vector<int> test     = {121, 1221, 12345, -121, 10};
    for (auto item : test) {
        cout << item << ":" << solution.isPalindrome(item) << endl;
    }
    return 0;
}