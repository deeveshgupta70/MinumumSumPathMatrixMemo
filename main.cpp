#include<bits/stdc++.h>

using namespace std;

int getMinPathHelper( int **a, int n, int m, int i , int j , int** res){
    
    if( i == n-1 && j == m-1) return a[i][j];
    
    if( i >= n || j >= m) return INT_MAX;
    
    if( res[i][j] != -1) return res[i][j];
    
    int x = getMinPathHelper( a,n,m,i,j+1,res);
    int y = getMinPathHelper( a,n,m,i+1,j+1,res);
    int z = getMinPathHelper( a,n,m,i+1,j,res);
     
    int ans  = min( x, min( y , z)) + a[i][j];
     
     res[i][j] = ans;
     return ans;
}

int getMinPath( int **a , int n,int m){
    
    int **res = new int*[n];
    
    for( int i = 0; i < n;i++){
        
        res[i] = new int[m];
        for( int j = 0 ; j < m; j++) res[i][j] = -1;
    };
    
    return getMinPathHelper( a,n,m,0,0,res);
}



int main(){
    
    int n,m;
    cin>>n>>m;
    int **a = new int*[n];
    
    for( int i = 0; i < n;i++){
        
        a[i] = new int[m];
        for( int j = 0 ; j < m; j++) cin>>a[i][j];
    }
    
    // for( int i = 0; i < n; i++){
    //     for( int j = 0; j < m; j++) cout<<a[i][j]<<" ";
        
    //     cout<<"\n";
    // }
    
    cout<<"Minimum Cost to End : "<<getMinPath(a,n,m);
    return 0;
}

/*
input:
2 3
3 6 9
1 2 6

output:
Minimum Cost to End : 11
*/
