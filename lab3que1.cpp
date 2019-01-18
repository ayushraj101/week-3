/*Implement Doubly Linked List using C++. Make sure the following functions are implemented: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. */


#include <iostream>
using namespace std;

class element
	{
		public:
		int data;
		element * next;
		element * previous;
		element()
		{
			next = NULL;
			previous = NULL;
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
		element * temp2;
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
		 	temp2 = tail;
		 }
		 tail = temp;   
		 tail-> previous = temp2;
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
			temp->previous = current;
			current->next->previous = temp;
			current->next = temp;
		}	
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
		tail-> next = NULL;
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
			temp->next->previous = temp->previous;
			delete temp;			
		}
	}
int linklist :: countitems()
	{
		element*current = head;
		int counter = 1; 
		for (; current->next != NULL;counter++)
		{
			current = current -> next;
		}
		return counter;
	}
void linklist :: display ()
	{
		element * current=head;
		cout<< "Displaing the list list normally : ";
		while( current != NULL)
		{
			cout<< current->data<< " -> ";
			current = current ->next;
		}
		cout<< "NULL"<<endl<< "Now printing just to prove it's a doubbly link list : ";
		current = tail;
		while( current != head)
		{
			cout<< current->data<< " -> ";
			current = current->previous;
		}
		cout<< "NULL";
		cout<<endl;
	}
	
	
int main()
	{
		linklist l1;
		l1.insert(21);
		l1.insert(2);
		l1.insert(3);
		l1.insert(9);
		l1.insert(12);
		l1.insert(7);
		l1.deleteat(2);
		l1.display();
		//l1.insertat(6, 45);
		return 0;
	}
	
