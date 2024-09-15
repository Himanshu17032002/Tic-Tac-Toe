# Tic-Tac-Toe

#1 .Game Board:

The board is a 3x3 array initialized with numbers (1-9) representing the positions where players can place their marks.
#2 .Display Board:

The displayBoard function prints the current state of the Tic-Tac-Toe board.
#3 .Player Input:

The current player is asked to enter their move (a number between 1 and 9). The input is then mapped to a row and column on the board using the formulas:
cpp

 int row = (move - 1) / 3;
 int col = (move - 1) % 3;
#4 .Update Board:

The board is updated with the player's move, provided the chosen cell is not already occupied by 'X' or 'O'. If the move is invalid (cell already taken), the player is prompted to try again.
#5 .Check for Win:

The checkWin function checks if the current player has won by evaluating:
All three cells in any row.
All three cells in any column.
Both diagonals.
#6 .Check for Draw:

The checkDraw function checks if the board is full and no player has won, meaning the game is a draw.
#7 .Switch Players:

The switchPlayer function alternates turns between player 'X' and player 'O' after each valid move.
#8 .Game Result:

The game ends when either a player wins or there is a draw. The result is displayed to the players.
