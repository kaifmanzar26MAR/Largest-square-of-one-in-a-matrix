#include<bits/stdc++.h>
using namespace std;
int maximalSquare(vector<vector<char>>& matrix) {
    vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
    int ans=0;
    for(int i=0;i<matrix.size();i++){
        if(matrix[i][matrix[0].size()-1]=='1' && ans==0) ans=1;

        dp[i][matrix[0].size()-1]=matrix[i][matrix[0].size()-1]-'0';
    }
    for(int i=0;i<matrix[0].size();i++){
        if(matrix[matrix.size()-1][i]=='1' && ans==0) ans=1;
        dp[matrix.size()-1][i]=matrix[matrix.size()-1][i]-'0';
    }
    
    for(int i=matrix.size()-2;i>=0;i--){
        for(int j=matrix[0].size()-2;j>=0;j--){
            if(matrix[i][j]=='1'){
                if(ans==0) ans=1;

                int mini=min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
                dp[i][j]=mini+1;
                ans=max(ans,dp[i][j]);
            }
            
        }
    }
    // for(int i=0;i<dp.size();i++){
    //     for(int j=0;j<dp[0].size();j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return ans*ans;
}
int main(){
    int n;
    int m;
    cout<<"enter n and m"<<endl;
    cin>>n>>m;
    cout<<"enter the matrix with only 0s and 1s" <<endl;
    vector<vector<char>> matrix;
    for(int i=0;i<n;i++){
        vector<char> v;
        for(int j=0;j<m;j++){
            char x;
            cin>>x;
            v.push_back(x);
        }
        matrix.push_back(v);
    }
    int area=maximalSquare(matrix);
    cout<<area;
return 0;
}
// 5 4
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
//op: 4