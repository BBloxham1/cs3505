/* A 'string set' is defined as a set of strings stored
 * in sorted order in a drop list.  See the class video
 * for details.
 *
 * For lists that do not exceed 2 ^ (max_width + 1)
 * elements, the add, remove, and contains functions are 
 * O(lg size) on average.  The operator= and get_elements 
 * functions are O(size).   
 * 
 * Peter Jensen
 * February 12, 2021
 */

#include "string_set.h"
#include <iostream>  // For debugging, if needed.
#include <vector>

namespace cs3505
{
  /*******************************************************
   * string_set member function definitions
   ***************************************************** */
  
  /** Constructor:  The parameter indicates the maximum
    * width of the next pointers in drop list nodes.
    */
  cs3505::string_set::string_set(int max_width)
  {
    // TODO:  Complete this constructor
    this->max_width = max_width;
    this->head = new node("", max_width);
    this->current = head->next_nodes[max_width-1];

  }

  
  /** Copy constructor:  Initialize this set
    * to contain exactly the same elements
    * as another set.
    */
  cs3505::string_set::string_set (const string_set &other)
  {
    // TODO:  Complete this constructor
  }


  /** Destructor:  Release any memory allocated
    * for this object.
    */
  cs3505::string_set::~string_set()
  {
    // TODO:  Complete this destructor to correctly deallocate 
    // any heap-allocated memory for this object.    
  }




  /* Additional public and private helper function definitions needed here */
  void cs3505::string_set::add(const std::string &data){
    // NEED TO FINISH THIS
    if(contains(data))
      return; 

    
    node *new_node = new node (data, rand_length(this->max_width));
    std::vector<node*> prior_nodes;

    int head_iterator = max_width - 1;
    node * current_node = head;
    node * current_pointer = head->next_nodes[head_iterator];

    current = head->next_nodes[head_iterator];

    while (current_pointer == NULL){    
      // if the list is empty add it to the first item head list
      if (head_iterator == 0){
        for (int i = 0; i < new_node->capacity; i++){
          prior_nodes[i]->next_nodes[i] = new_node;
        }
        return;
      } 
      prior_nodes.push_back(current_node);
      // decrement place in array
      head_iterator--;  
      current_pointer = current_node->next_nodes[head_iterator];

    }

    // add the current node to prior nodes
    prior_nodes.push_back(current_node);
    //current found  non-null pointer
    int comparison = data.compare(current_node->data);
    if (comparison == 0)
      return;

    // if comparison is negative, then data should be higher in the list than the current data
    else if (comparison < 0){
      for (int i = 0; i < prior_nodes.size(); i++){
          new_node->next_nodes[i] = prior_nodes[i];
          prior_nodes[i] = new_node;
        }
      return;  
    }
     
       
  }
  bool cs3505::string_set::contains(const std::string &data) const{
    int head_iterator = max_width - 1;
    std::vector<node*> prior_nodes;
    prior_nodes.push_back(head);

    node * current_node = head;
    node * current_pointer = head->next_nodes[head_iterator];

    // loop until the end
    while (true){
      //std::cout << "head iterator: " << head_iterator <<  std::endl;
      //std::cout << current_pointer <<  std::endl;
      // decrement and add to prior nodes if the current is null
      if  (current_pointer == NULL){
        head_iterator--;
       current_pointer = current_node->next_nodes[head_iterator];
        // this means the string set is empty 
        if  (current_pointer == NULL && head_iterator == 0)
          return false;

      }
      
      // now we're at a pointer that points to something
      else{
        int comparison = data.compare(current_pointer->data);

        if (comparison == 0)
          return true;
        // we've gone too far
        else if(comparison < 0 && head_iterator != 0){
          head_iterator--;
          std::cout << "fuck your mom" << std::endl;
         current_pointer = prior_nodes[head_iterator];
          std::cout << "also your dad" << std::endl;
        }

        else if(comparison < 0 && head_iterator == 0){
          std::cout << "hade it here" << std::endl;
          current_pointer = current_pointer->next_nodes[0];
        }
      }
    }

    return false;
  }

  
  const int cs3505::string_set::rand_length(int maxlength){
    int length = 1;
    int operand = 1;
    
    while (length <= maxlength){
      operand = std::rand() % 2;
      if (operand == 1)
	length += 1;

      else
	return length;
    }
    
    return maxlength;
  }

 
}
