// Assignment #1
// Name:
// ASU Email Address:
// Description: To be completed

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
//Description: ...... to be completed
LinkedList::~LinkedList()
 {
    //To be completed
 }

//Description: .... to be completed
bool LinkedList::addElement(string newTitle, string newISBN)
 {
    //To be completed
 }

//Description: .... to be completed
bool LinkedList::removeElement(string someISBN)
 {
    //To be complete
 } 

//Description: .... to be completed
void LinkedList::printList()
 {
   //To be completed
 }

