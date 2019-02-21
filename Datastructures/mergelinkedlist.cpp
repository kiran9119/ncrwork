using namespace std;
#include<iostream>
struct node
{
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
	friend void merge(LinkedList a, LinkedList b);
	friend void sort(LinkedList a);
};

void sort(LinkedList a)
{
	struct node * temp, *temp2;
	temp = a.start;
	while (temp->next!= NULL)
	{
		temp2 = temp->next;
		int min = 10000;
		while (temp2!= NULL)
		{
			if (temp2->data < min)
				min = temp2->data;
			temp2 = temp2->next;
		}
		//cout << min << endl;
		if (temp->data > min)
		{
			struct node *temp3;
			int swap_value = temp->data;
			temp->data = min;
			temp3 = temp->next;
			while (temp3->data != min)
				temp3 = temp3->next;
			temp3->data = swap_value;
		}


		temp = temp->next;
	}
}

void merge(LinkedList a, LinkedList b)
{
	struct node * temp;
	temp = a.start;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = b.start;
	sort(a);

}



int main()
{
	LinkedList obj, obj1;
	while (1) {
		cout << "1.insert at begining\n2.insert at end\n3.display \n4.merge\n";
		int n;
		cin >> n;
		switch (n)
		{
		case 1:cout << "enter element to insert into linked list1\n";
			cin >> n;
			obj.insertAtBegining(n);
			cout << "enter element to insert into linked list2\n";
			cin >> n;
			obj1.insertAtBegining(n);
			break;

		case 2:cout << "enter element to insert into linked list1\n";
			cin >> n;
			obj.insertAtEnd(n);
			cout << "enter element to insert into linked list2\n";
			cin >> n;
			obj1.insertAtEnd(n);
			break;
		case 3:obj.display();
			//j1.display();
			break;

		case 4:merge(obj, obj1);
			break;
		default:return 0;
		}
	}
	return 0;
}