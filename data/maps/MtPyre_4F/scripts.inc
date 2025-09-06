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

