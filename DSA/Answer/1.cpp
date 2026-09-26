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

void makeRoot(node *root, int v, int c){
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);
}

void insertRoot(node *root, int u, int v, char c){
	if(root == nullptr) return;
	if(root->val == u){
		makeRoot(root, v, c);
	}else{
		insertRoot(root->left, u, v, c);
		insertRoot(root->right, u, v, c);
	}
}

void inorder(node* root){
	if(root == nullptr) return;
	inorder(root->left);
	cout << root->val << ' ';
	inorder(root->right);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	node* root = nullptr;
	for(int i = 0; i < n; i++){
		int u, v; char c;
		cin >> u >> v >> c;
		if(root == nullptr){
			root = new node(u);
			makeRoot(root, v, c);
		}else{
			insertRoot(root, u, v, c);
		}
	}
	
	inorder(root);
	return 0;
}