#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "game.h"


using namespace std;

bool determineDirection(string &dir, string &cmd) { //  return true if the command is a direction
    if (cmd == "no") {
        dir = "no";
    } else if (cmd == "so") {
        dir = "so";
    } else if (cmd == "ea") {
        dir = "ea";
    } else if (cmd == "we") {
        dir = "we";
    } else if (cmd == "ne") {
        dir = "ne";
    } else if (cmd == "nw") {
        dir = "nw";
    } else if (cmd == "se") {
        dir = "se";
    } else if (cmd == "sw") {
        dir = "sw";
    } else {
        return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {


    //  Game object;
    string command;
    string secondCommand;
    string direction;
    string race;

    

    // Floor newfloor = object.getFloor();

    cout << "Please select a race for your player" << endl;
    cout << "Drow : 'd'" << endl;
    cout << "Goblins : 'g'" << endl;
    cout << "Shade : 's'" << endl;
    cout << "Troll : 't'" << endl;
    cout << "Vampire : 'v'" << endl;
    cin >> command;

    if (command == "d") {
        race = "Drow";
    } else if (command == "g") {
        race = "Goblin";
    } else if (command == "s") {
        race = "Shade";
    } else if (command == "t") {
        race = "Troll";
    } else  if (command == "v") {
        race = "Vampire";
    }

    Game object(race);
    object.newGame();


 //   std::cout << "\x1B[2J\x1B[H";
    object.render();
    cout << "Action: Player character has spawned"<<endl;

//    cout<<newfloor.charAt(3,5);




    while(cin >> command) {
    
        if (determineDirection(direction, command)) {  //  return true if the command is a direction
            //cout<<direction;

            string tmp_dir;
            object.moveplayer(direction);
         //   std::cout << "\x1B[2J\x1B[H";
            

            if (direction == "no") {
                tmp_dir = "North";
            } else if (direction == "so") {
                tmp_dir = "South";
            } else if (direction == "ea") {
                tmp_dir = "East";
            } else if (direction == "we") {
                tmp_dir = "West";
            } else if (direction == "ne") {
                tmp_dir = "NorthEast";
            } else if (direction == "nw") {
                tmp_dir = "NorthWest";         
            } else if (direction == "se") {
                tmp_dir = "SouthEast";
            } else if (direction == "sw") {
                tmp_dir = "SouthWest";
            }

            cout << "Action: Player moves " << tmp_dir << endl;

        } else if (command == "u") {

            cin >> secondCommand;

            if (determineDirection(direction, secondCommand)) {
                int newRow = object.newRowWrtPlayer(direction);
                int newCol = object.newColWrtPlayer(direction);
                
                if (object.getFloor().charAt(newRow, newCol) == 'P') {
                    
                    // object.getpotions();
                    object.usePotion(newRow, newCol);
                    object.resetChar(newRow, newCol);

                    object.render();
                    cout << "Used a potion" << endl;
                } else {
                    object.render();
                    cout << "no potion there, dumbass" << endl;
                }
            } else {
                object.render();
                cout << "wrong input, dumbass" << endl;
            }
            
        } else if (command == "a") {

        } else {
            cout << "wrong input, dumbass" << endl;
        }
        
        bool playerStatus = object.getPlayerStatus();

        if (!playerStatus) {
            char end; 

            while(true){
                cout<<"The Game is over. Do uu want to continue. Press r to restart the game and q to quit"<< endl;
                cin>>end;
                if (end == 'r') {
                    object.newGame();
                    break;
                } 
                else if(end == 'q'){
                    return 0;
                }
                else {
                    cout << "``wrong input" << endl;
                }
            }
        } 

        object.render();
    }
}




