//
// Created by Felicia Rulita on 2024/6/12.
//

#ifndef SUPERMARIO1_PIRANHA_H
#define SUPERMARIO1_PIRANHA_H

#include <vector>
#include <string>
#include <__memory/shared_ptr.h>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include "AnimatedCharacter.h"

class Piranha : public AnimatedCharacter{
public:
    explicit Piranha(const std::vector<std::string> & AnimationPaths);

    int direction = 1;

    bool goUp = true;
    bool EnemyDie = false;
};

#endif //SUPERMARIO1_PIRANHA_H
