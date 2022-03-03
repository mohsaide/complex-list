#include <iostream>
#include <string>
using namespace std; 
class node {
private: 
	string Data;  
	node* Next;
	node* Prev; 
	node* Head; 
	node* Tail;
	friend class LIST;  
public: 
	node()
	{
		Next = Prev = Head = Tail = nullptr; 
		Data = "empty"; 
	}
};

class LIST 
{
private :
	node* head;   // pointer that point to first node in the list  .  . . . .
	int no; // number of the nodes in the list . . . .  

public: 
	//constructor 
	LIST()
	{
		head = NULL; 
		no = 0; 
	}

	// help method ( empty ) 
	bool empty()
	{
		if (!head)
			return true;
		else
			return false;

	}

	// help method ( tail )  

	node* get_tail()
	{
		if (empty())
		{
			return NULL; 
		}
		else
		{

			node* ptr = head; 
			while (ptr->Next)
			{
				ptr = ptr->Next;  
			}
			return ptr;  
		}

	}

	// add node in the front of the list 

	void add_front(string &e)
	{
		// prepare the node before add it in the list  
		node* NEW_NODE = new node;  
		NEW_NODE->Data = e;  
		
		if (empty())
		{
			head = NEW_NODE;  
			NEW_NODE->Head = head;  
			NEW_NODE->Tail = get_tail(); 
			NEW_NODE->Next = head; 
			NEW_NODE->Prev = head;
		}
		else
		{
			NEW_NODE->Prev = get_tail();
			NEW_NODE->Next = head; 
			head = NEW_NODE; 
			NEW_NODE->Head = NEW_NODE;  
			NEW_NODE->Tail = get_tail(); 
		}

		no++;  
	}

	// add node in the back of the list 

	void add_back(string& e)
	{
		// prepare the node before add it in the list  
		node* NEW_NODE = new node;
		NEW_NODE->Data = e;

		if (empty())
		{
			head = NEW_NODE;
			NEW_NODE->Head = head;
			NEW_NODE->Tail = get_tail();
			NEW_NODE->Next = head;
			NEW_NODE->Prev = head;
		}
		else
		{
			NEW_NODE->Prev = get_tail();  
			get_tail()->Next = NEW_NODE; 
			NEW_NODE->Next = head;  
			NEW_NODE->Tail = NEW_NODE;  
			NEW_NODE->Next = head; 
		}
		no++;
	}

	// get  first data in the list 

	string get_front()
	{

		if (empty())
		{
			return "The list is empty";  
		}

		else
		{
			return head->Data;
		}
	}

	// get last data in the list 

	string get_back()
	{

		if (empty())
		{
			return "The list is empty";
		}

		else
		{
			return get_tail()->Data;
		}
	}

	// to display the data on console

	void normal_print()
	{
		if (empty())
		{
			cout << "Oops , list is empty . . . \n"; 
		}
		else
		{

			node* ptr = head;  
			do
			{
				cout << ptr->Data << "\t"; 
				ptr = ptr->Next; 

			}
			while (ptr != head); 

			cout << endl; 
		}
	}

	// to display the data on console in reverse 

	void reverse_print()
	{
		if (empty())
		{
			cout << "Oops , list is empty . . . \n";
		}
		else
		{

			node* ptr = get_tail();
			do
			{
				cout << ptr->Data << "\t";
				ptr = ptr->Prev;

			} while (ptr != get_tail());

			cout << endl;
		}
	}

    // delete the  first node in the list 

	void remove_front()
	{
		if (empty())
		{
			return; 
		}
		else if (no == 1)
		{
			delete head;  
			no--; 
		}
		else
		{
			node* ptr = head->Next;
			
			ptr->Next->Prev = head;
			head->Next = ptr->Next; 

			delete ptr; 
			no--;  
		}

	}

	// delete  the last node in the list 

	void remove_back()
	{
		
			if (empty())
			{
				return;
			}
			else if (no == 1)
			{
				delete head;
				no--;
			}
			else
			{
				node* ptr = get_tail();  

				ptr->Prev->Next = head;
				head->Prev = ptr->Prev;

				delete ptr;
				no--;
			}

		
	}
	// destructor 

 
};



int main()
{
	LIST L;
   // cheack it here 

	system("pause");
	return 0;  
}