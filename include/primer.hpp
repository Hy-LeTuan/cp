#pragma once

#include <vector>
#include <string>

using namespace std;

/* LINKED LIST */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *build_list_node(vector<int> &data);
void log_list_node(ListNode *x);

/* GRAPH NODE */

class Node {
  public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/* BINARY SEARCH TREE */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

TreeNode *build_tree_node(vector<string> &data);
void log_tree(TreeNode *x);

/* GRAPH  UTILS */

extern vector<pair<int, int>> directions;

/* TRIE */

class TrieNode {
  public:
    TrieNode *children[26];
    bool is_whole_word;

    TrieNode() {
        is_whole_word = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
  public:
    TrieNode *root;

    Trie() { root = new TrieNode(); }

    TrieNode *getRoot() { return root; }

    void addWord(string word) {
        TrieNode *curr = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            TrieNode *next = curr->children[index];

            if (i == word.length() - 1) {
                next->is_whole_word = true;
            }

            curr = next;
        }
    }

    TrieNode *search(TrieNode *curr, char next) {
        int index = next - 'a';

        if (!curr->children[index]) {
            return nullptr;
        } else {
            return curr->children[index];
        }
    }
};

/* QUAD TREE */
class QuadNode {
  public:
    bool val;
    bool isLeaf;
    QuadNode *topLeft;
    QuadNode *topRight;
    QuadNode *bottomLeft;
    QuadNode *bottomRight;

    QuadNode() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    QuadNode(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    QuadNode(bool _val, bool _isLeaf, QuadNode *_topLeft, QuadNode *_topRight,
             QuadNode *_bottomLeft, QuadNode *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

/* General Utilities */
void log_vector(vector<int> &res);
