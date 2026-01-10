MtPyre_Summit_MapScripts::
# 2 "data/maps/MtPyre_Summit/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_Summit_EventScript_TryRemoveUnown
# 3 "data/maps/MtPyre_Summit/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_EventScript_HideFriendlyUnown
# 4 "data/maps/MtPyre_Summit/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MtPyre_Summit_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 7 "data/maps/MtPyre_Summit/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtPyre_Summit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

MtPyre_Summit_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 5 "data/maps/MtPyre_Summit/scripts.pory"
	map_script_2 VAR_UNOWN_KING_PRISON_STATE, 0, MtPyre_Summit_EventScript_FacePlayerNorth
	.2byte 0

MtPyre_Summit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 8 "data/maps/MtPyre_Summit/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, MtPyre_Summit_EventScript_StartFinalBossSequence
	.2byte 0


MtPyre_Summit_EventScript_TryRemoveUnown::
# 13 "data/maps/MtPyre_Summit/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtPyre_Summit_EventScript_TryRemoveUnown_1
	return

MtPyre_Summit_EventScript_TryRemoveUnown_1:
# 14 "data/maps/MtPyre_Summit/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MtPyre_Summit_EventScript_TryRemoveUnown_3
	return

MtPyre_Summit_EventScript_TryRemoveUnown_3:
# 17 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_UNOWN_BOTTOM_LEFT
# 18 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_UNOWN_MIDDLE_LEFT
# 19 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_UNOWN_TOP_LEFT
# 20 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_UNOWN_BOTTOM_RIGHT
# 21 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_UNOWN_MIDDLE_RIGHT
# 22 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_UNOWN_TOP_RIGHT
	return


MtPyre_Summit_EventScript_FacePlayerNorth::
# 28 "data/maps/MtPyre_Summit/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	return


MtPyre_Summit_EventScript_HideFriendlyUnown::
# 32 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_TEMP_2
# 33 "data/maps/MtPyre_Summit/scripts.pory"
	hideobjectat LOCALID_UNOWN_G, MAP_MT_PYRE_SUMMIT
# 34 "data/maps/MtPyre_Summit/scripts.pory"
	hideobjectat LOCALID_UNOWN_L, MAP_MT_PYRE_SUMMIT
# 35 "data/maps/MtPyre_Summit/scripts.pory"
	hideobjectat LOCALID_UNOWN_Y, MAP_MT_PYRE_SUMMIT
# 36 "data/maps/MtPyre_Summit/scripts.pory"
	hideobjectat LOCALID_UNOWN_P, MAP_MT_PYRE_SUMMIT
# 37 "data/maps/MtPyre_Summit/scripts.pory"
	hideobjectat LOCALID_UNOWN_H, MAP_MT_PYRE_SUMMIT
# 38 "data/maps/MtPyre_Summit/scripts.pory"
	hideobjectat LOCALID_UNOWN_S, MAP_MT_PYRE_SUMMIT
	return


MtPyre_Summit_EventScript_StartFinalBossSequence::
# 42 "data/maps/MtPyre_Summit/scripts.pory"
	lockplayer
# 43 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_TEMP_0, 1
# 44 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_WalkToFinalBoss1
# 45 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement LOCALID_PLAYER
# 46 "data/maps/MtPyre_Summit/scripts.pory"
	delay 30
# 47 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_WalkToFinalBoss2
# 48 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement LOCALID_PLAYER
# 49 "data/maps/MtPyre_Summit/scripts.pory"
	playbgm MUS_VS_ELITE_FOUR, FALSE
# 50 "data/maps/MtPyre_Summit/scripts.pory"
	playse SE_PIN
# 51 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_Surprised
# 52 "data/maps/MtPyre_Summit/scripts.pory"
	special SpawnCameraObject
# 53 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_CAMERA, MtPyre_Summit_Movement_PanCameraToUnownKing
# 54 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement LOCALID_CAMERA
# 55 "data/maps/MtPyre_Summit/scripts.pory"
	special RemoveCameraObject
# 56 "data/maps/MtPyre_Summit/scripts.pory"
	delay 60
# 57 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_WorthlessHuman, MSGBOX_DEFAULT
# 58 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 59 "data/maps/MtPyre_Summit/scripts.pory"
	delay 60
# 60 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_YouWantToDefeatMe, MSGBOX_DEFAULT
# 61 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 62 "data/maps/MtPyre_Summit/scripts.pory"
	call MtPyre_Summit_EventScript_UnownSurroundPlayer
# 63 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 64 "data/maps/MtPyre_Summit/scripts.pory"
	call MtPyre_Summit_EventScript_DoUnownKingBattle
# 65 "data/maps/MtPyre_Summit/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 66 "data/maps/MtPyre_Summit/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 67 "data/maps/MtPyre_Summit/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MtPyre_Summit_EventScript_StartFinalBossSequence_2
# 72 "data/maps/MtPyre_Summit/scripts.pory"
	call MtPyre_Summit_EventScript_BadEnding
MtPyre_Summit_EventScript_StartFinalBossSequence_1:
# 74 "data/maps/MtPyre_Summit/scripts.pory"
	releaseall
	return

MtPyre_Summit_EventScript_StartFinalBossSequence_2:
# 69 "data/maps/MtPyre_Summit/scripts.pory"
	call MtPyre_Summit_EventScript_UnownKingDefeated
	goto MtPyre_Summit_EventScript_StartFinalBossSequence_1


# 77 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_WalkToFinalBoss1:
# 78 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 78 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 78 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
	step_end

# 81 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_WalkToFinalBoss2:
# 82 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 82 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 82 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 82 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 82 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 82 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
# 82 "data/maps/MtPyre_Summit/scripts.pory"
	walk_up
	step_end

# 85 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_Surprised:
# 86 "data/maps/MtPyre_Summit/scripts.pory"
	emote_exclamation_mark
	step_end

# 89 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_PanCameraToUnownKing:
# 90 "data/maps/MtPyre_Summit/scripts.pory"
	walk_slow_up
# 90 "data/maps/MtPyre_Summit/scripts.pory"
	walk_slow_up
# 90 "data/maps/MtPyre_Summit/scripts.pory"
	walk_slow_up
	step_end

MtPyre_Summit_EventScript_UnownSurroundPlayer::
# 129 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 130 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_LEFT, MtPyre_Summit_Movement_UnownDown
# 131 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 132 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 133 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_MIDDLE_LEFT, MtPyre_Summit_Movement_UnownDown
# 134 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_LEFT, MtPyre_Summit_Movement_UnownDown
# 135 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 136 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 137 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_RIGHT, MtPyre_Summit_Movement_UnownDown
# 138 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_BOTTOM_LEFT, MtPyre_Summit_Movement_UnownDown
# 139 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_MIDDLE_LEFT, MtPyre_Summit_Movement_UnownDown
# 140 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_LEFT, MtPyre_Summit_Movement_UnownDown
# 141 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 142 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 143 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_MIDDLE_RIGHT, MtPyre_Summit_Movement_UnownDown
# 144 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_RIGHT, MtPyre_Summit_Movement_UnownDown
# 145 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_BOTTOM_LEFT, MtPyre_Summit_Movement_UnownDown
# 146 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_MIDDLE_LEFT, MtPyre_Summit_Movement_UnownDown
# 147 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_LEFT, MtPyre_Summit_Movement_UnownDown
# 148 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 149 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 150 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_BOTTOM_RIGHT, MtPyre_Summit_Movement_SurroundFromBottomRight
# 151 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_BOTTOM_LEFT, MtPyre_Summit_Movement_SurroundFromBottomLeft
# 152 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_MIDDLE_RIGHT, MtPyre_Summit_Movement_SurroundFromMiddleRight
# 153 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_MIDDLE_LEFT, MtPyre_Summit_Movement_SurroundFromMiddleLeft
# 154 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_RIGHT, MtPyre_Summit_Movement_SurroundFromTopRight
# 155 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_TOP_LEFT, MtPyre_Summit_Movement_SurroundFromTopLeft
# 156 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
	return


# 159 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_UnownDown:
# 160 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_down
	step_end

# 163 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundFromBottomRight:
# 164 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 164 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 164 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 164 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 165 "data/maps/MtPyre_Summit/scripts.pory"
	face_down
	step_end

# 168 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundFromBottomLeft:
# 169 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 169 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 169 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 169 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 170 "data/maps/MtPyre_Summit/scripts.pory"
	face_up
	step_end

# 173 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundFromMiddleRight:
# 174 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_down
# 175 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 175 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 175 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 176 "data/maps/MtPyre_Summit/scripts.pory"
	face_down
	step_end

# 179 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundFromMiddleLeft:
# 180 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_down
# 181 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 181 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 181 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 182 "data/maps/MtPyre_Summit/scripts.pory"
	face_up
	step_end

# 185 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundFromTopRight:
# 186 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_down
# 186 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_down
# 187 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 187 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 188 "data/maps/MtPyre_Summit/scripts.pory"
	face_down
	step_end

# 191 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundFromTopLeft:
# 192 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_down
# 192 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_down
# 193 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 193 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 194 "data/maps/MtPyre_Summit/scripts.pory"
	face_up
	step_end

MtPyre_Summit_EventScript_DoUnownKingBattle::
# 199 "data/maps/MtPyre_Summit/scripts.pory"
	setflag FLAG_PREVENT_WHITEOUT
# 200 "data/maps/MtPyre_Summit/scripts.pory"
	random 12
# 201 "data/maps/MtPyre_Summit/scripts.pory"
	switch VAR_RESULT
# 202 "data/maps/MtPyre_Summit/scripts.pory"
	case 0, MtPyre_Summit_EventScript_DoUnownKingBattle_2
# 204 "data/maps/MtPyre_Summit/scripts.pory"
	case 1, MtPyre_Summit_EventScript_DoUnownKingBattle_3
# 206 "data/maps/MtPyre_Summit/scripts.pory"
	case 2, MtPyre_Summit_EventScript_DoUnownKingBattle_4
# 208 "data/maps/MtPyre_Summit/scripts.pory"
	case 3, MtPyre_Summit_EventScript_DoUnownKingBattle_5
# 210 "data/maps/MtPyre_Summit/scripts.pory"
	case 4, MtPyre_Summit_EventScript_DoUnownKingBattle_6
# 212 "data/maps/MtPyre_Summit/scripts.pory"
	case 5, MtPyre_Summit_EventScript_DoUnownKingBattle_7
# 214 "data/maps/MtPyre_Summit/scripts.pory"
	case 6, MtPyre_Summit_EventScript_DoUnownKingBattle_8
# 216 "data/maps/MtPyre_Summit/scripts.pory"
	case 7, MtPyre_Summit_EventScript_DoUnownKingBattle_9
# 218 "data/maps/MtPyre_Summit/scripts.pory"
	case 8, MtPyre_Summit_EventScript_DoUnownKingBattle_10
# 220 "data/maps/MtPyre_Summit/scripts.pory"
	case 9, MtPyre_Summit_EventScript_DoUnownKingBattle_11
# 222 "data/maps/MtPyre_Summit/scripts.pory"
	case 10, MtPyre_Summit_EventScript_DoUnownKingBattle_12
# 224 "data/maps/MtPyre_Summit/scripts.pory"
	case 11, MtPyre_Summit_EventScript_DoUnownKingBattle_13
MtPyre_Summit_EventScript_DoUnownKingBattle_13:
# 226 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_ARC_DEF_REG, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_2:
# 203 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_COF_SPE_HOO, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_3:
# 205 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_COF_SPE_REG, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_4:
# 207 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_COF_ATT_HOO, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_5:
# 209 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_COF_ATT_REG, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_6:
# 211 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_COF_DEF_HOO, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_7:
# 213 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_COF_DEF_REG, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_8:
# 215 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_ARC_SPE_HOO, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_9:
# 217 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_ARC_SPE_REG, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_10:
# 219 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_ARC_ATT_HOO, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_11:
# 221 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_ARC_ATT_REG, MtPyre_Summit_Text_UnownKingDefeated
	return

MtPyre_Summit_EventScript_DoUnownKingBattle_12:
# 223 "data/maps/MtPyre_Summit/scripts.pory"
	trainerbattle_no_intro TRAINER_UNOWN_KING_ARC_DEF_HOO, MtPyre_Summit_Text_UnownKingDefeated
	return


MtPyre_Summit_EventScript_BadEnding:
# 236 "data/maps/MtPyre_Summit/scripts.pory"
	playbgm MUS_TOO_BAD, FALSE
# 237 "data/maps/MtPyre_Summit/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 238 "data/maps/MtPyre_Summit/scripts.pory"
	doweather
# 239 "data/maps/MtPyre_Summit/scripts.pory"
	delay 180
# 240 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_YouAreDone, MSGBOX_DEFAULT
# 241 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 242 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 10
# 243 "data/maps/MtPyre_Summit/scripts.pory"
	delay 60
# 244 "data/maps/MtPyre_Summit/scripts.pory"
	special DoSoftReset
	return


MtPyre_Summit_EventScript_UnownKingDefeated:
# 255 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_EventScript_ItCannotBe, MSGBOX_DEFAULT
# 256 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 257 "data/maps/MtPyre_Summit/scripts.pory"
	call MtPyre_Summit_EventScript_ShowFriendlyUnown
# 258 "data/maps/MtPyre_Summit/scripts.pory"
	call MtPyre_Summit_EventScript_FriendlyUnownSurroundUnownKing
# 259 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_MySubjectsObeyYou, MSGBOX_DEFAULT
# 260 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 261 "data/maps/MtPyre_Summit/scripts.pory"
	delay 60
# 262 "data/maps/MtPyre_Summit/scripts.pory"
	msgbox MtPyre_Summit_Text_YouCannotDestroyMe, MSGBOX_DEFAULT
# 263 "data/maps/MtPyre_Summit/scripts.pory"
	closemessage
# 264 "data/maps/MtPyre_Summit/scripts.pory"
	playse SE_ORB
# 265 "data/maps/MtPyre_Summit/scripts.pory"
	special DoOrbEffect
# 266 "data/maps/MtPyre_Summit/scripts.pory"
	delay 300
# 267 "data/maps/MtPyre_Summit/scripts.pory"
	playse SE_M_STRENGTH
# 268 "data/maps/MtPyre_Summit/scripts.pory"
	special FadeOutOrbEffect
# 269 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
# 270 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 0
# 271 "data/maps/MtPyre_Summit/scripts.pory"
	removeobject LOCALID_UNOWN_KING
# 272 "data/maps/MtPyre_Summit/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 0
# 273 "data/maps/MtPyre_Summit/scripts.pory"
	delay 180
# 274 "data/maps/MtPyre_Summit/scripts.pory"
	setvar VAR_INTRO_AREA_STATE, 2
# 275 "data/maps/MtPyre_Summit/scripts.pory"
	warpsilent MAP_ROUTE101, 12, 13
# 276 "data/maps/MtPyre_Summit/scripts.pory"
	waitstate
	return


MtPyre_Summit_EventScript_ShowFriendlyUnown:
# 288 "data/maps/MtPyre_Summit/scripts.pory"
	clearflag FLAG_TEMP_2
# 289 "data/maps/MtPyre_Summit/scripts.pory"
	addobject LOCALID_UNOWN_G, MAP_MT_PYRE_SUMMIT
# 290 "data/maps/MtPyre_Summit/scripts.pory"
	addobject LOCALID_UNOWN_L, MAP_MT_PYRE_SUMMIT
# 291 "data/maps/MtPyre_Summit/scripts.pory"
	addobject LOCALID_UNOWN_Y, MAP_MT_PYRE_SUMMIT
# 292 "data/maps/MtPyre_Summit/scripts.pory"
	addobject LOCALID_UNOWN_P, MAP_MT_PYRE_SUMMIT
# 293 "data/maps/MtPyre_Summit/scripts.pory"
	addobject LOCALID_UNOWN_H, MAP_MT_PYRE_SUMMIT
# 294 "data/maps/MtPyre_Summit/scripts.pory"
	addobject LOCALID_UNOWN_S, MAP_MT_PYRE_SUMMIT
	return


MtPyre_Summit_EventScript_FriendlyUnownSurroundUnownKing:
# 305 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 306 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_L, MtPyre_Summit_Movement_UnownUp
# 307 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 309 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 310 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_L, MtPyre_Summit_Movement_UnownLeft
# 311 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_Y, MtPyre_Summit_Movement_UnownUp
# 312 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 314 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 315 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_L, MtPyre_Summit_Movement_UnownLeft
# 316 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_Y, MtPyre_Summit_Movement_UnownRight
# 317 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_G, MtPyre_Summit_Movement_UnownUp
# 318 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 320 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 321 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_L, MtPyre_Summit_Movement_UnownLeft
# 322 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_Y, MtPyre_Summit_Movement_UnownRight
# 323 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_G, MtPyre_Summit_Movement_UnownLeft
# 324 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_S, MtPyre_Summit_Movement_UnownUp
# 325 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 327 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 328 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_L, MtPyre_Summit_Movement_UnownUp
# 329 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_Y, MtPyre_Summit_Movement_UnownRight
# 330 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_G, MtPyre_Summit_Movement_UnownLeft
# 331 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_S, MtPyre_Summit_Movement_UnownRight
# 332 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_P, MtPyre_Summit_Movement_UnownUp
# 333 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 335 "data/maps/MtPyre_Summit/scripts.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 336 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_L, MtPyre_Summit_Movement_UnownUp
# 337 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_Y, MtPyre_Summit_Movement_UnownUp
# 338 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_G, MtPyre_Summit_Movement_UnownLeft
# 339 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_S, MtPyre_Summit_Movement_UnownRight
# 340 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_P, MtPyre_Summit_Movement_UnownLeft
# 341 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_H, MtPyre_Summit_Movement_UnownUp
# 342 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement 0
# 345 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_L, MtPyre_Summit_Movement_SurroundL
# 346 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_Y, MtPyre_Summit_Movement_SurroundY
# 347 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_G, MtPyre_Summit_Movement_SurroundG
# 348 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_S, MtPyre_Summit_Movement_SurroundS
# 349 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_P, MtPyre_Summit_Movement_SurroundP
# 350 "data/maps/MtPyre_Summit/scripts.pory"
	applymovement LOCALID_UNOWN_H, MtPyre_Summit_Movement_SurroundH
# 351 "data/maps/MtPyre_Summit/scripts.pory"
	waitmovement LOCALID_UNOWN_L
	return


# 354 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_UnownUp:
# 355 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_up
	step_end

# 358 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_UnownLeft:
# 359 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
	step_end

# 362 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_UnownRight:
# 363 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
	step_end

# 366 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundL:
# 367 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_up
# 367 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_up
# 368 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 368 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 368 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 369 "data/maps/MtPyre_Summit/scripts.pory"
	face_down
	step_end

# 372 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundY:
# 373 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_up
# 373 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_up
# 373 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_up
# 374 "data/maps/MtPyre_Summit/scripts.pory"
	face_down
	step_end

# 377 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundG:
# 378 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_up
# 378 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_up
# 378 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_up
# 378 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_up
# 379 "data/maps/MtPyre_Summit/scripts.pory"
	face_down
	step_end

# 382 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundS:
# 383 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_right
# 384 "data/maps/MtPyre_Summit/scripts.pory"
	face_up
	step_end

# 387 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundP:
# 388 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 388 "data/maps/MtPyre_Summit/scripts.pory"
	walk_fast_left
# 389 "data/maps/MtPyre_Summit/scripts.pory"
	face_up
	step_end

# 392 "data/maps/MtPyre_Summit/scripts.pory"
MtPyre_Summit_Movement_SurroundH:
# 393 "data/maps/MtPyre_Summit/scripts.pory"
	face_up
	step_end

MtPyre_Summit_Text_WorthlessHuman::
# 93 "data/maps/MtPyre_Summit/scripts.pory"
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
# 114 "data/maps/MtPyre_Summit/scripts.pory"
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
# 230 "data/maps/MtPyre_Summit/scripts.pory"
	.string "My servants… Powerless!\n"
	.string "Reduced to dust!$"

MtPyre_Summit_Text_YouAreDone::
# 247 "data/maps/MtPyre_Summit/scripts.pory"
	.string "You are done, foolish nobody!\p"
	.string "My servants will accelerate my healing,\n"
	.string "then I will leave this prison and\l"
	.string "destroy each and every one of your kind!$"

MtPyre_Summit_EventScript_ItCannotBe::
# 279 "data/maps/MtPyre_Summit/scripts.pory"
	.string "No! It cannot be!\p"
	.string "My servants… Defeated?!\n"
	.string "By an insignificant human like you?!\p"
	.string "I have not healed yet… And without them,\n"
	.string "I cannot…!$"

MtPyre_Summit_Text_MySubjectsObeyYou::
# 396 "data/maps/MtPyre_Summit/scripts.pory"
	.string "What?!\n"
	.string "My subjects… They side with you now?!$"

MtPyre_Summit_Text_YouCannotDestroyMe::
# 401 "data/maps/MtPyre_Summit/scripts.pory"
	.string "Traitors! You will never destroy me!\n"
	.string "You will seal me back into this altar,\l"
	.string "but my wounds will heal!\p"
	.string "Once my healing is complete, I will\n"
	.string "break free from this prison, then\l"
	.string "I will be strong enough to fight\l"
	.string "myself!\p"
	.string "Centuries…\n"
	.string "Millennia…\p"
	.string "However long it may take,\n"
	.string "I will resurface!$"
