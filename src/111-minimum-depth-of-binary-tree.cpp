/*

    111. 二叉树的最小深度

    给定一个二叉树，找出其最小深度。

    最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

    说明: 叶子节点是指没有子节点的节点。

    示例:
    给定二叉树 [3,9,20,null,null,15,7],

        3
       / \
      9  20
        /  \
       15   7
    返回它的最小深度 2.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：8 ms, 在所有 C++ 提交中击败了97.17%的用户
    内存消耗：17.2 MB, 在所有 C++ 提交中击败了91.36%的用户

*/

#include <iostream>

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
    int  minDepth = INT_MAX;
    int  curDepth = 0;
    void dfs(TreeNode* root) {
        if (NULL == root) {
            return;
        }

        // 如果当前的深度已经超过之前得到的最小深度
        // 则无需继续递归
        if (++curDepth > minDepth) {
            curDepth--;
            return;
        }

        if (NULL == root->left && NULL == root->right) {
            // 递归到叶子节点时判断当前深度是否小于之前得到的最小深度
            // 是则替换，否则返回
            if (curDepth < minDepth) {
                minDepth = curDepth;
            }
        } else {
            dfs(root->left);
            dfs(root->right);
        }

        curDepth--;
    }

    public:
    int minDepth(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        dfs(root);
        return minDepth;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}