#include<bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define endl              "\n"

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

int n,a,b;
pii k;
int dp[1001][1001];
vector<int> l[300000];
int l2[300000];
int vis[300000];
int col[300000];
int c,w;
int kk,maxx,minn;
int tt = 0;
queue<pii> q;
void dfs(int par){
    
}
//void bpg(int par){
 //   if(tt == 1)return;
//    vis[par] = 1;
//    rep(i,0,l2[par].size()){
//        if(vis[l2[par][i]] == 0){
 //           col[l2[par][i]] = 1-col[par];
//            bpg(l2[par][i]);
//        }
 //       else{
//            if(col[l2[par][i]] == col[par]){
  //              tt = 1;
//                return;
//            }
//        }
//}


void solve(){
    int node = 1;
    cin>>n;
    rep(i,2,n+1){
        cin>>a>>b;
        //l[i].pb(k);
        l[a].pb(b);
        l[b].pb(a);
    }
    q.push(make_pair(1,-1));
    while(!q.empty()){
        k = q.front();
        q.pop();
        for(auto ch:l[k.first]){
            if(ch!=k.second){
                vis[ch] = vis[k.first]+1;
                q.push(make_pair(ch,k.first));
            }
        }
    }
    a = 0;
    rep(i,1,n+1){
        if(vis[i]>a){
            node = i;
            a = vis[i];
        }
    }
    vis[node] = 0;
    q.push(make_pair(node,-1));
    col[node] = -1;
    while(!q.empty()){
        k = q.front();
        q.pop();
        for(auto ch:l[k.first]){
            if(ch!=k.second){
                col[ch] = k.first;
                vis[ch] = vis[k.first]+1;
                q.push(make_pair(ch,k.first));
            }
        }
    }
    b = 0;
    a = 0;
    rep(i,1,n+1){
        if(vis[i]>a){
            b = i;
            a = vis[i];
        }
    }
    int
    rep(i,1,n+1)cout<<l2[i]<<" ";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    w = 0;
    while(t--){w+=1;solve();}

}