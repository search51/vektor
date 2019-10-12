#pragma once
template <class T>
class Vektor
{
private:
  struct element {
    struct element* last;
    struct element* next;
    T m_content;
    unsigned int id;
  };
  struct element* head = 0;
  struct element* tail = 0;
  struct element* phelp = 0;
  int m_size = 0;
public:

  Vektor() {}
  ~Vektor() {}


  void pushback(T value) {
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

  int size() {
    return m_size;
  }
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
  void clear() {
    while (head != 0) {
      popback();
    }
  }
};

