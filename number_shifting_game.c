
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



// MACRO Declaration

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72
#define KEY_DOWN 80

// FUNCTION DECLATIONS

void Rules();
void RandNumber(int A[][4], int , int);
void Start(int A[][4],int , int , int, char name[]);
void PrintMatrix(int A[][4],int, int, char name[], int);
int MoveUp(int A[][4], int ,int , int );
int MoveDown(int A[][4], int ,int , int );
int MoveLeft(int A[][4], int ,int , int );
int MoveRight(int A[][4], int ,int , int );
int Compare(int A[4][4],int );



// CODING MAIN

int main()
{

    while(1)
    {

        int Mat[4][4]={};
        int moves= 120,x=0;
        char name[30],c;
        printf("\n\n\tWelcome to 'THE NUMBER SHIFTING GAME' TO Play the game : - ");
        printf("\n\n\tPlease ENTER Your Name : ");
        gets(name);
        system("cls");

        // print game rules

        Rules();
        printf("\n\n\t\tPress any key to start the game...\n");
        getchar();
        system("cls");

        char key;
        system("cls");
        RandNumber(Mat,4,4);
        Start(Mat, 4, 4, moves,name);
        printf("\n\n\t  Press 'Y' to Play  Again  \t");
        printf(" Press any key to Exit \n");

        switch(c = getch())
        {
        case 'Y':
            x = 0;
            break;
        case 'y':
            x = 0;
            break;
        default:
            x = 1;
        }
        if(x)
            break;

    }
    return 0;
}


// Function Definition

void Rules()
{

    printf("\t\t\t---------------NUMBER SHIFTING GAME BY REENU---------------\n\n\n");

    printf("\t\t\t@@@@@@@@@@@@@@@@@@@@----GAME RULES----@@@@@@@@@@@@@@@@@@@@\n\n");
    printf("\t(1).You can move only 1 step at a time by arrow key\n\n");

    printf("\t\tMove Right : by RIGHT Arrow -> key\n");
    printf("\t\tMove Left : by LEFT Arrow <- key\n");
    printf("\t\tMove Up : by UP Arrow ^ key\n");
    printf("\t\tMove Down : by DOWN Arrow key");
    printf("%c\n",25);


     printf("\n\t(2).You can move numbers at Empty position only\n");
     printf("\t(3).For each valid move : your total number of moves will be decreased by 1\n");
     printf("\twinning Situation : Number in a 4X4 Matrix should be in Order from 1 to 15.\n\n");




     printf("\t\t\t@@@@@@@@@@@@@@@@@@@@@--WINNING SITUATION--@@@@@@@@@@@@@@@@@@@@@\n\n");




     int count = 1,i,j;

     printf("\t\t\t\t\t------------------\n");
     for(i=0;i<4;i++)
     {
         printf("\t\t\t\t\t|");
         for(j=0;j<4;j++)
         {
             if(count==16)
                printf("%3c ",32);
             else
                printf("%3d ",count++);
         }
         printf("|");
         printf("\n");

     }

     printf("\t\t\t\t\t------------------\n");

     printf("\n\t\t(5).You can exit the game any time by pressing the 'E' or 'e'\n");

}

void RandNumber(int M[][4],int r,int c)
{
    int i,j,count = 1,x=0,y=0;
    M[3][3]=0;
    srand(time(NULL));
    while(count<16)
    {
        int randNum = rand() % 15 + 1;
        int flag = 1;

        // checking duplicate number
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(M[i][j]==randNum)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
        {
            M[x][y]=randNum;
            y++;
            if(y>3)
            {
                x++;
                y=0;
            }
            count++;

        }
    }
}


void Start(int A[][4],int r, int c, int totalMov, char name[])
{

    PrintMatrix(A,4,4,name,totalMov);

    int ch,flag= 0,x;
    while(1)
    {

        ch= getch();
        if(ch==0)
            ch=getch();
        switch(ch)
        {
        case 69:
            flag =1;
            break;
        case 101:
             flag =1;
            break;
        case KEY_UP:
            totalMov = MoveUp(A,4,4,totalMov);
            x=Compare(A,totalMov);
            if(x==1)
            {
                printf("You Won\n");
                flag =1;
            }
            else if(x==0)
            {

                printf("YOU LOSE\n");
                flag = 1;
            }
            else
            {
                system("cls");
                PrintMatrix(A,4,4,name,totalMov);
            }
            break;
        case KEY_DOWN:
            totalMov = MoveDown(A,4,4,totalMov);
            x=Compare(A,totalMov);
            if(x==1)
            {
                printf("You Won\n");
                flag =1;
            }
            else if(x==0)
            {

                printf("YOU LOSE\n");
                flag = 1;
            }
            else
            {
                system("cls");
                PrintMatrix(A,4,4,name,totalMov);
            }
            break;
        case KEY_LEFT:
            totalMov = MoveLeft(A,4,4,totalMov);
            x=Compare(A,totalMov);
            if(x==1)
            {
                printf("You Won\n");
                flag =1;
            }
            else if(x==0)
            {

                printf("YOU LOSE\n");
                flag = 1;
            }
            else
            {
                system("cls");
                PrintMatrix(A,4,4,name,totalMov);
            }
            break;
        case KEY_RIGHT:
            totalMov = MoveRight(A,4,4,totalMov);
            x=Compare(A,totalMov);
            if(x==1)
            {
                printf("You Won\n");
                flag =1;
            }
            else if(x==0)
            {

                printf("YOU LOSE\n");
                flag = 1;
            }
            else
            {
                system("cls");
                PrintMatrix(A,4,4,name,totalMov);
            }
            break;
        }
        if(flag)
            break;
    }
}

void PrintMatrix(int A[][4],int r,int c,char name[],int totalMov)
{

    printf("\n\n\t\t Player Name : ");
    printf("%s\t",name);
    printf("Remaining Moves : %d \n\n",totalMov);

    printf("\t\t\t---------------------\n");

    for(int i=0;i<r;i++)
    {
        printf("\t\t\t|");
        for(int j=0;j<c;j++)
        {
            if(A[i][j]==0)
            {
                 printf("%3c |",32);
                 continue;
            }
            printf("%3d |",A[i][j]);
        }
        printf("\n");
    }
    printf("\t\t\t---------------------\n\n");
}

int Compare(int A[4][4],int Mov)
{
    int b[4][4]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    int flag =1,i,j;
    if(Mov>=0)
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(A[i][j]!=b[i][j])
                {
                    flag =0;
                    break;
                }
            }
        }
        if(flag)
        {
            return flag;
        }
    }
    else
        return 0;
}


// MoveUp fn
int MoveUp(int A[][4],int r, int c, int mov)
{
    int i, j,flag =0,temp;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(A[i][j]==0)
            {
                if(i!=3)
                {
                    temp=A[i][j];
                    A[i][j]=A[i+1][j];
                    A[i+1][j]=temp;
                    mov--;
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
            break;
    }
    return mov;
}

int MoveDown(int A[][4],int r, int c, int mov)
{
    int i, j,temp;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(A[i][j]==0)
            {
                if(i!=0)
                {
                    temp=A[i][j];
                    A[i][j]=A[i-1][j];
                    A[i-1][j]=temp;
                    mov--;

                    break;
                }
            }
        }
    }
    return mov;
}


int MoveRight(int A[][4],int r, int c, int mov)
{
    int i, j,flag =0,temp;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(A[i][j]==0)
            {
                if(j!=0)
                {
                    temp=A[i][j];
                    A[i][j]=A[i][j-1];
                    A[i][j-1]=temp;
                    mov--;
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
            break;
    }
    return mov;
}


int MoveLeft(int A[][4],int r, int c, int mov)
{
    int i, j,flag =0,temp;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(A[i][j]==0)
            {
                if(j!=3)
                {
                    temp=A[i][j];
                    A[i][j]=A[i][j+1];
                    A[i][j+1]=temp;
                    mov--;
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
            break;
    }
    return mov;
}
