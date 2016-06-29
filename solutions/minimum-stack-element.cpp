#include <iostream>
#include <stack>

using namespace std;

// Remember that top() gets you (reference to) the value at the top of the stack
// and that pop() actually takes the element off of the top (but returns nothing)
int getMinimumElementInStack(stack<int>& inputStack)
{
   // Temporary stack that will hold the integers in 
   // inputStack except "upside-down" as we pop off
   stack<int> x; 

   // Start off our minimum element with the value at the top of the stack
   int min = inputStack.top(); 

   // Cycle through all of the values in the stack by popping them 
   // off of inputStack and placing them in a different stack (x) 
   // If we find a smaller element than min, save its value in min
   while( !inputStack.empty() )
   {
      x.push(inputStack.top());
      if(inputStack.top() < min) 
      {
         min = inputStack.top(); 
      }
      inputStack.pop();
   }

   // Be sure to return inputStack back to its initial state
   while( !x.empty() )
   {
      inputStack.push(x.top());
      x.pop();  
   }
   
   return min; 
}