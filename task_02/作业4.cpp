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
}//��������
node* creatlist(int n)
{
	node* head = new node;
	node* pre = head;
	for (int i = 0; i < n; i++)
	{
		node* p = new node;
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	return head;
}//��������
void reverselist(node* head1, node* head2)
{
	node* p1 = head1;
	p1 = head1->next;
	node* pre = head1;
	while (p1->next != NULL)
	{
		pre = p1;
		p1 = p1->next;
	}//�õ���һ����������һ���ڵ�
	head2->next->c = p1->c;
	head2 = head2->next;
	delete p1;
	pre->next = NULL;
	if (head2->next == NULL)return;
	reverselist(head1, head2);
}//��ת����
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
}//ɾ������
void printlist(node* head)
{
	node* p = head;
	p = p->next;
	while (p != NULL)
	{
		cout << p->c << '\t';
		p = p->next;
	}
}//��ӡ����
int main()
{
	int a[8]{ 1,4,2,5,1,4,3,8 };
	node* head1 = creatlist(a, 8);
	node* head2 = creatlist(8);
	reverselist(head1, head2);
	printlist(head2);
	deletelist(head2);
}