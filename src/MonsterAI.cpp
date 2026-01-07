/*****************************************
 *  File_name : MonsterAI.cpp
 *  몬스터의 모든 행동 관리
 ******************************************/
#include "MonsterAI.h"
#include "Monster.h"
#include "Random.h"

MonsterAI::MonsterAI() {}
MonsterAction MonsterAI::decide_action(Monster &m)
{
    int roll = Random::range(1, 100);
    int max_hp = m.get_max_hp();
    if (m.get_hp() <= max_hp * 0.5) {
        if (roll <= 45) return MonsterAction::Heal;
        else if (roll <= 75) return MonsterAction::Defend;
        else if (roll <= 95) return MonsterAction::Attack;
        else return MonsterAction::StrongAttack;
    } else if (m.get_hp() <= 0.7) {
        if (roll <= 50) return MonsterAction::Attack;
        else if (roll <= 75) return MonsterAction::StrongAttack;
        else if (roll <= 90) return MonsterAction::Defend;
        else return MonsterAction::Heal;
    } else {
        if (roll <= 50) return MonsterAction::Attack;
        else if (roll <= 65) return MonsterAction::StrongAttack;
        else if (roll <= 85) return MonsterAction::Idle;
        else if (roll <= 93) return MonsterAction::Defend;
        else return MonsterAction::Heal;
    }
}