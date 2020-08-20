/*

    529. 扫雷游戏

    让我们一起来玩扫雷游戏！

    给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。

    现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：

    如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
    如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
    如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
    如果在此次点击中，若无更多方块可被揭露，则返回面板。
     

    示例 1：
    输入: 
    [['E', 'E', 'E', 'E', 'E'],
    ['E', 'E', 'M', 'E', 'E'],
    ['E', 'E', 'E', 'E', 'E'],
    ['E', 'E', 'E', 'E', 'E']]
    Click : [3,0]
    输出: 
    [['B', '1', 'E', '1', 'B'],
    ['B', '1', 'M', '1', 'B'],
    ['B', '1', '1', '1', 'B'],
    ['B', 'B', 'B', 'B', 'B']]
    解释:
    ![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/minesweeper_example_1.png)

    示例 2：
    输入: 
    [['B', '1', 'E', '1', 'B'],
    ['B', '1', 'M', '1', 'B'],
    ['B', '1', '1', '1', 'B'],
    ['B', 'B', 'B', 'B', 'B']]
    Click : [1,2]
    输出: 
    [['B', '1', 'E', '1', 'B'],
    ['B', '1', 'X', '1', 'B'],
    ['B', '1', '1', '1', 'B'],
    ['B', 'B', 'B', 'B', 'B']]
    解释:
    ![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/minesweeper_example_2.png)

    注意：
    输入矩阵的宽和高的范围为 [1,50]。
    点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。
    输入面板不会是游戏结束的状态（即有地雷已被挖出）。
    简单起见，未提及的规则在这个问题中可被忽略。例如，当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/minesweeper
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：68 ms, 在所有 C++ 提交中击败了76.70%的用户
    内存消耗：13.6 MB, 在所有 C++ 提交中击败了84.90%的用户

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    private:
    // 计算环绕地雷数
    int getSurroundSweeperCpint(vector<vector<char>>& board, int row, int col) {
        int count = 0;
        if (row - 1 >= 0 && 'M' == board[row - 1][col]) {
            count++;
        }
        if (row + 1 < board.size() && 'M' == board[row + 1][col]) {
            count++;
        }
        if (col - 1 >= 0 && 'M' == board[row][col - 1]) {
            count++;
        }
        if (col + 1 < board[0].size() && 'M' == board[row][col + 1]) {
            count++;
        }
        if (row - 1 >= 0 && col - 1 >= 0 && 'M' == board[row - 1][col - 1]) {
            count++;
        }
        if (row + 1 < board.size() && col + 1 < board[0].size() && 'M' == board[row + 1][col + 1]) {
            count++;
        }
        if (row - 1 >= 0 && col + 1 < board[0].size() && 'M' == board[row - 1][col + 1]) {
            count++;
        }
        if (row + 1 < board.size() && col - 1 >= 0 && 'M' == board[row + 1][col - 1]) {
            count++;
        }
        return count;
    }

    // 递归翻土
    void updateBoard(vector<vector<char>>& board, int row, int col) {
        // 越界则返回
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) {
            return;
        }

        // 如果当前位置为安全位置
        //      则先判断周围有无地雷
        //          有则标示数量后返回
        //          无则继续递归翻土
        // 否则表示当前位置是已经翻过到土或地雷时，结束递归
        if ('E' == board[row][col]) {
            int n = 0;
            // 如果当前点击点周围有地雷，则将其改为环绕地雷数量后返回
            if ((n = getSurroundSweeperCpint(board, row, col)) > 0) {
                board[row][col] = (char)(48 + n);
                return;
            }
            board[row][col] = 'B';
        } else {
            return;
        }

        updateBoard(board, row - 1, col - 1);
        updateBoard(board, row + 1, col + 1);
        updateBoard(board, row + 1, col - 1);
        updateBoard(board, row - 1, col + 1);
        updateBoard(board, row - 1, col);
        updateBoard(board, row, col - 1);
        updateBoard(board, row + 1, col);
        updateBoard(board, row, col + 1);
    }

    public:
    vector<vector<char>>
    updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0];
        int col = click[1];

        // 如果上来就挖到挖到地雷
        if ('M' == board[row][col]) {
            board[row][col] = 'X';
            return board;
        }

        if ('E' == board[row][col]) {
            int n = 0;
            // 如果当前点击点周围有地雷，则将其改为环绕地雷数量后返回
            if ((n = getSurroundSweeperCpint(board, row, col)) > 0) {
                board[row][col] = (char)(48 + n);
                return board;
            }
            board[row][col] = 'B';
            updateBoard(board, row - 1, col - 1);
            updateBoard(board, row + 1, col + 1);
            updateBoard(board, row + 1, col - 1);
            updateBoard(board, row - 1, col + 1);
            updateBoard(board, row - 1, col);
            updateBoard(board, row, col - 1);
            updateBoard(board, row + 1, col);
            updateBoard(board, row, col + 1);
        }

        return board;
    }
};

void print(vector<vector<char>> v) {
    cout << "[";
    if (v.size()) {
        cout << "[";
        if (v[0].size()) {
            cout << v[0][0];
        }
        for (int i = 1; i < v[0].size(); i++) {
            cout << "," << v[0][i];
        }
        cout << "]" << endl;

        for (int i = 1; i < v.size(); i++) {
            cout << ",[";
            if (v[i].size()) {
                cout << v[i][0];
            }
            for (int j = 1; j < v[i].size(); j++) {
                cout << "," << v[i][j];
            }
            cout << "]" << endl;
        }
    }
    cout << "]" << endl;
}

int main(int argc, char* argv[]) {
    vector<vector<char>> test = {
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
    };
    vector<int> click    = {3, 0};
    Solution    solution = Solution();
    cout << "Origin board:" << endl;
    print(test);
    cout << "After click (" << click[0] << "," << click[1] << ") board:" << endl;
    vector<vector<char>> ans = solution.updateBoard(test, click);
    print(ans);
    return 0;
}