GraniteCave_B1F_MapScripts::
	.byte 0


GraniteCave_B1F_Inscription::
# 4 "data/maps/GraniteCave_B1F/scripts.pory"
	lock
# 5 "data/maps/GraniteCave_B1F/scripts.pory"
	goto_if_unset FLAG_SYS_USE_FLASH, GraniteCave_B1F_Inscription_2
# 9 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_UnownKingStory, MSGBOX_UNOWNCRYPT
# 10 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
GraniteCave_B1F_Inscription_1:
# 12 "data/maps/GraniteCave_B1F/scripts.pory"
	release
	return

GraniteCave_B1F_Inscription_2:
# 6 "data/maps/GraniteCave_B1F/scripts.pory"
	msgbox GraniteCave_B1F_Text_TooDark, MSGBOX_DEFAULT
# 7 "data/maps/GraniteCave_B1F/scripts.pory"
	closemessage
	goto GraniteCave_B1F_Inscription_1


GraniteCave_B1F_Text_TooDark::
# 15 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "It's too dark to read anything.$"

GraniteCave_B1F_Text_UnownKingStory::
# 19 "data/maps/GraniteCave_B1F/scripts.pory"
	.string "Some humans warred their own equals.\n"
	.string "Through the centuries, the wars never\l"
	.string "stopped.\p"
	.string "The destruction caused by those humans\n"
	.string "angered the Unown King, who succumbed\l"
	.string "to the same craze.\p"
	.string "It attempted to eradicate all humans.\p"
	.string "However, there existed humans who\n"
	.string "loathed bloodshed.\p"
	.string "The Unown King saw the kind,\n"
	.string "the poor, and the just\l"
	.string "and could not ignore what it saw.\p"
	.string "Unknowingly, the Unown King split in\n"
	.string "two halves: the Good and the Bad.\p"
	.string "The Good rejected the Bad's desire to\n"
	.string "exterminate all human beings.\p"
	.string "The two Kings clashed.\n"
	.string "The Good perished.\p"
	.string "The Bad, however, was weakened in the\n"
	.string "battle.\p"
	.string "It became weak enough\n"
	.string "for the innocent humans to conquer it\l"
	.string "and seal it into a temple,\l"
	.string "till the day when an unfazed soul\l"
	.string "may put it to rest for good.$"
