#pragma once
//template class with the datatype T
//solution approach with linked lists
template <class T>
class Vektor
{
private:  
  /*the element that will be createt and linked to another with the "next" and "last" pointer;
  contains the content that will be stored inside a field of the vector,
  as well as an identification numbre "id" to find the element*/
  struct element {
    struct element* last;
    struct element* next;
    T m_content;
    unsigned int id;
  };
  //initializes pointer that mark the head and tail of the list by pointing on those elements
  struct element* head = 0;
  struct element* tail = 0;
  //phelp is a helping pointer to search through the list
  struct element* phelp = 0;
  //the size of the vector
  int m_size = 0;
public:

  Vektor() {}
  ~Vektor() {}

  //adds one element with a content value to the end of the list
  void pushback(T value) {
    //if the list is empty
    if (head == 0) {
      head = new struct element;
      head->next = 0;
      head->last = 0;
      tail = head;
    }    
    else {
      head->last = new struct element;
      head->last->last = 0;
      head->last->next = head;
      head = head->last;
    }
    head->m_content = value;
    head->id = m_size;
    ++m_size;
  }
  //popback deletes the last element of the vector
  void popback() {
    if (head != 0) {
      if (m_size > 1) {
        head = head->next;
        delete head->last;
        head->last = 0;
      }
      else if (m_size == 1) {
        delete head;
        head = 0;
        tail = 0;
      }
      --m_size;
    }
  }
  //at returns the value with the data typ T on the comitted position of the list
  T at(int pos) {
    if (m_size > 0) {
      phelp = tail;
      for (int i = 0; i < m_size; ++i) {
        if (pos == phelp->id) {
          return phelp->m_content;
        }
        if (i < m_size - 1) {
          phelp = phelp->last;
        }
      }
    }
  }
  //returns the size of the vector
  int size() {
    return m_size;
  }
  /*resizes the vector to either shrinkining or enlarging it, which means the popback or pushback
  function will be called repeatedly until the the size of the vector matches the intended size*/
  void resize(int size) {
    if (size < m_size) {
      do {
        popback();
      } while (size < m_size);
    }
    if (size > m_size) {
      do {
        pushback(NULL);
      } while (size > m_size);
    }
  }
  //clears the vector by poping back the elements until the vector is empty
  void clear() {
    while (head != 0) {
      popback();
    }
  }
};

