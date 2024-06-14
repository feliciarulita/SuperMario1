//
// Created by Felicia Rulita on 2024/4/29.
//

#ifndef SUPERMARIO1_KOOPA_H
#define SUPERMARIO1_KOOPA_H

#include <vector>
#include <string>
#include <__memory/shared_ptr.h>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include "AnimatedCharacter.h"
#include "Character.h"

class Koopa : public AnimatedCharacter{
public:
    explicit Koopa(const std::vector<std::string>& AnimationPaths);

    template<typename T>
    bool IsCollideRight(std::vector<std::shared_ptr<T>> Object ){
        for(int i=0;i<Object.size();i++){
            auto tiles = Object[i];
            bool collideX = (GetPosition().x + GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x+GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<=(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>=tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<=tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>=tiles->GetPosition().y-tiles->GetScaledSize().y/2;

            bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
            bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

            bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

            if(collideX && collideY){
                return true;
            }

        }
        return false;
    }
    template<typename T>
    bool IsCollideLeft(std::vector<std::shared_ptr<T>> Object){
        for(int i=0;i<Object.size();i++){
            auto tiles = Object[i];
            bool collideX = (GetPosition().x - GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x - GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<=(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>=tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<=tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>=tiles->GetPosition().y-tiles->GetScaledSize().y/2;

            bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
            bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

            bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

            if(collideX && collideY){
                return true;
            }

        }
        return false;
    }

    template<typename T>
    bool IsCollideRight(std::vector<std::shared_ptr<T>> Object, int index){
        for(int i=0;i<Object.size();i++){
            if(i!=index){
                auto tiles = Object[i];
                bool collideX = (GetPosition().x + GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x+GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
                bool collideY1 = (GetPosition().y + GetScaledSize().y/2<=(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>=tiles->GetPosition().y-tiles->GetScaledSize().y/2);
                bool collideY2 = (GetPosition().y - GetScaledSize().y/2<=tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>=tiles->GetPosition().y-tiles->GetScaledSize().y/2;

                bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
                bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

                bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

                if(collideX && collideY){
                    return true;
                }
            }
        }
        return false;
    }

    template<typename T>
    bool IsCollideLeft(std::vector<std::shared_ptr<T>> Object, int index){
        for(int i=0;i<Object.size();i++){
            if(i!=index){
                auto tiles = Object[i];
                bool collideX = (GetPosition().x - GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x - GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
                bool collideY1 = (GetPosition().y + GetScaledSize().y/2<=(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>=tiles->GetPosition().y-tiles->GetScaledSize().y/2);
                bool collideY2 = (GetPosition().y - GetScaledSize().y/2<=tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>=tiles->GetPosition().y-tiles->GetScaledSize().y/2;

                bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
                bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

                bool collideY = collideY1 || collideY2 || collideY3 || collideY4;



                if(collideX && collideY){
                    return true;
                }
            }
        }
        return false;
    }

    bool IsCollideRightDead(std::vector<std::shared_ptr<Koopa>> Object ,int index){
        for(int i=0;i<Object.size();i++){
            if(i!=index) {
                auto tiles = Object[i];
                bool collideX = (GetPosition().x + GetScaledSize().x / 2 >=
                                 tiles->GetPosition().x - tiles->GetScaledSize().x / 2) &&
                                (GetPosition().x + GetScaledSize().x / 2 <=
                                 tiles->GetPosition().x + tiles->GetScaledSize().x / 2);
                bool collideY1 = (GetPosition().y + GetScaledSize().y / 2 <=
                                  (tiles->GetPosition().y + tiles->GetScaledSize().y / 2) &&
                                  GetPosition().y + GetScaledSize().y / 2 >=
                                  tiles->GetPosition().y - tiles->GetScaledSize().y / 2);
                bool collideY2 = (GetPosition().y - GetScaledSize().y / 2 <=
                                  tiles->GetPosition().y + tiles->GetScaledSize().y / 2) &&
                                 GetPosition().y - GetScaledSize().y / 2 >=
                                 tiles->GetPosition().y - tiles->GetScaledSize().y / 2;

                bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y / 2 <=
                                  GetPosition().y + GetScaledSize().y / 2) &&
                                 (tiles->GetPosition().y + tiles->GetScaledSize().y / 2 >=
                                  GetPosition().y + GetScaledSize().y / 2);
                bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y / 2 >=
                                  GetPosition().y - GetScaledSize().y / 2) &&
                                 (tiles->GetPosition().y - tiles->GetScaledSize().y / 2 <=
                                  GetPosition().y + GetScaledSize().y / 2);

                bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

                if (collideX && collideY && tiles->levelUp ) {
                    return true;
                }
            }

        }
        return false;
    }

    bool IsCollideLeftDead(std::vector<std::shared_ptr<Koopa>> Object, int index){
        for(int i=0;i<Object.size();i++){
            if(i!=index) {
                auto tiles = Object[i];
                bool collideX = (GetPosition().x - GetScaledSize().x / 2 >=
                                 tiles->GetPosition().x - tiles->GetScaledSize().x / 2) &&
                                (GetPosition().x - GetScaledSize().x / 2 <=
                                 tiles->GetPosition().x + tiles->GetScaledSize().x / 2);
                bool collideY1 = (GetPosition().y + GetScaledSize().y / 2 <=
                                  (tiles->GetPosition().y + tiles->GetScaledSize().y / 2) &&
                                  GetPosition().y + GetScaledSize().y / 2 >=
                                  tiles->GetPosition().y - tiles->GetScaledSize().y / 2);
                bool collideY2 = (GetPosition().y - GetScaledSize().y / 2 <=
                                  tiles->GetPosition().y + tiles->GetScaledSize().y / 2) &&
                                 GetPosition().y - GetScaledSize().y / 2 >=
                                 tiles->GetPosition().y - tiles->GetScaledSize().y / 2;

                bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y / 2 <=
                                  GetPosition().y + GetScaledSize().y / 2) &&
                                 (tiles->GetPosition().y + tiles->GetScaledSize().y / 2 >=
                                  GetPosition().y + GetScaledSize().y / 2);
                bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y / 2 >=
                                  GetPosition().y - GetScaledSize().y / 2) &&
                                 (tiles->GetPosition().y - tiles->GetScaledSize().y / 2 <=
                                  GetPosition().y + GetScaledSize().y / 2);

                bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

                if (collideX && collideY && tiles->levelUp ) {
                    return true;
                }
            }
        }
        return false;
    }

    int stepTimes = 0;

    float direction = -1.0f;
    float directionUp = 1.0f;
    float time_koopa =0.0f;
    float Y_start_koopa = 0.0f;


    bool EnemyDie = false;
    bool EnemyDie2 = false;
    bool isActive = false;
    //bool isActive2 = false;
    bool levelUp = false;

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};

#endif //SUPERMARIO1_KOOPA_H
