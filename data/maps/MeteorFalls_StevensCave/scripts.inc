MeteorFalls_StevensCave_MapScripts::
	.byte 0


MeteorFalls_StevensCave_EventScript_Tornadus::
# 4 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	lock
# 5 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	release
	return


MeteorFalls_StevensCave_EventScript_Inscription::
# 9 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	lock
# 10 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	msgbox MeteorFalls_StevensCave_Text_NeedFly, MSGBOX_UNOWNCRYPT
# 11 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	release
	return


MeteorFalls_StevensCave_Text_NeedFly::
# 14 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "Those who can soar will reach\n"
	.string "the place where the Unown King\l"
	.string "is imprisoned.\p"
	.string "The master of flight appears\n"
	.string "when the Melody of Awakening is heard.$"
