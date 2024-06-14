//
// Created by Felicia Rulita on 2024/3/12.
//

#ifndef SUPERMARIO1_APP_H
#define SUPERMARIO1_APP_H

#include "Util/Root.hpp"
#include "Character.h"
#include "Util/Text.hpp"
#include "AnimatedCharacter.h"
#include "PhaseResourcesManager.h"
#include "Util/SFX.hpp"
#include "Util/BGM.hpp"
#include "QuestionTiles.h"
#include "TEXTS.h"
#include "Mario.h"
#include "Mushroom.h"
#include "Koopa.h"
#include "YellowMush.h"
#include "Bricks.h"
#include "Coins.h"
#include "Piranha.h"

class Phase;

class App {
public:
    enum class Phases {
        MENU,
        BEGINNING,
        FIRST_WORLD_ONE,
        FIRST_WORLD_TWO,
    };

    explicit App(Phases phase);

    ~App() = default;

    void Update();

    void ChangePhase(Phases phase);

    void SetPhase(Phases phase);

    Util::Root m_Root;

    std::shared_ptr<Phase> m_CurrentPhase = std::shared_ptr<Phase>();

    Phases m_Phase = Phases::MENU;

    int MarioLevel = 0;
    int MarioLives = 3;

    bool debugMode = false;

};

#endif //SUPERMARIO1_APP_H
