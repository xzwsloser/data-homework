#include "BaseMethod.h"
/**
 * 对于有序单链表,删除重复节点(这里就默认为升序)
 * 思路: 还是双指针法,定义快慢指针,最后慢指针之后的置为空即可
*/
void deleteSameElem(Node* head);
int main(){
// 链表的创建
    Node* head=getHeadByParameters(12,9,8,8,8,7,7,4,4,3,3,3,1);
    printf("原来的链表为:\n");
    displayList(head);
    // 之后就是核心代码逻辑的执行
    deleteSameElem(head);
    printf("删除重复元素之后的链表为:\n");
    displayList(head);
    return 0;

}
void deleteSameElem(Node* head){
    // 定义一个快指针,遍历元素
    Node* fast=head->next;
    // 定义一个慢指针,指向元素下标
    Node* slow=head->next;
    while(fast!=NULL){
        if(fast->data!=slow->data){
            slow->next->data=fast->data;
            slow=slow->next;
        }
        fast=fast->next;
    }
    slow->next=NULL;  
    // 之后slow之后的都置为空即可
    
}
