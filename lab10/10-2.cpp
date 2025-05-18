#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildBSTFromLevelOrder(const vector<string>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == "null") {
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(levelOrder[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < levelOrder.size()) {
        TreeNode* current = q.front();
        q.pop();
        if (i < levelOrder.size() && levelOrder[i] != "null") {
            current->left = new TreeNode(stoi(levelOrder[i]));
            q.push(current->left);
        }
        i++;
        if (i < levelOrder.size() && levelOrder[i] != "null") {
            current->right = new TreeNode(stoi(levelOrder[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

void preorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    result.push_back(root->val);
    preorderTraversal(root->left, result);
    preorderTraversal(root->right, result);
}

int main() {
    int n;
    cin >> n;
    vector<string> levelOrder(n);
    for (int i = 0; i < n; i++) {
        cin >> levelOrder[i];
    }
    int value;
    cin >> value;

    // 重建BST
    TreeNode* root = buildBSTFromLevelOrder(levelOrder);
    // 插入新值
    root = insertIntoBST(root, value);
    // 前序遍历
    vector<int> result;
    preorderTraversal(root, result);

    // 输出结果
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
