#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


void dashboard();
int mainmenu();
void newgame();
int newgame_menu();
void easy();
void medium();
void hard();
void gameplay(int sudoku[9][9]);
int functions();
void display(int sudoku[9][9]);
int isvalid(int sudoku[9][9], int r, int c, int num, int l);
void insert_undo(int sudoku[9][9],int row,int col,int previous,int current);
void undo(int sudoku[9][9]);
void insert_redo(int sudoku[9][9],int row,int col,int previous,int current);
void redo(int sudoku[9][9]);
void sudoku_answer(int sudoku[9][9]);
int solve_sudoku(int sudoku[9][9]);
int number_unassigned(int sudoku[9][9],int *row, int *col);
int is_safe(int sudoku[9][9],int n, int r, int c);
int gamerules();
void exit_sudoku();


int undo_row[200],undo_col[200],undo_previous[200],undo_current[200];
int redo_row[200],redo_col[200],redo_previous[200],redo_current[200];
int undo_top=-1,redo_top=-1;
int check_row[50];
int check_col[50];

int main()
{   
    while(1)
    {
        dashboard();
        int choice= mainmenu(),choice_gamerules;

        switch (choice)
        {
            case 1:
                newgame();
                printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
                getch();
                break;

            case 2:
                while(1)
                {
                    choice_gamerules = gamerules();
                    switch(choice_gamerules)
                    {
                        case 1:
                            main();
                            printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                            printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
                            getch();
                            break;
                        case 2:
                            exit_sudoku();
                            break;
                        default:
                            printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                            printf("\t\t\t\t\t\t\t\t!!!!!!!!!!         YOU HAVE ENTERED INVALID CHOICE        !!!!!!!!!!\n");
                            printf("\t\t\t\t\t\t\t\t!!!!!!!!!!    PLEASE ENTER YOUR CHOICE BETWEEN 1 and 2    !!!!!!!!!!\n");
                            printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                            printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
                            getch();
                            break;
                    }
                }

            case 3:
                exit_sudoku();
                break;
            default:
                printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\t\t\t\t\t\t\t\t!!!!!!!!!!         YOU HAVE ENTERED INVALID CHOICE        !!!!!!!!!!\n");
                printf("\t\t\t\t\t\t\t\t!!!!!!!!!!     PLEASE ENTER YOUR CHOICE BETWEEN 1 TO 3    !!!!!!!!!!\n");
                printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
                getch();
                break;
        }
    }
    return 0;
}



void dashboard()
{
    system("cls");
    printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t\t\t\t\t\t\t||                               _           _                    ||\n");
    printf("\t\t\t\t\t\t\t\t||                              | |         | | __                ||  \n");
    printf("\t\t\t\t\t\t\t\t||          ____   _   _    ____| |   ___   | |/ /  _   _         ||  \n");
    printf("\t\t\t\t\t\t\t\t||         / ___| | | | |  /  _   |  / _ \\  |   /  | | | |        ||  \n");
    printf("\t\t\t\t\t\t\t\t||         \\___ \\ \\ |_| | |  (_)  | | (_) | |   \\  \\ |_| |        ||  \n");
    printf("\t\t\t\t\t\t\t\t||         |____/  \\____|  \\______|  \\___/  |_|\\_\\  \\____|        ||  \n");
    printf("\t\t\t\t\t\t\t\t||                                                                ||  ");
    printf("\n\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t\t\t\t||                        -: CODE BY :-                           ||  \n");
    printf("\t\t\t\t\t\t\t\t||              20BCE081     20BCE082    20BCE157                 ||     \n");
    printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
} 

int mainmenu()
{
    int choice;
    printf("\n\t\t\t\t\t\t\t\t********************************************************************\n");
    printf("\t\t\t\t\t\t\t\t||                          MAIN MENU                             ||");
    printf("\n\t\t\t\t\t\t\t\t********************************************************************\n");
    printf("\t\t\t\t\t\t\t\t||                    1. Play a New Game                          ||\n");
    printf("\t\t\t\t\t\t\t\t||                    2. Show Game Rules                          ||\n");
    printf("\t\t\t\t\t\t\t\t||                    3. Exit the Game                            ||\n");
    printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t\t\t\t||  ~~> Enter Your Choice : ");
    scanf("%d",&choice);
    return choice;
}

void newgame()
{
    while(1)
    {
        dashboard();
        int choice_difficulty=newgame_menu();
        switch(choice_difficulty)
        {
            case 1:
                easy();
                break;
            case 2:
                medium();
                break;
            case 3:
                hard();
                break;
            case 4:
                main();
                break;
            default:
                printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\t\t\t\t\t\t\t\t!!!!!!!!!!         YOU HAVE ENTERED INVALID CHOICE        !!!!!!!!!!\n");
                printf("\t\t\t\t\t\t\t\t!!!!!!!!!!    PLEASE ENTER YOUR CHOICE BETWEEN 1 to 4     !!!!!!!!!!\n");
                printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
                getch();
                break;
        }
    }
}
int newgame_menu()
{
    int choice_difficulty;
    printf("\n\t\t\t\t\t\t\t\t********************************************************************\n");
    printf("\t\t\t\t\t\t\t\t||                          DIFFICULTY                            ||");
    printf("\n\t\t\t\t\t\t\t\t********************************************************************\n");
    printf("\t\t\t\t\t\t\t\t||                       1. EASY                                  ||\n");
    printf("\t\t\t\t\t\t\t\t||                       2. MEDIUM                                ||\n");
    printf("\t\t\t\t\t\t\t\t||                       3. HARD                                  ||\n");    
    printf("\t\t\t\t\t\t\t\t||                       4. GO BACK TO MAIN MENU                  ||\n");
    printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t\t\t\t||  ~~> Enter Your Choice : ");
    scanf("%d",&choice_difficulty);
    return choice_difficulty;
}
void easy()
{
    int easy1[9][9]={{0,0,0,  0,0,0,  9,0,1},
                     {0,0,0,  2,1,4,  0,5,6},
                     {0,7,0,  0,0,0,  3,8,0},

                     {3,0,0,  0,0,8,  4,1,0},
                     {1,0,0,  4,0,6,  0,0,7},
                     {0,5,4,  9,0,0,  0,0,8},

                     {0,8,7,  0,0,0,  0,6,0},
                     {4,1,0,  3,5,2,  0,0,0},
                     {9,0,2,  0,0,0,  0,0,0}};

    int easy2[9][9]={{0,0,0,  0,5,0,  8,6,1},
                     {0,0,0,  7,9,3,  0,0,0},
                     {0,4,2,  0,0,0,  0,0,0},

                     {0,0,0,  5,0,0,  3,2,4},
                     {8,0,4,  2,0,1,  6,0,9},
                     {6,2,3,  0,0,4,  0,0,0},

                     {0,0,0,  0,0,0,  7,5,0},
                     {0,0,0,  3,8,7,  0,0,0},
                     {7,1,9,  0,2,0,  0,0,0}};

    int easy3[9][9]={{3,0,0,  0,0,0,  9,1,5},
                     {0,0,4,  0,8,0,  0,0,0},
                     {0,0,9,  2,5,0,  0,0,0},

                     {0,6,2,  1,0,7,  0,0,0},
                     {5,7,0,  4,0,2,  0,6,8},
                     {0,0,0,  8,0,5,  7,3,0},

                     {0,0,0,  0,1,9,  2,0,0},
                     {0,0,0,  0,7,0,  5,0,0},
                     {1,8,7,  0,0,0,  0,0,6}};

    int easy4[9][9]={{7,9,2,  0,3,0,  0,0,0},
                     {0,0,0,  0,0,0,  4,8,3},
                     {0,0,0,  5,6,1,  0,0,0},

                     {0,0,0,  0,0,6,  9,5,0},
                     {8,6,0,  7,0,3,  0,2,4},
                     {0,4,9,  2,0,0,  0,0,0},

                     {0,0,0,  1,4,8,  0,0,0},
                     {5,1,3,  0,0,0,  0,0,0},
                     {0,0,0,  0,5,0,  7,1,6}};

    int easy5[9][9]={{5,0,1,  0,0,6,  0,9,0},
                     {2,7,6,  0,3,0,  0,0,0},
                     {0,0,0,  1,7,8,  0,0,0},

                     {0,0,0,  7,0,4,  6,0,0},
                     {0,4,8,  0,0,0,  7,5,0},
                     {0,0,9,  8,0,3,  0,0,0},

                     {0,0,0,  4,6,7,  0,0,0},
                     {0,0,0,  0,8,0,  9,7,1},
                     {0,3,0,  9,0,0,  4,0,2}};
    int random=rand()%5 +1;
    if(random==1) 
        gameplay(easy1);
    else if(random==2)
        gameplay(easy2);
    else if(random==3)
        gameplay(easy3);
    else if(random==4)
        gameplay(easy4);
    else
        gameplay(easy5);
}
void medium()
{
    int medium1[9][9]={{0,5,9,  0,6,0,  0,0,0},
                       {0,0,0,  0,0,0,  2,6,3},
                       {1,0,0,  8,4,3,  0,0,0},

                       {6,8,4,  0,0,0,  0,0,0},
                       {0,0,0,  1,0,9,  0,0,0},
                       {0,0,0,  0,0,0,  3,7,5},

                       {0,0,0,  3,1,5,  0,0,9},
                       {2,7,1,  0,0,0,  0,0,0},
                       {0,0,0,  0,7,0,  6,8,0}};

    int medium2[9][9]={{0,0,0,  0,0,0,  6,5,8},
                       {0,0,0,  8,3,9,  0,0,0},
                       {8,7,1,  0,0,0,  0,0,0},

                       {0,0,0,  0,0,0,  3,1,6},
                       {0,0,6,  2,0,7,  9,0,0},
                       {4,5,9,  0,0,0,  0,0,0},

                       {0,0,0,  0,0,0,  4,9,7},
                       {0,0,0,  5,6,1,  0,0,0},
                       {2,8,3,  0,0,0,  0,0,0}};

    int medium3[9][9]={{0,0,0,  6,0,1,  2,0,0},
                       {3,0,0,  0,0,8,  4,0,0},
                       {9,0,0,  0,0,3,  7,0,0},

                       {0,8,0,  5,4,0,  0,6,0},
                       {0,2,0,  0,0,0,  0,8,0},
                       {0,1,0,  0,7,2,  0,9,0},

                       {0,0,4,  1,0,0,  0,0,3},
                       {0,0,6,  9,0,0,  0,0,5},
                       {0,0,8,  2,0,7,  0,0,0}};

    int medium4[9][9]={{4,0,1,  6,3,9,  0,0,0},
                       {0,0,0,  0,0,0,  4,0,1},
                       {2,0,5,  0,0,0,  0,0,8},

                       {0,0,4,  0,0,0,  0,0,2},
                       {6,0,0,  8,0,7,  0,0,3},
                       {1,0,0,  0,0,0,  5,0,0},

                       {9,0,0,  0,0,0,  8,0,6},
                       {3,0,7,  0,0,0,  0,0,0},
                       {0,0,0,  4,2,1,  3,0,9}};

    int medium5[9][9]={{0,0,0,  0,0,0,  3,6,0},
                       {0,0,0,  9,4,1,  0,0,0},
                       {2,5,4,  0,0,0,  0,0,9},

                       {0,1,0,  0,0,0,  5,2,7},
                       {0,0,0,  6,0,3,  0,0,0},
                       {7,9,8,  0,0,0,  0,4,0},
                     
                       {5,0,0,  0,0,0,  4,1,8},
                       {0,0,0,  7,5,2,  0,0,0},
                       {0,3,6,  0,0,0,  0,0,0}};
    int random=rand()%5 +1;
    if(random==1) 
    gameplay(medium1);
    else if(random==2)
    gameplay(medium2);
    else if(random==3)
    gameplay(medium3);
    else if(random==4)
    gameplay(medium4);
    else
    gameplay(medium5);
}
void hard()
{
    int hard1[9][9]={{0,0,6,  0,0,0,  3,0,0},
                     {0,0,0,  0,0,0,  2,9,4},
                     {7,3,0,  0,0,5,  0,0,0},

                     {0,0,0,  0,3,0,  1,0,6},
                     {0,0,3,  0,8,0,  7,0,0},
                     {4,0,9,  0,6,0,  0,0,0},

                     {0,0,0,  2,0,0,  0,3,8},
                     {5,1,2,  0,0,0,  0,0,0},
                     {0,0,8,  0,0,0,  4,0,0}};

    int hard2[9][9]={{0,0,2,  0,0,0,  8,0,0},
                     {0,0,0,  4,7,2,  0,0,9},
                     {5,0,0,  0,0,0,  3,0,0},

                     {7,0,0,  0,0,0,  4,0,6},
                     {0,0,0,  3,0,1,  0,0,0},
                     {4,0,9,  0,0,0,  0,0,5},

                     {0,0,1,  0,0,0,  0,0,4},
                     {3,0,0,  5,6,9,  0,0,0},
                     {0,0,8,  0,0,0,  2,0,0}};

    int hard3[9][9]={{0,9,6,  0,0,0,  0,0,8},
                     {0,0,0,  0,3,0,  4,0,0},
                     {3,0,0,  0,2,1,  0,0,0},

                     {0,7,5,  0,0,0,  0,0,4},
                     {0,0,0,  2,0,4,  0,0,0},
                     {8,0,0,  0,0,0,  3,9,0},

                     {0,0,0,  4,8,0,  0,0,7},
                     {0,0,2,  0,6,0,  0,0,0},
                     {4,0,0,  0,0,0,  1,5,0}};

    int hard4[9][9]={{0,0,0,  3,0,0,  0,0,0},
                     {1,0,0,  0,9,5,  0,0,2},
                     {4,0,0,  0,7,0,  9,0,0},

                     {0,0,0,  9,0,1,  0,3,0},
                     {0,6,0,  0,0,0,  0,8,0},
                     {0,5,0,  2,0,3,  0,0,0},

                     {0,0,7,  0,4,0,  0,0,6},
                     {3,0,0,  6,2,0,  0,0,5},
                     {0,0,0,  0,0,8,  0,0,0}};

    int hard5[9][9]={{0,0,0,  8,1,6,  0,3,0},
                     {4,0,0,  0,0,0,  0,9,0},
                     {0,0,0,  0,0,0,  0,0,2},

                     {2,0,0,  9,0,3,  0,7,0},
                     {9,0,0,  0,0,0,  0,0,4},
                     {0,3,0,  6,0,5,  0,0,8},
                     
                     {7,0,0,  0,0,0,  0,0,0},
                     {0,6,0,  0,0,0,  0,0,5},
                     {0,1,0,  2,3,7,  0,0,0}};
    int random=rand()%5 +1;
    if(random==1) 
        gameplay(hard1);
    else if(random==2)
        gameplay(hard2);
    else if(random==3)
        gameplay(hard3);
    else if(random==4)
        gameplay(hard4);
    else
        gameplay(hard5);
}
void gameplay(int sudoku[9][9])
{
    int k = 0;
    int reserved_sudoku[9][9];
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            reserved_sudoku[i][j]=sudoku[i][j];
        }
    }

    // for storing fixed positions in two arrays check_Col and check_row
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
          {
            if(sudoku[i][j] != 0)
            {
                check_row[k] = i;
                check_col[k] = j;
                k++;
            }
        }
    }

    int row,column,number,previous;
    while(1)
    {
        dashboard();
        display(sudoku);
        int choice_function=functions();
        switch(choice_function)
        {
            case 1:
                printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\t\t\t\t\t\t\t\t~~> Enter row number(1-9) : ");
                scanf("%d",&row);
                if((row<1 || row>9) )
                {
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t!!!! ENTRE ROW NUMBER BETWEEN 1 T0 9  !!!!\n\n");
                    printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
                    getch();
                    break;
                }

                printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\t\t\t\t\t\t\t\t~~> Enter column number(1-9) : ");                
                scanf("%d",&column);
                if(column<1 || column>9)
                {
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t!!!! ENTRE COLUMN NUMBER BETWEEN 1 T0 9  !!!!\n\n");
                    printf("                                             ~~> Press any key to continue...\n");
                    getch();
                    break;
                }

                printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\t\t\t\t\t\t\t\t~~> Enter number to be inserted (1-9) : ");
                scanf("%d",&number);
                if(number<1 || number>9)
                {
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t!!!! ENTRE THE NUMBER BETWEEN 1 T0 9  !!!!\n\n");
                    printf("\t\t\t\t\t\t\t\t ~~> Press any key to continue...\n");
                    getch();
                    break;
                }

                
                if(!isvalid(sudoku, row-1, column-1, number,k))
                    break;
                
                previous=sudoku[row-1][column-1];
                sudoku[row-1][column-1]=number;
                insert_undo(sudoku,row-1,column-1,previous,number);
                break;

            case 2:
                undo(sudoku);
                break;

            case 3:
                redo(sudoku);
                break;

            case 4:
                while(1)
                {
                    dashboard();
                    display(sudoku);
                    printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("\t\t\t\t\t\t\t\t||                    1. GO BACK TO MAIN MENU                     ||\n");
                    printf("\t\t\t\t\t\t\t\t||                    2. DISPLAY SOLVED SUDOKU                    ||\n");
                    printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("\t\t\t\t\t\t\t\t||  ~~> Enter Your Choice : ");
                    int choice_quit ;
                    scanf("%d",&choice_quit);
                    printf("\n");
                    
                    switch (choice_quit)
                    {
                        case 1:
                            main();
                            printf("\n\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                            printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
                            getch();
                            break;
                        case 2:
                            sudoku_answer(reserved_sudoku);
                            break;                       
                        default:
                            printf("\n\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                            printf("\t\t\t\t\t\t\t\t!!!!!!!!!!         YOU HAVE ENTERED INVALID CHOICE        !!!!!!!!!!\n");
                            printf("\t\t\t\t\t\t\t\t!!!!!!!!!!    PLEASE ENTER YOUR CHOICE BETWEEN 1 and 2    !!!!!!!!!!\n");
                            printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                            printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
                            getch();
                            break;
                    }
                }
                break;

            default :
                printf("\n\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\t\t\t\t\t\t\t\t!!!!!!!!!!         YOU HAVE ENTERED INVALID CHOICE        !!!!!!!!!!\n");
                printf("\t\t\t\t\t\t\t\t!!!!!!!!!!    PLEASE ENTER YOUR CHOICE BETWEEN 1 to 4     !!!!!!!!!!\n");
                printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
                getch();
                break;
        }
    }
}
int functions()
{
    int choice_function;    
    printf("\n\t\t\t\t\t\t\t\t\t  ***********************************************\n");
    printf("\t\t\t\t\t\t\t\t\t  ||                FUNCTIONS                  ||");
    printf("\n\t\t\t\t\t\t\t\t\t  ***********************************************\n");
    printf("\t\t\t\t\t\t\t\t\t  ||           1. ADD NUMBER                   ||\n");
    printf("\t\t\t\t\t\t\t\t\t  ||           2. UNDO                         ||\n");
    printf("\t\t\t\t\t\t\t\t\t  ||           3. REDO                         ||\n");    
    printf("\t\t\t\t\t\t\t\t\t  ||           4. QUIT CURRENT GAME            ||\n");
    printf("\t\t\t\t\t\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t\t\t\t\t  ||  ~~> Enter Your Choice : ");
    scanf("%d",&choice_function);
    return choice_function;
}
void display(int sudoku[9][9])
{
    for(int i=0;i<9;i++)
    {
        if(i%3==0)
            printf("\t\t\t\t\t\t\t\t\t\t  ||=======||=======||=======||\n");
        for(int j=0;j<9;j++)
        {
            if(j%3==0)
            {
                if(j==0) printf("\t\t\t\t\t\t\t\t\t\t  ||");
                else printf(" ||");
            }
            if(sudoku[i][j]==0)
            {
                printf(" .");
            }
            else{
                printf(" %d", sudoku[i][j]);
            }
            if(j==8)
            printf(" ||");
        }
        printf("\n");
    }
    printf("\t\t\t\t\t\t\t\t\t\t  ||=======||=======||=======||\n");
}

int isvalid(int sudoku[9][9], int r, int c, int num, int l)
{
    //1. check for use fixed position ?
    for(int i=0;i<l;i++)
    {
        if((check_row[i] == r) && (check_col[i] == c))
        {
            printf("You can not use fixed position...!\n");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t!!!!  You can not use fixed position   !!!!\n\n");
            printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
            getch();
            return 0;
        }
    }

    //2. check for position :
    //checking in row
    for(int i=0; i<9; i++)
    {
        //there is a cell with same value
        if(sudoku[r][i] == num)
        {
            printf("\n\t\t\t\t\t\t\t\t\t\t\t!!!!  %d already available in this row   !!!!\n\n",num);
            printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
            getch();
            return 0;
        }
    }

    //checking column
    for(int i=0; i<9; i++)
    {
        //there is a cell with the value equal to i
        if(sudoku[i][c] == num)
        {
            printf("\n\t\t\t\t\t\t\t\t\t\t\t!!!!   %d already available in this column   !!!!\n\n",num);
            printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
            getch();
            return 0;
        }
    }

    //checking sub matrix
    int row_start = (r/3)*3;
    int col_start = (c/3)*3;
    for(int i=row_start; i<row_start+3; i++)
    {
        for(int j=col_start; j<col_start+3; j++)
        {
            if(sudoku[i][j] == num)
            {
                printf("\n\t\t\t\t\t\t\t\t\t\t\t!!!!  %d already available in in corresponding 3x3 matrix  !!!!\n\n",num);
                printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
                getch();
                return 0;
            }
        }
    }

}

void insert_undo(int sudoku[9][9],int row,int col,int previous,int current)
{ 
    undo_top++;
    undo_row[undo_top]=row;
    undo_col[undo_top]=col;
    undo_previous[undo_top]=previous;
    undo_current[undo_top]=current; 
}
void undo(int sudoku[9][9])
{
    if(undo_top==-1)
    {
        printf("\n\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t\t\t\t!!!!!!!!!!         FIRST OF ALL ADD ANY NUMBER        !!!!!!!!!!\n");
        printf("\t\t\t\t\t\t\t\t!!!!!!!!! THEN ONLY YOU CAN ABLE TO DO UNDO OPERATION  !!!!!!!!!\n");
        printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
        getch();
    }
    sudoku[undo_row[undo_top]][undo_col[undo_top]]=undo_previous[undo_top];    
    insert_redo(sudoku,undo_row[undo_top],undo_col[undo_top],undo_previous[undo_top],undo_current[undo_top]);
    undo_top--;
}
void insert_redo(int sudoku[9][9],int row,int col,int previous,int current)
{
    redo_top++;
    redo_row[redo_top]=row;
    redo_col[redo_top]=col;
    redo_previous[redo_top]=previous;
    redo_current[redo_top]=current;
}
void redo(int sudoku[9][9])
{
    if(redo_top==-1)
    {
        printf("\n\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t\t\t\t!!!!!!!!!!         FIRST OF ALL DO UNDO OPERATION         !!!!!!!!!!\n");
        printf("\t\t\t\t\t\t\t\t!!!!!!!!!    THEN ONLY YOU CAN ABLE TO DO REDO OPERATION   !!!!!!!!!\n");
        printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
        getch();
        return;
    }
    else
    {
    sudoku[redo_row[redo_top]][redo_col[redo_top]]=redo_current[redo_top];
    insert_undo(sudoku,redo_row[redo_top],redo_col[redo_top],redo_previous[redo_top],redo_current[redo_top]);
    redo_top--;
    }  
}
void sudoku_answer(int sudoku[9][9])
{
    if (solve_sudoku(sudoku))
    {
        display(sudoku);
        printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
        getch();
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t\t\t\t!!!!!!!!!!             SOLUTION IS NOT POSSIBLE           !!!!!!!!!!\n");
        printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t\t\t\t~~> Press any key to continue...\n");
        getch();
    }
}
int solve_sudoku(int sudoku[9][9])//function to solve sudoku using backtracking
{
    int row , col , n , i;
    //if all cells are assigned then the sudoku is already solved
    //pass by reference because number_unassigned will change the values of row and col
    if(number_unassigned(sudoku,&row, &col) == 0)
        return 1;
    //number between 1 to 9
    for(i=1;i<=9;i++)
    {  /*if we can assign i to the cell or not_the cell is sudoku[row][col]*/
        if(is_safe(sudoku,i, row, col))
        {
            sudoku[row][col] = i;  //backtracking
            
            if(solve_sudoku(sudoku))
                return 1;
            //if we can't proceed with this solution
            //reassign the cell
            sudoku[row][col]=0;
        }
    }
    return 0;
}
int number_unassigned(int sudoku[9][9],int *row, int *col) 
/*function to check if all cells are assigned or not if there is any unassigned cell row and col accordingly*/
{
    int num_unassign = 0;
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            //cell is unassigned
            if(sudoku[i][j] == 0)
            {
                //changing the values of row and col
                *row = i;
                *col = j;
                //there is one or more unassigned cells
                num_unassign = 1;
                return num_unassign;
            }
        }
    }
    return num_unassign;
}
int is_safe(int sudoku[9][9],int n, int r, int c)
/*function to check if we can put a value in a paticular cell or not */
{
    int i,j;
    for(i=0;i<9;i++)  //checking in row
    {
        if(sudoku[r][i] == n)  //there is a cell with same value
            return 0;
    }
    for(i=0;i<9;i++)  //checking column
    {
        if(sudoku[i][c] == n)  //there is a cell with the value equal to i
            return 0;
    }
    //checking sub matrix
    int row_start = (r/3)*3;
    int col_start = (c/3)*3;
    for(i=row_start;i<row_start+3;i++)
    {
        for(j=col_start;j<col_start+3;j++)
        {
            if(sudoku[i][j]==n)
                return 0;
        }
    }
    return 1;
}


int gamerules()
{
    dashboard();
    int choice_gamerules;
    
    printf("\n\t\t\t\t\t\t\t\t********************************************************************\n");
    printf("\t\t\t\t\t\t\t\t||                         SUDOKU RULES                           ||");
    printf("\n\t\t\t\t\t\t\t\t********************************************************************\n");
    printf("\t\t\t\t\t\t\t\t||      1. Every square has to contain a single number.           ||\n");
    printf("\t\t\t\t\t\t\t\t||      2. Only the numbers from 1 through to 9 can be used.      ||\n");
    printf("\t\t\t\t\t\t\t\t||      3. Each 3x3 box can only contain each number from         ||\n");
    printf("\t\t\t\t\t\t\t\t||         1 to 9 once.                                           ||\n");
    printf("\t\t\t\t\t\t\t\t||      4. Each vertical column can only contain each number      ||\n");
    printf("\t\t\t\t\t\t\t\t||         from 1 to 9 once.                                      ||\n");
    printf("\t\t\t\t\t\t\t\t||      5. Each horizontal row can only contain each number       ||\n");
    printf("\t\t\t\t\t\t\t\t||         from 1 to 9 once.                                      ||\n");
    printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t\t\t\t||                    1. GO BACK TO MAIN MENU                     ||\n");
    printf("\t\t\t\t\t\t\t\t||                    2. Exit the Game                            ||\n");
    printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t\t\t\t||  ~~> Enter Your Choice : ");
    
    scanf("%d",&choice_gamerules);
    return choice_gamerules;
}

void exit_sudoku()
{
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t\t\t\t\t\t||                 <<<   THANKS FOR PLAYING    >>>                ||\n");
    printf("\t\t\t\t\t\t\t\t||                 <<<      VISIT  AGAIN       >>>                ||\n");
    printf("\t\t\t\t\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    exit(1);
}
