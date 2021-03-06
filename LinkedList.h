// Assignment #1
// Name: Jacob Pruitt
// ASU Email Address: jrpruit1@asu.edu
// Description: Describes a LinkedList class that holds
//        a reference to a list of Book structures, and
//        has methods for manipulating Book data,
//        including deleting and removing items

#include <iostream> //to use cout
#include <string> //to use strings

using namespace std;

//struct Book represents some book information
struct Book
 {
  string title;
  string isbn;
  struct Book * next;
 };

//class LinkedList will contains a linked list of books
class LinkedList
 {
  private:
     struct Book * head;

  public:
     LinkedList();
     ~LinkedList();
     bool addElement(string title, string isbn);
     bool removeElement(string isbn);
     void printList();
 };

//Constructor 
//It sets head to be NULL to create an empty linked list
LinkedList::LinkedList()
 {
   head = NULL;
 }

//Destructor
//Description: Destructor function that is called when LinkedList
//      object is deleted.  Needed in order to remove the Book nodes
//      from heap memory.
LinkedList::~LinkedList()
 {
    struct Book *bookPtr = head;
    int count = 0;
    while( bookPtr != NULL) {
      Book *nextBookPtr = bookPtr->next;
      delete bookPtr;
      bookPtr = nextBookPtr;
      count++;
    }
    bookPtr = NULL;

    cout << "The number of deleted books is: " << count << "\n";
 }

//Description: addElement function creates a new Book from the
//      newTitle and newISBN parameters. The new Book struct is
//      then appended to the LinkedList.  The function returns true if the
//      Book was unique and successfuly inserted, and returns false
//      if the Book already exists.
bool LinkedList::addElement(string newTitle, string newISBN)
 {
    // First part: finding if the Book already exists
    struct Book *bookPtr = head, *prevPtr = bookPtr;
    while( bookPtr != NULL && bookPtr->title.compare(newTitle) <= 0) {
      if (bookPtr->title.compare(newTitle) == 0) {
        return false;
      } else {
        prevPtr = bookPtr;
        bookPtr = bookPtr->next;
      }
    }

    // Second part: create new Book
    struct Book *newBook = new Book();

    // Third part: inserting new Book
    newBook->title = newTitle;
    newBook->isbn  = newISBN;

    if (bookPtr == head) {
      newBook->next = head;
      head = newBook;
    } else {
      newBook->next = bookPtr;
      prevPtr->next = newBook;
    }

    bookPtr = NULL;
    prevPtr = NULL;
    newBook = NULL;

    return true;
 }

//Description: removeElement function removes a Book element from
//      the LinkedList based on the someISBN parameter.  The function
//      returns true if the Book was successfully removed, false otherwise.
bool LinkedList::removeElement(string someISBN)
 {
    struct Book *bookPtr = head, *prevPtr = bookPtr;
    while( bookPtr != NULL) {
      if (bookPtr->isbn.compare(someISBN) == 0) {
        if (bookPtr == head) {
          head = bookPtr->next;
          delete bookPtr;
        } else {
          prevPtr->next = bookPtr->next;
          delete bookPtr;
        }

        return true;
      } else {
        prevPtr = bookPtr;
        bookPtr = bookPtr->next;
      }
    }
    bookPtr = NULL;
    prevPtr = NULL;

    return false;
 } 

//Description: printList function outputs the contents of
//      the list to std::out.  The function takes no arguments
//      and returns void.
void LinkedList::printList()
 {
    struct Book *bookPtr = head;
    cout << "\n\n";
    while(bookPtr != NULL) {
      cout << "Book Title: " << bookPtr->title << "\n";
      cout << "Book ISBN: "  << bookPtr->isbn  << "\n\n\n";
      bookPtr = bookPtr->next;
    }
    cout << "\n";
    bookPtr = NULL;
 }

