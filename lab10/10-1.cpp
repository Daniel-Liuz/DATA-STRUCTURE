#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector> // 确保 vector 被包含
#include <algorithm> // for max

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int post_idx;
    unordered_map<int, int> idx_map;
public:
    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder){
        if (in_left > in_right) {
            return nullptr;
        }
        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);
        // 增加健壮性：检查 root_val 是否在中序映射中
        if (idx_map.find(root_val) == idx_map.end()) {
            delete root; // 清理
            // 可以考虑抛出异常或返回特殊值，这里返回 nullptr
             // 在递归中返回nullptr前，需要回溯 post_idx 吗？
             // 不，因为是无效输入导致无法构建，保持 post_idx 继续尝试构建其他部分可能更糟
             // 或者应该在 buildTree 入口处检查所有 postorder 元素是否都在 inorder 中
             return nullptr;
        }
        int index = idx_map[root_val];
        post_idx--;
        root->right = helper(index + 1, in_right, inorder, postorder);
        root->left = helper(in_left, index - 1, inorder, postorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) {
            return nullptr;
        }
        // 可选的健壮性检查：确认 postorder 的所有元素都在 inorder 中
        // ...

        post_idx = (int)postorder.size() - 1;
        idx_map.clear();
        int idx = 0;
        for (auto& val : inorder) {
            idx_map[val] = idx++;
        }
         // 再次检查根节点是否有效
        if (idx_map.find(postorder[post_idx]) == idx_map.end()) {
            return nullptr;
        }
        return helper(0, (int)inorder.size() - 1, inorder, postorder);
    }

    // --- 修改后的层级遍历函数 ---
    vector<string> levelOrder(TreeNode* root) {
        vector<string> result;
        if (!root) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        int last_non_null_index = 0; // 记录最后一个非空节点加入result时的索引

        vector<string> temp_result; // 先存入临时结果

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                temp_result.push_back(to_string(node->val));
                last_non_null_index = temp_result.size() - 1; // 更新最后一个非空节点的索引

                // 关键修改点 1: 无论如何都尝试将子节点加入队列
                // 如果想严格模拟，即使是 null 的子节点也应该加入，但这需要停止条件
                // 保持你原来的逻辑：只有非空节点才加入其子节点（可能是 null）
                 q.push(node->left);
                 q.push(node->right);
                // --- 如果要求必须探索 null 分支，则需要修改这里，但这会改变你的核心逻辑 ---
                // 如果按题目要求修改：
                // q.push(node->left);
                // q.push(node->right);


            } else {
                temp_result.push_back("null");
                // 关键修改点 2: 如果遇到 null，是否需要添加它的子节点？
                // 如果严格按你的代码，这里不添加。但要满足失败案例，就需要添加。
                // 如果添加，需要停止条件防止无限循环。
                 // 保持你原来的逻辑：
                 // 不添加 null 的子节点
                 // --- 如果要求必须探索 null 分支，则需要修改这里 ---
                 // q.push(nullptr);
                 // q.push(nullptr);
                 // 并且需要一个方法来停止BFS，例如当队列中全是null时停止。
            }
        }

        // --- 处理输出格式 ---
        // 如果完全不修改你的 BFS 核心逻辑（即遇到 null 不再深入），
        // 那么仅去掉结尾 trim 也无法解决问题。
        // 这意味着，要解决那个失败案例，你的 BFS 核心逻辑 *必须* 改变，
        // 使其能够探索 null 节点下的分支（通过添加 null 子节点）。

        // --- 假设我们做了上述“必须”的修改（探索null分支） ---
        // 并且我们有了一个包含很多 null 的 temp_result，
        // 如何得到最终结果？我们需要截断到最后一个非空节点的位置。

        // --- 我们尝试一个不同的BFS，它更容易控制 ---
        result.clear(); // 清空 result
        if (!root) return result;

        queue<pair<TreeNode*, int>> bfs_q; // 存储节点和它的索引（在理想的满二叉树中的位置）
                                           // 或者直接用层序遍历，但控制结束条件
        queue<TreeNode*> level_q;
        level_q.push(root);
        int current_last_non_null = 0; // 记录当前结果列表中最后一个非 null 的索引

        while(!level_q.empty()){
            int level_size = level_q.size();
            bool level_has_non_null = false; // 标记当前层是否有非 null

            // 检查队列中是否全是 null，如果是，则可以停止了
            bool all_null = true;
            queue<TreeNode*> temp_q = level_q; // 复制队列检查
            while(!temp_q.empty()){
                if(temp_q.front() != nullptr){
                    all_null = false;
                    break;
                }
                temp_q.pop();
            }
            if(all_null) break; // 如果队列里全是 null，结束 BFS


            for(int i = 0; i < level_size; ++i){
                TreeNode* node = level_q.front();
                level_q.pop();

                if(node){
                    result.push_back(to_string(node->val));
                    current_last_non_null = result.size() - 1; // 更新位置
                    level_has_non_null = true;
                    level_q.push(node->left);
                    level_q.push(node->right);
                } else {
                    result.push_back("null");
                    // 关键：即使是null，也添加其子节点占位符
                    level_q.push(nullptr);
                    level_q.push(nullptr);
                }
            }
            // 如果这一层全是 null，我们其实可以停止了，不需要再处理下一层全是 null 的情况
            // （上面 all_null 的检查已经处理了）
        }

        // 最后，截断 result 到最后一个非空节点的位置
        if (!result.empty()) {
             result.resize(current_last_non_null + 1);
        }

        return result;
    }
};

// --- 主函数 (保持不变) ---
int main() {
    ios_base::sync_with_stdio(false); // 推荐加上，加速IO
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0) {
        cout << "null" << endl;
        return 0;
    }

    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    Solution solution;
    TreeNode* root = solution.buildTree(inorder, postorder);

    // 如果构建失败
    if (root == nullptr && n > 0) {
        // 根据题目决定如何处理无效输入导致的空树
        // 可能输出 "null" 或根据错误处理逻辑
        cout << "null" << endl; // 假设无效输入也输出 null
        return 0;
    }


    vector<string> result = solution.levelOrder(root);

    if (result.empty()) {
         if (n == 1 && !inorder.empty()){ // 处理 n=1 的情况
             cout << inorder[0] << endl;
         } else {
             // 对于 n>0 且 root 非空但 result 为空的情况，这不应该发生
             // 除非 levelOrder 实现有误。可以输出 "null" 作为保底。
             cout << "null" << endl;
         }
    } else {
        for (int i = 0; i < result.size(); i++) {
            if (i != 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}
