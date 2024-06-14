//
// Created by Felicia Rulita on 2024/5/7.
//

#ifndef SUPERMARIO1_PHASE_H
#define SUPERMARIO1_PHASE_H

#include "Character.h"
#include "App.h"
#include "Util/Input.hpp"

class Phase{
public:
    enum class State {
        START,
        STARTLEVEL,
        STARTLEVEL2,
        UPDATE,
        FINISH,
        WINLEVEL,
        WINLEVEL2,
        END,
        EXIT,
        GAMEOVER,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void SetState(State state);

    virtual void Start(App *app) = 0;

    virtual void StartLevel(App *app);

    virtual void StartLevel2(App *app);

    virtual void Update(App *app);

    virtual void Finish(App *app);

    virtual void WinLevel(App *app);

    virtual void WinLevel2(App *app);

    virtual void End(App *app);

    void GameOver(App *app);

    void Restart(App *app);

    State m_CurrentState = State::START;

    std::shared_ptr<BackgroundImage> m_Bg;

    float gravity (float y0,float powerjump,std::shared_ptr<AnimatedCharacter>);

    bool pressed1= false ;
    bool pressed2=false;

    float speed=2;
    float powerjump =0.0f;
    float t =0;


    std::shared_ptr<Util::BGM> m_BGMusic;

    std::shared_ptr<Util::SFX> m_Mario_jump_audio;
    std::shared_ptr<Util::SFX> m_Mario_dead_audio;
    std::shared_ptr<Util::SFX> m_Mario_coin_audio;
    std::shared_ptr<Util::SFX> m_Mario_stomp_audio;
    std::shared_ptr<Util::SFX> m_Mario_bump_audio;
    std::shared_ptr<Util::SFX> m_Mario_levelFinish_audio;
    std::shared_ptr<Util::SFX> m_Mario_flagpole_audio;
    std::shared_ptr<Util::SFX> m_Brick_Break_audio;
    std::shared_ptr<Util::SFX> PowerUP_audio;

    std::shared_ptr<TEXTS> m_title;
    std::shared_ptr<TEXTS> m_score;
    std::shared_ptr<TEXTS> m_coin;
    std::shared_ptr<TEXTS> m_world;
    std::shared_ptr<TEXTS> m_time;
    std::shared_ptr<TEXTS> m_finishGame;
    std::shared_ptr<TEXTS> m_instruction;
    std::shared_ptr<TEXTS> m_popup_lvlup_score;
    std::shared_ptr<TEXTS> m_popup1;
    std::shared_ptr<TEXTS> m_popup2;
    std::shared_ptr<TEXTS> m_popup3;
    std::shared_ptr<TEXTS> m_popup4;
    std::shared_ptr<TEXTS> m_lives;

    std::shared_ptr<BackgroundImage> m_Bg1;

    std::shared_ptr<Character> m_Bg2;
    std::shared_ptr<Character> m_Pillar;
    std::shared_ptr<Character> m_Flag;
    std::shared_ptr<Character> m_TubeBig;
    std::shared_ptr<Character> m_TubeBig2;
    std::shared_ptr<Character> m_Land2;
    std::shared_ptr<Character> m_Tube2;

    std::vector<std::shared_ptr<Character>> m_DeadQues;
    std::vector<std::shared_ptr<Character>> m_Land;
    std::vector<std::shared_ptr<Character>> m_Tube;
    std::vector<std::shared_ptr<Character>> m_Wood;
    std::vector<std::shared_ptr<Character>> m_Castle;
    std::vector<std::shared_ptr<Character>> m_MovingPlatform;
    std::vector<std::shared_ptr<Character>> m_MovingPlatform2;
    std::vector<std::shared_ptr<Character>> m_TubeBig2Vec;

    std::vector<std::shared_ptr<Brick>> m_Brick;
    std::vector<std::shared_ptr<Brick>> m_BrickMove;

    std::vector<std::vector<std::shared_ptr<Brick>>> m_Brick_break;

    std::shared_ptr<Brick> m_BrickBreak;

    std::vector<std::shared_ptr<YellowMush>> m_YellowMushVec;

    std::vector<std::shared_ptr<Koopa>> m_KoopaVec;

    std::shared_ptr<Koopa> m_KoopaRed;

    std::vector<std::shared_ptr<QuestionTiles>> m_QuesVector;

    std::shared_ptr<QuestionTiles> m_Question;

    std::vector<std::shared_ptr<Mushroom>> m_MushVector;

    std::vector<std::shared_ptr<Piranha>> m_Piranhas;

    std::shared_ptr<Mario> m_Mario;
    std::shared_ptr<Mario> m_MarioPillar;
    std::shared_ptr<Mario> m_MarioBack;

    std::shared_ptr<Mushroom> m_Mushroom;

    std::shared_ptr<YellowMush> m_YellowMush;

    std::shared_ptr<Coins> m_Coins2;

    std::vector<std::shared_ptr<Coins>> m_Coins2Vec;
    std::vector<std::shared_ptr<Coins>> m_Coins;

    std::shared_ptr<Koopa> m_Koopa;

    glm::vec2 position;
    glm::vec2 positionLand;

    std::shared_ptr<PhaseResourcesManager> m_PRM;

    std::vector<std::string> MarioSlidesRight;
    std::vector<std::string> MarioSlidesLeft;
    std::vector<std::string> MarioSlidesRightLvl2;
    std::vector<std::string> MarioSlidesLeftLvl2;
    std::vector<std::string> MarioRun;
    std::vector<std::string> MarioRunLvl2;
    std::vector<std::string> MarioRunBack;
    std::vector<std::string> MarioRunBackLvl2;
    std::vector<std::string> MarioPillar;
    std::vector<std::string> MarioPillar2;
    std::vector<std::string> MarioShrink;
    std::vector<std::string> MarioShrinkBack;
    std::vector<std::string> Mushroom1;
    std::vector<std::string> QuestionMark;
    std::vector<std::string> CoinsPic;
    std::vector<std::string> levelUp;
    std::vector<std::string> levelUpBack;
    std::vector<std::string> MarioBigFront;
    std::vector<std::string> MarioBigBack;
    std::vector<std::string> MarioJump;
    std::vector<std::string> MarioJumpBack;
    std::vector<std::string> MarioJumpLvl2;
    std::vector<std::string> MarioJumpBackLvl2;
    std::vector<std::string> YellowMushroom;
    std::vector<std::string> MarioPillarEnd;
    std::vector<std::string> MarioPillarEnd2;
    std::vector<std::string> CoinsLvl2;
    std::vector<std::string> KoopaPic;
    std::vector<std::string> KoopaBack;
    std::vector<std::string> KoopaRed; //idk
    std::vector<std::string> KoopaRedBack; //idk
    std::vector<std::string> PiranhaPic;

    std::string KoopaDeadPic;
    std::string MushroomDead1;
    std::string MushroomDead2;

    int index=0;
    int index2=0;
    int indexTiles = 0;
    int indexTiles2 = 0;
    int indexMush = 0;
    int countBlinkTime = 0;
    int BlinkTime = 0;
    int isBrick = 0;
    int MarioLevel = 0;
    int MarioComesOutTime = 0;
    int piranhaOutTime = 0;
    int koopaRedTime = 0;

    float slideTime=0;
    float SpeedInAir=0;
    float y0= -172.0f;
    float h ;
    float max_jump=0;

    unsigned int cnt=0;
    unsigned int cnts=0;
    unsigned int time=1000 ;
    unsigned int score=0 ;
    unsigned int coin=0;

    unsigned long timenow = 0;
    unsigned long m_JumpBaseTime = 0;
    unsigned long m_MarioDiesTime = 0;
    unsigned long m_MarioStepTime = 0;
    unsigned long m_MarioHeadTime = 0;
    unsigned long m_MarioHeadTime2 = 0;
    unsigned long m_MarioHeadTime_yelmush = 0;
    unsigned long m_MarioShrinkTime = 0;

    bool m_EnterDown = false;
    bool m_EnterRight = true;
    bool m_EnterLeft = false;
    bool m_Collide = false;
    bool isWinLevel = false;
    bool winSong = false;
    bool leftSlide = false;
    bool rightSlide = false;
    bool pressUp = false;
    bool marioStart = false;
    bool FinishLevel = false;
    bool marioFromTube = false;

    void Rendering();

    void moveBackground(float position, App *app);

    void callMario();

    void MarioDeath(App *app);

    template <typename T>
    void popupWhenKills(std::shared_ptr<T> enemy, int power, App *app);

    void steppingKoopaTwice(std::shared_ptr<Koopa> koopa, std::shared_ptr<Mario> mario, std::vector<std::shared_ptr<Character>> wood, std::vector<std::shared_ptr<Brick>> bricks, std::vector<std::shared_ptr<Character>> movingplatform,std::vector<std::shared_ptr<Character>> movingplatform2,std::vector<std::shared_ptr<Character>> land, bool red);

    float searchLand(std::shared_ptr<AnimatedCharacter>);

    std::tuple<bool,glm::vec2> IsOnLand(const std::shared_ptr<AnimatedCharacter>&);

    std::tuple<bool,glm::vec2> IsOnLand(const std::shared_ptr<Character>&);

    bool IsCollideRight(const std::shared_ptr<AnimatedCharacter>& Object);

    bool IsCollideLeft(const std::shared_ptr<AnimatedCharacter>& Object);

    bool IsCollideUp();

    void callMarioJump();

    glm::vec2 ParabolicMovement (int v0,float angle_cos, float angel_sin,float time,std::shared_ptr<Character>);


};

#endif //SUPERMARIO1_PHASE_H