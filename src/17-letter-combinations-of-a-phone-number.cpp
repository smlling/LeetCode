/**

    17. 电话号码的字母组合

    给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

    给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

    示例 1：
    输入：digits = "23"
    输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

    示例 2：
    输入：digits = ""
    输出：[]

    示例 3：
    输入：digits = "2"
    输出：["a","b","c"]

    提示：
    0 <= digits.length <= 4
    digits[i] 是范围 ['2', '9'] 的一个数字。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
    内存消耗：6.7 MB, 在所有 C++ 提交中击败了10.38%的用户

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    private:
    unordered_map<char, vector<string>> map = {
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}},
    };

    vector<string>* matrixMultiply(const vector<string>& v1, const vector<string>& v2) {
        vector<string>* result = new vector<string>();
        for (const auto& v1Item : v1) {
            for (const auto& v2Item : v2) {
                result->push_back(v1Item + v2Item);
            }
        }
        return result;
    }

    public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return vector<string>();
        }

        vector<string>  init(map[digits[0]]);
        vector<string>* result = &init;

        for (int i = 1; i < digits.length(); i++) {
            result = matrixMultiply(*result, map[digits[i]]);
        }

        return *result;
    }
};

int main() {
    Solution solution;
    bool     startFlag = false;
    for (const auto& item : solution.letterCombinations("999")) {
        if (!startFlag) {
            cout << "\"" << item << "\""
                 << ",";
            startFlag = true;
        } else {
            cout << ", \"" << item << "\""
                 << ",";
        }
    }
}