MtPyre_4F_MapScripts::
# 2 "data/maps/MtPyre_4F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_4F_EventScript_TryRemoveFakeBoulderAfterBattle
# 3 "data/maps/MtPyre_4F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_4F_EventScript_TryRemoveFakeBoulderAfterWarp
	.byte 0


MtPyre_4F_EventScript_TryRemoveFakeBoulderAfterBattle::
# 7 "data/maps/MtPyre_4F/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtPyre_4F_EventScript_TryRemoveFakeBoulderAfterBattle_1
	return

MtPyre_4F_EventScript_TryRemoveFakeBoulderAfterBattle_1:
# 8 "data/maps/MtPyre_4F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 9 "data/maps/MtPyre_4F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq MtPyre_4F_EventScript_TryRemoveFakeBoulderAfterBattle_3
# 9 "data/maps/MtPyre_4F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MtPyre_4F_EventScript_TryRemoveFakeBoulderAfterBattle_3
	return

MtPyre_4F_EventScript_TryRemoveFakeBoulderAfterBattle_3:
# 10 "data/maps/MtPyre_4F/scripts.pory"
	removeobject VAR_LAST_TALKED
	return


MtPyre_4F_EventScript_TryRemoveFakeBoulderAfterWarp::
# 16 "data/maps/MtPyre_4F/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 17 "data/maps/MtPyre_4F/scripts.pory"
	compare VAR_TEMP_0, 4
	goto_if_eq MtPyre_4F_EventScript_TryRemoveFakeBoulderAfterWarp_2
	return

MtPyre_4F_EventScript_TryRemoveFakeBoulderAfterWarp_1:
# 18 "data/maps/MtPyre_4F/scripts.pory"
	setflag FLAG_TEMP_1C
	return

MtPyre_4F_EventScript_TryRemoveFakeBoulderAfterWarp_2:
# 17 "data/maps/MtPyre_4F/scripts.pory"
	compare VAR_TEMP_1, 5
	goto_if_eq MtPyre_4F_EventScript_TryRemoveFakeBoulderAfterWarp_1
	return


MtPyre_4F_EventScript_Inscription::
# 23 "data/maps/MtPyre_4F/scripts.pory"
	lock
# 24 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_DefeatTheDarkness, MSGBOX_UNOWNCRYPT
# 25 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 26 "data/maps/MtPyre_4F/scripts.pory"
	release
	return


MtPyre_4F_EventScript_MaidenAressia::
# 35 "data/maps/MtPyre_4F/scripts.pory"
	lock
# 36 "data/maps/MtPyre_4F/scripts.pory"
	faceplayer
# 37 "data/maps/MtPyre_4F/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, MtPyre_4F_EventScript_MaidenAressia_2
# 41 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_ImTheStrongestMaiden, MSGBOX_YESNO
# 42 "data/maps/MtPyre_4F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MtPyre_4F_EventScript_MaidenAressia_5
# 56 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 57 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_ISee, MSGBOX_DEFAULT
# 58 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
MtPyre_4F_EventScript_MaidenAressia_1:
# 61 "data/maps/MtPyre_4F/scripts.pory"
	release
	return

MtPyre_4F_EventScript_MaidenAressia_2:
# 38 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_BelieveInYourself, MSGBOX_DEFAULT
# 39 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
	goto MtPyre_4F_EventScript_MaidenAressia_1

MtPyre_4F_EventScript_MaidenAressia_5:
# 43 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 44 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_ShallWeBegin, MSGBOX_DEFAULT
# 45 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 46 "data/maps/MtPyre_4F/scripts.pory"
	playbgm MUS_VS_GYM_LEADER, FALSE
# 47 "data/maps/MtPyre_4F/scripts.pory"
	trainerbattle_no_intro TRAINER_MAIDEN4, MtPyre_4F_Text_MaidenAressiaDefeated
# 48 "data/maps/MtPyre_4F/scripts.pory"
	lock
# 49 "data/maps/MtPyre_4F/scripts.pory"
	faceplayer
# 50 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_WhatAnIncredibleBattle, MSGBOX_DEFAULT
# 51 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 52 "data/maps/MtPyre_4F/scripts.pory"
	giveitem ITEM_HM_SURF
# 53 "data/maps/MtPyre_4F/scripts.pory"
	setflag FLAG_BADGE05_GET
# 54 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_ThisIsAPowerfulMove, MSGBOX_DEFAULT
	goto MtPyre_4F_EventScript_MaidenAressia_1


MtPyre_4F_Text_DefeatTheDarkness::
# 29 "data/maps/MtPyre_4F/scripts.pory"
	.string "Those who wish to see clear\n"
	.string "must put out the darkness.$"

MtPyre_4F_Text_ImTheStrongestMaiden::
# 64 "data/maps/MtPyre_4F/scripts.pory"
	.string "Greetings, traveler!\p"
	.string "I am Aressia, the strongest of\n"
	.string "the four Maidens.\p"
	.string "I aid the worty ones by lending them\n"
	.string "the force of nature.\p"
	.string "Be warned, though: if you accept my\n"
	.string "gift, the road ahead will be a\l"
	.string "perilous one.\l"
	.string "That is why I must test your ability\l"
	.string "in battle more than my Sisters.\p"
	.string "Are you ready to fight?$"

MtPyre_4F_Text_ISee::
# 78 "data/maps/MtPyre_4F/scripts.pory"
	.string "I see.\n"
	.string "Take your time to prepare.$"

MtPyre_4F_Text_ShallWeBegin::
# 83 "data/maps/MtPyre_4F/scripts.pory"
	.string "Well then, shall we begin?$"

MtPyre_4F_Text_MaidenAressiaDefeated::
# 87 "data/maps/MtPyre_4F/scripts.pory"
	.string "Well done, traveler!\n"
	.string "You are indeed a worthy one.$"

MtPyre_4F_Text_WhatAnIncredibleBattle::
# 92 "data/maps/MtPyre_4F/scripts.pory"
	.string "What an incredible battle!\n"
	.string "You earned the power I promised:\l"
	.string "the ability to navigate the calm waters\l"
	.string "that cuddle this temple.\p"
	.string "Take it!$"

MtPyre_4F_Text_ThisIsAPowerfulMove::
# 100 "data/maps/MtPyre_4F/scripts.pory"
	.string "If you feel like teaching this move\n"
	.string "to one of your Pokémon, it is a \l"
	.string "powerful one. Pokémon that are weak to\l"
	.string "Water-type moves do not fare well\l"
	.string "against it.\p"
	.string "I must warn you again: from now on,\n"
	.string "you must always be on your toes.\p"
	.string "But I believe in you.\n"
	.string "You too, believe in yourself.$"

MtPyre_4F_Text_BelieveInYourself::
# 112 "data/maps/MtPyre_4F/scripts.pory"
	.string "I believe in you.\n"
	.string "You too, believe in yourself, always.$"
