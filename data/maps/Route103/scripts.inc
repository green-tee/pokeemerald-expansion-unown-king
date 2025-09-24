Route103_MapScripts::
# 2 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route103_EventScript_TryRemoveMilotic
	.byte 0


Route103_EventScript_TryRemoveMilotic::
# 6 "data/maps/Route103/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route103_EventScript_TryRemoveMilotic_1
	return

Route103_EventScript_TryRemoveMilotic_1:
# 7 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 8 "data/maps/Route103/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Route103_EventScript_TryRemoveMilotic_3
	return

Route103_EventScript_TryRemoveMilotic_3:
# 9 "data/maps/Route103/scripts.pory"
	removeobject VAR_LAST_TALKED
	return


Route103_EventScript_Milotic::
# 15 "data/maps/Route103/scripts.pory"
	lock
# 16 "data/maps/Route103/scripts.pory"
	faceplayer
# 17 "data/maps/Route103/scripts.pory"
	playmoncry SPECIES_MILOTIC, CRY_MODE_NORMAL
# 18 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_Milotic, MSGBOX_DEFAULT
# 19 "data/maps/Route103/scripts.pory"
	waitmoncry
# 20 "data/maps/Route103/scripts.pory"
	closemessage
# 21 "data/maps/Route103/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 22 "data/maps/Route103/scripts.pory"
	createmon 1, 0, SPECIES_MILOTIC, 35, move1 = MOVE_DRAINING_KISS, move2 = MOVE_WATER_PULSE, move3 = MOVE_DRAGON_TAIL, move4 = MOVE_AVALANCHE, abilityNum = 0, isShiny = FALSE
# 23 "data/maps/Route103/scripts.pory"
	special BattleSetup_StartBossBattle
# 24 "data/maps/Route103/scripts.pory"
	waitstate
# 25 "data/maps/Route103/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 26 "data/maps/Route103/scripts.pory"
	giveitem ITEM_HM_DIVE
# 27 "data/maps/Route103/scripts.pory"
	setflag FLAG_BADGE07_GET
# 28 "data/maps/Route103/scripts.pory"
	release
	return


Route103_EventScript_Scoundrel::
# 40 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_SCOUNDREL_WALTER, Route103_Text_ISpottedYou, Route103_Text_IJustHadToOpenMyMouth
# 41 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IHaveAWaterStone, MSGBOX_AUTOCLOSE
	return


Route103_EventScript_Fighter::
# 60 "data/maps/Route103/scripts.pory"
	lock
# 61 "data/maps/Route103/scripts.pory"
	faceplayer
# 62 "data/maps/Route103/scripts.pory"
	goto_if_set FLAG_TEMP_1, Route103_EventScript_Fighter_2
# 66 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ImAFighter, MSGBOX_YESNO
# 67 "data/maps/Route103/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route103_EventScript_Fighter_5
# 76 "data/maps/Route103/scripts.pory"
	closemessage
Route103_EventScript_Fighter_1:
# 79 "data/maps/Route103/scripts.pory"
	release
	return

Route103_EventScript_Fighter_2:
# 63 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_HaveYouSeenMilotic, MSGBOX_DEFAULT
# 64 "data/maps/Route103/scripts.pory"
	closemessage
	goto Route103_EventScript_Fighter_1

Route103_EventScript_Fighter_5:
# 68 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LetsDoOurBest, MSGBOX_DEFAULT
# 69 "data/maps/Route103/scripts.pory"
	closemessage
# 70 "data/maps/Route103/scripts.pory"
	playbgm MUS_VS_WILD, FALSE
# 71 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_FIGHTER_SARAH, Route103_Text_IAcceptMyDefeat
# 72 "data/maps/Route103/scripts.pory"
	setflag FLAG_TEMP_1
# 73 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IWasHopingToWin, MSGBOX_DEFAULT
# 74 "data/maps/Route103/scripts.pory"
	closemessage
	goto Route103_EventScript_Fighter_1


Route103_EventScript_Breeder::
# 118 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_BREEDER_LEO, Route103_Text_LookWhatMyPokemonCanDo, Route103_Text_PrettyCool
# 119 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IfYouCouldFly, MSGBOX_AUTOCLOSE
	return


Route103_Text_Milotic::
# 31 "data/maps/Route103/scripts.pory"
	.string "Wow!\n"
	.string "This Pokémon is gorgeous!\p"
	.string "…\p"
	.string "Oh no!\n"
	.string "It's hostile!$"

Route103_Text_ISpottedYou::
# 44 "data/maps/Route103/scripts.pory"
	.string "I spotted you, weakling!$"

Route103_Text_IJustHadToOpenMyMouth::
# 48 "data/maps/Route103/scripts.pory"
	.string "I just had to open my mouth, huh?$"

Route103_Text_IHaveAWaterStone::
# 52 "data/maps/Route103/scripts.pory"
	.string "I used a Water Stone on one of my\n"
	.string "Lombre and it turned into a Ludicolo.\l"
	.string "I wish I had a Staryu and a Feebas\l"
	.string "as well!$"

Route103_Text_ImAFighter::
# 82 "data/maps/Route103/scripts.pory"
	.string "I'm a Fighter, guess what I like doing\n"
	.string "the most.\l"
	.string "Battling, of course!\p"
	.string "Would you accept my challenge?$"

Route103_Text_LetsDoOurBest::
# 89 "data/maps/Route103/scripts.pory"
	.string "Perfect!\n"
	.string "Let's both do our best!$"

Route103_Text_IAcceptMyDefeat::
# 94 "data/maps/Route103/scripts.pory"
	.string "I accept my defeat with dignity.\n"
	.string "That's the way of us Fighters!$"

Route103_Text_IWasHopingToWin::
# 99 "data/maps/Route103/scripts.pory"
	.string "I won't lie, I was hoping to win\n"
	.string "this one.\p"
	.string "But it doesn't matter, I'm always\n"
	.string "in the mood for another battle.$"

Route103_Text_HaveYouSeenMilotic::
# 106 "data/maps/Route103/scripts.pory"
	.string "Have you seen the majestic creature\n"
	.string "on the pond's surface?\l"
	.string "It's very tanky, a damage sponge,\l"
	.string "if you will.\p"
	.string "If it had a Flame Orb along, it could\n"
	.string "become brutal!\p"
	.string "Oh, by the way, we should battle again\n"
	.string "in the future!$"

Route103_Text_LookWhatMyPokemonCanDo::
# 122 "data/maps/Route103/scripts.pory"
	.string "Look what my Pokémon can do!$"

Route103_Text_PrettyCool::
# 126 "data/maps/Route103/scripts.pory"
	.string "See? Pretty cool, huh?$"

Route103_Text_IfYouCouldFly::
# 130 "data/maps/Route103/scripts.pory"
	.string "If you could fly, you could reach\n"
	.string "the top of the temple and see\l"
	.string "what's there."
	.string "\lMaybe… a legendary Pokémon?$"
