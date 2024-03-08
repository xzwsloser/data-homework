// 找出单链表的中点
// 使用双指针法: fast指针每次 走2个,slow指针每次走1个,fast走到头即可
// 1-2-3-4-5-6-7
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
    insertHead(head,7);
    printf("建立的单链表为:\n");
    displayList(head);
    // 寻找的逻辑
    Node* fast=head->next;
    Node* slow=fast;
    while(fast->next!=NULL&&fast!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
   
    printf("中间节点对应的元素为:%d\n",slow->data);
    return 0;
    
}

    
  