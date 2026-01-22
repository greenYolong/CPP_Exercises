#pragma once

#include <string>
#include <vector>

#include "Card.hpp"

class Player{
public:
    Player(const std::string& name);

    Card operator[](int index) const;
    std::string getName() const;
    unsigned int getScore() const;
    void score();
    void score(int points);
    
    static inline unsigned int turn_number;
    static void deal_all_cards(Player& p1, Player& p2);
    static bool play(Player& p1, Player& p2);

private:
    std::string _name;
    std::vector<Card> _cards; //vector vide par défault
    unsigned int _score = 0u; //undefined par défaut
    static inline unsigned int points = 1u;
};

