MtPyre_1F_MapScripts::
	.byte 0


MtPyre_1F_EventScript_Inscription::
# 4 "data/maps/MtPyre_1F/scripts.pory"
	lock
# 5 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_UnownKingImprisoned, MSGBOX_UNOWNCRYPT
# 6 "data/maps/MtPyre_1F/scripts.pory"
	closemessage
# 7 "data/maps/MtPyre_1F/scripts.pory"
	release
	return


MtPyre_1F_EventScript_WalkingGal::
# 16 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_ImLookingForRarePokemon, MSGBOX_NPC
	return


MtPyre_1F_Text_UnownKingImprisoned::
# 10 "data/maps/MtPyre_1F/scripts.pory"
	.string "This temple keeps the Unown King\n"
	.string "imprisoned.$"

MtPyre_1F_Text_ImLookingForRarePokemon::
# 19 "data/maps/MtPyre_1F/scripts.pory"
	.string "I'm looking for rare Pokémon to catch,\n"
	.string "but I'm not in the mood to battle\l"
	.string "other Trainers.$"
