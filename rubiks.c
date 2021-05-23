#include "rubiks.h"

T_COLOR select_color(char *a)
{
    if (strcmp(a, "W") == 0)
    {
        return 0;
    }
    if (strcmp(a, "Y") == 0)
    {
        return 1;
    }
    if (strcmp(a, "B") == 0)
    {
        return 2;
    }
    if (strcmp(a, "G") == 0)
    {
        return 3;
    }
    if (strcmp(a, "R") == 0)
    {
        return 4;
    }
    if (strcmp(a, "O") == 0)
    {
        return 5;
    }
}

T_SIDE side_to_index(char *l)
{
    if ((((strcmp(l, "FRONT") == O) || (strcmp(l, "front") == O)) || (strcmp(l, "f") == O)) || (strcmp(l, "F") == O))
    {
        return 0;
    }
    if ((((strcmp(l, "BACK") == O) || (strcmp(l, "back") == O)) || (strcmp(l, "b") == O)) || (strcmp(l, "B") == O))
    {
        return 1;
    }
    if ((((strcmp(l, "UP") == O) || (strcmp(l, "up") == O)) || (strcmp(l, "u") == O)) || (strcmp(l, "U") == O))
    {
        return 2;
    }
    if ((((strcmp(l, "DOWN") == O) || (strcmp(l, "down") == O)) || (strcmp(l, "d") == O)) || (strcmp(l, "D") == O))
    {
        return 3;
    }
    if ((((strcmp(l, "RIGHT") == O) || (strcmp(l, "right") == O)) || (strcmp(l, "r") == O)) || (strcmp(l, "R") == O))
    {
        return 4;
    }
    if ((((strcmp(l, "LEFT") == O) || (strcmp(l, "left") == O)) || (strcmp(l, "l") == O)) || (strcmp(l, "L") == O))
    {
        return 5;
    }
}

char *get_color_name(T_COLOR c)
{
    switch (c)
    {
    case 0:
        return "\033[0;37m0\033[0m"; //https://www.theurbanpenguin.com/4184-2/ pour la doc pour le rapport
    case 1:
        return "\033[0;33m0\033[0m";
    case 2:
        return "\033[0;34m0\033[0m";
    case 3:
        return "\033[0;32m0\033[0m";
    case 4:
        return "\033[0;31m0\033[0m";
    case 5:
        return "\033[0;35m0\033[0m";
    case 6:
        return "X";
    default:
        printf("Unknow color.\n");
        return 0;
    }
}

FACE **create_rubiks()
{
    FACE **rubiks = malloc(sizeof(FACE *) * 6);
    for (int i = 0; i < 6; i++)
    {
        rubiks[i] = malloc(sizeof(FACE));
    }
    return rubiks;
}

int getIndex(FACE **rubiks, T_SIDE side)
{
    for (int i = 0; i < 6; i++)
    {
        if (rubiks[i]->name == side)
        {
            return i;
        }
    }
    return (-1);
}

void init_rubiks(FACE **rub)
{
    int m, n;
    T_SIDE l = FRONT;
    for (int i = 0; i < 6; i++)
    {

        rub[i]->name = l;
        l = l + 1;
        for (m = 0; m < 3; m++)
        {
            for (n = 0; n < 3; n++)
            {
                rub[i]->tab_face[m][n].color = i;
            }
        }
    }
}

void display_rubiks(FACE **rub)
{
    int frontIndex = getIndex(rub, FRONT);
    int rightIndex = getIndex(rub, RIGHT);
    int leftIndex = getIndex(rub, LEFT);
    int upIndex = getIndex(rub, UP);
    int downIndex = getIndex(rub, DOWN);
    int backIndex = getIndex(rub, BACK);

    for (int i = 0; i < 3; i++)
    {
        printf("\t\t\t\t\t");
        printf("    ");
        for (int j = 0; j < 3; j++)
        {
            printf("%s", get_color_name(rub[upIndex]->tab_face[i][j].color));
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++)
    {
        printf("\t\t\t\t\t");
        for (int j = 0; j < 3; j++)
        {
            printf("%s", get_color_name(rub[leftIndex]->tab_face[i][j].color));
        }
        printf("|");

        for (int j = 0; j < 3; j++)
        {
            printf("%s", get_color_name(rub[frontIndex]->tab_face[i][j].color));
        }
        printf("|");

        for (int j = 0; j < 3; j++)
        {
            printf("%s", get_color_name(rub[rightIndex]->tab_face[i][j].color));
        }
        printf("|");

        for (int j = 0; j < 3; j++)
        {
            printf("%s", get_color_name(rub[backIndex]->tab_face[i][j].color));
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++)
    {
        printf("\t\t\t\t\t");
        printf("    ");
        for (int j = 0; j < 3; j++)
        {
            printf("%s", get_color_name(rub[downIndex]->tab_face[i][j].color));
        }
        printf("\n");
    }

    /*int ordre[6] = {2, 5, 0, 4, 1, 3};
    for (int i = 0; i < 3; i++)
    {
        printf("    %s%s%s\n", get_color_name(rub[2]->tab_face[i][0].color),
               get_color_name(rub[2]->tab_face[i][1].color),
               get_color_name(rub[2]->tab_face[i][2].color));
    }
    for (int i = 0; i < 3; i++)
    {
        for (int k = 1; k < 5; k++)
        {
            int j = ordre[k];
            printf("%s%s%s ", get_color_name(rub[j]->tab_face[i][0].color),
                   get_color_name(rub[j]->tab_face[i][1].color),
                   get_color_name(rub[j]->tab_face[i][2].color));
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++)
    {
        printf("    %s%s%s\n", get_color_name(rub[3]->tab_face[i][0].color),
               get_color_name(rub[3]->tab_face[i][1].color),
               get_color_name(rub[3]->tab_face[i][2].color));
    }*/
}

void blank_rubiks(FACE **rub)
{
    int m, n;
    T_SIDE l = FRONT;
    for (int i = 0; i < 6; i++)
    {
        rub[i]->name = l;
        l = l + 1;
        for (m = 0; m < 3; m++)
        {
            for (n = 0; n < 3; n++)
            {
                rub[i]->tab_face[m][n].color = 6;
            }
        }
    }
}

void fill_rubiks();

void rotate_face_cells(FACE *face, int turns)
{
    for (int i = 0; i < turns; i++)
    {
        CELL tmpCell1 = face->tab_face[0][0];
        CELL tmpCell2 = face->tab_face[0][1];
        face->tab_face[0][0] = face->tab_face[0][2];
        face->tab_face[0][1] = face->tab_face[1][2];
        face->tab_face[0][2] = face->tab_face[2][2];
        face->tab_face[1][2] = face->tab_face[2][1];
        face->tab_face[2][2] = face->tab_face[2][0];
        face->tab_face[2][1] = face->tab_face[1][0];
        face->tab_face[2][0] = tmpCell1;
        face->tab_face[1][0] = tmpCell2;
    }
}

void FRONT_rotation(FACE **rub, int turns)
{
    int frontIndex = getIndex(rub, FRONT);
    int rightIndex = getIndex(rub, RIGHT);
    int leftIndex = getIndex(rub, LEFT);
    int upIndex = getIndex(rub, UP);
    int downIndex = getIndex(rub, DOWN);
    int backIndex = getIndex(rub, BACK);

    CELL tmpCell1;
    CELL tmpCell2;
    CELL tmpCell3;

    for (int i = 0; i < turns; i++)
    {
        tmpCell1 = rub[upIndex]->tab_face[2][0];
        tmpCell2 = rub[upIndex]->tab_face[2][1];
        tmpCell3 = rub[upIndex]->tab_face[2][2];
        rub[upIndex]->tab_face[2][0] = rub[rightIndex]->tab_face[0][0];
        rub[upIndex]->tab_face[2][1] = rub[rightIndex]->tab_face[1][0];
        rub[upIndex]->tab_face[2][2] = rub[rightIndex]->tab_face[2][0];
        rub[rightIndex]->tab_face[0][0] = rub[downIndex]->tab_face[0][2];
        rub[rightIndex]->tab_face[1][0] = rub[downIndex]->tab_face[0][1];
        rub[rightIndex]->tab_face[2][0] = rub[downIndex]->tab_face[0][0];
        rub[downIndex]->tab_face[0][2] = rub[leftIndex]->tab_face[2][2];
        rub[downIndex]->tab_face[0][1] = rub[leftIndex]->tab_face[1][2];
        rub[downIndex]->tab_face[0][0] = rub[leftIndex]->tab_face[0][2];
        rub[leftIndex]->tab_face[2][2] = tmpCell1;
        rub[leftIndex]->tab_face[1][2] = tmpCell2;
        rub[leftIndex]->tab_face[0][2] = tmpCell3;
        rotate_face_cells(rub[frontIndex], 1);
        printf("Turned front for %d/%d turns. \n", i + 1, turns);
    }
    /*  int a[3] = {0, 0, 0};
    int b[3] = {0, 0, 0};
    int c[3] = {0, 0, 0};
    int d[3] = {0, 0, 0};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[j] = rub[i + 2]->tab_face[2 - 2 * i][j].color;
            b[j] = rub[i + 4]->tab_face[j][2 * i].color;
        }
        for (int j = 0; j < 3; j++)
        {
            rub[i + 4]->tab_face[j][2 * i].color = a[j];
            rub[i + 2]->tab_face[2 - 2 * i][j].color = b[j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        c[i] = rub[0]->tab_face[1 + i][i].color;
        d[i] = rub[0]->tab_face[i][1 + i].color;
    }

    for (int i = 0; i < 2; i++)
    {
        rub[0]->tab_face[2 - i][1 - i].color = c[i];
        rub[0]->tab_face[1 - i][2 - i].color = d[i];
    }

    for (int i = 0; i < 2; i++)
    {
        c[i] = rub[0]->tab_face[0][i * 2].color;
        d[i] = rub[0]->tab_face[2][i * 2].color;
    }
    for (int i = 0; i < 2; i++)
    {
        rub[0]->tab_face[0][2 - i * 2].color = c[i];
        rub[0]->tab_face[2][2 - i * 2].color = d[i];
    }
    printf("1: Clockwise        2: Anticlockwise\n");
    char value[2];
    if (scanf("%s", value) == 0)
    {
        printf("Error scanf.\n");
        return;
    }
    switch (atoi(value))
    {
    case 1:

        for (int i = 0; i < 3; i++)
        {
            a[i] = rub[2]->tab_face[2][i].color;
            b[i] = rub[3]->tab_face[0][i].color;
        }

        for (int i = 0; i < 3; i++)
        {
            rub[2]->tab_face[2][i].color = b[i];
            rub[3]->tab_face[0][i].color = a[i];
        }

        rub[0]->tab_face[0][1].color = c[0];
        rub[0]->tab_face[2][1].color = d[1];
        rub[0]->tab_face[0][0].color = d[0];
        rub[0]->tab_face[2][2].color = c[1];
        break;

    case 2:
        for (int i = 0; i < 3; i++)
        {
            a[i] = rub[4]->tab_face[i][0].color;
            b[i] = rub[5]->tab_face[i][2].color;
        }
        for (int i = 0; i < 3; i++)
        {
            rub[4]->tab_face[i][0].color = b[i];
            rub[5]->tab_face[i][2].color = a[i];
        }
        rub[0]->tab_face[1][2].color = c[1];
        rub[0]->tab_face[1][0].color = d[0];
        rub[0]->tab_face[2][0].color = c[0];
        rub[0]->tab_face[0][2].color = d[1];
    default:
        printf("PBM\n");
        break;
    }*/
}

void BACK_rotation(FACE **rub, int turns)
{
    int frontIndex = getIndex(rub, FRONT);
    int rightIndex = getIndex(rub, RIGHT);
    int leftIndex = getIndex(rub, LEFT);
    int upIndex = getIndex(rub, UP);
    int downIndex = getIndex(rub, DOWN);
    int backIndex = getIndex(rub, BACK);

    CELL tmpCell1;
    CELL tmpCell2;
    CELL tmpCell3;

    for (int i = 0; i < turns; i++)
    {
        tmpCell1 = rub[upIndex]->tab_face[0][2];
        tmpCell2 = rub[upIndex]->tab_face[0][1];
        tmpCell3 = rub[upIndex]->tab_face[0][0];
        rub[upIndex]->tab_face[0][2] = rub[leftIndex]->tab_face[0][0];
        rub[upIndex]->tab_face[0][1] = rub[leftIndex]->tab_face[1][0];
        rub[upIndex]->tab_face[0][0] = rub[leftIndex]->tab_face[2][0];
        rub[leftIndex]->tab_face[0][0] = rub[downIndex]->tab_face[2][0];
        rub[leftIndex]->tab_face[1][0] = rub[downIndex]->tab_face[2][1];
        rub[leftIndex]->tab_face[2][0] = rub[downIndex]->tab_face[2][2];
        rub[downIndex]->tab_face[2][0] = rub[rightIndex]->tab_face[2][2];
        rub[downIndex]->tab_face[2][1] = rub[rightIndex]->tab_face[1][2];
        rub[downIndex]->tab_face[2][2] = rub[rightIndex]->tab_face[0][2];
        rub[rightIndex]->tab_face[2][2] = tmpCell1;
        rub[rightIndex]->tab_face[1][2] = tmpCell2;
        rub[rightIndex]->tab_face[0][2] = tmpCell3;
        rotate_face_cells(rub[backIndex], 1);

        printf("Turned back for %d/%d turns. \n", i + 1, turns);
    }
}

void UP_rotation(FACE **rub, int turns)
{
    int frontIndex = getIndex(rub, FRONT);
    int rightIndex = getIndex(rub, RIGHT);
    int leftIndex = getIndex(rub, LEFT);
    int upIndex = getIndex(rub, UP);
    int downIndex = getIndex(rub, DOWN);
    int backIndex = getIndex(rub, BACK);

    CELL tmpCell1;
    CELL tmpCell2;
    CELL tmpCell3;

    for (int i = 0; i < turns; i++)
    {
        tmpCell1 = rub[backIndex]->tab_face[0][2];
        tmpCell2 = rub[backIndex]->tab_face[0][1];
        tmpCell3 = rub[backIndex]->tab_face[0][0];
        rub[backIndex]->tab_face[0][2] = rub[rightIndex]->tab_face[0][2];
        rub[backIndex]->tab_face[0][1] = rub[rightIndex]->tab_face[0][1];
        rub[backIndex]->tab_face[0][0] = rub[rightIndex]->tab_face[0][0];
        rub[rightIndex]->tab_face[0][2] = rub[frontIndex]->tab_face[0][2];
        rub[rightIndex]->tab_face[0][1] = rub[frontIndex]->tab_face[0][1];
        rub[rightIndex]->tab_face[0][0] = rub[frontIndex]->tab_face[0][0];
        rub[frontIndex]->tab_face[0][2] = rub[leftIndex]->tab_face[0][2];
        rub[frontIndex]->tab_face[0][1] = rub[leftIndex]->tab_face[0][1];
        rub[frontIndex]->tab_face[0][0] = rub[leftIndex]->tab_face[0][0];
        rub[leftIndex]->tab_face[0][2] = tmpCell1;
        rub[leftIndex]->tab_face[0][1] = tmpCell2;
        rub[leftIndex]->tab_face[0][0] = tmpCell3;
        rotate_face_cells(rub[upIndex], 1);

        printf("Turned up for %d/%d turns. \n", i + 1, turns);
    }
}

void DOWN_rotation(FACE **rub, int turns)
{
    int frontIndex = getIndex(rub, FRONT);
    int rightIndex = getIndex(rub, RIGHT);
    int leftIndex = getIndex(rub, LEFT);
    int upIndex = getIndex(rub, UP);
    int downIndex = getIndex(rub, DOWN);
    int backIndex = getIndex(rub, BACK);

    CELL tmpCell1;
    CELL tmpCell2;
    CELL tmpCell3;

    for (int i = 0; i < turns; i++)
    {
        tmpCell1 = rub[frontIndex]->tab_face[2][0];
        tmpCell2 = rub[frontIndex]->tab_face[2][1];
        tmpCell3 = rub[frontIndex]->tab_face[2][2];
        rub[frontIndex]->tab_face[2][0] = rub[rightIndex]->tab_face[2][0];
        rub[frontIndex]->tab_face[2][1] = rub[rightIndex]->tab_face[2][1];
        rub[frontIndex]->tab_face[2][2] = rub[rightIndex]->tab_face[2][2];
        rub[rightIndex]->tab_face[2][0] = rub[backIndex]->tab_face[2][0];
        rub[rightIndex]->tab_face[2][1] = rub[backIndex]->tab_face[2][1];
        rub[rightIndex]->tab_face[2][2] = rub[backIndex]->tab_face[2][2];
        rub[backIndex]->tab_face[2][0] = rub[leftIndex]->tab_face[2][0];
        rub[backIndex]->tab_face[2][1] = rub[leftIndex]->tab_face[2][1];
        rub[backIndex]->tab_face[2][2] = rub[leftIndex]->tab_face[2][2];
        rub[leftIndex]->tab_face[2][0] = tmpCell1;
        rub[leftIndex]->tab_face[2][1] = tmpCell2;
        rub[leftIndex]->tab_face[2][2] = tmpCell3;
        rotate_face_cells(rub[downIndex], 1);

        printf("Turned down for %d/%d turns. \n", i + 1, turns);
    }
}

void LEFT_rotation(FACE **rub, int turns)
{
    int frontIndex = getIndex(rub, FRONT);
    int rightIndex = getIndex(rub, RIGHT);
    int leftIndex = getIndex(rub, LEFT);
    int upIndex = getIndex(rub, UP);
    int downIndex = getIndex(rub, DOWN);
    int backIndex = getIndex(rub, BACK);

    CELL tmpCell1;
    CELL tmpCell2;
    CELL tmpCell3;

    for (int i = 0; i < turns; i++)
    {
        tmpCell1 = rub[upIndex]->tab_face[0][0];
        tmpCell2 = rub[upIndex]->tab_face[1][0];
        tmpCell3 = rub[upIndex]->tab_face[2][0];
        rub[upIndex]->tab_face[0][0] = rub[frontIndex]->tab_face[0][0];
        rub[upIndex]->tab_face[1][0] = rub[frontIndex]->tab_face[1][0];
        rub[upIndex]->tab_face[2][0] = rub[frontIndex]->tab_face[2][0];
        rub[frontIndex]->tab_face[0][0] = rub[downIndex]->tab_face[0][0];
        rub[frontIndex]->tab_face[1][0] = rub[downIndex]->tab_face[1][0];
        rub[frontIndex]->tab_face[2][0] = rub[downIndex]->tab_face[2][0];
        rub[downIndex]->tab_face[0][0] = rub[backIndex]->tab_face[0][2];
        rub[downIndex]->tab_face[1][0] = rub[backIndex]->tab_face[1][2];
        rub[downIndex]->tab_face[2][0] = rub[backIndex]->tab_face[2][2];
        rub[backIndex]->tab_face[0][2] = tmpCell1;
        rub[backIndex]->tab_face[1][2] = tmpCell2;
        rub[backIndex]->tab_face[2][2] = tmpCell3;
        rotate_face_cells(rub[leftIndex], 1);

        printf("Turned left for %d/%d turns. \n", i + 1, turns);
    }
}

void RIGHT_rotation(FACE **rub, int turns)
{
    int frontIndex = getIndex(rub, FRONT);
    int rightIndex = getIndex(rub, RIGHT);
    int leftIndex = getIndex(rub, LEFT);
    int upIndex = getIndex(rub, UP);
    int downIndex = getIndex(rub, DOWN);
    int backIndex = getIndex(rub, BACK);

    CELL tmpCell1;
    CELL tmpCell2;
    CELL tmpCell3;

    for (int i = 0; i < turns; i++)
    {
        tmpCell1 = rub[upIndex]->tab_face[2][2];
        tmpCell2 = rub[upIndex]->tab_face[1][2];
        tmpCell3 = rub[upIndex]->tab_face[0][2];
        rub[upIndex]->tab_face[2][2] = rub[backIndex]->tab_face[0][0];
        rub[upIndex]->tab_face[1][2] = rub[backIndex]->tab_face[1][0];
        rub[upIndex]->tab_face[0][2] = rub[backIndex]->tab_face[2][0];
        rub[backIndex]->tab_face[0][0] = rub[downIndex]->tab_face[2][2];
        rub[backIndex]->tab_face[1][0] = rub[downIndex]->tab_face[1][2];
        rub[backIndex]->tab_face[2][0] = rub[downIndex]->tab_face[0][2];
        rub[downIndex]->tab_face[2][2] = rub[frontIndex]->tab_face[2][2];
        rub[downIndex]->tab_face[1][2] = rub[frontIndex]->tab_face[1][2];
        rub[downIndex]->tab_face[0][2] = rub[frontIndex]->tab_face[0][2];
        rub[frontIndex]->tab_face[2][2] = tmpCell1;
        rub[frontIndex]->tab_face[1][2] = tmpCell2;
        rub[frontIndex]->tab_face[0][2] = tmpCell3;
        rotate_face_cells(rub[rightIndex], 1);

        printf("Turned right for %d/%d turns. \n", i + 1, turns);
    }
}

int play_rubiks(FACE **rub)
{
    int i = 1;
    char action[2];
    while (i)
    {
        printf("\n\n----------------------------------------------------------\n");
        printf("|   1: Turn face   |   2: Rotate rubiks   |   0: Return   |\n");
        printf("-----------------------------------------------------------\n");

        scanf("%s", action);

        switch (atoi(action))
        {
        case 1:
            move_rubiks(rub);
            break;
        case 2:
            rotate_rubiks(rub);
            break;
        case 0:
            printf("Return.\n");
            i = 0;
            return 0;
        default:
            printf("Unknow action.\n");
            break;
        }
        display_rubiks(rub);
    }
}

int move_rubiks(FACE **rub)
{
    int i = 1;
    int action;
    int clock;
    int turns = 1;

    while (i)
    {
        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("|   1: FRONT   |   2: BACK   |   3: LEFT   |   4: RIGHT   |   5: UP   |   6: DOWN   |   0: Return   |\n");
        printf("-----------------------------------------------------------------------------------------------------\n");
        scanf("%d", &action);
        if ((action) < 1 || (action) > 6)
        {
            return 0;
        }
        printf("----------------------------------------------------------\n");
        printf("|   1: Clockwise   |   2: Anticlockwise  |   0: Return   |\n");
        printf("----------------------------------------------------------\n");
        scanf("%d", &clock);
        if ((clock) == 2)
        {
            turns = 3;
        }
        else if ((clock) != 1 && (clock) != 2)
        {
            return 0;
        }
        switch ((action))
        {
        case 1:
            FRONT_rotation(rub, turns);
            break;
        case 2:
            BACK_rotation(rub, turns);
            break;
        case 3:
            UP_rotation(rub, turns);
            break;
        case 4:
            DOWN_rotation(rub, turns);
            break;
        case 5:
            RIGHT_rotation(rub, turns);
            break;
        case 6:
            LEFT_rotation(rub, turns);
            break;
        default:
            printf("Unknow action.\n");
            break;
        }
        display_rubiks(rub);
    }
}

void vertical_rotation(FACE **rub, int turns)
{
    int frontIndex = 0;
    int rightIndex = 0;
    int leftIndex = 0;
    int backIndex = 0;
    int upIndex = 0;
    int downIndex = 0;
    for (int i = 0; i < turns; i++)
    {
        frontIndex = getIndex(rub, FRONT);
        rightIndex = getIndex(rub, RIGHT);
        leftIndex = getIndex(rub, LEFT);
        backIndex = getIndex(rub, BACK);
        upIndex = getIndex(rub, UP);
        downIndex = getIndex(rub, DOWN);
        rotate_face_cells(rub[rightIndex], 3);
        rotate_face_cells(rub[leftIndex], 1);
        rotate_face_cells(rub[upIndex], 2);
        rub[frontIndex]->name = UP;
        rub[downIndex]->name = FRONT;
        rub[backIndex]->name = DOWN;
        rub[upIndex]->name = BACK;
        printf("Rotate rubiks up for %d/%d turns. \n", i + 1, turns);
    }
    display_rubiks(rub);
}

void horizontal_rotation(FACE **rub, int turns)
{
    int frontIndex = 0;
    int rightIndex = 0;
    int leftIndex = 0;
    int backIndex = 0;
    int upIndex = 0;
    int downIndex = 0;
    for (int i = 0; i < turns; i++)
    {
        frontIndex = getIndex(rub, FRONT);
        rightIndex = getIndex(rub, RIGHT);
        leftIndex = getIndex(rub, LEFT);
        backIndex = getIndex(rub, BACK);
        upIndex = getIndex(rub, UP);
        downIndex = getIndex(rub, DOWN);
        rotate_face_cells(rub[upIndex], 1);
        rotate_face_cells(rub[downIndex], 3);
        rub[frontIndex]->name = RIGHT;
        rub[leftIndex]->name = FRONT;
        rub[backIndex]->name = LEFT;
        rub[rightIndex]->name = BACK;

        printf("Rotate right for %d/%d turns. \n", i + 1, turns);
    }
    display_rubiks(rub);
}

void menu_rotate_rubiks(FACE **rub, int side, int orientation)
{
    int turns = 1;
    if (orientation == 2)
    {
        turns = 3;
    }
    if (side == 1)
    {
        return vertical_rotation(rub, turns);
    }
    else
    {
        return horizontal_rotation(rub, turns);
    }
}

int rotate_rubiks(FACE **rub)
{
    int i = 1;
    char action[2];
    char ori[2];
    while (i)
    {
        printf("-------------------------------------------------------\n");
        printf("|   1: Vertical   |   2: Horizontal   |   0: Return   |\n");
        printf("-------------------------------------------------------\n");
        scanf("%s", action);
        switch (atoi(action))
        {
        case 1:
            printf("---------------------------------------------------\n");
            printf("|   1: Up Way   |   2: Down Way   |   0: Return   |\n");
            printf("---------------------------------------------------\n");
            scanf("%s", ori);
            menu_rotate_rubiks(rub, atoi(action), atoi(ori));
            break;
        case 2:
            printf("------------------------------------------------------\n");
            printf("|   1: Right Way   |   2: Left Way   |   0: Return   |\n");
            printf("------------------------------------------------------\n");
            scanf("%s", ori);
            menu_rotate_rubiks(rub, atoi(action), atoi(ori));
            break;
        case 0:
            printf("Return.\n");
            i = 0;
            return 0;
        default:
            printf("Unknow action.\n");
            break;
        }
    }
}

void scramble_rubiks(FACE **rub)
{
    for (int i = 0; i < 50; i++)
    {
        int random = rand() % 6;
        switch (random)
        {
        case 1:
            FRONT_rotation(rub, 1);
            break;
        case 2:
            BACK_rotation(rub, 1);
            break;
        case 3:
            UP_rotation(rub, 1);
            break;
        case 4:
            DOWN_rotation(rub, 1);
            break;
        case 5:
            RIGHT_rotation(rub, 1);
            break;
        case 6:
            LEFT_rotation(rub, 1);
            break;
        default:
            break;
        }
    }
}

void free_rubiks(FACE **rub)
{
    for (int i = 0; i < 6; i++)
    {
        free(rub[i]);
    }
    free(rub);
}