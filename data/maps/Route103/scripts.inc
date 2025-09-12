Route103_MapScripts::
# 2 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route103_EventScript_TryRemoveMilotic
	.byte 0


Route103_EventScript_TryRemoveMilotic::
# 6 "data/maps/Route103/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route103_EventScript_TryRemoveMilotic_1
	return

Route103_EventScript_TryRemoveMilotic_1:
# 7 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 8 "data/maps/Route103/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Route103_EventScript_TryRemoveMilotic_3
	return

Route103_EventScript_TryRemoveMilotic_3:
# 9 "data/maps/Route103/scripts.pory"
	removeobject VAR_LAST_TALKED
	return


Route103_EventScript_Milotic::
# 15 "data/maps/Route103/scripts.pory"
	lock
# 16 "data/maps/Route103/scripts.pory"
	faceplayer
# 17 "data/maps/Route103/scripts.pory"
	playmoncry SPECIES_MILOTIC, CRY_MODE_NORMAL
# 18 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_Milotic, MSGBOX_DEFAULT
# 19 "data/maps/Route103/scripts.pory"
	waitmoncry
# 20 "data/maps/Route103/scripts.pory"
	closemessage
# 21 "data/maps/Route103/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 22 "data/maps/Route103/scripts.pory"
	createmon 1, 0, SPECIES_MILOTIC, 35, move1 = MOVE_DRAINING_KISS, move2 = MOVE_WATER_PULSE, move3 = MOVE_DRAGON_TAIL, move4 = MOVE_AVALANCHE, abilityNum = 0, isShiny = FALSE
# 23 "data/maps/Route103/scripts.pory"
	special BattleSetup_StartBossBattle
# 24 "data/maps/Route103/scripts.pory"
	waitstate
# 25 "data/maps/Route103/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 26 "data/maps/Route103/scripts.pory"
	finditem ITEM_HM_DIVE
# 27 "data/maps/Route103/scripts.pory"
	setflag FLAG_BADGE07_GET
# 28 "data/maps/Route103/scripts.pory"
	release
	return


Route103_Text_Milotic::
# 31 "data/maps/Route103/scripts.pory"
	.string "Wow!\n"
	.string "This Pokémon is gorgeous!\p"
	.string "…\p"
	.string "Oh no!\n"
	.string "It's hostile!$"
