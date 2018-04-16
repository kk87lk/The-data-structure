PNode MergeTwoOrderedLists(PNode pHead1, PNode pHead2)   //http://blog.csdn.net/a1414345/article/details/52641794
{  
    PNode pTail = NULL;//ָ������������һ����� pTail->nextȥ����  
    PNode newHead = NULL;//ָ��ϲ��������һ�����  
  
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
        //ȷ��ͷָ��  
        if ( pHead1->data < pHead2->data)  
        {  
            newHead = pHead1;  
            pHead1 = pHead1->next;  //ָ������ĵڶ������  
        }   
        else  
        {  
            newHead = pHead2;  
            pHead2 = pHead2->next;  
        }  
        pTail = newHead;    //ָ���һ�����  
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
