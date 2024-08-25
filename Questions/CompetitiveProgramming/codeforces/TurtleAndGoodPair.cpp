#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Info{
    public:
    char val;
    int count;
    Info(char ch, int cnt) {
        this->val = ch;
        this->count = cnt;
    }
};
class compare{
    public:
        bool operator()(Info a, Info b) {
            return a.count < b.count;
        }
};

int main(){
    int t;
    cin>>t;
    int n;
    string s;
    for(int a=1;a<=t;a++){
        cin>>n;
        cin>>s;

        int arr[26]={0};
        for(auto ch:s){
            arr[ch-'a']++;
        }

        priority_queue<Info, vector<Info>, compare> maxHeap;
        //push all characters into heap, where freq > 0
        for(int i=0; i<26; i++) {
            if(arr[i] > 0) {
                Info temp(i+'a', arr[i]);
                maxHeap.push(temp);
            }
        }    

        string ans = "";

        while(maxHeap.size() > 1) {
            Info first = maxHeap.top();
            maxHeap.pop();
            Info second = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.val);
            first.count--;
            ans.push_back(second.val);
            second.count--;

            if(first.count > 0) {
                maxHeap.push(first);
            }
            if(second.count > 0) {
                maxHeap.push(second);
            }
        }            
        while(maxHeap.size() == 1) {
            Info first = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.val);
            first.count--;
            if(first.count > 0) {
                maxHeap.push(first);
            }
        }
        cout<<ans<<endl;
    
    }
}