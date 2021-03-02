ListNode* reverseList(ListNode* head) {
   ListNode* pre = NULL;
   ListNode* cur = head;
   while(cur != NULL){
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
   }
   return pre;
}
