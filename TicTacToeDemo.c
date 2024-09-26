#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 3

// Structure to represent a player
struct Player {
    char symbol;
    int score;
};

// Function to dynamically allocate memory for the grid
char** initializeGrid() {
    char** grid = (char**)malloc(GRID_SIZE * sizeof(char*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = (char*)malloc(GRID_SIZE * sizeof(char));
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = ' ';
        }
    }
    return grid;
}

// Function to print the current state of the grid
void printGrid(char** grid) {
    printf("Current Tic-Tac-Toe Grid:\n");

    for (int i = 0; i < GRID_SIZE; i++) {

        for (int j = 0; j < GRID_SIZE; j++) {
            printf(" %c ", grid[i][j]);
            if(j<2)
            {
                printf("|");
            }
        }
        printf("\n");
    if(i<2)
    {
        printf("------------- \n");
    }
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char** grid, char symbol) {
    // Check rows and columns
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) {
            return 1;
        }
        if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol) {
            return 1;
        }
    }

    // Check diagonals
    if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) {
        return 1;
    }
    if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol) {
        return 1;
    }

    return 0; // No win
}

int main() {
    struct Player playerX = {'X', 0};
    struct Player playerO = {'O', 0};

    char** grid = initializeGrid();
    int currentPlayer = 0; // 0 for playerX, 1 for playerO
    int moves = 0;

    printf("Tic-Tac-Toe Game\n");

    while (1) {
        printGrid(grid);
        struct Player current = (currentPlayer == 0) ? playerX : playerO;
        printf("Player %c's turn. Enter row and column (e.g., 1 2): ", current.symbol);

        int row, col;
        if (scanf("%d %d", &row, &col) != 2 || row < 1 || row > 3 || col < 1 || col > 3 || grid[row - 1][col - 1] != ' ') {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        grid[row - 1][col - 1] = current.symbol;
        moves++;

        if (checkWin(grid, current.symbol)) {
            (currentPlayer == 0) ? playerX.score++ : playerO.score++;
            printf("Player %c wins!\n", current.symbol);
            break;
        } else if (moves == GRID_SIZE * GRID_SIZE) {
            printf("It's a tie!\n");
            break;
        }

        currentPlayer = 1 - currentPlayer; // Switch players
    }

    printf("Final Scores:\n");
    printf("Player X: %d\n", playerX.score);
    printf("Player O: %d\n", playerO.score);

    // Deallocate memory
    for (int i = 0; i < GRID_SIZE; i++) {
        free(grid[i]);
    }
    free(grid);



    return 0;
}
