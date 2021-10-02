#include<bits/stdc++.h>
using namespace std;
class trie
 {
 public:
 	trie* children[26];
 	bool isEndOfWord;

 	trie(){
 		this->isEndOfWord = false;
 		for(int i=0;i<26;i++)
 			this->children[i] = nullptr;
 	}
 	
 };

 void insert(string word){
 		trie* curr = this;
 		for(char c: word){
 			if(!(curr->children[c-'a']))
 				curr->children[c] = new trie();
 			curr = curr->children[c-'a'];
 		}
 	}

 bool search(string word){
 		trie* curr = this;
 		for(char c:word){
 			if(!(curr->children[c-'a']))
 				return false;
 			curr = curr->children[c-'a'];
 		}
 		return isEndOfWord;
 	}

 bool startsWith(string pref){
 		trie* curr = this;
 		for(char c:pref){
 			if(!(curr->children[c-'a']))
 				return false;
 			curr = curr->children[c-'a'];
 		}
 		return true;
 	}

int main(){
	int n;
	cin>>n;
	trie* head  = new trie();
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		head->insert(s);
	}
	cout<<head->startsWith("p")<<endl;
	if(head->search("pqrs"))
		cout<<"Present"<<endl;
	else
		cout<<"Not Present"<<endl;
	return 0;
}