Route101_MapScripts::
	.byte 0


Route101_EventScript_GiveEmergencyMon::
# 4 "data/maps/Route101/scripts.pory"
	lock
# 5 "data/maps/Route101/scripts.pory"
	faceplayer
# 6 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_TakeThisMon, MSGBOX_DEFAULT
# 7 "data/maps/Route101/scripts.pory"
	closemessage
# 8 "data/maps/Route101/scripts.pory"
	givemon SPECIES_GYARADOS, 25
# 9 "data/maps/Route101/scripts.pory"
	release
	return


Route101_Text_TakeThisMon::
# 13 "data/maps/Route101/scripts.pory"
	.string "You don't have a Pokémon\n"
	.string "with you. Take this.$"
