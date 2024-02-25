#include "StrList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _node
{
    char* _data;
    struct _node* next;
} Node;

struct _StrList 
{
    Node* _head;
    size_t _size;
    Node* _last;
};

Node* StrNode_alloc(const char* data, Node* next) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node != NULL) {
        node->_data = strdup(data); // Copy
        node->next = next;
    }
    return node;
}

void StrNode_free(Node* node) 
{
    if (node) {
        free(node->_data); 
        free(node); 
    }
}
void StrList_free(StrList* list) 
{
    Node* current = list->_head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current->_data); 
        free(current);
        current = next;
    }

    free(list);
}

StrList* StrList_alloc() 
{
    StrList* list = malloc(sizeof(StrList));
    list->_head = NULL;
    list->_size = 0;
    list->_last = list->_head;
    return list;
}

size_t StrList_size(const StrList* StrList)
{
    return StrList->_size;
}

char* StrList_firstData(const StrList* StrList)
{
    return StrList->_head->_data;
}

void StrList_insertLast(StrList* StrList, const char* data) 
{
    Node* newNode = StrNode_alloc(data, NULL);
    
    if (StrList->_head == NULL) 
    {
        StrList->_head = newNode;
        StrList->_last = newNode; // Point to the new node
    } 
    else 
    {
        StrList->_last->next = newNode; // connect to the new node
        StrList->_last = newNode; // update last
    }
    ++StrList->_size;
}

void StrList_insertAt(StrList* list, const char* data, int index) 
{
    if (list == NULL || index < 0 || index > list->_size) 
    {
        return; // exit because the index is out of the list
    }

    Node* newNode = StrNode_alloc(data, NULL);
    if (newNode == NULL) 
    {
        return; // for case of error
    }

    if (index == 0) 
    {
        // to the head of the list
        newNode->next = list->_head;
        list->_head = newNode;
        if (list->_size == 0) 
        {
            // if the list was emty this node is too the last one
            list->_last = newNode;
        }
    } 
    else if (index == list->_size) 
    {
        // Insert to the end of the list
        if (list->_last != NULL) 
        {
            list->_last->next = newNode;
        }
        list->_last = newNode;
    } 
    else 
    {
        // Insertion in the list
        Node* current = list->_head;
        for (int i = 0; i < index - 1; i++) 
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    if (index == 0 && list->_size == 0) 
    {
        // update of last
        list->_last = newNode;
    }

    list->_size++; // update the size of the list
}


StrList* sentence_to_list(char* sentence) 
{
    StrList* list = StrList_alloc();
    const char* delim = " ";
    char* token = strtok(sentence, delim);

    while (token != NULL) 
    {
        StrList_insertLast(list, token);
        token = strtok(NULL, delim);
    }

    return list;
}



void add_sentence_to_end_of_list(StrList* list, const char* sentence, int num) 
{
    const char* space = " ";
    char* temp_sentence = strdup(sentence); // copy the sentence for utilisation of strtok
    if (temp_sentence == NULL) return; 
    char* token = strtok(temp_sentence, space);
    int wordsAdded = 0;

    while (token != NULL && wordsAdded < num) {
        StrList_insertLast(list, token); // use StrList_insertLast for each word
        wordsAdded++;
        token = strtok(NULL, space);
    }

    free(temp_sentence);
}

void StrList_print(const StrList* list) 
{
    // if (list == NULL || list->_head == NULL) 
    // {
    //     printf("");
    //     return;
    // }

    Node* current = list->_head;
    while (current != NULL) 
    {
        if (current->next != NULL) 
        {
            printf("%s ", current->_data); // print the date with a space at the end if it's not the last one
        } 
        else 
        {
            printf("%s", current->_data); // no space for the last node
        }
        current = current->next; // next one
    }
    printf("\n"); 
}

void print_size(const StrList* StrList)
{
    printf("%zu\n", StrList_size(StrList));
}

void StrList_printAt(const StrList* Strlist,int index)
{
    if (index >= 0 && index < Strlist->_size)
    {
        Node* current = Strlist->_head;
    int count = 0;
    while (count != index)
    {
        ++count;
        current = current->next;
    }
    printf("%s\n", current->_data);
    }
    else return;
}

int StrList_printLen(const StrList* Strlist)
{
    int count = 0;
    Node* current = Strlist->_head;
    while (current != NULL)
    {
        count += strlen(current->_data);
        current = current->next;
    }
    return count;
}

int nodes_equal(const Node* node1, const Node* node2) {
    // check if they are null
    if (node1 == NULL || node2 == NULL) 
    {
        return FALSE;
    }
    
    if (strcmp(node1->_data, node2->_data) == 0) 
    {
        return TRUE;
    } 
    else 
    {
        return FALSE;
    }
}

int StrList_count(StrList* list, const char* data)
{
    if (list == NULL || list->_head == NULL) return 0;
    if (data == NULL || strlen(data) == 0) return 0;
    StrList* str = sentence_to_list(data);
    int size = StrList_size(str);
    int count = 0;
    int i = 0;
    int j = 0;
    Node* current = list->_head;
    int bool = TRUE;
    // we pass on each node and each time that the data apparate we add 1 to count
    while (i < StrList_size(list))
    {
        if (nodes_equal(current, str->_head))
        {
            Node* temp1 = current;
            Node* temp2 = str->_head;
            bool = TRUE;
            j = 0;
            while (j < size)
            {
                if (nodes_equal(temp1, temp2) == FALSE)
                {
                    bool = FALSE;
                    break;
                }
                ++j;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            if (bool == TRUE)
            {
                ++count;
            }
        }
        ++i;
        current = current->next;
    }
    StrList_free(str);
    return count;
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2)
{
    int size1 = StrList_size(StrList1);
    int size2 = StrList_size(StrList2);
    if (size1 != size2)
    {
        return FALSE;
    }

    Node* current1 = StrList1->_head;
    Node* current2 = StrList2->_head;
    for (size_t i = 0; i < size1; i++)
    {
        if (nodes_equal(current1, current2) == FALSE)
        {
            return FALSE;
        } 
        current1 = current1->next;
        current2 = current2->next;
    }
    return TRUE;
}

StrList* StrList_clone(const StrList* list) 
{
    // new empty list
    StrList* ret = StrList_alloc();
    if (!ret || !list) return NULL; 

    Node** copy = &(ret->_head); // point to the next cloned node
    const Node* old = list->_head; // pointer for the old list

    // for each node
    while (old) 
    {
        *copy = StrNode_alloc(old->_data, NULL); 
        if (old == list->_last) 
        {
            ret->_last = *copy;
        }
        old = old->next;
        copy = &((*copy)->next);
    }
    ret->_size = list->_size;
    return ret;
}

void StrList_remove(StrList* list, const char* data) 
{
    if (list == NULL || list->_head == NULL) return;
    int x = StrList_count(list, data);

    Node** ptr = &(list->_head);

    while (*ptr != NULL) 
    {
        Node* current = *ptr;
        if (strcmp(current->_data, data) == 0) 
        {
            *ptr = current->next; // update the pointer for the jump
            StrNode_free(current); 

            // update last
            if (*ptr == NULL) 
            {
                list->_last = (Node*)ptr;
            }
        } 
        else 
        {
            ptr = &current->next; 
        }
    }

}

void StrList_removeAt(StrList* StrList, int index)
{
    if (StrList->_head == NULL || index < 0 || index >= StrList->_size) return;

    Node** ptr = &(StrList->_head);
    for (int i = 0; i < index; i++) {
        ptr = &((*ptr)->next);
    }

    Node* toDelete = *ptr;
    *ptr = toDelete->next;

    if (toDelete == StrList->_last) {
        StrList->_last = (Node*)((ptr == &(StrList->_head)) ? NULL : ptr);
    }

    StrNode_free(toDelete);
    StrList->_size--;
    
}

void StrList_reverse( StrList* list)
{
    if (list == NULL || list->_head == NULL) return;
    Node* precedent = NULL;
    Node* current = list->_head; 
    Node* next = NULL;

    while (current != NULL) 
    {
        next = current->next; // save the next node
        current->next = precedent; // reverse the pointer of the next node so that it point to the precedent
        precedent = current; // move the precedent ponter so that it point to current node
        current = next; // move the current pointer so that it point to the next node
    }

    list->_last = list->_head;
    list->_head = precedent;
    
}

void StrList_findMiddle(Node* head, Node** frontRef, Node** backRef) 
{
    Node* speed;
    Node* slow;
    slow = head;
    speed = head->next;

    // move speed up by two nodes, and slow by one
    while (speed != NULL) 
    {
        speed = speed->next;
        if (speed != NULL) 
        {
            slow = slow->next;
            speed = speed->next;
        }
    }

    // 'slow' is before the midlle in the list so we divide in his place
    *frontRef = head;
    *backRef = slow->next;
    slow->next = NULL;
}

// merge two sorted list
Node* StrList_sortedMerge(Node* a, Node* b) 
{
    Node* result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    // choose a and b ans recursive
    if (strcmp(a->_data, b->_data) <= 0) 
    {
        result = a;
        result->next = StrList_sortedMerge(a->next, b);
    } 
    else 
    {
        result = b;
        result->next = StrList_sortedMerge(a, b->next);
    }
    return result;
}

// execute the merge sort
void StrList_mergeSort(Node** headRef) 
{
    Node* head = *headRef;
    Node* a;
    Node* b;

    if ((head == NULL) || (head->next == NULL)) 
    {
        return;
    }

    // Divide
    StrList_findMiddle(head, &a, &b);

    // sort recursive
    StrList_mergeSort(&a);
    StrList_mergeSort(&b);

    // merge
    *headRef = StrList_sortedMerge(a, b);
}


// execute merge sort on our list
void StrList_sort(StrList* list) 
{
    if (list == NULL || list->_head == NULL) 
    {
        return;
    }
    StrList_mergeSort(&(list->_head));
    // update last
    Node* current = list->_head;
    while (current != NULL && current->next != NULL) 
    {
        current = current->next;
    }
    list->_last = current;
}

int StrList_isSorted(StrList* list) 
{
    if (list == NULL || list->_head == NULL || list->_head->next == NULL) 
    {
        return TRUE;
    }

    Node* current = list->_head;
    while (current->next != NULL) 
    {
        // Compare the node to the next one
        if (strcmp(current->_data, current->next->_data) > 0) 
        {
            return FALSE;
        }
        current = current->next;
    }
    return TRUE;
}

void add_sentence_to_index_of_list(StrList* list, const char* sentence, int index) 
{
    char tempSentence[MAX_LENGTH]; // for copy
    strncpy(tempSentence, sentence, MAX_LENGTH);
    tempSentence[MAX_LENGTH - 1] = '\0'; 

    const char* delim = " "; // delimitation : " "
    char* token = strtok(tempSentence, delim); // cut the sentence by words
    int currentIndex = index;

    while (token != NULL) 
    {
        StrList_insertAt(list, token, currentIndex); 
        currentIndex++;
        token = strtok(NULL, delim);
    }
}

