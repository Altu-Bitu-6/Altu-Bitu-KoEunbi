#include <iostream>

using namespace std;

struct Node {
    int val = NULL;
    Node* right = NULL;
    Node* left = NULL;
};

void insert(int idx, Node* n) { //노드 추가 함수
    if (n->val < idx) { //추가할 값이 부모 노드보다 작을 때 
        if (n->right == NULL) { //오른쪽으로
            n->right = new Node;
            n->right->val = idx;
        }
        else
            insert(idx, n->right);
    }
    else { //부모 노드보다 클 때
        if (n->left == NULL) { //왼쪽으로
            n->left = new Node;
            n->left->val = idx;
        }
        else
            insert(idx, n->left);
    }
}

void postOrder(Node& n) { //포스트오더 탐색
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
            root.val = n; //루트 생성
        else
            insert(n, &root); //노드 삽입
    }

    postOrder(root);

    return 0;
}
