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
	node* left;
	node* right;

	node(int x){
		val = x;
		left = right = nullptr;
	}
};

void makeRoot(node* root, int v, char c){
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);
}

void insertRoot(node* root, int u, int v, char c){
	if(root == nullptr) return;
	if(root->val == u){
		makeRoot(root, v, c);
	}else{
		insertRoot(root->left, u, v, c);
		insertRoot(root->right, u, v, c);
	}
}

bool checkBalanceTree(node* root){
	if(root == nullptr) return true;
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* cur = q.front();
		q.pop();

		if(cur->left != nullptr && cur->right == nullptr) return false;
		if(cur->left == nullptr && cur->right != nullptr) return false;

		if(cur->left) q.push(cur->left);
		if(cur->right) q.push(cur->right);
	}
	return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    node*  root = nullptr;
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

    cout << (checkBalanceTree(root) ? "YES" : "NO");
    return 0;
}