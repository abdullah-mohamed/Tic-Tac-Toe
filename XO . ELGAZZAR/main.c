#include <stdio.h>
#include <stdlib.h>

char board[] = {'*', '*', '*',
                '*', '*', '*',
                '*', '*', '*', '\0'};

int end_game    = 0;
int turn_number = 1;
char turn       = 'X';

void print_board(void);
void input_symbols(void);
void check_row (void);

int main()
{
    printf("Welcome to XO game.\n");
    printf("made by : Abdullah Mohamed Abunar.\n");
    printf("Rules: \n1. Player X starts first.\n2. Enter CAPITAl letters only.\n3. To win, connect 3 horizontal, vertical or Diagonal places.\n");
    printf("To play:\n Enter symbol (X or O) then\n Enter a number between 1 and 9.\n");
    while(end_game == 0){
        print_board();
        input_symbols();
        check_row();
        check_coulmn();
        check_diagonal();
        if (end_game == 1){
            printf("Hard luck player %c.\n", turn);
        }
        if (turn_number == 9 && end_game == 0){
            printf("There is no winner.\n");
            end_game = 1;
        }
    }
    char nothing;
    scanf("%c", &nothing);
    return 0;
}

void print_board (void){
    int i ;
    for (i = 0; i < 10; i++){
        printf("%c\t", board[i]);
        if (i == 2 || i == 5){
            printf("\n");
        }
    }
}


void check_diagonal (void){
    if (((board[0] == board[4] && board[4] == board[8])
        ||(board[2] == board[4] && board[4] == board[6])) && board[4] != '*' ) {
            end_game = 1;
        }
}

void check_coulmn (void){
    int coulmn, spot = 3;
    for (coulmn = 1; coulmn < 4; coulmn++){
        if(board[spot-3] == board[spot] && board[spot] == board[spot+3] && board[spot] != '*'){
            end_game = 1;
        }
            spot += 1;
    }
}


void check_row (void){
     int row, spot = 1;
     for (row = 1; row < 4; row++){
            if (board[spot-1] == board[spot] && board[spot] == board[spot+1] && board[spot] != '*'){
                end_game = 1;
            }
            spot += 3;
        }
}

void input_symbols(void){
     char game;
     int place;
     s:
        printf("\nEnter symbol >> ");
        fflush(stdin);
        scanf("%c", &game);
        if (game == turn){
             printf("Enter place >> ");
             scanf("%d", &place);
             place -= 1;
             if (place < 9 && place >= 0 && board[place] == '*'){
                board[place] = game;
                turn_number++;
                if (turn_number % 2 == 0){
                   turn = 'O';
                }else{
                    turn = 'X';
                }
             }
        }else{
            printf("wrong turn");
            goto s;
        }
}
