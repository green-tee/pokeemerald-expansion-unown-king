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


MtPyre_4F_EventScript_Inscription::
# 23 "data/maps/MtPyre_4F/scripts.pory"
	lock
# 24 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_DefeatTheDarkness, MSGBOX_UNOWNCRYPT
# 25 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 26 "data/maps/MtPyre_4F/scripts.pory"
	release
	return


MtPyre_4F_EventScript_MaidenAressia::
# 35 "data/maps/MtPyre_4F/scripts.pory"
	lock
# 36 "data/maps/MtPyre_4F/scripts.pory"
	faceplayer
# 37 "data/maps/MtPyre_4F/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, MtPyre_4F_EventScript_MaidenAressia_2
# 41 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_ImTheStrongestMaiden, MSGBOX_YESNO
# 42 "data/maps/MtPyre_4F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MtPyre_4F_EventScript_MaidenAressia_5
# 56 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 57 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_ISee, MSGBOX_DEFAULT
# 58 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
MtPyre_4F_EventScript_MaidenAressia_1:
# 61 "data/maps/MtPyre_4F/scripts.pory"
	release
	return

MtPyre_4F_EventScript_MaidenAressia_2:
# 38 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_BelieveInYourself, MSGBOX_DEFAULT
# 39 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
	goto MtPyre_4F_EventScript_MaidenAressia_1

MtPyre_4F_EventScript_MaidenAressia_5:
# 43 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 44 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_ShallWeBegin, MSGBOX_DEFAULT
# 45 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 46 "data/maps/MtPyre_4F/scripts.pory"
	playbgm MUS_VS_GYM_LEADER, FALSE
# 47 "data/maps/MtPyre_4F/scripts.pory"
	trainerbattle_no_intro TRAINER_MAIDEN4, MtPyre_4F_Text_MaidenAressiaDefeated
# 48 "data/maps/MtPyre_4F/scripts.pory"
	lock
# 49 "data/maps/MtPyre_4F/scripts.pory"
	faceplayer
# 50 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_WhatAnIncredibleBattle, MSGBOX_DEFAULT
# 51 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 52 "data/maps/MtPyre_4F/scripts.pory"
	giveitem ITEM_HM_SURF
# 53 "data/maps/MtPyre_4F/scripts.pory"
	setflag FLAG_BADGE05_GET
# 54 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_ThisIsAPowerfulMove, MSGBOX_DEFAULT
	goto MtPyre_4F_EventScript_MaidenAressia_1


MtPyre_4F_EventScript_ScoundrelN::
# 118 "data/maps/MtPyre_4F/scripts.pory"
	lock
# 119 "data/maps/MtPyre_4F/scripts.pory"
	faceplayer
# 120 "data/maps/MtPyre_4F/scripts.pory"
	checktrainerflag TRAINER_SCOUNDREL_GROSKY
	goto_if 1, MtPyre_4F_EventScript_ScoundrelN_2
# 124 "data/maps/MtPyre_4F/scripts.pory"
	goto_if_set FLAG_FOUND_UNOWN_V, MtPyre_4F_EventScript_ScoundrelN_5
# 136 "data/maps/MtPyre_4F/scripts.pory"
	playbgm MUS_VS_WILD, FALSE
# 137 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_WeReBullyingThisUnown, MSGBOX_DEFAULT
# 138 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 139 "data/maps/MtPyre_4F/scripts.pory"
	trainerbattle_no_intro TRAINER_SCOUNDREL_GROSKY, MtPyre_4F_Text_HowCouldILose
# 140 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_ImOutOfHere, MSGBOX_DEFAULT
# 141 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 142 "data/maps/MtPyre_4F/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq MtPyre_4F_EventScript_ScoundrelN_12
# 146 "data/maps/MtPyre_4F/scripts.pory"
	applymovement LOCALID_SCOUNDREL_N, MtPyre_4F_Movement_EscapeN
# 147 "data/maps/MtPyre_4F/scripts.pory"
	waitmovement LOCALID_SCOUNDREL_N
MtPyre_4F_EventScript_ScoundrelN_11:
# 149 "data/maps/MtPyre_4F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 150 "data/maps/MtPyre_4F/scripts.pory"
	playse SE_FLEE
# 151 "data/maps/MtPyre_4F/scripts.pory"
	waitse
MtPyre_4F_EventScript_ScoundrelN_1:
# 154 "data/maps/MtPyre_4F/scripts.pory"
	release
	return

MtPyre_4F_EventScript_ScoundrelN_2:
# 121 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_IHaveToFindAnotherUnown, MSGBOX_DEFAULT
# 122 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
	goto MtPyre_4F_EventScript_ScoundrelN_1

MtPyre_4F_EventScript_ScoundrelN_5:
# 125 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_TheUnownIsGone, MSGBOX_YESNO
# 126 "data/maps/MtPyre_4F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MtPyre_4F_EventScript_ScoundrelN_8
# 133 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
	goto MtPyre_4F_EventScript_ScoundrelN_1

MtPyre_4F_EventScript_ScoundrelN_8:
# 127 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 128 "data/maps/MtPyre_4F/scripts.pory"
	playbgm MUS_VS_WILD, FALSE
# 129 "data/maps/MtPyre_4F/scripts.pory"
	trainerbattle_no_intro TRAINER_SCOUNDREL_GROSKY, MtPyre_4F_Text_HowCouldILose
# 130 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_IHaveToFindAnotherUnown, MSGBOX_DEFAULT
# 131 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
	goto MtPyre_4F_EventScript_ScoundrelN_1

MtPyre_4F_EventScript_ScoundrelN_12:
# 143 "data/maps/MtPyre_4F/scripts.pory"
	applymovement LOCALID_SCOUNDREL_N, MtPyre_4F_Movement_EscapeDodgeN
# 144 "data/maps/MtPyre_4F/scripts.pory"
	waitmovement LOCALID_SCOUNDREL_N
	goto MtPyre_4F_EventScript_ScoundrelN_11


# 181 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_4F_Movement_EscapeN:
# 182 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 182 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 182 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 182 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
	step_end

# 185 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_4F_Movement_EscapeDodgeN:
# 186 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_left
# 187 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 187 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 187 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 187 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
	step_end

MtPyre_4F_EventScript_ScoundrelS::
# 191 "data/maps/MtPyre_4F/scripts.pory"
	lock
# 192 "data/maps/MtPyre_4F/scripts.pory"
	faceplayer
# 193 "data/maps/MtPyre_4F/scripts.pory"
	checktrainerflag TRAINER_SCOUNDREL_JOAQUIN
	goto_if 1, MtPyre_4F_EventScript_ScoundrelS_2
# 197 "data/maps/MtPyre_4F/scripts.pory"
	goto_if_set FLAG_FOUND_UNOWN_V, MtPyre_4F_EventScript_ScoundrelS_5
# 209 "data/maps/MtPyre_4F/scripts.pory"
	playbgm MUS_VS_WILD, FALSE
# 210 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_ShutUp, MSGBOX_DEFAULT
# 211 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 212 "data/maps/MtPyre_4F/scripts.pory"
	trainerbattle_no_intro TRAINER_SCOUNDREL_JOAQUIN, MtPyre_4F_Text_ICantBelieveILost
# 213 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_ImHeadingOut, MSGBOX_DEFAULT
# 214 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 215 "data/maps/MtPyre_4F/scripts.pory"
	compare VAR_FACING, DIR_EAST
	goto_if_eq MtPyre_4F_EventScript_ScoundrelS_12
# 220 "data/maps/MtPyre_4F/scripts.pory"
	applymovement LOCALID_SCOUNDREL_S, MtPyre_4F_Movement_EscapeS
# 221 "data/maps/MtPyre_4F/scripts.pory"
	waitmovement LOCALID_SCOUNDREL_S
MtPyre_4F_EventScript_ScoundrelS_11:
# 223 "data/maps/MtPyre_4F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 224 "data/maps/MtPyre_4F/scripts.pory"
	playse SE_FLEE
# 225 "data/maps/MtPyre_4F/scripts.pory"
	waitse
MtPyre_4F_EventScript_ScoundrelS_1:
# 228 "data/maps/MtPyre_4F/scripts.pory"
	release
	return

MtPyre_4F_EventScript_ScoundrelS_2:
# 194 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_NowImBoredAgain, MSGBOX_DEFAULT
# 195 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
	goto MtPyre_4F_EventScript_ScoundrelS_1

MtPyre_4F_EventScript_ScoundrelS_5:
# 198 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_ImBored, MSGBOX_YESNO
# 199 "data/maps/MtPyre_4F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MtPyre_4F_EventScript_ScoundrelS_8
# 206 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
	goto MtPyre_4F_EventScript_ScoundrelS_1

MtPyre_4F_EventScript_ScoundrelS_8:
# 200 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 201 "data/maps/MtPyre_4F/scripts.pory"
	playbgm MUS_VS_WILD, FALSE
# 202 "data/maps/MtPyre_4F/scripts.pory"
	trainerbattle_no_intro TRAINER_SCOUNDREL_JOAQUIN, MtPyre_4F_Text_ICantBelieveILost
# 203 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_NowImBoredAgain, MSGBOX_DEFAULT
# 204 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
	goto MtPyre_4F_EventScript_ScoundrelS_1

MtPyre_4F_EventScript_ScoundrelS_12:
# 216 "data/maps/MtPyre_4F/scripts.pory"
	applymovement LOCALID_SCOUNDREL_S, MtPyre_4F_Movement_EscapeDodgeS
# 217 "data/maps/MtPyre_4F/scripts.pory"
	waitmovement LOCALID_SCOUNDREL_S
	goto MtPyre_4F_EventScript_ScoundrelS_11


# 255 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_4F_Movement_EscapeS:
# 256 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_left
# 256 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_left
# 257 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 257 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 257 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 258 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_right
# 259 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 259 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 259 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
	step_end

# 262 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_4F_Movement_EscapeDodgeS:
# 263 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_right
# 263 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_right
# 264 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 264 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 264 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 265 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_left
# 266 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 266 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 266 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
	step_end

MtPyre_4F_EventScript_ScoundrelW::
# 270 "data/maps/MtPyre_4F/scripts.pory"
	lock
# 271 "data/maps/MtPyre_4F/scripts.pory"
	faceplayer
# 272 "data/maps/MtPyre_4F/scripts.pory"
	checktrainerflag TRAINER_SCOUNDREL_DIRK
	goto_if 1, MtPyre_4F_EventScript_ScoundrelW_2
# 276 "data/maps/MtPyre_4F/scripts.pory"
	goto_if_set FLAG_FOUND_UNOWN_V, MtPyre_4F_EventScript_ScoundrelW_5
# 288 "data/maps/MtPyre_4F/scripts.pory"
	playbgm MUS_VS_WILD, FALSE
# 289 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_MoveYourFaceAway, MSGBOX_DEFAULT
# 290 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 291 "data/maps/MtPyre_4F/scripts.pory"
	trainerbattle_no_intro TRAINER_SCOUNDREL_DIRK, MtPyre_4F_Text_NoWay
# 292 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_INeverWantToSeeYou, MSGBOX_DEFAULT
# 293 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 294 "data/maps/MtPyre_4F/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq MtPyre_4F_EventScript_ScoundrelW_12
# 298 "data/maps/MtPyre_4F/scripts.pory"
	applymovement LOCALID_SCOUNDREL_W, MtPyre_4F_Movement_EscapeW
# 299 "data/maps/MtPyre_4F/scripts.pory"
	waitmovement LOCALID_SCOUNDREL_W
MtPyre_4F_EventScript_ScoundrelW_11:
# 301 "data/maps/MtPyre_4F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 302 "data/maps/MtPyre_4F/scripts.pory"
	playse SE_FLEE
# 303 "data/maps/MtPyre_4F/scripts.pory"
	waitse
MtPyre_4F_EventScript_ScoundrelW_1:
# 306 "data/maps/MtPyre_4F/scripts.pory"
	release
	return

MtPyre_4F_EventScript_ScoundrelW_2:
# 273 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_ILostToAPipsqueakLikeYou, MSGBOX_DEFAULT
# 274 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
	goto MtPyre_4F_EventScript_ScoundrelW_1

MtPyre_4F_EventScript_ScoundrelW_5:
# 277 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_AreYouLookingForAFight, MSGBOX_YESNO
# 278 "data/maps/MtPyre_4F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MtPyre_4F_EventScript_ScoundrelW_8
# 285 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
	goto MtPyre_4F_EventScript_ScoundrelW_1

MtPyre_4F_EventScript_ScoundrelW_8:
# 279 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 280 "data/maps/MtPyre_4F/scripts.pory"
	playbgm MUS_VS_WILD, FALSE
# 281 "data/maps/MtPyre_4F/scripts.pory"
	trainerbattle_no_intro TRAINER_SCOUNDREL_DIRK, MtPyre_4F_Text_NoWay
# 282 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_ILostToAPipsqueakLikeYou, MSGBOX_DEFAULT
# 283 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
	goto MtPyre_4F_EventScript_ScoundrelW_1

MtPyre_4F_EventScript_ScoundrelW_12:
# 295 "data/maps/MtPyre_4F/scripts.pory"
	applymovement LOCALID_SCOUNDREL_W, MtPyre_4F_Movement_EscapeDodgeW
# 296 "data/maps/MtPyre_4F/scripts.pory"
	waitmovement LOCALID_SCOUNDREL_W
	goto MtPyre_4F_EventScript_ScoundrelW_11


# 333 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_4F_Movement_EscapeW:
# 334 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 334 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 334 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 334 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 334 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
	step_end

# 337 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_4F_Movement_EscapeDodgeW:
# 338 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_left
# 339 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 339 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 340 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_right
# 341 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 341 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 341 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
	step_end

MtPyre_4F_EventScript_ScoundrelE::
# 345 "data/maps/MtPyre_4F/scripts.pory"
	lock
# 346 "data/maps/MtPyre_4F/scripts.pory"
	faceplayer
# 347 "data/maps/MtPyre_4F/scripts.pory"
	checktrainerflag TRAINER_SCOUNDREL_ABDUL
	goto_if 1, MtPyre_4F_EventScript_ScoundrelE_2
# 351 "data/maps/MtPyre_4F/scripts.pory"
	goto_if_set FLAG_FOUND_UNOWN_V, MtPyre_4F_EventScript_ScoundrelE_5
# 363 "data/maps/MtPyre_4F/scripts.pory"
	playbgm MUS_VS_WILD, FALSE
# 364 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_ItsNoneOfYourBusiness, MSGBOX_DEFAULT
# 365 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 366 "data/maps/MtPyre_4F/scripts.pory"
	trainerbattle_no_intro TRAINER_SCOUNDREL_ABDUL, MtPyre_4F_Text_GreatNoImOutOfPokemon
# 367 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_ImDoneHere, MSGBOX_DEFAULT
# 368 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 369 "data/maps/MtPyre_4F/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq MtPyre_4F_EventScript_ScoundrelE_12
# 373 "data/maps/MtPyre_4F/scripts.pory"
	applymovement LOCALID_SCOUNDREL_E, MtPyre_4F_Movement_EscapeE
# 374 "data/maps/MtPyre_4F/scripts.pory"
	waitmovement LOCALID_SCOUNDREL_E
MtPyre_4F_EventScript_ScoundrelE_11:
# 376 "data/maps/MtPyre_4F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 377 "data/maps/MtPyre_4F/scripts.pory"
	playse SE_FLEE
# 378 "data/maps/MtPyre_4F/scripts.pory"
	waitse
MtPyre_4F_EventScript_ScoundrelE_1:
# 381 "data/maps/MtPyre_4F/scripts.pory"
	release
	return

MtPyre_4F_EventScript_ScoundrelE_2:
# 348 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_IHeardMoonStone, MSGBOX_DEFAULT
# 349 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
	goto MtPyre_4F_EventScript_ScoundrelE_1

MtPyre_4F_EventScript_ScoundrelE_5:
# 352 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_WantToBattle, MSGBOX_YESNO
# 353 "data/maps/MtPyre_4F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MtPyre_4F_EventScript_ScoundrelE_8
# 360 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
	goto MtPyre_4F_EventScript_ScoundrelE_1

MtPyre_4F_EventScript_ScoundrelE_8:
# 354 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
# 355 "data/maps/MtPyre_4F/scripts.pory"
	playbgm MUS_VS_WILD, FALSE
# 356 "data/maps/MtPyre_4F/scripts.pory"
	trainerbattle_no_intro TRAINER_SCOUNDREL_ABDUL, MtPyre_4F_Text_GreatNoImOutOfPokemon
# 357 "data/maps/MtPyre_4F/scripts.pory"
	msgbox MtPyre_4F_Text_IHeardMoonStone, MSGBOX_DEFAULT
# 358 "data/maps/MtPyre_4F/scripts.pory"
	closemessage
	goto MtPyre_4F_EventScript_ScoundrelE_1

MtPyre_4F_EventScript_ScoundrelE_12:
# 370 "data/maps/MtPyre_4F/scripts.pory"
	applymovement LOCALID_SCOUNDREL_E, MtPyre_4F_Movement_EscapeDodgeE
# 371 "data/maps/MtPyre_4F/scripts.pory"
	waitmovement LOCALID_SCOUNDREL_E
	goto MtPyre_4F_EventScript_ScoundrelE_11


# 410 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_4F_Movement_EscapeE:
# 411 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 411 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 411 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 411 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 411 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
	step_end

# 414 "data/maps/MtPyre_4F/scripts.pory"
MtPyre_4F_Movement_EscapeDodgeE:
# 415 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_right
# 416 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 416 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 417 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_left
# 418 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 418 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
# 418 "data/maps/MtPyre_4F/scripts.pory"
	walk_fast_up
	step_end

MtPyre_4F_Text_DefeatTheDarkness::
# 29 "data/maps/MtPyre_4F/scripts.pory"
	.string "Those who wish to see clear\n"
	.string "must put out the darkness.$"

MtPyre_4F_Text_ImTheStrongestMaiden::
# 64 "data/maps/MtPyre_4F/scripts.pory"
	.string "Greetings, traveler!\p"
	.string "I am Aressia, the strongest of\n"
	.string "the four Maidens.\p"
	.string "I aid the worty ones by lending them\n"
	.string "the force of nature.\p"
	.string "Be warned, though: if you accept my\n"
	.string "gift, the road ahead will be a\l"
	.string "perilous one.\l"
	.string "That is why I must test your ability\l"
	.string "in battle more than my Sisters.\p"
	.string "Are you ready to fight?$"

MtPyre_4F_Text_ISee::
# 78 "data/maps/MtPyre_4F/scripts.pory"
	.string "I see.\n"
	.string "Take your time to prepare.$"

MtPyre_4F_Text_ShallWeBegin::
# 83 "data/maps/MtPyre_4F/scripts.pory"
	.string "Well then, shall we begin?$"

MtPyre_4F_Text_MaidenAressiaDefeated::
# 87 "data/maps/MtPyre_4F/scripts.pory"
	.string "Well done, traveler!\n"
	.string "You are indeed a worthy one.$"

MtPyre_4F_Text_WhatAnIncredibleBattle::
# 92 "data/maps/MtPyre_4F/scripts.pory"
	.string "What an incredible battle!\n"
	.string "You earned the power I promised:\l"
	.string "the ability to navigate the calm waters\l"
	.string "that cuddle this temple.\p"
	.string "Take it!$"

MtPyre_4F_Text_ThisIsAPowerfulMove::
# 100 "data/maps/MtPyre_4F/scripts.pory"
	.string "If you feel like teaching this move\n"
	.string "to one of your Pokémon, it is a \l"
	.string "powerful one. Pokémon that are weak to\l"
	.string "Water-type moves do not fare well\l"
	.string "against it.\p"
	.string "I must warn you again: from now on,\n"
	.string "you must always be on your toes.\p"
	.string "But I believe in you.\n"
	.string "You too, believe in yourself.$"

MtPyre_4F_Text_BelieveInYourself::
# 112 "data/maps/MtPyre_4F/scripts.pory"
	.string "I believe in you.\n"
	.string "You too, believe in yourself, always.$"

MtPyre_4F_Text_WeReBullyingThisUnown::
# 157 "data/maps/MtPyre_4F/scripts.pory"
	.string "What? I'm bullying this Unown,\n"
	.string "don't you see?$"

MtPyre_4F_Text_HowCouldILose::
# 162 "data/maps/MtPyre_4F/scripts.pory"
	.string "How?! How could I lose?!$"

MtPyre_4F_Text_ImOutOfHere::
# 166 "data/maps/MtPyre_4F/scripts.pory"
	.string "Tsk!\n"
	.string "I'm out of here!$"

MtPyre_4F_Text_TheUnownIsGone::
# 171 "data/maps/MtPyre_4F/scripts.pory"
	.string "Welp, the Unown is gone.\n"
	.string "How about a battle?$"

MtPyre_4F_Text_IHaveToFindAnotherUnown::
# 176 "data/maps/MtPyre_4F/scripts.pory"
	.string "Now I have to find another Unown.\p"
	.string "Haha! Just kidding.$"

MtPyre_4F_Text_ShutUp::
# 231 "data/maps/MtPyre_4F/scripts.pory"
	.string "Shut up!\n"
	.string "I'm busy here!$"

MtPyre_4F_Text_ICantBelieveILost::
# 236 "data/maps/MtPyre_4F/scripts.pory"
	.string "Nooo! I can't believe I lost!$"

MtPyre_4F_Text_ImHeadingOut::
# 240 "data/maps/MtPyre_4F/scripts.pory"
	.string "Umpf!\n"
	.string "I'm heading out!$"

MtPyre_4F_Text_ImBored::
# 245 "data/maps/MtPyre_4F/scripts.pory"
	.string "Ugh, I'm so bored.\n"
	.string "Kill my boredom with a battle!$"

MtPyre_4F_Text_NowImBoredAgain::
# 250 "data/maps/MtPyre_4F/scripts.pory"
	.string "It was good while it lasted,\n"
	.string "but now I'm bored again.$"

MtPyre_4F_Text_MoveYourFaceAway::
# 309 "data/maps/MtPyre_4F/scripts.pory"
	.string "Hey, pipsqueak! Move your dumb face\n"
	.string "away from mine!$"

MtPyre_4F_Text_NoWay::
# 314 "data/maps/MtPyre_4F/scripts.pory"
	.string "No way!$"

MtPyre_4F_Text_INeverWantToSeeYou::
# 318 "data/maps/MtPyre_4F/scripts.pory"
	.string "I never want to see your face again,\n"
	.string "pipsqueak!$"

MtPyre_4F_Text_AreYouLookingForAFight::
# 323 "data/maps/MtPyre_4F/scripts.pory"
	.string "Pipsqueak!\n"
	.string "Are you looking for a fight?$"

MtPyre_4F_ILostToAPipsqueakLikeYou::
# 328 "data/maps/MtPyre_4F/scripts.pory"
	.string "I lost to a pipsqueak like you. I guess\n"
	.string "you can't always judge by appearence.$"

MtPyre_4F_Text_ItsNoneOfYourBusiness::
# 384 "data/maps/MtPyre_4F/scripts.pory"
	.string "It's none of your business what I'm\n"
	.string "doing here! Go back to your mummy!$"

MtPyre_4F_Text_GreatNoImOutOfPokemon::
# 389 "data/maps/MtPyre_4F/scripts.pory"
	.string "Oh, great! Now I'm out of Pokémon.$"

MtPyre_4F_Text_ImDoneHere::
# 393 "data/maps/MtPyre_4F/scripts.pory"
	.string "Alright, then!\n"
	.string "I'm done here!$"

MtPyre_4F_Text_WantToBattle::
# 398 "data/maps/MtPyre_4F/scripts.pory"
	.string "Hm? You want to battle?\n"
	.string "Sure, why not?$"

MtPyre_4F_Text_IHeardMoonStone::
# 403 "data/maps/MtPyre_4F/scripts.pory"
	.string "I heard that a Moon Stone could make\n"
	.string "my Pokémon evolve.\p"
	.string "If you think about it, it's a stone\n"
	.string "coming from a big rock in the sky.$"
