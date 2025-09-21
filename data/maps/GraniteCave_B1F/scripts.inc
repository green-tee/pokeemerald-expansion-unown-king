GraniteCave_B1F_MapScripts::
	.byte 0


GraniteCave_B1F_InscriptionLeft::
# 9 "data/maps/GraniteCave_B1F/scripts.pory"
	setvar VAR_TEMP_0, 0
# 10 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_InscriptionCommon
	return


GraniteCave_B1F_InscriptionMiddle::
# 14 "data/maps/GraniteCave_B1F/scripts.pory"
	setvar VAR_TEMP_0, 1
# 15 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_InscriptionCommon
	return


GraniteCave_B1F_InscriptionRight::
# 19 "data/maps/GraniteCave_B1F/scripts.pory"
	setvar VAR_TEMP_0, 2
# 20 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_InscriptionCommon
	return


GraniteCave_B1F_InscriptionCommon::
# 24 "data/maps/GraniteCave_B1F/scripts.pory"
	lockall
# 25 "data/maps/GraniteCave_B1F/scripts.pory"
	goto_if_unset FLAG_SYS_USE_FLASH, GraniteCave_B1F_InscriptionCommon_2
# 29 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_UnownKingStory, MSGBOX_UNOWNCRYPT
# 30 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
# 31 "data/maps/GraniteCave_B1F/scripts.pory"
	compare VAR_CHAMBER_OF_TRUTH_STATE, 3
	goto_if_lt GraniteCave_B1F_InscriptionCommon_5
GraniteCave_B1F_InscriptionCommon_1:
# 43 "data/maps/GraniteCave_B1F/scripts.pory"
	releaseall
	return

GraniteCave_B1F_InscriptionCommon_2:
# 26 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_TooDark, MSGBOX_DEFAULT
# 27 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
	goto GraniteCave_B1F_InscriptionCommon_1

GraniteCave_B1F_InscriptionCommon_5:
# 32 "data/maps/GraniteCave_B1F/scripts.pory"
	specialvar VAR_RESULT, FoundAllUnown
# 33 "data/maps/GraniteCave_B1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq GraniteCave_B1F_InscriptionCommon_8
GraniteCave_B1F_InscriptionCommon_7:
# 37 "data/maps/GraniteCave_B1F/scripts.pory"
	compare VAR_CHAMBER_OF_TRUTH_STATE, 1
	goto_if_eq GraniteCave_B1F_InscriptionCommon_10
	goto GraniteCave_B1F_InscriptionCommon_1

GraniteCave_B1F_InscriptionCommon_8:
# 34 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_EventScript_PlayerDecyphered
# 35 "data/maps/GraniteCave_B1F/scripts.pory"
	setvar VAR_CHAMBER_OF_TRUTH_STATE, 3
	goto GraniteCave_B1F_InscriptionCommon_7

GraniteCave_B1F_InscriptionCommon_10:
# 38 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_EventScript_PlayerDidntDecypher
# 39 "data/maps/GraniteCave_B1F/scripts.pory"
	setvar VAR_CHAMBER_OF_TRUTH_STATE, 2
	goto GraniteCave_B1F_InscriptionCommon_1


GraniteCave_B1F_EventScript_PlayerDecyphered:
# 79 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_EventScript_InscriptionGuyAsksWhatItSays
# 80 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_IsThatWhatItSays
# 81 "data/maps/GraniteCave_B1F/scripts.pory"
	waitmessage
# 82 "data/maps/GraniteCave_B1F/scripts.pory"
	playfanfare MUS_RG_POKE_FLUTE
# 83 "data/maps/GraniteCave_B1F/scripts.pory"
	waitfanfare
# 84 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
# 85 "data/maps/GraniteCave_B1F/scripts.pory"
	playmoncry SPECIES_TORNADUS, CRY_MODE_NORMAL
# 86 "data/maps/GraniteCave_B1F/scripts.pory"
	setvar VAR_0x8004, 1
# 87 "data/maps/GraniteCave_B1F/scripts.pory"
	setvar VAR_0x8005, 1
# 88 "data/maps/GraniteCave_B1F/scripts.pory"
	setvar VAR_0x8006, 8
# 89 "data/maps/GraniteCave_B1F/scripts.pory"
	setvar VAR_0x8007, 5
# 90 "data/maps/GraniteCave_B1F/scripts.pory"
	special ShakeCamera
# 91 "data/maps/GraniteCave_B1F/scripts.pory"
	waitstate
# 92 "data/maps/GraniteCave_B1F/scripts.pory"
	clearflag FLAG_HIDE_TORNADUS
# 93 "data/maps/GraniteCave_B1F/scripts.pory"
	clearflag FLAG_HIDE_LUGIA
# 94 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_WhatWasThat, MSGBOX_DEFAULT
# 95 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
# 96 "data/maps/GraniteCave_B1F/scripts.pory"
	giveitem ITEM_POKE_FLUTE
# 97 "data/maps/GraniteCave_B1F/scripts.pory"
	setflag FLAG_RECEIVED_FLUTE
# 98 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_ThankYou, MSGBOX_DEFAULT
# 99 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
# 100 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_InscriptionGuysGoesBack
	return


GraniteCave_B1F_EventScript_PlayerDidntDecypher:
# 104 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_EventScript_InscriptionGuyAsksWhatItSays
# 105 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_YouCantDecypher, MSGBOX_DEFAULT
# 106 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
# 107 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_InscriptionGuysGoesBack
	return


GraniteCave_B1F_EventScript_InscriptionGuyAsksWhatItSays:
# 111 "data/maps/GraniteCave_B1F/scripts.pory"
	switch VAR_TEMP_0
# 112 "data/maps/GraniteCave_B1F/scripts.pory"
	case 0, GraniteCave_B1F_EventScript_InscriptionGuyAsksWhatItSays_3
# 115 "data/maps/GraniteCave_B1F/scripts.pory"
	case 1, GraniteCave_B1F_EventScript_InscriptionGuyAsksWhatItSays_4
# 118 "data/maps/GraniteCave_B1F/scripts.pory"
	case 2, GraniteCave_B1F_EventScript_InscriptionGuyAsksWhatItSays_5
GraniteCave_B1F_EventScript_InscriptionGuyAsksWhatItSays_1:
# 122 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_WhatDoesItSay, MSGBOX_DEFAULT
# 123 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
# 124 "data/maps/GraniteCave_B1F/scripts.pory"
	applymovement LOCALID_PLAYER, GraniteCave_B1F_Movement_TurnToInscriptionGuy
# 125 "data/maps/GraniteCave_B1F/scripts.pory"
	waitmovement LOCALID_PLAYER
# 126 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_ThreeDots, MSGBOX_DEFAULT
# 127 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
	return

GraniteCave_B1F_EventScript_InscriptionGuyAsksWhatItSays_3:
# 113 "data/maps/GraniteCave_B1F/scripts.pory"
	applymovement LOCALID_INSCRIPTION_GUY, GraniteCave_B1F_Movement_WalkToPlayerAtLeft
# 114 "data/maps/GraniteCave_B1F/scripts.pory"
	waitmovement LOCALID_INSCRIPTION_GUY
	goto GraniteCave_B1F_EventScript_InscriptionGuyAsksWhatItSays_1

GraniteCave_B1F_EventScript_InscriptionGuyAsksWhatItSays_4:
# 116 "data/maps/GraniteCave_B1F/scripts.pory"
	applymovement LOCALID_INSCRIPTION_GUY, GraniteCave_B1F_Movement_WalkToPlayerAtMiddle
# 117 "data/maps/GraniteCave_B1F/scripts.pory"
	waitmovement LOCALID_INSCRIPTION_GUY
	goto GraniteCave_B1F_EventScript_InscriptionGuyAsksWhatItSays_1

GraniteCave_B1F_EventScript_InscriptionGuyAsksWhatItSays_5:
# 119 "data/maps/GraniteCave_B1F/scripts.pory"
	applymovement LOCALID_INSCRIPTION_GUY, GraniteCave_B1F_Movement_WalkToPlayerAtRight
# 120 "data/maps/GraniteCave_B1F/scripts.pory"
	waitmovement LOCALID_INSCRIPTION_GUY
	goto GraniteCave_B1F_EventScript_InscriptionGuyAsksWhatItSays_1


# 130 "data/maps/GraniteCave_B1F/scripts.pory"
GraniteCave_B1F_Movement_WalkToPlayerAtLeft:
# 131 "data/maps/GraniteCave_B1F/scripts.pory"
	walk_left
# 131 "data/maps/GraniteCave_B1F/scripts.pory"
	walk_left
# 132 "data/maps/GraniteCave_B1F/scripts.pory"
	walk_in_place_up
	step_end

# 135 "data/maps/GraniteCave_B1F/scripts.pory"
GraniteCave_B1F_Movement_WalkToPlayerAtMiddle:
# 136 "data/maps/GraniteCave_B1F/scripts.pory"
	walk_left
# 137 "data/maps/GraniteCave_B1F/scripts.pory"
	walk_in_place_up
	step_end

# 140 "data/maps/GraniteCave_B1F/scripts.pory"
GraniteCave_B1F_Movement_WalkToPlayerAtRight:
# 141 "data/maps/GraniteCave_B1F/scripts.pory"
	walk_in_place_up
	step_end

# 148 "data/maps/GraniteCave_B1F/scripts.pory"
GraniteCave_B1F_Movement_TurnToInscriptionGuy:
# 149 "data/maps/GraniteCave_B1F/scripts.pory"
	walk_in_place_down
	step_end

GraniteCave_B1F_InscriptionGuysGoesBack:
# 203 "data/maps/GraniteCave_B1F/scripts.pory"
	switch VAR_TEMP_0
# 204 "data/maps/GraniteCave_B1F/scripts.pory"
	case 0, GraniteCave_B1F_InscriptionGuysGoesBack_2
# 207 "data/maps/GraniteCave_B1F/scripts.pory"
	case 1, GraniteCave_B1F_InscriptionGuysGoesBack_3
# 210 "data/maps/GraniteCave_B1F/scripts.pory"
	case 2, GraniteCave_B1F_InscriptionGuysGoesBack_4
	return

GraniteCave_B1F_InscriptionGuysGoesBack_2:
# 205 "data/maps/GraniteCave_B1F/scripts.pory"
	applymovement LOCALID_INSCRIPTION_GUY, GraniteCave_B1F_Movement_WalkAwayFromPlayerFromLeft
# 206 "data/maps/GraniteCave_B1F/scripts.pory"
	waitmovement LOCALID_INSCRIPTION_GUY
	return

GraniteCave_B1F_InscriptionGuysGoesBack_3:
# 208 "data/maps/GraniteCave_B1F/scripts.pory"
	applymovement LOCALID_INSCRIPTION_GUY, GraniteCave_B1F_Movement_WalkAwayFromPlayerFromMiddle
# 209 "data/maps/GraniteCave_B1F/scripts.pory"
	waitmovement LOCALID_INSCRIPTION_GUY
	return

GraniteCave_B1F_InscriptionGuysGoesBack_4:
# 211 "data/maps/GraniteCave_B1F/scripts.pory"
	applymovement LOCALID_INSCRIPTION_GUY, GraniteCave_B1F_Movement_WalkAwayFromPlayerFromRight
# 212 "data/maps/GraniteCave_B1F/scripts.pory"
	waitmovement LOCALID_INSCRIPTION_GUY
	return


# 216 "data/maps/GraniteCave_B1F/scripts.pory"
GraniteCave_B1F_Movement_WalkAwayFromPlayerFromLeft:
# 217 "data/maps/GraniteCave_B1F/scripts.pory"
	walk_right
# 217 "data/maps/GraniteCave_B1F/scripts.pory"
	walk_right
# 218 "data/maps/GraniteCave_B1F/scripts.pory"
	walk_in_place_up
	step_end

# 221 "data/maps/GraniteCave_B1F/scripts.pory"
GraniteCave_B1F_Movement_WalkAwayFromPlayerFromMiddle:
# 222 "data/maps/GraniteCave_B1F/scripts.pory"
	walk_right
# 223 "data/maps/GraniteCave_B1F/scripts.pory"
	walk_in_place_up
	step_end

# 226 "data/maps/GraniteCave_B1F/scripts.pory"
GraniteCave_B1F_Movement_WalkAwayFromPlayerFromRight:
# 227 "data/maps/GraniteCave_B1F/scripts.pory"
	walk_in_place_down
# 228 "data/maps/GraniteCave_B1F/scripts.pory"
	face_up
	step_end

GraniteCave_B1F_EventScript_MeetInscriptionGuyFromWest::
# 232 "data/maps/GraniteCave_B1F/scripts.pory"
	lockall
# 233 "data/maps/GraniteCave_B1F/scripts.pory"
	applymovement LOCALID_INSCRIPTION_GUY, GraniteCave_B1F_Movement_TurnSurprisedWest
# 234 "data/maps/GraniteCave_B1F/scripts.pory"
	playse SE_PIN
# 235 "data/maps/GraniteCave_B1F/scripts.pory"
	waitmovement LOCALID_INSCRIPTION_GUY
# 236 "data/maps/GraniteCave_B1F/scripts.pory"
	waitse
# 237 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_EventScript_MeetInscriptionGuyCommon
# 238 "data/maps/GraniteCave_B1F/scripts.pory"
	releaseall
	return


GraniteCave_B1F_EventScript_MeetInscriptionGuyFromSouth::
# 242 "data/maps/GraniteCave_B1F/scripts.pory"
	lockall
# 243 "data/maps/GraniteCave_B1F/scripts.pory"
	applymovement LOCALID_INSCRIPTION_GUY, GraniteCave_B1F_Movement_TurnSurprisedSouth
# 244 "data/maps/GraniteCave_B1F/scripts.pory"
	playse SE_PIN
# 245 "data/maps/GraniteCave_B1F/scripts.pory"
	waitmovement LOCALID_INSCRIPTION_GUY
# 246 "data/maps/GraniteCave_B1F/scripts.pory"
	waitse
# 247 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_EventScript_MeetInscriptionGuyCommon
# 248 "data/maps/GraniteCave_B1F/scripts.pory"
	releaseall
	return


GraniteCave_B1F_EventScript_MeetInscriptionGuyCommon:
# 252 "data/maps/GraniteCave_B1F/scripts.pory"
	goto_if_set FLAG_SYS_USE_FLASH, GraniteCave_B1F_EventScript_MeetInscriptionGuyCommon_2
# 256 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_CanYouTurnOnTheLight, MSGBOX_DEFAULT
# 257 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
GraniteCave_B1F_EventScript_MeetInscriptionGuyCommon_1:
# 259 "data/maps/GraniteCave_B1F/scripts.pory"
	applymovement LOCALID_INSCRIPTION_GUY, GraniteCave_B1F_Movement_TurnBackNorth
# 260 "data/maps/GraniteCave_B1F/scripts.pory"
	waitmovement LOCALID_INSCRIPTION_GUY
# 261 "data/maps/GraniteCave_B1F/scripts.pory"
	setvar VAR_CHAMBER_OF_TRUTH_STATE, 1
	return

GraniteCave_B1F_EventScript_MeetInscriptionGuyCommon_2:
# 253 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_EventScript_ThankYouForTurningOnTheLight, MSGBOX_DEFAULT
# 254 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
	goto GraniteCave_B1F_EventScript_MeetInscriptionGuyCommon_1


# 264 "data/maps/GraniteCave_B1F/scripts.pory"
GraniteCave_B1F_Movement_TurnSurprisedWest:
# 265 "data/maps/GraniteCave_B1F/scripts.pory"
	face_left
# 266 "data/maps/GraniteCave_B1F/scripts.pory"
	emote_exclamation_mark
	step_end

# 269 "data/maps/GraniteCave_B1F/scripts.pory"
GraniteCave_B1F_Movement_TurnSurprisedSouth:
# 270 "data/maps/GraniteCave_B1F/scripts.pory"
	face_down
# 271 "data/maps/GraniteCave_B1F/scripts.pory"
	emote_exclamation_mark
	step_end

# 274 "data/maps/GraniteCave_B1F/scripts.pory"
GraniteCave_B1F_Movement_TurnBackNorth:
# 275 "data/maps/GraniteCave_B1F/scripts.pory"
	face_up
	step_end

GraniteCave_B1F_EventScript_InscriptionGuy::
# 297 "data/maps/GraniteCave_B1F/scripts.pory"
	lock
# 298 "data/maps/GraniteCave_B1F/scripts.pory"
	faceplayer
# 299 "data/maps/GraniteCave_B1F/scripts.pory"
	switch VAR_CHAMBER_OF_TRUTH_STATE
# 300 "data/maps/GraniteCave_B1F/scripts.pory"
	case 0, GraniteCave_B1F_EventScript_InscriptionGuy_3
# 302 "data/maps/GraniteCave_B1F/scripts.pory"
	case 1, GraniteCave_B1F_EventScript_InscriptionGuy_4
# 304 "data/maps/GraniteCave_B1F/scripts.pory"
	case 2, GraniteCave_B1F_EventScript_InscriptionGuy_5
# 306 "data/maps/GraniteCave_B1F/scripts.pory"
	case 3, GraniteCave_B1F_EventScript_InscriptionGuy_6
# 309 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_EventScript_InscriptionGuy_AfterTornadusBattle
GraniteCave_B1F_EventScript_InscriptionGuy_1:
# 311 "data/maps/GraniteCave_B1F/scripts.pory"
	release
	return

GraniteCave_B1F_EventScript_InscriptionGuy_3:
# 301 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_EventScript_InscriptionGuy_TryingToDecypher
	goto GraniteCave_B1F_EventScript_InscriptionGuy_1

GraniteCave_B1F_EventScript_InscriptionGuy_4:
# 303 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_EventScript_InscriptionGuy_TryingToDecypher
	goto GraniteCave_B1F_EventScript_InscriptionGuy_1

GraniteCave_B1F_EventScript_InscriptionGuy_5:
# 305 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_EventScript_InscriptionGuy_WaitingForPlayerToDecypher
	goto GraniteCave_B1F_EventScript_InscriptionGuy_1

GraniteCave_B1F_EventScript_InscriptionGuy_6:
# 307 "data/maps/GraniteCave_B1F/scripts.pory"
	call GraniteCave_B1F_EventScript_InscriptionGuy_PlayedFlute
	goto GraniteCave_B1F_EventScript_InscriptionGuy_1


GraniteCave_B1F_EventScript_InscriptionGuy_TryingToDecypher:
# 315 "data/maps/GraniteCave_B1F/scripts.pory"
	goto_if_set FLAG_SYS_USE_FLASH, GraniteCave_B1F_EventScript_InscriptionGuy_TryingToDecypher_2
# 319 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_ItsYouCanYouTurnTheLightOn, MSGBOX_DEFAULT
# 320 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
GraniteCave_B1F_EventScript_InscriptionGuy_TryingToDecypher_1:
# 322 "data/maps/GraniteCave_B1F/scripts.pory"
	applymovement LOCALID_INSCRIPTION_GUY, GraniteCave_B1F_Movement_TurnBackNorth
# 323 "data/maps/GraniteCave_B1F/scripts.pory"
	waitmovement LOCALID_INSCRIPTION_GUY
	return

GraniteCave_B1F_EventScript_InscriptionGuy_TryingToDecypher_2:
# 316 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_ICantUnderstandThisWriting, MSGBOX_DEFAULT
# 317 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
	goto GraniteCave_B1F_EventScript_InscriptionGuy_TryingToDecypher_1


GraniteCave_B1F_EventScript_InscriptionGuy_WaitingForPlayerToDecypher:
# 343 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_CountingOnYou, MSGBOX_DEFAULT
# 344 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
	return


GraniteCave_B1F_EventScript_InscriptionGuy_PlayedFlute:
# 361 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_TheFluteDidSomething, MSGBOX_DEFAULT
# 362 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
	return


GraniteCave_B1F_EventScript_InscriptionGuy_AfterTornadusBattle:
# 374 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_IWouldveNeverImagined, MSGBOX_DEFAULT
# 375 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
	return


GraniteCave_B1F_EventScript_BeastTamer::
# 391 "data/maps/GraniteCave_B1F/scripts.pory"
	trainerbattle_single TRAINER_BEAST_TAMER_XANTE, GraniteCave_B1F_Text_WhatAreYouDoingHere, GraniteCave_B1F_Text_IUnderstandWhy
# 392 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_SneaselRazorClaw, MSGBOX_AUTOCLOSE
	return


GraniteCave_B1F_Text_TooDark::
# 46 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "It's too dark to read anything.$"

GraniteCave_B1F_Text_UnownKingStory::
# 50 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "Some humans warred their own equals.\n"
	.string "Through the centuries, the wars never\l"
	.string "stopped.\p"
	.string "The destruction caused by those humans\n"
	.string "angered the Unown King, who succumbed\l"
	.string "to the same craze.\p"
	.string "It attempted to eradicate all humans.\p"
	.string "However, there existed humans who\n"
	.string "loathed bloodshed.\p"
	.string "The Unown King saw the kind,\n"
	.string "the poor, and the just\l"
	.string "and could not ignore what it saw.\p"
	.string "Unknowingly, the Unown King split in\n"
	.string "two halves: the Good and the Bad.\p"
	.string "The Good rejected the Bad's desire to\n"
	.string "exterminate all human beings.\p"
	.string "The two Kings clashed.\n"
	.string "The Good perished.\p"
	.string "The Bad, however, was weakened in the\n"
	.string "battle.\p"
	.string "It became weak enough\n"
	.string "for the innocent humans to conquer it\l"
	.string "and seal it into a temple,\l"
	.string "till the day when an unfazed soul\l"
	.string "may put it to rest for good.$"

GraniteCave_B1F_Text_WhatDoesItSay::
# 144 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "So, what does it say?$"

GraniteCave_B1F_Text_ThreeDots::
# 152 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "…$"

GraniteCave_B1F_Text_IsThatWhatItSays::
# 156 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "Really?\n"
	.string "Is that what it says?\p"
	.string "Wow, I… I'd never have thought that\n"
	.string "the Unown King's story would be so dark.\l"
	.string "I can hardly believe what you're\l"
	.string "telling me!\p"
	.string "So, this temple is some kind of prison\n"
	.string "for the Unown King, right?\l"
	.string "I mean, the “Bad King”.\p"
	.string "Well then, I suppose I must reward you\n"
	.string "for the trouble of decyphering\l"
	.string "the whole thing.\p"
	.string "I don't have much money to give you,\n"
	.string "but you can keep this flute.\l"
	.string "It's really valuable, I promise!\p"
	.string "Listen to its sound!$"

GraniteCave_B1F_Text_WhatWasThat::
# 175 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "…\p"
	.string "…\n"
	.string "What was that?\l"
	.string "Could it be… Did the flute do this?\p"
	.string "You know, the song I played…\n"
	.string "It's the Melody of Awakening.\l"
	.string "It's supposed to wake up whoever has\l"
	.string "fallen asleep.\p"
	.string "I really hope I didn't cause anything\n"
	.string "serious…\p"
	.string "Anyway, you can keep the flute.\n"
	.string "Hold on, I'll clean it for you.$"

GraniteCave_B1F_Text_ThankYou::
# 190 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "Thank you for helping me out.\n"
	.string "I really appreciate it!$"

GraniteCave_B1F_Text_YouCantDecypher::
# 195 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "You can't decypher it completely, huh?\p"
	.string "I see.\p"
	.string "If you manage to decypher more parts\n"
	.string "of it, let me know!$"

GraniteCave_B1F_Text_CanYouTurnOnTheLight::
# 278 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "Hey, you!\n"
	.string "Would you mind lighting up this place?\p"
	.string "I'm trying to read the inscription on\n"
	.string "this wall, but it's too dark!\l"
	.string "I can barely see it!$"

GraniteCave_B1F_EventScript_ThankYouForTurningOnTheLight::
# 286 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "Hey, you!\n"
	.string "Thank you for brightening up this room.\p"
	.string "I'm trying to read the inscription on\n"
	.string "this wall, but I could barely see it\l"
	.string "in the dark.\p"
	.string "Not that it matters, because I don't\n"
	.string "understand a thing!$"

GraniteCave_B1F_Text_ItsYouCanYouTurnTheLightOn::
# 326 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "Oh, it's you!\p"
	.string "Could you make it a bit brighter\n"
	.string "for me?$"

GraniteCave_B1F_Text_ICantUnderstandThisWriting::
# 332 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "Oh… Er…\p"
	.string "I have no clue what this writing is\n"
	.string "saying!\p"
	.string "But according to the Maidens, it should\n"
	.string "tell crucial information about the tale\l"
	.string "of the Unown King.\p"
	.string "Would you help me decypher it?$"

GraniteCave_B1F_Text_CountingOnYou::
# 347 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "With your help, I'm sure I can finally\n"
	.string "read the inscription on this wall.\p"
	.string "I'm counting on you!\p"
	.string "If you manage to decipher the whole\n"
	.string "thing, I'll give you something cool\l"
	.string "in return: my flute!\p"
	.string "Hey, don't give me that look!\n"
	.string "It's very valuable!\p"
	.string "Yes, I'll clean it before giving it\n"
	.string "to you.$"

GraniteCave_B1F_Text_TheFluteDidSomething::
# 365 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "Er…\n"
	.string "I think the Melody of Awakening did\l"
	.string "something.\p"
	.string "I don't know what happened, let's hope\n"
	.string "everything will be alright!$"

GraniteCave_B1F_Text_IWouldveNeverImagined::
# 378 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "I would've never imagined that the tale\n"
	.string "of the Unown King would take a turn\l"
	.string "like that.\p"
	.string "What I'm getting is that\n"
	.string "it turned evil, but half of it\l"
	.string "separated from its body and stayed\l"
	.string "good.\p"
	.string "Should we perhaps… defeat the evil half\n"
	.string "once and for all?$"

GraniteCave_B1F_Text_WhatAreYouDoingHere::
# 395 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "What are you doing here? It's dangerous!\n"
	.string "Dangerous because of me!$"

GraniteCave_B1F_Text_IUnderstandWhy::
# 400 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "I understand why you weren't afraid!$"

GraniteCave_B1F_Text_SneaselRazorClaw::
# 404 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "Some wild Sneasel hold a Razor Claw.\n"
	.string "It helps them evolve.\p"
	.string "I'm pretty sure wild Axew can hold them\n"
	.string "too.$"
