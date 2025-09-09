FieryPath_MapScripts::
# 2 "data/maps/FieryPath/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FieryPath_EventScript_TryRemoveFakeBoulder
	.byte 0


FieryPath_EventScript_TryRemoveFakeBoulder::
# 6 "data/maps/FieryPath/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, FieryPath_EventScript_TryRemoveFakeBoulder_1
	return

FieryPath_EventScript_TryRemoveFakeBoulder_1:
# 7 "data/maps/FieryPath/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 8 "data/maps/FieryPath/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FieryPath_EventScript_TryRemoveFakeBoulder_3
# 8 "data/maps/FieryPath/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FieryPath_EventScript_TryRemoveFakeBoulder_3
	return

FieryPath_EventScript_TryRemoveFakeBoulder_3:
# 9 "data/maps/FieryPath/scripts.pory"
	removeobject VAR_LAST_TALKED
	return


FieryPath_EventScript_Inscription::
# 15 "data/maps/FieryPath/scripts.pory"
	lock
# 16 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_WaysOfWater, MSGBOX_UNOWNCRYPT
# 17 "data/maps/FieryPath/scripts.pory"
	closemessage
# 18 "data/maps/FieryPath/scripts.pory"
	release
	return


FieryPath_Text_WaysOfWater::
# 21 "data/maps/FieryPath/scripts.pory"
	.string "Only those who truly master the ways\n"
	.string "of water can explore this temple\l"
	.string "to the fullest.\p"
	.string "This hallway is connected to one\n"
	.string "of the aquatic caverns.$"
