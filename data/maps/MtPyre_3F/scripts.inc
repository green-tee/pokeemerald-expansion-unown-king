MtPyre_3F_MapScripts::
	.byte 0


MtPyre_3F_EventScript_Inscription::
# 4 "data/maps/MtPyre_3F/scripts.pory"
	lock
# 5 "data/maps/MtPyre_3F/scripts.pory"
	msgbox MtPyre_3F_Text_TruthRevealed, MSGBOX_UNOWNCRYPT
# 6 "data/maps/MtPyre_3F/scripts.pory"
	closemessage
# 7 "data/maps/MtPyre_3F/scripts.pory"
	release
	return


MtPyre_3F_Text_TruthRevealed::
# 10 "data/maps/MtPyre_3F/scripts.pory"
	.string "In this room, the truth about\n"
	.string "the Unown King is unveiled.\p"
	.string "Humans came into existence in its\n"
	.string "shape after its wish.\p"
	.string "Oh, how much we, the Imprisoners,\n"
	.string "pity what has become of it!$"
