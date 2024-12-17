#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
	struct TrieNode* children[ALPHABET_SIZE];
    int count;
};

struct TrieNode* getNode(void)
{
	struct TrieNode* pNode = new TrieNode;

	pNode->count=0;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

void insert(struct TrieNode* root, string key)
{
	struct TrieNode* pCrawl = root;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();
        
		pCrawl = pCrawl->children[index];
		pCrawl->count++;
	}

}

int search(struct TrieNode* root, string key)
{
	struct TrieNode* pCrawl = root;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return 0;

		pCrawl = pCrawl->children[index];
	}

	return pCrawl->count;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    struct TrieNode* root = getNode();
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
    	string s;
    	cin>>s;
    	insert(root,s);
    }
    while(q--)
    {
    	string s;
    	cin>>s;
    	int c=search(root,s);
    	cout<<c<<'\n';
    }
	
	return 0;
}
