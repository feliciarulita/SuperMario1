//
// Created by Felicia Rulita on 2024/6/12.
//
#include "Piranha.h"

Piranha::Piranha(const std::vector<std::string>& AnimationPaths) : AnimatedCharacter(AnimationPaths){
    m_Drawable = std::make_shared<Util::Animation>(AnimationPaths, false, 500, false, 0);
}