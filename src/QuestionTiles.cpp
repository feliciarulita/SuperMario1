//
// Created by Felicia Rulita on 2024/4/11.
//

#include "QuestionTiles.h"

QuestionTiles::QuestionTiles(const std::vector<std::string> &QuestionPaths) : AnimatedCharacter(QuestionPaths){
    m_Drawable = std::make_shared<Util::Animation>(QuestionPaths, false, 500, false, 0);
}