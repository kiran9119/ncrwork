using namespace std;
#include<iostream>
struct node {
	int data;
	struct node * next;
};

class LinkedList
{
	struct node * start;


public:

	LinkedList()
	{
		start = NULL;
	}

	void insertAtBegining(int ele)
	{
		if (start == NULL)
		{
			struct node *nn = new node;
			nn->data = ele;
			nn->next = NULL;
			start = nn;
		}
		else
		{
			struct node *nn = new node;
			nn->data = ele;
			nn->next = start;
			start = nn;
		}

	}

	void insertAtEnd(int ele)
	{
		if (start == NULL)
		{
			struct node *nn = new node;
			nn->data = ele;
			nn->next = NULL;
			start = nn;
		}

		else
		{
			struct node * temp, *nn;
			nn = new node;
			nn->data = ele;
			temp = start;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = nn;
			nn->next = NULL;
		}
	}

	void selfAdjust(int ele)
	{
		struct node * temp;
		temp = start;
		while (temp->next->data != ele)
			temp = temp->next;
		struct node *temp2 = temp->next;
		if (temp->next->next == NULL)
			temp->next = NULL;
		else
			temp->next = temp->next->next;
		temp2->next = start;
		start = temp2;

	}

	void display()
	{
		if (start == NULL)
		{
			cout << "Empty LinkedList\n";
			return;
		}
		struct node * temp;
		temp = start;
		while (temp->next != NULL) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << temp->data << "\n";
	}
};



int main()
{
	int n;
	LinkedList obj;
	while (1) {
		cout << "enter your choice\n1.insertAtBegining\n2.insertAtEnd\n3.SelfAdjust the LinkedList\n4.Display";
		cin >> n;
		switch (n)
		{
		case 1:cout << "enter element to insert\n";
			       cin >> n;
			      obj.insertAtBegining(n);
			      break;
		case 2:cout << "enter element to insert\n";
			  cin >> n;
			  obj.insertAtEnd(n);
			  break;
		case 3:cout << "enter element in linked list to self adjust\n";
			cin >> n;
			obj.selfAdjust(n);
			break;
		case 4:obj.display();
			   break;

		default: return 0;
		}

	}
	return 0;
}