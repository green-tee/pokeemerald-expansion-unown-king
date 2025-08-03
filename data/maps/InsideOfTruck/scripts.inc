InsideOfTruck_MapScripts::
# 2 "data/maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, InsideOfTruck_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

InsideOfTruck_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/InsideOfTruck/scripts.pory"
	map_script_2 VAR_ROUTE101_STATE, 0, InsideOfTruck_EventScript_PlayIntro
	.2byte 0


InsideOfTruck_EventScript_PlayIntro::
# 8 "data/maps/InsideOfTruck/scripts.pory"
	lockall
# 10 "data/maps/InsideOfTruck/scripts.pory"
	delay 120
# 11 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_AtDawnThereExistedNothing, MSGBOX_DEFAULT
# 12 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 13 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 14 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_ArceusCameToBe, MSGBOX_DEFAULT
# 15 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 16 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 17 "data/maps/InsideOfTruck/scripts.pory"
	applymovement LOCALID_PLAYER, InsideOfTruck_Movement_Slide11
# 18 "data/maps/InsideOfTruck/scripts.pory"
	waitmovement LOCALID_PLAYER
# 20 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 21 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_ArceusCreatedTime, MSGBOX_DEFAULT
# 22 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 23 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 24 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_ArceusCreatedSpace, MSGBOX_DEFAULT
# 25 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 26 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 27 "data/maps/InsideOfTruck/scripts.pory"
	applymovement LOCALID_PLAYER, InsideOfTruck_Movement_Slide11
# 28 "data/maps/InsideOfTruck/scripts.pory"
	waitmovement LOCALID_PLAYER
# 30 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 31 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_ArceusCreatedMew, MSGBOX_DEFAULT
# 32 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 33 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 34 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_ArceusGaveMewPowerToSplit, MSGBOX_DEFAULT
# 35 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 36 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 37 "data/maps/InsideOfTruck/scripts.pory"
	applymovement LOCALID_PLAYER, InsideOfTruck_Movement_Slide11
# 38 "data/maps/InsideOfTruck/scripts.pory"
	waitmovement LOCALID_PLAYER
# 40 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 41 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_ArceusCreatedUnown, MSGBOX_DEFAULT
# 42 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 43 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 44 "data/maps/InsideOfTruck/scripts.pory"
	applymovement LOCALID_PLAYER, InsideOfTruck_Movement_Slide14
# 45 "data/maps/InsideOfTruck/scripts.pory"
	waitmovement LOCALID_PLAYER
# 47 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 48 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_MewBeganToMutate, MSGBOX_DEFAULT
# 49 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 50 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 51 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_WorldShaped, MSGBOX_DEFAULT
# 52 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 53 "data/maps/InsideOfTruck/scripts.pory"
	delay 120
# 54 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_ArceusCreatedUnownKing, MSGBOX_DEFAULT
# 55 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 56 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 57 "data/maps/InsideOfTruck/scripts.pory"
	applymovement LOCALID_PLAYER, InsideOfTruck_Movement_Slide15
# 58 "data/maps/InsideOfTruck/scripts.pory"
	waitmovement LOCALID_PLAYER
# 60 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 61 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_MoreVariationsCreated, MSGBOX_DEFAULT
# 62 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 63 "data/maps/InsideOfTruck/scripts.pory"
	delay 60
# 64 "data/maps/InsideOfTruck/scripts.pory"
	warpsilent MAP_ROUTE101, 11, 13
# 65 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	return


# 68 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_Slide11:
# 69 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 69 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 69 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 69 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 69 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 69 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 69 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 69 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 69 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 69 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 69 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
	step_end

# 72 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_Slide14:
# 73 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 73 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 73 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 73 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 73 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 73 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 73 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 73 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 73 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 73 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 73 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 73 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 73 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 73 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
	step_end

# 76 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_Slide15:
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
# 77 "data/maps/InsideOfTruck/scripts.pory"
	walk_slow_right
	step_end

InsideOfTruck_Text_AtDawnThereExistedNothing::
# 80 "data/maps/InsideOfTruck/scripts.pory"
	.string "At Dawn, there was neither space\n"
	.string "nor time.\p"
	.string "There existed nothing\n"
	.string "but Nothing.$"

InsideOfTruck_Text_ArceusCameToBe::
# 87 "data/maps/InsideOfTruck/scripts.pory"
	.string "Arceus came to be\n"
	.string "and Nothing ceased to exist.$"

InsideOfTruck_Text_ArceusCreatedTime::
# 92 "data/maps/InsideOfTruck/scripts.pory"
	.string "Arceus created time\n"
	.string "and Dialga to rule over it.$"

InsideOfTruck_Text_ArceusCreatedSpace::
# 97 "data/maps/InsideOfTruck/scripts.pory"
	.string "Then It created space\n"
	.string "and Palkia to rule over it.$"

InsideOfTruck_Text_ArceusCreatedMew::
# 102 "data/maps/InsideOfTruck/scripts.pory"
	.string "With time and space in place,\n"
	.string "Arceus brought the first\l"
	.string "true life form, bearing the name\l"
	.string "Mew.$"

InsideOfTruck_Text_ArceusGaveMewPowerToSplit::
# 109 "data/maps/InsideOfTruck/scripts.pory"
	.string "However, Arceus desired that\n"
	.string "there be countless living beings,\l"
	.string "thus It granted Mew the power\l"
	.string "to split into two life forms.$"

InsideOfTruck_Text_ArceusCreatedUnown::
# 116 "data/maps/InsideOfTruck/scripts.pory"
	.string "At last, Arceus brought\n"
	.string "the life forms known as Unown.\p"
	.string "They appeared in a number of shapes\n"
	.string "called Glyphs.\p"
	.string "Every Glyph could radiate a wave\n"
	.string "in its own image.$"

InsideOfTruck_Text_MewBeganToMutate::
# 125 "data/maps/InsideOfTruck/scripts.pory"
	.string "Exposed to those waves,\n"
	.string "the true life forms began\l"
	.string "to alter their appearence,\l"
	.string "resulting in the birth\l"
	.string "of final life forms.$"

InsideOfTruck_Text_WorldShaped::
# 133 "data/maps/InsideOfTruck/scripts.pory"
	.string "The earliest final life forms\n"
	.string "set out to shape the world\l"
	.string "in which life would proliferate.$"

InsideOfTruck_Text_ArceusCreatedUnownKing::
# 139 "data/maps/InsideOfTruck/scripts.pory"
	.string "But the Unown wished for a leader\n"
	.string "to command them,\l"
	.string "for they did not know\l"
	.string "how to best combine their waves\l"
	.string "to affect the true life forms.\p"
	.string "Arceus granted their wish\n"
	.string "by gifting them the Unown King.$"

InsideOfTruck_Text_MoreVariationsCreated::
# 149 "data/maps/InsideOfTruck/scripts.pory"
	.string "Thanks to the Unown King's orders,\n"
	.string "the world met more and more\l"
	.string "variations of the final life forms,\l"
	.string "until the Unown and the Unown King\l"
	.string "were content.$"
