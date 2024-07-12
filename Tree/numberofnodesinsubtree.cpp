#include<bits/stdc++.h>
// This question is from subordinataes cses 

using namespace std;
#define MAX 202020

vector<vector<int>> adj(MAX);
vector<int> subtree(MAX);


int subtrees(int node){
    if(adj[node].size()==0){
        // size hi zero he to wo leaf he na ki graph 

        return 1; 
        // kar denge aur leaf me subtree wale function me kuch daalne 
        // ki jaroorat nahi he bydefault zero hi he 1 to hame uske 
        // uper wale ke lye chhahye the 


    }else{

        // now we will calculate height of subtree for our node 
        int height=0;

        for( int i=0;i<adj[node].size();i++){
            height+=subtrees(adj[node][0]);

        }
        subtree[node]=height;
        return subtree[node]+1;
    }
}


void solve(){
    int n;
    cin>>n;

    for( int i=2;i<=n;i++){
        // ye batayega ki i ka boss kaun he ? 
       // yaani i kiske neeche he tree me 
       int  boss;
       cin>>boss;
       adj[boss].push_back(i);

    }

    // ab hame bas subtree ki length calculate karni he 

    subtrees(1);

    for( int i=1;i<=n;i++){
        cout<<subtree[i]<<" ";
    }

    cout<<'\n';


}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

        solve();
}