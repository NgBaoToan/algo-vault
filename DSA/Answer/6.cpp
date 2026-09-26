#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;

    node(int val){
        data = val;
        left = right = nullptr;
    }
};

void makeRoot(node *root, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insertRoot(node *root, int u, int v, char c){
    if(root == nullptr) return;
    if(root->data == u) makeRoot(root, v, c);
    else{
        insertRoot(root->left, u, v, c);
        insertRoot(root->right, u, v, c);
    }
}

bool bfs(node *root){
    if(root == nullptr) return true;
    queue<node*> q;
    q.push(root);
    bool found = false;
    while(!q.empty()){
        node* cur = q.front(); q.pop();
        if(cur == nullptr){
            found = true;
        }else{
            if(found) return false;
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    node *root = nullptr;
    for(int i = 0; i < n; i++){
        int u, v; char c;
        cin >> u >> v >> c;
        if(root == nullptr){
            root = new node(u);
            makeRoot(root, v, c);
        }
        else insertRoot(root, u, v, c);
    }

    cout << ((bfs(root)) ? "YES" : "NO");

    return 0;
}
