#include<iostream>
using namespace std;

int divide(int a, int b){
    int s=0;
    int e=a;
    int mid;
    int ans=-1;
    while(s<=e){
        mid=s+(e-s)/2;
        if(b*mid<=a){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}


double precise_divide(int a, int b ,int decimalplaces){
    double ans=(double)divide(a,b);
    double step=0.1;
    double temp;
    for(int i=0;i<decimalplaces;i++){
        temp=ans; //it is an important step it cant be done outside loop because for every next decimal place b*temp should be less than a.
                  //as ans is always less than a . so we have done temp = ans
        while(b*temp<=a){
            ans=temp;
            temp+=step;
        }
        step=step/10;
    }
    return ans;
}

int main(){
    int a;
    int b;
    int decimalplaces;
    cout<<"enter numerator : ";
    cin>>a;
    cout<<"enter denominator : ";
    cin>>b;

    cout<<"enter decimal places : ";
    cin>>decimalplaces;
    cout<<precise_divide(a,b,decimalplaces);
}