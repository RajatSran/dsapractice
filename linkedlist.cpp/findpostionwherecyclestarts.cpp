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


Node* findcyclenode(Node* head) {
	if (head == NULL) return head;
	Node* slow = head;
	Node* fast = head;
	bool flag = false;
	while (fast->next != NULL) {
		slow = slow->next;
		fast = fast->nexxt->next;
		if (slow == fast) {
			flag = true;
			break;
		}
	}
	if (!flag) {
		return NULL;
	}
	Node* entry = head;
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
	insertathead(head, 4);
	insertathead(head, 5);
	insertathead(head, 6);
	insertathead(head, 7);
	display(head);
	rotate(head);
	display(head);
}






