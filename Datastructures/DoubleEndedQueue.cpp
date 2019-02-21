using namespace std;
#include<iostream>

struct DQueue
{
	int front;
	int rear;
	int size;
	int *s;
};

class DoubleEndedQueue
{
	struct DQueue queue;

public:
	DoubleEndedQueue()
	{
		queue.front = queue.rear = -1;
		queue.size = 0;
	}

	void setSize(int n)
	{
		queue.size = n;
		queue.s = new int[queue.size];
	}

	void InsertAtBegining(int n)
	{
		if (queue.front == 0)
		{
			cout << "The starting index is not empty\n";
			return;
		}

		if (queue.front == -1)
		{
			queue.s[++queue.front] = n;
			++queue.rear;
		}

		else
		{
			queue.s[--queue.front] = n;
		}
	}

	void InsertAtEnd(int n)
	{
		if (queue.rear == queue.size - 1)
			cout << "Index at end is not empty....can't insert\n";
		else
			queue.s[++queue.rear] = n;
	}

	void DeleteAtBegining()
	{
		if (queue.front == -1)
			cout << "There is no element to delete\n";
		else
			if (queue.front != queue.rear) {
				++queue.front;
				cout << "Delete successful\n";
			}
			else
			{
				queue.front = -1;
				queue.rear = -1;
				cout << "Delete successful\n";
			}

	}

	void deleteAtEnd()
	{
		if (queue.rear = -1)
			cout << "No element to delete\n";
		else
			if (queue.front == queue.rear)
			{
				queue.front = -1;
				queue.rear = -1;
				cout << "delete successful\n";
			}

			else {
				--queue.rear;
				cout << "delete successful\n";
			}
	}


	void display()
	{
		for (int i = queue.front; i <= queue.rear; i++)
			cout << queue.s[i] << " ";
	}
};

int main()
{
	int n;
	DoubleEndedQueue q;
	cout << "Enter the size of the double ended queue\n";
	cin >> n;
	q.setSize(n);
	while (1)
	{
		cout << "enter your choice\n1.insert at begining\n2.insert at end\n3.delete at begining\n4.delete at end\n5.display";
		cin >> n;
		switch (n)
		{
		case 1:cout << "enter element to insert"; cin >> n;
			   q.InsertAtBegining(n);
			   break;
		case 2:cout << "enter element to insert"; cin >> n;
			   q.InsertAtEnd(n);
			   break;
		case 3:q.DeleteAtBegining();
			   break;
		case 4:q.deleteAtEnd();
			   break;
		case 5:q.display();
			break;
		default: return 0;
		}
	}
	return 0;
}