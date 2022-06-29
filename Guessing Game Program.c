
//  Hamzah Jamal Eddin
//Guessing game Program
// need to fix issue with finding best value because used to save over everytime i loop
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int getrandomNum();

struct Game
{
    char name[30];
    int won;
    int lost;
    int best;
};
void getNames(struct Game *player1,struct Game *player2);
void getData(struct Game *player1,struct Game *player2,int random1,int *guess1PTR,int *guessCount1,int random2,int *guess2PTR,int *guessCount2);
void findWinner(struct Game player1,struct Game player2);


int main()
{

    int random1,random2,guess1,guess2,guessCount1,guessCount2,again;
    struct Game player1;
    struct Game player2;
    player1.best=1000;
    player2.best=1000;

    again=1;
    player1.won=0;
    player2.won=0;
    player1.lost=0;
    player2.lost=0;

 

    getNames(&player1, &player2);
    
  while(again==1)
   {
    random1= getrandomNum();
    random2= getrandomNum();

    getData(&player1,&player2,random1,&guess1,&guessCount1,random2,&guess2,&guessCount2);
       
       if (player1.best>guessCount1)
       {
           player1.best=guessCount1;
       }

       
       if (player2.best>guessCount2)
       {
           player2.best=guessCount2;
       }
  
        
        
        if(guessCount1<guessCount2)
        {
            player1.won++;
            player2.lost++;
        }
        else if(guessCount2<guessCount1)
        {
            player2.won++;
            player1.lost++;
        }
        else
        {
            
        }
        
        
    
        printf("\nplay again (0 for no or 1 for yes) ");
        scanf("%d",&again);
    if (again !=0 && again!=1)
    {
        printf("\nInvalid Input");
        printf("\nplay again (0 for no or 1 for yes) ");
        scanf("%d",&again);
    }
   }
   

    findWinner(player1,player2);
    
return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void getNames(struct Game *player1,struct Game *player2)
{
    printf("\nWelcome to the Two-Player guessing Game");
    printf("\nEnter the First Player's Name: ");
    fgets(player1->name,30,stdin);
    player1->name[strlen(player1->name)-1]='\0';
    printf("\nEnter the Second Player's Name: ");
    fgets(player2->name,30,stdin);
    player2->name[strlen(player2->name)-1]='\0';
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void getData(struct Game *player1,struct Game *player2,int random1,int *guess1PTR,int *guessCount1,int random2,int *guess2PTR,int *guessCount2)
{
    
    int counter1=0;
    
    printf("\nYour guess Should be a number between(1-1000)");
    while(*guess1PTR != random1)
    {

        printf("\nEnter %s's guess: ",player1->name);
            scanf("%d",guess1PTR);
            counter1++;
        if(*guess1PTR>random1)
            printf("\nToo High");
        
        if(*guess1PTR<random1)
            printf("\nToo low");
        
    }
    *guessCount1=counter1;
    printf("\n%s guessed the number %d after %d tries",player1->name,random1,*guessCount1);

    int counter2=0;
    
    printf("\nYour guess Should be a number between(1-1000)");
    while(*guess2PTR != random2)
    {
        printf("\nEnter %s's guess: ",player2->name);
            scanf("%d",guess2PTR);
            counter2++;
        if(*guess2PTR>random2)
            printf("\nToo High");
        
        if(*guess2PTR<random2)
            printf("\nToo low");
    }
    
    *guessCount2=counter2;
    
    printf("\n%s guessed the number %d after %d tries",player2->name,random2,*guessCount2);
    
    if(*guessCount1<*guessCount2)
    {
        printf("\n%s won this round",player1->name);
    }
    if (*guessCount2<*guessCount1)
    {
        printf("\n%s won this round",player2->name);
    }
    if(*guessCount2==*guessCount1)
    {
        printf("\nIt was A Draw!");
    }
   
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void findWinner(struct Game player1,struct Game player2)
{
    float winPer1,winPer2;
    float totalrounds=(player1.won + player1.lost);

    winPer1=(player1.won*1.00/ totalrounds)*100 ;
    winPer2=(player2.won*1.00/ totalrounds)*100 ;
    
    
    if(player1.won>player2.won)
    {
        printf("\n%s Won with a high score of %d attemps winning %d rounds and losing %d rounds ending with a winning Percentage of %.2f%%",player1.name,player1.best,player1.won,player1.lost,winPer1);
        printf("\n%s had a high score of %d attemps winning %d rounds and losing %d rounds ending with a winning Percentage of %.2f%%",player2.name,player2.best,player2.won,player2.lost,winPer2);
    }
    
    else if(player2.won>player1.won)
    {
        printf("\n%s Won with a high score of %d attemps winning %d rounds and losing %d rounds ending with a winning Percentage of %.2f%%",player2.name,player2.best,player2.won,player2.lost,winPer2);
        printf("\n%s had a high score of %d attemps winning %d rounds and losing %d rounds ending with a winning Percentage of %.2f%%",player1.name,player1.best,player1.won,player1.lost,winPer1);

    }
    else if(player2.won==player1.won)
    {
        printf("\nGame was a Draw!!");
        printf("\n%s had a high score of %d attemps winning %d rounds and losing %d rounds ending with a winning Percentage of %.2f%%",player1.name,player1.best,player1.won,player1.lost,winPer1);
        printf("\n%s had a high score of %d attemps winning %d rounds and losing %d rounds ending with a winning Percentage of %.2f%%",player2.name,player2.best,player2.won,player2.lost,winPer2);

    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int getrandomNum()
{
    int random;
    
    srand(time(0)+clock()*clock());
    for(int x=0;x<5;x++)
      {
    random =( rand() % 1000 )+ 1;
        }
    return random;
}
