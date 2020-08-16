/*

    733. 图像渲染

    有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。

    给你一个坐标 (row, col) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。

    为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。

    最后返回经过上色渲染后的图像。

    示例 1:
    输入: 
    image = [[1,1,1],[1,1,0],[1,0,1]]
    row = 1, col = 1, newColor = 2
    输出: [[2,2,2],[2,2,0],[2,0,1]]
    
    解析: 
    在图像的正中间，(坐标(row,col)=(1,1)),
    在路径上所有符合条件的像素点的颜色都被更改成2。
    注意，右下角的像素没有更改为2，
    因为它不是在上下左右四个方向上与初始点相连的像素点。
    注意:

    image 和 image[0] 的长度在范围 [1, 50] 内。
    给出的初始点将满足 0 <= row < image.length 和 0 <= col < image[0].length。
    image[i][j] 和 newColor 表示的颜色值在范围 [0, 65535]内。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/flood-fill
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：12 ms, 在所有 C++ 提交中击败了90.97%的用户
    内存消耗：13.8 MB, 在所有 C++ 提交中击败了78.80%的用户

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    // 原来的颜色
    int originColor;

    void move(vector<vector<int>>& image, char direction, int row, int col, int newColor) {
        // 越界返回
        if (col < 0 || col >= image[0].size() || row < 0 || row >= image.size()) {
            return;
        }
        // 当前位置颜色是需要修改的颜色则修改，否则返回
        if (image[row][col] == originColor) {
            image[row][col] = newColor;
        } else {
            return;
        }
        switch (direction) {
            case 'u':
                move(image, 'u', row - 1, col, newColor);
                move(image, 'l', row, col - 1, newColor);
                move(image, 'r', row, col + 1, newColor);
                print(image);
                break;
            case 'd':
                move(image, 'd', row + 1, col, newColor);
                move(image, 'l', row, col - 1, newColor);
                move(image, 'r', row, col + 1, newColor);
                print(image);
                break;
            case 'l':
                move(image, 'l', row, col - 1, newColor);
                move(image, 'u', row - 1, col, newColor);
                move(image, 'd', row + 1, col, newColor);
                print(image);
                break;
            case 'r':
                move(image, 'r', row, col + 1, newColor);
                move(image, 'u', row - 1, col, newColor);
                move(image, 'd', row + 1, col, newColor);
                print(image);
                break;
            default:
                break;
        }
    }
    void print(vector<vector<int>> v) {
        cout << "[";
        if (v.size()) {
            cout << "[";
            if (v[0].size()) {
                cout << v[0][0];
            }
            for (int i = 1; i < v[0].size(); i++) {
                cout << "," << v[0][i];
            }
            cout << "]";

            for (int i = 1; i < v.size(); i++) {
                cout << ",[";
                if (v[i].size()) {
                    cout << v[0][0];
                }
                for (int j = 1; j < v[i].size(); j++) {
                    cout << "," << v[i][j];
                }
                cout << "]";
            }
        }
        cout << "]" << endl;
        ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int row, int col, int newColor) {
        print(image);
        originColor = image[row][col];

        // 特殊情况需要修改的颜色与改后颜色相同则不需要修改
        if (originColor == newColor) {
            return image;
        }
        image[row][col] = newColor;
        move(image, 'u', row - 1, col, newColor);
        move(image, 'd', row + 1, col, newColor);
        move(image, 'l', row, col - 1, newColor);
        move(image, 'r', row, col + 1, newColor);

        print(image);
        return image;
    }
};

int main(int argc, char* argv[]) {
    Solution solution = Solution();

    vector<vector<vector<int>>> test = {
        {
            {1, 1, 1},
            {1, 1, 0},
            {1, 0, 1},
        },
        {
            {0, 1, 1, 2, 3, 1},
            {0, 1, 1, 0, 2, 2},
        },
    };

    vector<vector<int>> pram = {
        {2, 2, 2},
        {1, 1, 1},
    };

    for (int i = 0; i < test.size(); i++) {
        solution.floodFill(test[i], pram[i][0], pram[i][1], pram[i][2]);
    }
    return 0;
}