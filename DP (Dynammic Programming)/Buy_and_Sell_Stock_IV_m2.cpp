#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{1,2,3,4,5};
   int n = price.size();
   int k =3;
   vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(k+1,0)));
   for(int i=n-1;i>=0;i--){
      for(int j=0;j<=1;j++){
         for(int m=1;m<k+1;m++){
            if(j){
               dp[i][j][m] = max((-price[i]+dp[i+1][0][m]), (0+dp[i+1][1][m]));
            }
            else dp[i][j][m] = max((price[i]+dp[i+1][1][m-1]), (0+dp[i+1][0][m]));
         }
      }
   }
   cout<<dp[0][1][k]<<endl;
}