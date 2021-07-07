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


node* Intersection(node* l1, node* l2) {
	node* d1 = l1;
	node* d2 = l2;
	if (!d1 || !d2) {
		return NULL;
	}
	while (d1 != d2) {
		d1 = (d1 == NULL) ? l2 : d1->next;
		d2 = (d2 == NULL) ? l1 : d2->next;
	}
	return d1;
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






