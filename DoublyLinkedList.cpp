/*
  Author:
  Ashutosh Kumar
  @an_shuman777
  DOUBLY LINKED LIST IMPLEMENTATION
*/

#include<bits/stdc++.h>
using namespace std;

//Doubly Linked List Node
struct DllNode{
    struct DllNode *pre;
    int data;
    struct DllNode *next;
};

//Note that here we have to handle the first case separately unlike the Single Linked List
struct DllNode *addtoempty(struct DllNode *start,int item){
    struct DllNode *tmp;
    tmp = (struct DllNode*)malloc(sizeof(struct DllNode));
    tmp->data = item;
    tmp->pre = NULL;
    tmp ->next = NULL;
    start = tmp;
    return start;
}

//adding value to the beginning of the list
struct DllNode *addtobeg(struct DllNode *start,int item){
    struct DllNode *tmp;
    tmp = (struct DllNode*)malloc(sizeof(struct DllNode));
    tmp->data = item;
    tmp->next = start;
    start->pre = tmp;
    start = tmp;
    return start;
}

//add Node at a particular position given the data to that position
struct DllNode *addAfterParticularNode(struct DllNode *start ,int perNodeData, int item){
    struct DllNode *tmp = start;
    struct DllNode *tmp1;
    tmp1 = (struct DllNode*)malloc(sizeof(struct DllNode));
    tmp1->data = item;
    while(tmp != NULL){
        if(tmp->data == perNodeData){
            tmp1->pre = tmp;
            tmp1->next = tmp->next;
            if(tmp->next != NULL){
                tmp->next->pre = tmp1;
            }
            tmp->next=tmp1;
            return start;
        }
        tmp=tmp->next;
    }
    cout<<"Given Node does not exist in the list "<<endl;
}

//adding Node to the end of the list
struct DllNode *addtoend(struct DllNode *start,int item){
    struct DllNode *tmp;
    tmp = (struct DllNode*)malloc(sizeof(struct DllNode));
    tmp->data = item;
    struct DllNode *ptr=start;
    while(ptr->next != NULL){
        ptr=ptr->next;
        }
    tmp->next = NULL;
    ptr->next = tmp;
    tmp->pre = ptr;
    return start;
}

//Doubly Linked list traversal
void DLLtraversal(struct DllNode *ptr){
    while(ptr != NULL ){
        cout<< ptr->data << " ";
        ptr = ptr->next;
    }
}

//Driver Function
int main(){
    struct DllNode *start = NULL;
    start = addtoempty(start,4);
    start = addtoend(start,21);
    start = addtoend(start,14);
    start = addtoend(start,20);
    start = addtoend(start,12);
    start = addtobeg(start,50);
    start = addAfterParticularNode(start,14,11);
    DLLtraversal(start);
    /* 50 4 21 14 11 20 12 */
    return 0;
}
