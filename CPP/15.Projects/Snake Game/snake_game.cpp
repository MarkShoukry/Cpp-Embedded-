#include "Snake_game.h"



void SnakeGame::GameInit()
{
    isGameOver = false;
    score = 0 ;

    // height and width of the boundary 
    const int width = 40 ;
    const int height = 20 ;

    dir = STOP;
    snakeHeadX = width / 2 ;
    snakeHeadY = height / 2 ;


    srand(time(NULL));
    fruitX = rand() % width ;
    fruitY = rand() % height ;
// Array to store the coordinates of snake tail (x-axis, y-axis) 
    snakeTailX.resize(100);
    snakeTailY.resize(100);

    snakeTailLength = 0;
}



// Function for creating the game board & rendering 
void SnakeGame::GameRender(std::string PlayerName)
{
    system("Cls"); // Clear console 

    // Creating top walls with '_' 
    for (int i = 0 ; i < width + 2 ; i++)
    {
        std::cout << "_";
    }
    std::cout<< std::endl ;



    for (int i = 0 ; i < height + 2 ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            // Creating side walls with '|' 
            if(j == 0)
                {   std:: cout << "|" ;  }

            // Creating snake's head with 'O' 
            if(i == snakeHeadY && j == snakeHeadX)
                {   std::cout << "O" ; }
                
			// Creating the sanke's fruit with '#'
            else if (i == fruitY && j == fruitX)
                {   std::cout << "#" ; }

            else
            {
                // Creating snake's tail with 'o' 
                bool isSnakeTailCoord = false ;
                for (int k=0 ; k < snakeTailLength; k++)
                    {
                        if (snakeTailX[k] == j && snakeTailY[k] == i)
                        {
                            std::cout << "o" ;
                            isSnakeTailCoord = true ;
                        }
                    }
                    if (!isSnakeTailCoord)
                          {   std::cout << " " ; }
            }
            if (j == width - 1 )
                    {std::cout << "|" ; }
        }
        std::cout << std::endl ;
    }
    // Creating bottom walls with '-' 
    for (int i = 0 ; i < width + 2 ; i ++)
            {   std::cout << "-" ;   }
    
    // Display player's score 
    std::cout << std::endl << std::endl ;
    std::cout << PlayerName << "'s Score: " << score  << std::endl  << std::endl ;    
}


// Function to handle user User Input 
void SnakeGame::Input()
{
    // Checks if a key is pressed or not 
    if (_kbhit())
    {   

        // Getting the pressed key 
        switch (_getch())
        {
            case 'w':
                dir = UP ;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 27: // ESC button
                isGameOver = true ;
                break;
            
        }
    }
}

// Function for updating the game state 
void SnakeGame::UpdateGame()
{
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X , prev2Y;

    snakeTailX[0] = snakeHeadX;
    snakeTailY[0] = snakeHeadY;

    for (int i= 1 ; i < snakeTailLength ; i++)
    {
        prev2X = snakeTailX[i] ;
        prev2Y = snakeTailY[i] ;

        snakeTailX[i] = prevX ;
        snakeTailY[i] = prevY ;

        prevX = prev2X ;
        prevY = prev2Y ;

        switch (dir)
        {
        case LEFT :
            snakeHeadX--;
            break;
        case RIGHT :
            snakeHeadX++;
            break;
        case UP :
            snakeHeadY--;
            break;
        case DOWN :
            snakeHeadY++;
            break;
        
        }

        // Checks for snake's collision with the wall (|) 

        // if (snakeHeadX >= width )
        //     {   snakeHeadX = 0 ; }
        // else if (snakeHeadX < 0)
        //     {   snakeHeadX = width - 1 ;   }

        //if (snakeHeadY >= height)
        //     {   snakeHeadY = 0 ; }
        // else if (snakeHeadY < 0)
        //     {   snakeHeadY = height - 1 ;   }

        if (snakeHeadX>=width || snakeHeadX <0 || snakeHeadY >= height || snakeHeadY <0)
            {   isGameOver =true ;}
       
         
        
        
        // Checks for collision with the tail (o) 
        for (int i = 0 ; i < snakeTailLength ; i++)
        {
            if(snakeTailX[i] == snakeHeadX && snakeTailY[i] == snakeHeadY)
                isGameOver = true ;
        }

        // Checks for snake's collision with the food (#) 
        if (snakeHeadX == fruitX && snakeHeadY == fruitY)
        {
            snakeTailLength++;
            score += 10;

            srand(time(NULL));
            fruitX = rand() % width;
            fruitY = rand() % height;
        }
    }

}








// Function to set the game difficulty level 
int SetDifficult()
{
    int DFC, choice;
    std::cout << "\nSET DIFFICULT\n1- Easy\n2- Medium\n3- Hard"
                "\nNOTE: If not chosen or pressed any other key,\n"
                "The difficulty will be automatically set to Medium\n"
                "Chosse difficulty level: ";

    std::cin  >> choice;

    switch (choice)
    {
    case '1':
        DFC =50;
        break;
    case '2':
        DFC =100;
        break;
    case '3':
        DFC =150;
        break;
    default:
        DFC =100;
        break;
    }
    return DFC;      

}

// //Main function : game looping function
int main ()
{
    std::string PlayerName;
    std::cout << "Enter your Name: ";
    std::cin >> PlayerName ;
    int DFC = SetDifficult();
    SnakeGame snake;
    
    snake.GameInit();
    while (!snake.getIsGameOver())
    {
        snake.GameRender(PlayerName);
        snake.Input();
        snake.UpdateGame();
        // Creating a delay for accorfing to chosen difficulty
        sleep(DFC);

#ifdef _WIN32
        Sleep(100); // Windows sleep function (milliseconds)
#else
        usleep(DFC * 1000); // Unix sleep function (microseconds)
#endif
    }


    return 0 ;
}


