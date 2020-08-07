/**

    2. 两数相加

    给出两个 非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
    如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
    您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

    示例：
    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/add-two-numbers
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int       val;
    ListNode* next;
    ListNode(int x)
        : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 以l1作为主链，记录头节点用于最终返回
        ListNode* ans = l1;

        // 进位记录
        int carry = 0;

        // 中间量
        int tmp = 0;

        // 先计算l1与l2第一个节点的和结果
        tmp     = l1->val + l2->val + carry;
        l1->val = tmp % 10;
        carry   = tmp / 10;

        // 遍历l1与l2对每位做加法直至任意一条链遍历结束
        while (l1->next && l2->next) {
            l1 = l1->next;
            l2 = l2->next;

            tmp     = l1->val + l2->val + carry;
            l1->val = tmp % 10;
            carry   = tmp / 10;
        }

        // 如果l2有剩余则直接先将剩余的部分移接到l1尾部
        if (l2->next) {
            l1->next = l2->next;
        }

        // 继续遍历l1，每次遍历让该位上的数加上上一步的进位，直至进位为0或l1遍历完时结束
        while (carry && l1->next) {
            l1      = l1->next;
            tmp     = l1->val + carry;
            carry   = tmp / 10;
            l1->val = tmp % 10;
        }

        // 若l1遍历结束仍有进位，则在l1尾部直接新建一个节点存储进位
        if (carry) {
            l1->next = new ListNode(carry);
        }

        return ans;
    }
};

// 根据数组生成list
ListNode* generateList(vector<int> list) {
    ListNode* root  = new ListNode(list[0]);
    ListNode* cusor = root;
    int       count = list.size();
    for (int i = 1; i < count; i++) {
        cusor->next = new ListNode(list[i]);
        cusor       = cusor->next;
    }
    return root;
}

// 打印list
void printList(ListNode* list) {
    cout << "[" << list->val;
    while (list->next) {
        list = list->next;
        cout << "," << list->val;
    }
    cout << "]" << endl;
}

int main(int argc, char* argv[]) {
    ListNode* l1 = generateList({9});
    cout << " ";
    printList(l1);
    cout << "+";
    ListNode* l2 = generateList({1, 9, 9, 9, 9, 9});
    printList(l2);
    cout << "=";
    Solution  solution = Solution();
    ListNode* ans      = solution.addTwoNumbers(l1, l2);
    printList(ans);
}