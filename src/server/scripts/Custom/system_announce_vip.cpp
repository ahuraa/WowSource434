    /* Announce VIP
    * Edited by: lizard.tiny
    */
     
    #include "ScriptPCH.h"
     
    class announce_vip : public PlayerScript
    {
    public:
        announce_vip() : PlayerScript("announce_vip") { }
     
        void OnLogin(Player* player, bool /*loginFirst*/)
        {
            if (player->GetSession()->GetVipLevel())
                    {
                std::ostringstream ss;
                            ss << "|cffFF72EC[ VIP    Announcer ]|cffFFD800 : Player|cff4CFF00 " << player->GetName() << " |cffFFD800Is The |cffFF0000VIP|cffFFD800 Member";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
                    
					}
            }
    };
     
    void AddSC_announce_vip()
    {
        new announce_vip;
    }