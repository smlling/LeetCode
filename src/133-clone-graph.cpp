/*

    133. 克隆图

    给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
    图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
    class Node {
        public int val;
        public List<Node> neighbors;
    }
     

    测试用例格式：
    简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（val = 1），第二个节点值为 2（val = 2），以此类推。该图在测试用例中使用邻接列表表示。
    邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。
    给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。

    示例 1：
    ![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/01/133_clone_graph_question.png)
    输入：adjList = [[2,4],[1,3],[2,4],[1,3]]
    输出：[[2,4],[1,3],[2,4],[1,3]]
    解释：
    图中有 4 个节点。
    节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
    节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
    节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
    节点 4 的值是 4，它有两个邻居：节点 1 和 3 。

    示例 2:
    ![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/01/graph.png)
    输入：adjList = [[]]
    输出：[[]]
    解释：输入包含一个空列表。该图仅仅只有一个值为 1 的节点，它没有任何邻居。

    示例 3：
    输入：adjList = []
    输出：[]
    解释：这个图是空的，它不含任何节点。

    示例 4：
    ![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/01/graph-1.png)
    输入：adjList = [[2],[1]]
    输出：[[2],[1]]
     

    提示：
    节点数不超过 100 。
    每个节点值 Node.val 都是唯一的，1 <= Node.val <= 100。
    无向图是一个简单图，这意味着图中没有重复的边，也没有自环。
    由于图是无向的，如果节点 p 是节点 q 的邻居，那么节点 q 也必须是节点 p 的邻居。
    图是连通图，你可以从给定节点访问到所有节点。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/clone-graph
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    author:smlling
    email:smlling@hotmail.com
    github:https://github.com/smlling

    执行用时：4 ms, 在所有 C++ 提交中击败了99.42%的用户
    内存消耗：9.1 MB, 在所有 C++ 提交中击败了25.88%的用户

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
    public:
    int           val;
    vector<Node*> neighbors;

    Node() {
        val       = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val       = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val       = _val;
        neighbors = _neighbors;
    }
};

Node* nodeList = NULL;

class Solution {
    public:
    int                      maxNode;
    unordered_map<int, bool> path = unordered_map<int, bool>();

    /**
     * 对输入的图进行一遍dfs
     * 找出最大的node标号
     * 因为题目告知每个节点的值都和它的索引相同且不会重复
     * 那么可以知道最大的标号即为图的节点个数
    */
    void traverse(Node* node) {
        path[node->val] = true;
        if (node->val > maxNode) {
            maxNode = node->val;
        }
        for (auto adj : node->neighbors) {
            if (false == path[adj->val]) {
                traverse(adj);
            }
        }
    }
    /**
     * 对原图进行dfs
     * 边遍历边拷贝
    */
    Node* clone(Node* node) {
        int currentNode = node->val;
        // 初始化的nodeList中每一个node的val为0，neighbors为空的vector<Node*>
        // 因此如果当前node标号已经在克隆数组中找到，说明已被克隆，直接返回克隆数组中对应的地址
        if (nodeList[currentNode - 1].val == currentNode) {
            return &nodeList[currentNode - 1];
        }
        // 否则拷贝当前节点信息
        nodeList[currentNode - 1].val = currentNode;
        for (auto adj : node->neighbors) {
            // 递归对neighbors进行拷贝(dfs)
            nodeList[currentNode - 1].neighbors.push_back(clone(adj));
        }
        return &nodeList[currentNode - 1];
    }
    Node* cloneGraph(Node* node) {
        // 调试用
        init();

        if (NULL == node) {
            print();
            return NULL;
        }

        traverse(node);
        // 知道图中节点的个数后即可一次性将所需的空间分配出来
        nodeList  = new Node[maxNode];
        Node* ans = clone(node);

        // 调试用
        print();

        return ans;
    }

    void init() {
        Node* nodeList = NULL;
        maxNode        = 0;
        path           = unordered_map<int, bool>();
    }

    void print() {
        cout << "[";
        if (maxNode) {
            cout << "[";
            if (nodeList[0].neighbors.size()) {
                cout << nodeList[0].neighbors[0]->val;
            }
            for (int i = 1; i < nodeList[0].neighbors.size(); i++) {
                cout << "," << nodeList[0].neighbors[i]->val;
            }
            cout << "]";
            for (int i = 1; i < maxNode; i++) {
                cout << ",[";
                if (nodeList[i].neighbors.size()) {
                    cout << nodeList[i].neighbors[0]->val;
                }
                for (int j = 1; j < nodeList[i].neighbors.size(); j++) {
                    cout << "," << nodeList[i].neighbors[j]->val;
                }
                cout << "]";
            }
        }
        cout << "]" << endl;
    }
};

int main(int argc, char* argv[]) {
    Solution                    solution = Solution();
    vector<vector<vector<int>>> test     = {
        {},
        {{}},
        {{2}, {1}},
        {{2, 3}, {1}, {1}},
        {{2, 4}, {1, 3}, {2, 4}, {1, 3}},
    };
    for (auto graph : test) {
        vector<Node> list = vector<Node>();
        fill_n(back_inserter(list), graph.size(), Node());
        for (int i = 0; i < graph.size(); i++) {
            list[i].val = i + 1;
            for (auto adj : graph[i]) {
                list[i].neighbors.push_back(&list[adj - 1]);
            }
        }
        solution.cloneGraph(&list[0]);
    }
    return 0;
}