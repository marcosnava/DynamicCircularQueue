#include <stdio.h>

#include "CircularQueue.h"

// Constants
enum {
    MNU_NO_SELECTION = 0,
    MNU_ADD,
    MNU_REMOVE,
    MNU_SHRINK,
    MNU_PRINT,
    MNU_QUIT
};

// Prototype
int menu();

int main() {
    Create(5);

    int option = MNU_NO_SELECTION;
    int value;

    while(option != MNU_QUIT)
    {
        option = menu();

        switch (option) {
            case MNU_ADD:
                printf("Enter a number: ");
                scanf("%d", &value);

                if(Add(value))
                {
                    printf("%d added to queue!\n", value);
                }
//                else
//                {
//                    printf("Impossible to add. Queue is full!\n");
//                }
                break;
            case MNU_REMOVE:
                if(Remove(&value))
                {
                    printf("%d was removed from queue!\n", value);
                }
                else
                {
                    printf("Impossible to remove! Queue is empty!\n");
                }
                break;
            case MNU_SHRINK:
                ShrinkQueue();
                break;
            case MNU_PRINT:
                printQueue();
                break;
            case MNU_QUIT:
                break;
            default:
                printf("Invalid option!\n");
        }
    }

    Destroy();

    return 0;
}

int menu()
{
    int opt = MNU_NO_SELECTION;

    printf("********************\n");
    printf("*     M E N U      *\n");
    printf("********************\n");
    printf("* %d - Add          *\n", MNU_ADD);
    printf("* %d - Remove       *\n", MNU_REMOVE);
    printf("* %d - Shrink       *\n", MNU_SHRINK);
    printf("* %d - Print Queue  *\n", MNU_PRINT);
    printf("* %d - Quit Program *\n", MNU_QUIT);
    printf("********************\n");
    printf("Choose your option: ");
    scanf("%d", &opt);

    return opt;
}
