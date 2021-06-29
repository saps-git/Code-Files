#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next;
};

node* createNode(int x){
	node* temp = new node;
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void printNode(node* ptr){
	while(ptr){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

node* mergeList(node* l1, node* l2){
	node* p1 = l1;
    node* p2 = l2;
    
    node* dummy = new node; //taking sentianl head (dummy node for head)
    node* p3 = dummy; 
    
    while(p1 && p2){
        if(p1->data < p2->data){ //comparing both the LLs for the smaller node and adding it to the next of p3
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    
    while(p1){
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    
     while(p2){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    
    return dummy->next;
}

int main(){
	node* head1 = new node;
	head1->data = 0;
	head1->next = createNode(1);
	head1->next->next = createNode(2);
	head1->next->next->next = createNode(4);

	node* head2 = new node;
	head2->data = 0;
	head2->next = createNode(1);
	head2->next->next = createNode(3);
	head2->next->next->next = createNode(4);

	node* ans = mergeList(head1->next, head2->next);
	printNode(ans);
}