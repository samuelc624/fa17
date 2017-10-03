/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <class T>
List<T>::~List() {
  /// @todo Graded in MP3.1
    clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear() {
  /// @todo Graded in MP3.1
  while(head_ != NULL){
    tail_ = head_ -> next;
    delete head_;
    head_ = tail_;
    } 
  }

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata) {
  /// @todo Graded in MP3.1

  ListNode * poo = new ListNode(ndata);
    poo->next = head_;
    poo -> prev = NULL;
  if(head_ == NULL){
    poo -> next = NULL;
    tail_ = poo;
  }  
  else{
    poo->next = head_;
    head_ -> prev = poo;
  }
  head_ = poo;
/*
  if(head_ == NULL){
        head_ = new ListNode(ndata);
        head_->next = NULL;
        head_->prev = NULL;
        tail_ = head_;
        tail_-> next = NULL;
        tail_->prev = NULL;
  }
  head_ -> prev = new ListNode(ndata);  
  ListNode * knew = head_;
    head_ = head_ -> prev;
    head_ -> prev = NULL;
    head_ -> next = knew;
*/
        length_++;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
  ://github.com/dyjhhh/cs225/blob/master/mp3/list.cppistNode * poo = new ListNode(ndata);
    poo -> prev = NULL;
  if(head_ == NULL){
    poo -> next = NULL;
    poo = head_;
  }  
  else{
    poo->next = head_;
    head -> prev = poo;
  }
  head_ = poo
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata) {
  /// @todo Graded in MP3.1
  ListNode * pool = new ListNode(ndata);
    pool -> next = NULL;
  if(tail_ == NULL){
    pool -> prev = NULL;
    head_ = pool;
  }  
  else{
    pool->prev = tail_;
    tail_ -> next = pool;
  }
  tail_ = pool;
    length_++;
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse() {
  reverse(head_, tail_);
    
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse(ListNode*& startPoint, ListNode*& endPoint) {
    /// @todo Graded in MP3.1
    ListNode* endPointnext = endPoint->next;
    ListNode* startPointprev = startPoint->prev;
    ListNode* current = startPoint;
   ListNode* startPointnext = startPoint -> next;
   ListNode* binky = NULL;
       while(current != endPoint){
    binky = current -> next;
    current -> next = current -> prev;
    current -> prev = binky;
    current = startPointnext;
    startPointnext = startPointnext -> next;

   } 
       startPoint -> next = endPointnext;
      if(endPointnext != NULL)
            endPointnext -> prev = startPoint;
      endPoint -> next = endPoint -> prev;
      endPoint -> prev = startPointprev;
        if(startPointprev != NULL)
                startPointprev -> next = endPoint;
        if(startPoint == head_)
                head_ = endPoint;
        if(endPoint == tail_)
                tail_ = startPoint;
        binky = endPoint;
        endPoint = startPoint;
        startPoint = binky;
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.1
     if (length_ <= 1 || n == 1)
            return;
    if (n == length_)
            reverse();
    ListNode *bink = head_;
    ListNode *newhead = head_;
    ListNode *newtail = NULL;
    
    int num = n;
    while(bink != NULL){
        if(num == 0){
            if(newhead == head_)
                    head_ = newhead;
            reverse(newhead, newtail);
            num = n;
            newhead = newtail = bink;
        }
        if(bink -> next == NULL)
                reverse(newhead, bink);
    newtail = bink;
    bink = bink->next;
    num--;
    }

}


/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1
    if(length_ == 0)
            return;
    ListNode * all = head_;
    ListNode * start = head_;
    int num = 1;
    while(all != tail_ && all->next != tail_ && all != NULL){
        while(num > 0){
            start = all;
            all = all -> next;
            num--;
        }
        start->next = all->next;
        all->next->prev = start;
        tail_ -> next = all;
        all -> next = NULL;
        all -> prev = tail_;
        tail_ = all;
        all = start -> next;
        num = 1;
    }
    all = NULL;
    start = NULL;
    
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint) {
    if (splitPoint > length_)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode* secondHead = split(head_, splitPoint);

    int oldLength = length_;
    if (secondHead == head_) {
        // current list is going to be empty
        head_ = NULL;
        tail_ = NULL;
        length_ = 0;
    } else {
        // set up current list
        tail_ = head_;
        while (tail_->next != NULL)
            tail_ = tail_->next;
        length_ = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head_ = secondHead;
    ret.tail_ = secondHead;
    if (ret.tail_ != NULL) {
        while (ret.tail_->next != NULL)
            ret.tail_ = ret.tail_->next;
    }
    ret.length_ = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint) {
    /// @todo Graded in MP3.2
    return NULL;
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T>& otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second) {
  /// @todo Graded in MP3.2
  return NULL;
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort() {
    if (empty())
        return;
    head_ = mergesort(head_, length_);
    tail_ = head_;
    while (tail_->next != NULL)
        tail_ = tail_->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength) {
    /// @todo Graded in MP3.2
    return NULL;
}
