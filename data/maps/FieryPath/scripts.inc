FieryPath_MapScripts::
# 2 "data/maps/FieryPath/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FieryPath_EventScript_TryRemoveFakeBoulder
	.byte 0


FieryPath_EventScript_TryRemoveFakeBoulder::
# 10 "data/maps/FieryPath/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, FieryPath_EventScript_TryRemoveFakeBoulder_1
	return

FieryPath_EventScript_TryRemoveFakeBoulder_1:
# 11 "data/maps/FieryPath/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 12 "data/maps/FieryPath/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FieryPath_EventScript_TryRemoveFakeBoulder_3
# 12 "data/maps/FieryPath/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FieryPath_EventScript_TryRemoveFakeBoulder_3
	return

FieryPath_EventScript_TryRemoveFakeBoulder_3:
# 13 "data/maps/FieryPath/scripts.pory"
	removeobject VAR_LAST_TALKED
	return


FieryPath_EventScript_Inscription::
# 19 "data/maps/FieryPath/scripts.pory"
	lock
# 20 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_WaysOfWater, MSGBOX_UNOWNCRYPT
# 21 "data/maps/FieryPath/scripts.pory"
	closemessage
# 22 "data/maps/FieryPath/scripts.pory"
	release
	return


FieryPath_EventScript_MaidenGaia::
# 34 "data/maps/FieryPath/scripts.pory"
	lock
# 35 "data/maps/FieryPath/scripts.pory"
	faceplayer
# 36 "data/maps/FieryPath/scripts.pory"
	goto_if_set FLAG_BADGE04_GET, FieryPath_EventScript_MaidenGaia_2
# 62 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_ImOneOfTheMaidens, MSGBOX_YESNO
# 63 "data/maps/FieryPath/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FieryPath_EventScript_MaidenGaia_8
# 77 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_IUnderstand, MSGBOX_DEFAULT
# 78 "data/maps/FieryPath/scripts.pory"
	closemessage
FieryPath_EventScript_MaidenGaia_1:
# 81 "data/maps/FieryPath/scripts.pory"
	release
	return

FieryPath_EventScript_MaidenGaia_2:
# 37 "data/maps/FieryPath/scripts.pory"
	goto_if_set FLAG_RECEIVED_EGG_FROM_GAIA, FieryPath_EventScript_MaidenGaia_5
# 40 "data/maps/FieryPath/scripts.pory"
	goto_if_set FLAG_GAVE_WATER_TO_GAIA, FieryPath_EventScript_MaidenGaia_11
# 43 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_ImSoThirsty, MSGBOX_DEFAULT
# 44 "data/maps/FieryPath/scripts.pory"
	checkitem ITEM_FRESH_WATER, 1
# 45 "data/maps/FieryPath/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq FieryPath_EventScript_MaidenGaia_14
# 57 "data/maps/FieryPath/scripts.pory"
	closemessage
	goto FieryPath_EventScript_MaidenGaia_1

FieryPath_EventScript_MaidenGaia_5:
# 38 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_HallwayImpractical, MSGBOX_DEFAULT
	goto FieryPath_EventScript_MaidenGaia_1

FieryPath_EventScript_MaidenGaia_8:
# 64 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_LetTheBattleBegin, MSGBOX_DEFAULT
# 65 "data/maps/FieryPath/scripts.pory"
	closemessage
# 66 "data/maps/FieryPath/scripts.pory"
	playbgm MUS_VS_GYM_LEADER, FALSE
# 67 "data/maps/FieryPath/scripts.pory"
	trainerbattle_no_intro TRAINER_MAIDEN3, FieryPath_Text_MaidenGaiaDefeated
# 68 "data/maps/FieryPath/scripts.pory"
	lock
# 69 "data/maps/FieryPath/scripts.pory"
	faceplayer
# 70 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_YouSucceeded, MSGBOX_DEFAULT
# 71 "data/maps/FieryPath/scripts.pory"
	closemessage
# 72 "data/maps/FieryPath/scripts.pory"
	giveitem ITEM_HM_STRENGTH
# 73 "data/maps/FieryPath/scripts.pory"
	setflag FLAG_BADGE04_GET
# 74 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_YouCanReachTheStrongestSister, MSGBOX_DEFAULT
# 75 "data/maps/FieryPath/scripts.pory"
	closemessage
	goto FieryPath_EventScript_MaidenGaia_1

FieryPath_EventScript_MaidenGaia_11:
# 41 "data/maps/FieryPath/scripts.pory"
	call FieryPath_EventScript_TryGiveEgg
	goto FieryPath_EventScript_MaidenGaia_1

FieryPath_EventScript_MaidenGaia_14:
# 46 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_MayIHaveWater, MSGBOX_YESNO
# 47 "data/maps/FieryPath/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FieryPath_EventScript_MaidenGaia_17
# 54 "data/maps/FieryPath/scripts.pory"
	closemessage
	goto FieryPath_EventScript_MaidenGaia_1

FieryPath_EventScript_MaidenGaia_17:
# 48 "data/maps/FieryPath/scripts.pory"
	removeitem ITEM_FRESH_WATER, 1
# 49 "data/maps/FieryPath/scripts.pory"
	setflag FLAG_GAVE_WATER_TO_GAIA
# 50 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_ThankYouVeryMuch, MSGBOX_DEFAULT
# 51 "data/maps/FieryPath/scripts.pory"
	closemessage
# 52 "data/maps/FieryPath/scripts.pory"
	call FieryPath_EventScript_TryGiveEgg
	goto FieryPath_EventScript_MaidenGaia_1


FieryPath_EventScript_TryGiveEgg:
# 85 "data/maps/FieryPath/scripts.pory"
	getpartysize
# 86 "data/maps/FieryPath/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt FieryPath_EventScript_TryGiveEgg_1
# 119 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_NoRoomForEgg, MSGBOX_DEFAULT
# 120 "data/maps/FieryPath/scripts.pory"
	closemessage
	return

FieryPath_EventScript_TryGiveEgg_1:
# 87 "data/maps/FieryPath/scripts.pory"
	switch VAR_STARTER_MON
# 88 "data/maps/FieryPath/scripts.pory"
	case 0, FieryPath_EventScript_TryGiveEgg_6
# 91 "data/maps/FieryPath/scripts.pory"
	case 1, FieryPath_EventScript_TryGiveEgg_7
# 94 "data/maps/FieryPath/scripts.pory"
	case 2, FieryPath_EventScript_TryGiveEgg_8
FieryPath_EventScript_TryGiveEgg_4:
# 98 "data/maps/FieryPath/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_0
# 99 "data/maps/FieryPath/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_TEMP_1
# 100 "data/maps/FieryPath/scripts.pory"
	message FieryPath_Text_WhichEggDoYouWant
# 101 "data/maps/FieryPath/scripts.pory"
	waitmessage
# 102 "data/maps/FieryPath/scripts.pory"
	dynmultichoice 20, 8, TRUE, 2, 0, DYN_MULTICHOICE_CB_NONE, FieryPath_EventScript_TryGiveEgg_Text_0, FieryPath_EventScript_TryGiveEgg_Text_1
# 103 "data/maps/FieryPath/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FieryPath_EventScript_TryGiveEgg_10
# 106 "data/maps/FieryPath/scripts.pory"
	copyvar VAR_TEMP_2, VAR_TEMP_1
FieryPath_EventScript_TryGiveEgg_9:
# 108 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_Sure, MSGBOX_DEFAULT
# 109 "data/maps/FieryPath/scripts.pory"
	giveegg VAR_TEMP_2
# 110 "data/maps/FieryPath/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_ne FieryPath_EventScript_TryGiveEgg_14
FieryPath_EventScript_TryGiveEgg_13:
# 114 "data/maps/FieryPath/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 115 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_ReceivedAnEgg, MSGBOX_DEFAULT
# 116 "data/maps/FieryPath/scripts.pory"
	waitfanfare
# 117 "data/maps/FieryPath/scripts.pory"
	closemessage
	return

FieryPath_EventScript_TryGiveEgg_6:
# 89 "data/maps/FieryPath/scripts.pory"
	setvar VAR_TEMP_0, SPECIES_HOUNDOUR
# 90 "data/maps/FieryPath/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_VULPIX_ALOLA
	goto FieryPath_EventScript_TryGiveEgg_4

FieryPath_EventScript_TryGiveEgg_7:
# 92 "data/maps/FieryPath/scripts.pory"
	setvar VAR_TEMP_0, SPECIES_VULPIX_ALOLA
# 93 "data/maps/FieryPath/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_ELECTRIKE
	goto FieryPath_EventScript_TryGiveEgg_4

FieryPath_EventScript_TryGiveEgg_8:
# 95 "data/maps/FieryPath/scripts.pory"
	setvar VAR_TEMP_0, SPECIES_ELECTRIKE
# 96 "data/maps/FieryPath/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_HOUNDOUR
	goto FieryPath_EventScript_TryGiveEgg_4

FieryPath_EventScript_TryGiveEgg_10:
# 104 "data/maps/FieryPath/scripts.pory"
	copyvar VAR_TEMP_2, VAR_TEMP_0
	goto FieryPath_EventScript_TryGiveEgg_9

FieryPath_EventScript_TryGiveEgg_14:
# 111 "data/maps/FieryPath/scripts.pory"
	setflag FLAG_RECEIVED_EGG_FROM_GAIA
# 112 "data/maps/FieryPath/scripts.pory"
	copyvar VAR_GAIA_EGG_SPECIES, VAR_TEMP_2
	goto FieryPath_EventScript_TryGiveEgg_13


FieryPath_EventScript_BeastTamerNE::
# 214 "data/maps/FieryPath/scripts.pory"
	lock
# 215 "data/maps/FieryPath/scripts.pory"
	faceplayer
# 216 "data/maps/FieryPath/scripts.pory"
	goto_if_set FLAG_TEMP_1, FieryPath_EventScript_BeastTamerNE_2
# 220 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_ImTheStrongestTrainer, MSGBOX_YESNO
# 221 "data/maps/FieryPath/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FieryPath_EventScript_BeastTamerNE_5
# 239 "data/maps/FieryPath/scripts.pory"
	closemessage
FieryPath_EventScript_BeastTamerNE_1:
# 242 "data/maps/FieryPath/scripts.pory"
	release
	return

FieryPath_EventScript_BeastTamerNE_2:
# 217 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_ImUpToAnotherFight
# 218 "data/maps/FieryPath/scripts.pory"
	closemessage
	goto FieryPath_EventScript_BeastTamerNE_1

FieryPath_EventScript_BeastTamerNE_5:
# 222 "data/maps/FieryPath/scripts.pory"
	playbgm MUS_VS_GYM_LEADER, FALSE
# 223 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_VeryWellBringItOn, MSGBOX_DEFAULT
# 224 "data/maps/FieryPath/scripts.pory"
	closemessage
# 225 "data/maps/FieryPath/scripts.pory"
	trainerbattle_no_intro TRAINER_BEAST_TAMER_CAESAR, FieryPath_Text_YouAreTheRealBeast
# 226 "data/maps/FieryPath/scripts.pory"
	setflag FLAG_TEMP_1
# 227 "data/maps/FieryPath/scripts.pory"
	goto_if_set FLAG_RECEIVED_MASTER_BALL, FieryPath_EventScript_BeastTamerNE_8
# 231 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_IHaveAPresent, MSGBOX_DEFAULT
# 232 "data/maps/FieryPath/scripts.pory"
	closemessage
# 233 "data/maps/FieryPath/scripts.pory"
	giveitem ITEM_MASTER_BALL, 1
# 234 "data/maps/FieryPath/scripts.pory"
	setflag FLAG_RECEIVED_MASTER_BALL
# 235 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_ThisIsAMasterBall, MSGBOX_DEFAULT
# 236 "data/maps/FieryPath/scripts.pory"
	closemessage
	goto FieryPath_EventScript_BeastTamerNE_1

FieryPath_EventScript_BeastTamerNE_8:
# 228 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_IHaveNothingMoreToSay, MSGBOX_DEFAULT
# 229 "data/maps/FieryPath/scripts.pory"
	closemessage
	goto FieryPath_EventScript_BeastTamerNE_1


FieryPath_EventScript_BeastTamerNW::
# 290 "data/maps/FieryPath/scripts.pory"
	trainerbattle_single TRAINER_BEAST_TAMER_TRITON, FieryPath_Text_AssistMeInTraining, FieryPath_Text_NotAsPlanned
# 291 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_LegendaryPokemon, MSGBOX_AUTOCLOSE
	return


FieryPath_EventScript_BeastTamerSW::
# 312 "data/maps/FieryPath/scripts.pory"
	trainerbattle_single TRAINER_BEAST_TAMER_WILHELM, FieryPath_Text_ThisIsntAPlaceForInexperienced, FieryPath_Text_ITakeItBack
# 313 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_HowIsItGoing, MSGBOX_AUTOCLOSE
	return


FieryPath_EventScript_BeastTamerSE::
# 330 "data/maps/FieryPath/scripts.pory"
	trainerbattle_single TRAINER_BEAST_TAMER_SOLOMON, FieryPath_Text_TodaysYouthIsPathetic, FieryPath_Text_YouGotLucky
# 331 "data/maps/FieryPath/scripts.pory"
	msgbox FieryPath_Text_HaveYouFoundDarkrai, MSGBOX_AUTOCLOSE
	return


FieryPath_EventScript_TryGiveEgg_Text_0:
# 102 "data/maps/FieryPath/scripts.pory"
	.string "{STR_VAR_1}$"

FieryPath_EventScript_TryGiveEgg_Text_1:
# 102 "data/maps/FieryPath/scripts.pory"
	.string "{STR_VAR_2}$"

FieryPath_Text_WaysOfWater::
# 25 "data/maps/FieryPath/scripts.pory"
	.string "Only those who truly master the ways\n"
	.string "of water can explore this temple\l"
	.string "to the fullest.\p"
	.string "This hallway is connected to one\n"
	.string "of the aquatic caverns.$"

FieryPath_Text_ImOneOfTheMaidens::
# 124 "data/maps/FieryPath/scripts.pory"
	.string "Hi, traveler!\n"
	.string "Do you need help?\p"
	.string "I'm Gaia, one of the four Maidens\n"
	.string "of this temple.\p"
	.string "I can lend you the power to move\n"
	.string "those heavy boulders out of your way,\l"
	.string "but you must defeat me in battle first.\p"
	.string "I'm not the strongest of the four,\n"
	.string "but I advise you to be prepared\l"
	.string "nonetheless.\p"
	.string "Are you sure you want to challenge me?$"

FieryPath_Text_IUnderstand::
# 138 "data/maps/FieryPath/scripts.pory"
	.string "I understand.\n"
	.string "If you want to prove yourself,\l"
	.string "talk to me again.$"

FieryPath_Text_LetTheBattleBegin::
# 144 "data/maps/FieryPath/scripts.pory"
	.string "Of course.\n"
	.string "Let the battle begin!$"

FieryPath_Text_MaidenGaiaDefeated::
# 149 "data/maps/FieryPath/scripts.pory"
	.string "You defeated me. For that, you deserve\n"
	.string "the prize I'm about to give you.$"

FieryPath_Text_YouSucceeded::
# 154 "data/maps/FieryPath/scripts.pory"
	.string "You succeeded in winning our battle.\n"
	.string "That makes you worthy of receiving\l"
	.string "this power.$"

FieryPath_Text_YouCanReachTheStrongestSister::
# 160 "data/maps/FieryPath/scripts.pory"
	.string "With this power, you can reach\n"
	.string "the strongest of my Sisters.\p"
	.string "The large boulders on the floor are\n"
	.string "now barely an inconvenience to you.\p"
	.string "I wish you success in everything\n"
	.string "in your life!$"

FieryPath_Text_ImSoThirsty::
# 169 "data/maps/FieryPath/scripts.pory"
	.string "Oh, I'm so thirsty!$"

FieryPath_Text_MayIHaveWater::
# 173 "data/maps/FieryPath/scripts.pory"
	.string "Hey, may I have a bottle of water,\n"
	.string "please?$"

FieryPath_Text_ThankYouVeryMuch::
# 178 "data/maps/FieryPath/scripts.pory"
	.string "Thank you very much!\p"
	.string "{FONT_SMALL}Glug… Glug…\p"
	.string "{FONT_NORMAL}That's better!\p"
	.string "Hey, listen!$"

FieryPath_Text_NoRoomForEgg::
# 185 "data/maps/FieryPath/scripts.pory"
	.string "I've got two Pokémon eggs here,\n"
	.string "but your party is already full of\l"
	.string "Pokémon, you have no room for an egg.\p"
	.string "Could you come back with a free space?$"

FieryPath_Text_WhichEggDoYouWant::
# 192 "data/maps/FieryPath/scripts.pory"
	.string "I've got two Pokémon eggs here.\n"
	.string "One will hatch into {STR_VAR_1},\l"
	.string "the other into {STR_VAR_2}.\p"
	.string "Which one would you like?$"

FieryPath_Text_Sure::
# 199 "data/maps/FieryPath/scripts.pory"
	.string "Sure!$"

FieryPath_Text_HallwayImpractical::
# 203 "data/maps/FieryPath/scripts.pory"
	.string "This hallway is highly impractical,\n"
	.string "don't you think?$"

FieryPath_Text_ReceivedAnEgg::
# 208 "data/maps/FieryPath/scripts.pory"
	.string "{PLAYER} received an egg, which\n"
	.string "will hatch into {STR_VAR_1}.$"

FieryPath_Text_ImTheStrongestTrainer::
# 245 "data/maps/FieryPath/scripts.pory"
	.string "I'm the strongest Trainer lurking\n"
	.string "in this temple. My Pokémon are brutal\l"
	.string "and well trained. They know moves that\l"
	.string "you can only dream of teaching yours.\p"
	.string "If you want to challenge me, I'm in.$"

FieryPath_Text_VeryWellBringItOn::
# 253 "data/maps/FieryPath/scripts.pory"
	.string "Very well, traveler.\n"
	.string "I don't intend to go easy on you.\p"
	.string "Now, bring it on!$"

FieryPath_Text_YouAreTheRealBeast::
# 259 "data/maps/FieryPath/scripts.pory"
	.string "You are the real beast!$"

FieryPath_Text_IHaveNothingMoreToSay::
# 263 "data/maps/FieryPath/scripts.pory"
	.string "Traveler! I have nothing more to say\n"
	.string "to you.\p"
	.string "Don't let any opponent frighten you!$"

FieryPath_Text_IHaveAPresent::
# 269 "data/maps/FieryPath/scripts.pory"
	.string "Excellent, traveler!\n"
	.string "You fight incredibly well!\p"
	.string "I have a present for you.\n"
	.string "You absolutely earned it!$"

FieryPath_Text_ThisIsAMasterBall::
# 276 "data/maps/FieryPath/scripts.pory"
	.string "This is a Master Ball.\n"
	.string "It's the most effective Poké Ball.\p"
	.string "It can catch any wild Pokémon\n"
	.string "and it never fails.\p"
	.string "Don't go waste it on a common Pokémon!$"

FieryPath_Text_ImUpToAnotherFight::
# 284 "data/maps/FieryPath/scripts.pory"
	.string "If you pass by again,\n"
	.string "I'm up for another fight!$"

FieryPath_Text_AssistMeInTraining::
# 294 "data/maps/FieryPath/scripts.pory"
	.string "You!\n"
	.string "Assist me in my training!$"

FieryPath_Text_NotAsPlanned::
# 299 "data/maps/FieryPath/scripts.pory"
	.string "Hmpf!\n"
	.string "Didn't work out quite as planned!$"

FieryPath_Text_LegendaryPokemon::
# 304 "data/maps/FieryPath/scripts.pory"
	.string "I know there's supposed to be a\n"
	.string "legendary creature inside the\l"
	.string "Room of Bagon, but last time I checked,\l"
	.string "it wasn't there.$"

FieryPath_Text_ThisIsntAPlaceForInexperienced::
# 316 "data/maps/FieryPath/scripts.pory"
	.string "This isn't a place for the inexperienced!$"

FieryPath_Text_ITakeItBack::
# 320 "data/maps/FieryPath/scripts.pory"
	.string "I take it back, you aren't inexperenced\n"
	.string "at all.$"

FieryPath_Text_HowIsItGoing::
# 325 "data/maps/FieryPath/scripts.pory"
	.string "How's it going, champ?$"

FieryPath_Text_TodaysYouthIsPathetic::
# 334 "data/maps/FieryPath/scripts.pory"
	.string "Today's youth is pathetic!\n"
	.string "I'll show you how a real Trainer fights!$"

FieryPath_Text_YouGotLucky::
# 339 "data/maps/FieryPath/scripts.pory"
	.string "You got lucky this time!$"

FieryPath_Text_HaveYouFoundDarkrai::
# 343 "data/maps/FieryPath/scripts.pory"
	.string "Youngling!\n"
	.string "Have you found Darkrai yet?\p"
	.string "I heard it patrols a room so dark\n"
	.string "that you can't see your own feet.\p"
	.string "Of course, against my Bug-type Pokémon,\n"
	.string "it's got no chance!$"
