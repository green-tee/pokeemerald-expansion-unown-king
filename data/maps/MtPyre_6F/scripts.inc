MtPyre_6F_MapScripts::
# 2 "data/maps/MtPyre_6F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_6F_TryRemoveFakeBoulder
	.byte 0


MtPyre_6F_TryRemoveFakeBoulder::
# 6 "data/maps/MtPyre_6F/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtPyre_6F_TryRemoveFakeBoulder_1
	return

MtPyre_6F_TryRemoveFakeBoulder_1:
# 7 "data/maps/MtPyre_6F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 8 "data/maps/MtPyre_6F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq MtPyre_6F_TryRemoveFakeBoulder_3
# 8 "data/maps/MtPyre_6F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MtPyre_6F_TryRemoveFakeBoulder_3
	return

MtPyre_6F_TryRemoveFakeBoulder_3:
# 9 "data/maps/MtPyre_6F/scripts.pory"
	removeobject VAR_LAST_TALKED
	return


MtPyre_6F_EventScript_Inscription::
# 15 "data/maps/MtPyre_6F/scripts.pory"
	lock
# 16 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_Text_RockSmashTip, MSGBOX_UNOWNCRYPT
# 17 "data/maps/MtPyre_6F/scripts.pory"
	closemessage
# 18 "data/maps/MtPyre_6F/scripts.pory"
	release
	return


MtPyre_6F_EventScript_StoneMerchant::
# 28 "data/maps/MtPyre_6F/scripts.pory"
	lockall
# 29 "data/maps/MtPyre_6F/scripts.pory"
	applymovement LOCALID_STONE_MERCHANT, Common_Movement_FacePlayer
# 30 "data/maps/MtPyre_6F/scripts.pory"
	waitmovement 0
# 31 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_EventScript_BuySomeStones, MSGBOX_DEFAULT
# 32 "data/maps/MtPyre_6F/scripts.pory"
	pokemart MtPyre_6F_Mart_Stones
# 33 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_EventScript_SeeYouAgain, MSGBOX_DEFAULT
# 34 "data/maps/MtPyre_6F/scripts.pory"
	closemessage
# 35 "data/maps/MtPyre_6F/scripts.pory"
	releaseall
	return


	.align 2
# 48 "data/maps/MtPyre_6F/scripts.pory"
MtPyre_6F_Mart_Stones:
# 49 "data/maps/MtPyre_6F/scripts.pory"
	.2byte ITEM_FIRE_STONE
# 50 "data/maps/MtPyre_6F/scripts.pory"
	.2byte ITEM_WATER_STONE
# 51 "data/maps/MtPyre_6F/scripts.pory"
	.2byte ITEM_DAWN_STONE
# 52 "data/maps/MtPyre_6F/scripts.pory"
	.2byte ITEM_MOON_STONE
	.2byte ITEM_NONE

MtPyre_6F_EventScript_PsychicM::
# 56 "data/maps/MtPyre_6F/scripts.pory"
	lock
# 57 "data/maps/MtPyre_6F/scripts.pory"
	faceplayer
# 58 "data/maps/MtPyre_6F/scripts.pory"
	goto_if_set FLAG_TEMP_1, MtPyre_6F_EventScript_PsychicM_2
# 62 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_Text_ISenseYourDesire, MSGBOX_YESNO
# 63 "data/maps/MtPyre_6F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MtPyre_6F_EventScript_PsychicM_5
# 72 "data/maps/MtPyre_6F/scripts.pory"
	closemessage
MtPyre_6F_EventScript_PsychicM_1:
# 75 "data/maps/MtPyre_6F/scripts.pory"
	release
	return

MtPyre_6F_EventScript_PsychicM_2:
# 59 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_ImLookingForwardToRematch, MSGBOX_DEFAULT
# 60 "data/maps/MtPyre_6F/scripts.pory"
	closemessage
	goto MtPyre_6F_EventScript_PsychicM_1

MtPyre_6F_EventScript_PsychicM_5:
# 64 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_Text_LetsGo, MSGBOX_DEFAULT
# 65 "data/maps/MtPyre_6F/scripts.pory"
	closemessage
# 66 "data/maps/MtPyre_6F/scripts.pory"
	playbgm MUS_VS_WILD, FALSE
# 67 "data/maps/MtPyre_6F/scripts.pory"
	trainerbattle_no_intro TRAINER_PSYCHIC_SIGMUND, MtPyre_6F_WhatABitterDefeat
# 68 "data/maps/MtPyre_6F/scripts.pory"
	setflag FLAG_TEMP_1
# 69 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_YouAreAmazing, MSGBOX_DEFAULT
# 70 "data/maps/MtPyre_6F/scripts.pory"
	closemessage
	goto MtPyre_6F_EventScript_PsychicM_1


MtPyre_6F_EventScript_PsychicFSouth::
# 104 "data/maps/MtPyre_6F/scripts.pory"
	lock
# 105 "data/maps/MtPyre_6F/scripts.pory"
	faceplayer
# 106 "data/maps/MtPyre_6F/scripts.pory"
	goto_if_set FLAG_TEMP_2, MtPyre_6F_EventScript_PsychicFSouth_2
# 110 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_Text_WhatsTheMatter, MSGBOX_YESNO
# 111 "data/maps/MtPyre_6F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MtPyre_6F_EventScript_PsychicFSouth_5
# 120 "data/maps/MtPyre_6F/scripts.pory"
	closemessage
MtPyre_6F_EventScript_PsychicFSouth_1:
# 123 "data/maps/MtPyre_6F/scripts.pory"
	release
	return

MtPyre_6F_EventScript_PsychicFSouth_2:
# 107 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_Text_IfYouComeBack, MSGBOX_DEFAULT
# 108 "data/maps/MtPyre_6F/scripts.pory"
	closemessage
	goto MtPyre_6F_EventScript_PsychicFSouth_1

MtPyre_6F_EventScript_PsychicFSouth_5:
# 112 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_Text_LetsHaveSomeFun, MSGBOX_DEFAULT
# 113 "data/maps/MtPyre_6F/scripts.pory"
	closemessage
# 114 "data/maps/MtPyre_6F/scripts.pory"
	playbgm MUS_VS_WILD, FALSE
# 115 "data/maps/MtPyre_6F/scripts.pory"
	trainerbattle_no_intro TRAINER_PSYCHIC_LAURA, MtPyre_6F_Text_LosingIsPartOfTheHobby
# 116 "data/maps/MtPyre_6F/scripts.pory"
	setflag FLAG_TEMP_2
# 117 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_Text_OhWell, MSGBOX_DEFAULT
# 118 "data/maps/MtPyre_6F/scripts.pory"
	closemessage
	goto MtPyre_6F_EventScript_PsychicFSouth_1


MtPyre_6F_EventScript_PsychicFCenter::
# 153 "data/maps/MtPyre_6F/scripts.pory"
	trainerbattle_single TRAINER_PSYCHIC_ELLIE, MtPyre_6F_Text_IForesaw, MtPyre_6F_Text_MyPredictionsWereWrong
# 154 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_Text_GolduckIsntPsychich, MSGBOX_AUTOCLOSE
	return


MtPyre_6F_EventScript_Fighter::
# 173 "data/maps/MtPyre_6F/scripts.pory"
	trainerbattle_single TRAINER_FIGHTER_STEPHANIE, MtPyre_6F_Text_YouKnowTheRules, MtPyre_6F_Text_NeverGonnaGiveUp
# 174 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_Text_Ditto, MSGBOX_AUTOCLOSE
	return


MtPyre_6F_Text_RockSmashTip::
# 21 "data/maps/MtPyre_6F/scripts.pory"
	.string "Those unwilling to take the bugs\n"
	.string "and the dragons from their haven\l"
	.string "can find luck in the rocks.$"

MtPyre_6F_EventScript_BuySomeStones::
# 38 "data/maps/MtPyre_6F/scripts.pory"
	.string "Hello, traveler.\n"
	.string "I've got some rare stones here.\l"
	.string "Do you want to buy some?$"

MtPyre_6F_EventScript_SeeYouAgain::
# 44 "data/maps/MtPyre_6F/scripts.pory"
	.string "Step by again!$"

MtPyre_6F_Text_ISenseYourDesire::
# 78 "data/maps/MtPyre_6F/scripts.pory"
	.string "I sense your desire to have a battle.\n"
	.string "Can I be your opponent?$"

MtPyre_6F_Text_LetsGo::
# 83 "data/maps/MtPyre_6F/scripts.pory"
	.string "Let's go!$"

MtPyre_6F_WhatABitterDefeat::
# 87 "data/maps/MtPyre_6F/scripts.pory"
	.string "Oh, what a bitter defeat!\n"
	.string "Alas, I must hand it to you.$"

MtPyre_6F_YouAreAmazing::
# 92 "data/maps/MtPyre_6F/scripts.pory"
	.string "You're amazing! I'm even more\n"
	.string "motivated to defeat you, if we\l"
	.string "battle again.$"

MtPyre_6F_ImLookingForwardToRematch::
# 98 "data/maps/MtPyre_6F/scripts.pory"
	.string "I'm looking forward to having a\n"
	.string "rematch against you!$"

MtPyre_6F_Text_WhatsTheMatter::
# 126 "data/maps/MtPyre_6F/scripts.pory"
	.string "What's the matter?\n"
	.string "A battle, right now?\l"
	.string "Yes, count me in.$"

MtPyre_6F_Text_LetsHaveSomeFun::
# 132 "data/maps/MtPyre_6F/scripts.pory"
	.string "Let's have some fun!$"

MtPyre_6F_Text_LosingIsPartOfTheHobby::
# 136 "data/maps/MtPyre_6F/scripts.pory"
	.string "Taking some losses comes with\n"
	.string "the territory in our hobby.$"

MtPyre_6F_Text_OhWell::
# 141 "data/maps/MtPyre_6F/scripts.pory"
	.string "Oh, well. I'll do better\n"
	.string "next time!$"

MtPyre_6F_Text_IfYouComeBack::
# 146 "data/maps/MtPyre_6F/scripts.pory"
	.string "If you come back and you're\n"
	.string "in the mood for another battle,\l"
	.string "I'll gladly take you on again.$"

MtPyre_6F_Text_IForesaw::
# 157 "data/maps/MtPyre_6F/scripts.pory"
	.string "I foresaw you coming to me,\n"
	.string "now I challenge you to a battle!$"

MtPyre_6F_Text_MyPredictionsWereWrong::
# 162 "data/maps/MtPyre_6F/scripts.pory"
	.string "But… But… My predictions!\n"
	.string "They were wrong?!$"

MtPyre_6F_Text_GolduckIsntPsychich::
# 167 "data/maps/MtPyre_6F/scripts.pory"
	.string "What do you mean, Golduck isn't a\n"
	.string "Psychic-type?$"

MtPyre_6F_Text_YouKnowTheRules::
# 177 "data/maps/MtPyre_6F/scripts.pory"
	.string "You know the rules, when two Trainers'\n"
	.string "eyes meet…$"

MtPyre_6F_Text_NeverGonnaGiveUp::
# 182 "data/maps/MtPyre_6F/scripts.pory"
	.string "I'm never gonna give up!\n"
	.string "Not for a single loss!$"

MtPyre_6F_Text_Ditto::
# 187 "data/maps/MtPyre_6F/scripts.pory"
	.string "Is it just me, or are Ditto\n"
	.string "almost everywhere?$"
