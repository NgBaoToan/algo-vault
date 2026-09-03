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
#include <sys/types.h>
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
	if(root->val == u) makeRoot(root, v, c);
	else{
		insertRoot(root->left, u, v, c);
		insertRoot(root->right, u, v, c);
	}
}

int duyet(node* root1, node* root2){
	if(root1 == nullptr && root2 == nullptr) return 1;
	if(root1 == nullptr || root2 == nullptr) return 0;
	if(root1->val != root2->val) return 0;
	return duyet(root1->left, root2->left) && duyet(root1->right, root2->right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    node *root1 = nullptr;
    node *root2 = nullptr;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
    	int u, v; char c; cin >> u >> v >> c;
    	if(root1 == nullptr){
    		root1 = new node(u);
    		makeRoot(root1, v, c);
    	}else{
    		insertRoot(root1, u, v, c);
    	}    
    }

    int m; cin >> m;
    for(int i = 0; i < m; i++){
    	int u, v; char c; cin >> u >> v >> c;
    	if(root2 == nullptr){
    		root2 = new node(u);
    		makeRoot(root2, v, c);
    	}else{
    		insertRoot(root2, u, v, c);
    	}
    }

    if(n != m){
    	cout << "NO\n";
    	return 0;
    }

    cout << (duyet(root1, root2) ? "YES" : "NO");
    return 0;
}