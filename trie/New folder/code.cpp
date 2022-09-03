#include<bits/stdc++.h>
using namespace std;

struct Node{
	Node* links[26];
	int freq;
	int prefix;

	Node() {
		for(int i=0;i<26;i++) links[i] = 0;
		freq = 0;
		prefix = 0;
	}

	bool containsKey(int i){
		return links[i] != NULL;
	}

	Node* getNext(int i){
		return links[i];
	}

	void put(int i,Node* node){
		links[i] = node;
	}
};

class Trie{
public:
	Node* root;
	Trie() {
		root = new Node();
	}

	void insert(string word,int f){
		Node* node = root;
		for(char ch:word){
			if(node->containsKey(ch-'a') == false)
				node->put(ch-'a',new Node());
			node = node->getNext(ch-'a');
			node->prefix += f;
		}
		node->prefix -= f;
		node->freq = f;
	}

	int getPrefix(string word){
		Node* node = root;
		for(char ch:word){
			if(node->containsKey(ch-'a') == false)
				return 0;
			node = node->getNext(ch-'a');
		}
		return node->prefix + node->freq;
	}

	int getFreq(string word){
		Node* node = root;
		for(char ch:word){
			if(node->containsKey(ch-'a') == false)
			node = node->getNext(ch-'a');
		}
		return node->freq;
	}

	void update(string word,int f){
		int prevFreq = getFreq(word);
		int offset = f-prevFreq;
		Node* node = root;
		for(char ch:word){
			node = node->getNext(ch-'a');
			node->prefix += offset;
		}
		node->prefix -= offset;
		node->freq = f;
	}
};

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;

	string type;
	string word;
	int num;

	Trie trie = Trie();

	while(t--){
		cin>>type>>word;
		if(type.compare("I") == 0 or type.compare("Q") == 0) cin>>num;

		if(type.compare("I") == 0) trie.insert(word,num);
		else if(type.compare("Q") == 0) cout<<trie.getPrefix(word)<<endl;
		else trie.update(word,num);
	}
}