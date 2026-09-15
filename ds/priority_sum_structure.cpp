#include "../header.cpp"
 

// PrioritySumStructure(更新ありの数列の大きい要素K個の総和を返す)
// https://atcoder.jp/contests/abc306/submissions/50482538 降順ver
// https://atcoder.jp/contests/abc281/submissions/50482691 昇順ver
// https://ei1333.github.io/luzhiled/snippets/structure/priority-sum-structure.html

//Priority queueで高速化できる。
//less,greaterで切り替えられる用にしたほうがいい。
//PriorityKthStructureを改変するのが良い。

struct PrioritySumStructure{
    ll k,sum,siz;
    multiset<ll> ge,le;
    PrioritySumStructure(int _k):k(_k),sum(0),siz(0){};
    
    void add(int x){
        siz++;
        ge.insert(x);sum+=x;
        if(ge.size()>k){
            le.insert(*ge.begin());
            sum-=*ge.begin();
            ge.erase(ge.begin());
        }
    }

    void del(int x){
        assert(siz);
        siz--;
        if(ge.find(x)!=ge.end()){
            ge.erase(ge.find(x));sum-=x;
            if(le.size()){
                ge.insert(*le.rbegin());sum+=*le.rbegin();
                le.erase(le.find(*le.rbegin()));
            }
        }else{
            assert(le.find(x)!=le.end());
            le.erase(le.find(x));
        }
    }
};
