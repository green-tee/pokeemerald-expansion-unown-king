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
# 10 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_OUTDOOR_TORNADUS_STATE, 1, Route101_EventScript_WildTornadusEncounter
	.2byte 0


Route101_EventScript_OnTransition::
# 15 "data/maps/Route101/scripts.pory"
	setrespawn HEAL_LOCATION_ROUTE101
# 16 "data/maps/Route101/scripts.pory"
	compare VAR_INTRO_AREA_STATE, 2
	goto_if_eq Route101_EventScript_OnTransition_1
	return

Route101_EventScript_OnTransition_1:
# 17 "data/maps/Route101/scripts.pory"
	setflag FLAG_TEMP_1
# 18 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return


Route101_EventScript_FacePlayerNorth::
# 23 "data/maps/Route101/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	return


Route101_EventScript_FacePlayerSouth::
# 27 "data/maps/Route101/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
	return


Route101_EventScript_PlayIntroFollowUp::
# 31 "data/maps/Route101/scripts.pory"
	lockall
# 32 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_RestOfTheStory, MSGBOX_DEFAULT
# 33 "data/maps/Route101/scripts.pory"
	closemessage
# 34 "data/maps/Route101/scripts.pory"
	special ChooseStarter
# 35 "data/maps/Route101/scripts.pory"
	waitstate
# 36 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_ThereAre26Unown, MSGBOX_DEFAULT
# 37 "data/maps/Route101/scripts.pory"
	closemessage
# 38 "data/maps/Route101/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 39 "data/maps/Route101/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 40 "data/maps/Route101/scripts.pory"
	setvar VAR_INTRO_AREA_STATE, 1
# 41 "data/maps/Route101/scripts.pory"
	releaseall
	return


Route101_EventScript_GiveEmergencyMon::
# 61 "data/maps/Route101/scripts.pory"
	lock
# 62 "data/maps/Route101/scripts.pory"
	faceplayer
# 63 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_TakeThisMon, MSGBOX_DEFAULT
# 64 "data/maps/Route101/scripts.pory"
	closemessage
# 65 "data/maps/Route101/scripts.pory"
	givemon SPECIES_GYARADOS, 25
# 66 "data/maps/Route101/scripts.pory"
	release
	return


Route101_EventScript_CannotLeave::
# 76 "data/maps/Route101/scripts.pory"
	lockall
# 77 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_CannotLeave, MSGBOX_DEFAULT
# 78 "data/maps/Route101/scripts.pory"
	closemessage
# 79 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_WalkUp2
# 80 "data/maps/Route101/scripts.pory"
	waitmovement LOCALID_PLAYER
# 81 "data/maps/Route101/scripts.pory"
	releaseall
	return


# 88 "data/maps/Route101/scripts.pory"
Route101_Movement_WalkUp2:
# 89 "data/maps/Route101/scripts.pory"
	walk_up
# 89 "data/maps/Route101/scripts.pory"
	walk_up
	step_end

Route101_EventScript_MoveRelearner::
# 93 "data/maps/Route101/scripts.pory"
	lockall
# 94 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_MOVE_REMINDER, Common_Movement_FacePlayer
# 95 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WantToRelearnMove, MSGBOX_YESNO
# 96 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route101_EventScript_MoveRelearner_2
# 128 "data/maps/Route101/scripts.pory"
	closemessage
Route101_EventScript_MoveRelearner_1:
# 130 "data/maps/Route101/scripts.pory"
	releaseall
	return

Route101_EventScript_MoveRelearner_2:
# 97 "data/maps/Route101/scripts.pory"
	closemessage
# 98 "data/maps/Route101/scripts.pory"
	special ChooseMonForMoveRelearner
# 99 "data/maps/Route101/scripts.pory"
	waitstate
# 100 "data/maps/Route101/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_ne Route101_EventScript_MoveRelearner_5
# 124 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_ComeBackAtAnyTime, MSGBOX_DEFAULT
# 125 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1

Route101_EventScript_MoveRelearner_5:
# 101 "data/maps/Route101/scripts.pory"
	special IsSelectedMonEgg
# 102 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Route101_EventScript_MoveRelearner_8
# 106 "data/maps/Route101/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq Route101_EventScript_MoveRelearner_11
# 110 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WhichMove, MSGBOX_DEFAULT
# 111 "data/maps/Route101/scripts.pory"
	closemessage
# 112 "data/maps/Route101/scripts.pory"
	special TeachMoveRelearnerMove
# 113 "data/maps/Route101/scripts.pory"
	waitstate
# 114 "data/maps/Route101/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Route101_EventScript_MoveRelearner_14
# 118 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DoneComeBackAtAnyTime, MSGBOX_DEFAULT
# 119 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1

Route101_EventScript_MoveRelearner_8:
# 103 "data/maps/Route101/scripts.pory"
	msgbox Route101_ThatIsAnEgg, MSGBOX_DEFAULT
# 104 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1

Route101_EventScript_MoveRelearner_11:
# 107 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_CantTeachAnyMoves, MSGBOX_DEFAULT
# 108 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1

Route101_EventScript_MoveRelearner_14:
# 115 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_ComeBackAtAnyTime, MSGBOX_DEFAULT
# 116 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1


Route101_EventScript_Ending::
# 168 "data/maps/Route101/scripts.pory"
	lockall
# 170 "data/maps/Route101/scripts.pory"
	setvar VAR_INTRO_AREA_STATE, 1
# 171 "data/maps/Route101/scripts.pory"
	special HealPlayerParty
# 172 "data/maps/Route101/scripts.pory"
	message Route101_Text_UnownKingWasDefeated
# 173 "data/maps/Route101/scripts.pory"
	delay 90
# 174 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_EndingWalk
# 175 "data/maps/Route101/scripts.pory"
	waitmessage
# 176 "data/maps/Route101/scripts.pory"
	waitbuttonpress
# 177 "data/maps/Route101/scripts.pory"
	closemessage
# 178 "data/maps/Route101/scripts.pory"
	delay 60
# 179 "data/maps/Route101/scripts.pory"
	waitmovement LOCALID_PLAYER
# 180 "data/maps/Route101/scripts.pory"
	clearflag FLAG_TEMP_1
# 181 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_UnownKingNeverSucceeded, MSGBOX_DEFAULT
# 182 "data/maps/Route101/scripts.pory"
	closemessage
# 183 "data/maps/Route101/scripts.pory"
	delay 30
# 184 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WeHopeYouEnjoyed, MSGBOX_DEFAULT
# 185 "data/maps/Route101/scripts.pory"
	closemessage
# 186 "data/maps/Route101/scripts.pory"
	call Common_EventScript_SaveGame
# 187 "data/maps/Route101/scripts.pory"
	closemessage
# 188 "data/maps/Route101/scripts.pory"
	delay 30
# 189 "data/maps/Route101/scripts.pory"
	call Route101_EventScript_EndingFly
	return


# 226 "data/maps/Route101/scripts.pory"
Route101_Movement_EndingWalk:
# 227 "data/maps/Route101/scripts.pory"
	walk_down
# 227 "data/maps/Route101/scripts.pory"
	walk_down
# 227 "data/maps/Route101/scripts.pory"
	walk_down
# 227 "data/maps/Route101/scripts.pory"
	walk_down
# 227 "data/maps/Route101/scripts.pory"
	walk_down
# 227 "data/maps/Route101/scripts.pory"
	walk_down
# 227 "data/maps/Route101/scripts.pory"
	walk_down
# 227 "data/maps/Route101/scripts.pory"
	walk_down
# 227 "data/maps/Route101/scripts.pory"
	walk_down
# 227 "data/maps/Route101/scripts.pory"
	walk_down
# 227 "data/maps/Route101/scripts.pory"
	walk_down
# 227 "data/maps/Route101/scripts.pory"
	walk_down
# 227 "data/maps/Route101/scripts.pory"
	walk_down
# 227 "data/maps/Route101/scripts.pory"
	walk_down
	step_end

Route101_EventScript_EndingFly:
# 231 "data/maps/Route101/scripts.pory"
	checkpartymove MOVE_FLY
# 232 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq Route101_EventScript_EndingFly_1
# 240 "data/maps/Route101/scripts.pory"
	call Route101_EventScript_FlyReboot
	return

Route101_EventScript_EndingFly_1:
# 233 "data/maps/Route101/scripts.pory"
	checkpartylearnable MOVE_FLY
# 234 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq Route101_EventScript_EndingFly_4
# 237 "data/maps/Route101/scripts.pory"
	call Route101_EventScript_FlyReboot
	return

Route101_EventScript_EndingFly_4:
# 235 "data/maps/Route101/scripts.pory"
	call Route101_EventScript_BoringReboot
	return


Route101_EventScript_BoringReboot:
# 245 "data/maps/Route101/scripts.pory"
	fadescreen FADE_TO_BLACK
# 246 "data/maps/Route101/scripts.pory"
	special DoSoftReset
	return


Route101_EventScript_FlyReboot:
# 250 "data/maps/Route101/scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 251 "data/maps/Route101/scripts.pory"
	dofieldeffect FLDEFF_USE_FLY
# 252 "data/maps/Route101/scripts.pory"
	delay 300
# 253 "data/maps/Route101/scripts.pory"
	fadeoutbgm 0
# 255 "data/maps/Route101/scripts.pory"
	special DoSoftReset
	return


Route101_EventScript_WildTornadusEncounter::
# 260 "data/maps/Route101/scripts.pory"
	lockall
# 261 "data/maps/Route101/scripts.pory"
	setvar VAR_OUTDOOR_TORNADUS_STATE, 0
# 262 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_SomethingFeelsOff, MSGBOX_DEFAULT
# 263 "data/maps/Route101/scripts.pory"
	closemessage
# 264 "data/maps/Route101/scripts.pory"
	playmoncry SPECIES_TORNADUS_THERIAN, CRY_MODE_NORMAL
# 265 "data/maps/Route101/scripts.pory"
	waitmoncry
# 266 "data/maps/Route101/scripts.pory"
	setwildbattle SPECIES_TORNADUS_THERIAN, 55
# 267 "data/maps/Route101/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 268 "data/maps/Route101/scripts.pory"
	waitstate
# 269 "data/maps/Route101/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 270 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Route101_EventScript_WildTornadusEncounter_2
Route101_EventScript_WildTornadusEncounter_1:
# 273 "data/maps/Route101/scripts.pory"
	releaseall
	return

Route101_EventScript_WildTornadusEncounter_2:
# 271 "data/maps/Route101/scripts.pory"
	setflag FLAG_CAUGHT_TORNADUS
	goto Route101_EventScript_WildTornadusEncounter_1


Route101_Text_RestOfTheStory::
# 44 "data/maps/Route101/scripts.pory"
	.string "The rest of this story is for you\n"
	.string "to uncover.\p"
	.string "The Unown King has been confined\n"
	.string "inside the Temple of the Unown King.\p"
	.string "But first, you will need a companion.$"

Route101_Text_ThereAre26Unown::
# 52 "data/maps/Route101/scripts.pory"
	.string "There are 26 Unown specimen\n"
	.string "hiding in the Temple.\l"
	.string "They will help you decrypt messages\l"
	.string "written in an unintelligible script.\p"
	.string "Find them all!$"

Route101_Text_TakeThisMon::
# 70 "data/maps/Route101/scripts.pory"
	.string "You don't have a Pokémon\n"
	.string "with you. Take this.$"

Route101_Text_CannotLeave::
# 84 "data/maps/Route101/scripts.pory"
	.string "You cannot leave this area.$"

Route101_Text_WantToRelearnMove::
# 133 "data/maps/Route101/scripts.pory"
	.string "Hi! I'm an expert in moves that\n"
	.string "Pokémon can learn.\p"
	.string "If you need to, I can help your Pokémon\n"
	.string "remember a move that they forgot.\l"
	.string "Don't worry, the service is free.\n"
	.string "of charge. Wanna try?$"

Route101_ThatIsAnEgg::
# 142 "data/maps/Route101/scripts.pory"
	.string "That… is an egg.\n"
	.string "Let it hatch first!$"

Route101_Text_CantTeachAnyMoves::
# 147 "data/maps/Route101/scripts.pory"
	.string "Oh… I'm sorry, this Pokémon already\n"
	.string "knows every move that it has tried\l"
	.string "to learn. Come back when it's grown\l"
	.string "stronger!$"

Route101_Text_WhichMove::
# 154 "data/maps/Route101/scripts.pory"
	.string "Okay, which move should I teach it?$"

Route101_Text_ComeBackAtAnyTime::
# 158 "data/maps/Route101/scripts.pory"
	.string "Come back at any time!$"

Route101_Text_DoneComeBackAtAnyTime::
# 162 "data/maps/Route101/scripts.pory"
	.string "There we go!\n"
	.string "Come back at any time!$"

Route101_Text_UnownKingWasDefeated::
# 192 "data/maps/Route101/scripts.pory"
	.string "{PLAYER} and the Unown that {PLAYER}\n"
	.string "had collected managed to seal\l"
	.string "the Unown King back into the altar\l"
	.string "which it had broken free from.\p"
	.string "But is it truly how this story ends?\n"
	.string "Did these events really happen?\p"
	.string "Other sources claim that the Unown King\n"
	.string "vanished for eternity.\p"
	.string "Alas, the truth in the matter will\n"
	.string "remain fuzzy for a long time,\l"
	.string "possibly forever.$"

Route101_Text_UnownKingNeverSucceeded::
# 206 "data/maps/Route101/scripts.pory"
	.string "One thing is for sure: the Unown King\n"
	.string "never stopped the human race from\l"
	.string "prosperating. The only ones who can\l"
	.string "do that -let's hope they won't- are\l"
	.string "humans themselves.$"

Route101_Text_WeHopeYouEnjoyed::
# 214 "data/maps/Route101/scripts.pory"
	.string "{COLOR GREEN}We hope you enjoyed your time playing\n"
	.string "Pokémon - The Unown King.\p"
	.string "This ROM-hack is a submission for the\n"
	.string "{FONT_NARROW}2nd Team Aqua's Rom-Hacking Competition\l"
	.string "{FONT_NORMAL}(TARC2).\p"
	.string "If you wish to see all of the content\n"
	.string "that didn't make the cut due to\l"
	.string "time constraints, look forward to\l"
	.string "the definitive version!$"

Route101_Text_SomethingFeelsOff::
# 276 "data/maps/Route101/scripts.pory"
	.string "…\p"
	.string "Something feels off…$"
