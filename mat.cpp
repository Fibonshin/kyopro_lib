#include "header.cpp"
 
// 行列積
template<typename T> vector<vector<T>> mat_mul(const vector<vector<T>>& a,const vector<vector<T>>& b){
    if(a[0].size()!=b.size())return vector(a.size(),vector<T>(b[0].size()));
    vector res(a.size(),vector<T>(b[0].size()));
    rep(i,a.size())rep(j,b[0].size())rep(k,b.size()){
        res[i][j]+=a[i][k]*b[k][j];
    }
    return res;
}

// 行列累乗
template<typename T> vector<vector<T>> mat_pow(vector<vector<T>> a,ll n){
    vector<vector<T>> res(a.size(),vector<T>(a[0].size()));
    rep(i,a.size())res[i][i]=1;
    while (n){
        if(n&1)res=mat_mul(a,res);
        a=mat_mul(a,a);
        n>>=1;
    }
    return res;
}

int main(){

}
