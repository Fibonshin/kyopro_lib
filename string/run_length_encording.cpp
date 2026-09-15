#include "../header.cpp"

// RunLengthEncoding O(N)
vector<pair<char,int>> RunLengthEncoding(string&x){
    vector<pair<char,int>> res;
    res.emplace_back(x[0],0);
    for(char c:x){
		if(res.back().first==c)res.back().second++;
		else res.emplace_back(c,1);
	}
    return res;
};

