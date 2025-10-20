#include<stdlib.h>
#include<stdio.h>
struct SllNode{
    int data;
    struct SllNode *link;
};
typedef struct SllNode node; 

node *CreatNode(int data){
    node * newnode = (node * )malloc(sizeof(node));
    newnode->data=data ;
    newnode->link=NULL ; 
    return newnode ; 
}
void InsertAtBegining(int data , node **head){
    node *newnode=CreatNode(data);
    if(*head == NULL){
        *head = newnode; 
    }
    else{
        newnode->link = *head ;
        *head= newnode;
    }

}
void InsertAtEnd(int data , node ** head ){
    node *temp = *head; 
    node * newnode = CreatNode(data);
    while(temp->link!=NULL){
        temp=temp->link; 
    }
    temp->link=newnode;

}
void PrintNodes(node * head){
    node *temp = head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->link;
    }

}

void InsertAtPos(int data , int pos , node **head){
    node *temp = *head;
    node *newnode=CreatNode(data);
    for(int i = 0 ; i<=pos && temp!= NULL ;i++){
        temp=temp->link;
    }
    if (temp==NULL){
        free(newnode);
        printf("wrong pos val");
    }
    else {
        newnode->link=temp->link;
        temp->link=newnode;
    }
}
int main(){
    node *head=NULL; 
    InsertAtBegining(1,&head);
    InsertAtBegining(2,&head);
    InsertAtBegining(3,&head);
    InsertAtBegining(4,&head);
    InsertAtEnd(5,&head);
    InsertAtPos(32,0,&head);
    PrintNodes(head);

}