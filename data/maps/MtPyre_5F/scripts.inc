MtPyre_5F_MapScripts::
	.byte 0


MtPyre_5F_EventScript_Inscription::
# 4 "data/maps/MtPyre_5F/scripts.pory"
	lock
# 5 "data/maps/MtPyre_5F/scripts.pory"
	msgbox MtPyre_5F_Text_WeHopeTheBadKingNeverRecovers, MSGBOX_UNOWNCRYPT
# 6 "data/maps/MtPyre_5F/scripts.pory"
	closemessage
# 7 "data/maps/MtPyre_5F/scripts.pory"
	release
	return


MtPyre_5F_EventScript_MaidenAphrosie::
# 23 "data/maps/MtPyre_5F/scripts.pory"
	lock
# 24 "data/maps/MtPyre_5F/scripts.pory"
	faceplayer
# 25 "data/maps/MtPyre_5F/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, MtPyre_5F_EventScript_MaidenAphrosie_2
# 29 "data/maps/MtPyre_5F/scripts.pory"
	goto_if_unset FLAG_TALKED_TO_APHROSIE, MtPyre_5F_EventScript_MaidenAphrosie_6
MtPyre_5F_EventScript_MaidenAphrosie_5:
# 33 "data/maps/MtPyre_5F/scripts.pory"
	msgbox MtPyre_5F_Text_YouMustSucceedInTwoTrials, MSGBOX_DEFAULT
# 34 "data/maps/MtPyre_5F/scripts.pory"
	closemessage
# 35 "data/maps/MtPyre_5F/scripts.pory"
	special IsGhostTypeInParty
# 36 "data/maps/MtPyre_5F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MtPyre_5F_EventScript_MaidenAphrosie_8
# 55 "data/maps/MtPyre_5F/scripts.pory"
	msgbox MtPyre_5F_Text_NoGhostTypes, MSGBOX_DEFAULT
# 56 "data/maps/MtPyre_5F/scripts.pory"
	closemessage
MtPyre_5F_EventScript_MaidenAphrosie_1:
# 59 "data/maps/MtPyre_5F/scripts.pory"
	release
	return

MtPyre_5F_EventScript_MaidenAphrosie_2:
# 26 "data/maps/MtPyre_5F/scripts.pory"
	msgbox MtPyre_5F_Text_ThereAreSmallTreesOutside, MSGBOX_DEFAULT
# 27 "data/maps/MtPyre_5F/scripts.pory"
	closemessage
	goto MtPyre_5F_EventScript_MaidenAphrosie_1

MtPyre_5F_EventScript_MaidenAphrosie_6:
# 30 "data/maps/MtPyre_5F/scripts.pory"
	msgbox MtPyre_5F_Text_OhATraveler, MSGBOX_DEFAULT
# 31 "data/maps/MtPyre_5F/scripts.pory"
	setflag FLAG_TALKED_TO_APHROSIE
	goto MtPyre_5F_EventScript_MaidenAphrosie_5

MtPyre_5F_EventScript_MaidenAphrosie_8:
# 37 "data/maps/MtPyre_5F/scripts.pory"
	msgbox MtPyre_5F_Text_YouHaveAGhostType, MSGBOX_YESNO
# 38 "data/maps/MtPyre_5F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MtPyre_5F_EventScript_MaidenAphrosie_11
# 51 "data/maps/MtPyre_5F/scripts.pory"
	msgbox MtPyre_5F_Text_HowDisappointing, MSGBOX_DEFAULT
# 52 "data/maps/MtPyre_5F/scripts.pory"
	closemessage
	goto MtPyre_5F_EventScript_MaidenAphrosie_1

MtPyre_5F_EventScript_MaidenAphrosie_11:
# 39 "data/maps/MtPyre_5F/scripts.pory"
	msgbox MtPyre_5F_Text_LetsNotWasteAnyMoreTime, MSGBOX_DEFAULT
# 40 "data/maps/MtPyre_5F/scripts.pory"
	closemessage
# 41 "data/maps/MtPyre_5F/scripts.pory"
	playbgm MUS_VS_GYM_LEADER, FALSE
# 42 "data/maps/MtPyre_5F/scripts.pory"
	trainerbattle_no_intro TRAINER_MAIDEN2, MtPyre_5F_Text_MaidenAphrosieDefeated
# 43 "data/maps/MtPyre_5F/scripts.pory"
	lock
# 44 "data/maps/MtPyre_5F/scripts.pory"
	faceplayer
# 45 "data/maps/MtPyre_5F/scripts.pory"
	msgbox MtPyre_5F_Text_YouPassedTheSecondTrial, MSGBOX_DEFAULT
# 46 "data/maps/MtPyre_5F/scripts.pory"
	giveitem ITEM_HM_CUT
# 47 "data/maps/MtPyre_5F/scripts.pory"
	setflag FLAG_BADGE01_GET
# 48 "data/maps/MtPyre_5F/scripts.pory"
	msgbox MtPyre_5F_Text_WithCutYouCanExplore, MSGBOX_DEFAULT
# 49 "data/maps/MtPyre_5F/scripts.pory"
	closemessage
	goto MtPyre_5F_EventScript_MaidenAphrosie_1


MtPyre_5F_Text_WeHopeTheBadKingNeverRecovers::
# 10 "data/maps/MtPyre_5F/scripts.pory"
	.string "We, the Imprisoners, hope with all\n"
	.string "our heart that the Bad King never\l"
	.string "recover from the tragic confrontation\l"
	.string "with the Good King.\p"
	.string "Its servants, who had weakened the\n"
	.string "Good King, were exhausted, yet almost\l"
	.string "unharmed.\p"
	.string "Our allies, on the other hand, were\n"
	.string "able to wound the Bad King.$"

MtPyre_5F_Text_OhATraveler::
# 62 "data/maps/MtPyre_5F/scripts.pory"
	.string "Oh! A traveler?\p"
	.string "Hello! I'm Aphrosie, the youngest\n"
	.string "of this temple's Maidens.\p"
	.string "I'm here to lend a hand to… uhm…\n"
	.string "the worthy ones, those who wish to\l"
	.string "see every nook and granny…\p"
	.string "No, let me try again.\n"
	.string "Cranny, not granny.\p"
	.string "Ahem!\p"
	.string "Those who wish to see every nook\n"
	.string "and cranny of this temple must first\l"
	.string "prove that they're worthy.\l"
	.string "I'm here to see if they are.\p"
	.string "Those judged worthy will receive help\n"
	.string "in order to venture deeper into this\l"
	.string "temple.$"

MtPyre_5F_Text_YouMustSucceedInTwoTrials::
# 81 "data/maps/MtPyre_5F/scripts.pory"
	.string "In order to be judged worthy, you must\n"
	.string "succeed in two trials.\l"
	.string "The first consists in finding a\l"
	.string "Ghost-type Pokémon. Did you bring one?$"

MtPyre_5F_Text_NoGhostTypes::
# 88 "data/maps/MtPyre_5F/scripts.pory"
	.string "…\p"
	.string "You don't have any Ghost-type Pokémon\n"
	.string "in your party. Come back with one!$"

MtPyre_5F_Text_YouHaveAGhostType::
# 94 "data/maps/MtPyre_5F/scripts.pory"
	.string "…\p"
	.string "Yes! There's a Ghost-type Pokémon\n"
	.string "in your party!\p"
	.string "Alright, here's the second trial:\n"
	.string "You must defeat me in battle!\l"
	.string "Shall we let our Pokémon fight?$"

MtPyre_5F_Text_HowDisappointing::
# 103 "data/maps/MtPyre_5F/scripts.pory"
	.string "Aw, how disappointing!\n"
	.string "Come back if you change your mind.\l"
	.string "Don't forget your Ghost-type Pokémon!$"

MtPyre_5F_Text_LetsNotWasteAnyMoreTime::
# 109 "data/maps/MtPyre_5F/scripts.pory"
	.string "Cool!\n"
	.string "Let's not waste any more time!$"

MtPyre_5F_Text_MaidenAphrosieDefeated::
# 114 "data/maps/MtPyre_5F/scripts.pory"
	.string "Huh, I lost!$"

MtPyre_5F_Text_YouPassedTheSecondTrial::
# 118 "data/maps/MtPyre_5F/scripts.pory"
	.string "I guess you passed the second trial too!\n"
	.string "That means, you're worthy!\p"
	.string "As a reward, I'll give you this:\n"
	.string "a Hidden Maneuver!$"

MtPyre_5F_Text_WithCutYouCanExplore::
# 125 "data/maps/MtPyre_5F/scripts.pory"
	.string "This Hidden Maneuver bears the power\n"
	.string "of Cut. In battle it's a mediocre move,\l"
	.string "but if you have a Pokémon that can\l"
	.string "learn it, you can cut down those\l"
	.string "annoying small trees that bar your way.\p"
	.string "Don't feel bad for the environment,\n"
	.string "they grow back in the bat of an eye.\l"
	.string "Nobody can explain why!\p"
	.string "Anyway, there aren't many of those trees\n"
	.string "inside the temple, but you can find\l"
	.string "a few more outside.$"

MtPyre_5F_Text_ThereAreSmallTreesOutside::
# 139 "data/maps/MtPyre_5F/scripts.pory"
	.string "There aren't many small trees inside the\n"
	.string "temple, but there are a few outside.\p"
	.string "Although I don't think you can go much\n"
	.string "far without aid from my older Sisters.$"
