#include "../header.cpp"

// エラトステネスの篩 O(NloglogN)
vector<int> eratosthenes(int x){
    vector<bool> deleted(x+1);
    for(int i=2;i<=sqrt(x);i++){
        if(deleted[i])continue;
        for(int j=i*2;j<=x;j+=i)deleted[j]=1;
    }
    vector<int> res;
    for(int i=2;i<=x;i++)if(!deleted[i])res.push_back(i);
    return res;
}

