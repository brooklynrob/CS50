/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9



// board
int board[DIM_MAX][DIM_MAX];

// tiles
int sequence[81];

int tile_count;

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);


void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();


    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);
        
        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);

}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // set the amount of tiles
    int tile_count = ((d*d)-1);

    // Create array in reverse
    
    for (int m=0; m<tile_count; m++)
    {
        sequence[m] = (tile_count-m);
        //sequence[m] = 0;
    }
    
    // Set last element of sequence to 0 (blank)
    sequence[tile_count] = 0;
    
    // Switch the 1 and 2 only if the dimension is even
    if ((d % 2) == 0)
    {
        int swap=sequence[(tile_count-2)];
        sequence[(tile_count-2)]=sequence[(tile_count-1)];
        sequence[(tile_count-1)]=swap;
    }
    

    for (int g=0; g<d; g++)
    {
        for (int h=0; h<d; h++)
        {
            board[g][h]=sequence[((g*d)+h)];
        }
    }

}

/**
 * Prints the board in its current state.
 */

void draw(void)
{
    printf("\n");

    // Print rows
    for (int g=0; g<d; g++)
    {
    printf("  ");

        // Print elements per column
        for (int h=0; h<d; h++)
        {

            if (board[g][h]<=9)
            {
                printf(" ");
            }
            
            printf(" %d",board[g][h]);
        
        }
        printf("\n");
        printf("\n");
    
    }
}



/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int blank_row;
    int blank_col;
    int move_row;
    int move_col;
    
    // get position of blank (0)
    for (int i=0; i<d; i++)
    {
        for (int j=0; j<d; j++)
        {
            if (board[i][j]==0)
            {
                blank_row=i;
                blank_col=j;
            }
        }
    }
    
    for (int k=0; k<d; k++)
    {
        for (int l=0; l<d; l++)
        {
            if (board[k][l]==tile)
            {
                move_row=k;
                move_col=l;
            }
        }
    }
    
    
    if  ( (((move_col==blank_col+1) || (move_col==blank_col-1)) && (move_row==blank_row))  || ( ((move_row==blank_row+1) || (move_row==blank_row-1)) && (move_col==blank_col) ) )
    {
        board[blank_row][blank_col]=tile;
        board[move_row][move_col]=0;

        return true;
    }

    // illegal move so return false    
    else
    {
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int win=0;
    int check_val = 1;
    for (int g=0; g<d; g++)
    {
        for (int h=0; h<d; h++)
        {
            if (board[g][h]==check_val)
            {
                win++;
            }
            
            else
            {
     
            }
            check_val++;
        }
    }

    
    if (win==((d*d)-1))
    {
        return true;   
    }
    else
    {
        return false;
    }

}