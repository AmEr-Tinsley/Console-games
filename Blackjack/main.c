#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char players[8][15];
int n,score[9],pcscore,lost[9],won[9],cnt=0;
int cards[52];
int occ[12];

int continue_playing(){

 printf("\n\n\nIs there still players who want to play ? \n");
 printf("if yes type 1  otherwise type 0\n");
 int x;
 do{
      scanf("%d",&x);

 }while(x!=1 && x!=0);

 return x;
}
void clear_last_game(){

   for(int i=0;i<52;i++)cards[i]=0;
   for(int i=0;i<9;i++)score[i]=0;
   for(int i=0;i<9;i++)lost[i]=0;
   for(int i=0;i<9;i++)won[i]=0;
   for(int i=0;i<12;i++)occ[i]=0;
    cnt=0;
    pcscore=0;
    return;

}
int remain(int x){

    if(x == 11)
        return (occ[x]<12);

    return (occ[x]<4);
}
void shuffle_cards(){
 time_t t;
 srand((unsigned) time(&t));

 for(int i=0;i<52;i++){

     int curr = ((rand()%11)+1);

     while(remain(curr)==0){
           curr = ((rand()%11)+1);
     }
     cards[i]=curr;
     occ[curr]++;
 }


}
void Set_players(){

    printf("Welcome to Blackjack ! \n\n");
    printf("How many players will be there ? \n");
    do{
        printf("Make sure it doesn't exceed 7 players !\n");
        scanf("%d",&n);
    }while(n>7 || n<1);

    for(int i=0;i<n;i++){

          printf("Name of player %d ? \n",i+1);
          scanf("%s",players[i]);
    }

}
int check(int x){

  if(score[x]>21){
     printf("Ooops You lost , your score exceeded 21 , better luck next time  ... \n");
     lost[x]=1;
     return 1;
     }
  else if(score[x] == 21){
     printf("Congrats !! You won because you got exactly 21 score !! \n");
     won[x]=1;
     return 1;
  }

  return 0;

}
void Start_game(){

  printf("\n\n\nHello players , Im the dealer of this game, good luck to all of you ! \n\nIm going to distrube cards in turns to all of us\n\n");

  shuffle_cards();
  for(int i=0;i<n;i++){

     printf("Now its %s's turn ! \n",players[i]);

     char c1[6],c2[6];
     if(cards[cnt]==1)
        c1[0]='a',c1[1]='s',c1[2]='\0';
     else if(cards[cnt]==11){
         c1[0]='F',c1[1]='A',c1[2]='C',c1[3]='E',c1[4]='\0',score[i]+=10;
     }
     else if(cards[cnt]==10)
        c1[0]='1',c1[1]='0',c1[2]='\0',score[i]+=10;
     else
        c1[0]='0'+cards[cnt],c1[1]='\0',score[i]+=cards[cnt];
     cnt++;
     if(cards[cnt]==1)
        c2[0]='a',c2[1]='s',c2[2]='\0';
     else if(cards[cnt]==11){
         c2[0]='F',c2[1]='A',c2[2]='C',c2[3]='E',c2[4]='\0',score[i]+=10;
     }
     else if(cards[cnt]==10)
        c2[0]='1',c2[1]='0',c2[2]='\0',score[i]+=10;
     else
        c2[0]='0'+cards[cnt],c2[1]='\0',score[i]+=cards[cnt];
     cnt++;
     printf("You got : %s and %s cards\n",c1,c2);

     if(strcmp(c1,"as")==0){
         int k;
         do{
         printf("your first card is an as , do you want to convert it into 1 or 11 ? \n");
         scanf("%d",&k);
         }while(k!=1 && k!=11);

         score[i]+=k;
     }

     if(strcmp(c2,"as")==0){
         int k;
         do{
         printf("your second card is an as , do you want to convert it into 1 or 11 ? \n");
         scanf("%d",&k);
         }while(k!=1 && k!=11);

         score[i]+=k;
     }

     printf("Okay %s ! , so your current score is now : %d \n\n",players[i],score[i]);

     check(i);
  }

   char c1[6],c2[6];
     if(cards[cnt]==1)
        c1[0]='a',c1[1]='s',c1[2]='\0';
     else if(cards[cnt]==11){
         c1[0]='F',c1[1]='A',c1[2]='C',c1[3]='E',c1[4]='\0',pcscore+=10;
     }
     else if(cards[cnt]==10)
        c1[0]='1',c1[1]='0',c1[2]='\0',pcscore+=10;
     else
        c1[0]='0'+cards[cnt],c1[1]='\0',pcscore+=cards[cnt];
     cnt++;
     if(cards[cnt]==1)
        c2[0]='a',c2[1]='s',c2[2]='\0';
     else if(cards[cnt]==11){
         c2[0]='F',c2[1]='A',c2[2]='C',c2[3]='E',c2[4]='\0',pcscore+=10;
     }
     else if(cards[cnt]==10)
        c2[0]='1',c2[1]='0',c2[2]='\0',pcscore+=10;
     else
        c2[0]='0'+cards[cnt],c2[1]='\0',pcscore+=cards[cnt];

   printf("For my case im only allowed to show you one of my cards \n");
   printf("One of my cards is  : %s\n\n",c1);

   if(strcmp(c1,"as")==0){

         if(pcscore + 11 <=21)
            pcscore+=11;
         else
            pcscore++;
   }
    if(strcmp(c2,"as")==0){

         if(pcscore + 11 <=21)
            pcscore+=11;
         else
            pcscore++;
   }

}
void Add_cards(){

  printf("\n\n\nOkay players ! so our next step in the game is adding cards or not\nso each one of you has his score so now i will ask each one of you to either add cards or not\nMaximum cards that can be added are 3\n");

  printf("So here we start  : \n\n");

  for(int i=0;i<n;i++){

       if(won[i] || lost[i])continue;

       for(int j=0;j<3;j++){
       printf("%s would you like to add a card ? if yes type 1 otherwise type 0 \n",players[i]);

       int choice;

       do{
           scanf("%d",&choice);
       }while(choice!=1 && choice!=0);

       if(choice){

              char c1[6];
          if(cards[cnt]==1)
            c1[0]='a',c1[1]='s',c1[2]='\0';
          else if(cards[cnt]==11){
            c1[0]='F',c1[1]='A',c1[2]='C',c1[3]='E',c1[4]='\0',score[i]+=10;
            }
          else if(cards[cnt]==10){
             c1[0]='1',c1[1]='0',c1[2]='\0',score[i]+=10;
          }
          else
            c1[0]='0'+cards[cnt],c1[1]='\0',score[i]+=cards[cnt];
          cnt++;
           printf("You got a %s card \n",c1);

           if(strcmp(c1,"as")==0){
         int k;
         do{
         printf("do you want to convert it into 1 or 11 ? \n");
         scanf("%d",&k);
         }while(k!=1 && k!=11);

         score[i]+=k;
         }

         if(check(i))break;
       }
       else break;
    }
  }

}

void Winners(){

   printf("\n\n\nMy score was : %d \n",pcscore);
   printf("So as the game ended let's take a look of who won and who lost \n\n");

   for(int i=0;i<n;i++){

        printf("%s : ",players[i]);

        if(lost[i] || score[i]<pcscore)
            printf("Lost \n");
        else
             printf("Won \n");
   }

}
int main()
{

    while(1){
      clear_last_game();
      Set_players();
      Start_game();
      Add_cards();
      Winners();
      if(continue_playing())continue;


      break;
    }


    return 0;
}
