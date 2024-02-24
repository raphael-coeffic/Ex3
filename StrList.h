#pragma once
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_LENGTH 500

/********************************************************************************
 *
 * A StrList library.
 *
 * This library provides a StrList of STRINGS data structure.
 *
 * This library will fail in unpredictable ways when the system memory runs
 * out.
 *
 ********************************************************************************/

/*
 * StrList represents a StrList data structure.
 */
struct _StrList;
typedef struct _StrList StrList;
// typedef struct _node;
typedef struct _node Node;

/*
 * Allocates a new empty StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_alloc();                           //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

/*
 * Frees the memory and resources allocated to StrList.
 * If StrList==NULL does nothing (same as free).
 */
void StrList_free(StrList* StrList);                 //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

/*
 * Returns the number of elements in the StrList.
 */
size_t StrList_size(const StrList* StrList);        //xxxxxxxxxxxxxxxxxxxxxxxxxx

/*
 * Inserts an element in the end of the StrList.
 */
void StrList_insertLast(StrList* StrList,          //xxxxxxxxxxxxxxxxxxxx
					  const char* data);

/*
* Inserts an element at given index
*/
void StrList_insertAt(StrList* StrList,              //xxxxxxxxxxxxxxxxxxxxxxx
	const char* data,int index);

/*
 * Returns the StrList first data.
 */
char* StrList_firstData(const StrList* StrList);     //xxxxxxxxxxxxxxxxxxxxxxxxxxx

/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList* StrList);          //xxxxxxxxxxxxxxxxxxxxxxx

/*
 Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList* Strlist,int index);  //xxxxxxxxxxxxxxxxxxxxx

/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList* Strlist);             //xxxxxxxxxxxxxxxxxxxxxxxx

/*
Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList* StrList, const char* data);     //xxxxxxxxxxxxxxxxxxxxxxxxx

/*
Given a string and a list, remove all the appearences of this string in the list.
*/
void StrList_remove(StrList* StrList, const char* data);    //xxxxxxxxxxxxxxxxxxxxxxx

/*
	Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList* StrList, int index);          //xxxxxxxxxxxxxxxx

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2);   //xxxxxxxxxxxxxxxxxxxxxxx

/*
 * Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.      //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *                                                                 //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */
StrList* StrList_clone(const StrList* StrList);                  //xxxxxxxxxxxxxxxxxxxx

/*
 * Reverces the given StrList. 
 */
void StrList_reverse( StrList* StrList);                           //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

/*
 * Sort the given list in lexicographical order 
 */
void StrList_sort( StrList* StrList);

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StrList);

/*
 * return a list from a sentence (space is delimitation between words)
*/
StrList* sentence_to_list(char* sentence);

/*
 * Add an entire sentence to the end of a list
*/
void add_sentence_to_end_of_list(StrList* list, const char* sentence, int number);

void print_size(const StrList* StrList);


/*
* Check if two nodes are equals
*/
int nodes_equal(const Node* node1, const Node* node2);


void add_sentence_to_index_of_list(StrList* list, const char* sentence, int index);

/*
* The next functions if for sort with the algo of merge sort (nlogn)
*/

void StrList_findMiddle(Node* head, Node** frontRef, Node** backRef);

Node* StrList_sortedMerge(Node* a, Node* b);

void StrList_mergeSort(Node** headRef);
