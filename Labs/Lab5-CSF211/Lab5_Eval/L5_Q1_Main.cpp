#include <iostream>

#include "L5_Q1_solution.cpp"

using namespace std;

Node *buildList(int n) {
    if (n == 0) return nullptr;

    int x;
    std::cin >> x;
    Node *head = new Node(x);
    Node *temp = head;

    for (int i = 1; i < n; i++) {
        std::cin >> x;
        temp->next = new Node(x);
        temp = temp->next;
    }
    return head;
}

void printList(Node *head) {
    while (head) {
        std::cout << head->data;
        if (head->next) std::cout << " ";
        head = head->next;
    }
    std::cout << "\n";
}

void freeList(Node *head) {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) return 0;

    while (t--) {
        int n, m;

        std::cin >> n;
        Node *list_x = buildList(n);

        std::cin >> m;
        Node *list_y = buildList(m);

        Node *sum = solve(list_x, list_y);
        printList(sum);

        freeList(sum);
    }
    return 0;
}