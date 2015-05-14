/*
<--------------------------------------------------------------------------->
 - Developer(s): Made by ?? Edited by - Ghostcrawler336, Coth
 - Complete: 100%
 - ScriptName: 'Duel Reset' 
 - Comment: Not tested with latest ver but should work.
 - Updated - 15'th October 2013
<--------------------------------------------------------------------------->
*/
#include "ScriptPCH.h"
 
class DuelResetCooldown : public PlayerScript
{
        public:
                DuelResetCooldown() : PlayerScript("DuelResetCooldown"){}
 
                void OnDuelEnd(Player* Plr, Player* Plr2, DuelCompleteType /*type*/)
                {
                        Plr->SetHealth(Plr->GetMaxHealth());
                        Plr->RemoveArenaSpellCooldowns();
                        Plr->ResetAllPowers();
                        Plr2->SetHealth(Plr2->GetMaxHealth());
                        Plr2->RemoveArenaSpellCooldowns();
                        Plr2->ResetAllPowers();
                }
};
 
void AddSC_DuelResetCooldown()
{
        new DuelResetCooldown();
}