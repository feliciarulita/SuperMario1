//
// Created by Felicia Rulita on 2024/3/12.

#include "FirstWorldOne.h"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"
#include <cmath>
#include <algorithm>

void Phase::Rendering(){
    for(const auto & i:m_MushVector){
        if(i->GetPosition().x<400.0f && !i->EnemyDie){
            i->SetVisible(true);
        }
    }
    for(const auto & i:m_KoopaVec){
        if(i->GetPosition().x<400.0f){
            i->SetVisible(true);
        }
    }
    for(int i=0;i<m_QuesVector.size();i++){
        if(m_QuesVector[i]->GetPosition().x<400.0f && !m_DeadQues[i]->GetVisibility()){
            m_QuesVector[i]->SetVisible(true);
        }
    }
    for(const auto & i:m_Brick){
        if(i->GetPosition().x<700.0f){
            i->SetVisible(true);
        }
    }
    for(const auto & i:m_YellowMushVec){
        if(i->GetPosition().x<400.0f){
            i->SetVisible(true);
        }
    }
    for(const auto & i : m_MovingPlatform){
        if(i->GetPosition().x<400.0f){
            i->SetVisible(true);
        }
    }
    for(const auto & i : m_MovingPlatform2){
        if(i->GetPosition().x<400.0f){
            i->SetVisible(true);
        }
    }
    if(m_Pillar!= nullptr){
        if(m_Pillar->GetPosition().x<400.0f)m_Pillar->SetVisible(true);
        if(m_Flag->GetPosition().x<400.0f)m_Flag->SetVisible(true);
    }
    for(const auto & i: m_Coins){
        if(i->GetPosition().x<400.0f){
            i->SetVisible(true);
        }
    }
    if(m_Piranhas.size()!=0){
        for(const auto & i : m_Piranhas){
            if(i->GetPosition().x<400.0f){
                i->SetVisible(true);
            }
        }
    }
    if(m_KoopaRed!=nullptr){
        if(m_KoopaRed->GetPosition().x<400.0f){
            LOG_DEBUG("koopa red");
            LOG_DEBUG(m_KoopaRed->GetPosition().x);
            LOG_DEBUG(m_KoopaRed->GetPosition().y);
            LOG_DEBUG(m_KoopaRed->GetVisibility());
            m_KoopaRed->SetVisible(true);
        }
    }

}

float Phase::gravity(float y_start, float time_gravity, const std::shared_ptr<AnimatedCharacter> Object){
    float height = y_start - searchLand(Object);
    float y_exact =y_start-((10.0f/2)*((sqrt((2*height)/10.0))*(sqrt((2*height)/10.0))));

    if (Object->GetPosition().y<y_exact+25.0f){
        return y_exact;
    }

    else {
        return y_start - ((10.0f / 2) * (time_gravity * time_gravity));
    }

}

glm::vec2 Phase::ParabolicMovement (int v0, float angel_cos, float angel_sin,float time,std::shared_ptr<Character> Object){
    // gravity =10
    float x ,y, X_Point_start, Y_Point_start;
    Y_Point_start = Object->GetPosition().y;
    X_Point_start = Object ->GetPosition().x;

    //Horizontal Distance =>x(t)=v0 * cos(angle)*t
    x= X_Point_start + (v0* angel_cos*time);


    //Vertical Distance => y(t)=(v0 *sin(angel)*time)−(0.5 * Gravity * time^2)
    y= Y_Point_start + ((v0 * angel_sin*time)-(0.5 * 10 * (time*time)));

    LOG_INFO("SIN COS");


    glm::vec2 Position= {x,y};
    return Position;

}

void Phase::moveBackground(float position,App *app) {
    m_Bg2->SetPosition({m_Bg2->GetPosition().x-position,m_Bg2->GetPosition().y});

    for(const auto & i: m_BrickMove){
        i->SetPosition({i->GetPosition().x-position,i->GetPosition().y});
    }

    for(const auto & i : m_Land){
        i->SetPosition({i->GetPosition().x-position,i->GetPosition().y});
    }
    for(const auto & j : m_Tube){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});

        if(j->GetPosition().x<-400.0f){
            app->m_Root.RemoveChild(j);
        }

    }
    for(const auto & j : m_Wood){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});

        if(j->GetPosition().x<-400.0f){
            app->m_Root.RemoveChild(j);
        }

    }
    for(const auto & j : m_MushVector){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    for(const auto & j : m_KoopaVec){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    for(const auto & j : m_QuesVector){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});

        if(j->GetPosition().x<-400.0f){
            app->m_Root.RemoveChild(j);
        }

    }
    for(const auto & j : m_Brick){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});

        if(j->GetPosition().x<-400.0f){
            app->m_Root.RemoveChild(j);
        }

    }
    for(const auto & j: m_Brick_break){
        for(const auto & k : j){
            k->SetPosition({k->GetPosition().x-position,k->GetPosition().y});

            if(k->GetPosition().x<-400.0f){
                app->m_Root.RemoveChild(k);
            }
        }
    }
    if(!m_Castle.empty()){
        for(const auto & j : m_Castle){
            j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
        }
    }

    for(const auto & j : m_DeadQues){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    for(const auto & j : m_YellowMushVec){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    if(app->m_Phase==App::Phases::FIRST_WORLD_TWO){
        for(const auto &j : m_MovingPlatform){
            j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
        }
        for(const auto &j : m_MovingPlatform2){
            j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
        }
        m_TubeBig->SetPosition({m_TubeBig->GetPosition().x-position,m_TubeBig->GetPosition().y});
        for(const auto &j : m_Coins2Vec){
            j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
        }
        for(const auto &j : m_TubeBig2Vec){
            j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
        }

    }
    if(m_Pillar!= nullptr){
        m_Pillar->SetPosition({m_Pillar->GetPosition().x-position,m_Pillar->GetPosition().y});
        m_Flag->SetPosition({m_Flag->GetPosition().x-position,m_Flag->GetPosition().y});
    }
    for(const auto &j: m_Coins){
        j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
    }
    if(m_Land2!=nullptr) {
        m_Land2->SetPosition({m_Land2->GetPosition().x-position,m_Land2->GetPosition().y});
    }
    if(m_Piranhas.size()!=0){
        for(const auto & j : m_Piranhas){
            j->SetPosition({j->GetPosition().x-position,j->GetPosition().y});
        }
    }
    if(m_KoopaRed!= nullptr){
        m_KoopaRed->SetPosition({m_KoopaRed->GetPosition().x-position,m_KoopaRed->GetPosition().y});
    }

}

void Phase::callMario(){
    m_Mario->SetVisible(true);
    m_Mario->SetLooping(false);
    m_Mario->SetInterval(100);
    m_Mario->SetPlaying();
}

void Phase::callMarioJump() {
    if(m_EnterRight){
        if(m_Mario->level==0){
            m_Mario->SetImage(MarioJump);
            LOG_DEBUG(m_Mario->GetAnimationPath()[0]);
        }
        else if(m_Mario->level==1){
            m_Mario->SetImage(MarioJumpLvl2);
        }

    }
    else if(m_EnterLeft){
        if(m_Mario->level==0){
            m_Mario->SetImage(MarioJumpBack);
        }
        else if(m_Mario->level==1){
            m_Mario->SetImage(MarioJumpBackLvl2);
        }
    }

}

//make function for searching is on land from mario's x
float Phase::searchLand(const std::shared_ptr<AnimatedCharacter> Object){
    float x = Object->GetPosition().x;
    float y = -1000.0f;

    for(int i=0;i<m_KoopaVec.size();i++){
        auto tiles = m_KoopaVec[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y ));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }

    for(int i=0;i<m_MushVector.size();i++){
        auto tiles = m_MushVector[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y ));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }

    for(int i=0;i<m_Land.size();i++){
        auto tiles = m_Land[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2+5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2+5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2-5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2-5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y ));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }

    for(int i=0;i<m_Tube.size();i++){
        auto tiles = m_Tube[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2+5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2+5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2-5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2-5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y ));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }

    for(int i=0;i<m_QuesVector.size();i++){
        auto tiles = m_QuesVector[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2+5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2+5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2-5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2-5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y ));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }

    for(int i=0;i<m_Brick.size();i++){
        auto tiles = m_Brick[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2+5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2+5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2-5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2-5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y ));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }

    for(int i=0;i<m_Wood.size();i++){
        auto tiles = m_Wood[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2+5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2+5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2-5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2-5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y ));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }
    for(int i=0;i<m_MovingPlatform.size();i++){
        auto tiles = m_MovingPlatform[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2+5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2+5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2-5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2-5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2)));
        }
    }
    for(int i=0;i<m_MovingPlatform2.size();i++){
        auto tiles = m_MovingPlatform2[i];
        bool collideX1 = (x-Object->GetScaledSize().x/2+5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2+5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2-5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2-5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (tiles->GetPosition().y));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(tiles->GetPosition().y + (tiles->GetScaledSize().y/2) + 3.0f));
        }
    }
    if(m_TubeBig!=nullptr){
        bool collideX1 = (x-Object->GetScaledSize().x/2+5.0f>=m_TubeBig->GetPosition().x-((m_TubeBig->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2+5.0f<=m_TubeBig->GetPosition().x+m_TubeBig->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2-5.0f>=m_TubeBig->GetPosition().x-((m_TubeBig->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2-5.0f<=m_TubeBig->GetPosition().x+m_TubeBig->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (m_TubeBig->GetPosition().y));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(m_TubeBig->GetPosition().y + (m_TubeBig->GetScaledSize().y/2) + 3.0f));
        }
    }
    if(m_TubeBig!= nullptr){
        bool collideX1 = (x-Object->GetScaledSize().x/2+5.0f>=m_TubeBig2Vec[1]->GetPosition().x-((m_TubeBig2Vec[1]->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2+5.0f<=m_TubeBig2Vec[1]->GetPosition().x+m_TubeBig2Vec[1]->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2-5.0f>=m_TubeBig2Vec[1]->GetPosition().x-((m_TubeBig2Vec[1]->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2-5.0f<=m_TubeBig2Vec[1]->GetPosition().x+m_TubeBig2Vec[1]->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (m_TubeBig2Vec[1]->GetPosition().y));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(m_TubeBig2Vec[1]->GetPosition().y + (m_TubeBig2Vec[1]->GetScaledSize().y/2) + 3.0f));
        }
    }
    if(m_Land2!=nullptr){
        bool collideX1 = (x-Object->GetScaledSize().x/2+5.0f>=m_Land2->GetPosition().x-((m_Land2->GetScaledSize().x)/2))&&(x-Object->GetScaledSize().x/2+5.0f<=m_Land2->GetPosition().x+m_Land2->GetScaledSize().x/2);
        bool collideX2 = (x+Object->GetScaledSize().x/2-5.0f>=m_Land2->GetPosition().x-((m_Land2->GetScaledSize().x)/2))&&(x+Object->GetScaledSize().x/2-5.0f<=m_Land2->GetPosition().x+m_Land2->GetScaledSize().x/2);
        bool yPos = (Object->GetPosition().y > (m_Land2->GetPosition().y));

        if((collideX1 || collideX2) && yPos){
            y = std::max(y,(m_Land2->GetPosition().y + (m_Land2->GetScaledSize().y/2)));
        }
    }



    y = y + Object->GetScaledSize().y/2;

    return y;
}

std::tuple<bool,glm::vec2 > Phase::IsOnLand(const std::shared_ptr<AnimatedCharacter>& Object){
    for(const auto& tiles : m_Land){
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        //bool collideY = (Object->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y-(Object->GetScaledSize().y/2 + 3.0f));
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 100.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+Object->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    for(const auto& tiles : m_QuesVector){
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        //bool collideY = (m_Mario->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y-(m_Mario->GetScaledSize().y/2 + 3.0f));
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 10.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+Object->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    for(const auto& tiles : m_Brick){
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 10.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+Object->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    for(const auto& tiles : m_Tube){
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        //l collideY = (m_Mario->GetPosition().y==tiles->GetPosition().y+tiles->GetScaledSize().y-(m_Mario->GetScaledSize().y/2 + 3.0f));
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 20.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {m_Mario->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+m_Mario->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    for(const auto& tiles : m_Wood){
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 20.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+Object->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    for(const auto& tiles : m_MovingPlatform){
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 20.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+Object->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    for(const auto& tiles : m_MovingPlatform2){
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f>=tiles->GetPosition().x-((tiles->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=tiles->GetPosition().y+tiles->GetScaledSize().y/2 - 20.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=tiles->GetPosition().y+tiles->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,tiles->GetPosition().y+tiles->GetScaledSize().y/2+Object->GetScaledSize().y/2+3.0f};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    if(m_TubeBig!=nullptr){
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f>=m_TubeBig->GetPosition().x-((m_TubeBig->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f<=m_TubeBig->GetPosition().x+m_TubeBig->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f>=m_TubeBig->GetPosition().x-((m_TubeBig->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f<=m_TubeBig->GetPosition().x+m_TubeBig->GetScaledSize().x/2);
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=m_TubeBig->GetPosition().y+m_TubeBig->GetScaledSize().y/2 - 20.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=m_TubeBig->GetPosition().y+m_TubeBig->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,m_TubeBig->GetPosition().y+m_TubeBig->GetScaledSize().y/2+Object->GetScaledSize().y/2+3.0f};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    if(m_TubeBig!= nullptr){
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f>=m_TubeBig2Vec[1]->GetPosition().x-((m_TubeBig2Vec[1]->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f<=m_TubeBig2Vec[1]->GetPosition().x+m_TubeBig2Vec[1]->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f>=m_TubeBig2Vec[1]->GetPosition().x-((m_TubeBig2Vec[1]->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f<=m_TubeBig2Vec[1]->GetPosition().x+m_TubeBig2Vec[1]->GetScaledSize().x/2);
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=m_TubeBig2Vec[1]->GetPosition().y+m_TubeBig2Vec[1]->GetScaledSize().y/2 - 20.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=m_TubeBig2Vec[1]->GetPosition().y+m_TubeBig2Vec[1]->GetScaledSize().y/2+3.0f);

        glm::vec2 landPos = {Object->GetPosition().x,m_TubeBig2Vec[1]->GetPosition().y+m_TubeBig2Vec[1]->GetScaledSize().y/2+Object->GetScaledSize().y/2+3.0f};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }
    if(m_Land2!= nullptr){
        bool collideX1 = (Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f>=m_Land2->GetPosition().x-((m_Land2->GetScaledSize().x)/2))&&(Object->GetPosition().x-Object->GetScaledSize().x/2+5.0f<=m_Land2->GetPosition().x+m_Land2->GetScaledSize().x/2);
        bool collideX2 = (Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f>=m_Land2->GetPosition().x-((m_Land2->GetScaledSize().x)/2))&&(Object->GetPosition().x+Object->GetScaledSize().x/2-5.0f<=m_Land2->GetPosition().x+m_Land2->GetScaledSize().x/2);
        bool collideY = ((Object->GetPosition().y - Object->GetScaledSize().y/2)>=m_Land2->GetPosition().y+m_Land2->GetScaledSize().y/2 - 20.0f) && ((Object->GetPosition().y - Object->GetScaledSize().y/2)<=m_Land2->GetPosition().y+m_Land2->GetScaledSize().y/2);

        glm::vec2 landPos = {Object->GetPosition().x,m_Land2->GetPosition().y+m_Land2->GetScaledSize().y/2+Object->GetScaledSize().y/2};

        bool collideX = collideX1 || collideX2;

        if((collideX) && (collideY)){
            return {true,landPos};
        }
    }


    return {false,Object->GetPosition()};
}

bool Phase::IsCollideRight(const std::shared_ptr<AnimatedCharacter>& Object){
    for(const auto& tiles : m_Brick){
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2-3.0f)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2+3.0f);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_QuesVector){
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2-3.0f)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2+3.0f);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Land){
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2-3.0f)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2+3.0f);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Tube){
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2-3.0f)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2+3.0f);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Wood){
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2-3.0f)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2+3.0f);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    if(m_TubeBig2!= nullptr){
        bool collideX = (Object->GetPosition().x + Object->GetScaledSize().x/2>=m_TubeBig2Vec[0]->GetPosition().x-m_TubeBig2Vec[0]->GetScaledSize().x/2-3.0f)&&(Object->GetPosition().x+Object->GetScaledSize().x/2<=m_TubeBig2Vec[0]->GetPosition().x+m_TubeBig2Vec[0]->GetScaledSize().x/2+3.0f);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(m_TubeBig2Vec[0]->GetPosition().y+m_TubeBig2Vec[0]->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>m_TubeBig2Vec[0]->GetPosition().y-m_TubeBig2Vec[0]->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<m_TubeBig2Vec[0]->GetPosition().y+m_TubeBig2Vec[0]->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>m_TubeBig2Vec[0]->GetPosition().y-m_TubeBig2Vec[0]->GetScaledSize().y/2;

        bool collideY3 = (m_TubeBig2Vec[0]->GetPosition().y + m_TubeBig2Vec[0]->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(m_TubeBig2Vec[0]->GetPosition().y+m_TubeBig2Vec[0]->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (m_TubeBig2Vec[0]->GetPosition().y - m_TubeBig2Vec[0]->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (m_TubeBig2Vec[0]->GetPosition().y - m_TubeBig2Vec[0]->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }
    }
    return false;
};

bool Phase::IsCollideLeft(const std::shared_ptr<AnimatedCharacter>& Object){
    for(const auto& tiles : m_Brick){
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2-3.0f)&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2+3.0f);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_QuesVector){
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2-3.0f)&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2+3.0f);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Land){
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2-3.0f)&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2+3.0f);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Tube){
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2-3.0f)&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2+3.0f);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Wood){
        bool collideX = (Object->GetPosition().x - Object->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2-3.0f)&&(Object->GetPosition().x-Object->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2+3.0f);
        bool collideY1 = (Object->GetPosition().y + Object->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y+Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);
        bool collideY2 = (Object->GetPosition().y - Object->GetScaledSize().y/2<tiles->GetPosition().y+tiles->GetScaledSize().y/2) && Object->GetPosition().y-Object->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2;

        bool collideY3 = (tiles->GetPosition().y + tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2)&&(tiles->GetPosition().y+tiles->GetScaledSize().y/2>=Object->GetPosition().y+Object->GetScaledSize().y/2);
        bool collideY4 = (tiles->GetPosition().y - tiles->GetScaledSize().y/2 >= Object->GetPosition().y - Object->GetScaledSize().y/2)&& (tiles->GetPosition().y - tiles->GetScaledSize().y/2 <= Object->GetPosition().y+Object->GetScaledSize().y/2);

        bool collideY = collideY1 || collideY2 || collideY3 || collideY4;

        if(collideX && collideY){
            return true;
        }
    }
    return false;
};

bool Phase::IsCollideUp(){
    for(const auto& tiles : m_Brick){
        //debugging
        bool collideX1 = (m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2-5.0f);
        bool collideX2 = (m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2+5.0f)&&(m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);

        bool collideX = collideX1 || collideX2;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_QuesVector){
        //debugging
        bool collideX1 = (m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2-5.0f);
        bool collideX2 = (m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2+5.0f)&&(m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);

        bool collideX = collideX1 || collideX2;

        if(collideX && collideY){
            return true;
        }

    }
    for(const auto& tiles : m_Tube){
        //debugging
        bool collideX1 = (m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2)&&(m_Mario->GetPosition().x - m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2-5.0f);
        bool collideX2 = (m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2>=tiles->GetPosition().x-tiles->GetScaledSize().x/2+5.0f)&&(m_Mario->GetPosition().x + m_Mario->GetScaledSize().x/2<=tiles->GetPosition().x+tiles->GetScaledSize().x/2);
        bool collideY = (m_Mario->GetPosition().y + m_Mario->GetScaledSize().y/2<(tiles->GetPosition().y+tiles->GetScaledSize().y/2) && m_Mario->GetPosition().y+m_Mario->GetScaledSize().y/2>tiles->GetPosition().y-tiles->GetScaledSize().y/2);

        bool collideX = collideX1 || collideX2;

        if(collideX && collideY){
            return true;
        }

    }
    return false;
}
// control Mario death
void Phase::MarioDeath(){
    m_MarioDiesTime = Util::Time::GetElapsedTimeMs();
    m_Mario->MarioDie = true;
    m_BGMusic->Pause();
    m_Mario_dead_audio->SetVolume(75);
    m_Mario_dead_audio->Play();
};

void Phase::Update(App *app){
    Rendering();

    timenow +=1;

    if(!marioStart){
        if(m_Mario->level==0){
            m_Mario->SetImage(MarioJump);
        }
        else if(m_Mario->level==1){
            m_Mario->SetImage(MarioJumpLvl2);
        }
        m_Mario->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y-15.0f});
    }

    if(m_Mario->GetPosition().y<-200.0f){
        if(!std::get<0>(IsOnLand(m_Mario))){
            m_Mario->MarioDie = true;
        }
        else if(m_Mario->GetPosition().y<-300.0f){
            m_Mario->MarioDie = true;
        }


    }
    // Mario fall die
    if (m_Mario->GetPosition().y < -200.0f && !m_Mario->MarioDie) {MarioDeath();}
    // Control the time Management
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    if (time >0) {
        time = 400 - (static_cast<int>(timenow) / static_cast<int>(10));
    }
    else {
        time =0;
    }
    // SET TITLE TEXT
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    m_time->SetText(std::to_string(time));
    m_score->SetText(std::to_string(score));
    m_coin->SetText(std::to_string(coin));

    auto result = IsOnLand(m_Mario);

    if( std::get<0>(result) && !m_Mario->m_Jump && !m_Mario->MarioDie){
        //if on land then run
        LOG_DEBUG("mario on land");
        position = std::get<1>(result);
        m_Mario->KillEnemy_in_a_row=0;

        marioStart = true;

        pressed1 = false;

        m_Mario->y_start_mario = m_Mario->GetPosition().y;
        t = 0;
        cnt = 0;

        m_Mario->SetPosition(position);

    }
    else if(std::get<0>(result) && m_Mario->m_Jump && m_Mario->m_HasEnded && !m_Mario->MarioDie){
        //when after jump then stepping land
        LOG_DEBUG("mario on land 2");
        marioStart = true;
        position = std::get<1>(result);

        m_Mario->SetPosition(position);
        m_Mario->m_Jump=false;

    }

        // GRAVITY control;
        //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    else if(!m_Mario->MarioDie && !m_Mario->MarioStep && !m_Mario->MarioFinish && marioStart && !marioFromTube){
        callMarioJump();
        //make mario always fall is not on land
        ///*

        float y_under= searchLand(m_Mario);
        //float y_under= -172;

        h=m_Mario->y_start_mario - ( y_under);
        if(!m_Mario->m_Jump && !std::get<0>(result) ){

            t += 0.4;
            //jatuh tinggi
            if (m_Mario->GetPosition().y<m_Mario->y_start_mario-((10.0f/2)*((sqrt((2*h)/10.0))*(sqrt((2*h)/10.0))))+15.0f){
                m_Mario->SetPosition({m_Mario->GetPosition().x, m_Mario->y_start_mario-((10.0f/2)*((sqrt((2*h)/10.0))*(sqrt((2*h)/10.0))))});
            }

            else {

                m_Mario->SetPosition({m_Mario->GetPosition().x, m_Mario->y_start_mario - ((10.0f / 2) * (t * t))});
            }
        }

    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




    //press F to go to next 部分 of map
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if(Util::Input::IsKeyDown(Util::Keycode::F)){
        moveBackground(2400.0f,app);

        m_Mario->SetPosition({m_Mario->GetPosition().x,100.0f});
    }
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    // Control Mario Movement X-axis; ->(when m_Mario->speed != 0), then mario will always move;
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //m_Mario->SetPosition({m_Mario->GetPosition().x + m_Mario->speed , m_Mario->GetPosition().y});
    if (m_Mario->speed != 0) {
        if (!m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd && !m_Mario->MarioLevelingUp) {
            LOG_INFO("Mario Moving ON X-axis");
            LOG_DEBUG(m_Mario->speed);
            // make the speed back always back to 0;
            if ((!Util::Input::IsKeyPressed(Util::Keycode::RIGHT) && !Util::Input::IsKeyPressed(Util::Keycode::LEFT))  || (Util::Input::IsKeyPressed(Util::Keycode::LEFT) && m_EnterRight)  || (Util::Input::IsKeyPressed(Util::Keycode::RIGHT) && m_EnterLeft)    ){

                if (m_Mario->speed > 0) { m_Mario->speed -= 0.25; }
                else if (m_Mario->speed < 0) { m_Mario->speed += 0.25; }

            }
            if (((IsCollideRight(m_Mario) || IsCollideLeft(m_Mario))) && std::get<0>(result)){
                if (m_Mario -> speed >=1.0){m_Mario -> speed = 1.0;}
                else if (m_Mario -> speed <=-1.0){m_Mario -> speed = -1.0;}
            }
            // control mario go to right and left
            //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



            // Control movement to right
            //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            if (m_Mario->speed > 0) {

                if (!IsCollideRight(m_Mario)) {
                    if (m_Mario->GetPosition().x < 13.0f) {
                        m_Mario->SetPosition({m_Mario->GetPosition().x + m_Mario->speed, m_Mario->GetPosition().y});
                    } else if (m_Mario->GetPosition().x >= 13.0f ) {
                        moveBackground(m_Mario->speed, app);
                    }
                }
            }
            //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            //Control Movement to left
            //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            else if (m_Mario->speed < 0) {
                if (m_Mario->GetPosition().x > -340.0f and !IsCollideLeft(m_Mario)) {
                    m_Mario->SetPosition({m_Mario->GetPosition().x + m_Mario->speed, m_Mario->GetPosition().y});
                } else {
                    m_Mario->SetPosition(m_Mario->GetPosition());
                }
            }
            //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        }
    }

    else if (m_Mario->speed ==0 && std::get<0>(result) ){
        if (m_EnterRight){

            if (m_Mario->level==0) { m_Mario->SetImage(MarioRun); }
            else if (m_Mario->level==1) { m_Mario->SetImage(MarioRunLvl2); }
        }
        else if (m_EnterLeft){
            if (m_Mario->level==0) { m_Mario->SetImage(MarioRunBack); }
            else if (m_Mario->level==1) { m_Mario->SetImage(MarioRunBackLvl2); }
        }
    }


    // control when pressed RIGHT key;
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (Util::Input::IsKeyDown(Util::Keycode::RIGHT) && !m_Mario->MarioDie && !m_Mario->MarioFinish &&
        !m_Mario->MarioEnd && !m_Mario->MarioLevelingUp) {
        m_EnterRight = true;
        m_EnterLeft = false;


    }
    if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT) && !m_Mario->MarioDie && !m_Mario->MarioFinish &&
        !m_Mario->MarioEnd && !m_Mario->MarioLevelingUp && marioStart) {

        //when mario jump he can also go to the right
        m_Mario->SetPlaying();
        callMario();

        if (m_EnterRight) {
            if (m_Mario->speed < -0.5 && std::get<0>(result)) {
                m_Mario->speed+=0.25;
                if (m_Mario->level==0){m_Mario->SetImage(MarioSlidesRight);}
                else if (m_Mario->level==1) {m_Mario->SetImage(MarioSlidesRightLvl2);}
            }
            else if (m_Mario->speed > 0 && m_Mario->speed <1){
                if (m_Mario->level == 0) {
                    m_Mario->SetImage(MarioRun);

                } else if (m_Mario->level == 1) {
                    m_Mario->SetImage(MarioRunLvl2);

                }
            }
            if (m_Mario->speed <= 6 && !IsCollideRight(m_Mario)) { m_Mario->speed += 1.0; }
        }

    }

    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Control when pressed left key
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    if(Util::Input::IsKeyPressed(Util::Keycode::LEFT) && !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd && !m_Mario->MarioLevelingUp && marioStart){

        callMario();
        m_Mario->SetPlaying();
        m_Mario->SetVisible(true);

        if (m_EnterLeft) {
            if (m_Mario->speed > 0.5 && std::get<0>(result)) {
                m_Mario->speed-=0.25;
                if (m_Mario->level==0){m_Mario->SetImage(MarioSlidesLeft);}
                else if (m_Mario->level==1) {m_Mario->SetImage(MarioSlidesLeftLvl2);}
            }
            else if (m_Mario->speed < 0&& m_Mario->speed >-1) {
                if (m_Mario->level == 0) {
                    m_Mario->SetImage(MarioRunBack);

                } else if (m_Mario->level == 1) {
                    m_Mario->SetImage(MarioRunBackLvl2);

                }
            }

            if (m_Mario->speed >= -6 && !IsCollideLeft(m_Mario)) { m_Mario->speed -= 1.0; }
        }
    }

    if (Util::Input::IsKeyDown(Util::Keycode::LEFT) && !m_Mario->MarioDie && !m_Mario->MarioFinish &&
        !m_Mario->MarioEnd && !m_Mario->MarioLevelingUp) {
        m_EnterRight = false;
        m_EnterLeft = true;

    }



    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // end of control mario movement X-axis;
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------





    //set image jump
    if(Util::Input::IsKeyDown(Util::Keycode::UP) && marioStart){
        if(m_EnterRight){
            LOG_DEBUG("msk up");
            if(m_Mario->level == 0){
                LOG_DEBUG("msk level");
                m_Mario->SetImage(MarioJump);
            }
            else if (m_Mario->level == 1){
                m_Mario->SetImage(MarioJumpLvl2);
            }

        }
        else if(m_EnterLeft){
            if(m_Mario->level == 0){
                m_Mario->SetImage(MarioJumpBack);
            }
            else if (m_Mario->level == 1){
                m_Mario->SetImage(MarioJumpBackLvl2);
            }
        }
    }

    if(Util::Input::IsKeyUp(Util::Keycode::UP) && marioStart){
        pressed2 = false;

    }
    if(Util::Input::IsKeyPressed(Util::Keycode::UP) && marioStart){
        if (m_Mario->m_Jump && pressed2 && pressed1) {
            cnt++;

        }
        else {
            cnt =0;
        }
    }

    cnts= cnt/2.0;
    if(Util::Input::IsKeyPressed(Util::Keycode::UP) && !m_Mario->m_Jump && !m_Mario->MarioDie && !m_Mario->MarioFinish && !m_Mario->MarioEnd&& !pressed1 && !pressed2 && std::get<0>(result) && !m_Mario->MarioStep && cnt==0 && !m_Mario->MarioGoUp && marioStart){
        LOG_DEBUG("msk pressed up");
        glm::vec2 newPos = m_Mario->GetPosition();
        pressed1 = true;
        pressed2= true ;
        m_Mario_jump_audio->SetVolume(75);
        m_Mario_jump_audio->Play();
        cnt =0;
        t=0;
        //m_Mario->SetVisible(false);
        m_Mario->m_Jump= true;


    }


    if( m_Mario->m_Jump ){
        if (cnts>2) cnts=2;
        if (pressed2 && pressed1 && !m_Mario->MarioStep) m_Mario->PowerJump = 45.0f+(5.0f*cnts);

        t+=0.4f;

        if(!IsCollideUp()){
            max_jump= fmaxf(m_Mario->y_start_mario,m_Mario->GetPosition().y);


            LOG_INFO("t VALUE");
            LOG_INFO(t);
            if (t< (m_Mario->PowerJump/10.0)  ){
                m_Mario->SetPosition({m_Mario->GetPosition().x, m_Mario->y_start_mario+(m_Mario->PowerJump*t) -((10.0/2)*(t*t))});

            }
            else if (t> (m_Mario->PowerJump/10.0) ) {
                m_Mario->y_start_mario = max_jump;
                t = 0;
                m_Mario->m_Jump = false;
            }

        }

            //Mario collide with above brick
        else{
            m_Mario->m_Jump = false;
            t=1;
            m_Mario->y_start_mario = m_Mario->GetPosition().y-5.0f;
        }

    }
    //enemy moving
    for(int i=0; i<m_MushVector.size();i++){
        //gravity if fall
        if(m_MushVector[i]->GetPosition().x<=430.0f){
            m_MushVector[i]->isActive = true;
        }

        if(!std::get<0> (IsOnLand(m_MushVector[i])) && m_MushVector[i]->isActive && !m_MushVector[i]->EnemyDie){
            m_MushVector[i]->SetPosition({m_MushVector[i]->GetPosition().x, gravity(m_MushVector[i]->y_start_goombas, m_MushVector[i]->time_goombas, m_MushVector[i])});
            m_MushVector[i]->time_goombas+=0.3;

        }
        else if(m_MushVector[i]->isActive && !m_MushVector[i]->EnemyDie){
            //reset time goombas to 0
            m_MushVector[i]->time_goombas=0.0f;
            //reset the y start of the goombas to the y now on land
            m_MushVector[i]->y_start_goombas = m_MushVector[i]->GetPosition().y;
            //need to adjust with another things
            //t_goombas=0.0f;

            //need to adjust with another things
            if  (!std::get<0> (IsOnLand(m_MushVector[i]))){m_MushVector[i]->direction *= 0.25f;}

            bool collides = false;
            if(m_MushVector[i]->IsCollideLeft(m_Tube)  || m_MushVector[i]->IsCollideLeft(m_Wood)||m_MushVector[i]->IsCollideLeft(m_MushVector, i) || m_MushVector[i]->IsCollideLeft(m_KoopaVec) ||m_MushVector[i]->IsCollideLeft(m_Brick) ){
                m_MushVector[i]->direction = 1.0f;
                collides = true;
            }
            else if(m_MushVector[i]->IsCollideRight(m_Tube)  || m_MushVector[i]->IsCollideRight(m_Wood) || m_MushVector[i]->IsCollideRight(m_MushVector,i)||m_MushVector[i]->IsCollideRight(m_KoopaVec) || m_MushVector[i]->IsCollideRight(m_Brick)  ){
                m_MushVector[i]->direction = -1.0f;
                collides = true;
            }

            if (!collides && (m_MushVector[i]->direction==1 || m_MushVector[i]->direction==-1) ){m_MushVector[i]->direction *= 2.0f;}
            m_MushVector[i]->SetPosition({m_MushVector[i]->GetPosition().x+( m_MushVector[i]->direction ),m_MushVector[i]->GetPosition().y});
        }
    }
    for(int i=0;i<m_KoopaVec.size();i++){
        //gravity if fall
        if(m_KoopaVec[i]->GetPosition().x<=430.0f){
            m_KoopaVec[i]->isActive = true;
        }

        if(!std::get<0> (IsOnLand(m_KoopaVec[i])) && m_KoopaVec[i]->isActive ){
            m_KoopaVec[i]->SetPosition({m_KoopaVec[i]->GetPosition().x-1.0f,m_KoopaVec[i]->GetPosition().y- 5.0f});
        }

        // koopa moving x-axis
        else if(m_KoopaVec[i]->isActive && !m_KoopaVec[i]->EnemyDie){
            bool collides = false;

            if(m_KoopaVec[i]->IsCollideLeft(m_Tube) || m_KoopaVec[i]->IsCollideLeft(m_Brick) || m_KoopaVec[i]->IsCollideLeft(m_Wood) || m_KoopaVec[i]->IsCollideLeft(m_KoopaVec,i)|| m_KoopaVec[i]->IsCollideLeft(m_MushVector)||m_KoopaVec[i]->IsCollideLeft(m_Brick)|| m_KoopaVec[i]->IsCollideLeft(m_Tube)){ // add if collide with koopa

                //set the koopa's image
                m_KoopaVec[i]->direction = 1.0f;
                collides = true;

            }else if(m_KoopaVec[i]->IsCollideRight(m_Tube) || m_KoopaVec[i]->IsCollideRight(m_Brick) || m_KoopaVec[i]->IsCollideRight(m_Wood) ||m_KoopaVec[i]->IsCollideRight(m_KoopaVec,i)|| m_KoopaVec[i]->IsCollideRight(m_MushVector)||m_KoopaVec[i]->IsCollideRight(m_Brick)|| m_KoopaVec[i]->IsCollideRight(m_Tube)){
                collides = true;
                m_KoopaVec[i]->direction = -1.0f;


            }

            if(!m_KoopaVec[i]->levelUp && !collides && m_KoopaVec[i]->stepTimes==0){

                if (m_KoopaVec[i]->direction==1) {
                    m_KoopaVec[i]->SetImage(KoopaBack);
                    m_KoopaVec[i]->SetInterval(100);
                    m_KoopaVec[i]->SetLooping(true);
                    m_KoopaVec[i]->SetPlaying();
                    m_KoopaVec[i]->direction = 2.0f;
                }

                else if (m_KoopaVec[i]->direction==-1){
                    m_KoopaVec[i]->SetImage(KoopaPic);
                    m_KoopaVec[i]->SetInterval(100);
                    m_KoopaVec[i]->SetLooping(true);
                    m_KoopaVec[i]->SetPlaying();
                    m_KoopaVec[i]->direction = -2.0f;
                }

            }
            if(m_KoopaVec[i]->stepTimes==0  ) {
                m_KoopaVec[i]->SetPosition({m_KoopaVec[i]->GetPosition().x + (m_KoopaVec[i]->direction), m_KoopaVec[i]->GetPosition().y});
            }
        }
    }





    //yellow mush
    for (const auto & i :m_YellowMushVec){
        if(!std::get<0> (IsOnLand(i)) && i->isActive && i->isActive2 && i->GetVisibility()){
            i->SetPosition({i->GetPosition().x+1.0f,gravity(i->y_start_Yellow_Mushroom,i->time_Yellow_Mushroom,i)});
            i->time_Yellow_Mushroom+=0.3f;
        }
        else if (i->isActive2){
            i->y_start_Yellow_Mushroom = i->GetPosition().y;
            i->time_Yellow_Mushroom =0.0f;

            if(i->IsCollideLeft(m_Tube) || i->IsCollideLeft(m_Wood)){
                i->SetImage(GA_RESOURCE_DIR"/images/Mushroom.png");
                i->direction = 1.0f;
            }
            else if(i->IsCollideRight(m_Tube) || i->IsCollideRight(m_Wood)){
                i->SetImage(GA_RESOURCE_DIR"/images/Mushroom_Back.png");
                i->direction = -1.0f;
            }
            i->SetPosition({i->GetPosition().x+(3.0f* i->direction ),i->GetPosition().y});
        }
    }

    auto stepOnMush = m_Mario->IsStepOn(m_MushVector);
    auto stepOnKoo = m_Mario->IsStepOn(m_KoopaVec);

    //if mario kills enemy
    if((std::get<0>(stepOnMush)) && !m_Mario->MarioStep && !m_Mario->MarioDie && !m_MushVector[std::get<1>(stepOnMush)]->EnemyDie){
        index = std::get<1>(stepOnMush);
        if (m_Mario->KillEnemy_in_a_row==0 && !m_popup1->GetVisibility()){
            m_popup1->SetPosition(m_MushVector[index]->GetPosition());
            m_popup1->timer=20;
            m_Mario->KillEnemy_in_a_row=1;
            score+= 100;
            m_popup1->SetVisible(true);
        }else if (m_Mario->KillEnemy_in_a_row==1 && !m_popup2->GetVisibility()){
            m_popup2->SetPosition(m_MushVector[index]->GetPosition());
            m_popup2->timer=20;
            m_Mario->KillEnemy_in_a_row=2;
            score+= 200;
            m_popup2->SetVisible(true);
        }else if (m_Mario->KillEnemy_in_a_row==2&& !m_popup3->GetVisibility()){
            m_popup3->SetPosition(m_MushVector[index]->GetPosition());
            m_popup3->timer=20;
            m_Mario->KillEnemy_in_a_row=3;
            score+= 300;
            m_popup3->SetVisible(true);
        }else if (m_Mario->KillEnemy_in_a_row==3&& !m_popup4->GetVisibility()){
            m_popup4->SetPosition(m_MushVector[index]->GetPosition());
            m_popup4->timer=20;
            m_Mario->KillEnemy_in_a_row=4;
            score+= 400;
            m_popup4->SetVisible(true);
        }
        t=0;
        m_Mario->PowerJump =20;
        m_Mario->y_start_mario = searchLand(m_Mario)-10.0f;
        m_Mario->m_Jump = true;


        m_Mario_stomp_audio->SetVolume(75);
        m_Mario_stomp_audio->Play();

        m_Mario->MarioStep = true;
        m_MarioStepTime = Util::Time::GetElapsedTimeMs();

        m_MushVector[index]->SetImage(GA_RESOURCE_DIR"/images/goombas_dead.png");

        m_MushVector[index]->EnemyDie = true;

    }
    // control m_popup
    if (m_popup1->timer>0){
        m_popup1->timer-=1;
        m_popup1->SetPosition({m_popup1->GetPosition().x,m_popup1->GetPosition().y+5});
    }
    else {m_popup1->SetVisible(false);}
    if(m_popup2->timer>0){
        m_popup2->timer-=1;
        m_popup2->SetPosition({m_popup2->GetPosition().x,m_popup2->GetPosition().y+5});
    }
    else {m_popup2->SetVisible(false);}
    if (m_popup3->timer>0){
        m_popup3->timer-=1;
        m_popup3->SetPosition({m_popup3->GetPosition().x,m_popup3->GetPosition().y+5});
    }
    else {m_popup3->SetVisible(false);}
    if (m_popup4->timer>0){
        m_popup4->timer-=1;
        m_popup4->SetPosition({m_popup4->GetPosition().x,m_popup4->GetPosition().y+5});
    }
    else {m_popup4->SetVisible(false);}



    if((std::get<0>(stepOnKoo))  && !m_Mario->MarioDie){
        //popup score need to fix!

        index2 = std::get<1>(stepOnKoo);
        if (m_Mario->KillEnemy_in_a_row==0 && m_KoopaVec[index2]->stepTimes ==0){
            m_popup1->SetPosition(m_KoopaVec[index2]->GetPosition());
            m_popup1->timer=20;
            m_Mario->KillEnemy_in_a_row=1;
            score+= 100;
            m_popup1->SetVisible(true);
        }else if (m_Mario->KillEnemy_in_a_row==1 && m_KoopaVec[index2]->stepTimes ==0){
            m_popup2->SetPosition(m_KoopaVec[index2]->GetPosition());
            m_popup2->timer=20;
            m_Mario->KillEnemy_in_a_row=2;
            score+= 200;
            m_popup2->SetVisible(true);
        }else if (m_Mario->KillEnemy_in_a_row==2&& m_KoopaVec[index2]->stepTimes ==0){
            m_popup3->SetPosition(m_KoopaVec[index2]->GetPosition());
            m_popup3->timer=20;
            m_Mario->KillEnemy_in_a_row=3;
            score+= 300;
            m_popup3->SetVisible(true);
        }

        t=0;
        m_Mario->PowerJump =30;
        m_Mario->y_start_mario = searchLand(m_Mario)-10.0f;
        m_Mario->m_Jump = true;


        m_Mario_stomp_audio->SetVolume(75);
        m_Mario_stomp_audio->Play();


        m_Mario->MarioStep = true;
        m_Mario->MarioStepKoopa = true;

        m_MarioStepTime = Util::Time::GetElapsedTimeMs();
        index2 = std::get<1>(stepOnKoo);
        m_KoopaVec[index2]->SetImage(KoopaDeadPic);
        m_KoopaVec[index2]->stepTimes +=1;
        if(m_KoopaVec[index2]->stepTimes>2){
            m_KoopaVec[index2]->stepTimes = 0;
        }


        if(m_Mario->GetPosition().x <= m_KoopaVec[index2]->GetPosition().x){
            m_KoopaVec[index2]->directionUp = 1.0f;
        }
        else if(m_Mario->GetPosition().x > m_KoopaVec[index2]->GetPosition().x){
            m_KoopaVec[index2]->directionUp = -1.0f;
        }
    }
    if(m_Mario->MarioStep){
        cnts= 0.0f;
        unsigned long now1 = Util::Time::GetElapsedTimeMs();
        if(now1-m_MarioStepTime>=300){
            m_MushVector[index]->SetPosition({m_MushVector[index]->GetPosition().x,-2000});
            m_Mario->MarioStep = false;
        }

    }
    //if mario step koopa twice
    if( m_Mario->MarioStepKoopa && m_KoopaVec[index2]->stepTimes==2){
        m_KoopaVec[index2]->levelUp = true;
    }
    if(m_KoopaVec[index2]->levelUp){
        if( m_KoopaVec[index2]->IsCollideRight(m_Wood)){
            m_KoopaVec[index2]->directionUp = -1.0f;
        }
        else if( m_KoopaVec[index2]->IsCollideLeft(m_Wood)){
            m_KoopaVec[index2]->directionUp = 1.0f;
        }
        m_KoopaVec[index2]->SetPosition({m_KoopaVec[index2]->GetPosition().x+(15.0f*m_KoopaVec[index2]->directionUp),m_KoopaVec[index2]->GetPosition().y});
    }

    //if mush killed by koopa
    for(const auto & i : m_MushVector){
        if((i->IsCollideRightDead(m_KoopaVec) || i->IsCollideLeftDead(m_KoopaVec))){
            i->SetImage(MushroomDead2);
            i->isBounced = true;
            i->EnemyDie = true;
        }
        if(i->isBounced){
            i->SetPosition({i->GetPosition().x, i->GetPosition().y- i->time_goombas});
            i -> time_goombas+=1.0;
        }
    }

    //if koopa killed by dead koopa
    for(int i=0;i<m_KoopaVec.size();i++){
        if((m_KoopaVec[i]->IsCollideRightDead(m_KoopaVec,i)) || m_KoopaVec[i]->IsCollideLeftDead(m_KoopaVec,i)){
            LOG_DEBUG("koopa die twice");
            m_KoopaVec[i]->EnemyDie2 = true;
        }
        if(m_KoopaVec[i]->EnemyDie2){
            m_KoopaVec[i]->SetImage(KoopaDeadPic);
            m_KoopaVec[i]->SetPosition({m_KoopaVec[i]->GetPosition().x, m_KoopaVec[i]->GetPosition().y- m_KoopaVec[i]->time_koopa});
            m_KoopaVec[i] -> time_koopa+=1.0;
        }
    }



    //if mario killed by enemy
    if((m_Mario->IsCollideRight(m_MushVector) || m_Mario->IsCollideLeft(m_MushVector) || m_Mario->IsCollideRight(m_KoopaVec) || m_Mario->IsCollideLeft(m_KoopaVec)) && !m_Mario->MarioDie && !m_Mario->MarioStep && !m_Mario->MarioLevelingDown && !std::get<0>(stepOnMush) && !std::get<0>(stepOnKoo)){
        LOG_DEBUG("collide enemy");
        m_Mario_dead_audio->SetVolume(50);
        m_Mario_dead_audio->Play();
        m_MarioDiesTime = Util::Time::GetElapsedTimeMs();


        if(m_Mario->level<=0){MarioDeath();}
        else{
            m_Mario->level=0;
            MarioLevel=0;
            LOG_DEBUG("msk brp kali leveldown");
            m_MarioShrinkTime = Util::Time::GetElapsedTimeMs();
            m_Mario->MarioLevelingDown = true;
            //check
            if(m_EnterLeft){
                m_Mario->MarioShrink(MarioShrink);
            }
            else{
                m_Mario->MarioShrink(MarioShrink);
            }
            countBlinkTime = 0;

        }

    }

    //if mario levelingdown
    if(m_Mario->MarioLevelingDown){
        BlinkTime+=1;
        countBlinkTime = m_Mario->MarioBlinking(countBlinkTime);
        if(BlinkTime>=100){
            m_Mario->MarioLevelingDown = false;
            BlinkTime = 0;
        }
    }


    //if mario heading tiles
    auto headOnBrick = m_Mario->IsHeading(m_Brick);
    auto headOnQues = m_Mario->IsHeading(m_QuesVector);
    if(std::get<0>(headOnBrick)){
        LOG_DEBUG("msk head on brick");
        m_Mario->MarioHeadBrick = true;
        indexTiles = std::get<1>(headOnBrick);
        m_Brick[indexTiles]->marioHeadTime = Util::Time::GetElapsedTimeMs();
        //when mario small or mario level=0 the brick won't break
        if(m_Mario->level == 0 ){
            m_BrickMove[indexTiles]->SetPosition(m_Brick[indexTiles]->GetPosition());
            isBrick = 1;
            //m_Mario_bump_audio->SetVolume(75);
            m_Mario_bump_audio->SetVolume(0);
            m_Mario_bump_audio->Play();
        }
        // when mario big or mario level = 1, so brick will crack
        else if (m_Mario->level >= 1){
            // is brick =2 => brick will crack
            m_Brick_Break_audio->SetVolume(75);
            m_Brick_Break_audio->Play();
            isBrick =2;
            m_Brick[indexTiles]-> SetVisible(false);
            for (int i =0 ; i<4; i++) m_Brick_break[indexTiles][i]->SetVisible(true);
            // m_Brick[indexTiles]->SetPosition({m_Brick[indexTiles]->GetPosition().x, -2000});

        }
        //if mush on the top of it
        for(const auto & i: m_MushVector){
            //define x too else it will only take y as the condition
            if( i->IsStepOn(m_Brick[indexTiles]) && !i->EnemyDie){
                LOG_DEBUG("step on brick");
                i->EnemyDie = true;
                i->isBounced = true;
            }
        }
    }
    else if(std::get<0>(headOnQues) ){
        indexTiles2 = std::get<1>(headOnQues);
        if(!m_Coins[indexTiles2]->isActive){
            LOG_DEBUG("msk head ques");
            m_Mario->MarioHeadQues = true;
            if(m_Mario->level==1){
                LOG_INFO("mario big is heading ques");
            }
            m_QuesVector[indexTiles2]->marioHeadTime = Util::Time::GetElapsedTimeMs();

            m_DeadQues[indexTiles2]->SetPosition(m_QuesVector[indexTiles2]->GetPosition());
            isBrick = 3;
            m_Mario_bump_audio->SetVolume(75);
            m_Mario_bump_audio->Play();

            m_Mario_coin_audio->SetVolume(75);
            m_Mario_coin_audio->Play();

            //coins or mushroom came out
            if(m_QuesVector[indexTiles2]->isActive) {
                if(m_QuesVector[indexTiles2]->isMushInside){
                    indexMush = m_QuesVector[indexTiles2]->indexMush;

                    if(!m_DeadQues[indexTiles2]->GetVisibility() && !m_YellowMushVec[indexMush]->isActive){
                        //change this
                        m_MarioHeadTime_yelmush = Util::Time::GetElapsedTimeMs();
                        m_YellowMushVec[indexMush]->isActive = true;
                        m_YellowMushVec[indexMush]->SetPosition(m_QuesVector[indexTiles2]->GetPosition());
                    }

                }
                else{
                    if(m_Coins[indexTiles2]->GetPosition().y == -1000.0f){
                        m_Coins[indexTiles2]->isActive = true;
                        m_Coins[indexTiles2]->headedBy = 1;
                        coin+=1;
                        m_Coins[indexTiles2]->SetPosition(m_QuesVector[indexTiles2]->GetPosition());

                    }
                }

            }
        }

    }
    //mushroom for leveling up
    for(const auto & i:m_YellowMushVec){
        if(i->isActive){
            auto now5 = Util::Time::GetElapsedTimeMs();
            i->SetVisible(true);
            if(now5-m_MarioHeadTime_yelmush<=60){
                LOG_DEBUG("masuk yellow mush sini");
                LOG_DEBUG(i->GetPosition().y);
                i->SetVisible(false);
                i->SetPosition({i->GetPosition().x,i->GetPosition().y+8.0f});
            }
            else if(now5-m_MarioHeadTime_yelmush>60 && now5-m_MarioHeadTime_yelmush<=500){
                i->SetVisible(true);
                i->SetPosition({i->GetPosition().x,i->GetPosition().y+2.0f});
            }
            else if(now5-m_MarioHeadTime_yelmush>500){
                i->isActive2 = true;

            }
        }
        //leveling up!
        if (m_popup_lvlup_score->timer>0){
            m_popup_lvlup_score->SetPosition({m_popup_lvlup_score->GetPosition().x,m_popup_lvlup_score->GetPosition().y+5});
            m_popup_lvlup_score->timer-=1;
        }else{m_popup_lvlup_score->SetVisible(false);}
        if(i->isActive2){

            if(i->IsCollideRight(m_Mario) || i->IsCollideLeft(m_Mario)){
                LOG_DEBUG("yellow mush collide mario");
                m_popup_lvlup_score->timer=30;
                score+=1000;
                m_popup_lvlup_score->SetPosition({i->GetPosition()});
                m_popup_lvlup_score->SetVisible(true);
                m_Mario->MarioLevelingUp = true;
                i->SetPosition({-1000.0f,-1000.0f});
                PowerUP_audio->SetVolume(50);
                PowerUP_audio->Play();
                m_Mario->level+=1;

                if(m_EnterRight){
                    m_Mario->SetImage(levelUp);
                }
                else if(m_EnterLeft){
                    m_Mario->SetImage(levelUpBack);
                }
                m_Mario->SetPlaying();
                m_Mario->SetInterval(75);


            }

        }
    }

    //if mario leveling up
    if(m_Mario->MarioLevelingUp && !m_Mario->IsPlaying()){
        m_Mario->MarioLevelingUp = false;
    }
    //debugging

    if(isBrick==3){
        LOG_DEBUG("isbrick==3");
        LOG_DEBUG(m_QuesVector[indexTiles2]->isActive);
        LOG_DEBUG(m_Mario->MarioHeadQues);
    }
    //heading brick and question
    if( (isBrick==1 || isBrick ==2 )&&(m_Mario->MarioHeadBrick)){
        if(isBrick==1){
            m_Brick[indexTiles]->isHeaded = true;

        }
        else if (isBrick==2){
            if (!m_Mario->m_Jump) m_Brick[indexTiles]->SetPosition({m_Brick[indexTiles]->GetPosition().x, -20000});

        }
    }
    else if((isBrick==3) && m_QuesVector[indexTiles2]->isActive && m_Mario->MarioHeadQues){
        if(m_Mario->level>=1){
            LOG_DEBUG("mario big head ques2");
        }
        m_QuesVector[indexTiles2]->isHeaded = true;
    }

    //moving bricks
    for(int i=0;i<m_Brick.size();i++){
        if(m_Brick[i]->isHeaded && m_Brick[i]->marioHeadTime!=0){
            unsigned long now2 = Util::Time::GetElapsedTimeMs();
            glm::vec2 tilePos = m_Brick[i]->GetPosition();
            m_BrickMove[i]->SetVisible(true);
            m_Brick[i]->SetVisible(false);
            if(now2-m_Brick[i]->marioHeadTime<=100 ){
                m_BrickMove[i]->SetPosition({m_BrickMove[i]->GetPosition().x,m_BrickMove[i]->GetPosition().y+5.0f});
                auto isheaded = m_BrickMove[i]->IsHeaded(m_Coins2Vec);
                if(std::get<0>(isheaded)){
                    int index = std::get<1>(isheaded);
                    LOG_DEBUG("msk isheaded");
                    m_Coins[index+5]->headedBy = 0;
                    LOG_DEBUG(m_Coins[index+5]->headedBy);
                    m_Coins[index+5]->SetPosition({m_Coins2Vec[index]->GetPosition().x,m_Coins2Vec[index]->GetPosition().y-32.0f});
                    m_Coins[index+5]->isActive = true;
                    m_Coins[index+5]->marioHeadTime = Util::Time::GetElapsedTimeMs();
                    m_Coins2Vec[index]->SetPosition({-1000.0f,-1000.0f});
                }
            }
            else if(now2-m_Brick[i]->marioHeadTime<=200 && now2-m_Brick[i]->marioHeadTime>100){
                m_BrickMove[i]->SetPosition({m_BrickMove[i]->GetPosition().x,m_BrickMove[i]->GetPosition().y-5.0f});
            }
            else{
                m_Brick[i]->SetVisible(true);
                m_BrickMove[i]->SetVisible(false);
                m_Mario->MarioHeadBrick = false;
                m_BrickMove[i]->SetPosition(tilePos);
                m_Brick[i]->isHeaded = false;
            }
        }
    }
    //moving question
    for(int i=0;i<m_QuesVector.size();i++){
        if(m_QuesVector[i]->isHeaded){
            unsigned long now4 = Util::Time::GetElapsedTimeMs();
            glm::vec2 tilePos2 = m_QuesVector[i]->GetPosition();
            m_DeadQues[i]->SetVisible(true);
            m_QuesVector[i]->SetVisible(false);
            if(now4-m_QuesVector[i]->marioHeadTime<=100){
                m_DeadQues[i]->SetPosition({m_DeadQues[i]->GetPosition().x,m_DeadQues[i]->GetPosition().y+5.0f});
            }
            else if(now4-m_QuesVector[i]->marioHeadTime<=200 && now4-m_QuesVector[i]->marioHeadTime>100){
                m_DeadQues[i]->SetPosition({m_DeadQues[i]->GetPosition().x,m_DeadQues[i]->GetPosition().y-5.0f});
            }
            else{
                m_Mario->MarioHeadQues = false;
                m_DeadQues[i]->SetPosition(tilePos2);
                m_QuesVector[i]->isActive = false;
                m_QuesVector[i]->isHeaded = false;
            }
        }
    }

    //coins
    for(int i=0;i<m_Coins.size();i++){
        if(m_Coins[i]->isActive){
            LOG_DEBUG("in m_Coins active");
            auto now3 = Util::Time::GetElapsedTimeMs();
            m_Coins[i]->SetVisible(true);
            //by brick
            LOG_DEBUG(m_Coins[i]->headedBy);
            if(m_Coins[i]->headedBy==0){
                LOG_DEBUG("msk headedby 0");
                if(now3 - m_Coins[i]->marioHeadTime<=450){
                    LOG_DEBUG("msk moving coins");
                    m_Coins[i]->SetPosition({m_Coins[i]->GetPosition().x,m_Coins[i]->GetPosition().y+8.0f});
                }
                else if (now3-m_Coins[i]->marioHeadTime<=900 && now3-m_Coins[i]->marioHeadTime>450){
                    m_Coins[i]->SetPosition({m_Coins[i]->GetPosition().x,m_Coins[i]->GetPosition().y-8.0f});
                }
                else{
                    m_Coins[i]->SetVisible(false);
                    m_Coins[i]->isActive = false;
                    m_Coins[i]->SetPosition({-1000.0f,-1000.0f});
                }
            }
            //by question
            else if(m_Coins[i]->headedBy==1){
                if(now3 - m_QuesVector[i]->marioHeadTime<=450){
                    m_Coins[i]->SetPosition({m_Coins[i]->GetPosition().x,m_Coins[i]->GetPosition().y+8.0f});
                }
                else if (now3-m_QuesVector[i]->marioHeadTime<=900 && now3-m_QuesVector[i]->marioHeadTime>450){
                    m_Coins[i]->SetPosition({m_Coins[i]->GetPosition().x,m_Coins[i]->GetPosition().y-8.0f});
                }
                else{
                    m_Coins[i]->SetVisible(false);
                    m_Coins[i]->isActive = false;
                    m_Coins[i]->SetPosition({-1000.0f,-1000.0f});
                }
            }
        }
    }


    // Makes the Brick Breaking independently => when m_Mario => (level==1) => collide up

    for (int i=0 ; i<m_Brick_break.size();i++){
        for (int Brickbat_index =0 ; Brickbat_index< m_Brick_break[i].size()-1;Brickbat_index++) {
            auto Brickbat_each = m_Brick_break[i][Brickbat_index];
            auto StartPoint= m_Brick_break[i][4];
            float Angle_cos, Angle_sin;
            if (Brickbat_each->GetVisibility()){
                Brickbat_each->CharacterTimePhysics +=0.4;

                //Control the movement of Left top Brickbat
                if (Brickbat_index==0) {Angle_cos = -0.087; Angle_sin = 0.99 ;}
                //Control the movement of Left bottom Brickbat
                else if (Brickbat_index==1) {Angle_cos = -0.17; Angle_sin = 0.98 ;}
                //Control the movement of Right top Brickbat
                else if (Brickbat_index==2){ Angle_cos = 0.087; Angle_sin = 0.99 ;}
                //Control the movement of Right bottom Brickbat
                else if (Brickbat_index==3) {Angle_cos = 0.17; Angle_sin = 0.98 ;}

                Brickbat_each->SetPosition(ParabolicMovement(30,Angle_cos,Angle_sin,Brickbat_each->CharacterTimePhysics,StartPoint));
                //Brickbat_each->SetPosition({Brickbat_each->GetPosition().x+AngelDegree,Brickbat_each->GetPosition().y- Brickbat_each->CharacterTimePhysics});

                // to remove the brickbat when y on coordinate less than -300
                if (Brickbat_each->GetPosition().y <= -300) Brickbat_each->SetVisible(false);
            }
        }

    }

    //if touch pillar
    if(m_Pillar!=nullptr) {
        if(m_Mario->IsCollideRight(m_Pillar) && !m_Mario->MarioFinish){
            m_Mario->MarioFinish = true;
            if(m_Mario->level==0){
                m_Mario->SetImage(MarioPillar);
            }
            else if(m_Mario->level>=1){
                m_Mario->SetImage(MarioPillar2);
                m_Mario->SetInterval(30);
            }
            m_Mario->SetInterval(100);
            m_Mario->SetLooping(true);
            m_Mario->SetPlaying();
        }
    }

    unsigned long timeEnd;
    if(m_Mario->MarioFinish){
        if(m_Mario->GetPosition().y>=-135.0f){
            m_Mario->SetPosition({m_Pillar->GetPosition().x-5.0f,m_Mario->GetPosition().y-5.0f});
        }
        if(m_Flag->GetPosition().y>=-135.0f){
            m_Flag->SetPosition({m_Flag->GetPosition().x,m_Flag->GetPosition().y-5.0f});
        }
        else{
            timeEnd = Util::Time::GetElapsedTimeMs();
            m_Mario->SetPosition({m_Mario->GetPosition().x+6.0f,m_Mario->GetPosition().y});
            if(m_Mario->level==0){
                m_Mario->SetImage(MarioPillarEnd);
            }
            else if(m_Mario->level>=1){
                m_Mario->SetImage(MarioPillarEnd2);
            }

            m_Mario->MarioEnd = true;
            m_Mario->MarioFinish = false;
        }

    }
    if(m_Mario->MarioEnd){
        m_BGMusic->Pause();
        if(!winSong) {
            m_Mario_levelFinish_audio->SetVolume(50);
            m_Mario_levelFinish_audio->Play();
            winSong = true;
        }
        if(Util::Time::GetElapsedTimeMs()-timeEnd >= 15500 && !isWinLevel){
            m_Mario->SetVisible(true);
            m_Mario->SetLooping(true);
            m_Mario->SetPlaying();
            m_Mario->SetInterval(70);
            moveBackground(6.0f,app);
        }
        if(m_Castle[0]->GetPosition().x<=m_Mario->GetPosition().x){
            m_Mario->SetVisible(false);
            isWinLevel = true;

        }

    }

    //mario levelup
    LOG_INFO("Mario POs");
    LOG_INFO(m_Mario->GetPosition().x);
    LOG_INFO(m_Mario->GetPosition().y);

    //if mario stepping the land
    if(std::get<0>(result) &&(m_Mario->GetAnimationPath() == MarioJump || m_Mario->GetAnimationPath() == MarioJumpBack ||m_Mario->GetAnimationPath() == MarioJumpLvl2 || m_Mario->GetAnimationPath() == MarioJumpBackLvl2)){
        if(m_EnterRight){
            if(m_Mario->level == 0){
                m_Mario->SetImage(MarioRun);
            }
            else if(m_Mario->level == 1){
                m_Mario->SetImage(MarioRunLvl2);
            }
        }
        else if(m_EnterLeft){
            LOG_DEBUG("step land left");
            if(m_Mario->level == 0){
                m_Mario->SetImage(MarioRunBack);
            }
            else if(m_Mario->level == 1){
                LOG_DEBUG("msk left level 1");
                m_Mario->SetImage(MarioRunBackLvl2);
            }
        }
    }
    //second world
    if(app->m_Phase==App::Phases::FIRST_WORLD_TWO){
        for(const auto & i : m_Coins2Vec){
            if(i->IsCollideRight(m_Mario) || i->IsCollideLeft(m_Mario)){
                //add sfx
                app->m_Root.RemoveChild(i);
                score = score + 100;
            }
        }
        if(m_MovingPlatform[0]->GetVisibility()){
            //moving platform thingy
            for(const auto & i:m_MovingPlatform){
                i->SetPosition({i->GetPosition().x,i->GetPosition().y-3.0f});
                if(i->GetPosition().y < -600.0f){
                    i->SetPosition({i->GetPosition().x , 600.0f});
                }
            }

            for(const auto & i:m_MovingPlatform2){
                i->SetPosition({i->GetPosition().x,i->GetPosition().y+3.0f});
                if(i->GetPosition().y > 600.0f){
                    i->SetPosition({i->GetPosition().x , -600.0f});
                }
            }
        }

        //finish underworld for world 2
        if(m_Mario->IsCollideRight(m_TubeBig) && (m_Mario->GetPosition().y-m_Mario->GetScaledSize().y/2 == -108.0f)){
            LOG_DEBUG("masuk go up");
            m_Mario->MarioGoUp = true;
        }
        if(m_Mario->MarioGoUp && std::get<0>(IsOnLand(m_Mario))){
            if(m_Mario->GetPosition().x <  50.0f) {
                m_Mario->SetPosition({m_Mario->GetPosition().x + 1.0f, m_Mario->GetPosition().y});
            }
        }

        if(m_Piranhas[0]->GetVisibility()){
            if(piranhaOutTime<50){
                for(const auto & i : m_Piranhas){
                    i->SetPosition({i->GetPosition().x,i->GetPosition().y+1.0f});
                }
            }
            else if(piranhaOutTime >= 50 && piranhaOutTime < 100){
                for(const auto & i : m_Piranhas){
                    i->SetPosition({i->GetPosition().x,i->GetPosition().y-1.0f});
                }
            }
            else{
                piranhaOutTime = 0;
            }
            piranhaOutTime+=1;
        }
        if(m_Mario->IsCollideRight(m_Piranhas) || m_Mario->IsCollideLeft(m_Piranhas)){
            m_Mario->MarioDie = true;
        }
        //koopa red
        if(koopaRedTime==124){
            m_KoopaRed->direction = m_KoopaRed->direction*(-1.0f);
            if(m_KoopaRed->direction < 0){
                m_KoopaRed->SetImage(KoopaPic);
            }
            else{
                m_KoopaRed->SetImage(KoopaBack);
            }

            m_KoopaRed->SetLooping(true);
            m_KoopaRed->SetInterval(100);
            m_KoopaRed->SetPlaying();
            koopaRedTime = 0;
        }
        else{
            m_KoopaRed->SetPosition({m_KoopaRed->GetPosition().x+(2.0f*m_KoopaRed->direction),m_KoopaRed->GetPosition().y});
        }
        koopaRedTime+=1;
    }

    if(FinishLevel){
        LOG_DEBUG("Mario comes out");
        if(MarioComesOutTime<=30){
            m_Mario->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y+1.0f});
        }
        else{
            marioFromTube = false;
        }
        MarioComesOutTime+=1;
    }


    //DO NOT MOVE OR ADD SOMETHING UNDER THESE TWO!!
    //mario go up now
    if(m_Mario->MarioGoUp && m_Mario->GetPosition().x>=50){
        LOG_DEBUG("masuk state finish");
        SetState(State::FINISH);

    }

    //exit
    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        SetState(State::END);

    }
    //if die
    else if(m_Mario->MarioDie){
        m_popup1->SetVisible(false);
        unsigned long now = Util::Time::GetElapsedTimeMs();
        m_Mario->SetImage(GA_RESOURCE_DIR"/Mario/mario_death.png");

        if(now-m_MarioDiesTime<=300){
            m_Mario->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y+5.0f});
        }
        else{
            m_Mario->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y-5.0f});

            if(m_Mario->GetPosition().y<-400.0f){
                LOG_DEBUG("mario die");
                Restart(app);
                LOG_DEBUG("mario die2");
                SetState(State::START);
            }
        }

    }

    //restart
    if(Util::Input::IsKeyPressed(Util::Keycode::R)){
        Restart(app);
        SetState(State::START);
    }

    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    app->m_Root.Update();

    //NEXT LEVEL
    if(isWinLevel || Util::Input::IsKeyPressed(Util::Keycode::N)){
        LOG_DEBUG("next level");
        //blm di restart
        //NextLevel(app);
        if(app->m_Phase==App::Phases::FIRST_WORLD_ONE){
            Restart(app);
            app->SetPhase(App::Phases::FIRST_WORLD_TWO);
            app->ChangePhase(App::Phases::FIRST_WORLD_TWO);
        }
        else if(app->m_Phase==App::Phases::FIRST_WORLD_TWO){
            SetState(State::WINLEVEL);
        }

    }


}
