#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	node* prev;
	node(int d)
	{
		this->data = d;
		this->next = NULL;
		this->prev = NULL;
	}
};
class linked{
	public:
		void insert(node* &head,int d)
		{
		
				node* temp = new node(d);
				temp->next = head;
				temp->prev = NULL;
				head->prev = temp;
				head = temp;
			
		}
		void insertend(node* &tail,int d)
		{
				node* temp = new node(d);
				temp->next = NULL;
				temp->prev = tail;
				tail->next = temp;
				tail = temp;
		}
		void position(node* &head,node* &tail,int d, int p)
		{
			linked s;
			node* temp = head;
			int count = 1;
			while(count < p)
			{
				temp = temp->next;
				count ++;
			}
			
			if(p==1)
			{
				s.insert(head,d);
			}
			else if(temp == NULL)
			{
				s.insertend(tail,d);
			}
			else{
				int i = 1;
				node* c = head;
				node* k;
				while(i<p)
				{
					k = c;
					c = c->next;
					i++;
				}
				node* node1 = new node(d);
				node1->next = c;
				node1->prev = k;
				c->prev = node1;
				k->next = node1;
			}
			
		}
		void deleted(node* &head)
		{
				node* current = head;
				head = head->next;
				head->prev = NULL;
				delete current;
			
		}
		void deleteend(node* &tail)
		{
				node* temp  = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
			
		}
		void deleteposition(node* &head,node* &tail, int p)
		{
			linked s;
			node* temp = head;
			int count = 1;
			while(count < p)
			{
				temp = temp->next;
				count ++;
			}
			
			if(p==1)
			{
				s.deleted(head);
			}
			else if(temp == NULL)
			{
				s.deleteend(tail);
			}
			else{
				int i = 1;
				node* c = head;
				node* k;
				while(i<p)
				{
					k = c;
					c = c->next;
					i++;
				}
				
				k->next = c->next;
				c->next->prev = k;
				delete c;
			}
		}
		
		node* dleteduplicat(node* & head)
		{
			
			node* current =  head;
			if(head == NULL)
			{
				return NULL;
			}
			while(current->next != NULL)
			{
				if(current->data == current->next->data)
				{
					node* next_next = current->next->next; 
					node* nodetodelete = current->next;
					delete nodetodelete;
					current->next = next_next;
					next_next->prev = current;
					 
				}
				else{
					current = current->next;
				}
			}
			return head;
		}
	node* reverse(node* 	head)
	{
		node* current = head;
		node* nextnode = current->next;
		current->next = NULL;
		current->prev = nextnode;
		while(nextnode != NULL){
		
			nextnode->prev = nextnode->next;
			nextnode->next = current;
			current = nextnode;
			current = nextnode->prev;
		}
		current = head;
		return head;
	}

		void display(node* &head)
		{
			while(head!= NULL)
			{
				cout << head->data << "  ";
				head=head->next;
			}
		}
};
int main()
{
	node* node1 = new node(10);
	linked s;
	node*  tail = node1;
	node*  head = node1;
	s.insert(head,2);
	s.insert(head,2);
	s.insert(head,1);
	s.insertend(tail,3);
	s.position(head,tail,0,2);
	//s.reverse(head);
	s.deleteposition(head,tail,4);
	s.dleteduplicat(head);
	//s.dleteduplicatunsort(head);
	s.display(head);
}