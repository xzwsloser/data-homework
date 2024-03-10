#include "BaseMethod.h"
/**
 *  演示找到倒数第k个节点
 * 
*/
Node* findIndex(Node* head,int index);
int main(){
   // 首先还是建立链表
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
    // 之后就可以完成找倒数第k个节点的逻辑
    int index=0;
    printf("请问你想得到倒数第几个节点:\n");
    scanf("%d",&index);
    // 开始找到倒数的节点
    // 1->2->3->4->5
    Node* res=findIndex(head,index);
    printf("倒数第%d个节点对应的数字为:%d",index,res->data);
    return 0;
}
Node* findIndex(Node* head,int index){
    /**
     *  思路: 还是定义一个快指针,一个慢指针,快比慢多走n+1即可
    */
   Node* fast=head->next;
   Node* slow=head->next;
   for(int i=0;i<index+1;i++){
    fast=fast->next;
   }
   // 继续开始走
   while(fast!=NULL){
    slow=slow->next;
    fast=fast->next;
   }
   return slow->next;

}
