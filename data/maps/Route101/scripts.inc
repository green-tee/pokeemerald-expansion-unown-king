Route101_MapScripts::
# 2 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route101_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 5 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route101_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_FacePlayerNorth
	.2byte 0

Route101_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 6 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_PlayIntroFollowUp
	.2byte 0


Route101_EventScript_FacePlayerNorth::
# 11 "data/maps/Route101/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	return


Route101_EventScript_PlayIntroFollowUp::
# 15 "data/maps/Route101/scripts.pory"
	lockall
# 16 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_RestOfTheStory, MSGBOX_DEFAULT
# 17 "data/maps/Route101/scripts.pory"
	closemessage
# 18 "data/maps/Route101/scripts.pory"
	special ChooseStarter
# 19 "data/maps/Route101/scripts.pory"
	waitstate
# 20 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_ThereAre26Unown, MSGBOX_DEFAULT
# 21 "data/maps/Route101/scripts.pory"
	closemessage
# 22 "data/maps/Route101/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 23 "data/maps/Route101/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 24 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 1
# 25 "data/maps/Route101/scripts.pory"
	releaseall
	return


Route101_EventScript_GiveEmergencyMon::
# 45 "data/maps/Route101/scripts.pory"
	lock
# 46 "data/maps/Route101/scripts.pory"
	faceplayer
# 47 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_TakeThisMon, MSGBOX_DEFAULT
# 48 "data/maps/Route101/scripts.pory"
	closemessage
# 49 "data/maps/Route101/scripts.pory"
	givemon SPECIES_GYARADOS, 25
# 50 "data/maps/Route101/scripts.pory"
	release
	return


Route101_Text_RestOfTheStory::
# 28 "data/maps/Route101/scripts.pory"
	.string "The rest of this story is for you\n"
	.string "to uncover.\p"
	.string "The Unown King has been confined\n"
	.string "inside the Temple of the Unown King.\p"
	.string "But first, you will need a companion.$"

Route101_Text_ThereAre26Unown::
# 36 "data/maps/Route101/scripts.pory"
	.string "There are 26 Unown specimen\n"
	.string "hiding in the Temple.\l"
	.string "They will help you decrypting messages\l"
	.string "written in an unintelligible script.\p"
	.string "Find them all!$"

Route101_Text_TakeThisMon::
# 54 "data/maps/Route101/scripts.pory"
	.string "You don't have a Pokémon\n"
	.string "with you. Take this.$"
