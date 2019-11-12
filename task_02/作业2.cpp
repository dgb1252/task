#include<iostream>
using namespace std;
typedef struct node {
	int c;
	node* next;
}node1;
node* creatlist(int arr[], int n)
{
	node* head = new node;
	node* pre = head;
	for (int i = 0; i < n; i++)
	{
		node* p = new node;
		p->c = arr[i];
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	return head;
}
void printlist(node* head)
{
	node* p = head;
	p = p->next;
	while (p != NULL)
	{
		cout << p->c << '\t';
		p = p->next;
	}
}
void deletelist(node* head)
{
	node* p = head;
	while (head->next != NULL)
	{
		head = head->next;
		delete p;
		p = head;
	}
	delete head;
}
int main()
{
	int a[8]{ 1,4,2,5,1,4,3,8 };
	node* head = creatlist(a, 8);
	printlist(head);
	deletelist(head);
}