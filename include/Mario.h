//
// Created by Felicia Rulita on 2024/4/26.
//

#ifndef SUPERMARIO1_MARIO_H
#define SUPERMARIO1_MARIO_H
#include <vector>
#include <string>
#include <__memory/shared_ptr.h>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include "Character.h"
#include "QuestionTiles.h"
#include "AnimatedCharacter.h"
#include "Mushroom.h"
#include "Koopa.h"

class Mario : public AnimatedCharacter{
public:
    explicit Mario(const std::vector<std::string>& AnimationPaths);

    template<typename T>
    std::tuple<bool,int> IsStepOn(std::vector<std::shared_ptr<T>> Objects){
        for(int i=0;i<Objects.size();i++){
            auto tiles = Objects[i];
            bool collideX1 = (GetPosition().x-GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2-2.0f))&&(GetPosition().x-GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2+2.0f);
            bool collideX2 = (GetPosition().x+GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2)-2.0f)&&(GetPosition().x+GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2+2.0f);
            //bool collideY = (Object->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y-(Object->GetScaledSize().y/2 + 3.0f));
            bool collideY = ((GetPosition().y - GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 15.0f) && ((GetPosition().y - GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+5.0f);

            glm::vec2 landPos = {GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+GetScaledSize().y/2};

            bool collideX = collideX1 || collideX2;

            if((collideX) && (collideY)){
                return {true,i};
            }
        }
        return {false, -1};
    }
    template<typename T>
    std::tuple<bool,int> IsHeading(std::vector<std::shared_ptr<T>>Objects){
        for(int i=0;i<Objects.size();i++){
            //debugging
            auto tiles = Objects[i];
            bool collideX1 = (GetPosition().x - GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x - GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2-5.0f);
            bool collideX2 = (GetPosition().x + GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2+5.0f)&&(GetPosition().x + GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);

            bool collideX = collideX1 || collideX2;

            if(collideX && collideY){
                return {true,i};
            }

        }
        return {false,-1};
    }
    template<typename T>
    bool IsCollideRight(std::vector<std::shared_ptr<T>> Object ){
        for(int i=0;i<Object.size();i++){
            auto tiles = Object[i];
            bool collideX = (GetPosition().x + GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x+GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            //musuh jg hrs bisa klo lbh kecil dr mario
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

            bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
            bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

            bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

            if(collideX && collideY && !tiles->EnemyDie){
                return true;
            }

        }
        return false;
    }

    bool IsCollideRight(std::vector<std::shared_ptr<Character>> Object ){
        for(int i=0;i<Object.size();i++){
            auto tiles = Object[i];
            bool collideX = (GetPosition().x + GetScaledSize().x/2>tiles->GetPosition().x-tiles->GetScaledSize().x/2-2.0f)&&(GetPosition().x+GetScaledSize().x/2<tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

            bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
            bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

            bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

            if(collideX && collideY){
                return true;
            }

        }
        return false;
    }
    bool IsCollideRight(std::vector<std::shared_ptr<AnimatedCharacter>> Object ){
        for(int i=0;i<Object.size();i++){
            auto tiles = Object[i];
            bool collideX = (GetPosition().x + GetScaledSize().x/2>tiles->GetPosition().x-tiles->GetScaledSize().x/2-2.0f)&&(GetPosition().x+GetScaledSize().x/2<tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

            bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
            bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

            bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

            if(collideX && collideY){
                return true;
            }

        }
        return false;
    }
    bool IsCollideRight(std::shared_ptr<Character> Object ){
        bool collideX = (GetPosition().x + GetScaledSize().x/2>=Object->GetPosition().x-Object->GetScaledSize().x/2)&&(GetPosition().x+GetScaledSize().x/2<=Object->GetPosition().x+Object->GetScaledSize().x/2);
        bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(Object->GetPosition().y+Object->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>Object->GetPosition().y-Object->GetScaledSize().y/2);
        bool collideY2 = (GetPosition().y - GetScaledSize().y/2<Object->GetPosition().y+Object->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>Object->GetPosition().y-Object->GetScaledSize().y/2;

        bool collideY3 = (Object->GetPosition().y + Object->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(Object->GetPosition().y+Object->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
        bool collideY4 = (Object->GetPosition().y - Object->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (Object->GetPosition().y - Object->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }


        return false;
    }

    template<typename T>
    bool IsCollideLeft(std::vector<std::shared_ptr<T>> Object ){
        for(int i=0;i<Object.size();i++){
            auto tiles = Object[i];
            bool collideX = (GetPosition().x - GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(GetPosition().x-GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
            bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
            bool collideY2 = (GetPosition().y - GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

            bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
            bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

            bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

            if(collideX && collideY && !tiles->EnemyDie){
                return true;
            }

        }
        return false;
    }

    bool IsCollideLeft(std::shared_ptr<Character> Object ){
        bool collideX = (GetPosition().x + GetScaledSize().x/2>=Object->GetPosition().x-Object->GetScaledSize().x/2)&&(GetPosition().x+GetScaledSize().x/2<=Object->GetPosition().x+Object->GetScaledSize().x/2);
        bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(Object->GetPosition().y+Object->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>Object->GetPosition().y-Object->GetScaledSize().y/2);
        bool collideY2 = (GetPosition().y - GetScaledSize().y/2<Object->GetPosition().y+Object->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>Object->GetPosition().y-Object->GetScaledSize().y/2;

        bool collideY3 = (Object->GetPosition().y + Object->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(Object->GetPosition().y+Object->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
        bool collideY4 = (Object->GetPosition().y - Object->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (Object->GetPosition().y - Object->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }


        return false;
    }
    bool IsCollideLeft(std::shared_ptr<AnimatedCharacter> Object ){
        bool collideX = (GetPosition().x + GetScaledSize().x/2>=Object->GetPosition().x-Object->GetScaledSize().x/2)&&(GetPosition().x+GetScaledSize().x/2<=Object->GetPosition().x+Object->GetScaledSize().x/2);
        bool collideY1 = (GetPosition().y + GetScaledSize().y/2<(Object->GetPosition().y+Object->GetScaledSize().y/2) && GetPosition().y+GetScaledSize().y/2>Object->GetPosition().y-Object->GetScaledSize().y/2);
        bool collideY2 = (GetPosition().y - GetScaledSize().y/2<Object->GetPosition().y+Object->GetScaledSize().y/2) && GetPosition().y-GetScaledSize().y/2>Object->GetPosition().y-Object->GetScaledSize().y/2;

        bool collideY3 = (Object->GetPosition().y + Object->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2)&&(Object->GetPosition().y+Object->GetScaledSize().y/2>=GetPosition().y+GetScaledSize().y/2);
        bool collideY4 = (Object->GetPosition().y - Object->GetScaledSize().y/2 >= GetPosition().y - GetScaledSize().y/2)&& (Object->GetPosition().y - Object->GetScaledSize().y/2 <= GetPosition().y+GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }


        return false;
    }

    void MarioShrink(std::vector<std::string>);

    int MarioBlinking(int time);

    bool MarioDie = false;
    bool MarioStep = false;
    bool MarioHeadBrick = false;
    bool MarioHeadQues = false;
    bool MarioFinish = false;
    bool MarioEnd = false;
    bool MarioStepKoopa = false;
    bool MarioLevelingUp = false;
    bool MarioLevelingDown = false;
    bool MarioGoUp = false;


    void Update(unsigned long BaseTime);

    void Jump(unsigned long BaseTime){
        m_Jump=true;
        Update(BaseTime);
    }

    bool m_Jump=false;
    bool m_HasEnded=true;

    float speed = 0.0f;
    float time_mario ;
    float y_start_mario =0.0f;
    float PowerJump = 0.0f;

    int level = 0;

    //mushroom, coins
    bool isActive = false;



private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};
#endif //SUPERMARIO1_MARIO_H
