/*

    130. 被围绕的区域

    给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

    找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

    示例:
    X X X X
    X O O X
    X X O X
    X O X X

    运行你的函数后，矩阵变为：
    X X X X
    X X X X
    X X X X
    X O X X
    
    解释:
    被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/surrounded-regions
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：336 ms, 在所有 C++ 提交中击败了5.78%的用户  (一口老血喷起老远)
    内存消耗：13 MB, 在所有 C++ 提交中击败了11.86%的用户

*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
    public:
    // 行数
    int rowCount;
    // 列数
    int colCount;

    bool move(vector<vector<char>>& board, char direction, int row, int col) {
        // 如果已越界表明还没有找到路径上的'X'即
        if (row >= rowCount || row < 0 || col >= colCount || col < 0) {
            return false;
        }
        // 碰到墙'X'或者本轮已走过的格子'E'时返回
        if ('X' == board[row][col] || 'E' == board[row][col]) {
            return true;
        }
        // 走路时标记当前走过的格子
        board[row][col] = 'E';
        // 递归寻径
        switch (direction) {
            case 'u':
                if (move(board, 'u', row - 1, col) && move(board, 'l', row, col - 1) && move(board, 'r', row, col + 1)) {
                    return true;
                }
                break;
            case 'd':
                if (move(board, 'd', row + 1, col) && move(board, 'l', row, col - 1) && move(board, 'r', row, col + 1)) {
                    return true;
                }
                break;
            case 'l':
                if (move(board, 'l', row, col - 1) && move(board, 'u', row - 1, col) && move(board, 'd', row + 1, col)) {
                    return true;
                }
                break;
            case 'r':
                if (move(board, 'r', row, col + 1) && move(board, 'u', row - 1, col) && move(board, 'd', row + 1, col)) {
                    return true;
                }
                break;
            default:
                break;
        }
        // 如果当前路径能够走出迷宫则将当前格子还原
        board[row][col] = 'O';

        return false;
    }

    // 开始新一轮寻径时先将上一次留下的E给还原
    void filter(vector<vector<char>>& board) {
        for (int row = 1; row < rowCount - 1; row++) {
            for (int col = 1; col < colCount; col++) {
                if ('E' == board[row][col]) {
                    board[row][col] = 'O';
                }
            }
        }
    }

    /**
     * 根据题目要求，我们可以假设输入的矩阵为一个迷宫地图
     * 'O'为可以踩的路，'X'为墙壁
     * 那么题目的意思就是找从某一起点（某一个'O'）开始的路能否走出迷宫（'O'一直连通直到地图边界）
     * 如果可以走出迷宫，那么这条路上的每一个'O'都不能用'X'替换
    */
    void solve(vector<vector<char>>& board) {
        // 如果矩阵行数小于等于2，那么它里面的O一定处于边界上，无需处理
        if (board.size() <= 2) {
            return;
        }

        rowCount = board.size();
        colCount = board[0].size();

        for (int row = 1; row < rowCount - 1; row++) {
            for (int col = 1; col < colCount; col++) {
                if ('O' == board[row][col - 1]) {
                    continue;
                }
                cout << row + 1 << ':' << col + 1 << endl;
                cout << "current matrix:" << endl;
                for (auto row : board) {
                    for (auto ele : row) {
                        cout << ele << ' ';
                    }
                    cout << endl;
                }
                if ('O' == board[row][col] || 'E' == board[row][col]) {
                    board[row][col] = 'E';
                    if (move(board, 'r', row, col + 1) && move(board, 'u', row - 1, col) && move(board, 'd', row + 1, col)) {
                        board[row][col] = 'X';
                        continue;
                    } else {
                        board[row][col] = 'O';
                    }
                    filter(board);
                }
            }
        }
    }
};

int main(int argc, char* argv[]) {
    Solution                     solution = Solution();
    vector<vector<vector<char>>> test     = {
        {{'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X', 'O'},
         {'O', 'O', 'O', 'O', 'X', 'X', 'O', 'O', 'X'},
         {'X', 'O', 'X', 'O', 'O', 'X', 'X', 'O', 'X'},
         {'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O'},
         {'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O'},
         {'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
         {'O', 'O', 'O', 'X', 'X', 'O', 'X', 'O', 'X'},
         {'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O'},
         {'O', 'X', 'O', 'O', 'O', 'X', 'O', 'X', 'O'}},
        {{'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O'},
         {'X', 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'X'},
         {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X'},
         {'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X'},
         {'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'O', 'O'},
         {'X', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'O'},
         {'X', 'O', 'X', 'O', 'O', 'X', 'X', 'O', 'X', 'O'},
         {'X', 'X', 'O', 'X', 'X', 'O', 'X', 'O', 'O', 'X'},
         {'O', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
         {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O'}},
        {{'O', 'O', 'O', 'O', 'X', 'X'},
         {'O', 'O', 'O', 'O', 'O', 'O'},
         {'O', 'X', 'O', 'X', 'O', 'O'},
         {'O', 'X', 'O', 'O', 'X', 'O'},
         {'O', 'X', 'O', 'X', 'O', 'O'},
         {'O', 'X', 'O', 'O', 'O', 'O'}},
        {{'O', 'O', 'O', 'O', 'O', 'O'},
         {'O', 'X', 'X', 'X', 'X', 'O'},
         {'O', 'X', 'O', 'O', 'X', 'O'},
         {'O', 'X', 'O', 'O', 'X', 'O'},
         {'O', 'X', 'X', 'X', 'X', 'O'},
         {'O', 'O', 'O', 'O', 'O', 'O'}},
        {{'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X', 'O'},
         {'O', 'O', 'O', 'O', 'X', 'X', 'O', 'O', 'X'},
         {'X', 'O', 'X', 'O', 'O', 'X', 'X', 'O', 'X'},
         {'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O'},
         {'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O'},
         {'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
         {'O', 'O', 'O', 'X', 'X', 'O', 'X', 'O', 'X'},
         {'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O'},
         {'O', 'X', 'O', 'O', 'O', 'X', 'O', 'X', 'O'}},
        {{'X', 'X', 'X', 'X', 'X'},
         {'X', 'O', 'O', 'O', 'X'},
         {'X', 'X', 'O', 'O', 'X'},
         {'X', 'X', 'X', 'O', 'X'},
         {'X', 'O', 'X', 'X', 'X'}}};
    for (auto item : test) {
        cout << "origin matrix:" << endl;
        for (auto row : item) {
            for (auto ele : row) {
                cout << ele << ' ';
            }
            cout << endl;
        }
        solution.solve(item);
        cout << "modified matrix:" << endl;
        for (auto row : item) {
            for (auto ele : row) {
                cout << ele << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}