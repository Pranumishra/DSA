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


//insertion
void insert(TrieNode* &root,string str){

    //base case
    if(str.length()==0){
        // pura word insert ho chuka hai iss liye last chacter pe terminal true hona chahiye
        root->terminal=true;
        return;
    }

    char currCh=str[0];
    TrieNode* newNode;

    if(root->mpp.find(currCh)!=root->mpp.end()){
        //character found.
        newNode=root->mpp[currCh];
    }
    else{
        // character not found
        root->mpp[currCh]=new TrieNode(currCh);
        newNode=root->mpp[currCh];
    }

    //first charcter we have inserted now recursion will insert the rest characters.
    insert(newNode,str.substr(1));

}



//searching
bool search(TrieNode* &root,string str){
    if(str.length()==0){
        if(root->terminal)
            return true;
        else
            return false;
    }

    char currCh=str[0];
    TrieNode* newNode;

    if(root->mpp.find(currCh)!=root->mpp.end()){
        //character found.
        newNode=root->mpp[currCh];
    }
    else{
        // character not found
        return false;
    }

    //first charcter we have found now recursion will find the rest characters.
    return search(newNode,str.substr(1));
}




//deletion
void deleteWord(TrieNode* root,string str){
    if(str.length()==0){
        root->terminal=false;
        return;
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
    return deleteWord(newNode,str.substr(1));
}


int main(){
    TrieNode* root=new TrieNode('-');
    insert(root,"love");
    insert(root,"LOVE");
    insert(root,"lover");
    insert(root,"dove");
    insert(root,"dog");
    insert(root,"do");
    insert(root,"don");
    insert(root,"dont");

    if(search(root,"don")){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found "<<endl;
    }

    deleteWord(root,"don");
    if(search(root,"don")){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found "<<endl;
    }
}