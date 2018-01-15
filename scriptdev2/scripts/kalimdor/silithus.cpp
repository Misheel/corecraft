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
SDName: Silithus
SD%Complete: 100
SDComment: Quest support: 7785, 8304, 8519.
SDCategory: Silithus
EndScriptData */

/* ContentData
npc_highlord_demitrian
npcs_rutgar_and_frankal
npc_anachronos_the_ancient
EndContentData */

#include "precompiled.h"

/*###
## npc_highlord_demitrian
###*/

#define GOSSIP_ITEM_DEMITRIAN1 "What do you know of it?"
#define GOSSIP_ITEM_DEMITRIAN2 "I am listening , Demitrian."
#define GOSSIP_ITEM_DEMITRIAN3 "Continue, please."
#define GOSSIP_ITEM_DEMITRIAN4 "A battle?"
#define GOSSIP_ITEM_DEMITRIAN5 "<Nod>"
#define GOSSIP_ITEM_DEMITRIAN6 "Caught unaware? How?"
#define GOSSIP_ITEM_DEMITRIAN7 "So what did Ragnaros do next?"

enum
{
    QUEST_EXAMINE_THE_VESSEL = 7785,
    ITEM_BINDINGS_WINDSEEKER_LEFT = 18563,
    ITEM_BINDINGS_WINDSEEKER_RIGHT = 18564,
    ITEM_VESSEL_OF_REBIRTH = 19016,
    GOSSIP_TEXTID_DEMITRIAN1 = 6842,
    GOSSIP_TEXTID_DEMITRIAN2 = 6843,
    GOSSIP_TEXTID_DEMITRIAN3 = 6844,
    GOSSIP_TEXTID_DEMITRIAN4 = 6867,
    GOSSIP_TEXTID_DEMITRIAN5 = 6868,
    GOSSIP_TEXTID_DEMITRIAN6 = 6869,
    GOSSIP_TEXTID_DEMITRIAN7 = 6870
};

bool GossipHello_npc_highlord_demitrian(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetObjectGuid());

    if (pPlayer->GetQuestStatus(QUEST_EXAMINE_THE_VESSEL) ==
            QUEST_STATUS_NONE &&
        (pPlayer->HasItemCount(ITEM_BINDINGS_WINDSEEKER_LEFT, 1, false) ||
            pPlayer->HasItemCount(ITEM_BINDINGS_WINDSEEKER_RIGHT, 1, false)))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_DEMITRIAN1,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    pPlayer->SEND_GOSSIP_MENU(
        pPlayer->GetGossipTextId(pCreature), pCreature->GetObjectGuid());

    return true;
}

bool GossipSelect_npc_highlord_demitrian(
    Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch (uiAction)
    {
    case GOSSIP_ACTION_INFO_DEF:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_DEMITRIAN2,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_DEMITRIAN1, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 1:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_DEMITRIAN3,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_DEMITRIAN2, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 2:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_DEMITRIAN4,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_DEMITRIAN3, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 3:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_DEMITRIAN5,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_DEMITRIAN4, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 4:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_DEMITRIAN6,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_DEMITRIAN5, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 5:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_DEMITRIAN7,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_DEMITRIAN6, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 6:
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_DEMITRIAN7, pCreature->GetObjectGuid());
        pPlayer->add_item(ITEM_VESSEL_OF_REBIRTH, 1);
        break;
    }
    return true;
}

/*###
## npcs_rutgar_and_frankal
###*/

// gossip item text best guess
#define GOSSIP_ITEM_SEEK1 "I seek information about Natalia"

#define GOSSIP_ITEM_RUTGAR2 "That sounds dangerous!"
#define GOSSIP_ITEM_RUTGAR3 "What did you do?"
#define GOSSIP_ITEM_RUTGAR4 "Who?"
#define GOSSIP_ITEM_RUTGAR5 "Women do that. What did she demand?"
#define GOSSIP_ITEM_RUTGAR6 "What do you mean?"
#define GOSSIP_ITEM_RUTGAR7 "What happened next?"

#define GOSSIP_ITEM_FRANKAL11 "Yes, please continue"
#define GOSSIP_ITEM_FRANKAL12 "What language?"
#define GOSSIP_ITEM_FRANKAL13 "The Priestess attacked you?!"
#define GOSSIP_ITEM_FRANKAL14 "I should ask the monkey about this"
#define GOSSIP_ITEM_FRANKAL15 "Then what..."

enum
{
    QUEST_DEAREST_NATALIA = 8304,
    NPC_RUTGAR = 15170,
    NPC_FRANKAL = 15171,
    TRIGGER_RUTGAR = 15222,
    TRIGGER_FRANKAL = 15221,
    GOSSIP_TEXTID_RF = 7754,
    GOSSIP_TEXTID_RUTGAR1 = 7755,
    GOSSIP_TEXTID_RUTGAR2 = 7756,
    GOSSIP_TEXTID_RUTGAR3 = 7757,
    GOSSIP_TEXTID_RUTGAR4 = 7758,
    GOSSIP_TEXTID_RUTGAR5 = 7759,
    GOSSIP_TEXTID_RUTGAR6 = 7760,
    GOSSIP_TEXTID_RUTGAR7 = 7761,
    GOSSIP_TEXTID_FRANKAL1 = 7762,
    GOSSIP_TEXTID_FRANKAL2 = 7763,
    GOSSIP_TEXTID_FRANKAL3 = 7764,
    GOSSIP_TEXTID_FRANKAL4 = 7765,
    GOSSIP_TEXTID_FRANKAL5 = 7766,
    GOSSIP_TEXTID_FRANKAL6 = 7767
};

bool GossipHello_npcs_rutgar_and_frankal(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetObjectGuid());

    if (pPlayer->GetQuestStatus(QUEST_DEAREST_NATALIA) ==
            QUEST_STATUS_INCOMPLETE &&
        pCreature->GetEntry() == NPC_RUTGAR &&
        !pPlayer->GetReqKillOrCastCurrentCount(
            QUEST_DEAREST_NATALIA, TRIGGER_RUTGAR))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_SEEK1,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    if (pPlayer->GetQuestStatus(QUEST_DEAREST_NATALIA) ==
            QUEST_STATUS_INCOMPLETE &&
        pCreature->GetEntry() == NPC_FRANKAL &&
        pPlayer->GetReqKillOrCastCurrentCount(
            QUEST_DEAREST_NATALIA, TRIGGER_RUTGAR))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_SEEK1,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);

    pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_RF, pCreature->GetObjectGuid());

    return true;
}

bool GossipSelect_npcs_rutgar_and_frankal(
    Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch (uiAction)
    {
    case GOSSIP_ACTION_INFO_DEF:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_RUTGAR2,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_RUTGAR1, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 1:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_RUTGAR3,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_RUTGAR2, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 2:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_RUTGAR4,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_RUTGAR3, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 3:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_RUTGAR5,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_RUTGAR4, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 4:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_RUTGAR6,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_RUTGAR5, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 5:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_RUTGAR7,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_RUTGAR6, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 6:
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_RUTGAR7, pCreature->GetObjectGuid());
        //'kill' our trigger to update quest status
        pPlayer->KilledMonsterCredit(
            TRIGGER_RUTGAR, pCreature->GetObjectGuid());
        break;

    case GOSSIP_ACTION_INFO_DEF + 9:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FRANKAL11,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_FRANKAL1, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 10:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FRANKAL12,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_FRANKAL2, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 11:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FRANKAL13,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_FRANKAL3, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 12:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FRANKAL14,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_FRANKAL4, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 13:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FRANKAL15,
            GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_FRANKAL5, pCreature->GetObjectGuid());
        break;
    case GOSSIP_ACTION_INFO_DEF + 14:
        pPlayer->SEND_GOSSIP_MENU(
            GOSSIP_TEXTID_FRANKAL6, pCreature->GetObjectGuid());
        //'kill' our trigger to update quest status
        pPlayer->KilledMonsterCredit(
            TRIGGER_FRANKAL, pCreature->GetObjectGuid());
        break;
    }
    return true;
}

/*###
## npc_anachronos_the_ancient
###*/

enum
{
    // Dragons
    NPC_MERITHRA_OF_THE_DREAM = 15378,
    NPC_CAELESTRASZ = 15379,
    NPC_ARYGOS = 15380,
    NPC_ANACHRONOS_THE_ANCIENT = 15381,
    NPC_ANACHRONOS_QUEST_TRIGGER = 15454, // marks some movement for the dragons

    // Elfs
    NPC_FANDRAL_STAGHELM = 15382,
    NPC_KALDOREI_INFANTRY = 15423,

    // Qiraji warriors
    NPC_QIRAJI_WASP = 15414,
    NPC_QIRAJI_DRONE = 15421,
    NPC_QIRAJI_TANK = 15422,
    NPC_ANUBISATH_CONQUEROR = 15424,

    QUEST_A_PAWN_ON_THE_ETERNAL_BOARD = 8519,

    // Yells -> in chronological order
    SAY_ANACHRONOS_INTRO_1 = -1000740,
    SAY_FANDRAL_INTRO_2 = -1000741,
    SAY_MERITHRA_INTRO_3 = -1000742,
    EMOTE_ARYGOS_NOD = -1000743,
    SAY_CAELESTRASZ_INTRO_4 = -1000744,
    EMOTE_MERITHRA_GLANCE = -1000745,
    SAY_MERITHRA_INTRO_5 = -1000746,

    SAY_MERITHRA_ATTACK_1 = -1000747,
    SAY_ARYGOS_ATTACK_2 = -1000748,
    SAY_ARYGOS_ATTACK_3 = -1000749,
    SAY_CAELESTRASZ_ATTACK_4 = -1000750,
    SAY_CAELESTRASZ_ATTACK_5 = -1000751,

    SAY_ANACHRONOS_SEAL_1 = -1000752,
    SAY_FANDRAL_SEAL_2 = -1000753,
    SAY_ANACHRONOS_SEAL_3 = -1000754,
    SAY_ANACHRONOS_SEAL_4 = -1000755,
    SAY_ANACHRONOS_SEAL_5 = -1000756,
    SAY_FANDRAL_SEAL_6 = -1000757,

    EMOTE_FANDRAL_EXHAUSTED = -1000758,
    SAY_ANACHRONOS_EPILOGUE_1 = -1000759,
    SAY_ANACHRONOS_EPILOGUE_2 = -1000760,
    SAY_ANACHRONOS_EPILOGUE_3 = -1000761,
    EMOTE_ANACHRONOS_SCEPTER = -1000762,
    SAY_FANDRAL_EPILOGUE_4 = -1000763,
    SAY_FANDRAL_EPILOGUE_5 = -1000764,
    EMOTE_FANDRAL_SHATTER = -1000765,
    SAY_ANACHRONOS_EPILOGUE_6 = -1000766,
    SAY_FANDRAL_EPILOGUE_7 = -1000767,
    EMOTE_ANACHRONOS_DISPPOINTED = -1000768,
    EMOTE_ANACHRONOS_PICKUP = -1000769,
    SAY_ANACHRONOS_EPILOGUE_8 = -1000770,

    // The transform spell for Anachronos was removed from DBC
    DISPLAY_ID_BRONZE_DRAGON = 15500,

    // Spells
    SPELL_GREEN_DRAGON_TRANSFORM = 25105,
    SPELL_RED_DRAGON_TRANSFORM = 25106,
    SPELL_BLUE_DRAGON_TRANSFORM = 25107,
    // SPELL_BRONZE_DRAGON_TRANSFORM       = 25108,          // Spell was
    // removed - exists only before 2.0.1

    SPELL_MERITHRA_WAKE = 25145, // should trigger 25172 on targets
    SPELL_ARYGOS_VENGEANCE = 25149,
    SPELL_CAELESTRASZ_MOLTEN_RAIN = 25150,

    SPELL_TIME_STOP =
        25158, // Anachronos stops the battle - should trigger 25171
    SPELL_GLYPH_OF_WARDING =
        25166, // Sends event 9427 - should activate Go 176148
    SPELL_PRISMATIC_BARRIER =
        25159,                   // Sends event 9425 - should activate Go 176146
    SPELL_CALL_ANCIENTS = 25167, // Sends event 9426 - should activate Go 176147
    SPELL_SHATTER_HAMMER = 25182, // Breakes the scepter - needs DB coords

    POINT_ID_DRAGON_ATTACK = 1,
    POINT_ID_EXIT = 2,
    POINT_ID_GATE = 3,
    POINT_ID_SCEPTER_1 = 4,
    POINT_ID_SCEPTER_2 = 5,
    POINT_ID_EPILOGUE = 6,
    DATA_HANDLE_SCEPTER = 7, // dummy members - used in dialogue helper
    DATA_MERITHRA_ATTACK = 8,
    DATA_CAELASTRASZ_ATTACK = 9,

    MAX_DRAGONS = 4,
    MAX_CONQUERORS = 3,
    MAX_QIRAJI = 6,
    MAX_KALDOREI = 20,
};

/* Known event issues:
 * The Kaldorei and Qiraji soldiers don't have the correct flags and factions in
 * DB
 * The Ahn'Qiraj gate gameobjects are missing from DB
 * The spells used by the dragons upon the Qiraji need core support
 * The script events sent by the spells which close the AQ gate needs DB support
 * Can't make Fandral equip the Scepter when Anachronos handles it to him
 */

static const DialogueEntry aEventDialogue[] = {
    {NPC_ANACHRONOS_THE_ANCIENT, 0, 2000}, // summon the dragons
    {SAY_ANACHRONOS_INTRO_1, NPC_ANACHRONOS_THE_ANCIENT, 3000},
    {EMOTE_ONESHOT_SHOUT, NPC_ANACHRONOS_THE_ANCIENT,
     3000}, // make Anachronos shout and summon the warriors
    {SAY_FANDRAL_INTRO_2, NPC_FANDRAL_STAGHELM, 6000},
    {EMOTE_MERITHRA_GLANCE, NPC_MERITHRA_OF_THE_DREAM, 2000},
    {SAY_MERITHRA_INTRO_3, NPC_MERITHRA_OF_THE_DREAM, 3000},
    {EMOTE_ARYGOS_NOD, NPC_ARYGOS, 4000},
    {SAY_CAELESTRASZ_INTRO_4, NPC_CAELESTRASZ, 9000},
    {SAY_MERITHRA_INTRO_5, NPC_MERITHRA_OF_THE_DREAM, 5000},
    {NPC_ANACHRONOS_QUEST_TRIGGER, 0, 0}, // send Merithra to fight
    {DATA_MERITHRA_ATTACK, 0, 5000},      // make Merithra wait
    {SAY_MERITHRA_ATTACK_1, NPC_MERITHRA_OF_THE_DREAM, 1000},
    {SPELL_GREEN_DRAGON_TRANSFORM, 0, 6000},
    {SAY_ARYGOS_ATTACK_2, NPC_ARYGOS, 5000},
    {NPC_ARYGOS, 0, 1000},    // send Arygos to fight
    {POINT_ID_EXIT, 0, 4000}, // make Merithra exit
    {SAY_ARYGOS_ATTACK_3, NPC_ARYGOS, 4000},
    {SPELL_BLUE_DRAGON_TRANSFORM, 0, 5000}, {SPELL_ARYGOS_VENGEANCE, 0, 7000},
    {POINT_ID_DRAGON_ATTACK, 0, 1000}, // make Arygos exit
    {SAY_CAELESTRASZ_ATTACK_4, NPC_CAELESTRASZ, 5000},
    {NPC_CAELESTRASZ, 0, 0},            // send Caelestrasz to fight
    {DATA_CAELASTRASZ_ATTACK, 0, 3000}, // make Caelestrasz wait
    {SAY_CAELESTRASZ_ATTACK_5, NPC_CAELESTRASZ, 5000},
    {SPELL_RED_DRAGON_TRANSFORM, 0, 4000},    // transform Caelestrasz
    {SPELL_CAELESTRASZ_MOLTEN_RAIN, 0, 6000}, // Caelestrasz casts molten rain
    {SAY_ANACHRONOS_SEAL_1, NPC_ANACHRONOS_THE_ANCIENT, 5000},
    {SAY_FANDRAL_SEAL_2, NPC_FANDRAL_STAGHELM, 3000},
    {SAY_ANACHRONOS_SEAL_3, NPC_ANACHRONOS_THE_ANCIENT, 1000},
    {POINT_ID_GATE, 0, 1000},     // send Anachronos to the gate
    {NPC_FANDRAL_STAGHELM, 0, 0}, // send Fandral to the gate
    {SPELL_TIME_STOP, 0, 7000},   // Anachronos casts Time Stop
    {SPELL_PRISMATIC_BARRIER, 0, 15000}, {SPELL_GLYPH_OF_WARDING, 0, 4000},
    {SAY_ANACHRONOS_SEAL_5, NPC_ANACHRONOS_THE_ANCIENT, 3000},
    {SAY_FANDRAL_SEAL_6, NPC_FANDRAL_STAGHELM, 9000},
    {EMOTE_FANDRAL_EXHAUSTED, NPC_FANDRAL_STAGHELM, 1000},
    {SAY_ANACHRONOS_EPILOGUE_1, NPC_ANACHRONOS_THE_ANCIENT, 6000},
    {SAY_ANACHRONOS_EPILOGUE_2, NPC_ANACHRONOS_THE_ANCIENT, 5000},
    {SAY_ANACHRONOS_EPILOGUE_3, NPC_ANACHRONOS_THE_ANCIENT, 15000},
    {DATA_HANDLE_SCEPTER, NPC_ANACHRONOS_THE_ANCIENT,
     3000}, // handle the scepter
    {SAY_FANDRAL_EPILOGUE_4, NPC_FANDRAL_STAGHELM, 3000},
    {POINT_ID_SCEPTER_2, 0, 4000}, // make Anachronos stand
    {SAY_FANDRAL_EPILOGUE_5, NPC_FANDRAL_STAGHELM, 12000},
    {EMOTE_FANDRAL_SHATTER, NPC_FANDRAL_STAGHELM, 3000},
    {SAY_ANACHRONOS_EPILOGUE_6, NPC_ANACHRONOS_THE_ANCIENT, 0},
    {SAY_FANDRAL_EPILOGUE_7, NPC_FANDRAL_STAGHELM, 8000},
    {POINT_ID_EPILOGUE, 0, 4000}, // move Fandral to Anachronos
    {EMOTE_ANACHRONOS_DISPPOINTED, NPC_ANACHRONOS_THE_ANCIENT, 1000},
    {POINT_ID_SCEPTER_1, 0, 0}, // make Anachronos pick the pieces
    {0, 0, 0},
};

struct EventLocations
{
    float m_fX, m_fY, m_fZ, m_fO;
    uint32 m_uiEntry;
};

static EventLocations aEternalBoardNPCs[MAX_DRAGONS] = {
    {-8029.301f, 1534.612f, 2.609f, 3.121f, NPC_FANDRAL_STAGHELM},
    {-8034.227f, 1536.580f, 2.609f, 6.161f, NPC_ARYGOS},
    {-8031.935f, 1532.658f, 2.609f, 1.012f, NPC_CAELESTRASZ},
    {-8034.106f, 1534.224f, 2.609f, 0.290f, NPC_MERITHRA_OF_THE_DREAM},
};

static EventLocations aEternalBoardMovement[] = {
    {-8159.951f, 1525.241f, 74.994f, 0, 0}, // 0 Flight position for dragons
    {-8106.238f, 1525.948f, 2.639f, 0, 0},  // 1 Anachronos gate location
    {-8103.861f, 1525.923f, 2.677f, 0, 0},  // 2 Fandral gate location
    {-8107.387f, 1523.641f, 2.609f, 0, 0},  // 3 Shattered scepter
    {-8100.921f, 1527.740f, 2.871f, 0, 0},  // 4 Fandral epilogue location
    {-8115.270f, 1515.926f, 3.305f, 0,
     0}, // 5 Anachronos gather broken scepter 1
    {-8116.879f, 1530.615f, 3.762f, 0,
     0}, // 6 Anachronos gather broken scepter 2
    {-7997.790f, 1548.664f, 3.738f, 0, 0},  // 7 Fandral exit location
    {-8061.933f, 1496.196f, 2.556f, 0, 0},  // 8 Anachronos launch location
    {-8008.705f, 1446.063f, 44.104f, 0, 0}, // 9 Anachronos flight location
    {-8085.748f, 1521.484f, 2.624f, 0,
     0} // 10 Anchor point for the army summoning
};

struct MANGOS_DLL_DECL npc_anachronos_the_ancientAI : public ScriptedAI,
                                                      private DialogueHelper
{
    npc_anachronos_the_ancientAI(Creature* pCreature)
      : ScriptedAI(pCreature), DialogueHelper(aEventDialogue)
    {
        Reset();
    }

    uint32 m_uiEventTimer;

    uint8 m_uiEventStage;

    ObjectGuid m_fandralGuid;
    ObjectGuid m_merithraGuid;
    ObjectGuid m_CaelestraszGuid;
    ObjectGuid m_arygosGuid;
    ObjectGuid m_playerGuid;
    ObjectGuid m_triggerGuid;

    GUIDList m_lQirajiWarriorsList;

    void Reset() override
    {
        // We summon the rest of the dragons on timer
        m_uiEventTimer = 100;
        m_uiEventStage = 0;
    }

    void JustDidDialogueStep(int32 iEntry) override
    {
        switch (iEntry)
        {
        case NPC_ANACHRONOS_THE_ANCIENT:
            // Call the other dragons
            DoSummonDragons();
            break;
        case EMOTE_ONESHOT_SHOUT:
            // Summon warriors
            DoSummonWarriors();
            m_creature->HandleEmote(EMOTE_ONESHOT_SHOUT);
            break;
        case SAY_FANDRAL_INTRO_2:
            if (Creature* pFandral =
                    m_creature->GetMap()->GetCreature(m_fandralGuid))
                pFandral->SetFacingToObject(m_creature);
            break;
        case EMOTE_MERITHRA_GLANCE:
            if (Creature* pMerithra =
                    m_creature->GetMap()->GetCreature(m_merithraGuid))
            {
                if (Creature* pFandral =
                        m_creature->GetMap()->GetCreature(m_fandralGuid))
                    pFandral->SetFacingToObject(pMerithra);
            }
            break;
        case NPC_ANACHRONOS_QUEST_TRIGGER:
            // Move Merithra to attack
            if (Creature* pTrigger = GetClosestCreatureWithEntry(
                    m_creature, NPC_ANACHRONOS_QUEST_TRIGGER, 35.0f))
            {
                m_triggerGuid = pTrigger->GetObjectGuid();
                if (Creature* pMerithra =
                        m_creature->GetMap()->GetCreature(m_merithraGuid))
                {
                    pMerithra->movement_gens.push(
                        new movement::PointMovementGenerator(
                            POINT_ID_DRAGON_ATTACK, pTrigger->GetX(),
                            pTrigger->GetY(), pTrigger->GetZ(), true, true));
                }
            }
            break;
        case SPELL_GREEN_DRAGON_TRANSFORM:
            if (Creature* pMerithra =
                    m_creature->GetMap()->GetCreature(m_merithraGuid))
                pMerithra->CastSpell(
                    pMerithra, SPELL_GREEN_DRAGON_TRANSFORM, false);
            break;
        case SAY_ARYGOS_ATTACK_2:
            if (Creature* pMerithra =
                    m_creature->GetMap()->GetCreature(m_merithraGuid))
                pMerithra->CastSpell(pMerithra, SPELL_MERITHRA_WAKE, false);
            break;
        case NPC_ARYGOS:
            // Move Arygos to attack
            if (Creature* pTrigger =
                    m_creature->GetMap()->GetCreature(m_triggerGuid))
            {
                if (Creature* pArygos =
                        m_creature->GetMap()->GetCreature(m_arygosGuid))
                {
                    pArygos->movement_gens.push(
                        new movement::PointMovementGenerator(
                            POINT_ID_DRAGON_ATTACK, pTrigger->GetX(),
                            pTrigger->GetY(), pTrigger->GetZ(), true, true));
                }
            }
            break;
        case POINT_ID_EXIT:
            // Move Merithra to the exit point
            if (Creature* pMerithra =
                    m_creature->GetMap()->GetCreature(m_merithraGuid))
            {
                pMerithra->SetByteValue(UNIT_FIELD_BYTES_1, 3,
                    UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_UNK_2);
                pMerithra->SetLevitate(true);
                pMerithra->movement_gens.push(
                    new movement::PointMovementGenerator(POINT_ID_EXIT,
                        aEternalBoardMovement[0].m_fX,
                        aEternalBoardMovement[0].m_fY,
                        aEternalBoardMovement[0].m_fZ, true, true));
                pMerithra->ForcedDespawn(9000);
            }
            break;
        case SPELL_BLUE_DRAGON_TRANSFORM:
            if (Creature* pArygos =
                    m_creature->GetMap()->GetCreature(m_arygosGuid))
                pArygos->CastSpell(pArygos, SPELL_BLUE_DRAGON_TRANSFORM, false);
            break;
        case SPELL_ARYGOS_VENGEANCE:
            if (Creature* pArygos =
                    m_creature->GetMap()->GetCreature(m_arygosGuid))
                pArygos->CastSpell(pArygos, SPELL_ARYGOS_VENGEANCE, false);
            break;
        case POINT_ID_DRAGON_ATTACK:
            // Move Arygos to the exit point
            if (Creature* pArygos =
                    m_creature->GetMap()->GetCreature(m_arygosGuid))
            {
                pArygos->SetByteValue(UNIT_FIELD_BYTES_1, 3,
                    UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_UNK_2);
                pArygos->SetLevitate(true);
                pArygos->movement_gens.push(
                    new movement::PointMovementGenerator(POINT_ID_EXIT,
                        aEternalBoardMovement[0].m_fX,
                        aEternalBoardMovement[0].m_fY,
                        aEternalBoardMovement[0].m_fZ, false, true));
                pArygos->ForcedDespawn(9000);
            }
            break;
        case NPC_CAELESTRASZ:
            // Move Caelestrasz to attack
            if (Creature* pTrigger =
                    m_creature->GetMap()->GetCreature(m_triggerGuid))
            {
                if (Creature* pCaelestrasz =
                        m_creature->GetMap()->GetCreature(m_CaelestraszGuid))
                {
                    pCaelestrasz->movement_gens.push(
                        new movement::PointMovementGenerator(
                            POINT_ID_DRAGON_ATTACK, pTrigger->GetX(),
                            pTrigger->GetY(), pTrigger->GetZ(), false, true));
                }
            }
            break;
        case SPELL_RED_DRAGON_TRANSFORM:
            if (Creature* pCaelestrasz =
                    m_creature->GetMap()->GetCreature(m_CaelestraszGuid))
                pCaelestrasz->CastSpell(
                    pCaelestrasz, SPELL_RED_DRAGON_TRANSFORM, false);
            break;
        case SPELL_CAELESTRASZ_MOLTEN_RAIN:
            if (Creature* pCaelestrasz =
                    m_creature->GetMap()->GetCreature(m_CaelestraszGuid))
                pCaelestrasz->CastSpell(
                    pCaelestrasz, SPELL_CAELESTRASZ_MOLTEN_RAIN, false);
            break;
        case SAY_ANACHRONOS_SEAL_1:
            // Send Caelestrasz on flight
            if (Creature* pCaelestrasz =
                    m_creature->GetMap()->GetCreature(m_CaelestraszGuid))
            {
                pCaelestrasz->SetByteValue(UNIT_FIELD_BYTES_1, 3,
                    UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_UNK_2);
                pCaelestrasz->SetLevitate(true);
                m_creature->movement_gens.push(
                    new movement::PointMovementGenerator(POINT_ID_EXIT,
                        aEternalBoardMovement[0].m_fX,
                        aEternalBoardMovement[0].m_fY,
                        aEternalBoardMovement[0].m_fZ, false, true));
                pCaelestrasz->ForcedDespawn(9000);
            }
            if (Creature* pFandral =
                    m_creature->GetMap()->GetCreature(m_fandralGuid))
                m_creature->SetFacingToObject(pFandral);
            break;
        case SAY_FANDRAL_SEAL_2:
            if (Creature* pFandral =
                    m_creature->GetMap()->GetCreature(m_fandralGuid))
                pFandral->SetFacingToObject(m_creature);
            break;
        case POINT_ID_GATE:
            // Send Anachronos to the gate
            m_creature->movement_gens.push(new movement::PointMovementGenerator(
                POINT_ID_GATE, aEternalBoardMovement[1].m_fX,
                aEternalBoardMovement[1].m_fY, aEternalBoardMovement[1].m_fZ,
                false, true));
            break;
        case NPC_FANDRAL_STAGHELM:
            // Send Fandral to the gate
            if (Creature* pFandral =
                    m_creature->GetMap()->GetCreature(m_fandralGuid))
            {
                pFandral->SetWalk(false);
                pFandral->movement_gens.push(
                    new movement::PointMovementGenerator(POINT_ID_GATE,
                        aEternalBoardMovement[2].m_fX,
                        aEternalBoardMovement[2].m_fY,
                        aEternalBoardMovement[2].m_fZ, false, true));
            }
            break;
        case SPELL_PRISMATIC_BARRIER:
            DoCastSpellIfCan(m_creature, SPELL_PRISMATIC_BARRIER);
            break;
        case SPELL_GLYPH_OF_WARDING:
            DoCastSpellIfCan(m_creature, SPELL_GLYPH_OF_WARDING);
            break;
        case SAY_FANDRAL_SEAL_6:
            // Here Anachronos should continue to cast something
            if (Creature* pFandral =
                    m_creature->GetMap()->GetCreature(m_fandralGuid))
                pFandral->CastSpell(pFandral, SPELL_CALL_ANCIENTS, false);
            break;
        case EMOTE_FANDRAL_EXHAUSTED:
            if (Creature* pFandral =
                    m_creature->GetMap()->GetCreature(m_fandralGuid))
            {
                pFandral->SetStandState(UNIT_STAND_STATE_KNEEL);
                m_creature->SetFacingToObject(pFandral);
            }
            break;
        case DATA_HANDLE_SCEPTER:
            // Give the scepter to Fandral (it should equip it somehow)
            if (Creature* pFandral =
                    m_creature->GetMap()->GetCreature(m_fandralGuid))
                DoScriptText(EMOTE_ANACHRONOS_SCEPTER, m_creature, pFandral);
            m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);
            break;
        case SAY_FANDRAL_EPILOGUE_4:
            if (Creature* pFandral =
                    m_creature->GetMap()->GetCreature(m_fandralGuid))
                pFandral->SetStandState(UNIT_STAND_STATE_STAND);
            break;
        case POINT_ID_SCEPTER_2:
            m_creature->SetStandState(UNIT_STAND_STATE_STAND);
            break;
        case EMOTE_FANDRAL_SHATTER:
            // Shatter the scepter
            if (Creature* pFandral =
                    m_creature->GetMap()->GetCreature(m_fandralGuid))
                pFandral->CastSpell(pFandral, SPELL_SHATTER_HAMMER, false);
            break;
        case SAY_ANACHRONOS_EPILOGUE_6:
            if (Creature* pFandral =
                    m_creature->GetMap()->GetCreature(m_fandralGuid))
            {
                pFandral->SetWalk(true);
                pFandral->movement_gens.push(
                    new movement::PointMovementGenerator(POINT_ID_SCEPTER_1,
                        aEternalBoardMovement[3].m_fX,
                        aEternalBoardMovement[3].m_fY,
                        aEternalBoardMovement[3].m_fZ, false, true));
            }
            break;
        case POINT_ID_EPILOGUE:
            // Make Fandral leave
            if (Creature* pFandral =
                    m_creature->GetMap()->GetCreature(m_fandralGuid))
                pFandral->movement_gens.push(
                    new movement::PointMovementGenerator(POINT_ID_EXIT,
                        aEternalBoardMovement[7].m_fX,
                        aEternalBoardMovement[7].m_fY,
                        aEternalBoardMovement[7].m_fZ, false, true));
            break;
        case POINT_ID_SCEPTER_1:
            // Anachronos collects the pieces
            m_creature->movement_gens.push(new movement::PointMovementGenerator(
                POINT_ID_SCEPTER_1, aEternalBoardMovement[5].m_fX,
                aEternalBoardMovement[5].m_fY, aEternalBoardMovement[5].m_fZ,
                false, true));
            break;
        }
    }

    Creature* GetSpeakerByEntry(uint32 uiEntry) override
    {
        switch (uiEntry)
        {
        case NPC_ANACHRONOS_THE_ANCIENT:
            return m_creature;
        case NPC_ARYGOS:
            return m_creature->GetMap()->GetCreature(m_arygosGuid);
        case NPC_CAELESTRASZ:
            return m_creature->GetMap()->GetCreature(m_CaelestraszGuid);
        case NPC_MERITHRA_OF_THE_DREAM:
            return m_creature->GetMap()->GetCreature(m_merithraGuid);
        case NPC_FANDRAL_STAGHELM:
            return m_creature->GetMap()->GetCreature(m_fandralGuid);

        default:
            return NULL;
        }
    }

    void DoSummonDragons()
    {
        for (auto& aEternalBoardNPC : aEternalBoardNPCs)
            m_creature->SummonCreature(aEternalBoardNPC.m_uiEntry,
                aEternalBoardNPC.m_fX, aEternalBoardNPC.m_fY,
                aEternalBoardNPC.m_fZ, aEternalBoardNPC.m_fO,
                TEMPSUMMON_CORPSE_DESPAWN, 0);

        // Also summon the 3 anubisath conquerors
        for (uint8 i = 0; i < MAX_CONQUERORS; ++i)
        {
            auto pos = m_creature->GetPointXYZ(
                G3D::Vector3(aEternalBoardMovement[10].m_fX,
                    aEternalBoardMovement[10].m_fY,
                    aEternalBoardMovement[10].m_fZ),
                2 * M_PI_F * rand_norm_f(), 20.0f * rand_norm_f());
            m_creature->SummonCreature(NPC_ANUBISATH_CONQUEROR, pos.x, pos.y,
                pos.z, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
        }
    }

    void DoSummonWarriors()
    {
        // Summon kaldorei warriors
        for (uint8 i = 0; i < MAX_KALDOREI; ++i)
        {
            auto pos = m_creature->GetPointXYZ(
                G3D::Vector3(aEternalBoardMovement[10].m_fX,
                    aEternalBoardMovement[10].m_fY,
                    aEternalBoardMovement[10].m_fZ),
                2 * M_PI_F * rand_norm_f(), 10.0f * rand_norm_f());
            m_creature->SummonCreature(NPC_KALDOREI_INFANTRY, pos.x, pos.y,
                pos.z, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
        }

        // Summon Qiraji warriors
        for (uint8 i = 0; i < MAX_QIRAJI; ++i)
        {
            auto pos = m_creature->GetPointXYZ(
                G3D::Vector3(aEternalBoardMovement[10].m_fX,
                    aEternalBoardMovement[10].m_fY,
                    aEternalBoardMovement[10].m_fZ),
                2 * M_PI_F * rand_norm_f(), 15.0f * rand_norm_f());
            m_creature->SummonCreature(NPC_QIRAJI_WASP, pos.x, pos.y, pos.z,
                0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);

            pos = m_creature->GetPointXYZ(
                G3D::Vector3(aEternalBoardMovement[10].m_fX,
                    aEternalBoardMovement[10].m_fY,
                    aEternalBoardMovement[10].m_fZ),
                2 * M_PI_F * rand_norm_f(), 15.0f * rand_norm_f());
            m_creature->SummonCreature(NPC_QIRAJI_DRONE, pos.x, pos.y, pos.z,
                0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);

            pos = m_creature->GetPointXYZ(
                G3D::Vector3(aEternalBoardMovement[10].m_fX,
                    aEternalBoardMovement[10].m_fY,
                    aEternalBoardMovement[10].m_fZ),
                2 * M_PI_F * rand_norm_f(), 15.0f * rand_norm_f());
            m_creature->SummonCreature(NPC_QIRAJI_TANK, pos.x, pos.y, pos.z,
                0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
        }
    }

    void DoUnsummonArmy()
    {
        for (GUIDList::const_iterator itr = m_lQirajiWarriorsList.begin();
             itr != m_lQirajiWarriorsList.end(); ++itr)
        {
            if (Creature* pTemp = m_creature->GetMap()->GetCreature(*itr))
                pTemp->ForcedDespawn();
        }
    }

    void JustSummoned(Creature* pSummoned) override
    {
        // Also remove npc flags where needed
        switch (pSummoned->GetEntry())
        {
        case NPC_FANDRAL_STAGHELM:
            m_fandralGuid = pSummoned->GetObjectGuid();
            break;
        case NPC_MERITHRA_OF_THE_DREAM:
            m_merithraGuid = pSummoned->GetObjectGuid();
            pSummoned->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
            break;
        case NPC_CAELESTRASZ:
            m_CaelestraszGuid = pSummoned->GetObjectGuid();
            pSummoned->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
            break;
        case NPC_ARYGOS:
            m_arygosGuid = pSummoned->GetObjectGuid();
            pSummoned->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
            break;
        case NPC_ANUBISATH_CONQUEROR:
        case NPC_QIRAJI_WASP:
        case NPC_QIRAJI_DRONE:
        case NPC_QIRAJI_TANK:
        case NPC_KALDOREI_INFANTRY:
            m_lQirajiWarriorsList.push_back(pSummoned->GetObjectGuid());
            break;
        }
    }

    void MovementInform(movement::gen uiType, uint32 uiPointId) override
    {
        if (uiType != movement::gen::point)
            return;

        switch (uiPointId)
        {
        case POINT_ID_GATE:
            // Cast time stop when he reaches the gate
            DoCastSpellIfCan(m_creature, SPELL_TIME_STOP);
            StartNextDialogueText(SPELL_TIME_STOP);
            break;
        case POINT_ID_SCEPTER_1:
            // Pickup the pieces
            DoScriptText(EMOTE_ANACHRONOS_PICKUP, m_creature);
            m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);
            m_uiEventTimer = 2000;
            break;
        case POINT_ID_SCEPTER_2:
            // Pickup the pieces
            DoScriptText(SAY_ANACHRONOS_EPILOGUE_8, m_creature);
            m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);
            m_uiEventTimer = 4000;
            break;
        case POINT_ID_EXIT:
            // Spell was removed, manually change the display
            // DoCastSpellIfCan(m_creature, SPELL_BRONZE_DRAGON_TRANSFORM);
            m_creature->SetDisplayId(DISPLAY_ID_BRONZE_DRAGON);
            m_uiEventTimer = 4000;
            break;
        }
    }

    void SummonedMovementInform(
        Creature* pSummoned, movement::gen type, uint32 uiPointId) override
    {
        if (type != movement::gen::point)
            return;

        if (pSummoned->GetEntry() == NPC_FANDRAL_STAGHELM)
        {
            switch (uiPointId)
            {
            case POINT_ID_EPILOGUE:
                // Face Anachronos and restart the dialogue
                pSummoned->SetFacingToObject(m_creature);
                StartNextDialogueText(SAY_FANDRAL_EPILOGUE_7);
                DoUnsummonArmy();
                break;
            case POINT_ID_SCEPTER_1:
                pSummoned->movement_gens.push(
                    new movement::PointMovementGenerator(POINT_ID_EPILOGUE,
                        aEternalBoardMovement[4].m_fX,
                        aEternalBoardMovement[4].m_fY,
                        aEternalBoardMovement[4].m_fZ, true, true));
                break;
            case POINT_ID_EXIT:
                pSummoned->ForcedDespawn();
                break;
            }
        }
        else if (uiPointId == POINT_ID_DRAGON_ATTACK)
        {
            switch (pSummoned->GetEntry())
            {
            case NPC_MERITHRA_OF_THE_DREAM:
                StartNextDialogueText(DATA_MERITHRA_ATTACK);
                break;
            case NPC_CAELESTRASZ:
                StartNextDialogueText(DATA_CAELASTRASZ_ATTACK);
                break;
            }
        }
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        DialogueUpdate(uiDiff);

        if (m_uiEventTimer)
        {
            if (m_uiEventTimer <= uiDiff)
            {
                switch (m_uiEventStage)
                {
                case 0:
                    // Start the dialogue
                    StartNextDialogueText(NPC_ANACHRONOS_THE_ANCIENT);
                    m_uiEventTimer = 0;
                    break;
                case 1:
                    // Do the epilogue movement
                    m_creature->movement_gens.push(
                        new movement::PointMovementGenerator(POINT_ID_SCEPTER_2,
                            aEternalBoardMovement[6].m_fX,
                            aEternalBoardMovement[6].m_fY,
                            aEternalBoardMovement[6].m_fZ, false, true));
                    m_creature->SetStandState(UNIT_STAND_STATE_STAND);
                    m_uiEventTimer = 0;
                    break;
                case 2:
                    // Complete quest and despawn gate
                    if (Player* pPlayer =
                            m_creature->GetMap()->GetPlayer(m_playerGuid))
                        pPlayer->GroupEventHappens(
                            QUEST_A_PAWN_ON_THE_ETERNAL_BOARD, m_creature);
                    m_creature->SetStandState(UNIT_STAND_STATE_STAND);
                    m_uiEventTimer = 4000;
                    break;
                case 3:
                    // Move to exit
                    m_creature->movement_gens.push(
                        new movement::PointMovementGenerator(POINT_ID_EXIT,
                            aEternalBoardMovement[8].m_fX,
                            aEternalBoardMovement[8].m_fY,
                            aEternalBoardMovement[8].m_fZ, false, true));
                    m_uiEventTimer = 0;
                    break;
                case 4:
                    // Take off and fly
                    m_creature->SetByteValue(UNIT_FIELD_BYTES_1, 3,
                        UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_UNK_2);
                    m_creature->SetLevitate(true);
                    m_creature->movement_gens.push(
                        new movement::PointMovementGenerator(0,
                            aEternalBoardMovement[9].m_fX,
                            aEternalBoardMovement[9].m_fY,
                            aEternalBoardMovement[9].m_fZ, false, true));
                    m_creature->ForcedDespawn(10000);
                    m_uiEventTimer = 0;
                    break;
                }
                ++m_uiEventStage;
            }
            else
                m_uiEventTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_npc_anachronos_the_ancient(Creature* pCreature)
{
    return new npc_anachronos_the_ancientAI(pCreature);
}

bool QuestAcceptGO_crystalline_tear(
    Player* pPlayer, GameObject* pGo, const Quest* pQuest)
{
    // Summon the controller dragon at GO position (orientation is wrong -
    // hardcoded)
    if (pQuest->GetQuestId() == QUEST_A_PAWN_ON_THE_ETERNAL_BOARD)
    {
        // Check if event is already in progress first
        if (GetClosestCreatureWithEntry(
                pGo, NPC_ANACHRONOS_THE_ANCIENT, 90.0f) != nullptr)
            return true;

        if (Creature* pAnachronos = pPlayer->SummonCreature(
                NPC_ANACHRONOS_THE_ANCIENT, pGo->GetX(), pGo->GetY(),
                pGo->GetZ(), 3.75f, TEMPSUMMON_CORPSE_DESPAWN, 0))
        {
            // Send the player's guid in order to handle the quest complete
            if (npc_anachronos_the_ancientAI* pAnachronosAI =
                    dynamic_cast<npc_anachronos_the_ancientAI*>(
                        pAnachronos->AI()))
                pAnachronosAI->m_playerGuid = pPlayer->GetObjectGuid();
        }
    }

    return true;
}

void AddSC_silithus()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "npc_highlord_demitrian";
    pNewScript->pGossipHello = &GossipHello_npc_highlord_demitrian;
    pNewScript->pGossipSelect = &GossipSelect_npc_highlord_demitrian;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npcs_rutgar_and_frankal";
    pNewScript->pGossipHello = &GossipHello_npcs_rutgar_and_frankal;
    pNewScript->pGossipSelect = &GossipSelect_npcs_rutgar_and_frankal;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_anachronos_the_ancient";
    pNewScript->GetAI = &GetAI_npc_anachronos_the_ancient;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_crystalline_tear";
    pNewScript->pQuestAcceptGO = &QuestAcceptGO_crystalline_tear;
    pNewScript->RegisterSelf();
}