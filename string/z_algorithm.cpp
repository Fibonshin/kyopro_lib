#include "../header.cpp"

// Z algorithm O(|S|)
vector<int> z_algo(string&s){
    int n= s.size();
    vector<int> z(n+1);
    z[0]=n;
    int i=1,j=0;
    while (i < n){
        while (i+j < n && s[i+j]==s[j])j++;
        z[i]=j;
        if(j==0){
            i++;
            continue;
        }
        int k=1;
        while (z[k] < j-k){
            z[i+k]=z[k];
            k++;
        }
        i+=k;
        j-=k;
    }
    return z;
}
