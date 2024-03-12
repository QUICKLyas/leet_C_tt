//
// Created by Administrator on 2024/3/12.
//
#include <unordered_set>

using namespace std;
/**
 * TreeNode.val == -1
 * 二叉树的高度不超过 20
 * 节点的总数在 [1, 10^4] 之间
 * 调用 find() 的总次数在 [1, 10^4] 之间
 * 0 <= target <= 10^6
 */
class FindElements {
    unordered_set<int> valSet;
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    void dfs(TreeNode *node, int val) {
        if (node == nullptr) return;
        node->val = val;
        valSet.insert(val);
        // 访问左侧结点
        dfs(node->left,val * 2 + 1);
        // 访问右侧结点
        dfs(node->right,val * 2 + 2);
    }
public:
    /**
     * 满足下述规则的二叉树
     * 1. root.val = 0
     * 2. treeNode.val = x, treeNode.left != null => treeNode.left.val = 2*x + 1
     * 3. treeNode.val = x, treeNode.right != null => treeNode.right.val = 2*x + 2
     * 说污染后，treeNode.val 都变成 -1
     * 请还原二叉树
     * FindElements (TreeNode * root) 用污染的二叉树初始化对象，需要先把它还原
     * bool find(int target)判断目标值 target 是否存在于还原后的二叉树中并返回结果
     * @param root
     */
    FindElements (TreeNode * root) {
        dfs(root, 0);
    }

    bool find (int target) {
        return valSet.count(target); // 判断是否存在与这个二叉树
        // target在其中就返回真，否则返回false
    }
};
class FindElements_2 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    void dfs (TreeNode *node , int val) {
        if (node == nullptr) return;
        node->val = val;
        dfs (node->left, val * 2 + 1);
        dfs (node->right, val * 2 + 2);
    }
private:
    TreeNode * root;
public:
    /**
     * 1261-2 深度优先搜索 + 位运算
    * 具有规律性，将二叉树的结点值都增加1，分别记
    * 增加前结点node的值为v，左节点值为lv，右节点值rv
    * 增加1后节点node的值v_1 = v + 1 左节点值为lv_1 = lv + 1，右节点值rv_1 = rv + 1
    * @param target
    * @return
    */
    FindElements_2 (TreeNode *root) {
        this->root = root;
        dfs(root, 0); // 重构二叉树
    }
    bool find_2 (int target) {
        target ++;
        int k = 30 - __builtin_clz(target); // 计算二进制下左侧零的个数，二进制数一般为32个零，2个字
        TreeNode * node  = root;
        while (k >= 0 && node != nullptr) { //如果还有0，就是说0的个数没有使用完全，且 当前的node 不是空
            if ((target & (1 << k)) ==0) { // target 和 在 k位置的1进行与运算 如果此时targe是一个0，就是说应该向左节点移动
                node = node ->left;
            } else { // 否则向右节点移动
                node = node -> right;
            }
            k--;
        }
        return node != nullptr; // 如果结果是一个结点的地址，那么返回真，否则返回假
    }
};