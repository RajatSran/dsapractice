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


void rotate(node* &head, int k) {
	if (head == NULL || head->next == NULL || k == 0) {
		return head;
	}
	int n = 1;
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
		n++;
	}
	k = k % n;
	temp->next = head;
	for (int i = 0; i < n - k; i++) {
		temp = temp->next;
	}
	head = temp->next;
	temp->next = NULL;
	return head;
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
	insertathead(head, 5);
	insertathead(head, 6);
	insertathead(head, 7);
	display(head);
	rotate(head, 3);
	display(head);
}






