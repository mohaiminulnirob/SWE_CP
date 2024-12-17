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
    int charCount=0;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';

		pCrawl = pCrawl->children[index];
		charCount++;
		if(pCrawl->count==1)
			break;
	}

	return charCount;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    int t;
    cin>>t;
    while(t--)
    {
        struct TrieNode* root = getNode();
        int totalCount=0;
        int n;
        cin>>n;
        string s[n];
        for(int i=0;i<n;i++)
        {
        	cin>>s[i];
        	insert(root,s[i]);
        }
        for(int i=0;i<n;i++)
        {
        	totalCount+=search(root,s[i]);
        }
        cout<<totalCount<<'\n';
    }
	
	return 0;
}
