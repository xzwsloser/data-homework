#include "BaseMethod.h"
Node* ifCircleInList(Node* head);
Node* createListWithCircle(int index);
Node* creatListWithoutCircle();
int main(){
    // 判断单链表是否有环
    // 链表的建立
    Node* head=(Node*)malloc(sizeof(Node));
    printf("请问是否要建立有环的链表(1代表是,0代表否):\n");
    int choice=-1;
    scanf("%d",&choice);
    if(choice==1){
        printf("请输入环的入口位置:\n");
        int index=-1;
        scanf("%d",&index);
       head=createListWithCircle(index);
    } else{
       head=creatListWithoutCircle();
    }
    // 题目的核心逻辑
    // 判断是否有环
    Node* res=ifCircleInList(head);
    if(res==NULL){ 
        printf("链表中没有环\n");
    } else{
        printf("链表中有环,并且环的入环点为: %d\n",res->data);
    }
    return 0;

}
// 定义一个环化单链表的函数
Node* createListWithCircle(int index){
    
    // 首先建立一个单链表
    Node* head=createHead();
    // 头插法
    insertHead(head,1);
    insertHead(head,2);
    insertHead(head,3);
    insertHead(head,4);
    insertHead(head,5);
    insertHead(head,6);
    insertHead(head,7);
    insertHead(head,8);
    insertHead(head,9);
    // 开始环化单链表
    Node* temp=head->next;
    for(int i=0;i<index;i++){
        temp=temp->next;
    }
    // 找到尾巴节点
    Node* pend=head->next;
    while(pend->next!=NULL){
       pend=pend->next; 
    }
    pend->next=temp; // 环化完成
    // 打印一下链表
    printf("生成的链表为:\n");
    Node* prun=head->next;
    while(prun!=pend){
        printf(prun==head->next?"%d":"->%d",prun->data);
        prun=prun->next;
    }
    return head; 
    
}



// 定义一个非环化单链表的函数
Node* creatListWithoutCircle(){
    Node* head=createHead();
    insertHead(head,1);
    insertHead(head,2);
    insertHead(head,3);
    insertHead(head,4);
    insertHead(head,5);
    insertHead(head,6);
    insertHead(head,7);
    insertHead(head,8);
    insertHead(head,9);
    printf("生成的链表为:\n");
    displayList(head);
    return head;
}
Node* ifCircleInList(Node* head){
    /**
     *  思路: 还是定义两个指针快指针每一次走2,慢指针每一次走1
     *  相遇点再顶一个指针,和头节点的指针一起走,相遇点就是入环点
    */
   Node* fast=head->next;
   Node* slow=head->next;
   while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            // 开始执行逻辑
            Node* index1=head->next;
            Node* index2=fast;
            while(index1!=index2){
                index1=index1->next;
                index2=index2->next;
            }
            return index2;
        }
   }
   return NULL;
}
