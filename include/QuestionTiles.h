//
// Created by Felicia Rulita on 2024/4/11.
//

#ifndef SUPERMARIO1_QUESTIONTILES_H
#define SUPERMARIO1_QUESTIONTILES_H
#include <vector>
#include <string>
#include <__memory/shared_ptr.h>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include "AnimatedCharacter.h"

class QuestionTiles : public AnimatedCharacter {
public:
    explicit QuestionTiles(const std::vector<std::string>& QuestionPaths);

    bool isHeaded = false;
    bool isActive = true;
    bool isMushInside = false;

    int indexMush;

    unsigned long marioHeadTime = 0;

};

#endif //SUPERMARIO1_QUESTIONTILES_H
