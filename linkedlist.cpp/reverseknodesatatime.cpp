#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node(int val) {
		data = val;
		next = NULL;
	}
};

void insertattail(node* &head, int val) {
	node* n = new node(val);
	if (head == NULL) {
		head = n;
		return;
	}
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
}


void reverseknode(Node* &head, int k) {
	int n = 0;
	Node* size = head;
	while (size != NULL) {
		size = size->next;
		n++;
	}

	Node* dummy = new Node(0);
	dummy->next = head;
	Node* current = head;
	Node* nxt = current -> next;
	Node* pre = dummy;

	for (int i = 0; i < n / k; ++i)
	{
		for (int i = 0; i < k; i++) {
			current->next = nxt->next;
			nxt->next = current->next;
			pre->next = nxt;
			nxt->next = current->next;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	node* head = NULL;
	insertattail(head, 1);
	insertattail(head, 2);
	insertattail(head, 3);
	insertathead(head, 4);
	display(head);
	display(head);
}






