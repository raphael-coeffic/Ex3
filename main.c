#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"


int main()
{
    StrList* myList = StrList_alloc();
    while (1)
    {
        // the user choose the option that he want
        int func_choice = 0;
        scanf("%d", &func_choice);
        getchar();
        switch (func_choice)
        {
            case 1:                                 // add a sentence to a list
            {
                int number = 0;
                scanf("%d", &number);
                getchar();
                
                char sentence[MAX_LENGTH]; 
                fgets(sentence, MAX_LENGTH, stdin); 
                
                sentence[strcspn(sentence, "\n")] = 0;
                add_sentence_to_end_of_list(myList, sentence, number);
                break;
            }
            
            case 2:                               // add a sentence at an index of then list
            {
                int index = 0;
                scanf("%d", &index);
                getchar();
                
                char sentence[MAX_LENGTH]; 
                fgets(sentence, MAX_LENGTH, stdin); 
                
                sentence[strcspn(sentence, "\n")] = 0;
                add_sentence_to_index_of_list(myList, sentence, index);
                break;
            }

            case 3:                              // print the entire list
                StrList_print(myList);
                break;

            case 4:                              // print the number of words
                print_size(myList);
                break;

            case 5:
            {
                int index = 0;                 // print an string at an index
                scanf("%d", &index);
                getchar();
                StrList_printAt(myList, index);
                break;
            }
            case 6:                            // print the num of chars
                printf("%d\n", StrList_printLen(myList));
                break;
      
            case 7:                             // pritn how much a string apparate in the list
            {
                char sentence[MAX_LENGTH]; 
                fgets(sentence, MAX_LENGTH, stdin);
                sentence[strcspn(sentence, "\n")] = 0;
                printf("%d\n", StrList_count(myList, sentence));
                break;
            }

            case 8:                              // for each time that a specific string apparate we remove him
            {
                char sentence[MAX_LENGTH]; 
                fgets(sentence, MAX_LENGTH, stdin); 
                sentence[strcspn(sentence, "\n")] = 0;
                StrList_remove(myList, sentence);
                break;
            }

            case 9:                            // remove the data of an index
            {
                int index = 0;
                scanf("%d", &index);
                getchar();
                StrList_removeAt(myList, index);
                break;
            }

            case 10:                        // reverse the list
                StrList_reverse(myList);
                break;

            case 11:                         // remove all the data of the list
                StrList_free(myList);
                myList = StrList_alloc();
                break;
            
            case 12:                        // sort he list
                StrList_sort(myList); 
                break;

            case 13:                              // check if the list is sorted
            {
                if (StrList_isSorted(myList) == FALSE)
                {
                    printf("false\n");
                }
                else
                {
                    printf("true\n");
                }
                break;
            }

            case 0:                              // exit
                StrList_free(myList);
                exit(0);

            default:
                break;
        }
    }

    StrList_free(myList);
    return 0;
}
