/*

    110.平衡二叉树

    给定一个二叉树，判断它是否是高度平衡的二叉树。

    本题中，一棵高度平衡二叉树定义为：
        一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

    示例 1:
    给定二叉树 [3,9,20,null,null,15,7]
      3
     / \
    9  20
      /  \
    15    7
    返回 true 。

    示例 2:

    给定二叉树 [1,2,2,3,3,null,null,4,4]

           1
          / \
         2   2
       / \
      3   3
     / \
    4   4
    返回 false 。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/balanced-binary-tree
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    /**
     * 执行用时：8 ms, 在所有 C++ 提交中击败了99.07%的用户
     * 内存消耗：15.1 MB, 在所有 C++ 提交中击败了16.76%的用户
    */

    bool isBalanced(TreeNode* root, int& deep) {
        if (NULL == root) {
            return true;
        }

        deep++;

        int ldeep = 0;
        int rdeep = 0;

        // 如果当前节点的左子树为平衡树且右子树也为平衡树
        // 则将本树的深度累加到父节点上
        // 否则只要有一边的子树不是平衡树就可以判定整棵树不是平衡树了，直接层层返回false
        if (isBalanced(root->left, ldeep)) {
            if (isBalanced(root->right, rdeep)) {
                // 本树的深度为左右子树深度的最大值
                deep += (ldeep > rdeep) ? ldeep : rdeep;
                cout << "node:" << root->val << " ldeep:" << ldeep << " rdeep:" << rdeep << endl;
                return abs(ldeep - rdeep) <= 1;
            } else {
                cout << "false at:" << root->right->val << endl;
                return false;
            }
        } else {
            cout << "false at:" << root->left->val << endl;
            return false;
        }
    }
    bool isBalanced(TreeNode* root) {
        if (NULL == root) {
            return true;
        }

        int ldeep = 0;
        int rdeep = 0;

        if (isBalanced(root->left, ldeep)) {
            if (isBalanced(root->right, rdeep)) {
                return abs(ldeep - rdeep) <= 1;
            } else {
                cout << "false at:" << root->right->val << endl;
                return false;
            }
        } else {
            cout << "false at:" << root->left->val << endl;
            return false;
        }
    }

    /**
     * 执行用时：12 ms, 在所有 C++ 提交中击败了92.31%的用户
     * 内存消耗：14.3 MB, 在所有 C++ 提交中击败了92.29%的用户

    bool isBalanced(TreeNode* root) {
        if (NULL == root) {
            return true;
        }

        int ldeep = deep(root->left);
        if (-1 == ldeep) {
            cout << "false at:" << root->right->val << endl;
            return false;
        }
        int rdeep = deep(root->right);
        if (-1 == rdeep) {
            cout << "false at:" << root->left->val << endl;
            return false;
        }

        if (abs(ldeep - rdeep) <= 1) {
            return true;
        } else {
            cout << "false at:" << root->val << endl;
            return false;
        }
    }

    // 递归求树的深度，过程中如果检测到自己不是平衡树则层层返回-1，从而达到提前结束的目的
    int deep(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }

        int ldeep = deep(root->left);
        if (-1 == ldeep) {
            return -1;
        }
        int rdeep = deep(root->right);
        if (-1 == rdeep) {
            return -1;
        }

        cout << "node:" << root->val << " ldeep:" << ldeep << " rdeep:" << rdeep << endl;

        if (abs(ldeep - rdeep) <= 1) {
            return (ldeep > rdeep ? ldeep : rdeep) + 1;
        } else {
            return -1;
        }
    }

    */
};

main(int argc, char* argv[]) {
    return 0;
}