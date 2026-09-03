#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }


#ifdef nbaotoan
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

struct node{
	int val;
	node *left, *right;
};

node* makeRoot(int v){
	node *newNode = new node();

	newNode->val = v;
	newNode->left = newNode->right = nullptr;
	return newNode;
}

node* insertRoot(node* root, int key){
	if(root == nullptr){
		return makeRoot(key);
	}

	if(key < root->val){
		root->left = insertRoot(root->left, key);
	}else{
		root->right = insertRoot(root->right, key);
	}

	return root;
}

void inorder(node* root){
	if(root == nullptr) return;

	inorder(root->left);
	cout << root->val << ' ';
	inorder(root->right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node* root = nullptr;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		root = insertRoot(root, x);
	}

	inorder(root);
    return 0;
}