#ifndef INC_230308_EZREALSKILL_H
#define INC_230308_EZREALSKILL_H

#include <iostream>
#include "Skill.h"

class EzrealSkill : public Skill {
    void q() { std::cout << "RISING SPELL FORCE (끓어오르는 주문의 힘)" << std::endl; };
    void w() { std::cout << "MYSTIC SHOT (신비한 화살)" << std::endl; };
    void e() { std::cout << "ESSENCE FLUX (정수의 흐름)" << std::endl; };
    void r() { std::cout << "ARCANE SHIFT (비전 이동)"  << std::endl; };
};

#endif //INC_230308_EZREALSKILL_H
