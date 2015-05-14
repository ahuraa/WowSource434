    /* Announce Login
    * Edited by: Bloodshark
    * (C)Nomsoftware 'Nomsoft' 2012-2013
    */
     
    #include "ScriptPCH.h"
     
    class announce_login : public PlayerScript
    {
    public:
        announce_login() : PlayerScript("announce_login") { }
     
        void onLogin(Player* player, bool /*loginFirst*/)
        {
            if (player->GetTeam() == ALLIANCE)
                    {
                std::ostringstream ss;
                            ss << "|cff3DAEFF[ Login Announcer ]|cffFFD800 : Player|cff4CFF00 " << player->GetName() << " |cffFFD800Has Online. This Player is|cff0026FF Alliance";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
				player->RemoveAllSpellCooldown(); //reset cooldowns on login!
				player->PlayDirectSound(11803, player);
                    }
                    else
                    {
                std::ostringstream ss;
                            ss << "|cff3DAEFF[ Login Announcer ]|cffFFD800 : Player|cff4CFF00 " << player->GetName() << " |cffFFD800Has Online. This Player is|cffFF0000 Horde" ;
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
				player->RemoveAllSpellCooldown(); //reset cooldowns on login!
				player->PlayDirectSound(11803, player);
                    }
            }
    };
     
    void AddSC_announce_login()
    {
        new announce_login;
    }