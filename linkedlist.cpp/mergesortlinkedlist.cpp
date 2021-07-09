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


node* findcyclenode(node* head) {
	if (head == NULL) return head;
	node* slow = head;
	node* fast = head;
	bool flag = false;
	while (fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			flag = true;
			break;
		}
	}
	if (!flag) {
		return NULL;
	}
	node* entry = head;
	while (entry != slow) {
		entry = entry->next;
		slow = slow->next;
	}
	return slow;
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
	insertattail(head, 4);
	insertattail(head, 5);
	insertattail(head, 6);
	insertattail(head, 7);
	// display(head);
	cout << findcyclenode(head)->data;
	// display(head);
}






