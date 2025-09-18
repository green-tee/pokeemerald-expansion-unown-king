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
	.2byte ITEM_NONE

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
