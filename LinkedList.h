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
    while( bookPtr != NULL) {
      Book *nextBookPtr = bookPtr->next;
      free(bookPtr);
      bookPtr = nextBookPtr;
    }
    bookPtr = NULL;
 }

//Description: addElement function creates a new Book from the
//      newTitle and newISBN parameters. The new Book struct is
//      then appended to the LinkedList.  The function returns true if the
//      Book was unique and successfuly inserted, and returns false
//      if the Book already exists.
bool LinkedList::addElement(string newTitle, string newISBN)
 {
    // First part: finding if the Book already exists
    struct Book *bookPtr = head;
    while( bookPtr != NULL) {
      if (bookPtr->title.compare(newTitle) == 0 && bookPtr->isbn.compare(newISBN) == 0)
      {
        return false;
      }
      bookPtr = bookPtr->next;
    }

    // Second part: create new Book
    struct Book *newBook;
    newBook = (struct Book *) malloc(sizeof(struct Book));

    // Check that there is not heap overflow
    if (newBook == NULL) {
      printf("out of memory\n");  return false;
    }

    // Third part: inserting new Book
    newBook->title = newTitle;
    newBook->isbn  = newISBN;

    newBook->next = head;
    head = newBook;

    return true;
 }

//Description: .... to be completed
bool LinkedList::removeElement(string someISBN)
 {
    return true;
 } 

//Description: printList function outputs the contents of
//      the list to std::out.  The function takes no arguments
//      and returns void.
void LinkedList::printList()
 {
    struct Book *bookPtr = head;
    while(bookPtr != NULL) {
      cout << "Book Title: " << bookPtr->title << "\n";
      cout << "Book ISBN: "  << bookPtr->isbn  << "\n\n";
    }
 }

