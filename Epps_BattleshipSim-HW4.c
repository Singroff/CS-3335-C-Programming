/******************************************************************************
Program Name: battleshipSim.c
Programmer: Caleb Epps
Class: CS3335
HW: 04
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Quick Note: I added a couple of extra features, so hopefully this small note helps while you're grading:
** The setBoard methods checks all possible ways the user-supplied numbers could be invalid and loops until they're invalid
** The computer can't guess the same number twice. If it does, it will loop until it guesses a number it hasn't yet.
   This is controlled using a boolean array, it's not the best way, but it works for C right now for me.
** I used character pointers and character arrays because it looks better when printing them out.
*/


void setBoard (char *boardPtr) {
  int pos1, pos2;
  // isValid is used to ensure that the numbers will work for the program.
  bool isValid = false;
  
  for (int i = 0; i < 10; i++) {
      *(boardPtr + i) = '*';
    }
    
    do {
        printf ("\nPlease enter your first position: ");
        scanf ("%d", &pos1);

        printf ("Please enter your second position: ");
        scanf ("%d", &pos2); 
        
        // Checks all possible conditions to ensure the numbers will work (i.e. 11 and 12 would be rejects)
        // 3 and 8 would also be rejected as they aren't adjacent.
        if(pos1 < 0 || pos1 > 9) {
            printf("The numbers must be between 0 and 9.");
        }
        else if(pos2 < 0 || pos2 > 9) {
            printf("The numbers must be between 0 and 9.");
        }
        else if(abs(pos1 - pos2) == 1) {
            isValid = true;
        }
        else {
            printf("The numbers must be adjacent to each other.");
        }

        
    } while(!isValid);
    
  // These 2 lines assign the ship's location using pointers.
  *(boardPtr + pos1) = 'S';
  *(boardPtr + pos2) = 'S';


}

void setComputerBoard (char *boardPtr) {
  int pos1, pos2;
  
  for (int i = 0; i < 10; i++) {
    *(boardPtr + i) = '*';
    }
    
  // Instead of asking for input, the computer's ship locations are chosen via random numbers between 0 and 9.
  pos1 = rand() % 10;
  pos2 = pos1 + 1;
  
  *(boardPtr + pos1) = 'S';
  *(boardPtr + pos2) = 'S';
}

// This method is simply for properly printing the boards of the player and the computer.
void printBoard (char *board, bool isComp) {
  printf ("\n");

  for (int i = 0; i < 10; i++) {
      printf ("%d ", i);
  }

  printf ("\n");

  for (int i = 0; i < 10; i++) {
      // This hides the computer board from the player when it's printed.
      if(isComp) {
          if(*(board + i) == 'S') {
              printf("* ");
          } 
          else {
              printf ("%c ", *(board + i));
          }
      } 
      else {
        printf ("%c ", *(board + i));
      }
      
  }
}

// This super short method just returns a random integer. It's used below in playGame()
int getRanNum() {
    return rand() % 10;
}


int playGame (char *comp, char *player) {
 int numPlayerHits = 0;
 int numCompHits = 0;
 int compGuess, playerGuess;
 // This array will hold booleans correlating to locations the computer already guessed.
 bool compGuesses[10];
 bool alreadyGuessed;
 int roundNum = 1;

 
 do {
     // While already guessed is true, the computer will continue to guess numbers.
     // This prevents duplicate guesses + endless games
     alreadyGuessed = true;
     while(alreadyGuessed) {
         compGuess = getRanNum();
         if(compGuesses[compGuess] == false) {
             alreadyGuessed = false;
             compGuesses[compGuess] = true;
         }
     }
     // Formats to distinguish between rounds
     printf("\n\nROUND %d", roundNum);
     roundNum++;
     printf("\nThe computer fires at position %d.", compGuess);
     
     if(*(player + compGuess) == 'S') {
        printf("\nComputer struck a target!");
        *(player + compGuess) = 'H';
        numCompHits++;
        // ends the game if the computer gets 2 hits.
        if(numCompHits == 2) {
             
             if(numCompHits == 2) {
                printf("\nYour Board:");
                printBoard(player, false);
     
                printf("\nComputer's Board:");
                printBoard(comp, false);
                return 0;
             } else {
                return 1;
             }
             
        }
     } 
     else {
         printf("\nComputer misfires!");
         *(player + compGuess) = 'M';
     }
     // Prompts user and runs same logic as above but for the player instead.
     printf("\nEnter a position to strike: ");
     scanf("%d", &playerGuess);
     
     if(*(comp + playerGuess) == 'S') {
         printf("\nYou struck a target!");
         *(comp + playerGuess) = 'H';
         numPlayerHits++;
     }
     else {
         printf("You've missed!");
         *(comp + playerGuess) = 'M';
     }
     
     printf("\nYour Board:");
     printBoard(player, false);
     
     printf("\n Computer's Board:");
     printBoard(comp, true);
     
     // while condition will fail when either player or computer gets 2 hits.
 } while(numPlayerHits != 2 && numCompHits != 2);
 
 if(numCompHits == 2) {
     return 0;
 } else {
     return 1;
 }
}

int main() {
// Both character boards (I think that characters are more aesthetically pleasing than using integers.)
  char playerBoard[10];
  
  char compBoard[10];

  setBoard (playerBoard);
  setComputerBoard (compBoard);

  int winner = playGame(compBoard, playerBoard);
  // If the playGame() method returns a 0, the computer wins. Otherwise, the player wins.
  if(winner == 0) {
      printf("\nTHE COMPUTER HAS SUNK YOUR SHIP!");
  } else {
      printf("\nYOU HAVE SUCK THE COMPUTER'S SHIP!");
  }


  return 0;

}
