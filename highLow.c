#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to High Low Game!\n");

    int numberToGuess = rand() % 10 + 1; 
    int currentGuess;
    int attempts = 0;
    const int maxAttempts = 5;
    const int maxMistakes = 3;
    int mistakes = 0;          
    int warningUsed = 0;       
    int previousGuess = 0;
    int guessedToLow = 0;
    int guessedToHigh = 0;
    int maxPlays = 0;

    while (attempts < maxAttempts && mistakes < maxMistakes) {
        printf("\nEnter your guess (1-10): ");

        if (scanf("%d", &currentGuess) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}

            if (!warningUsed) {
                printf("Don't be a Dufus! This is a warning!\n");
                warningUsed = 1;
            } else {
                mistakes++;
                printf("Don't be a Dufus! You have made %d mistakes.\n", mistakes);
            }

            if (mistakes >= maxMistakes) {
                printf("Game Over! You've made too many mistakes. The number was %d.\n", numberToGuess);
                break;
            }
            continue;
        }

        int isInvalid =
            (currentGuess < 1 || currentGuess > 10) ||
            (previousGuess == currentGuess) ||
            (currentGuess < previousGuess && guessedToLow) ||
            (currentGuess > previousGuess && guessedToHigh);

        if (isInvalid) {
            if (!warningUsed) {
                printf("Don't be a Dufus! This is a warning!\n");
                warningUsed = 1;
            } else {
                mistakes++;
                printf("Don't be a Dufus! You have made %d mistakes.\n", mistakes);
            }

            if (mistakes >= maxMistakes) {
                printf("Game Over! You've made too many mistakes. The number was %d.\n", numberToGuess);
                break;
            }
            continue;
        }

        mistakes = 0;
        previousGuess = currentGuess;

        if (currentGuess < numberToGuess) {
            printf("Higher!\n");
            guessedToLow = 1;
            guessedToHigh = 0;
            attempts++;
        } else if (currentGuess > numberToGuess) {
            printf("Lower!\n");
            guessedToHigh = 1;
            guessedToLow = 0;
            attempts++;
        } else {
            attempts++;
            printf("Congratulations! You've guessed the number!\n");
            printf("It took you %d attempts.\n", attempts);

            if (maxPlays >= 3) {
                printf("Thanks for Playing! You've reached the maximum number of plays.\n");
                break;
            }

            printf("Game Over! You Win!\nWould you like to play again? (y/n): ");
            char playAgain;
            scanf(" %c", &playAgain);

            if (playAgain == 'y' || playAgain == 'Y') {
                numberToGuess = rand() % 10 + 1;
                attempts = 0;
                mistakes = 0;
                previousGuess = 0;
                guessedToLow = 0;
                guessedToHigh = 0;
                maxPlays++;
                warningUsed = 0;
                continue;
            } else {
                break;
            }
        }

        if (attempts >= maxAttempts) {
            printf("Game Over! You've used all your attempts. The number was %d.\n", numberToGuess);
            break;
        }
    }

    return 0;
}
