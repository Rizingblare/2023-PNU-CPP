#ifndef INC_230308_GANGPLANKSKILL_H
#define INC_230308_GANGPLANKSKILL_H

#include <iostream>
#include "Skill.h"

class GangplankSkill : public Skill {
    void q() { std::cout << "TRIAL BY FIRE (불의 심판)" << std::endl; };
    void w() { std::cout << "PARRRLEY (혀어어어업상)" << std::endl; };
    void e() { std::cout << "REMOVE SCURVY (괴혈병 치료)" << std::endl; };
    void r() { std::cout << "POWDER KEG (화약통)" << std::endl; };
};

#endif //INC_230308_GANGPLANKSKILL_H
