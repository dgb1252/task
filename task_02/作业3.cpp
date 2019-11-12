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
node* mergelist_sort(node* head1, node* head2)
{
	node* p1 = head1;
	p1 = p1->next;
	node* p2 = head2;
	p2 = p2->next;
	node* head3 = new node;
	node* pre = head3;
	while (p1 != NULL && p2 != NULL)
	{
		node* p3 = new node;
		if (p1->c < p2->c)
		{
			p3->c = p1->c;
			p1 = p1->next;
		}
		else
		{
			p3->c = p2->c;
			p2 = p2->next;
		}
		pre->next = p3;
		pre = p3;
		p3->next = NULL;
		if (p1 == NULL)
		{
			for (; p2 != NULL; p2 = p2->next) { node* p3 = new node; p3->c = p2->c; pre->next = p3; pre = p3; p3->next = NULL; }
			break;
		}
		if (p1 == NULL)
		{
			for (; p1 != NULL; p1 = p1->next) { node* p3 = new node; p3->c = p1->c; pre->next = p3; pre = p3; p3->next = NULL; }
			break;
		}
	}
	return head3;
}//采用归并合并两个链表
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
int main()
{
	int a[4] = { 1,2,3,5 }, b[4]{ 2,4,7,8 };
	node* heada = creatlist(a, 4);
	node* headb = creatlist(b, 4);
	node* headc = mergelist_sort(heada, headb);
	printlist(headc);
	deletelist(heada);
	deletelist(headb);
	deletelist(headc);
}