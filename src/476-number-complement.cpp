/**

    476. 数字的补数

    对整数的二进制表示取反（0 变 1 ，1 变 0）后，再转换为十进制表示，可以得到这个整数的补数。

    例如，整数 5 的二进制表示是 "101" ，取反后得到 "010" ，再转回十进制表示得到补数 2 。
    给你一个整数 num ，输出它的补数。

    示例 1：
    输入：num = 5
    输出：2
    解释：5 的二进制表示为 101（没有前导零位），其补数为 010。所以你需要输出 2 。

    示例 2：
    输入：num = 1
    输出：0
    解释：1 的二进制表示为 1（没有前导零位），其补数为 0。所以你需要输出 0 。

    提示：
    1 <= num < 231

    注意：本题与 1009 https://leetcode-cn.com/problems/complement-of-base-10-integer/ 相同

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/number-complement
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
    内存消耗：5.8 MB, 在所有 C++ 提交中击败了72.29%的用户

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    // 假设num为 00001010则运行过程如下：
    // 00001010 ==> 10100000 (左移四位)   此时shift=4
    // 10100000 ^ 11111111 ==> 01011111 (取反)
    // 01011111 ==> 00000101 (右移四位)
    int findComplement(int num) {
        // 前导位数
        unsigned short shift = 0;

        // 找到第一个非零位的前导位数
        while (!((num <<= 1) & 0x80000000)) {
            shift++;
        }

        // 由于最后一次while条件判断时依然会左移一次，因此此处需要shift++
        shift++;

        // 取反
        num ^= 0xffffffff;

        // 右移回去
        num >>= shift;
        return num;
    }
};

int main() {
    Solution    solution;
    vector<int> test = {1, 5, 10, 100, 1000, 2342342};
    for (const auto& t : test) {
        cout << "num: " << t << ", "
             << "complement: " << solution.findComplement(t) << endl;
    }
    return 0;
}