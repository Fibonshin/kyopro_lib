#include "../header.cpp"

//約数列挙 O(√N)
vector<ll> enumdiv(ll n) { 
    vector<ll> res;
    for (ll i = 1; i <= sqrt(n); i++) if (n%i == 0) { res.push_back(i); if (i != sqrt(n)) res.push_back(n / i); }
    sort(res.begin(), res.end());
    return res;
}

