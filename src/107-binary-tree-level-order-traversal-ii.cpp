/*

    107. 二叉树的层次遍历 II

    给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

    例如：
    给定二叉树 [3,9,20,null,null,15,7],

        3
       / \
      9  20
        /  \
       15   7
       
    返回其自底向上的层次遍历为：
    [
        [15,7],
        [9,20],
        [3]
    ]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：8 ms, 在所有 C++ 提交中击败了55.76%的用户
    内存消耗：11.5 MB, 在所有 C++ 提交中击败了98.80%的用户

*/

#include <iostream>
#include <stack>
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
    private:
    // 树的深度(最大深度)
    int treeDepth;

    // 获取以root为根的二叉树最大深度
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int depth = 1;
        if (root->left || root->right) {
            depth += max({maxDepth(root->left), maxDepth(root->right)});
        }

        return depth;
    }

    // 层序遍历(自底向上)
    void levelOrder(vector<vector<int>>& ans, TreeNode* root, int depth) {
        if (!root) {
            return;
        }

        // 当前是第几层(当前深度)
        depth++;

        // 由于是自底向上层序遍历,因此当前层应该存储的位置为树的深度-当前深度
        ans[treeDepth - depth].push_back(root->val);

        // 对左子树层序遍历
        levelOrder(ans, root->left, depth);

        // 对右子树层序遍历
        levelOrder(ans, root->right, depth);
    }

    public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        treeDepth = maxDepth(root);
        cout << "TreeDepth:" << treeDepth << endl;
        vector<vector<int>> ans = vector<vector<int>>(treeDepth);
        levelOrder(ans, root, 0);
        return ans;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}