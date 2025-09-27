MtPyre_Exterior_MapScripts::
# 2 "data/maps/MtPyre_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_Exterior_EventScript_TryRemoveLatiosOrLatias
# 3 "data/maps/MtPyre_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_EventScript_TryShowLatiosLatias
	.byte 0


MtPyre_Exterior_EventScript_TryRemoveLatiosOrLatias::
# 9 "data/maps/MtPyre_Exterior/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtPyre_Exterior_EventScript_TryRemoveLatiosOrLatias_1
	return

MtPyre_Exterior_EventScript_TryRemoveLatiosOrLatias_1:
# 10 "data/maps/MtPyre_Exterior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 11 "data/maps/MtPyre_Exterior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq MtPyre_Exterior_EventScript_TryRemoveLatiosOrLatias_3
# 11 "data/maps/MtPyre_Exterior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MtPyre_Exterior_EventScript_TryRemoveLatiosOrLatias_3
	return

MtPyre_Exterior_EventScript_TryRemoveLatiosOrLatias_3:
# 12 "data/maps/MtPyre_Exterior/scripts.pory"
	removeobject VAR_LAST_TALKED
	return


MtPyre_Exterior_EventScript_TryShowLatiosLatias::
# 18 "data/maps/MtPyre_Exterior/scripts.pory"
	goto_if_set FLAG_HIDE_LATIOS, MtPyre_Exterior_EventScript_TryShowLatiosLatias_3
MtPyre_Exterior_EventScript_TryShowLatiosLatias_1:
# 21 "data/maps/MtPyre_Exterior/scripts.pory"
	goto_if_set FLAG_HIDE_LATIAS, MtPyre_Exterior_EventScript_TryShowLatiosLatias_7
	return

MtPyre_Exterior_EventScript_TryShowLatiosLatias_2:
# 19 "data/maps/MtPyre_Exterior/scripts.pory"
	clearflag FLAG_HIDE_LATIOS
	goto MtPyre_Exterior_EventScript_TryShowLatiosLatias_1

MtPyre_Exterior_EventScript_TryShowLatiosLatias_3:
# 18 "data/maps/MtPyre_Exterior/scripts.pory"
	goto_if_unset FLAG_CAUGHT_LATIOS, MtPyre_Exterior_EventScript_TryShowLatiosLatias_2
	goto MtPyre_Exterior_EventScript_TryShowLatiosLatias_1

MtPyre_Exterior_EventScript_TryShowLatiosLatias_6:
# 22 "data/maps/MtPyre_Exterior/scripts.pory"
	clearflag FLAG_HIDE_LATIAS
	return

MtPyre_Exterior_EventScript_TryShowLatiosLatias_7:
# 21 "data/maps/MtPyre_Exterior/scripts.pory"
	goto_if_unset FLAG_CAUGHT_LATIAS, MtPyre_Exterior_EventScript_TryShowLatiosLatias_6
	return


MtPyre_Exterior_EventScript_LatiosOrLatias::
# 27 "data/maps/MtPyre_Exterior/scripts.pory"
	lock
# 28 "data/maps/MtPyre_Exterior/scripts.pory"
	faceplayer
# 29 "data/maps/MtPyre_Exterior/scripts.pory"
	call MtPyre_Exterior_EventScript_LatiosOrLatias_Cry
# 30 "data/maps/MtPyre_Exterior/scripts.pory"
	msgbox MtPyre_Exterior_Text_FightLatiosOrLatias, MSGBOX_YESNO
# 31 "data/maps/MtPyre_Exterior/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MtPyre_Exterior_EventScript_LatiosOrLatias_2
# 45 "data/maps/MtPyre_Exterior/scripts.pory"
	closemessage
MtPyre_Exterior_EventScript_LatiosOrLatias_1:
# 47 "data/maps/MtPyre_Exterior/scripts.pory"
	release
	return

MtPyre_Exterior_EventScript_LatiosOrLatias_2:
# 32 "data/maps/MtPyre_Exterior/scripts.pory"
	closemessage
# 33 "data/maps/MtPyre_Exterior/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 34 "data/maps/MtPyre_Exterior/scripts.pory"
	call MtPyre_Exterior_EventScript_LatiosOrLatias_SetBattle
# 35 "data/maps/MtPyre_Exterior/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 36 "data/maps/MtPyre_Exterior/scripts.pory"
	waitstate
# 37 "data/maps/MtPyre_Exterior/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 38 "data/maps/MtPyre_Exterior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 39 "data/maps/MtPyre_Exterior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq MtPyre_Exterior_EventScript_LatiosOrLatias_5
	goto MtPyre_Exterior_EventScript_LatiosOrLatias_1

MtPyre_Exterior_EventScript_LatiosOrLatias_5:
# 40 "data/maps/MtPyre_Exterior/scripts.pory"
	call MtPyre_Exterior_EventScript_LatiosOrLatias_CaughtFlag
# 41 "data/maps/MtPyre_Exterior/scripts.pory"
	call MtPyre_Exterior_EventScript_LatiosOrLatias_SoulDew
	goto MtPyre_Exterior_EventScript_LatiosOrLatias_1


MtPyre_Exterior_EventScript_LatiosOrLatias_Cry:
# 51 "data/maps/MtPyre_Exterior/scripts.pory"
	switch VAR_LAST_TALKED
# 52 "data/maps/MtPyre_Exterior/scripts.pory"
	case LOCALID_LATIOS, MtPyre_Exterior_EventScript_LatiosOrLatias_Cry_2
# 54 "data/maps/MtPyre_Exterior/scripts.pory"
	case LOCALID_LATIAS, MtPyre_Exterior_EventScript_LatiosOrLatias_Cry_3
	return

MtPyre_Exterior_EventScript_LatiosOrLatias_Cry_2:
# 53 "data/maps/MtPyre_Exterior/scripts.pory"
	playmoncry SPECIES_LATIOS, CRY_MODE_NORMAL
	return

MtPyre_Exterior_EventScript_LatiosOrLatias_Cry_3:
# 55 "data/maps/MtPyre_Exterior/scripts.pory"
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
	return


MtPyre_Exterior_EventScript_LatiosOrLatias_SetBattle:
# 60 "data/maps/MtPyre_Exterior/scripts.pory"
	switch VAR_LAST_TALKED
# 61 "data/maps/MtPyre_Exterior/scripts.pory"
	case LOCALID_LATIOS, MtPyre_Exterior_EventScript_LatiosOrLatias_SetBattle_2
# 63 "data/maps/MtPyre_Exterior/scripts.pory"
	case LOCALID_LATIAS, MtPyre_Exterior_EventScript_LatiosOrLatias_SetBattle_3
# 66 "data/maps/MtPyre_Exterior/scripts.pory"
	setwildbattle SPECIES_HAXORUS, 45, item = ITEM_MAX_REVIVE
	return

MtPyre_Exterior_EventScript_LatiosOrLatias_SetBattle_2:
# 62 "data/maps/MtPyre_Exterior/scripts.pory"
	setwildbattle SPECIES_LATIOS, 45, item = ITEM_MAX_REVIVE
	return

MtPyre_Exterior_EventScript_LatiosOrLatias_SetBattle_3:
# 64 "data/maps/MtPyre_Exterior/scripts.pory"
	setwildbattle SPECIES_LATIAS, 45, item = ITEM_MAX_REVIVE
	return


MtPyre_Exterior_EventScript_LatiosOrLatias_CaughtFlag:
# 71 "data/maps/MtPyre_Exterior/scripts.pory"
	switch VAR_LAST_TALKED
# 72 "data/maps/MtPyre_Exterior/scripts.pory"
	case LOCALID_LATIOS, MtPyre_Exterior_EventScript_LatiosOrLatias_CaughtFlag_2
# 74 "data/maps/MtPyre_Exterior/scripts.pory"
	case LOCALID_LATIAS, MtPyre_Exterior_EventScript_LatiosOrLatias_CaughtFlag_3
	return

MtPyre_Exterior_EventScript_LatiosOrLatias_CaughtFlag_2:
# 73 "data/maps/MtPyre_Exterior/scripts.pory"
	setflag FLAG_CAUGHT_LATIOS
	return

MtPyre_Exterior_EventScript_LatiosOrLatias_CaughtFlag_3:
# 75 "data/maps/MtPyre_Exterior/scripts.pory"
	setflag FLAG_CAUGHT_LATIAS
	return


MtPyre_Exterior_EventScript_LatiosOrLatias_SoulDew:
# 80 "data/maps/MtPyre_Exterior/scripts.pory"
	switch VAR_LAST_TALKED
# 81 "data/maps/MtPyre_Exterior/scripts.pory"
	case LOCALID_LATIOS, MtPyre_Exterior_EventScript_LatiosOrLatias_SoulDew_2
# 84 "data/maps/MtPyre_Exterior/scripts.pory"
	case LOCALID_LATIAS, MtPyre_Exterior_EventScript_LatiosOrLatias_SoulDew_3
	return

MtPyre_Exterior_EventScript_LatiosOrLatias_SoulDew_2:
# 82 "data/maps/MtPyre_Exterior/scripts.pory"
	clearflag FLAG_ITEM_LATIOS_SOUL_DEW
# 83 "data/maps/MtPyre_Exterior/scripts.pory"
	showobjectat LOCALID_LATIOS_SOUL_DEW, MAP_MT_PYRE_EXTERIOR
	return

MtPyre_Exterior_EventScript_LatiosOrLatias_SoulDew_3:
# 85 "data/maps/MtPyre_Exterior/scripts.pory"
	clearflag FLAG_ITEM_LATIAS_SOUL_DEW
# 86 "data/maps/MtPyre_Exterior/scripts.pory"
	showobjectat LOCALID_LATIAS_SOUL_DEW, MAP_MT_PYRE_EXTERIOR
	return


MtPyre_Exterior_EventScript_GoToFinalBoss::
# 97 "data/maps/MtPyre_Exterior/scripts.pory"
	lockall
# 98 "data/maps/MtPyre_Exterior/scripts.pory"
	message MtPyre_Exterior_Text_WantToGoToFinalBoss
# 99 "data/maps/MtPyre_Exterior/scripts.pory"
	waitmessage
# 100 "data/maps/MtPyre_Exterior/scripts.pory"
	dynmultichoice 16, 8, TRUE, 2, 1, DYN_MULTICHOICE_CB_NONE, Multichoice_Option_GoAhead, Multichoice_Option_GoBack
# 101 "data/maps/MtPyre_Exterior/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MtPyre_Exterior_EventScript_GoToFinalBoss_1
# 112 "data/maps/MtPyre_Exterior/scripts.pory"
	closemessage
# 113 "data/maps/MtPyre_Exterior/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Exterior_Movement_GoBack
# 114 "data/maps/MtPyre_Exterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 115 "data/maps/MtPyre_Exterior/scripts.pory"
	releaseall
	return

MtPyre_Exterior_EventScript_GoToFinalBoss_1:
# 103 "data/maps/MtPyre_Exterior/scripts.pory"
	closemessage
# 104 "data/maps/MtPyre_Exterior/scripts.pory"
	msgbox MtPyre_Exterior_Text_GoodLuck, MSGBOX_DEFAULT
# 105 "data/maps/MtPyre_Exterior/scripts.pory"
	closemessage
# 106 "data/maps/MtPyre_Exterior/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Exterior_Movement_GoForth
# 107 "data/maps/MtPyre_Exterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 108 "data/maps/MtPyre_Exterior/scripts.pory"
	warp MAP_MT_PYRE_SUMMIT, 15, 30
# 109 "data/maps/MtPyre_Exterior/scripts.pory"
	waitstate
	return


# 144 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_Movement_GoForth:
# 145 "data/maps/MtPyre_Exterior/scripts.pory"
	walk_up
	step_end

# 148 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_Movement_GoBack:
# 149 "data/maps/MtPyre_Exterior/scripts.pory"
	walk_down
# 149 "data/maps/MtPyre_Exterior/scripts.pory"
	walk_down
	step_end

MtPyre_Exterior_Text_FightLatiosOrLatias::
# 90 "data/maps/MtPyre_Exterior/scripts.pory"
	.string "This Pokémon is staring at you\n"
	.string "with a smile on its face.\l"
	.string "Will you fight it?$"

MtPyre_Exterior_Text_WantToGoToFinalBoss::
# 119 "data/maps/MtPyre_Exterior/scripts.pory"
	.string "Hold on a second!\n"
	.string "Ahead lies the end of your quest.\p"
	.string "Once you cross this line, you won't be\n"
	.string "able to come back. The only options are\l"
	.string "victory or defeat.\p"
	.string "Losing the final battle will take you\n"
	.string "to the title screen.\p"
	.string "If you wish to save your game, go back\n"
	.string "before stepping forward.\p"
	.string "What will you do?$"

Multichoice_Option_GoAhead::
# 132 "data/maps/MtPyre_Exterior/scripts.pory"
	.string "I'm going ahead!$"

Multichoice_Option_GoBack::
# 136 "data/maps/MtPyre_Exterior/scripts.pory"
	.string "I'm not ready.$"

MtPyre_Exterior_Text_GoodLuck::
# 140 "data/maps/MtPyre_Exterior/scripts.pory"
	.string "Good luck!$"
