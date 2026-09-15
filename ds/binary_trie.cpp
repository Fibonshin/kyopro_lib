#include "../header.cpp"

// binaryだけじゃなくて、boolをintにすれば整数列なんでも入れれるようにできるはず。
// cnt_lowerで数列s以下の数列、cnt_greaterで数列s以上の数列の数が得られる。
struct Trie{
    struct Edge
    {
        vector<int> ch;
        ll cnt=0; // その頂点が末尾
        ll common=0; // その頂点を通る
        bool c;
        Edge(bool _c):c(_c){};
    };

    vector<Edge> dat;
    Trie(){
        dat.push_back(Edge(0));
    };

    void insert(vector<bool> s,int num=1){
        int cur=0;
        for(bool c:s){
            dat[cur].common+=num;
            bool ok=0;
            for(int i:dat[cur].ch){
                if(dat[i].c==c){
                    cur=i;
                    ok=1;
                    break;
                }
            }
            if(!ok){
                dat[cur].ch.push_back(dat.size());
                cur=dat.size();
                dat.push_back(Edge(c));
            }
        }
        dat[cur].common+=num;
        dat[cur].cnt+=num;
    }

    int search(vector<bool> s,bool prefix=false){
        int cur=0;
        for(bool c:s){
            bool ok=0;
            for(int i:dat[cur].ch)if(dat[i].c==c){
                ok=1;
                cur=i;
                break;
            }
            if(!ok)return 0;
        }
        if(prefix)return dat[cur].common;
        return dat[cur].cnt;
    }

	int cnt_lower(vector<bool> s){
		int cur=0;
		int cnt=0;
		for(bool c:s){
			int nx=-1;
			for(int i:dat[cur].ch){
				if(dat[i].c==c)nx=i;
				if(dat[i].c<c)cnt+=dat[i].common;
			}
			if(nx==-1)return cnt;
			cur=nx;
		}
		return cnt;
	}

	int cnt_grater(vector<bool> s){
		int cur=0;
		int cnt=0;
		for(bool c:s){
			int nx=-1;
			for(int i:dat[cur].ch){
				if(dat[i].c==c){
					cnt+=dat[i].cnt;
					nx=i;
				}
				if(dat[i].c>c)cnt+=dat[i].common;
			}
			if(nx==-1)return cnt;
			cur=nx;
		}
		return cnt;
	}
};
