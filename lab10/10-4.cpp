#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm> // 包含 find_if

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// --- buildTreeFromLevelOrder (保持不变) ---
TreeNode* buildTreeFromLevelOrder(const vector<string>& levelOrder) {
    int n = levelOrder.size();
    if (n == 0 || levelOrder[0] == "null") return nullptr;
    vector<TreeNode*> nodes(n, nullptr);
    for (int i = 0; i < n; i++) {
        if (levelOrder[i] != "null") nodes[i] = new TreeNode(stoi(levelOrder[i]));
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i] != nullptr) {
            int left_idx = 2 * i + 1;
            if (left_idx < n) nodes[i]->left = nodes[left_idx];
            int right_idx = 2 * i + 2;
            if (right_idx < n) nodes[i]->right = nodes[right_idx];
        }
    }
    return nodes[0];
}

// --- pruneTree (保持不变) ---
TreeNode* pruneTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->val == 0 && root->left == nullptr && root->right == nullptr) {
        delete root; // 释放内存是个好习惯
        return nullptr;
    }
    return root;
}

// --- levelOrderTraversal (保持不变) ---
// 生成长度为 n 的完整层次遍历序列
vector<string> levelOrderTraversal(TreeNode* root, int n) {
    vector<string> result;
    if (root == nullptr) {
        for (int i = 0; i < n; i++) result.push_back("null");
        return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    int count = 0;
    while (!q.empty() && count < n) {
        TreeNode* current = q.front();
        q.pop();
        if (current != nullptr) {
            result.push_back(to_string(current->val));
            q.push(current->left);
            q.push(current->right);
        } else {
            result.push_back("null");
            // 即使当前是 null，也要为下一层添加占位符，直到达到 n
             if (count * 2 + 2 < n) { // 检查子节点是否在 n 范围内
                 q.push(nullptr);
                 q.push(nullptr);
             }
        }
        count++;
    }
    // 确保结果长度为 n
    while (result.size() < n) result.push_back("null");
    // 注意：如果树比 n 指定的层数少，这里会填充 null，是正确的
    return result;
}


int main() {
    int n;
    cin >> n;

    // 处理 n=0 的情况
    if (n == 0) {
        cout << endl; // 输出空行
        return 0;
    }

    vector<string> levelOrder(n);
    for (int i = 0; i < n; i++) {
        cin >> levelOrder[i];
    }

    TreeNode* root = buildTreeFromLevelOrder(levelOrder);
    root = pruneTree(root); // 执行剪枝

    // 处理剪枝后树为空的情况
    if (root == nullptr) {
        cout << "null" << endl;
        return 0;
    }

    // 生成完整的层次遍历（可能包含结尾的 null）
    vector<string> result = levelOrderTraversal(root, n);

    // 查找最后一个非 "null" 元素的索引
    int lastNonNullIndex = -1;
    for (int i = result.size() - 1; i >= 0; --i) {
        if (result[i] != "null") {
            lastNonNullIndex = i;
            break;
        }
    }

    // 输出从开头到最后一个非 "null" 元素的部分
    // 如果 lastNonNullIndex 仍然是 -1 (理论上不会发生，因为 root 非空)
    // 但为了安全，我们处理这种情况
    if (lastNonNullIndex == -1) {
         // 这只可能在 root 非空但 levelOrderTraversal 出错时发生
         // 或者如果 result 只包含 "null" （但 root 非空，这也不应该）
         // 安全起见，如果 root 非空但找不到非 null 元素，可能是哪里逻辑错了
         // 但按逻辑，至少 root 本身不是 null
         // 假设如果 root 非空，则 lastNonNullIndex >= 0
    } else {
        for (int i = 0; i <= lastNonNullIndex; ++i) {
            cout << result[i];
            if (i < lastNonNullIndex) {
                cout << " ";
            }
        }
        cout << endl;
    }


    // 清理内存 (可选，但良好实践)
    // 实现一个 deleteTree 函数来递归删除节点
    // deleteTree(root);

    return 0;
}

// 可选的清理函数
// void deleteTree(TreeNode* node) {
//     if (node == nullptr) return;
//     deleteTree(node->left);
//     deleteTree(node->right);
//     delete node;
// }

