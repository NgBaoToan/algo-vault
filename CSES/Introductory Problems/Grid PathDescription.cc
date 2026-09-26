#include <bits/stdc++.h>
using namespace std;
 
string s;
int vis[7][7];
int ans = 0;
 
void dfs(int i, int j, int a = 0){
    if(i == 6 && j == 0){
        if(a == 48){
            ans++;
        }
        return;
    }
 
    if((i == 0 || i == 6 || (i > 0 && i < 6 && vis[i - 1][j] && vis[i + 1][j])) &&
        j > 0 && j < 6 && !vis[i][j - 1] && !vis[i][j + 1])
        return;
 
    if((j == 0 || j == 6 || (j > 0 && j < 6 && vis[i][j - 1] && vis[i][j + 1])) &&
        i > 0 && i < 6 && !vis[i - 1][j] && !vis[i + 1][j])
        return;
 
    vis[i][j] = 1;
    if(s[a] == '?' || s[a] == 'L'){
        if(j > 0 && !vis[i][j - 1]){
            dfs(i, j - 1, a + 1);
        }
    }
 
    if(s[a] == '?' || s[a] == 'R'){
        if(j < 6 && !vis[i][j + 1]){
            dfs(i, j + 1, a + 1);
        }
    }
 
    if(s[a] == '?' || s[a] == 'D'){
        if(i < 6 && !vis[i + 1][j]){
            dfs(i + 1, j, a + 1);
        }
    }
    
    if(s[a] == '?' || s[a] == 'U'){
        if(i > 0 && !vis[i - 1][j]){
            dfs(i - 1, j, a + 1);
        }
    }
    
    vis[i][j] = 0;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    cin >> s;
    dfs(0, 0);
 
    cout << ans << '\n';
    return 0;
}