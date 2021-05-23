#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include <time.h>
#include <string.h>


typedef enum { FRONT, BACK, UP, DOWN, RIGHT, LEFT } T_SIDE ;
typedef enum { W, Y, B, G, R, O, LG } T_COLOR ;

typedef struct cell{
    T_COLOR color;
}CELL;

typedef struct face{
    CELL tab_face[3][3];
    T_SIDE name;
    
}FACE;


//FONCTION ENUM TYPE
T_COLOR select_color(char *c);                
T_SIDE side_to_index(char*l);

//REPRESENTATION FUNCTIONS
FACE** create_rubiks();
void init_rubiks(FACE** rub);
int getIndex(FACE **rubiks, T_SIDE side);
void display_rubiks(FACE** rub);      
void blank_rubiks();                 
void fill_rubiks(); // entrée utilisateur F[1][3]R
int play_rubiks(FACE **rub);
void free_rubiks(FACE** rub);        

//MOUVEMENT FUNCTIONS
void horizontal_rotation(FACE **rub, int turns);
void vertical_rotation(FACE **rub, int turns);

int move_rubiks(FACE **rub);
void scramble_rubiks(FACE **rubiks);
void FRONT_rotation(FACE **rub, int turns);
void BACK_rotation(FACE **rub, int turns);
void UP_rotation(FACE **rub, int turns);
void DOWN_rotation(FACE **rub, int turns);
void LEFT_rotation(FACE **rub, int turns);
void RIGHT_rotation(FACE **rub, int turns);
void rotate_face_cells(FACE *face, int turns);
void menu_rotate_rubiks(FACE **rub, int side, int orientation);
int rotate_rubiks(FACE **rub);