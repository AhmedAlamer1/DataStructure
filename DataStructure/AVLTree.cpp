#include "AVLtree.h"

AVLtree::AVLtree() {
    root = NULL;
}

bool AVLtree::IsEmpty() {
    return root == NULL;
}

int AVLtree::Height(Node* node) {
    if (node == NULL) {
        return -1;
    }
    else {
        return node->height;
    }
}

int AVLtree::balanceFactor(Node* node) {
    if (node == NULL) {
        return 0;
    }
    else {
        return Height(node->left) - Height(node->right);
    }
}

Node* AVLtree::GetMnNode(Node* node) {
    if (node == NULL) {
        return NULL;
    }

    while (node->left != NULL) {
        node = node->left;
    }

    return node;
}

Node* AVLtree::RightRotation(Node* X) {
    Node* Y = X->left;
    Node* tmp = Y->right;

    Y->right = X;
    X->left = tmp;

    // Update heights
    X->height = max(Height(X->right), Height(X->left)) + 1;
    Y->height = max(Height(Y->right), Height(Y->left)) + 1;

    return Y;
}

Node* AVLtree::LeftRotation(Node* X) {
    Node* Y = X->right;
    Node* tmp = Y->left;

    Y->left = X;
    X->right = tmp;

    // Update heights
    X->height = max(Height(X->right), Height(X->left)) + 1;
    Y->height = max(Height(Y->right), Height(Y->left)) + 1;

    return Y;
}

Node* AVLtree::InsertRec(int key, Node* cur) {
    if (cur == NULL) {
        Node* newNode = new Node;
        newNode->item = key;
        newNode->right = newNode->left = NULL;
        newNode->height = 0;

        return newNode;
    }

    if (key < cur->item) {
        cur->left = InsertRec(key, cur->left);
    }
    else {
        cur->right = InsertRec(key, cur->right);
    }

    // Update height of the ancestor node
    cur->height = max(Height(cur->left), Height(cur->right)) + 1;

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = balanceFactor(cur);

    // ll-imbalance
    if (balance > 1 && key < cur->left->item) {
        cur = RightRotation(cur);
    }

    // rr-imbalance
    if (balance < -1 && key > cur->right->item) {
        cur = LeftRotation(cur);
    }

    // lr-imbalance
    if (balance > 1 && key > cur->left->item) {
        cur->left = LeftRotation(cur->left);
        cur = RightRotation(cur);
    }

    // rl-imbalance
    if (balance < -1 && key < cur->right->item) {
        cur->right = RightRotation(cur->right);
        cur = LeftRotation(cur);
    }

    return cur;
}

void AVLtree::Insert(int key) {
    if (IsEmpty()) {
        Node* newNode = new Node;
        newNode->item = key;
        newNode->right = newNode->left = NULL;
        newNode->height = 0;
        root = newNode;
    }
    else {
        root = InsertRec(key, root);
    }
}

Node* AVLtree::Delete(Node* cur, int key) {
    if (cur == NULL) {
        return cur;
    }

    if (key < cur->item) {
        cur->left = Delete(cur->left, key);
    }
    else if (key > cur->item) {
        cur->right = Delete(cur->right, key);
    }
    else {
        // Node to be deleted is cur.
        if (cur->left == NULL && cur->right == NULL) {
            // Leaf node.
            Node* tmp = cur;
            delete tmp;
            cur = NULL;
        }
        else if (cur->left == NULL) {
            // One child.
            Node* tmp = cur;
            cur = cur->right;
            delete tmp;
        }
        else if (cur->right == NULL) {
            // One child.
            Node* tmp = cur;
            cur = cur->left;
            delete tmp;
        }
        else {
            // Two children.
            Node* MnNode = GetMnNode(cur->right);
            cur->item = MnNode->item;
            cur->right = Delete(cur->right, cur->item);
        }
    }

    if (cur == NULL) {
        return cur;
    }

    // Update height and balance factor of the current node.
    cur->height = max(Height(cur->left), Height(cur->right)) + 1;
    int Balance = balanceFactor(cur);

    // Rebalance the tree if necessary.
    if (Balance > 1 && balanceFactor(cur->left) >= 0) {
        cur = RightRotation(cur);
    }
    else if (Balance > 1 && balanceFactor(cur->left) < 0) {
        cur->left = LeftRotation(cur->left);
        cur = RightRotation(cur);
    }
    else if (Balance < -1 && balanceFactor(cur->right) <= 0) {
        cur = LeftRotation(cur);
    }
    else if (Balance < -1 && balanceFactor(cur->right) > 0) {
        cur->right = RightRotation(cur->right);
        cur = LeftRotation(cur);
    }

    return cur;
}

bool AVLtree::search(Node* cur, int key) {
    if (cur == NULL) {
        return false;
    }

    if (key < cur->item) {
        return search(cur->left, key);
    }
    else if (key > cur->item) {
        return search(cur->right, key);
    }
    else {
        return true;
    }
}

void AVLtree::InOrder(Node* cur)
{
    if (cur == NULL) {
        return;
    }
    InOrder(cur->left);
    cout << cur->item << ' ';
    InOrder(cur->right);
}

Node* AVLtree::GetRoot()
{
    return root;
}

Node* AVLtree::ClearAvl(Node* root)
{
    Node* temp;
    if (root != NULL) {
        ClearAvl(root->left);
        ClearAvl(root->right);
        cout << "\nReleased node:" << root->item;
        temp = root;
        delete temp;
    }
    return root;
}

void AVLtree::clear()
{
    ClearAvl(root);
}

int AVLtree::CountNodes(Node* cur) {
    if (cur == NULL)
        return 0;
    int l = CountNodes(cur->left);
    int r = CountNodes(cur->right);
    return l + r + 1;
}

int AVLtree::Size()
{
    return CountNodes(root);
}

void AVLtree::Display()
{
    InOrder(root);
}