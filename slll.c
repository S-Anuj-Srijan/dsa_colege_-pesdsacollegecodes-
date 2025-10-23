#include<stdlib.h>
#include<stdio.h>
struct node {
    int data; 
    struct node *link ; 
};
typedef struct node node ; 
node * createnode(int data){
    node* newnode =(node * )malloc(sizeof(node));
    newnode->link=NULL; 
    newnode->data = data;
    return newnode ; 

}
void InsertAtBegining(int data , node ** head){
    node * newnode = createnode(data);
    if(*head == NULL){
        *head = newnode; 
    }
    else {
        newnode->link =*head ; 
        *head = newnode; 
    }
} 
void printlist(node *head){
    while(head!=NULL){
        printf("%d",head->data);
        head=head->link; 

    }
}
void insertatend(int data, node **head){
    node *newnode =createnode(data);
    node *temp =*head ;
    while(temp->link!=NULL){
        temp=temp->link; 
    }    
    temp->link= newnode;
}
void insertatpos(int data ,int pos , node ** head){
    node *newnode=createnode(data); 
    node *temp = *head; 
    for(int i =0;i<pos-1&&temp!=NULL;i++){
        temp = temp->link; 
    }
    if(temp==NULL){
        free(newnode);
    }
    else{
        newnode->link=temp->link; 
        temp->link =newnode; 
    }
}
void deleteatbegining(node ** head){
    node * temp = *head;
    *head = (*head)->link; 
    free(temp);

}
void deleteatend(node ** head){
    node *temp = *head;
    node * tempsecondlast=NULL ; 
    if(*head == NULL){
        return;
    }
    if((*head)->link==NULL){
        *head=NULL;
    }
    while(temp->link!=NULL){
        tempsecondlast=temp;
        temp=temp->link;
    }
    tempsecondlast->link=NULL;
    free(temp);
}
void deleteatpos(int pos , node ** head){
    node *temp = *head ; 
    node *secondlast=NULL;
    if(*head==NULL){
            return;
    }
    if(pos==0){
        deleteatbegining(head);
    }
    for(int i =0 ; i <pos && temp!=NULL;i++){
        secondlast=temp; 
        temp=temp->link; 
    }
    if (temp==NULL){
        return;
    }
    
    secondlast->link=temp->link;
    free(temp);
    return;
    

}

int main(){
    node *head = NULL;
    InsertAtBegining(1, &head);
    insertatend(5, &head);
    insertatpos(2,1,&head);
    insertatpos(3,2,&head);
    insertatpos(4,3,&head);
    printlist(head);
    printf("\n");
    deleteatbegining(&head);
    printlist(head);
    printf("\n");
    deleteatend(&head);
    printlist(head);
    printf("\n");
    deleteatpos(1,&head);
    printlist(head);


}