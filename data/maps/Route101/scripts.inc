Route101_MapScripts::
# 2 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_EventScript_OnTransition
# 3 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route101_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 7 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route101_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 4 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_INTRO_AREA_STATE, 0, Route101_EventScript_FacePlayerNorth
# 5 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_INTRO_AREA_STATE, 2, Route101_EventScript_FacePlayerSouth
	.2byte 0

Route101_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 8 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_INTRO_AREA_STATE, 0, Route101_EventScript_PlayIntroFollowUp
# 9 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_INTRO_AREA_STATE, 2, Route101_EventScript_Ending
	.2byte 0


Route101_EventScript_OnTransition::
# 14 "data/maps/Route101/scripts.pory"
	setrespawn HEAL_LOCATION_ROUTE101
# 15 "data/maps/Route101/scripts.pory"
	compare VAR_INTRO_AREA_STATE, 2
	goto_if_eq Route101_EventScript_OnTransition_1
	return

Route101_EventScript_OnTransition_1:
# 16 "data/maps/Route101/scripts.pory"
	setflag FLAG_TEMP_1
# 17 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return


Route101_EventScript_FacePlayerNorth::
# 22 "data/maps/Route101/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	return


Route101_EventScript_FacePlayerSouth::
# 26 "data/maps/Route101/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
	return


Route101_EventScript_PlayIntroFollowUp::
# 30 "data/maps/Route101/scripts.pory"
	lockall
# 31 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_RestOfTheStory, MSGBOX_DEFAULT
# 32 "data/maps/Route101/scripts.pory"
	closemessage
# 33 "data/maps/Route101/scripts.pory"
	special ChooseStarter
# 34 "data/maps/Route101/scripts.pory"
	waitstate
# 35 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_ThereAre26Unown, MSGBOX_DEFAULT
# 36 "data/maps/Route101/scripts.pory"
	closemessage
# 37 "data/maps/Route101/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 39 "data/maps/Route101/scripts.pory"
	setvar VAR_INTRO_AREA_STATE, 1
# 40 "data/maps/Route101/scripts.pory"
	releaseall
	return


Route101_EventScript_GiveEmergencyMon::
# 60 "data/maps/Route101/scripts.pory"
	lock
# 61 "data/maps/Route101/scripts.pory"
	faceplayer
# 62 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_TakeThisMon, MSGBOX_DEFAULT
# 63 "data/maps/Route101/scripts.pory"
	closemessage
# 64 "data/maps/Route101/scripts.pory"
	givemon SPECIES_GYARADOS, 25
# 65 "data/maps/Route101/scripts.pory"
	release
	return


Route101_EventScript_CannotLeave::
# 75 "data/maps/Route101/scripts.pory"
	lockall
# 76 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_CannotLeave, MSGBOX_DEFAULT
# 77 "data/maps/Route101/scripts.pory"
	closemessage
# 78 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_WalkUp2
# 79 "data/maps/Route101/scripts.pory"
	waitmovement LOCALID_PLAYER
# 80 "data/maps/Route101/scripts.pory"
	releaseall
	return


# 87 "data/maps/Route101/scripts.pory"
Route101_Movement_WalkUp2:
# 88 "data/maps/Route101/scripts.pory"
	walk_up
# 88 "data/maps/Route101/scripts.pory"
	walk_up
	step_end

Route101_EventScript_MoveRelearner::
# 92 "data/maps/Route101/scripts.pory"
	lockall
# 93 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_MOVE_REMINDER, Common_Movement_FacePlayer
# 94 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WantToRelearnMove, MSGBOX_YESNO
# 95 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route101_EventScript_MoveRelearner_2
# 127 "data/maps/Route101/scripts.pory"
	closemessage
Route101_EventScript_MoveRelearner_1:
# 129 "data/maps/Route101/scripts.pory"
	releaseall
	return

Route101_EventScript_MoveRelearner_2:
# 96 "data/maps/Route101/scripts.pory"
	closemessage
# 97 "data/maps/Route101/scripts.pory"
	special ChooseMonForMoveRelearner
# 98 "data/maps/Route101/scripts.pory"
	waitstate
# 99 "data/maps/Route101/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_ne Route101_EventScript_MoveRelearner_5
# 123 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_ComeBackAtAnyTime, MSGBOX_DEFAULT
# 124 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1

Route101_EventScript_MoveRelearner_5:
# 100 "data/maps/Route101/scripts.pory"
	special IsSelectedMonEgg
# 101 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Route101_EventScript_MoveRelearner_8
# 105 "data/maps/Route101/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq Route101_EventScript_MoveRelearner_11
# 109 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WhichMove, MSGBOX_DEFAULT
# 110 "data/maps/Route101/scripts.pory"
	closemessage
# 111 "data/maps/Route101/scripts.pory"
	special TeachMoveRelearnerMove
# 112 "data/maps/Route101/scripts.pory"
	waitstate
# 113 "data/maps/Route101/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Route101_EventScript_MoveRelearner_14
# 117 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DoneComeBackAtAnyTime, MSGBOX_DEFAULT
# 118 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1

Route101_EventScript_MoveRelearner_8:
# 102 "data/maps/Route101/scripts.pory"
	msgbox Route101_ThatIsAnEgg, MSGBOX_DEFAULT
# 103 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1

Route101_EventScript_MoveRelearner_11:
# 106 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_CantTeachAnyMoves, MSGBOX_DEFAULT
# 107 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1

Route101_EventScript_MoveRelearner_14:
# 114 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_ComeBackAtAnyTime, MSGBOX_DEFAULT
# 115 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1


Route101_EventScript_Ending::
# 167 "data/maps/Route101/scripts.pory"
	lockall
# 169 "data/maps/Route101/scripts.pory"
	setvar VAR_INTRO_AREA_STATE, 1
# 170 "data/maps/Route101/scripts.pory"
	special HealPlayerParty
# 171 "data/maps/Route101/scripts.pory"
	message Route101_Text_UnownKingWasDefeated
# 172 "data/maps/Route101/scripts.pory"
	delay 90
# 173 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_EndingWalk
# 174 "data/maps/Route101/scripts.pory"
	waitmessage
# 175 "data/maps/Route101/scripts.pory"
	waitbuttonpress
# 176 "data/maps/Route101/scripts.pory"
	closemessage
# 177 "data/maps/Route101/scripts.pory"
	delay 60
# 178 "data/maps/Route101/scripts.pory"
	waitmovement LOCALID_PLAYER
# 179 "data/maps/Route101/scripts.pory"
	clearflag FLAG_TEMP_1
# 180 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_UnownKingNeverSucceeded, MSGBOX_DEFAULT
# 181 "data/maps/Route101/scripts.pory"
	closemessage
# 182 "data/maps/Route101/scripts.pory"
	delay 30
# 183 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WeHopeYouEnjoyed, MSGBOX_DEFAULT
# 184 "data/maps/Route101/scripts.pory"
	closemessage
# 185 "data/maps/Route101/scripts.pory"
	call Common_EventScript_SaveGame
# 186 "data/maps/Route101/scripts.pory"
	closemessage
# 187 "data/maps/Route101/scripts.pory"
	delay 30
# 188 "data/maps/Route101/scripts.pory"
	call Route101_EventScript_EndingFly
	return


# 225 "data/maps/Route101/scripts.pory"
Route101_Movement_EndingWalk:
# 226 "data/maps/Route101/scripts.pory"
	walk_down
# 226 "data/maps/Route101/scripts.pory"
	walk_down
# 226 "data/maps/Route101/scripts.pory"
	walk_down
# 226 "data/maps/Route101/scripts.pory"
	walk_down
# 226 "data/maps/Route101/scripts.pory"
	walk_down
# 226 "data/maps/Route101/scripts.pory"
	walk_down
# 226 "data/maps/Route101/scripts.pory"
	walk_down
# 226 "data/maps/Route101/scripts.pory"
	walk_down
# 226 "data/maps/Route101/scripts.pory"
	walk_down
# 226 "data/maps/Route101/scripts.pory"
	walk_down
# 226 "data/maps/Route101/scripts.pory"
	walk_down
# 226 "data/maps/Route101/scripts.pory"
	walk_down
# 226 "data/maps/Route101/scripts.pory"
	walk_down
# 226 "data/maps/Route101/scripts.pory"
	walk_down
	step_end

Route101_EventScript_EndingFly:
# 230 "data/maps/Route101/scripts.pory"
	checkpartymove MOVE_FLY
# 231 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq Route101_EventScript_EndingFly_1
# 239 "data/maps/Route101/scripts.pory"
	call Route101_EventScript_FlyReboot
	return

Route101_EventScript_EndingFly_1:
# 232 "data/maps/Route101/scripts.pory"
	checkpartylearnable MOVE_FLY
# 233 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq Route101_EventScript_EndingFly_4
# 236 "data/maps/Route101/scripts.pory"
	call Route101_EventScript_FlyReboot
	return

Route101_EventScript_EndingFly_4:
# 234 "data/maps/Route101/scripts.pory"
	call Route101_EventScript_BoringReboot
	return


Route101_EventScript_BoringReboot:
# 244 "data/maps/Route101/scripts.pory"
	fadescreen FADE_TO_BLACK
# 245 "data/maps/Route101/scripts.pory"
	special DoSoftReset
	return


Route101_EventScript_FlyReboot:
# 249 "data/maps/Route101/scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 250 "data/maps/Route101/scripts.pory"
	dofieldeffect FLDEFF_USE_FLY
# 251 "data/maps/Route101/scripts.pory"
	delay 300
# 252 "data/maps/Route101/scripts.pory"
	fadeoutbgm 0
# 254 "data/maps/Route101/scripts.pory"
	special DoSoftReset
	return


Route101_Text_RestOfTheStory::
# 43 "data/maps/Route101/scripts.pory"
	.string "The rest of this story is for you\n"
	.string "to uncover.\p"
	.string "The Unown King has been confined\n"
	.string "inside the Temple of the Unown King.\p"
	.string "But first, you will need a companion.$"

Route101_Text_ThereAre26Unown::
# 51 "data/maps/Route101/scripts.pory"
	.string "There are 26 Unown specimen\n"
	.string "hiding in the Temple.\l"
	.string "They will help you decrypt messages\l"
	.string "written in an unintelligible script.\p"
	.string "Find them all!$"

Route101_Text_TakeThisMon::
# 69 "data/maps/Route101/scripts.pory"
	.string "You don't have a Pokémon\n"
	.string "with you. Take this.$"

Route101_Text_CannotLeave::
# 83 "data/maps/Route101/scripts.pory"
	.string "You cannot leave this area.$"

Route101_Text_WantToRelearnMove::
# 132 "data/maps/Route101/scripts.pory"
	.string "Hi! I'm an expert in moves that\n"
	.string "Pokémon can learn.\p"
	.string "If you need to, I can help your Pokémon\n"
	.string "remember a move that they forgot.\l"
	.string "Don't worry, the service is free.\n"
	.string "of charge. Wanna try?$"

Route101_ThatIsAnEgg::
# 141 "data/maps/Route101/scripts.pory"
	.string "That… is an egg.\n"
	.string "Let it hatch first!$"

Route101_Text_CantTeachAnyMoves::
# 146 "data/maps/Route101/scripts.pory"
	.string "Oh… I'm sorry, this Pokémon already\n"
	.string "knows every move that it has tried\l"
	.string "to learn. Come back when it's grown\l"
	.string "stronger!$"

Route101_Text_WhichMove::
# 153 "data/maps/Route101/scripts.pory"
	.string "Okay, which move should I teach it?$"

Route101_Text_ComeBackAtAnyTime::
# 157 "data/maps/Route101/scripts.pory"
	.string "Come back at any time!$"

Route101_Text_DoneComeBackAtAnyTime::
# 161 "data/maps/Route101/scripts.pory"
	.string "There we go!\n"
	.string "Come back at any time!$"

Route101_Text_UnownKingWasDefeated::
# 191 "data/maps/Route101/scripts.pory"
	.string "{PLAYER} and the Unown that {PLAYER}\n"
	.string "had collected managed to seal\l"
	.string "the Unown King back into the altair\l"
	.string "which it had broken free from.\p"
	.string "But is it truly how this story ends?\n"
	.string "Did these events really happen?\p"
	.string "Other sources claim that the Unown King\n"
	.string "vanished for eternity.\p"
	.string "Alas, the truth in the matter will\n"
	.string "remain fuzzy for a long time,\l"
	.string "possibly forever.$"

Route101_Text_UnownKingNeverSucceeded::
# 205 "data/maps/Route101/scripts.pory"
	.string "One thing is for sure: the Unown King\n"
	.string "never stopped the human race from\l"
	.string "prosperating. The only ones who can\l"
	.string "do that -let's hope they won't- are\l"
	.string "humans themselves.$"

Route101_Text_WeHopeYouEnjoyed::
# 213 "data/maps/Route101/scripts.pory"
	.string "{COLOR GREEN}We hope you enjoyed your time playing\n"
	.string "Pokémon - The Unown King.\p"
	.string "This ROM-hack is a submission for the\n"
	.string "{FONT_NARROW}2nd Team Aqua's Rom-Hacking Competition\l"
	.string "{FONT_NORMAL}(TARC2).\p"
	.string "If you wish to see all of the content\n"
	.string "that didn't make the cut due to\l"
	.string "time constraints, look forward to\l"
	.string "the definitive version!$"
