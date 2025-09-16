Route101_MapScripts::
# 2 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_EventScript_OnTransition
# 3 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route101_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 6 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route101_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 4 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_INTRO_AREA_STATE, 0, Route101_EventScript_FacePlayerNorth
	.2byte 0

Route101_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_INTRO_AREA_STATE, 0, Route101_EventScript_PlayIntroFollowUp
	.2byte 0


Route101_EventScript_OnTransition::
# 12 "data/maps/Route101/scripts.pory"
	setrespawn HEAL_LOCATION_ROUTE101
	return


Route101_EventScript_FacePlayerNorth::
# 16 "data/maps/Route101/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	return


Route101_EventScript_PlayIntroFollowUp::
# 20 "data/maps/Route101/scripts.pory"
	lockall
# 21 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_RestOfTheStory, MSGBOX_DEFAULT
# 22 "data/maps/Route101/scripts.pory"
	closemessage
# 23 "data/maps/Route101/scripts.pory"
	special ChooseStarter
# 24 "data/maps/Route101/scripts.pory"
	waitstate
# 25 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_ThereAre26Unown, MSGBOX_DEFAULT
# 26 "data/maps/Route101/scripts.pory"
	closemessage
# 27 "data/maps/Route101/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 28 "data/maps/Route101/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 29 "data/maps/Route101/scripts.pory"
	setvar VAR_INTRO_AREA_STATE, 1
# 30 "data/maps/Route101/scripts.pory"
	releaseall
	return


Route101_EventScript_GiveEmergencyMon::
# 50 "data/maps/Route101/scripts.pory"
	lock
# 51 "data/maps/Route101/scripts.pory"
	faceplayer
# 52 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_TakeThisMon, MSGBOX_DEFAULT
# 53 "data/maps/Route101/scripts.pory"
	closemessage
# 54 "data/maps/Route101/scripts.pory"
	givemon SPECIES_GYARADOS, 25
# 55 "data/maps/Route101/scripts.pory"
	release
	return


Route101_EventScript_CannotLeave::
# 65 "data/maps/Route101/scripts.pory"
	lockall
# 66 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_CannotLeave, MSGBOX_DEFAULT
# 67 "data/maps/Route101/scripts.pory"
	closemessage
# 68 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_WalkUp2
# 69 "data/maps/Route101/scripts.pory"
	waitmovement LOCALID_PLAYER
# 70 "data/maps/Route101/scripts.pory"
	releaseall
	return


# 77 "data/maps/Route101/scripts.pory"
Route101_Movement_WalkUp2:
# 78 "data/maps/Route101/scripts.pory"
	walk_up
# 78 "data/maps/Route101/scripts.pory"
	walk_up
	step_end

Route101_EventScript_MoveRelearner::
# 82 "data/maps/Route101/scripts.pory"
	lockall
# 83 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_MOVE_REMINDER, Common_Movement_FacePlayer
# 84 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WantToRelearnMove, MSGBOX_YESNO
# 85 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route101_EventScript_MoveRelearner_2
# 117 "data/maps/Route101/scripts.pory"
	closemessage
Route101_EventScript_MoveRelearner_1:
# 119 "data/maps/Route101/scripts.pory"
	releaseall
	return

Route101_EventScript_MoveRelearner_2:
# 86 "data/maps/Route101/scripts.pory"
	closemessage
# 87 "data/maps/Route101/scripts.pory"
	special ChooseMonForMoveRelearner
# 88 "data/maps/Route101/scripts.pory"
	waitstate
# 89 "data/maps/Route101/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_ne Route101_EventScript_MoveRelearner_5
# 113 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_ComeBackAtAnyTime, MSGBOX_DEFAULT
# 114 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1

Route101_EventScript_MoveRelearner_5:
# 90 "data/maps/Route101/scripts.pory"
	special IsSelectedMonEgg
# 91 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Route101_EventScript_MoveRelearner_8
# 95 "data/maps/Route101/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq Route101_EventScript_MoveRelearner_11
# 99 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WhichMove, MSGBOX_DEFAULT
# 100 "data/maps/Route101/scripts.pory"
	closemessage
# 101 "data/maps/Route101/scripts.pory"
	special TeachMoveRelearnerMove
# 102 "data/maps/Route101/scripts.pory"
	waitstate
# 103 "data/maps/Route101/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Route101_EventScript_MoveRelearner_14
# 107 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DoneComeBackAtAnyTime, MSGBOX_DEFAULT
# 108 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1

Route101_EventScript_MoveRelearner_8:
# 92 "data/maps/Route101/scripts.pory"
	msgbox Route101_ThatIsAnEgg, MSGBOX_DEFAULT
# 93 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1

Route101_EventScript_MoveRelearner_11:
# 96 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_CantTeachAnyMoves, MSGBOX_DEFAULT
# 97 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1

Route101_EventScript_MoveRelearner_14:
# 104 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_ComeBackAtAnyTime, MSGBOX_DEFAULT
# 105 "data/maps/Route101/scripts.pory"
	closemessage
	goto Route101_EventScript_MoveRelearner_1


Route101_Text_RestOfTheStory::
# 33 "data/maps/Route101/scripts.pory"
	.string "The rest of this story is for you\n"
	.string "to uncover.\p"
	.string "The Unown King has been confined\n"
	.string "inside the Temple of the Unown King.\p"
	.string "But first, you will need a companion.$"

Route101_Text_ThereAre26Unown::
# 41 "data/maps/Route101/scripts.pory"
	.string "There are 26 Unown specimen\n"
	.string "hiding in the Temple.\l"
	.string "They will help you decrypt messages\l"
	.string "written in an unintelligible script.\p"
	.string "Find them all!$"

Route101_Text_TakeThisMon::
# 59 "data/maps/Route101/scripts.pory"
	.string "You don't have a Pokémon\n"
	.string "with you. Take this.$"

Route101_Text_CannotLeave::
# 73 "data/maps/Route101/scripts.pory"
	.string "You cannot leave this area.$"

Route101_Text_WantToRelearnMove::
# 122 "data/maps/Route101/scripts.pory"
	.string "Hi! I'm an expert in moves that\n"
	.string "Pokémon can learn.\p"
	.string "If you need to, I can help your Pokémon\n"
	.string "remember a move that they forgot.\l"
	.string "Don't worry, the service is free.\n"
	.string "of charge. Wanna try?$"

Route101_ThatIsAnEgg::
# 131 "data/maps/Route101/scripts.pory"
	.string "That… is an egg.\n"
	.string "Let it hatch first!$"

Route101_Text_CantTeachAnyMoves::
# 136 "data/maps/Route101/scripts.pory"
	.string "Oh… I'm sorry, this Pokémon already\n"
	.string "knows every move that it has tried\l"
	.string "to learn. Come back when it's grown\l"
	.string "stronger!$"

Route101_Text_WhichMove::
# 143 "data/maps/Route101/scripts.pory"
	.string "Okay, which move should I teach it?$"

Route101_Text_ComeBackAtAnyTime::
# 147 "data/maps/Route101/scripts.pory"
	.string "Come back at any time!$"

Route101_Text_DoneComeBackAtAnyTime::
# 151 "data/maps/Route101/scripts.pory"
	.string "There we go!\n"
	.string "Come back at any time!$"
