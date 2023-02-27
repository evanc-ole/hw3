#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  //~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
std::vector<T> arr_;
private:
  /// Add whatever helper functions and data members you need below
  
  int m_;
  PComparator c_;


};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c):
m_(m), c_(c)
{}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw(std::underflow_error("Empty Heap"));
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return arr_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
  throw(std::underflow_error("Empty Heap"));
  }
  swap(arr_[0], arr_[arr_.size() - 1]);
  arr_.pop_back();
  bool end = true;
//trickle down
  int i = 0;
  while(m_*i + m_ < static_cast<int>(size())){
    int best = i;
    for(int j = 1; j <= m_; j++){
      if(!c_(arr_[best], arr_[i*m_ + j])){
        best = i*m_ + j;
      }
    }
    if(best != i){
      swap(arr_[best], arr_[i]);
      i = best;
    }
    else{
      end = false;
      break;
    }
  }
  //if tree is incomplete
  int s = static_cast<int>(size());
  if(s - 1 - i*m_ > 0 && end){
    int best = i;
    for(int j = 1; j <= s - 1 - i*m_; j++){
      if(!c_(arr_[best], arr_[i*m_ + j])){
        best = i*m_ + j;
      }
    }
    if(best != i){
      swap(arr_[best], arr_[i]);
      i = best;
    }
  }
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return arr_.std::vector<T>::size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return size() == 0;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  arr_.push_back(item);

  //trickle up
  size_t index = size() - 1;
  while(index > 0){
    size_t parent = (index - 1)/m_;
    if(c_(arr_[index], arr_[parent])){
      swap(arr_[index], arr_[parent]);
      index = parent;
    }
    else{break;}
  }

}
#endif

