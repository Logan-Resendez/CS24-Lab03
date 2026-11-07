// heap.cpp
// Logan Resendez

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end) : vdata(start, end)
{
  if(vdata.empty()) {return;}
  for(size_t i = vdata.size() / 2; i > 0; --i)
  {
    bubbleDown(i-1);
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  bubbleUp(vdata.size()-1);
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop()
{
  if(vdata.empty())
  {
    return;
  }

  vdata[0] = vdata.back();
  vdata.pop_back();

  if(!vdata.empty())
  {
    bubbleDown(0);
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if(vdata.empty())
  {
    return 0;
  }
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}

void Heap::bubbleDown(size_t i)
{
  size_t size = vdata.size();

  while(true)
  {
    size_t min = i;
    size_t left_child = 2 * i + 1;
    size_t right_child = 2 * i + 2;
    if(left_child < size && vdata[left_child] < vdata[min])
    {
      min = left_child;
    }
    if(right_child < size && vdata[right_child] < vdata[min])
    {
      min = right_child;
    }
    if (min == i)
    {
      return;
    }
    std::swap(vdata[i], vdata[min]);
    i = min;
    
  }
}

void Heap::bubbleUp(size_t i)
{
  while(i > 0)
  {
    size_t parent = ((i - 1)/2);
    if(vdata[i] >= vdata[parent])
    {
      return;
    }
    std::swap(vdata[i], vdata[parent]);
    i = parent;
  }
}