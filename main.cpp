/*
Author: Lina Dbagh
This file contains the main function for our program which will pull the data, process it, and then output the team names and scores pertaining to each game
Date: Jan 31, 2023
*/

#include <iostream>
#include "Request.h"
#include "Game.h"

using namespace std;

int main() {
    Request request("https://statsapi.web.nhl.com/api/v1/schedule?season=20222023&gameType=R"); // create our request using the URL for the schedule API
    
    // if the request fails to execute, print an error message to the user and exit the program
    if (!request.execute()) {
        cout << "Failed to download JSON data" << endl;
        return 1;
    }
   
    string jsonData = request.result(); // if the request is successful, assign the result of the request to a string to contain the JSON data
    vector<Game> games = Game::parseJSON(jsonData); // parse the JSON data and store it in a vector
    
    // iterate through the games vector and print out the data pertaining to the teams playing against each other and their respective scores for each game
    for (auto& game : games) {
        cout << game.getHomeTeam() << " vs. " << game.getAwayTeam() << ": " << game.getHomeScore()  << " - " << game.getAwayScore() << endl;
    }
    return 0;
}
