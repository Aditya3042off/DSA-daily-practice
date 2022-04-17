#include <bits/stdc++.h>
using namespace std;

struct Node{
	Node* links[2];

	bool containsBit(int bit){
		return links[bit] != NULL;
	}

	void put(int bit,Node* node){
		links[bit] = node;
	}

	Node* get(int bit){
		return links[bit];
	}

};

class Trie{
private: Node* root;
public:
	Trie(){
		root = new Node();
	}

	void insert(vector<int>& binary){
		Node* node = root;
		for(int i=0;i<32;i++){
			if(node->containsBit(binary[i]) == false){
				node->put(binary[i],new Node());
			}
			node = node->get(binary[i]);
		}
	}

	vector<int> findXOR(vector<int> number){
		vector<int> my_xor;
		Node* node = root;

		for(int i=0;i<32;i++){
			if(node->containsBit(number[i] ^ 1)){
				my_xor.push_back(number[i] ^ 1);
				node = node->get(number[i] ^ 1);
			}
			else{
				my_xor.push_back(number[i]);
				node = node->get(number[i]);
			}
		}
		return my_xor;
	}

};

void numToBin(int num,vector<int>& binary){
	while(num != 1){
		binary.push_back(num % 2);
		num = num / 2;
	}
	binary.push_back(1);
	while(binary.size() < 33)
		binary.push_back(0);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	vector<int> arr(n);

	for(int i=0;i<n;i++){
		cin>> arr[i];
	}

	int number;
	cin>>number;

	Trie trie = Trie();
	vector<int> binary;

	for(int i=0;i<n;i++){
		numToBin(arr[i],binary);
		trie.insert(binary);
		binary.clear();
	}

	vector<int> bin_ans;

	numToBin(number,binary);
	bin_ans = trie.findXOR(binary);

	int ans = 0;

	for(int i=0;i<32;i++)
		ans += (pow(2,i) * bin_ans[i]);

	cout<<ans;

}