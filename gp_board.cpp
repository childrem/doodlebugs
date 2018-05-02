/**********************************************
            INITIALIZE GAME BOARD
***********************************************/

void Board::initBoard(){


    std::cout << "Would you like to choose the size of the board?" << std::endl;
    std::cout << "1. Yes," << std::endl;
    std::cout << "2. No," << std::endl;

    int xDimension;
    int yDimension;
    int userChoice = intYomu(1, 2, "strict");
    bool customBoard = false; //used for our random spawning point function

    if (userChoice == 1) {
      std::cout << "How big is the board? (Format: X by Y tiles)" << std::endl;    
      std::cout << "X: " << std::endl;
      xDimension = intYomu(20);  //My input validator reads this as: "input must be 20 or greater to be valid"
      std::cout << "Y: " << std::endl;
      yDimension = intYomu(20);
      bool customBoard = true;
      
    }

    else {
      std::cout << "Okay, the board will be 20x20." << std::endl;
      xDimension = 20;
      yDimension = 20;
    }

    //create the board (dynamic 2D array)
    boardGoesHere = new Critter**[xDimension];
    for (int i = 0; i < yDimension; i++)
        boardGoesHere[i] = new Critter*[yDimension];
}