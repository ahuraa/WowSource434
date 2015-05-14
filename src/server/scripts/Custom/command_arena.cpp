#include "ScriptPCH.h"
    #include "language.h"
     
    class pvp_tele_commandscript : public CommandScript
    {
    public:
        pvp_tele_commandscript() : CommandScript("pvp_tele_commandscript") { }
     
                ChatCommand* GetCommands() const
        {
            static ChatCommand pvpTeleCommandTable[] =
            {
                { "duel",      SEC_PLAYER,  false, &HandlepvpTeleCommand,             "", NULL },
                { "pvp",       SEC_PLAYER,  false, &HandlepvpTeleCommand,             "", NULL },
                { NULL,             0,                  false, NULL,                              "", NULL }
            };
                     return pvpTeleCommandTable;
        }
     
        static bool HandlepvpTeleCommand(ChatHandler* handler, const char* args)
        {
     
            Player* me = handler->GetSession()->GetPlayer();
     
            if (me->isInCombat())
            {
                handler->SendSysMessage(LANG_YOU_IN_COMBAT);
                handler->SetSentErrorMessage(true);
                return false;
            }
     
            // stop flight if need
            if (me->isInFlight())
            {
                me->GetMotionMaster()->MovementExpired();
                me->CleanupAfterTaxiFlight();
            }
            // save only in non-flight case
            else
                me->SaveRecallPosition();
     
                    me->TeleportTo(0, -13266.0048f, 158.5045f, 35.8074f, 1.0747f); // MapId, X, Y, Z, O, don't remove the "f" after X,Y,Z,O or it won't work.
            return true;
        }
    };
    void AddSC_pvp_commandscript()
    {
        new pvp_tele_commandscript();
    }