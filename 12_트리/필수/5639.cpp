#include <iostream>

using namespace std;

struct Node {
    int val = NULL;
    Node* right = NULL;
    Node* left = NULL;
};

void insert(int idx, Node* n) {
    if (n->val < idx) {
        if (n->right == NULL) {
            n->right = new Node;
            n->right->val = idx;
        }
        else
            insert(idx, n->right);
    }
    else {
        if (n->left == NULL) {
            n->left = new Node;
            n->left->val = idx;
        }
        else
            insert(idx, n->left);
    }
}

void postOrder(Node& n) {
    if (n.left != NULL)
        postOrder(*n.left);
    if (n.right != NULL)
        postOrder(*n.right);

    cout << n.val << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Node root;
    root.val = NULL;

    int n;
    while (cin >> n) {
        if (root.val == NULL)
            root.val = n;
        else
            insert(n, &root);
    }

    postOrder(root);

    return 0;
}
