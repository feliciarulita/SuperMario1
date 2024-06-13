//
// Created by Felicia Rulita on 2024/6/11.
//
#include "Coins.h"

Coins::Coins(const std::vector<std::string>& AnimationPaths) : AnimatedCharacter(AnimationPaths){
    m_Drawable = std::make_shared<Util::Animation>(AnimationPaths, false, 500, false, 0);
}