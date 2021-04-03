#include<iostream>


using namespace std;

struct node{
	int data;
	node* next;
};
node* head = NULL;


void insertNode(int value);
void display();
void deleteNode(int value);
void insert_Biggining(int value);
void delete_Biggining();
void delete_End();
int main(){
	insertNode(45);
	insertNode(55);
	insertNode(65);
	display();
	delete_End();
	//delete_Biggining();
	//delete_End();
	display();
}

void insertNode(int value){
	node* new_node,*last;
	new_node=new node;
	new_node->data=value;
	
	if(head == NULL){
		head=new_node;
		new_node->next=	NULL;
	}
	else{
		//node *last;
		last=head;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=new_node;
		new_node->next=NULL;
		
	}
}

void display(){
	node* current_node;
	if(head==NULL)
		cout<<"the Linked List Is Empty!!\n";
	else{
		current_node=head;
		while(current_node!=NULL){
			cout<<current_node->data<<"\t";
			current_node=current_node->next;
		}
	}
	cout<<endl;
}

void deleteNode(int value){
	node* previous,*current;
	previous=head;
	current=head;
	if(current->data==value){
		head=current->next;
		delete current;
		return;
	//	free(current);
	}
	while(current->data!=value){
		previous=current;
		current=current->next;
	}
	previous->next=current->next;
	delete current;
//	free(current);
}

void insert_Biggining(int value){
	node *new_node=new node;
	new_node->data=value;
	new_node->next=head;
	head=new_node;
}
void delete_Biggining(){
	if(head==NULL){
		cout<<"the Linked List is Empty!!\n";
	}
	else{
		node* first_node=head;
		head=first_node->next;
		delete(first_node);
	}
}

void delete_End(){
	if(head==NULL){
		cout<<"Linked List is Empty!!\n";
	}
	else if(head->next==NULL){
		delete(head);
		head=NULL;
		
	}else{
		node* PTR=head;
		while(PTR->next->next!=NULL){
			PTR=PTR->next;
		}
		delete(PTR->next);
		PTR->next=NULL;
		
	}
}

















