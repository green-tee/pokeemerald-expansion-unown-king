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


MtPyre_6F_Text_RockSmashTip::
# 21 "data/maps/MtPyre_6F/scripts.pory"
	.string "Those unwilling to take the bugs\n"
	.string "and the dragons from their haven\l"
	.string "can find luck in the rocks.$"
