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

    Game object;

    string command;
    string direction;

    cout << "Please select a race for your player" << endl;
    cout << "Drow : 'd'" << endl;
    cout << "Goblins : 'g'" << endl;
    cout << "Shade : 's'" << endl;
    cout << "Troll : 't'" << endl;
    cout << "Vampire : 'v'" << endl;
    cin >> command;

    if (command == "d") {

    } else if (command == "g") {

    } else if (command == "s") {

    } else if (command == "t") {

    } else  if (command == "v") {

    }


    while(cin >> command) {

        if (determineDirection(direction, command)) {  //  return true if the command is a direction
            
        } else if (command == "u") {

        } else if (command == "a") {

        } else {
            cout << "wrong input, dumbass" << endl;
        }

    }




}




