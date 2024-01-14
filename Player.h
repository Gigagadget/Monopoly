#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector> 
#include "property.h"

class Player {
public:

    char name;
    //std::vector<Property> ownedProperties;
    bool isHuman;
    int gold;
    //const Property* currentLocation; // Puntatore alla casella corrente
    int currentLocation;
    int initTurn;
    bool HasLost; // Flag per indicare se il giocatore ha perso
    const int boardSize = 28;

    Player(const char& playerName, bool human);
    /*
    std::string name;
    std::vector<Property> ownedProperties;
    bool isHuman;
    int gold;
    const Property* currentLocation; // Puntatore alla casella corrente
    bool HasLost; // Flag per indicare se il giocatore ha perso

    Player(cconst std::string& playerName, bool human, int initialDiceRoll);
    */
   
    //metodo lancio dadi
    int getDiceRoll();
    //inizializzazione e settaggio della posizione del giocatore
    void setPosition(int diceResult);
    //recupero informazioni sulla cella pari alla positzione del player
    const Property* getPosition() const;
    //effetuare il turno con tiro di due dadi e eventuale mossa di acquisto o pagamento
    void takeTurn();
    //pagamento affitto sulla casella
    void payPlayer(const Player& propertyOwner, int rentAmount);
    
private:
    void move(int steps);
    bool checkBalance(int amount);
    void humanChoice();
};

#endif  // PLAYER_H
