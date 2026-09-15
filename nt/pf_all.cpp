#include "../header.cpp"

// n以下のすべての非負整数の素因数列挙 O(NlogN)?
// 0,1は空
vector<vector<pair<ll,ll>>> pf_all(int n){
    vector<vector<pair<ll,ll>>> res(n+1);
    for(int i=2;i<=n;i++){
        if(!res[i].empty())continue;
        for(int j=i;j<=n;j+=i){
            res[j].emplace_back(i,1);
            for(int mj=j;(mj/=i)%i==0;)res[j].back().second++;
        }
    }
    return res;
}
