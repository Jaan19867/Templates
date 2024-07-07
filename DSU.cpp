#include<bits/stdc++.h>

using namespace std;

class DisjointSet{
vector<int> rank, parent;

public: 
DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);

    for( int i=0;i<=n;i++){
        parent[i]=i;
    }
}

// do function banane he parentfind , void unionbyrank

int findUPar(int node){
    if(parent[node]==node){
        return node; 
    }
    return parent[node]=findUPar(parent[node]);
}


void unionByRank(int u, int v){
    // find ultimate parent 
    int ult_par_u=parent[u];
    int ult_par_v=parent[v];

    // agar parent hi same he to dono nodes ek hi component ke he to rank bhi same hogi kyunki wo to parent ka hi dkehte he aur parent to same he hi to kuch nahi karna 
      if(ult_par_u==ult_par_v){
        return;  
      }
      // ab parent ke rank pe kaam karna he 

      if(rank[ult_par_u]<rank[ult_par_v]){
        // 
        parent[ult_par_u]=ult_par_v;
      }else if(rank[ult_par_u]>rank[ult_par_v]){
        parent[ult_par_v]=ult_par_u;

      }else{
        // rank parent ki barabar he to kisi ko bhi jod do 
        parent[ult_par_u]=ult_par_v;
        // aur jisse joda he uski rank ++; kar do 
        rank[ult_par_v]++;
      }
}


};

void solve(){

DisjointSet ds(7);
ds.unionByRank(1,2);
ds.unionByRank(2,3);
ds.unionByRank(4,6);
ds.unionByRank(4,5);

// check 1 and 4 lie on the same component or not 
if(ds.findUPar(1)==ds.findUPar(4)){
    cout<<"YES";

}else{
    cout<<"NO";
}

    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin>>T;
    while(T--)
        solve();
}