/*
Author: Lina Dbagh
This file processes the JSON data by placing the team names and respective stores for each game within a Game object that is then stored into a vector, providing us with a collection of Game objects with data about each game.
Date: Jan 31, 2023
*/

#include "Game.h"
using namespace std;
using json = nlohmann::json;


// Game constructor takes in the data corresponding to team names and respective stores and initializes them

Game::Game(string home_team, string away_team, int home_score, int away_score) {
    m_home_team = home_team;
    m_away_team = away_team;
    m_home_score = home_score;
    m_away_score = away_score;
}

// Deconstructor
Game::~Game() {}

// Setter methods
void Game::setHomeTeam(const string home_team) { m_home_team = home_team;}

void Game::setAwayTeam(const string away_team) { m_away_team = away_team;}

void Game::setHomeScore(int home_score) { m_home_score = home_score;}

void Game::setAwayScore(int away_score) { m_away_score = away_score;}

// Getter methods
string Game::getHomeTeam() const { return m_home_team;}

string Game::getAwayTeam() const { return m_away_team;}

int Game::getHomeScore() const {return m_home_score;}

int Game::getAwayScore() const { return m_away_score;}

/*
Function Name: parseJSON
Description: parseJSON is a function to parse the JSON string into a vector containing a collection of Game objects
Parameters: the JSON data represented as a string
Return: the vector containing all the Game objects
*/
vector<Game> Game::parseJSON(const string &json_data) {
    vector<Game> games; // declare the game vector
    json j = json::parse(json_data); // parse the string into JSON format
    
    // iterate through the JSON data and assign the team names and scores from each corresponding game into its own Game object, then add the Game object to the vector
    for (json date : j["dates"]) {
        for (json game : date["games"]) {
            string home_team = game["teams"]["home"]["team"]["name"];
            string away_team = game["teams"]["away"]["team"]["name"];
            int home_score = game["teams"]["home"]["score"];
            int away_score = game["teams"]["away"]["score"];
            Game g(home_team, away_team, home_score, away_score);
            games.push_back(g);
        }
    }
	
    return games;
}
