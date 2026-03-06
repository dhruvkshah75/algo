#include <iostream>
#include <queue>
#include <vector>

#include "L6_Q1_solution.cpp"

using namespace std;

Node *buildTree(const std::vector<int> &arr) {
    if (arr.empty() || arr[0] == -1) {
        return nullptr;
    }

    Node *root = new Node(arr[0]);
    std::queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node *curr = q.front();
        q.pop();

        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void freeTree(Node *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }

        int p, q;
        std::cin >> p >> q;

        Node *root = buildTree(arr);

        int result = solve(root, p, q);
        std::cout << result << "\n";

        freeTree(root);
    }

    return 0;
}