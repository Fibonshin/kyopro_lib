#include "../header.cpp"

// Trie木
//使用例 https://atcoder.jp/contests/abc353/submissions/58002391

struct Trie{
    struct Edge
    {
        vector<int> ch;
        ll cnt=0; // その頂点が末尾となる単語数
        ll common=0; // その頂点を通る単語数
        char c;
        Edge(char _c):c(_c){};
    };

    vector<Edge> dat;
    Trie(){
        dat.push_back(Edge(' '));
    };

    void insert(string s,int num=1){
        int cur=0;
        for(char c:s){
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

    int search(string s,bool prefix=false){
        int cur=0;
        for(char c:s){
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
};
