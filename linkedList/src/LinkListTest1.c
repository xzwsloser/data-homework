// 逆转单链表
#include "BaseMethod.h"
int main(){
    // 建立链表插入节点
    Node* head=createHead();
    insertHead(head,1);
    insertHead(head,2);
    insertHead(head,3);
    insertHead(head,4);
    insertHead(head,5);
    insertHead(head,6);
    printf("建立的单链表为:\n");
    displayList(head);
    reverseList(head);
    printf("逆转之后的链表为:\n");
    displayList(head);
    return 0;
}
void reverseList(Node* head){
    // 开始逆转链表
    Node* pre=head->next;
    Node* cur=pre->next;
    pre->next=NULL;
    while(cur!=NULL){
        Node* temp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=temp;
    }
    // 最后就可以直接作为头节点
    head->next=pre;

}