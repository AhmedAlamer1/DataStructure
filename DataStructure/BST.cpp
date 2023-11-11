#include "BST.h"

BST::BST()
{
	root = NULL;
}

bool BST::IsEmpty() {
    return root == NULL;
}

Node* BST::GetMinNode(Node* Root) {
    Node* tmp = Root;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

Node* BST::GetMxNode(Node* Root) {
    Node* tmp = Root;
    while (tmp->right != NULL) {
        tmp = tmp->right;
    }
    return tmp;
}

int BST::GetMinKey() {
    return GetMinNode(root)->item;
}

int BST::GetMxKey() {
    return GetMxNode(root)->item;
}

int BST::Height(Node* cur) {
    if (cur == NULL) {
        return -1;
    }
    int Ldepth = Height(cur->left) + 1;
    int Rdepth = Height(cur->right) + 1;
    return max(Ldepth, Rdepth);
}

Node* BST::InsertRec(int key, Node* cur) {
    if (cur == NULL) {
        Node* NewNode = new Node;
        NewNode->item = key;
        NewNode->right = NewNode->left = NULL;
        return NewNode;
    }
    if (key > cur->item) {
        cur->right = InsertRec(key, cur->right);
    }
    else {
        cur->left = InsertRec(key, cur->left);
    }
    return cur;
}

void BST::Insert(int item) {
    if (IsEmpty()) {
        root = new Node;
        root->item = item;
        root->left = root->right = NULL;
    }
    else {
        InsertRec(item, root);
    }
}

Node* BST::DeleteNode(int key, Node* Root) {
    if (Root == NULL) {
        return Root;
    }
    if (Root->item < key) {
        Root->right = DeleteNode(key, Root->right);
    }
    else if (Root->item > key) {
        Root->left = DeleteNode(key, Root->left);
    }
    else {
        // case 1 -> the node is a leaf
        if (Root->left == NULL and Root->right == NULL) {
            delete Root;
            Root = NULL;
            return NULL;
        }
        // case 2 -> the node has one child
        else if (Root->right == NULL) {
            Node* tmp = Root;
            Root = Root->left;
            delete tmp;
            return Root;
        }
        else if (Root->left == NULL) {
            Node* tmp = Root;
            Root = Root->right;
            delete tmp;
            return Root;
        }
        // case 3 -> the node has two childes
        else {
            Node* tmp = GetMinNode(Root->right);
            Root->item = tmp->item;
            Root->right = DeleteNode(tmp->item, tmp);
        }
    }
    return Root;
}

bool BST::search(Node* cur, int key) {
    if (cur == NULL) {
        return 0;
    }
    if (key < cur->item) {
        return search(cur->left, key);
    }
    else if (key > cur->item) {
        return search(cur->right, key);
    }
    else {
        return 1;
    }
}

void BST::INOrder(Node* cur) {
    if (cur == NULL) {
        return;
    }
    INOrder(cur->left);
    cout << cur->item << ' ';
    INOrder(cur->right);
}

void BST::PreOrder(Node* cur) {
    if (cur == NULL) {
        return;
    }
    cout << cur->item << ' ';
    PreOrder(cur->left);
    PreOrder(cur->right);
}

void BST::PostOrder(Node* cur) {
    if (cur == NULL) {
        return;
    }
    PostOrder(cur->left);
    PostOrder(cur->right);
    cout << cur->item << ' ';
}
void BST::LevelOrder(Node* Root) {
    queue<Node*> q;
    q.push(Root);
    while (!q.empty()) {
        Node* node = q.front();
        cout << node->item << ' ';
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

void BST::PrintGivenLevel(int level, Node* cur) {
    if (cur == NULL)
        return;
    if (level == 0)
        cout << cur->item << ' ';
    else {
        PrintGivenLevel(level - 1, cur->left);
        PrintGivenLevel(level - 1, cur->right);
    }
}

void BST::PrintAllLeafNodes(Node* cur) {
    if (cur == NULL)
        return;
    if (cur->left == NULL and cur->right == NULL)
        cout << cur->item << ' ';
    PrintAllLeafNodes(cur->left);
    PrintAllLeafNodes(cur->right);
}

void BST::PrintAllNoneLeafNodes(Node* cur) {
    if (cur == NULL)
        return;
    if (cur->left != NULL or cur->right != NULL)
        cout << cur->item << ' ';
    PrintAllNoneLeafNodes(cur->left);
    PrintAllNoneLeafNodes(cur->right);
}

void BST::RightView() {
    Node* cur = root;
    while (cur != NULL) {
        cout << cur->item << ' ';
        cur = cur->right;
    }
    cout << endl;
}

void BST::LeftView() {
    Node* cur = root;
    while (cur != NULL) {
        cout << cur->item << ' ';
        cur = cur->left;
    }
    cout << endl;
}

void BST::DeleteNodeByKey(int key) {
    DeleteNode(key, root);
}

void BST::DeleteNode(Node* node) {
    DeleteNode(node->item, root);
}

int BST::CountNodes(Node* cur) {
    if (cur == NULL)
        return 0;
    int l = CountNodes(cur->left);
    int r = CountNodes(cur->right);
    return l + r + 1;
}

int BST::Size()
{
    return CountNodes(root);
}

void BST::clear()
{
    clearBst(root);
}

Node* BST::clearBst(Node* root)
{
    Node* temp;
    if (root != NULL) {
        clearBst(root->left);
        clearBst(root->right);
        cout << "\nReleased node:" << root->item;
        temp = root;
        delete temp;
    }
    return root;
}

void BST::Display()
{
    INOrder(root);
}

