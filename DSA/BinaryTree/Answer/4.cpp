#include <bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node *left;
    node *right;

    node(int x){
        val = x;
        left = right = nullptr;
    }
};

void makeRoot(node *root, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insertRoot(node *root, int u, int v, char c){
    if(root == nullptr) return;
    if(root->val == u) makeRoot(root, v, c);
    else{
        insertRoot(root->left, u, v , c);
        insertRoot(root->right, u, v, c);
    }
}

int bfs(node *root){
    int cnt = 0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* x = q.front(); q.pop();
        if(x->left != nullptr) q.push(x->left);
        if(x->right != nullptr) q.push(x->right);
        if(x->left == nullptr && x->right == nullptr) cnt++;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    node *root = nullptr;
    for(int i = 0; i < n; i++){
        int u, v; char c;
        cin >> u >> v >> c;
        if(root == NULL){
            root = new node(u);
            makeRoot(root, v, c);
        }else{
            insertRoot(root, u, v, c);
        }
    }

    cout << bfs(root);
    return 0;
}
