Underwater_Route134_MapScripts::
# 2 "data/maps/Underwater_Route134/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route134_EventScript_TryRemoveKyogreAndUpdateCrystals
	.byte 0


Underwater_Route134_EventScript_TryRemoveKyogreAndUpdateCrystals::
# 6 "data/maps/Underwater_Route134/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, Underwater_Route134_EventScript_TryRemoveKyogreAndUpdateCrystals_1
	return

Underwater_Route134_EventScript_TryRemoveKyogreAndUpdateCrystals_1:
# 7 "data/maps/Underwater_Route134/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 8 "data/maps/Underwater_Route134/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Underwater_Route134_EventScript_TryRemoveKyogreAndUpdateCrystals_3
	return

Underwater_Route134_EventScript_TryRemoveKyogreAndUpdateCrystals_3:
# 9 "data/maps/Underwater_Route134/scripts.pory"
	removeobject VAR_LAST_TALKED
# 10 "data/maps/Underwater_Route134/scripts.pory"
	clearflag FLAG_HIDE_ABYSS_OF_THE_END_CRYSTAL_HEAL
# 11 "data/maps/Underwater_Route134/scripts.pory"
	setflag FLAG_HIDE_ABYSS_OF_THE_END_CRYSTAL_FAINT
	return


Underwater_Route134_EventScript_Kyogre::
# 17 "data/maps/Underwater_Route134/scripts.pory"
	lock
# 18 "data/maps/Underwater_Route134/scripts.pory"
	faceplayer
# 19 "data/maps/Underwater_Route134/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_NORMAL
# 20 "data/maps/Underwater_Route134/scripts.pory"
	msgbox Underwater_Route134_Text_Kyogre, MSGBOX_DEFAULT
# 21 "data/maps/Underwater_Route134/scripts.pory"
	waitmoncry
# 22 "data/maps/Underwater_Route134/scripts.pory"
	closemessage
# 23 "data/maps/Underwater_Route134/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 24 "data/maps/Underwater_Route134/scripts.pory"
	createmon 1, 0, SPECIES_KYOGRE, 42, move1 = MOVE_WATER_SPOUT, move2 = MOVE_ANCIENT_POWER, move3 = MOVE_ICE_BEAM, move4 = MOVE_SHEER_COLD, abilityNum = 0, isShiny = FALSE
# 25 "data/maps/Underwater_Route134/scripts.pory"
	special BattleSetup_StartBossBattle
# 26 "data/maps/Underwater_Route134/scripts.pory"
	waitstate
# 27 "data/maps/Underwater_Route134/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 28 "data/maps/Underwater_Route134/scripts.pory"
	giveitem ITEM_HM_WATERFALL
# 29 "data/maps/Underwater_Route134/scripts.pory"
	setflag FLAG_BADGE08_GET
# 30 "data/maps/Underwater_Route134/scripts.pory"
	release
	return


Underwater_Route134_Text_Kyogre::
# 33 "data/maps/Underwater_Route134/scripts.pory"
	.string "An imposing creature is attacking!$"
