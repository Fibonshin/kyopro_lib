#if __has_include(<acl_bits.hpp>)
#include <acl_bits.hpp>
#else
#include <bits/stdc++.h>
#include <atcoder/all>
#endif
using namespace atcoder;
using namespace std;
using ll=long long;
using ld=long double;
using P = pair<ll,ll>;
using TUP = tuple<ll,ll,ll>;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename t,typename u>inline bool chmax(t&a,u b){return a<b?a=b,1:0;}
template<typename t,typename u>inline bool chmin(t&a,u b){return a>b?a=b,1:0;}
int yn(bool b){cout<<(b?"Yes\n":"No\n");return 0;}
vector<int> di={1,0,-1,0},dj={0,1,0,-1};
using mint = modint998244353;
ostream&operator<<(ostream&os,const mint& x){os<<x.val();return os;};
template <typename t>ostream&operator<<(ostream&os,const vector<t>&x){for(const t&i:x)os<<i<<' ';return os;}
template <typename t>ostream&operator<<(ostream&os,const vector<vector<t>>&x){for(const vector<t>&i:x)os<<i<<'\n';return os;}
ll inf=2e18;
