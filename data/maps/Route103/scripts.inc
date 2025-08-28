Route103_MapScripts::
	.byte 0


Route103_EventScript_ImHereForTesting::
# 4 "data/maps/Route103/scripts.pory"
	lock
# 5 "data/maps/Route103/scripts.pory"
	faceplayer
# 6 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ImHereForTesting, MSGBOX_DEFAULT
# 7 "data/maps/Route103/scripts.pory"
	closemessage
# 8 "data/maps/Route103/scripts.pory"
	release
	return


Route103_EventScript_TestUnowncrypt::
# 16 "data/maps/Route103/scripts.pory"
	lock
# 17 "data/maps/Route103/scripts.pory"
	faceplayer
# 18 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_TestUnowncrypt, MSGBOX_UNOWNCRYPT
# 19 "data/maps/Route103/scripts.pory"
	closemessage
# 20 "data/maps/Route103/scripts.pory"
	release
	return


Route103_EventScript_TestMiloticBossBattle::
# 34 "data/maps/Route103/scripts.pory"
	lock
# 35 "data/maps/Route103/scripts.pory"
	faceplayer
# 36 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_StartingMiloticBattle, MSGBOX_YESNO
# 37 "data/maps/Route103/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route103_EventScript_TestMiloticBossBattle_2
# 44 "data/maps/Route103/scripts.pory"
	closemessage
# 45 "data/maps/Route103/scripts.pory"
	setwildbattle SPECIES_MILOTIC, 30
# 46 "data/maps/Route103/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 47 "data/maps/Route103/scripts.pory"
	waitstate
Route103_EventScript_TestMiloticBossBattle_1:
# 49 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiloticBattleOver, MSGBOX_DEFAULT
# 50 "data/maps/Route103/scripts.pory"
	closemessage
# 51 "data/maps/Route103/scripts.pory"
	release
	return

Route103_EventScript_TestMiloticBossBattle_2:
# 38 "data/maps/Route103/scripts.pory"
	closemessage
# 39 "data/maps/Route103/scripts.pory"
	createmon 1, 0, SPECIES_MILOTIC, 30, move1 = MOVE_DRAINING_KISS, move2 = MOVE_WATER_PULSE, move3 = MOVE_DRAGON_TAIL, move4 = MOVE_AVALANCHE, abilityNum = 0, isShiny = FALSE
# 41 "data/maps/Route103/scripts.pory"
	special BattleSetup_StartBossBattle
# 42 "data/maps/Route103/scripts.pory"
	waitstate
	goto Route103_EventScript_TestMiloticBossBattle_1


Route103_Text_ImHereForTesting::
# 11 "data/maps/Route103/scripts.pory"
	.string "I'm here for testing purposes.$"

Route103_Text_TestUnowncrypt::
# 23 "data/maps/Route103/scripts.pory"
	.string "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n"
	.string "abcdefghijklmnopqrstuvwxyz\p"
	.string "0123456789\p"
	.string "Never gonna give you up,\n"
	.string "Never gonna let you down,\l"
	.string "Never gonna run around\l"
	.string "And desert you.$"

Route103_Text_StartingMiloticBattle::
# 54 "data/maps/Route103/scripts.pory"
	.string "Starting battle against Milotic.\n"
	.string "Do you want to fight the hostile version?$"

Route103_Text_MiloticBattleOver::
# 59 "data/maps/Route103/scripts.pory"
	.string "Milotic battle over.$"
