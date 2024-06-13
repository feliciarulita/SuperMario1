//
// Created by Felicia Rulita on 2024/5/22.
//

#ifndef SUPERMARIO1_BRICKS_H
#define SUPERMARIO1_BRICKS_H

#include <vector>
#include <string>
#include <__memory/shared_ptr.h>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include "Character.h"

class Brick : public Character{
public:
    explicit Brick(const std::string& ImagePath);

    template<typename T>
    std::tuple<bool,int> IsHeaded(std::vector<std::shared_ptr<T>> Objects){
        for(int i=0;i<Objects.size();i++){
            //return IsStepOn(i);
            auto tiles = Objects[i];
            bool collideY = (tiles->GetPosition().y-tiles->GetScaledSize().y/2 <= GetPosition().y+ GetScaledSize().y/2);
            bool collideX = GetPosition().x == tiles->GetPosition().x;

            LOG_DEBUG("isheaded coins");
            LOG_DEBUG(GetPosition().x);
            LOG_DEBUG(tiles->GetPosition().x);

            if((collideX) && (collideY)) {
                return {true,i};
            }

        }
        return {false,-1};
    }

    // CharacterTimePhysics => hold the value of the time we used in physics => esplecially fall, jump, etc.
    float CharacterTimePhysics = 0.0f;

    bool isMushInside = false;

    bool isHeaded = false;

    unsigned long marioHeadTime = 0;

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};

#endif //SUPERMARIO1_BRICKS_H
