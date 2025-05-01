#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;

    while(t--){
        int m=10;
        int n=10;

        vector<vector<char>> matrix(m,vector<char>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
            }
        }
        int starting_row=0;
        int ending_col=n-1;
        int ending_row=m-1;
        int starting_col=0;
        int count=0;

        int score=1;
        int ans=0;
        while(count<=m*n && starting_row<=ending_row && starting_col<=ending_col){
            for(int i=starting_col;i<=ending_col && count<m*n;i++){
                if(matrix[starting_row][i]=='X'){
                    ans+=score;
                }
                count++;
            }
            starting_row++;

            for(int i=starting_row;i<=ending_row && count<m*n;i++){
                if(matrix[i][ending_col]=='X'){
                    ans+=score;
                }
                count++;
            }
            ending_col--;

            for(int i=ending_col;i>=starting_col && count<m*n;i--){
                if(matrix[ending_row][i]=='X'){
                    ans+=score;
                }
                count++;
            }
            ending_row--;

            for(int i=ending_row;i>=starting_row && count<m*n;i--){
                if(matrix[i][starting_col]=='X'){
                    ans+=score;
                }
                count++;
            }
            starting_col++;
            score++;
        }

        cout<<ans<<endl;
    }
}
