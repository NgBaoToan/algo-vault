#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node(int x) {
        val = x;
        left = right = nullptr;
    }
};

node* buildTree(vector<int>& preorder, vector<int>& inorder,
                int preL, int preR, int inL, int inR,
                unordered_map<int, int>& pos) {
    if (preL > preR || inL > inR) return nullptr;

    int rootVal = preorder[preL];
    node* root = new node(rootVal);

    int k = pos[rootVal];
    int leftSize = k - inL;

    root->left = buildTree(preorder, inorder,
                           preL + 1, preL + leftSize,
                           inL, k - 1, pos);

    root->right = buildTree(preorder, inorder,
                            preL + leftSize + 1, preR,
                            k + 1, inR, pos);

    return root;
}

void postorder(node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int> preorderArr(n), inorderArr(n);
    for (int i = 0; i < n; i++) cin >> preorderArr[i];
    for (int i = 0; i < n; i++) cin >> inorderArr[i];

    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++) pos[inorderArr[i]] = i;

    node* root = buildTree(preorderArr, inorderArr, 0, n - 1, 0, n - 1, pos);

    postorder(root);

    return 0;
}
