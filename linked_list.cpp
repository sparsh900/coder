#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class linked_list {
	private: 
		node *head;
	public:
		linked_list()
		{
			head = NULL;
		}
	void add();
	void display();
	void add_begin();
	void add_mid(int val);
	void del_beg();
	void del_end();
	void del_mid(int val);
};

void linked_list::add()
{
	int n;
	cout<<"Enter the value:\n";
	cin>>n;
	node *t = new node;
	t->data = n;
	t->next = NULL;
	if(head==NULL)
	{
		head=t;
	}
	else
	{
		node *ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=t;
	}
}

void linked_list::add_begin()
{
	int n;
	cout<<"Enter the value that you want to enter\n";
	cin>>n;
	node *temp = new node;
	temp->data=n;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}

void linked_list::add_mid(int val)
{
	cout<<"Enter the value:\n";
	int n;
	cin>>n;
	node *temp=new node;
	temp->data=n;
	temp->next=NULL;
	node *ptr=head;
	node *value=NULL;
	if(head==NULL)
	{
		printf("Linked List Empty");
		return;
	}
	while(ptr->data!=val)
	{
		value=ptr;
		ptr=ptr->next;
	}
	value->next=temp;
	temp->next=ptr;
}

void linked_list::del_beg()
{
	if(head==NULL)
	{
		cout<<"LL Empty\n";
		return;
	}
	node *ptr=head;
	head=ptr->next;
	delete(ptr);
	ptr->next=NULL;
	ptr=NULL;
}

void linked_list::del_end()
{
	if(head==NULL)
	{
		cout<<"LL Empty\n";
		return;
	}
	node *ptr=head;
	while((ptr->next)->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=NULL;
	delete(ptr->next);
}

void linked_list::del_mid(int val)
{
	if(head==NULL)
	{
		cout<<"LL Empty\n";
		return;
	}
	node *ptr=head;
	node *value=head;
	while((ptr)->data!=val)
	{
		value=ptr;
		ptr=ptr->next;
	}
	value->next=ptr->next;
	delete(ptr);
	ptr->next=NULL;
}

void linked_list::display()
{
	node *p;
	p=head;
	while(p!=NULL)
	{
		cout<<p->data<<"	";
		p=p->next;
	}
}

int main()
{
	linked_list l1;int n;
	cout<<"Enter the number of values that you want to enter\n";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		l1.add();
	}
	/*cout<<"Enter the value before which you want to enter the node\n";
	int f;
	cin>>f;
	l1.add_mid(f);*/
	cout<<"Enter the value which you want to delete\n";
	int d;
	cin>>d;
	l1.del_mid(d);
	l1.display();
}
