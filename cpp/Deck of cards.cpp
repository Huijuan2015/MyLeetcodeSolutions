这道题让我们设计一个21点纸牌游戏的数据结构，用面向对象的思想来设计。
首先要搞清楚what he means by generic? 那么既然21点是一种特定的纸牌游戏，它可以是从普通纸牌的基础上派生出来的。所以我们先实现最基本的纸牌类Card，里面包括值和花色，还有一些基本的判断或标记可用性的函数。
然后就是基本的牌堆类Deck，可以用来加入牌，洗牌，发牌以及算剩余牌数。
还需要一个当前手牌类Hand，可以计算当前分数，可以加牌等。
然后就是它们的派生类21点纸牌类BlackJackCard，包括计算值，计算最大最小值，判断是不是Ace等等，
然后就是21点手牌类BlackjackHand，计算当前得分，判断是否爆了，是否是21点等等。


#include <string>
#include <unordered_map>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;


// C++ defination
enum Suit { Club = 0, Diamond, Heart, Spade };

vector<string> SUITS = { "C", "D", "H", "S" };
vector<string> RANKS = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
unordered_map<string, int> VALUES({ { "A", 1 }, { "2", 2 }, { "3", 3 }, { "4", 4 }, { "5", 5 }, { "6", 6 },
{ "7", 7 }, { "8", 8 }, { "9", 9 }, { "10", 10 }, { "J", 10 }, { "Q", 10 }, { "K", 10 } });

template<class T> //T is type of Card
class Deck {
public:
    Deck() {
        _dealtIndex = 0;
    }

    // 初始化cards，或者重新赋值 
    void setDeckOfCards(vector<T> deckOfCards) {
        _cards = deckOfCards;
    };

    // 洗牌 
    void shuffle() {
        random_shuffle(_cards.begin(), _cards.end());
        _dealtIndex = 0; //reset it!!!
        /*
        int n = nums.size();
        srand(time( NULL));
        for ( int i = 0; i < n; i++) {
        int id = rand() % n;
        cout << id << endl;
        swap( nums[i], nums[id]);
        }

        */
    };

    //计算还有几张牌
    int remainingCards() {
        return _cards.size() - _dealtIndex;
    }

    //Deals a hand of cards from the deck. 
    //size is the number of the hand to deal
    //returns: an array of cards deal to hand, 
    //or empty if there are not enough cards in the deck to deal the hand
    vector<T> dealHand(int size)
    {
        if (remainingCards() < size) {
            //no enought cards left
            return vector<T>();
        }
        vector<T> cards_hand = _cards(_cards.begin() + _dealtIndex, _cards.begin() + _dealtIndex + size);
    };

    //deal the next card in the deck
    T dealCard() throw(out_of_range){
        if (_dealtIndex > cards.size())
            return crads[_dealtIndex++];
        else {
            throw out_of_range("Errow: no more cards!\n");
            return _cards.back();
        }
    };
private:
    vector<T> _cards;//all cards, dealt or not
    int _dealtIndex = 0; //marks first undealt card，给remainingCards函数用的
};

class Card {
public:        
    Card(int c, Suit s) : _faceValue(c), _suit(s) {};
    virtual int value() = 0;
    Suit suit() { return _suit; };
    //Checks if the card is available to be given out to someone
    bool isFaceUp() { return _faceup; };
    void markFaceDown() { _faceup = false; };
    void markFaceUp() { _faceup = true; };
    void flip() { _faceup = ~_faceup; };
    string toString() {
        return (RANKS[_faceValue] + SUITS[_suit]);
    }
protected:
    int _faceValue;//number or face that's on card - a number 2 through 10, or 11
    //    for Jack, 12 for Queen, 13 for King, or 1 for Ace
    Suit _suit;
private:
    bool _faceup = true;    
};

template<class T>
class Hand {
public:
    //Returns the total value of the hand
    int score() {
        int score = 0;
        for (T card : cards) {
            score += card.value();
        }
        return score;
    }
    //Adds a card to the hand
    void addCard(T card) {
        cards.add(card);
    }
    void clearCard() {
        cards.clear();
    }
protected:
    vector<T> cards;
};

class BlackJackCard : public Card {
public:
    BlackJackCard(int c, Suit s) : Card(c, s) {};
    int value() {
        if (isAce()) return 1;
        else if (_faceValue >= 11 && _faceValue <= 13) return 10;
        else return _faceValue;
    }
    int minValue() {
        if (isAce()) return 1;
        else return value();
    }
    int maxValue() {
        if (isAce()) return 11;
        else return value();
    }
    bool isAce() {
        return _faceValue == 1;
    }
    bool isFaceCard() {
        return _faceValue >= 11 && _faceValue <= 13;
    }
};

class BlackjackHand : public Hand<BlackJackCard> {
public:
    int score() {
        vector<int> scores = possibleScores();
        int maxUnder = INT_MIN, minOver = INT_MAX;
        for (auto a : scores) {
            if (a > 21 && a < minOver) {
                minOver = a;
            }
            else if (a <= 21 && a > maxUnder) {
                maxUnder = a;
            }
        }
        return maxUnder == INT_MIN ? minOver : maxUnder;
    }
    bool busted() { return score() > 21; };
    bool is21() { return score() == 21; };
    bool isBlackJack() {}; // ...
private:
    //return a list of all possible scores this hand could have
    //Ace: 1 or 11
    vector<int> possibleScores() {
        int no_ace_score = Hand::score();
        vector<int> p_s;
        p_s.emplace_back(no_ace_score);
        for (auto card : cards) {
            if (card.isAce()) {
                no_ace_score += 10;
                p_s.emplace_back(no_ace_score);
            }
        }
        return p_s;
    }; 
};