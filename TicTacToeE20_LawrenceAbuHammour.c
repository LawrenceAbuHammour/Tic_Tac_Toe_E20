/*Tic-Tac-Toe:Dartmouth Style
* Created by: Lawrence Abu-Hammour '19
* Created on: April 26, 2016
* Engineering Sciences 20: Introduction to Scientific Computing
* Dartmouth College
*/

#include <stdio.h> /*printf and scanf definitions*/

/*Function Prototypes for functions used in this game*/
int legalMove (char a, char b, char c, char d, char e, char f, char g, char h, char i, int input);
int gameWon (char a, char b, char c, char d, char e, char f, char g, char h, char i);
void displayBoard (char a, char b, char c, char d, char e, char f, char g, char h, char i);
void writeGame (char *a, char *b, char *c, char *d, char *e, char *f, char *g, char *h, char *i, char *j,int *ThePlayer);
void readGame(char *a, char *b, char *c, char *d, char *e, char *f, char *g, char *h, char *i, char *j,int *ThePlayer);

int main(void){
	
	/*Define char and int variables to be used in main function*/
	char a, b, c, d, e, f, g, h, i;
	char Symbol;
	char start;
	char j;
	int ThePlayer;
	int Space;
	int won;
	int input;
	
	
	/*Display Menu*/
	printf("********************|Welcome to Tic-Tac-Toe:Dartmouth Style!|********************\n");
	printf("To play, type a. To quit, type q.>");
	scanf("%c", &start);
	
	/*If Statement for Menu. If the player decides to play the game by typing A, the rules are displayed. If the player quits, the game terminates.
	* Informs the player that typing 15 saves the game and 20 loads the game. If the player enters a space that has already been played, they lose their turn.
	* This encourages the player to follow the rules and play the game correctly so that they do not lose their turn.
	* This menu also shows what the game board looks like so players can learn how the board looks and can play the game as is
	* This menu also informs the player that if they want to quit the game at any point without saving, they can enter 66
	*/
	if(start=='a'||start=='A'){ /*If Statement that starts the game and allows player to enter capital A and lowercase a to run game*/
		printf("Here are the rules:\n");
		printf("(1) You type in an integer between 1 and 9 to place your space. Player 1 is \'X\' and Player 2 is \'O\'.\n");
		printf("The board looks like this.\n");
		printf("				 1 | 2 | 3 \n");
        printf("				-----------\n");
        printf("				 4 | 5 | 6 \n");
        printf("				-----------\n");
        printf("				 7 | 8 | 9 \n");
		printf("\n");
		printf("(2) You may not type in an integer that another player has already entered. If you do so, you will lose your turn.\n");
		printf("(3) You may save the game at any time by entering the number 15\n");
		printf("(4) You may load a game you have already started now by typing the number 20\n");
		printf("(5) You may type in the number 66 to quit the game at any point without saving.\n");
		printf("\n");
	}else if (start=='q'||start=='Q'){ /*If Statement that allows player to enter capital Q and lowercase q to quit and terminates the game*/
		printf("If you would like to play again another time, please run the program again!\n");
		return(0);
	}else if(start!='q'||start!='Q'||start!='a'||start!='A'){ /*If the player enters another character that isn't defined, it gives them an error message and terminates the program*/
		printf("That is not a valid input. Please try again by running the game again!\n");
		return(0);
	}else{
		return(10);
	}
	
	/*Initializes all variables before while loop including all letters as spaces on the board that start off empty*/
	a=' ';
	b=' ';
	c=' ';
	d=' ';
	e=' ';
	f=' ';
	g=' ';
	h=' ';
	i=' ';
	j=' ';
	ThePlayer=1;
	won=1;
	Space=0;
	/*While there is space left on the board and the game hasn't determined a winner, the game will keep asking the players for spaces*/
	while(a==' '||b==' '||c==' '||d==' '||e==' '||f==' '||g==' '||h==' '||i==' '&&won!=0){
	
	/*Defines Player 1 as an X and Player 2 as an O*/
	if (ThePlayer==1){
		Symbol='X';
	}else{
		Symbol='O';
	}
	
	/*Get the integer for the space in the board repeatedly*/
	printf("Player %d! It's your turn! Enter an integer between 1 and 9 to fill a space on the board!>\n", ThePlayer);
	scanf("%d", &Space);
	/*If Statement that checks whether or not the move is legal. If it is, the space will be filled with Player 1's X. If not, it informs Player 1 and Player 1 loses his turn*/
	if(legalMove(a,b,c,d,e,f,g,h,i,Space)){
		if(Space==1){
			a=Symbol;
		}if(Space==2){
			b=Symbol;
		}if(Space==3){
			c=Symbol;
		}else if(Space==4){
			d=Symbol;
		}else if(Space==5){
			e=Symbol;
		}else if(Space==6){
			f=Symbol;
		}else if(Space==7){
			g=Symbol;
		}else if(Space==8){
			h=Symbol;
		}else if(Space==9){
				i=Symbol;
		}
	}else{
		printf("Awww, that space is occupied. You lose your turn! Sorry! Try again!\n");
	}
	
	/*If Statement where Player 1 enters an integer that is between 1 and 9, it switches to the next player. Otherwise, it is Player 1's Turn*/
	if(Space>=1 && Space<=9){
		if(ThePlayer==1){
			ThePlayer=2;
		}else{
			ThePlayer=1;
		}
	}
	/*If Statement for other possible inputs such as if the player enters 15 which saves the game calling the writeGame function and if the player
	* enters 20, this calls the readGame function and loads the game that was saved and if the player wants to quit the game without saving, they enter 66*/
	if(Space==15){
		writeGame(&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&ThePlayer);
		return(0);
	}else if(Space==20){
		readGame(&a,&b,&c,&d,&e,&f,&g,&h,&i,&j, &ThePlayer);
	}else if(Space==66){
		printf("Thanks for playing! Play again soon!\n"); /*Thanks the player for playing the game*/
		return(0);
	}
	/*If the player does not load the game, continue looping the game by displaying the game board by calling the displayBoard function after each integer is entered and checking if the
	* game has been won by either player and storing the return value in the variable won*/
	if(Space!=20){
	displayBoard(a,b,c,d,e,f,g,h,i);
	won=gameWon(a,b,c,d,e,f,g,h,i);
	//printf("%d", won); /*This is a debugging tool that I used to print the return value of won while testing to make sure that the game terminates and the loop breaks based on the won value*/
	if(won==1||won==2){ /*If the game has been won by Player 1 or Player 2, the loop breaks and the game ends by congratulating the winner*/
		break;
		return(0);
	}else if(won==4){ /*If the gameWon return value is 4, then there is a draw*/
		printf("This game is a draw. Feel free to try again to decide a winner. Yay Socialism!\n"); /*In the case of a draw, it informs the players of the draw*/
		return(0);
	}
	}
	
	/*Get the integer for the space for Player 2's space inputs*/
	printf("Player %d! It's your turn! Enter an integer between 1 and 9 to fill a space on the board!>\n", ThePlayer);
	scanf("%d", &Space);
	/*Defines Player 2 as an O*/
	if (ThePlayer==2){
		Symbol='O';
	}else{
		Symbol='X';
	}
	/*Checks if the move is legal. If it is, the space will be filled with Player 2's O. If not, Player 2 loses his/her turn*/
	if(legalMove(a,b,c,d,e,f,g,h,i,Space)){
		if(Space==1){ /*If the space is empty, the space will be occupied with the value of symbol*/
			a=Symbol;
		}else if(Space==2){
			b=Symbol;
		}else if(Space==3){
			c=Symbol;
		}else if(Space==4){
			d=Symbol;
		}else if(Space==5){
			e=Symbol;
		}else if(Space==6){
			f=Symbol;
		}else if(Space==7){
			g=Symbol;
		}else if(Space==8){
			h=Symbol;
		}else if(Space==9){
				i=Symbol;
		}}else{
		printf("Awww,that space is occupied. You lose your turn! Sorry! Try again!\n"); /*Tells Player 2 the Space is occupied*/
	}
	
	
	/*If the player enter a number between 1 and 9, it will automatically switch turns to the next player. Otherwise, it is Player 2's turn*/
	if(Space>=1 && Space<=9){
		if(ThePlayer==2){
			ThePlayer=1;
		}else{
			ThePlayer=2;
		}
	}
	
	
	/*If Player 2 enters 15, the game is saved by calling the writeGame function and terminating the game. If Player 2 enters 20, the previous game is read and loaded by
	* calling the readGame function. If Player 2 enters 66, the game is quit without saving*/
	if(Space==15){
		writeGame(&a,&b,&c,&d,&e,&f,&g,&h,&i,&j, &ThePlayer);
		return(0);
	}else if(Space==20){
		readGame(&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&ThePlayer);
	}else if(Space==66){
		printf("Thanks for playing! This is how your game ended. Play again soon!\n"); /*Thanks the players for playing the game*/
		return(0);
	}
	/*If the Player does not load the game, continue looping the program as it normally would by displaying the board after each move by calling the displayBoard function and checking
	* if the game has been won by calling the gameWon function and storing the gameWon return value into the variable won*/
	if(Space!=20){
	displayBoard(a,b,c,d,e,f,g,h,i);
	won=gameWon(a,b,c,d,e,f,g,h,i);
	//printf("%d", won); /*This is a debugging tool used to print the return value of gameWon to make sure that the program terminates if someone has won*/
	if(won==1||won==2){ /*If Player 1 or Player 2 has won, the loop breaks and the game terminates after congratulating Player that won*/
		break;
		return(0);
	}else if(won==4){ /*The return value for gameWon if there is a draw is 4. If the game is a draw, it informs the players and terminates the game*/
		printf("This game is a draw. Feel free to try again to decide a winner. Yay Socialism!\n");
		return(0);
		}
		}
	}
	
	}
	

/*Function Definition for the legalMove. This function checks each space to see if it is empty. If it is, then it returns 1 and if not, it returns 0*/
int legalMove (char a, char b, char c, char d, char e, char f, char g, char h, char i, int input){
	
	switch (input){ /*Switch Statement for the case of each space*/
		case 1:
			if (a==' '){
				return(1);
				break;
			}else{
				return(0);
			}
		case 2:
			if (b==' '){
				return(1);
				break;
			}else{
				return(0);
			}
		case 3:
			if (c==' '){
				return(1);
				break;
			}else{
				return(0);
			}
		case 4:
			if (d==' '){
				return(1);
				break;
			}else{
				return(0);
			}
		case 5:
			if (e==' '){
				return(1);
				break;
			}else{
				return(0);
			}
		case 6:
			if (f==' '){
				return(1);
				break;
			}else{
				return(0);
			}
		case 7:
			if (g==' '){
				return(1);
				break;
			}else{
				return(0);
			}
		case 8:
			if (h==' '){
				return(1);
				break;
			}else{
				return(0);
			}
		case 9:
			if (i==' '){
				return(1);
				break;
			}else{
				return(0);
			}
		default:
			return(3);
	}

}
/*This is the function definition for the gameWon function. It checks for each case if the game has been won or not*/
int gameWon (char a, char b, char c, char d, char e, char f, char g, char h, char i){
	if (a=='X' && b=='X' && c=='X'){ /*If Statement for Player 1's possible ways to win*/
		printf("Congratulations Player 1! You have won the game! Go out and celebrate!\n"); /*Congratulates Player 1 in each winning case*/
		return(1);
	}else if (d=='X' && e=='X' && f=='X'){
		printf("Congratulations Player 1! You have won the game! Go out and celebrate!\n");
		return(1);
	}else if (g=='X' && h=='X' && i=='X'){
		printf("Congratulations Player 1! You have won the game! Go out and celebrate!\n");
		return(1);
	}else if (a=='X' && e=='X' && i=='X'){
		printf("Congratulations Player 1! You have won the game! Go out and celebrate!\n");
		return(1);
	}else if (c=='X' && e=='X' && g=='X'){
		printf("Congratulations Player 1! You have won the game! Go out and celebrate!\n");
		return(1);
	}else if (a=='X' && d=='X' && g=='X'){
		printf("Congratulations Player 1! You have won the game! Go out and celebrate!\n");
		return(1);
	}else if (b=='X' && e=='X' && h=='X'){
		printf("Congratulations Player 1! You have won the game! Go out and celebrate!\n");
		return(1);
	}else if (c=='X' && f=='X' && i=='X'){
		printf("Congratulations Player 1! You have won the game! Go out and celebrate!\n");
		return(1);
		
	}else if (a=='O' && b=='O' && c=='O'){ /*Continuation of If Statement for Player 2's Possible Ways to Win*/
		printf("Congratulations Player 2! You have won the game! Go out and celebrate!\n"); /*Congratulates Player 2 in each winning case*/
		return(2);
	}else if (d=='O' && e=='O' && f=='O'){
		printf("Congratulations Player 2! You have won the game! Go out and celebrate!\n");
		return(2);
	}else if (g=='O' && h=='O' && i=='O'){
		printf("Congratulations Player 2! You have won the game! Go out and celebrate!\n");
		return(2);
	}else if (a=='O' && e=='O' && i=='O'){
		printf("Congratulations Player 2! You have won the game! Go out and celebrate!\n");
		return(2);
	}else if (c=='O' && e=='O' && g=='O'){
		printf("Congratulations Player 2! You have won the game! Go out and celebrate!\n");
		return(2);
	}else if (a=='O' && d=='O' && g=='O'){
		printf("Congratulations Player 2! You have won the game! Go out and celebrate!\n");
		return(2);
	}else if (b=='O' && e=='O' && h=='O'){
		printf("Congratulations Player 2! You have won the game! Go out and celebrate!\n");
		return(2);
	}else if (c=='O' && f=='O' && i=='O'){
		printf("Congratulations Player 2! You have won the game! Go out and celebrate!\n");
		return(2);
	/*If each space is occupied by either an X or O, then it returns a 4 which the main function will store in won to tell the players that the game is a draw*/
	}else if((a=='X'||a=='O')&&(b=='X'||b=='O')&&(c=='X'||c=='O')&&(d=='X'||d=='O')&&(e=='X'||e=='O')&&(f=='X'||f=='O')&&(g=='X'||g=='O')&&(h=='X'||h=='O')&&(i=='X'||i=='O')){
		return(4);
	}else{
		return(3);
	}
}
/*Function Definition for the displayBoard function. It is Void because it is not returning a value. However, this function displays the board as a normal Tic-Tac-Toe board and fills it with the value of the spaces in the main*/
void displayBoard (char a, char b, char c, char d, char e, char f, char g, char h, char i){
	
	printf("\n");
	printf(" %c | %c | %c \n"
	"-----------\n"
	" %c | %c | %c \n"
	"-----------\n"
	" %c | %c | %c \n", a, b, c, d, e, f, g, h, i);
	printf("\n");
}
/*Function Definition for the writeGame function. This function saves the game if either player so chooses to save the game. This is void because it is not returning a value*/
void writeGame (char *a, char *b, char *c, char *d, char *e, char *f, char *g, char *h, char *i, char *j, int *ThePlayer){
	
	FILE *ofile; /*Defines the file that is being worked with*/
	
	ofile=fopen("TicTacToeSave.txt", "w"); /*Opens the file for writing*/
	
	if(*a=='X'){  /*Uses pointers in an if statement to store the value of each letter if it is an X or O on the board as an A or B in the file*/
		*a='A';
	}else if(*a=='O'){
		*a='B';
	}else{
		*a=' ';
	}
	
	if(*b=='X'){
		*b='A';
	}else if(*b=='O'){
		*b='B';
	}else{
		*b=' ';
	}
	
	if(*c=='X'){
		*c='A';
	}else if(*c=='O'){
		*c='B';
	}else{
		*c=' ';
	}
	
	if(*d=='X'){
		*d='A';
	}else if(*d=='O'){
		*d='B';
	}else{
		*d=' ';
	}
	
	if(*e=='X'){
		*e='A';
	}else if(*e=='O'){
		*e='B';
	}else{
		*e=' ';
	}
	
	if(*f=='X'){
		*f='A';
	}else if(*f=='O'){
		*f='B';
	}else{
		*f=' ';
	}
	
	if(*g=='X'){
		*g='A';
	}else if(*g=='O'){
		*g='B';
	}else{
		*g=' ';
	}
	
	if(*h=='X'){
		*h='A';
	}else if(*h=='O'){
		*h='B';
	}else{
		*h=' ';
	}
	
	if(*i=='X'){
		*i='A';
	}else if(*i=='O'){
		*i='B';
	}else{
		*i=' ';
	}
	/*If the Player that just went is Player 1, then it writes an A. If the Player is Player 2, then it writes a B to the file*/
	if(*ThePlayer==1){
		*j='A';
	}else if(*ThePlayer==2){
		*j='B';
	}else{
		*j=' ';
	}
	/*If the modulus of ThePlayer is not 0, then it saves the value j as an A. If the modulus of ThePlayer is 0, then it saves the value j as B*/
	if(*ThePlayer%2!=0){
		*j='A';
	}else if(*ThePlayer%2==0){
		*j='B';
	}else{
		*j=' ';
	}
	
	fprintf(ofile,"%c,%c,%c,%c,%c,%c,%c,%c,%c,%c", *a, *b, *c, *d, *e, *f, *g, *h, *i, *j); /*Prints the values of each space of A or B into the file*/
	fclose(ofile); /*Closes file*/
	printf("The game has been successfully saved.\n");	/*Informs the player that the game has been saved successfully*/
}
/*Function Definition for the readGame function for loading a game that has been saved. It is void because it is not returning a value*/
void readGame(char *a, char *b, char *c, char *d, char *e, char *f, char *g, char *h, char *i, char*j, int *ThePlayer){
		
	FILE*ifile; /*Defines the file that is being worked with*/
	
	ifile=fopen("TicTacToeSave.txt", "r"); /*Opens the file for reading*/
	
	if(ifile==NULL){ /*In the case that the file does not exist, then it informs the player that the file doesn't exist*/
		printf("That file does not exist. Please try again.\n");
	}
	
	fscanf(ifile,"%c,%c,%c,%c,%c,%c,%c,%c,%c,%c", a,b,c,d,e,f,g,h,i,j); /*Reads the file for the values of the spaces*/
	
	if(*a=='A'){ /*Uses an If Statement similar to the one in writeGame just with reversed logic to say that if there is an A, then it is an X on the board and so on*/
		*a='X';
	}else if(*a=='B'){
		*a='O';
	}else{
		*a=' ';
	}
	
	if(*b=='A'){
		*b='X';
	}else if(*b=='B'){
		*b='O';
	}else{
		*b=' ';
	}
	
	if(*c=='A'){
		*c='X';
	}else if(*c=='B'){
		*c='O';
	}else{
		*c=' ';
	}
	
	if(*d=='A'){
		*d='X';
	}else if(*d=='B'){
		*d='O';
	}else{
		*d=' ';
	}
	
	if(*e=='A'){
		*e='X';
	}else if(*e=='B'){
		*e='O';
	}else{
		*e=' ';
	}
	
	if(*f=='A'){
		*f='X';
	}else if(*f=='B'){
		*f='O';
	}else{
		*f=' ';
	}
	
	if(*g=='A'){
		*g='X';
	}else if(*g=='B'){
		*g='O';
	}else{
		*g=' ';
	}
	
	if(*h=='A'){
		*h='X';
	}else if(*h=='B'){
		*h='O';
	}else{
		*h=' ';
	}
	
	if(*i=='A'){
		*i='X';
	}else if(*i=='B'){
		*i='O';
	}else{
		*i=' ';
	}
	/*If the final character is an A or B, then the Player that goes is Player 1 or Player 2, respectively*/
	if(*j=='A'){
		*ThePlayer=1;
	}else if(*j='B'){
		*ThePlayer=2;
	}else{
		*j=' ';
	}
	
	displayBoard(*a,*b,*c,*d,*e,*f,*g,*h,*i); /*Displays the Board with how the saved game was written*/
	
	fclose(ifile); /*Closes the file*/
	
}