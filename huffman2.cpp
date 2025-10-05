#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Node structure
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to build the Huffman Tree
Node* buildHuffmanTree(string S, int f[], int N) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Create leaf nodes
    for (int i = 0; i < N; i++) {
        minHeap.push(new Node(S[i], f[i]));
    }

    // Build the tree
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* merged = new Node('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        minHeap.push(merged);
    }

    return minHeap.top(); // Root of Huffman Tree
}

// Preorder traversal to print codes
void preorder(Node* root, string code) {
    if (!root) return;

    // Print code if leaf node
    if (root->ch != '$') {
        cout << code << " ";
    }

    preorder(root->left, code + "0");
    preorder(root->right, code + "1");
}

int main() {
    string S = "abcdef";
    int f[] = {5, 9, 12, 13, 16, 45};
    int N = S.length();

    Node* root = buildHuffmanTree(S, f, N);
    preorder(root, "");

    return 0;
}
