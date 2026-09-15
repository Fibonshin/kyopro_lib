#include "../header.cpp"

//拡張ユークリッド ax+by=gcd(a,b)の(x,y)
// verify at https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=8933684#1
pair<ll,ll> extgcd(ll a,ll b){
    if(b==0)return {1,0};
    ll q=a/b,r=a%b;
    auto[x,y]=extgcd(b,r);
    return {y,x-q*y};
}

