#include "BaseMethod.h"
// 建立头节点
Node*  createHead(){
    Node*  head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL; // head就是虚拟头节点
    return head;
}
// 插入元素的操作
// 头插法
void insertHead(Node* head,int elem){
    Node* pnew=(Node*)malloc(sizeof(Node));
    pnew->data=elem;
    pnew->next=head->next;
    head->next=pnew; // 就是插入头节点
}
// 展示链表
void displayList(Node* head){
    Node* pstr=head->next;
    while(pstr!=NULL){
        printf(pstr==head->next?"%d":"->%d",pstr->data);
        pstr=pstr->next;
    }
    printf("\n");
}