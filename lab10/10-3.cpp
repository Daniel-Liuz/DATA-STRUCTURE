//
// Created by Daniel Liu on 25-4-30.
//
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm> // For std::max (if used) and std::vector operations
#include <stdexcept> // For exception handling in stoi

using namespace std;

// 1. TreeNode 结构体
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// --- Function Definitions (Ensure they are at global scope) ---

// 2. 构建树函数
TreeNode* buildTreeFromLevelOrder(const vector<string>& levelOrder) {
    int n = levelOrder.size();
    if (n == 0 || levelOrder[0] == "null") {
        return nullptr;
    }
    vector<TreeNode*> nodes(n, nullptr);
    // 创建节点
    for (int i = 0; i < n; ++i) {
        if (levelOrder[i] != "null") {
            try {
                 nodes[i] = new TreeNode(stoi(levelOrder[i]));
            } catch (const std::invalid_argument& ia) {
                 cerr << "Invalid input string: " << levelOrder[i] << endl;
                 return nullptr;
            } catch (const std::out_of_range& oor) {
                 cerr << "Input string out of range: " << levelOrder[i] << endl;
                 return nullptr;
            }
        }
    }
    // 连接节点
    for (int i = 0; i < n; ++i) {
        if (nodes[i] != nullptr) {
            int left_idx = 2 * i + 1;
            if (left_idx < n) {
                nodes[i]->left = nodes[left_idx];
            }
            int right_idx = 2 * i + 2;
            if (right_idx < n) {
                nodes[i]->right = nodes[right_idx];
            }
        }
    }
    return nodes[0]; // 返回根节点
}

// 3. 查找子树最小值函数
TreeNode* findMin(TreeNode* node) {
    while (node != nullptr && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// 4. 删除节点函数
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else {
            TreeNode* successor = findMin(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
    }
    return root;
}

// 5. 层次遍历函数
vector<string> levelOrderTraversal(TreeNode* root) {
     vector<string> result;
     if (root == nullptr) {
         return result;
     }
     queue<TreeNode*> bfs_q;
     bfs_q.push(root);
     while (!bfs_q.empty()) {
         TreeNode* current = bfs_q.front();
         bfs_q.pop();
         if (current) {
             result.push_back(to_string(current->val));
             bfs_q.push(current->left);
             bfs_q.push(current->right);
         } else {
             result.push_back("null");
         }
     }
     return result;
}

// 辅助函数：计算树的最大深度 (Optional)
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


// --- Main Function ---
int main() {
    ios_base::sync_with_stdio(false); // Optional: faster I/O
    cin.tie(NULL);                    // Optional: faster I/O

    string first_token;
    cin >> first_token;

    // --- Special Handling for "null 0" input ---
    if (first_token == "null") {
        string second_token;
        // Check if there is a second token and if it's "0"
        if (cin >> second_token && second_token == "0") {
            cout << "null" << endl;
            return 0; // Exit immediately
        } else {
            // Handle other cases starting with "null" if needed,
            // or treat as invalid input format.
            // For now, we assume only "null 0" needs special handling.
            // If it's just "null" or "null" followed by something else,
            // it might fall through or cause errors later.
            // Based on the requirement, we only explicitly handle "null 0".
             // Let's assume other inputs starting with "null" are invalid
             // for the standard processing path. We can exit or error here.
             // For safety, let's just exit if it starts with "null" but isn't "null 0"
             // Or maybe just output "null" for any input starting with "null"?
             // Let's stick to the specific "null 0" requirement.
             // If it's "null" followed by not "0", the behavior is undefined by the requirement.
             // Let's assume it won't happen or doesn't need specific output.
             return 1; // Indicate an issue or unexpected format
        }
    }

    // --- Standard Processing Path ---
    int n;
    try {
        n = stoi(first_token); // Convert the first token to n
    } catch (const std::invalid_argument& ia) {
        cerr << "Invalid number format for n: " << first_token << endl;
        return 1;
    } catch (const std::out_of_range& oor) {
        cerr << "Number n out of range: " << first_token << endl;
        return 1;
    }


    if (n <= 0) { // Handle n=0 or negative n
        // If n=0, the loop below won't run. We might need to read the key still?
        // Let's assume n > 0 for valid tree input based on samples.
        // If n=0 is possible input meaning empty tree, handle it.
        // The samples suggest n>=1 for actual trees.
        // Let's refine the n=0 case:
        if (n == 0) {
             int key; // Still need to read the key maybe? Problem description is unclear.
             if (cin >> key) { // Read key if present
                cout << endl; // Empty tree remains empty
             } else {
                 cout << endl; // Just n=0, no key
             }
             return 0;
        } else { // n < 0 is likely invalid
            cerr << "Invalid value for n: " << n << endl;
            return 1;
        }
    }

    vector<string> levelOrderInput(n);
    for (int i = 0; i < n; ++i) {
         if (!(cin >> levelOrderInput[i])) { // Check if input reading fails
              cerr << "Error reading level order traversal element " << i << endl;
              return 1;
         }
    }
    int key;
    if (!(cin >> key)) { // Check if reading key fails
         cerr << "Error reading key" << endl;
         return 1;
    }


    TreeNode* root = buildTreeFromLevelOrder(levelOrderInput);
    root = deleteNode(root, key); // 执行删除并更新 root

    if (root == nullptr) {
        cout << "null" << endl; // Tree is empty after deletion or was initially empty ("1 null" case)
    } else {
        vector<string> result = levelOrderTraversal(root);

        int lastNonNull = -1;
        for (int i = result.size() - 1; i >= 0; --i) {
            if (result[i] != "null") {
                lastNonNull = i;
                break;
            }
        }

        if (lastNonNull != -1) {
            for (int i = 0; i <= lastNonNull; ++i) {
                cout << result[i];
                if (i < lastNonNull) {
                    cout << " ";
                }
            }
            cout << endl;
        } else {
            // This case (root is not null but result has no non-null elements)
            // implies an issue with levelOrderTraversal or the tree structure.
            // A non-null root should at least produce its own value.
            // Fallback: maybe print "null" or error? Let's print "null" for safety.
             cout << "null" << endl;
        }
    }

    // Optional: Clean up allocated memory
    // deleteTree(root);

    return 0;
}

// Optional: Memory cleanup function
// void deleteTree(TreeNode* node) {
//     if (node == nullptr) return;
//     deleteTree(node->left);
//     deleteTree(node->right);
//     delete node;
// }
