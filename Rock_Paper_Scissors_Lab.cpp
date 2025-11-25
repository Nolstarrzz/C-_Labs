#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// possible moves
enum rpsmove {ROCK, PAPER, SCISSORS, LIZARD, SPOCK};

const vector<rpsmove> RPS_MOVES = {ROCK, PAPER, SCISSORS};
const vector<rpsmove> RPS_MOVES_ADVANCED = {ROCK, PAPER, SCISSORS, LIZARD, SPOCK};

// helper function to get a friendly string value for the enums
string rpsmove_to_string(rpsmove m)
{
    // take an incoming enum values and return something legibile
    // ie. rpsmove_to_string(ROCK) -> "Rock"
    if(m == ROCK)
        return "Rock";
    else if(m == PAPER) 
        return "Paper";
    else if(m == SCISSORS) 
        return "Scissors";
    else if(m == LIZARD) 
        return "Lizards";
    else if(m == SPOCK) 
        return "Spock";
    else
        return "N/A";
}

// get the type of game to play
void get_game_type(int& choice)
{
    // build menu of game options and prompt user for selection
    cout << "Please select the game you would like to play: " << endl <<
        "1. Basic Game"<< endl <<
        "2. Best of 5" << endl <<
        "3. Best of 3 Advanced Mode (RPS + Lizard, Spock)" << endl <<
        "4. Quit" << endl <<
        "Choice (1-4): ";
    cin >> choice;

}

// display list of user moves, allowing them to enter a number for their choice
// eg. 0:Rock 1:Paper 2:Scissors
rpsmove get_user_move(bool advanced)
{
    // prompt the user for their move, based on game type
    int choice;
    cout << "Enter your choice (";
    if (advanced)
    {
        // handle displaying move options for advanced mode
        for(int i = 0; i< RPS_MOVES_ADVANCED.size(); i++)
        {
            cout << i << ": " << rpsmove_to_string(RPS_MOVES_ADVANCED[i]) << " ";
        }
        cout << "): ";
        cin >> choice;
        return RPS_MOVES_ADVANCED[choice];
    }
    else
    {
        // handle displaying move options for basic mode
        for(int i = 0; i< RPS_MOVES.size(); i++)
        {
            cout << i << ": " << rpsmove_to_string(RPS_MOVES[i]) << " ";
        }
        cout << "): ";
        cin >> choice;
        return RPS_MOVES[choice];
    }
}

// return a computer generated move from the appropriate vector of moves 
rpsmove get_computer_move(bool advanced) 
{
    // generate a random computer move
    int compMove;
    if(advanced)
    {
        compMove = rand() % RPS_MOVES_ADVANCED.size();
        return RPS_MOVES_ADVANCED[compMove];
    }
    else
    {
       compMove = rand() % RPS_MOVES.size();
       return RPS_MOVES[compMove];
    }
}

// function to determine the winner, should return one of "Player", "Computer" or "Tie"
string check_winner(rpsmove player, rpsmove computer, bool advanced) {
    // compare player and computer moves and return who the winner is,
    string winner;
    
    if(advanced)
    {
        if(player == computer)
            return winner = "Tie";
        else if(
            player == ROCK && computer == LIZARD || 
            player == LIZARD && computer == SPOCK ||
            player == SPOCK && computer == SCISSORS ||
            player == SCISSORS && computer == LIZARD ||
            player == LIZARD && computer == PAPER ||
            player == PAPER && computer == SPOCK ||
            player == SPOCK && computer == ROCK ||
            player == ROCK && computer == SCISSORS || 
            player == PAPER && computer == ROCK ||
            player == SCISSORS && computer == PAPER
        )
            return "player"; 
        else
            return "computer";
    }
    else
    {
         if(player == computer)
            return winner = "Tie";
        else if(
            player == ROCK && computer == SCISSORS || 
            player == PAPER && computer == ROCK ||
            player == SCISSORS && computer == PAPER 
        )
            return "player"; 
        else
            return "computer";
    }
}

// Play a single round of rock, paper, scissors
void play_rps() {

    rpsmove player_move, computer_move;
    string winner;

    player_move = get_user_move(false);
    
    computer_move = get_computer_move(false);

    // get computer move

    // check who won and display result
    winner = check_winner(player_move, computer_move, false);
    cout << "Computer Chose: " << rpsmove_to_string(computer_move) << endl;
    if(winner == "player")
        {
            cout << "You won this Round!" << endl;
        }
        else if(winner == "computer")
        {
            cout << "The computer won this Round!" << endl;
        }
        else
            cout << "It was a Tie!" << endl;
}

// overloaded: Play with advanced rules
void play_rps(int rounds, bool advanced) {

    // keep track of winner for each round
    int p_wins = 0, c_wins = 0;

    // run the game for the given number of rounds 
    for (int i = 0; i < rounds; i++) {
        int var = i+1;
        string winner;
        rpsmove player_move, computer_move;
        cout << "Round " << var << " - ";
        // get player and computer moves
        player_move = get_user_move(advanced);
        computer_move = get_computer_move(advanced);
        cout << "Computer Chose: " << rpsmove_to_string(computer_move) << endl;
        winner = check_winner(player_move, computer_move, advanced);
        if(winner == "player")
        {
            p_wins++;
            cout << "You won this Round!" << endl;
        }
        else if(winner == "computer")
        {
            c_wins++;
            cout << "The computer won this Round!" << endl;
        }
        else
            cout << "It was a Tie!" << endl;
        // check who won the round, updating counters
    }
    cout << "Final Results: " << endl << "Player Wins: " << p_wins << endl <<
    "Computer Wins: " << c_wins << endl;
    if(p_wins > c_wins)
        cout << "Congratulations! You won the game." << endl;
    else
        cout << "Aw, the Computer won the game." << endl;
    // display final results

}

int main() {

    // seed our random number generator
    srand(time(0));

    int choice = 0;
    cout << "Welcome to Rock, Paper, Scissors [Lizard, Spock]!\n";

    do 
    {
        // ask user for type of game to play
        get_game_type(choice);
        switch(choice)
        {
            case 1:
                play_rps();
                break;
            case 2:
                play_rps(5, false);
                break;
            case 3:
                play_rps(3, true);
                break;
            default:
                exit(1);
        }

        // execute correct overloaded function based on selection
    } while (choice != 4);
    return 0;
}
