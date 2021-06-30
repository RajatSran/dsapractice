#include<bits/stdc++.h>
using namespace std;

struct Node {
        int val;
        struct Node* left;
        struct Node* right;
        Node(int data) {
                val = data;
                left = NULL;
                right = NULL;
        }
};

int sumreplacement(Node* &root) {
        if (root == NULL) return 0;
        int l = sumreplacement(root->left);
        int r = sumreplacement(root->right);

        if (root->left != NULL) root->val += l;
        if (root->right != NULL) root->val += r;
        return root->val;

}

void preorder(Node* root) {
        if (root == NULL) return ;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
}

int main() {
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif
        struct Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->left = new Node(6);
        root->right->right = new Node(7);
        preorder(root);
        cout << endl;
        sumreplacement(root);
        preorder(root);
        return 0;
}