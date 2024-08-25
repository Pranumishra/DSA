#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    string str="pranav";
    int ch='z';
    if(str.find(ch)==string::npos){
        cout<<"Not Found";
    }
    else{
        cout<<str.find(ch);
    }
}