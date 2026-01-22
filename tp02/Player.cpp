#include <algorithm>
#include <random>
#include <iostream>

#include "Player.hpp"

Player::Player(const std::string& name)
    : _name { name }
{}

Card Player::operator[](int index) const{
    return _cards[index];
}

std::string Player::getName() const {
    return _name;
}

unsigned int Player::getScore() const {
    return _score;
}

void Player::score(){
    _score++;
}

void Player::score(int points){
    _score+=points;
}

void Player::deal_all_cards(Player& p1, Player& p2) {
    turn_number = 0u;
    std::vector<Card> all_cards;
    for(auto color: all_color){
        for(auto value: all_value){
            all_cards.emplace_back(value, color);
        }
    }

    std::random_device rd;
    std::shuffle(all_cards.begin(), all_cards.end(), std::default_random_engine(rd()));

    size_t i = 0;
    for(; i < all_cards.size()/2; i++){
        p1._cards.emplace_back(all_cards[i]);
    }
    for(; i < all_cards.size(); i++){
        p2._cards.emplace_back(all_cards[i]);
    }
}

// return true if game is over, else return false
bool Player::play(Player& p1, Player& p2) {
    std::cout << "------------- TURN " << turn_number << " -------------" << std::endl;

    auto c1 = p1[turn_number];
    auto c2 = p2[turn_number];
    std::cout << p1._name << " played " << c1 << std::endl;
    std::cout << p2._name << " played " << c2 << std::endl;

    if(c1 == c2){
        std::cout << "Draw, no points won" << std::endl << std::endl;
        
        if(turn_number + 1 == 16){
            return true;
        } 
        turn_number++;
        points++;
        return play(p1,p2);
    } else if (c1 < c2) {
        std::cout << p2._name << " won this round: " << points << " point(s)!" << std::endl;
        p2.score(points);
    } else {
        std::cout << p1._name << " won this round: " << points << " point(s)!" << std::endl;
        p1.score(points);
    }
    points = 1u;
    turn_number++;

    return turn_number == 16;
}