//
// Created by Felicia Rulita on 2024/6/11.
//

#ifndef SUPERMARIO1_COINS_H
#define SUPERMARIO1_COINS_H

#include <vector>
#include <string>
#include <__memory/shared_ptr.h>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include "AnimatedCharacter.h"

class Coins : public AnimatedCharacter{
public:
    explicit Coins(const std::vector<std::string>& AnimationPaths);

    bool isActive = false;
    bool alreadyOut = false;

    unsigned long marioHeadTime = 0;

    /** 0 = Brick
     *  1 = Question
     */
    int headedBy = -1;
};

#endif //SUPERMARIO1_COINS_H
