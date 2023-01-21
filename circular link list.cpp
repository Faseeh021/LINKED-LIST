#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	node(int d){
		this->data = d;
		this->next = NULL;
	}
};

class linked{
	public:
	void insert(node* &head,int d)
	{
		if(head == NULL){
		
			node* newnode = new node(d);
			head = newnode;
			newnode->next = head; 
		}
		else{
			node* temp = new node(d);
			node* current = head;
			while(current->next!= head)
			{
				current = current->next;
			}
			temp->next = head;
			head = temp;
			current->next = temp;
			
			
		}
	}
	void insertatposition(node* &head,int d,int p)
	{
		node* newnode = new node(d);
		if(head == NULL)
		{
			
			head = newnode;
			newnode->next = head;
		}
		else if(p == 1)
		{
			node* current = head;
			while(current->next!=head)
			{
         current = current->next;
			}
			newnode->next = head;
			head = newnode;
			current->next = head;
		}
		else{
			node* current = head;
			node* prev;
			int i = 1;
			while(i < p)
			{
				prev = current;
				current = current->next;
				i++;
			}
			prev->next = newnode;
			newnode->next = current;
		}
	}

	void reverse(node* head)
	{
		if(head == NULL)
		{
			return ;
		}
		node* current,*prev,*nextnode;
		current = head;
		nextnode = current->next;
		while(current->next!= head)
		{
			prev = current;
			current = nextnode;
			nextnode = current->next;
			current->next = prev;
		}
			nextnode->next = current->next;
			head = nextnode; 
		
	}
	
	
	void display(node* &head){
		node* ptr = head;
		do
		{
			cout << ptr->data << "  ";
			ptr = ptr->next;
		}while(ptr!= head);
		cout << endl;
	}
	
	node* dleteduplicate(node* &head)
	{
		if(head == NULL)
		{
			return NULL;
		}
		else{
		
			node* current = head;
			while(current->next != head)
			{
				if(current->data == current->next->data)
				{
					node* next_next = current->next->next;
					node* nodetodelete = current->next;
					delete nodetodelete;
					current->next = next_next;
				}
				else{
					current = current->next;
				}
			}
			return head;
		}
	}

	
	void sort(node* &head)
	{
		int num;
		node* current = head;
		node* temp;
		while(current->next != head)
		{
			temp = current->next;
			while(temp != head)
			{
				if(current->data >= temp->data)
				{
					num = current->data;
					current->data = temp->data;
					temp->data = num;
				}
				temp = temp->next;
			}
			current = current->next;
		}
	}
};

int main()
{
	linked s;
	node* head1 = NULL;
	s.insert(head1,2);
	s.insert(head1,3);
	s.insert(head1,1);
	s.insertatposition(head1,2,4);
	s.display(head1);
	s.sort(head1);
	s.display(head1);
	s.dleteduplicate(head1);
	
	//s.display(head1);
	
	s.display(head1);
	
}