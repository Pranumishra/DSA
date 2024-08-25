#include<iostream>
using namespace std;

int square_root(int a){
    int s=0;
    int e=a;
    int mid;
    int ans=-1;
    while(s<=e){
        mid=s+(e-s)/2;
        if(mid*mid<=a){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

double precise_square_root(int a,int precision){
    double sqrt=(double)square_root(a);
    double num;
    double step=0.1;
    for(int i=0;i<precision;i++){
        num=sqrt;
        while(num*num<=a){
            sqrt=num;
            num+=step;
        }
        step=step/10;
    }
    return sqrt;
}
int main(){
    int a;
    cout<<"enter whose square root you want to calculate : ";
    cin>>a;

    int decimalplaces;
    cout<<"enter till which decimal place : ";
    cin>>decimalplaces;   
    cout<<"SQRT : "<<precise_square_root(a,decimalplaces);
}