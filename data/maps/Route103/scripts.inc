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


Route103_Text_ImHereForTesting::
# 11 "data/maps/Route103/scripts.pory"
	.string "I'm here for testing purposes.$"
