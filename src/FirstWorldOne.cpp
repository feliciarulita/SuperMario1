//
// Created by Felicia Rulita on 2024/5/9.
//
#include "FirstWorldOne.h"
#include <iostream>

FirstWorldOne::FirstWorldOne(int MarioLevel): MarioLevel(MarioLevel) {
    m_CurrentState = State::START;
    this->MarioLevel=MarioLevel;
}


