#include<bits/stdc++.h>
using namespace std;

struct Node{
	Node* links[26];
	bool flag = false;
	int num = 0;

	bool containsKey(char ch){
		return links[ch-'a'] != NULL;
	}

	void put(char ch,Node* node){
		links[ch-'a'] = node;
		num++;
	}

	Node* get(char ch){
		return links[ch-'a'];
	}

	void setEnd(){
		flag = true;
	}
};

class Trie{
private:
	Node* root;
public:
	Trie(){
		root = new Node();
	}

	void insert(string word){
		Node* node = root;

		for(int i=0;i<word.size();i++){
			if(node->containsKey(word[i]) == false){
				node->put(word[i],new Node());
			}
			node->num++;
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	int solve(string word,Node* node) {
		for(int i=0;i<word.size();i++){
			node = node->get(word[i]);
		}
		return node->num;
	}

	int countVal(string str) {
		return solve(str,root);
	}
};

int solve(vector<string>& arr,string question) {
	Trie trie = Trie();
	
	for(int i=0;i<arr.size();i++){
		trie.insert(arr[i]);
	}

	return trie.countVal(question) ;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	vector<string> array = {"apk", "app", "apple", "arp", "array" };

	string question  = "ap";

	cout<<solve(array,question);
}