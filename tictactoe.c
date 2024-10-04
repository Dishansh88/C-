#include<stdio.h>
#include<stdlib.h>
int input(int );
int board[3][3];
int gamemenu()
{
    system("cls");
    int choice;
    printf("\n1:Two players game");
    printf("\n2:Exit ");
    printf(" \n3:ENTER THE CHOICE" );
    scanf("%d",&choice);
    return choice;
}
void resetgame()
{
    int i,j;
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        board[i][j]=2;
    }
}
void displayboard()

{
    int i,j,k=1;
    for(i=0;i<=2;i++)
    {
    for(j=0;j<=2;j++)
    {
        if(board[i][j]==2)
        printf("%3d",k);
        else
        if(board[i][j]==3)
        printf("%3c",'X');
        else
          if(board[i][j]==5)
          printf("%3c",'C');
          k++;
    }
    printf("\n\n");
    }

    }
    void makemove(int player,int move)
    {
        switch (move)
        {
        
        case 1:
        if(player==1)
        board[0][0]=3;
        else
        board[0][0]=5;
        case 2:
        if(player==1)
        board[0][1]=3;
        else
        board[0][1]=5;
        break;
        case 3:
        if(player==1)
        board[0][2]=3;
        else
        board[0][2]=5;
        break;
        
        case 4:
        if(player==1)
        board[1][0]=3;
        else
        board[1][0]=5;
        break;
        case 5:
        if(player==1)
        board[1][1]=3;
        else
        board[1][1]=5;
        break;
        case 6:
        if(player==1)
        board[1][2]=3;
        else
        board[1][2]=5;
        break;
        case 7:
        if(player==1)
        board[2][0]=3;
        else
        board[2][0]=5;
        break;
        case 8:
        if(player==1)
        board[2][1]=3;
        else
        board[2][1]=5;
        break;
        case 9:
        if(player==1)
        board[2][2]=3;
        else
        board[2][2]=5;
        break;
        }
    }
    int checkwin( int player)
    {
        int i,j;
        if(player==1)
        {
           for(i=0;i<=2;i++)
           if(board[i][0]*board[i][0]*board[i][0]==27)
            return 1;
            for(j=0;j<=2;j++)
            if(board[0][j]*board[1][j]*board[2][j]==27)
            return 1;
            if(board[0][2]*board[1][1]*board[0][1]==27)
            return 1;
            if(board[0][0]*board[1][1]*board[2][2]==27)
            return 1;

        }
        else
        {
            for(i=0;i<=2;i++)
           if(board[i][0]*board[i][0]*board[i][0]==125)
            return 1;
            for(j=0;j<=2;j++)
            if(board[0][j]*board[1][j]*board[2][j]==125)
            return 1;
            if(board[0][2]*board[1][1]*board[0][1]==125)
            return 1;
            if(board[0][0]*board[1][1]*board[2][2])
            return 1;
        }
            return 0;


    }
    int ismovevalid( int move)
    {
        switch(move)
        {
            case 1:
            if(board[0][0]==2)
            return 1;
            break;
            case 2:
            if(board[0][1]==2)
            return 1;
            break;
            case 3:
            if(board[0][2]==2)
            return 1;
            break;
            case 4:
            if(board[1][0]==2)
            return 1;
            break;
            case 5:
            if(board[1][1]==2)
            return 1;
            break;
            case 6:
            if(board[1][2]==2)
            return 1;
            break;
            case 7:
            if(board[2][0]==2)
            return 1;
            break;
            case 8:
            if(board[2][1]==2)
            return 1;
            break;
            case 9:
            if(board[2][2]==2)
            return 1;
            break;
        }
        return 0;
}

int inputmove(int player) 

 {
   int move;
   do
   {printf("%d player",player);
   scanf("%d",&move);
   }while(!ismovevalid(move));
   return move;
     
 }
int main()
{
    int turn,player,move;;
while (1)
{
    switch(gamemenu())
    {
    case 1:
        resetgame();
        displayboard();
        for(turn=1,player=1;turn<=9;turn++)
        {
           move=inputmove(player);
           makemove(player,move);
           system("cls");
           displayboard();
          if( checkwin(player))
          {
          printf(" player  %d won the match  ",player);
          break;
          }
           
        
        if(player==1)
        player=2;
        else
        player=1;
        }
         if(turn==10)
        printf(" Game is draw ");
        break;
    case 2:
     exit(0);
        break;
    default:
    printf("fhirse khelo mkl");
    break;

    }
    }
}