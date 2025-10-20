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
void PrintNodes(node * head){
    node *temp = head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->link;
    }

}

int main(){
    node *head=NULL; 
    InsertAtBegining(1,&head);
    InsertAtBegining(2,&head);
    InsertAtBegining(3,&head);
    InsertAtBegining(4,&head);
    PrintNodes(head);

}