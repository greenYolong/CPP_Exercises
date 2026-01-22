#include <iostream>
#include <thread>

#include "Card.hpp"
#include "Player.hpp"

int main() {
    // const Card c1 {Value::Eight, Color::Spade};
    // std::cout << c1 << std::endl;

    // const Card c2 { Value::Eight, Color::Heart };
    // std::cout << (c2 == c1) << std::endl; // -> 1
    // const Card c3 { Value::Ace, Color::Diamond };
    // std::cout << (c2 == c3) << std::endl; // -> 0 

    // std::cout << (c1 < c2) << std::endl; // -> 0
    // std::cout << (c1 < c3) << std::endl; // -> 1
    // std::cout << (c3 < c1) << std::endl; // -> 0

    // const Card c4 { Value::Ace, Color::Club};
    // std::cout << c4 << std::endl;

    // Player p1 { "Gerald" };
    // Player p2 { "Julien" };
    // Player::deal_all_cards(p1, p2);

    // for (auto i = 0; i < 16; ++i)
    // {
    //     std::cout << p1[i] << std::endl;
    //     std::cout << p2[i] << std::endl;
    // }

    using namespace std::chrono_literals;

    Player p1 { "Gerald" };
    Player p2 { "Julien" };
    Player::deal_all_cards(p1, p2);

    while(!Player::play(p1, p2)){
        std::cout << "Score: " << p1.getScore() << " - " << p2.getScore() << " !" << std::endl << std::endl;
        std::this_thread::sleep_for(1000ms);
    }
    std::cout << "Score: " << p1.getScore() << " - " << p2.getScore() << " !" << std::endl;
    std::cout << std::endl;

    auto s1 = p1.getScore();
    auto s2 = p2.getScore();
    if(s1 == s2){
        std::cout << "Its a draw !" << std::endl;
    } else if (s1 < s2) {
        std::cout << p2.getName() << " won this game! GG EZ" << std::endl;
    } else {
        std::cout << p1.getName() << " won this game! THX FOR TUTO" << std::endl;
    }

    return 0;
}