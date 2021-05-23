#include "rubiks.h"

int main(int argc, char argv[])
{
    int i = 1;
    FACE **rubiks = create_rubiks();
    char action[2];
    init_rubiks(rubiks);
    display_rubiks(rubiks);

    while (i)
    {
        printf("\n\n---------------------------------------------------------------------------------------------------------\n");
        printf("|   1: Scramble   |   2: Reset   |   3: Blank   |   4: Play   |   5:Fill   |   6: Solve   |   0: Exit   |\n");
        printf("---------------------------------------------------------------------------------------------------------\n");
        scanf("%s", action);
        

        switch (atoi(action))
        {
        case 1:

            printf("Scramble.\n");
            scramble_rubiks(rubiks);
            break;
        case 2:
            printf("Reset.\n");
            init_rubiks(rubiks);
            break;
        case 3:
            printf("Blank.\n");
            blank_rubiks(rubiks);
            break;
        case 4:
            printf("Play.\n");
            play_rubiks(rubiks);
            break;
        case 5:
            printf("Fill.\n");
            //fill_rubiks();
            break;
        case 6:
            printf("Solve.\n");

            break;
        case 0:
            printf("Exit.\n");
            i = 0;
            break;
        default:
            printf("Unknow action.\n");
            break;
        }
        display_rubiks(rubiks);
    }

    free_rubiks(rubiks);

    return 0;
}
