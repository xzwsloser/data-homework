#include "BaseMethod.h"
// 演示无保留的删除重复元素
/**
 * 思路: 还是快慢指针法,快指针找到单一元素,slow指向单一元素
 * 
*/
int main(){
    // 建立链表
    Node* head=getHeadByParameters(12,1,1,2,3,3,4,5,5,6,7,7,9);
    printf("删除元素之前链表为:\n");
    displayList(head);
    deleteAllSameElem(head);
    printf("删除之后链表为:\n");
    displayList(head);

}
void deleteAllSameElem(Node* head){
  // 这里还是采用快慢指针法
  
  Node* slow=head;
  Node* pre=head->next;
  Node* fast=pre->next;
  // 判断头部
  if(pre->data!=fast->data){
    slow->next->data=pre->data;
    slow=slow->next;

  }
  while(fast->next!=NULL){
    // 不是尾巴节点
    if(fast->next->data!=fast->data&&pre->data!=fast->data){
        slow->next->data=fast->data;
        slow=slow->next;
    }
    fast=fast->next;
    pre=pre->next;
  }
  // 判断尾部
  if(fast->data!=pre->data){
    slow->next=fast;
    slow->next=NULL;
  }
  slow->next=NULL;
  
}