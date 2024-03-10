#include "BaseMethod.h"

Node* getHead(int firstNum,...);
int getLength(Node* head);
Node* isCombined(Node* pstr1,Node* pstr2);
// 判断链表是否相交
    /**
     *  首先要明确链表相交的含义
     *   链表相交: 链表1: 1->2->3->4->5  链表2: 10->9->3->4->5  
    */
   // 可以首先找到链表的尾节点,之后往前面比较
    // 思路1: 首先可以求解路径插,之后就可以让长的一个链表的指针前移插值倍
    // 首先构造链表
int main(){
    // 首先还是构造链表
    Node* head1=getHead(8,1,2,3,5,6,7,8,8);
    Node* head2=getHead(6,1,2,3,12,17,9);
    int len1=getLength(head1);
    int len2=getLength(head2);
    Node* pstr1=head1->next;
    Node* pstr2=head2->next;
    if(len1>=len2){
        // 首先pstr1开始移动
        int len=len1-len2;
        for(int i=0;i<len;i++){
            pstr1=pstr1->next;
        }
    } else{
        int len=len2-len1;
        for(int j=0;j<len;j++){
            pstr2=pstr2->next;
        }
    }
    // 得到了同一节点的两个指针
    Node* res=isCombined(pstr1,pstr2);
    if(res==NULL){
        printf("链表没有交点\n");
    } else{
        printf("链表相交,并且交点对应的元素为:%d",res->data);
    }
    return 0;
}

// 求解链表的长度
int getLength(Node* head){
    Node* pstr=head->next;
    int length=0;
    while(pstr!=NULL){
        length++;
        pstr=pstr->next;
    }
    return length;
}
// 构造链表,这里利用可变参数构建链表
/**
 *  这里利用c语言可变参数
 * va_list相当于创建一个数组
 * va_start相当于给数组分配空间
 * va_arg(p_args,int)相当于迭代操作取出元素
 * va_end(p_args)相当于释放空间
*/
Node* getHead(int arg_cnt,...){
    Node* head=createHead();
    va_list p_args; // 相当于建立一个装载变量的数组
    // 初始化数组
    va_start(p_args,arg_cnt);  // 相当于分配内存空间
    int val=0;
    for(int i=0;i<arg_cnt;i++ ){
        val=va_arg(p_args,int);
        insertHead(head,val);
    }
    va_end(p_args); // 结束赋值
    printf("你建立的链表为:\n");
    displayList(head);
    return head;
}
// 判断是否详见的逻辑
Node* isCombined(Node* pstr1,Node* pstr2){
    while(pstr1!=NULL&&pstr2!=NULL){
        if(pstr1->data!=pstr2->data){
            pstr1=pstr1->next;
            pstr2=pstr2->next;
        }
        else{
            return pstr1;  // 得到交点
        }
    }
    return NULL;
}