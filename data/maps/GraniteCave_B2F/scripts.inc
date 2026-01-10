GraniteCave_B2F_MapScripts::
# 2 "data/maps/GraniteCave_B2F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B2F_EventScript_TryRemoveDarkrai
	.byte 0


GraniteCave_B2F_EventScript_TryRemoveDarkrai::
# 6 "data/maps/GraniteCave_B2F/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, GraniteCave_B2F_EventScript_TryRemoveDarkrai_1
	return

GraniteCave_B2F_EventScript_TryRemoveDarkrai_1:
# 7 "data/maps/GraniteCave_B2F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 8 "data/maps/GraniteCave_B2F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GraniteCave_B2F_EventScript_TryRemoveDarkrai_3
	return

GraniteCave_B2F_EventScript_TryRemoveDarkrai_3:
# 9 "data/maps/GraniteCave_B2F/scripts.pory"
	removeobject VAR_LAST_TALKED
	return


GraniteCave_B2F_EventScript_Darkrai::
# 15 "data/maps/GraniteCave_B2F/scripts.pory"
	lock
# 16 "data/maps/GraniteCave_B2F/scripts.pory"
	faceplayer
# 17 "data/maps/GraniteCave_B2F/scripts.pory"
	playmoncry SPECIES_DARKRAI, CRY_MODE_NORMAL
# 18 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox GraniteCave_B2F_Text_Darkrai, MSGBOX_DEFAULT
# 19 "data/maps/GraniteCave_B2F/scripts.pory"
	waitmoncry
# 20 "data/maps/GraniteCave_B2F/scripts.pory"
	closemessage
# 21 "data/maps/GraniteCave_B2F/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 22 "data/maps/GraniteCave_B2F/scripts.pory"
	createmon 1, 0, SPECIES_DARKRAI, 30, move1 = MOVE_DARK_VOID, move2 = MOVE_NIGHTMARE, move3 = MOVE_DREAM_EATER, move4 = MOVE_DARK_PULSE, abilityNum = 0, isShiny = FALSE
# 23 "data/maps/GraniteCave_B2F/scripts.pory"
	special BattleSetup_StartBossBattle
# 24 "data/maps/GraniteCave_B2F/scripts.pory"
	waitstate
# 25 "data/maps/GraniteCave_B2F/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 26 "data/maps/GraniteCave_B2F/scripts.pory"
	giveitem ITEM_HM_FLASH
# 27 "data/maps/GraniteCave_B2F/scripts.pory"
	setflag FLAG_BADGE02_GET
# 28 "data/maps/GraniteCave_B2F/scripts.pory"
	release
	return


GraniteCave_B2F_Text_Darkrai::
# 31 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "Gasp!\n"
	.string "Something's coming out of the dark!$"
