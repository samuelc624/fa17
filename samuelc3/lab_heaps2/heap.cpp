using namespace std;
/**
* @file heap.cpp
* Implementation of a heap class.
*/

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
  /// @todo Update to return the index you are choosing to be your root.
  return 0;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
  /// @todo Update to return the index of the left child.
  return 2 * currentIdx + 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
  /// @todo Update to return the index of the right child.
  return 2 * currentIdx + 2;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
  /// @todo Update to return the index of the parent.
  return (currentIdx - 1) / 2;
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
  /// @todo Update to return whether the given node has a child
  int indexLastNode = _elems.size() - 1;
  // If left child exists, return true (tree is complete)
  int indexLeftChild = leftChild(currentIdx);
  if(indexLastNode >= indexLeftChild)
      return true;
  return false;
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
  /// @todo Update to return the index of the child with highest priority
  ///   as defined by higherPriority()
  if(rightChild(currentIdx) > _elems.size() - 1) return leftChild(currentIdx);
  if(higherPriority(_elems[leftChild(currentIdx)],_elems[rightChild(currentIdx)]))
      return leftChild(currentIdx);
  return rightChild(currentIdx);
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
  /// @todo Implement the heapifyDown algorithm.
  if(!hasAChild(currentIdx))
    return;
  size_t indexMinChild = maxPriorityChild(currentIdx);
  if(!higherPriority(_elems[currentIdx],_elems[indexMinChild])) {
    swap(_elems[currentIdx],_elems[indexMinChild]);
    heapifyDown(indexMinChild);
  }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
  if (currentIdx == 0)
    return;
  size_t indexParent = parent(currentIdx);
  if(higherPriority(_elems[currentIdx], _elems[indexParent])) {
    swap(_elems[currentIdx], _elems[indexParent]);
    heapifyUp(indexParent);
  }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
  /// @todo Depending on your implementation, this function may or may
  ///   not need modifying
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems)
{
  /// @todo Construct a heap using the buildHeap algorithm
  for (size_t i = 0; i < elems.size(); i++)
    _elems.push_back(elems[i]);
  for (long i = _elems.size() - 1; i > -1; i--)
    heapifyDown(i);
}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
  /// @todo Remove, and return, the element with highest priority
  T tempRoot = _elems[0];
  swap( _elems[0], _elems.back());
  _elems.pop_back();
  heapifyDown(0);
  return tempRoot;
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
  /// @todo Return, but do not remove, the element with highest priority
  return _elems[0];
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
  /// @todo Add elem to the heap
  _elems.push_back(elem);
  heapifyUp(_elems.size()-1);
}

template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
  /// @todo Determine if the heap is empty
  return _elems.empty();
}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
  for (size_t i = 0; i < _elems.size(); i++)
    heaped.push_back(_elems[i]);
}
