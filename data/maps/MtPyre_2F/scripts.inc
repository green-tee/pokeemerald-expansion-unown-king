MtPyre_2F_MapScripts::
	.byte 0


MtPyre_2F_EventScript_Inscription::
# 4 "data/maps/MtPyre_2F/scripts.pory"
	lock
# 5 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_UnownList, MSGBOX_UNOWNCRYPT
# 6 "data/maps/MtPyre_2F/scripts.pory"
	closemessage
# 7 "data/maps/MtPyre_2F/scripts.pory"
	release
	return


MtPyre_2F_Text_UnownList::
# 10 "data/maps/MtPyre_2F/scripts.pory"
	.string "K, C and J - This garden\n"
	.string "T and O - The antechamber\p"
	.string "M and F - The western wing\n"
	.string "V and G - The eastern wing\p"
	.string "I - The western hallway\n"
	.string "H and Y - The eastern hallway\p"
	.string "R, A and E - The longest hallway\n"
	.string "B - The sanctuary of dragons\p"
	.string "D and S - Where the truth is revealed\n"
	.string "L - Shrouded in the deepest dark\p"
	.string "Z and P - At the Pond of Grace\n"
	.string "W and X - At the Eternal Pond\p"
	.string "Q - In the intricate waters\n"
	.string "U - Below the longest hallway\p"
	.string "N - The bugs' nesting place$"
