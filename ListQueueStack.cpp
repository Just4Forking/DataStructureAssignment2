#include "DetectMemoryLeak.h"
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    Terence Tan Ming Jie
 *  \date      2016
 *  \note      151131H
 */

//*******************************************************************//
// Linked list stuff
//*******************************************************************//
LinkedList::LinkedList()
{
	head = 0;
}

LinkedList::~LinkedList()
{

}

void LinkedList::push_front(int data)
{
	Node* temp = new Node(data);
	

	if (head == 0)
	{
		head = temp;
	}
	else
	{
		Node* curr = head;
		temp->next = curr;
		head = temp;
	}
 
}

void LinkedList::push_back(int data)
{
	Node* temp = new Node(data);
	Node* curr = head;
	if (head == 0)
	{
		head = temp;
	}
	else
	{
		for (; curr->next != 0; curr = curr->next) {}
		curr->next = temp;
	}
}

int LinkedList::pop_front()
{
	if (head == 0)
	{
		return 0;
	}
	else
	{
		int temp = 0;
		Node* curr = head;
		head = curr->next;
		temp = curr->data;
		delete curr;
		return temp;
	}
}

int LinkedList::pop_back()
{
	if (head == 0)
	{
		return 0;
	}
	else if (head->next == 0)
	{
		return pop_front();
	}
	else
	{
		Node* curr = head->next;
		Node* prev = head;
		int temp = 0;
		while (curr ->next != 0)
		{
			prev = curr;
			curr = curr->next;
		}
		temp = curr->data;
		delete curr;
		prev->next = 0;
		return temp;
	}
}

void LinkedList::insert_at(int pos, int data)
{
	Node* temp = new Node(data);
	Node* prev = 0;
	Node* curr = head;
	if (pos <= 0)
	{
		push_front(data);
	}
	else if (pos >= (int)size())
	{
		push_back(data);
	}
	else
	{
		int i = 0;
		while (i < pos)
		{
			prev = curr;
			curr = curr->next;
			i++;
		}
		temp->next = curr;
		prev->next = temp;
	}
}

int LinkedList::pop_at(int pos)
{
	Node* curr = head;
	Node* prev = head;
	if (pos <= 0)
	{
		return pop_front();
	}
	else if (pos >= (int)size())
	{
		return 0;
	}
	curr = curr->next;
	int temp = 0;
	int i = 1;
	while (i < pos)
	{
		prev = curr;
		curr = curr->next;
		i++;
	}
	prev->next = curr->next;
	temp = curr->data;
	delete curr;
    return temp;
}

size_t LinkedList::size()
{
	Node* curr = head;
	if (head == 0)
	{
		return 0;
	}
	else
	{
		int size = 1;
		for (;curr->next != 0; curr = curr->next)
		{
			size += 1;
		}
		return size;
	}
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue()
{
	front = 0;
	back = front;
}

Queue::~Queue()
{

}

void Queue::enqueue(int data)
{
	Node* temp = new Node(data);

	if (front == 0)
	{
		front = temp;
	}
	else
	{
		temp->next = 0;
		back->next = temp;
	}
	back = temp;
}

int Queue::dequeue()
{
	
	if (front == 0)
	{
		back = 0;
		return 0;
	}
	else if (front->next == 0)
	{
		int temp = 0;
		Node* curr = front;
		temp = curr->data;
		front = 0;
		back = 0;
		delete curr;
		return temp;
	}
	else
	{
		int temp = 0;
		Node* curr = front;
		temp = front->data;
		front = front->next;
		delete curr;
		return temp;
	}
}

size_t Queue::size()
{
	Node* curr = front;
	int size = 0;
	if (front == 0)
	{
		return 0;
	}
	else
	{
		while (curr != 0)
		{
			size++;
			curr = curr->next;
		}
		return size;
	}
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{
	top = nullptr;
}

Stack::~Stack()
{
}

void Stack::push(int data)
{
	Node* temp = new Node(data);
	if (top != 0)
	{
		temp->next = top;
		top = temp;
	}
	else
	{
		temp->next = 0;
		top = temp;
	}
} 

int Stack::pop()
{
	int temp = 0;
	if (top == 0)
	{
		return 0;
	}
	else
	{
		Node* curr = top;
		temp = top->data;
		top = top->next;
		delete curr;
		return temp;
	}
}

size_t Stack::size()
{
	Node* curr = top;
	if (top == 0)
	{
		return 0;
	}
	else
	{
		int size = 1;
		while (curr->next != 0)
		{
			size++;
			curr = curr->next;
		}
		return size;
	}
} 

