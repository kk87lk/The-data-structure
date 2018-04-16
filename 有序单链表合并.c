PNode MergeTwoOrderedLists(PNode pHead1, PNode pHead2)   //http://blog.csdn.net/a1414345/article/details/52641794
{  
    PNode pTail = NULL;//指向新链表的最后一个结点 pTail->next去连接  
    PNode newHead = NULL;//指向合并后链表第一个结点  
  
    if (NULL == pHead1)  
    {  
        return pHead2;  
    }   
    else if(NULL == pHead2)  
    {  
        return pHead1;  
    }  
    else  
    {  
        //确定头指针  
        if ( pHead1->data < pHead2->data)  
        {  
            newHead = pHead1;  
            pHead1 = pHead1->next;  //指向链表的第二个结点  
        }   
        else  
        {  
            newHead = pHead2;  
            pHead2 = pHead2->next;  
        }  
        pTail = newHead;    //指向第一个结点  
        while ( pHead1 && pHead2)    
        {  
            if ( pHead1->data <= pHead2->data )  
            {  
                pTail->next = pHead1;    
                pHead1 = pHead1->next;  
            }  
            else   
            {  
                pTail->next = pHead2;  
                pHead2 = pHead2->next;  
            }  
            pTail = pTail->next;  
        }  
  
        if(NULL == pHead1)  
        {  
            pTail->next = pHead2;  
        }  
        else if(NULL == pHead2)  
        {  
            pTail->next = pHead1;  
        }  
        return newHead;  
}  
