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

void insertathead(node* &head, int val) {
	node* n = new node(val);
	n->next = head;
	head = n;
	return;
}

void display(node* head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void deletion(node* &head, int val) {
	if (head == NULL) {
		return;
	}

	node* temp = head;
	if (temp->data == val) {
		head = head->next;
		delete temp;
		return;
	}

	while (temp->next->data != val) {
		temp = temp->next;
	}

	node* todelete = temp->next;
	temp->next = temp->next->next;
	delete todelete;
}

void reverse(node* &head) {
	if (head == NULL || head->next == NULL) {
		return;
	}
	node* prev = NULL;
	node* curr = head;
	node* nextptr;
	while (curr != NULL) {
		nextptr = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextptr;
	}
	head = prev;
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
	reverse(head);
	display(head);
}






