#include "../header.cpp"

//遅延評価セグメント木 
//seg(初期値の配列 , 求めるものがmaxなら 1 )
//配列の添字は0-indexed
template<typename T>
class lazyRMQ{
    int n;
    bool is_max;
    const T INF = numeric_limits<T>::max();
    T e;
    vector<T> dat,lazy;
public:
    lazyRMQ(vector<T> a,bool is_max_=0):n(__bit_ceil(a.size())),is_max(is_max_),e(is_max?0:INF),dat(2*n,e),lazy(2*n,INF){
        rep(i,(int)a.size())dat[i+n]=a[i];
        for(int i=n-1;i>=1;i--){
            if(is_max)dat[i]=max(dat[2*i],dat[2*i+1]);
            else min(dat[2*i],dat[2*i+1]);
        }
    }

    void update(int l,int r,T x){update_sub(l,r,x,1,0,n);}

    void set(int k,T x){update(k,k+1,x);}
    
    T query(int l,int r){return query_sub(l,r,1,0,n);}

    T get(int k){return query(k,k+1);}

    void debug(){
        for(T&i:dat)cout<<i<<' ';
        // for(T&i:lazy)cout<<i<<' ';
        cout<<endl;
    }

private:
    void eval(int k){
        if(lazy[k]==INF)return;
        if(k < n){
            lazy[2*k] = lazy[k];
            lazy[2*k+1] = lazy[k];
        }
        dat[k]=lazy[k];
        lazy[k]=INF;
    }

    void update_sub(int l,int r,T x,int k,int a,int b){
        eval(k);
        if(l<=a && b<=r){
            lazy[k]=x;
            eval(k);
        }else if(l < b && a < r){
            update_sub(l,r,x,k*2,a,(a+b)/2);
            update_sub(l,r,x,k*2+1,(a+b)/2,b);
            if(is_max)dat[k]=max(dat[k*2],dat[k*2+1]);
            else dat[k]=min(dat[k*2],dat[k*2+1]);
        }
    }

    T query_sub(int l,int r,int k,int a,int b){
        eval(k);
        if(b<=l || r<=a)return e;
        if(l<=a && b<=r)return dat[k];
        T vl = query_sub(l,r,2*k,a,(a+b)/2);
        T vr = query_sub(l,r,2*k+1,(a+b)/2,b);
        if(is_max)return max(vl,vr);
        else return min(vl,vr);
    }
};

