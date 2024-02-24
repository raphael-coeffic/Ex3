#include <stdio.h>
#include <stdlib.h>
#include "StrList.h"


int main()
{
    StrList* myList = StrList_alloc();
    while (1)
    {
        int func_choice = 0;
        scanf("%d", &func_choice);
        getchar();
        switch (func_choice)
        {
            case 1:
            {
                int number = 0;
                scanf("%d", &number);
                getchar();
                
                char sentence[MAX_LENGTH]; // Déclare un tableau de caractères pour stocker la phrase
                fgets(sentence, MAX_LENGTH, stdin); // Lit une ligne de l'entrée standard
                
                // Supprime le saut de ligne potentiel à la fin de la chaîne si présent
                sentence[strcspn(sentence, "\n")] = 0;
                add_sentence_to_end_of_list(myList, sentence, number);
                break;
            }
            
            case 2:
            {
                int index = 0;
                scanf("%d", &index);
                getchar();
                
                char sentence[MAX_LENGTH]; // Déclare un tableau de caractères pour stocker la phrase
                fgets(sentence, MAX_LENGTH, stdin); // Lit une ligne de l'entrée standard
                
                // Supprime le saut de ligne potentiel à la fin de la chaîne si présent
                sentence[strcspn(sentence, "\n")] = 0;
                add_sentence_to_index_of_list(myList, sentence, index);
                break;
            }

            case 3:
                StrList_print(myList);
                break;

            case 4:
                print_size(myList);
                break;

            case 5:
            {
                int index = 0;
                scanf("%d", &index);
                getchar();
                StrList_printAt(myList, index);
                break;
            }
            case 6:
                printf("%d\n", StrList_printLen(myList));
                break;

            case 7:
            {
                char sentence[MAX_LENGTH]; // Déclare un tableau de caractères pour stocker la phrase
                fgets(sentence, MAX_LENGTH, stdin); // Lit une ligne de l'entrée standard
                sentence[strcspn(sentence, "\n")] = 0;
                printf("%d\n", StrList_count(myList, sentence));
                break;
            }

            case 8:
            {
                char sentence[MAX_LENGTH]; // Déclare un tableau de caractères pour stocker la phrase
                fgets(sentence, MAX_LENGTH, stdin); // Lit une ligne de l'entrée standard
                sentence[strcspn(sentence, "\n")] = 0;
                StrList_remove(myList, sentence);
                break;
            }

            case 9:
            {
                int index = 0;
                scanf("%d", &index);
                getchar();
                StrList_removeAt(myList, index);
                break;
            }

            case 10:
                StrList_reverse(myList);
                break;

            case 11:
                StrList_free(myList);
                break;
            
            case 12:
                StrList_sort(myList);
                break;

            case 13:
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

            case 0:
                StrList_free(myList);
                exit(0);

            default:
                break;
        }
    }

    
    return 0;
}