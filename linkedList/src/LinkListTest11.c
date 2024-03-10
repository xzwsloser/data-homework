#include "BaseMethod.h"
/**
 * 判断单链表是否对称
*/
// 1->2->3->3->2->1 
int ifSymmetry(Node* head,int len);
int main(){
    Node* head=createHead();
    printf("请输入单链表中元素个数:\n");
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        printf("请输入链表中第%d个元素:  ",(i+1));
        int val;
        scanf("%d",&val);
        insertHead(head,val);
        printf("\n");
    }
    printf("你创建的单链表为:\n");
    displayList(head);
    int res=ifSymmetry(head,len);
    if(res==1){
        printf("链表对称\n");
    }
    else{
        printf("链表不对称\n");
    }
    return 0;
}
int ifSymmetry(Node* head,int len){
    // 拷贝链表,反转链表并且进行链表的保存
    // 首先可以把原来链表中的数据装入到一个数组中
    int arr[len];
    Node* pstr=head->next;
    int index=0;
    while(pstr!=NULL){
        arr[index++]=pstr->data;
        pstr=pstr->next;
    }
    // 之后就是链表的反转操作了
    Node* pre=head->next;
    Node* cur=pre->next;
    pre->next=NULL;
    while(cur!=NULL){
        Node* temp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=temp;
    }
    head->next=pre;  // 尾巴节点
    int newIndex=0;
    Node* prun=head->next;
    while(prun!=NULL){
        if(arr[newIndex]!=prun->data){
            return 0;
        }
        prun=prun->next;
        newIndex++;
    }
    return 1;



}