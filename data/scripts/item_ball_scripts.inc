Common_EventScript_FindItem::
# 2 "data/scripts/item_ball_scripts.pory"
	callnative GetItemBallIdAndAmountFromTemplate
# 3 "data/scripts/item_ball_scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 4 "data/scripts/item_ball_scripts.pory"
	finditem VAR_RESULT, VAR_0x8009
# 5 "data/scripts/item_ball_scripts.pory"
	switch VAR_TEMP_0
# 6 "data/scripts/item_ball_scripts.pory"
	case ITEM_EXP_SHARE, Common_EventScript_FindItem_2
# 8 "data/scripts/item_ball_scripts.pory"
	case ITEM_LUCKY_CHARM, Common_EventScript_FindItem_3
	return

Common_EventScript_FindItem_2:
# 7 "data/scripts/item_ball_scripts.pory"
	setflag I_EXP_SHARE_FLAG
	return

Common_EventScript_FindItem_3:
# 9 "data/scripts/item_ball_scripts.pory"
	setflag FLAG_LUCKY_CHARM_ON
	return

