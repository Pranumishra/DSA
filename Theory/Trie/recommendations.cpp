#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class TrieNode{
    public:
    char ch;
    map<char,TrieNode*>mpp;
    bool terminal;

    TrieNode(char ch){
        this->ch=ch;
        terminal=false;
    }
};

void insert(TrieNode* root,string str){
    if(str.length()==0){
        root->terminal=true;
        return;
    }

    char currCh=str[0];
    TrieNode* newNode;

    if(root->mpp.find(currCh)!=root->mpp.end()){
        //found;
        newNode=root->mpp[currCh];
    }
    else{
        // not found
        root->mpp[currCh]=new TrieNode(currCh);
        newNode=root->mpp[currCh];
    }

    //recursion
    insert(newNode,str.substr(1));
}

//recommendations
void recommendations(TrieNode* &root,string str){
    if(root->mpp.size()==0){
        if(root->terminal){
            cout<<str<<endl;
        }
        return;
    }

    if(root->terminal){
       cout<<str<<endl;
    }

    TrieNode* nextNode;
    for(auto i: root->mpp){
        str.push_back(i.first);
        recommendations(i.second,str);
        str.pop_back();

    }
}
//searching
void search(TrieNode* &root,string str,string str1){
    if(str.length()==0){
        recommendations(root,str1);
    }

    char currCh=str[0];
    TrieNode* newNode;

    if(root->mpp.find(currCh)!=root->mpp.end()){
        //character found.
        newNode=root->mpp[currCh];
    }
    else{
        // character not found
        return;
    }

    //first charcter we have found now recursion will find the rest characters.
    return search(newNode,str.substr(1),str1);
}




int main(){
    TrieNode* root=new TrieNode('-');
    insert(root,"love");
    insert(root,"loving");
    insert(root,"lover");
    insert(root,"dove");
    insert(root,"dog");
    insert(root,"do");
    insert(root,"don");
    insert(root,"dont");

    //giving recommendations
    search(root,"d","d");

}