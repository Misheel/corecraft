/* Copyright (C) 2006 - 2012 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Boss_Baroness_Anastari
SD%Complete: 75
SDComment: Possess event NYI
SDCategory: Stratholme
EndScriptData */

#include "precompiled.h"

enum
{
    SPELL_BANSHEE_WAIL = 16565,
    SPELL_BANSHEE_CURSE = 16867,
    SPELL_SILENCE = 18327,
    SPELL_POSSESS = 17244,
    SPELL_POSSESS_INV =
        17250, // baroness becomes invisible while possessing a target
};

struct MANGOS_DLL_DECL boss_baroness_anastariAI : public ScriptedAI
{
    boss_baroness_anastariAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiBansheeWailTimer;
    uint32 m_uiBansheeCurseTimer;
    uint32 m_uiSilenceTimer;
    uint32 m_uiPossessTimer;

    void Reset() override
    {
        m_uiBansheeWailTimer = 0;
        m_uiBansheeCurseTimer = 10000;
        m_uiSilenceTimer = 25000;
        m_uiPossessTimer = 15000;
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        // BansheeWail
        if (m_uiBansheeWailTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(
                    ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_BANSHEE_WAIL) == CAST_OK)
                    m_uiBansheeWailTimer = urand(2000, 3000);
            }
        }
        else
            m_uiBansheeWailTimer -= uiDiff;

        // BansheeCurse
        if (m_uiBansheeCurseTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_BANSHEE_CURSE) == CAST_OK)
                m_uiBansheeCurseTimer = 20000;
        }
        else
            m_uiBansheeCurseTimer -= uiDiff;

        // Silence
        if (m_uiSilenceTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(
                    ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_SILENCE) == CAST_OK)
                    m_uiSilenceTimer = 25000;
            }
        }
        else
            m_uiSilenceTimer -= uiDiff;

        // Possess
        // ToDo: uncomment this when the event is properly implemented
        /*if (m_uiPossessTimer < uiDiff)
        {
            if (Unit* pTarget =
        m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_POSSESS) == CAST_OK)
                {
                    DoCastSpellIfCan(m_creature, SPELL_POSSESS_INV,
        CAST_TRIGGERED);
                    m_uiPossessTimer = 30000;
                }
            }
        }
        else
            m_uiPossessTimer -= uiDiff;*/

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_baroness_anastari(Creature* pCreature)
{
    return new boss_baroness_anastariAI(pCreature);
}

void AddSC_boss_baroness_anastari()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_baroness_anastari";
    pNewScript->GetAI = &GetAI_boss_baroness_anastari;
    pNewScript->RegisterSelf();
}
