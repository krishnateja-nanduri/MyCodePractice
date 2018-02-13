//https://practice.geeksforgeeks.org/problems/huffman-encoding/0   *****

#include <bits/stdc++.h>

using namespace std;

struct Node {
    char c;
    int freq;
    Node *left;
    Node *right;
};

void traverse(Node *root, string str) {
    if (!root)
        return;

    if (root->c != '$')
        cout << str << " ";
        
    traverse(root->left, str + '0');
    traverse(root->right, str + '1');
        
}

int main()
{
	int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        string str;
        cin >> str;
        priority_queue<Node*, vector<Node*>, function<bool(const Node*, const Node*)>> pq([](const Node* n1, const Node* n2) { return n1->freq > n2->freq; });
        for (int i = 0; i < str.size(); ++i) {
            int f;
            cin >> f;
            Node *n = new Node();
            n->c = str[i];
            n->freq = f;
            n->left = nullptr;
            n->right = nullptr;
            pq.push(n);
        }
        
        if (pq.size() == 1) {
            cout << 0 << endl;
            return 0;
        }
        
        while (pq.size() > 1) {
            Node* n1 = pq.top();
            pq.pop();
            Node* n2 = pq.top();
            pq.pop();
            
            Node *parent = new Node();
            parent->freq = n1->freq + n2->freq;
            parent->left = n1;
            parent->right = n2;
            parent->c = '$';
            pq.push(parent);
        }
        
        string code;
        traverse(pq.top(), code);
        cout << endl;
    }
	return 0;
}
