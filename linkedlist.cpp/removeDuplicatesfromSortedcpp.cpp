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

node *removeDuplicates(node *head)
{
	if (head == NULL) return head;
	map<int, int> track;
	node* p1 = head;

	while (p1) {
		track[p1->data]++;
		p1 = p1->next;
	}
	node* result = new node(0);
	node* out = result;
	for (auto x : track) {
		if (x.second >= 1) {
			result->next = new node(x.first);
			result = result->next;
		}
	}
	return out->next;
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
	insertattail(head, 3);
	insertattail(head, 3);
	insertattail(head, 6);
	insertattail(head, 7);
	display(head);
	removeDuplicates(head);
	display(head);
}






