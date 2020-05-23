//{Headers
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<string>
#include<algorithm>
#include<list>
#include<queue>
#include<deque>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<cassert>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair< int,int > pii;
#define mp(x,y) make_pair(x,y)
typedef long long ll;
//}

const int MAXN=2e5,MAXM=2e5;
int N,M,a[MAXN],p[MAXM],s[MAXM];
int best[MAXN+1];

void solve(){
    memset(best,0,(N+1)*sizeof(int));
    for(int i=0;i<M;i++) best[s[i]]=max(best[s[i]],p[i]);
    for(int i=N-1;i>=0;i--) best[i]=max(best[i+1],best[i]);
    int cnt=0,ans=0;
    while(cnt<N){
        int x=1;
        if(best[x]<a[cnt]){
            printf("-1\n");
            return;
        }
        ans++;
        int tMax=a[cnt];
        while(x<=N && cnt<N && best[x]>=tMax){x++;cnt++;tMax=max(tMax,a[cnt]);}
    }
    printf("%d\n",ans);
}

int main(void){
    freopen("1257d.inp","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++) scanf("%d",&a[i]);
        scanf("%d",&M);
        for(int i=0;i<M;i++) scanf("%d%d",&p[i],&s[i]);
        solve();
    }
    return 0;
}
