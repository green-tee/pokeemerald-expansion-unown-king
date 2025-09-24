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


MtPyre_2F_EventScript_Psychic::
# 29 "data/maps/MtPyre_2F/scripts.pory"
	trainerbattle_single TRAINER_PSYCHIC_CLELIA, MtPyre_2F_Text_JustBecauseImAPsychic, MtPyre_2F_Text_ImEvaporating
# 30 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_FindFeebas, MSGBOX_AUTOCLOSE
	return


MrPyre_2F_EventScript_GuyBeforeHollowRoom::
# 52 "data/maps/MtPyre_2F/scripts.pory"
	lock
# 53 "data/maps/MtPyre_2F/scripts.pory"
	faceplayer
# 54 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_ILetMyGuardDown, MSGBOX_DEFAULT
# 55 "data/maps/MtPyre_2F/scripts.pory"
	closemessage
# 56 "data/maps/MtPyre_2F/scripts.pory"
	release
	return


MtPyre_2F_EventScript_TrainerTypesGal::
# 69 "data/maps/MtPyre_2F/scripts.pory"
	lock
# 70 "data/maps/MtPyre_2F/scripts.pory"
	faceplayer
# 71 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_ExplainTrainerTypes, MSGBOX_DEFAULT
# 72 "data/maps/MtPyre_2F/scripts.pory"
	closemessage
# 73 "data/maps/MtPyre_2F/scripts.pory"
	release
	return


MtPyre_2F_EventScript_Fighter::
# 99 "data/maps/MtPyre_2F/scripts.pory"
	trainerbattle_single TRAINER_FIGHTER_JOLENE, MtPyre_2F_Text_GetZapped, MtPyre_2F_Text_INeedMorePower
# 100 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_LightningDoesntStruckTwice, MSGBOX_AUTOCLOSE
	return


MtPyre_2F_EventScript_BreederWalking::
# 118 "data/maps/MtPyre_2F/scripts.pory"
	trainerbattle_single TRAINER_BREEDER_LIAM, MtPyre_2F_Text_IDontUsuallyWin, MtPyre_2F_Text_NoBigDeal
# 119 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_HowDoesGardenWork, MSGBOX_AUTOCLOSE
	return


MtPyre_2F_EventScript_BreederStill::
# 141 "data/maps/MtPyre_2F/scripts.pory"
	trainerbattle_single TRAINER_BREEDER_OLIVER, MtPyre_2F_Text_WellShowPokemon, MtPyre_2F_Text_ThatWasEntertaining
# 142 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_HaveYouHeardOfMaidens, MSGBOX_AUTOCLOSE
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

MtPyre_2F_Text_JustBecauseImAPsychic::
# 33 "data/maps/MtPyre_2F/scripts.pory"
	.string "Just because I'm a Psychic, that\n"
	.string "doesn't mean I can only use\l"
	.string "Psychic-type Pokémon.\p"
	.string "I'll beat you with the power of water\n"
	.string "and water! And water! Water!$"

MtPyre_2F_Text_ImEvaporating::
# 41 "data/maps/MtPyre_2F/scripts.pory"
	.string "I'm evaporating…$"

MtPyre_2F_Text_FindFeebas::
# 45 "data/maps/MtPyre_2F/scripts.pory"
	.string "If you want to find a Feebas, you need\n"
	.string "a good rod. You can't expect one\l"
	.string "to fall for any old rod.$"

MtPyre_2F_Text_ILetMyGuardDown::
# 59 "data/maps/MtPyre_2F/scripts.pory"
	.string "I walked into this room ahead and found\n"
	.string "a bunch of harmless Pokémon.\l"
	.string "I let my guard down.\p"
	.string "But then a big bipedal Pokémon and a\n"
	.string "huge Bug came from behind a pillar and\l"
	.string "I barely escaped!$"

MtPyre_2F_Text_ExplainTrainerTypes::
# 76 "data/maps/MtPyre_2F/scripts.pory"
	.string "There are different types of Trainers\n"
	.string "around here. Breeders are the weakest,\l"
	.string "but they tend to use more Pokémon than\l"
	.string "the others.\p"
	.string "Fighters are a bit tougher, but you\n"
	.string "should be able to overcome them with a\l"
	.string "little training.\p"
	.string "Next are the bald Scoundrels. They're\n"
	.string "usually mean towards weak Trainers.\l"
	.string "You might want to avoid them, at least\l"
	.string "for a while.\p"
	.string "And you definitely want to avoid\n"
	.string "Psychics.\p"
	.string "As for the Beast Tamers, you'll hardly\n"
	.string "meet them if you aren't strong enough\l"
	.string "to take them on.\p"
	.string "That said, there's a feral Beast Tamer\n"
	.string "hiding in a room shrouded in darkness.\l"
	.string "Be extra careful if you venture there!$"

MtPyre_2F_Text_GetZapped::
# 103 "data/maps/MtPyre_2F/scripts.pory"
	.string "Get zapped by my overcharged Pokémon!$"

MtPyre_2F_Text_INeedMorePower::
# 107 "data/maps/MtPyre_2F/scripts.pory"
	.string "I need more raw power.$"

MtPyre_2F_Text_LightningDoesntStruckTwice::
# 111 "data/maps/MtPyre_2F/scripts.pory"
	.string "Lightning usually doesn't strike\n"
	.string "twice. I'm not going to battle with you\l"
	.string "again.$"

MtPyre_2F_Text_IDontUsuallyWin::
# 122 "data/maps/MtPyre_2F/scripts.pory"
	.string "I'm not exactly used to winning,\n"
	.string "but that won't stop me from trying!$"

MtPyre_2F_Text_NoBigDeal::
# 127 "data/maps/MtPyre_2F/scripts.pory"
	.string "No big deal, I'll keep trying!$"

MtPyre_2F_HowDoesGardenWork::
# 131 "data/maps/MtPyre_2F/scripts.pory"
	.string "How does this garden even work?\n"
	.string "Did the people who built this temple\l"
	.string "leave a patch of ground so deep that\l"
	.string "trees could grow and have room for\l"
	.string "their roots?\p"
	.string "Where's the light coming from anyway?$"

MtPyre_2F_Text_WellShowPokemon::
# 145 "data/maps/MtPyre_2F/scripts.pory"
	.string "You'll show me your Pokémon\n"
	.string "and I'll show you mine!$"

MtPyre_2F_Text_ThatWasEntertaining::
# 150 "data/maps/MtPyre_2F/scripts.pory"
	.string "That was entertaining!$"

MtPyre_2F_Text_HaveYouHeardOfMaidens::
# 154 "data/maps/MtPyre_2F/scripts.pory"
	.string "Have you heard of the four Maidens\n"
	.string "of this temple?\p"
	.string "They're four sisters who dress in fancy\n"
	.string "clothes and help Trainers who are\l"
	.string "skilled enough.\p"
	.string "I've heard that one of them is obsessed\n"
	.string "with Ghost-type Pokémon.$"
