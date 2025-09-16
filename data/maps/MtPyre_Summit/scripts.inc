MtPyre_Summit_MapScripts::
# 2 "data/maps/MtPyre_Summit/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_Summit_EventScript_TryRemoveUnown
# 3 "data/maps/MtPyre_Summit/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MtPyre_Summit_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 6 "data/maps/MtPyre_Summit/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtPyre_Summit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

MtPyre_Summit_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 4 "data/maps/MtPyre_Summit/scripts.pory"
	map_script_2 VAR_UNOWN_KING_PRISON_STATE, 0, MtPyre_Summit_EventScript_FacePlayerNorth
	.2byte 0

MtPyre_Summit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/MtPyre_Summit/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, MtPyre_Summit_EventScript_StartFinalBossSequence
	.2byte 0


MtPyre_Summit_EventScript_TryRemoveUnown::
# 12 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtPyre_Summit_EventScript_TryRemoveUnown_1
	return

MtPyre_Summit_EventScript_TryRemoveUnown_1:
# 13 "data/maps/MtPyre_Summit/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MtPyre_Summit_EventScript_TryRemoveUnown_3
	return

MtPyre_Summit_EventScript_TryRemoveUnown_3:
# 15 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_UNOWN_BOTTOM_LEFT
# 16 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_UNOWN_MIDDLE_LEFT
# 17 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_UNOWN_TOP_LEFT
# 18 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_UNOWN_BOTTOM_RIGHT
# 19 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_UNOWN_MIDDLE_RIGHT
# 20 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_UNOWN_TOP_RIGHT
	return


MtPyre_Summit_EventScript_FacePlayerNorth::
# 26 "data/maps/MtPyre_Summit/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	return


MtPyre_Summit_EventScript_StartFinalBossSequence::
# 30 "data/maps/MtPyre_Summit/scripts.pory"
	lockplayer
# 31 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_TEMP_0, 1
# 32 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_WalkToFinalBoss1
# 33 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement LOCALID_PLAYER
# 34 "data/maps/MtPyre_Summit/scripts.pory"
	delay 30
# 35 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_WalkToFinalBoss2
# 36 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement LOCALID_PLAYER
# 37 "data/maps/MtPyre_Summit/scripts.pory"
	playbgm MUS_VS_ELITE_FOUR, FALSE
# 38 "data/maps/MtPyre_Summit/scripts.pory"
	playse SE_PIN
# 39 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_Surprised
# 40 "data/maps/MtPyre_Summit/scripts.pory"
	special SpawnCameraObject
# 41 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_CAMERA, MtPyre_Summit_Movement_PanCameraToUnownKing
# 42 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement LOCALID_CAMERA
# 43 "data/maps/MtPyre_Summit/scripts.pory"
	special RemoveCameraObject
# 44 "data/maps/MtPyre_Summit/scripts.pory"
	delay 60
# 45 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WorthlessHuman, MSGBOX_DEFAULT
# 46 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 47 "data/maps/MtPyre_Summit/scripts.pory"
	delay 60
# 48 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_YouWantToDefeatMe, MSGBOX_DEFAULT
# 49 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 50 "data/maps/MtPyre_Summit/scripts.pory"
	call MtPyre_Summit_EventScript_UnownSurroundPlayer
# 51 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 52 "data/maps/MtPyre_Summit/scripts.pory"
	call MtPyre_Summit_EventScript_DoUnownKingBattle
# 53 "data/maps/MtPyre_Summit/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 54 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
	return


# 57 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_WalkToFinalBoss1:
# 58 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 58 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 58 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
	step_end

# 61 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_WalkToFinalBoss2:
# 62 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 62 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 62 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 62 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 62 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 62 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 62 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
	step_end

# 65 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_Surprised:
# 66 "data/maps/MtPyre_Summit/scripts.pory"
	emote_exclamation_mark
	step_end

# 69 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PanCameraToUnownKing:
# 70 "data/maps/MtPyre_Summit/scripts.pory"
	walk_slow_up
# 70 "data/maps/MtPyre_Summit/scripts.pory"
	walk_slow_up
# 70 "data/maps/MtPyre_Summit/scripts.pory"
	walk_slow_up
	step_end

MtPyre_Summit_EventScript_UnownSurroundPlayer::
# 109 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 110 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_LEFT, MtPyre_Summit_Movement_UnownDown
# 111 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 112 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 113 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_MIDDLE_LEFT, MtPyre_Summit_Movement_UnownDown
# 114 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_LEFT, MtPyre_Summit_Movement_UnownDown
# 115 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 116 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 117 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_RIGHT, MtPyre_Summit_Movement_UnownDown
# 118 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_BOTTOM_LEFT, MtPyre_Summit_Movement_UnownDown
# 119 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_MIDDLE_LEFT, MtPyre_Summit_Movement_UnownDown
# 120 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_LEFT, MtPyre_Summit_Movement_UnownDown
# 121 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 122 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 123 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_MIDDLE_RIGHT, MtPyre_Summit_Movement_UnownDown
# 124 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_RIGHT, MtPyre_Summit_Movement_UnownDown
# 125 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_BOTTOM_LEFT, MtPyre_Summit_Movement_UnownDown
# 126 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_MIDDLE_LEFT, MtPyre_Summit_Movement_UnownDown
# 127 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_LEFT, MtPyre_Summit_Movement_UnownDown
# 128 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 129 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 130 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_BOTTOM_RIGHT, MtPyre_Summit_Movement_SurroundFromBottomRight
# 131 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_BOTTOM_LEFT, MtPyre_Summit_Movement_SurroundFromBottomLeft
# 132 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_MIDDLE_RIGHT, MtPyre_Summit_Movement_SurroundFromMiddleRight
# 133 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_MIDDLE_LEFT, MtPyre_Summit_Movement_SurroundFromMiddleLeft
# 134 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_RIGHT, MtPyre_Summit_Movement_SurroundFromTopRight
# 135 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_LEFT, MtPyre_Summit_Movement_SurroundFromTopLeft
# 136 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
	return


# 139 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_UnownDown:
# 140 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_down
	step_end

# 143 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundFromBottomRight:
# 144 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 144 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 144 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 144 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 145 "data/maps/MtPyre_Summit/scripts.pory"
	face_down
	step_end

# 148 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundFromBottomLeft:
# 149 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 149 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 149 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 149 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 150 "data/maps/MtPyre_Summit/scripts.pory"
	face_up
	step_end

# 153 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundFromMiddleRight:
# 154 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_down
# 155 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 155 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 155 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 156 "data/maps/MtPyre_Summit/scripts.pory"
	face_down
	step_end

# 159 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundFromMiddleLeft:
# 160 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_down
# 161 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 161 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 161 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 162 "data/maps/MtPyre_Summit/scripts.pory"
	face_up
	step_end

# 165 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundFromTopRight:
# 166 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_down
# 166 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_down
# 167 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 167 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 168 "data/maps/MtPyre_Summit/scripts.pory"
	face_down
	step_end

# 171 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundFromTopLeft:
# 172 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_down
# 172 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_down
# 173 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 173 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 174 "data/maps/MtPyre_Summit/scripts.pory"
	face_up
	step_end

MtPyre_Summit_EventScript_DoUnownKingBattle::
# 179 "data/maps/MtPyre_Summit/scripts.pory"
	random 12
# 180 "data/maps/MtPyre_Summit/scripts.pory"
	switch VAR_RESULT
# 181 "data/maps/MtPyre_Summit/scripts.pory"
	case 0, MtPyre_Summit_EventScript_DoUnownKingBattle_2
# 183 "data/maps/MtPyre_Summit/scripts.pory"
	case 1, MtPyre_Summit_EventScript_DoUnownKingBattle_3
# 185 "data/maps/MtPyre_Summit/scripts.pory"
	case 2, MtPyre_Summit_EventScript_DoUnownKingBattle_4
# 187 "data/maps/MtPyre_Summit/scripts.pory"
	case 3, MtPyre_Summit_EventScript_DoUnownKingBattle_5
# 189 "data/maps/MtPyre_Summit/scripts.pory"
	case 4, MtPyre_Summit_EventScript_DoUnownKingBattle_6
# 191 "data/maps/MtPyre_Summit/scripts.pory"
	case 5, MtPyre_Summit_EventScript_DoUnownKingBattle_7
# 193 "data/maps/MtPyre_Summit/scripts.pory"
	case 6, MtPyre_Summit_EventScript_DoUnownKingBattle_8
# 195 "data/maps/MtPyre_Summit/scripts.pory"
	case 7, MtPyre_Summit_EventScript_DoUnownKingBattle_9
# 197 "data/maps/MtPyre_Summit/scripts.pory"
	case 8, MtPyre_Summit_EventScript_DoUnownKingBattle_10
# 199 "data/maps/MtPyre_Summit/scripts.pory"
	case 9, MtPyre_Summit_EventScript_DoUnownKingBattle_11
# 201 "data/maps/MtPyre_Summit/scripts.pory"
	case 10, MtPyre_Summit_EventScript_DoUnownKingBattle_12
# 203 "data/maps/MtPyre_Summit/scripts.pory"
	case 11, MtPyre_Summit_EventScript_DoUnownKingBattle_13
MtPyre_Summit_EventScript_DoUnownKingBattle_13:
# 205 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_ARC_DEF_REG, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_2:
# 182 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_COF_SPE_HOO, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_3:
# 184 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_COF_SPE_REG, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_4:
# 186 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_COF_ATT_HOO, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_5:
# 188 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_COF_ATT_REG, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_6:
# 190 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_COF_DEF_HOO, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_7:
# 192 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_COF_DEF_REG, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_8:
# 194 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_ARC_SPE_HOO, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_9:
# 196 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_ARC_SPE_REG, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_10:
# 198 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_ARC_ATT_HOO, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_11:
# 200 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_ARC_ATT_REG, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_12:
# 202 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_ARC_DEF_HOO, MtPyre_Summit_Text_UnownKingDefeated
	return


MtPyre_Summit_EventScript_TestFinalBoss::
# 215 "data/maps/MtPyre_Summit/scripts.pory"
	lock
# 216 "data/maps/MtPyre_Summit/scripts.pory"
	playbgm MUS_VS_ELITE_FOUR, FALSE
# 217 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_EventScript_TestFinalBoss_Text_0, MSGBOX_DEFAULT
# 218 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 219 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_COF_SPE_HOO, MtPyre_Summit_EventScript_TestFinalBoss_Text_1
# 220 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_EventScript_TestFinalBoss_Text_2, MSGBOX_DEFAULT
# 221 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 222 "data/maps/MtPyre_Summit/scripts.pory"
	release
	return


MtPyre_Summit_EventScript_TestFinalBoss_Text_0:
# 217 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Testing final boss battle.$"

MtPyre_Summit_EventScript_TestFinalBoss_Text_1:
# 219 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Final boss battle completed.$"

MtPyre_Summit_EventScript_TestFinalBoss_Text_2:
# 220 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Final boss test completed.$"

MtPyre_Summit_Text_WorthlessHuman::
# 73 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Worthless human!\n"
	.string "Are you the one who made the Melody\l"
	.string "of Awakening resonate through this\l"
	.string "whole prison?\p"
	.string "Ha ha ha!\n"
	.string "I congratulate you!\p"
	.string "…\n"
	.string "It was not you?\p"
	.string "It does not matter!\n"
	.string "Whoever it was, their clueless, foolish\l"
	.string "mistake has allowed my servants to\l"
	.string "fully recover from the clash with\l"
	.string "my other half and its damned\l"
	.string "human allies!\p"
	.string "If the Melody of Awakening had been\n"
	.string "performed outside, the Master of Flight\l"
	.string "would have prevented it from reaching\l"
	.string "us, thanks to its power over the winds!$"

MtPyre_Summit_Text_YouWantToDefeatMe::
# 94 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Regardless, you have come here in order\n"
	.string "to destroy me and my servants,\l"
	.string "have you not?\p"
	.string "You fool!\p"
	.string "My wounds may not have healed,\n"
	.string "but my servants will extinguish\l"
	.string "those creatures that follow you,\l"
	.string "then you will be defenseless\l"
	.string "against them!\p"
	.string "You have no hope of triumph.\n"
	.string "Prepare to meet your end!$"

MtPyre_Summit_Text_UnownKingDefeated::
# 209 "data/maps/MtPyre_Summit/scripts.pory"
	.string "My servants… Powerless!\n"
	.string "Reduced to dust!$"
