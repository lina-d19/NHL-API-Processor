/*
Author: Lina Dbagh
This is the header file for the Game class.
Date: Jan 31, 2023
*/

#ifndef ASSIGNMENT1_GAME_H
#define ASSIGNMENT1_GAME_H

#include <string>
#include <vector>
#include "json.hpp"
#include "Request.h"

class Game {

private:
    std::string m_home_team;
    std::string m_away_team;
    int m_home_score;
    int m_away_score;

public:
    //Constructor
    Game(std::string home_team, std::string away_team, int home_score, int away_score);

    // Destructor
    ~Game();
    // Accessor methods
    std::string getHomeTeam() const;
    void setHomeTeam(const std::string home_team);

    std::string getAwayTeam() const;
    void setAwayTeam(const std::string away_team);

    int getHomeScore() const;
    void setHomeScore(int home_score);

    int getAwayScore() const;
    void setAwayScore(int away_score);
    static std::vector<Game> parseJSON(const std::string& json_data);
};

#endif //ASSIGNMENT1_GAME_H
