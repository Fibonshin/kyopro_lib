#include "../header.cpp"

//誤差なしsqrt
ll isqrt(ll x){
    ll ac=0,wa=1e9+1;
    while(ac+1 < wa){
        ll m = (ac+wa)/2;
        if(m <= 1e9 && m*m <=x)ac = m;
        else wa = m;
    }
    return ac;
}

