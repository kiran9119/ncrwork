using namespace std;
#include<iostream>
struct node
{
	int coefficient;
	int power;
	struct node * next;
};

class PolynomialAddittion
{
	struct node *start;

public:
	PolynomialAddittion()
	{
		start = NULL;
	}


	void insert()
	{
		int coefficient, power;
		cout << "enter coefficient and power";
		cin >> coefficient >> power;
		
		if (start == NULL)
		{
			struct node *nn = new node;
			nn->coefficient =coefficient;
			nn->power = power;
			nn->next = NULL;
			start = nn;
		}
		else
		{
			struct node *nn = new node;
			struct node* temp;
			nn->coefficient = coefficient;
			nn->power = power;
			nn->next = NULL;
			temp = start;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = nn;
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
			cout << temp->coefficient<<","<<temp->power << "->";
			temp = temp->next;
		}
		cout << temp->coefficient <<","<<temp->power<< "\n";
	}

	friend void AddLinkedLists(PolynomialAddittion a,PolynomialAddittion b);
};

void AddLinkedLists(PolynomialAddittion a, PolynomialAddittion b)
{
	struct node *temp, *temp2;
	temp = a.start;
	temp2 = b.start;
	while (temp != NULL && temp2!=NULL)
	{
		if (temp->power > temp2->power)
		{
			temp = temp->next;
			continue;
		}

		

		if (temp->power == temp2->power) {
			temp->coefficient = temp->coefficient + temp2->coefficient;
			temp = temp->next;
			temp2 = temp2->next;
		}
		
	}

	if (temp2 != NULL)
	{
		while (temp2 != NULL)
		{
			temp->next = temp2;
			temp2 = temp2->next;
			temp = temp->next;
		}
	}



}
int main()
{
	int choice;
	PolynomialAddittion linkedlist1, linkedlist2;
	while (true){
		cout << "Enter your choice\n1.Insert\n2.Add\n3.Display";
	cin >> choice;
	switch (choice)
	{

	case 1:linkedlist1.insert();
		linkedlist2.insert();
		break;
	case 2:AddLinkedLists(linkedlist1, linkedlist1);
		break;
	case 3:linkedlist1.display();
		break;
	default:return 0;
	}
}
		return 0;
}
