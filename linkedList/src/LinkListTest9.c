#include "BaseMethod.h"
/**
 * 要求: 合并两个升序单链表
 *  假设要合并的单链表为
 * A: 1->3->3->5->6->6->7->9->10
 * B: 1->2->2->4->6->7->11->12
*/
// 升序合并
Node* createListA();
Node* createListB();
int main(){
    // 创建链表
    Node* pa=createListA();
    Node* pb=createListB();
    // 开始合并
    Node* p1=pa->next;
    Node* p2=pb->next;
    
    while(p1->next!=NULL&&p2!=NULL){
        if((p1->data<=p2->data)&&(p1->next->data>=p2->data)){
            // 开始插入
            Node* temp=(Node*)malloc(sizeof(Node));
            temp->data=p2->data;
            temp->next=p1->next;
            p1->next=temp;
            p2=p2->next; 
        }
            p1=p1->next;
        
    }
    if(p2!=NULL){
        p1->next=p2;
    }
    printf("合并之后的链表为:\n");
    displayList(pa);
    return 0;
}
Node* createListA(){
    Node* pa=createHead();
    insertHead(pa,10);
    insertHead(pa,9);
    insertHead(pa,9);
    insertHead(pa,7);
    insertHead(pa,6);
    insertHead(pa,6);
    insertHead(pa,3);
    insertHead(pa,3);
    insertHead(pa,1);
    return pa;
}
Node* createListB(){
    Node* pb=createHead();
    insertHead(pb,12);
    insertHead(pb,11);
    insertHead(pb,7);
    insertHead(pb,6);
    insertHead(pb,4);
    insertHead(pb,2);
    insertHead(pb,2);
    insertHead(pb,1);
    return pb;
}
