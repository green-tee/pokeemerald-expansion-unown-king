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

