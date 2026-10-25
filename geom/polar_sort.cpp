#include "vector.cpp"
// https://atcoder.jp/contests/abc481/submissions/80384188
// // sortされた時の元のindex列を返す

template<class T> vector<int> polar_sort(vector<V<T>>&v){
	int n=v.size();
	vector<int> is(n);
	iota(is.begin(),is.end(),0);
	sort(is.begin(),is.end(),[&v](int a,int b){
			bool fa=(v[a].y<0 || (v[a].y==0 && v[a].x<0));
			bool fb=(v[b].y<0 || (v[b].y==0 && v[b].x<0));
			if(fa^fb)return fb;
			return v[a].cross(v[b])>0;
			});
	return is;
}

