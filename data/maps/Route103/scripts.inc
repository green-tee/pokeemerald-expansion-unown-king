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
