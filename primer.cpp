#include <primer.hpp>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

ListNode *build_list_node(vector<int> &data) {
    ListNode *head = new ListNode(-1);
    ListNode *curr = head;

    for (auto x : data) {
        ListNode *next = new ListNode(x);
        curr->next = next;
        curr = next;
    }

    head = head->next;

    return head;
}

void log_list_node(ListNode *x) {
    while (x) {
        cout << x->val << " ";
        x = x->next;
    }

    cout << endl;

    return;
}

TreeNode *build_tree_node(vector<string> &data) {
    if (data.size() < 1)
        return nullptr;

    TreeNode *root = new TreeNode(stoi(data[0]));
    int i = 1;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty() && i < data.size()) {
        TreeNode *curr = q.front();

        string left_val = i < data.size() ? data[i] : "null";
        string right_val = i + 1 < data.size() ? data[i + 1] : "null";

        TreeNode *left =
            left_val == "null" ? nullptr : new TreeNode(stoi(left_val));
        TreeNode *right =
            right_val == "null" ? nullptr : new TreeNode(stoi(right_val));

        curr->left = left;
        curr->right = right;

        q.pop();

        if (left)
            q.push(left);
        if (right)
            q.push(right);

        i += 2;
    }

    return root;
}

void log_tree(TreeNode *x) {
    if (x == nullptr)
        return;

    queue<TreeNode *> q;
    q.push(x);

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (!curr) {
            cout << "null" << " ";
            continue;
        }

        cout << curr->val << " ";

        q.push(curr->left);
        q.push(curr->right);
    }

    cout << endl;

    return;
}

vector<pair<int, int>> directions = {
    {-1, 0}, // up
    {1, 0},  // down
    {0, -1}, // left
    {0, 1},  // right
};

void log_vector(vector<int> &res) {
    for (auto x : res) {
        cout << x << " ";
    }

    cout << endl;
}
