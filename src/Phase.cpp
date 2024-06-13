//
// Created by Felicia Rulita on 2024/5/8.
//
#include "Phase.h"

void Phase::SetState(State state){
    m_CurrentState = state;
}

void Phase::Restart(App *app) {
    std::cout<<"msk restart"<<std::endl;
    app->m_Root.RemoveAllChildren();

    pressed1 =  false ;
    pressed2 = false;

    speed=2;
    powerjump =0.0f;
    t =0;

    m_BGMusic = nullptr;

    m_Mario_jump_audio = nullptr;
    m_Mario_dead_audio = nullptr;
    m_Mario_coin_audio = nullptr;
    m_Mario_stomp_audio = nullptr;
    m_Mario_bump_audio = nullptr;
    m_Mario_levelFinish_audio = nullptr;
    m_Mario_flagpole_audio = nullptr;

    m_title = nullptr;

    m_score = nullptr;
    m_coin = nullptr;
    m_world = nullptr;
    m_time = nullptr;
    m_lives= nullptr;
    m_popup1 = nullptr;
    m_popup2 = nullptr;
    m_popup3 = nullptr;
    m_popup4 = nullptr;
    m_popup_lvlup_score = nullptr;

    m_Bg = nullptr;

    m_Bg1 = nullptr;

    m_Bg2 = nullptr;
    m_Pillar = nullptr;
    m_Flag = nullptr;
    m_TubeBig = nullptr;
    m_TubeBig2 = nullptr;
    m_Tube2 = nullptr;

    m_DeadQues.clear();
    m_Land.clear();
    m_Tube.clear();
    m_Wood.clear();
    m_Castle.clear();
    m_MovingPlatform.clear();
    m_MovingPlatform2.clear();
    m_TubeBig2Vec.clear();
    m_Brick_break.clear();

    m_Brick.clear();
    m_BrickMove.clear();

    m_BrickBreak = nullptr;

    m_YellowMushVec.clear();

    m_KoopaVec.clear();

    m_KoopaRed = nullptr;

    m_QuesVector.clear();

    m_Question = nullptr;

    m_MushVector.clear();

    m_Piranhas.clear();

    m_Mario = nullptr;
    m_MarioPillar = nullptr;
    m_MarioBack = nullptr;

    m_Mushroom = nullptr;

    m_YellowMush = nullptr;

    m_Coins2 = nullptr;

    m_Coins2Vec.clear();
    m_Coins.clear();

    m_Koopa = nullptr;

    position = {0.0f,0.0f};
    positionLand = {0.0f,0.0f};

    m_PRM = nullptr;
    MarioSlidesRight.clear();
    MarioSlidesLeft.clear();
    MarioSlidesRightLvl2.clear();
    MarioSlidesLeftLvl2.clear();
    MarioRun.clear();
    MarioRunLvl2.clear();
    MarioRunBack.clear();
    MarioRunBackLvl2.clear();
    MarioPillar.clear();
    MarioPillar2.clear();
    MarioShrink.clear();
    Mushroom1.clear();
    QuestionMark.clear();
    CoinsPic.clear();
    KoopaPic.clear();
    levelUp.clear();
    levelUpBack.clear();
    MarioBigFront.clear();
    MarioBigBack.clear();
    MarioJump.clear();
    MarioJumpBack.clear();
    MarioJumpLvl2.clear();
    MarioJumpBackLvl2.clear();
    YellowMushroom.clear();
    MarioPillarEnd.clear();
    MarioPillarEnd2.clear();
    CoinsLvl2.clear();
    KoopaPic.clear();
    KoopaBack.clear();
    KoopaRed.clear();
    KoopaRedBack.clear();
    PiranhaPic.clear();

    index=0;
    index2=0;
    indexTiles = 0;
    indexTiles2 = 0;
    indexMush = 0;
    countBlinkTime = 0;
    BlinkTime = 0;
    isBrick = 0;
    MarioComesOutTime = 0;
    piranhaOutTime = 0;
    koopaRedTime = 0;

    slideTime=0;
    SpeedInAir=0;
    y0= -172.0f;
    h=0 ;
    max_jump=0;

    cnt=0;
    cnts=0;
    time=1000 ;
    score=0 ;
    coin=0;

    timenow = 0;
    m_JumpBaseTime = 0;
    m_MarioDiesTime = 0;
    m_MarioStepTime = 0;
    m_MarioHeadTime = 0;
    m_MarioHeadTime2 = 0;
    m_MarioHeadTime_yelmush = 0;
    m_MarioShrinkTime = 0;

    m_EnterDown = false;
    m_EnterRight = true;
    m_EnterLeft = false;
    m_Collide = false;
    isWinLevel = false;
    winSong = false;
    leftSlide = false;
    rightSlide = false;
    pressUp = false;
    marioStart = false;
    FinishLevel = false;
    marioFromTube = false;



}


void Phase::End(App *app) {
    app->m_Root.RemoveAllChildren();
    SetState(State::EXIT);
}

void Phase::StartLevel(App *app) {
    SetState(State::UPDATE);
}

void Phase::StartLevel2(App *app) {
    SetState(State::UPDATE);
}

void Phase::Finish(App *app) {
    SetState(State::UPDATE);
}

void Phase::WinLevel(App *app) {
    SetState(State::UPDATE);
}

void Phase::WinLevel2(App *app) {
    SetState(State::UPDATE);
}