/*Implement Singly Linked List using C++. Make sure the following functions: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4.*/


#include <iostream>
using namespace std;

class element
	{
		public:
		int data;
		element * next;
		element()
		{
			next = NULL;
		}
	};
	
class linklist
	{
		public:
		element * head;
		element * tail;
		
		linklist()
		{	
			head=NULL;
			tail=NULL;
		}
		
	void insert(int value);
	void insertat(int posi, int value );
	void delet();
	void deleteat(int posi);
	int countitems();
	void display();
	};
	
void linklist:: insert(int value )
	{
		// If 1st Node is added
		element * temp = new element;
		// Insert value in the node
		temp->data = value;
		// 1st Node only
		if (head == NULL)
		{
			head = temp;
		}
		// Any other Node only.
		 else 
		 {
		 	tail->next = temp;
		 }
		 tail = temp;
		 tail->next = head;
	};
void linklist:: insertat(int posi, int value )
	{
		if(countitems()>posi)
		cout<< "Linked List does not have that many elements"<<endl;
		else 
		{
			element * current = head;
			for (int counter=2; counter< posi; counter++  )
			{
				current = current -> next ; 
			}
			element * temp = new element;
			temp->data = value;
			temp->next = current->next;
			current->next = temp;
		}
		tail->next = head;	
	}
void linklist:: delet ()
	{
		element * temp = tail;
		element* current = head;
		while(current->next!= tail)
		{
			current = current -> next;
		}
		delete temp;
		tail = current;
		tail-> next = head;
	}
void linklist:: deleteat(int posi)
	{
		if(countitems() < posi)
		cout<< "Linked List does not have that many elements"<<endl;
		
		else 
		{
			element * current = head;
			for(int counter = 2; counter< posi; counter++ )
			{
				current = current-> next;
			}
			element * temp;
			temp = current->next;
			current->next = temp->next;
			delete temp;
			tail->next = head;
		}
	}
int linklist :: countitems()
	{
		element*current = head;
		int counter = 1; 
		for (; current->next != head;counter++)
		{
			current = current -> next;
		}
		return counter;
	}
void linklist :: display ()
	{
		element * current=head;
		cout<< "printing same as the normal linklist : ";
		while( current->next != head)
		{
			cout<< current->data<< " -> ";
			current = current->next;
		}
		cout << tail->data<< " -> ";
		cout<< "NULL";
		cout<<endl;
		current=head;
		cout<<"checking for the presence of circular linklist (printing 2 rounds) : ";
		int counter = 0;
		while( counter != 2)
		{
			cout<< current->data<< " -> ";
			current = current ->next;
			if (current == head)
				{counter++;}	
		}
		cout<< "NULL "<<endl;
	}



 
	

	
	
int main()
	{
		linklist l1;
		l1.insert(21);
		l1.insert(2);
		l1.insert(3);
		l1.insert(5);
		l1.insert(9);
		l1.insert(76);
		l1.insert(5);
		l1.insert(9);
		l1.deleteat(2);
		l1.display();
		//l1.insertat(6, 45);
		return 0;
	}
	
