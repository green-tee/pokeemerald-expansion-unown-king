Route103_MapScripts::
# 2 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route103_EventScript_TryRemoveMilotic
# 3 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route103_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route103_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/Route103/scripts.pory"
	map_script_2 VAR_OUTDOOR_TORNADUS_STATE, 1, Route101_EventScript_WildTornadusEncounter
	.2byte 0


Route103_EventScript_TryRemoveMilotic::
# 9 "data/maps/Route103/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route103_EventScript_TryRemoveMilotic_1
	return

Route103_EventScript_TryRemoveMilotic_1:
# 10 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 11 "data/maps/Route103/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Route103_EventScript_TryRemoveMilotic_3
	return

Route103_EventScript_TryRemoveMilotic_3:
# 12 "data/maps/Route103/scripts.pory"
	removeobject VAR_LAST_TALKED
	return


Route103_EventScript_Milotic::
# 18 "data/maps/Route103/scripts.pory"
	lock
# 19 "data/maps/Route103/scripts.pory"
	faceplayer
# 20 "data/maps/Route103/scripts.pory"
	playmoncry SPECIES_MILOTIC, CRY_MODE_NORMAL
# 21 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_Milotic, MSGBOX_DEFAULT
# 22 "data/maps/Route103/scripts.pory"
	waitmoncry
# 23 "data/maps/Route103/scripts.pory"
	closemessage
# 24 "data/maps/Route103/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 25 "data/maps/Route103/scripts.pory"
	createmon 1, 0, SPECIES_MILOTIC, 35, move1 = MOVE_DRAINING_KISS, move2 = MOVE_WATER_PULSE, move3 = MOVE_DRAGON_TAIL, move4 = MOVE_AVALANCHE, abilityNum = 0, isShiny = FALSE
# 26 "data/maps/Route103/scripts.pory"
	special BattleSetup_StartBossBattle
# 27 "data/maps/Route103/scripts.pory"
	waitstate
# 28 "data/maps/Route103/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 29 "data/maps/Route103/scripts.pory"
	giveitem ITEM_HM_DIVE
# 30 "data/maps/Route103/scripts.pory"
	setflag FLAG_BADGE07_GET
# 31 "data/maps/Route103/scripts.pory"
	release
	return


Route103_EventScript_RepelsMerchant::
# 43 "data/maps/Route103/scripts.pory"
	lock
# 44 "data/maps/Route103/scripts.pory"
	faceplayer
# 45 "data/maps/Route103/scripts.pory"
	goto_if_set FLAG_RECEIVED_FIRST_REPELS, Route103_EventScript_RepelsMerchant_2
# 48 "data/maps/Route103/scripts.pory"
	call Route103_EventScript_RepelsMerchant_BeforeBuyingFirstRepels
Route103_EventScript_RepelsMerchant_1:
# 50 "data/maps/Route103/scripts.pory"
	release
	return

Route103_EventScript_RepelsMerchant_2:
# 46 "data/maps/Route103/scripts.pory"
	call Route103_EventScript_RepelsMerchant_AfterBuyingFirstRepels
	goto Route103_EventScript_RepelsMerchant_1


Route103_EventScript_RepelsMerchant_AfterBuyingFirstRepels:
# 56 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ThanksForThePurchase, MSGBOX_DEFAULT
# 57 "data/maps/Route103/scripts.pory"
	closemessage
	return


Route103_EventScript_RepelsMerchant_BeforeBuyingFirstRepels:
# 61 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_DoYouNeedRepels, MSGBOX_YESNO
# 62 "data/maps/Route103/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route103_EventScript_RepelsMerchant_BeforeBuyingFirstRepels_1
# 87 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ComeBackIfYouChangeYourMind, MSGBOX_DEFAULT
# 88 "data/maps/Route103/scripts.pory"
	closemessage
	return

Route103_EventScript_RepelsMerchant_BeforeBuyingFirstRepels_1:
# 63 "data/maps/Route103/scripts.pory"
	checkmoney 2000
# 64 "data/maps/Route103/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Route103_EventScript_RepelsMerchant_BeforeBuyingFirstRepels_4
# 82 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_YouDontHaveMoney, MSGBOX_DEFAULT
# 83 "data/maps/Route103/scripts.pory"
	closemessage
	return

Route103_EventScript_RepelsMerchant_BeforeBuyingFirstRepels_4:
# 65 "data/maps/Route103/scripts.pory"
	checkitemspace ITEM_REPEL, 5
# 66 "data/maps/Route103/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Route103_EventScript_RepelsMerchant_BeforeBuyingFirstRepels_7
# 77 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_YouDontHaveRoom, MSGBOX_DEFAULT
# 78 "data/maps/Route103/scripts.pory"
	closemessage
	return

Route103_EventScript_RepelsMerchant_BeforeBuyingFirstRepels_7:
# 69 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_SmartChoice, MSGBOX_DEFAULT
# 70 "data/maps/Route103/scripts.pory"
	removemoney 2000
# 71 "data/maps/Route103/scripts.pory"
	giveitem ITEM_REPEL, 5
# 72 "data/maps/Route103/scripts.pory"
	setflag FLAG_RECEIVED_FIRST_REPELS
# 73 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ThanksForThePurchase, MSGBOX_DEFAULT
# 74 "data/maps/Route103/scripts.pory"
	closemessage
	return


# 142 "data/maps/Route103/scripts.pory"
Route103_Movement_RepelsMerchantRunInside:
# 143 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 143 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 144 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 144 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 144 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 144 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 144 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 144 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 144 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 144 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 144 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 145 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 145 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 145 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 145 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 145 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 145 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 145 "data/maps/Route103/scripts.pory"
	walk_fast_right
	step_end

# 148 "data/maps/Route103/scripts.pory"
Route103_Movement_RepelsMerchantRunInsideDodge:
# 149 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 150 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 150 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 151 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 151 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 151 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 151 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 151 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 151 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 151 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 151 "data/maps/Route103/scripts.pory"
	walk_fast_down
# 152 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 152 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 152 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 152 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 152 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 152 "data/maps/Route103/scripts.pory"
	walk_fast_right
# 152 "data/maps/Route103/scripts.pory"
	walk_fast_right
	step_end

Route103_EventScript_Scoundrel::
# 156 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_SCOUNDREL_WALTER, Route103_Text_ISpottedYou, Route103_Text_IJustHadToOpenMyMouth
# 157 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IHaveAWaterStone, MSGBOX_AUTOCLOSE
	return


Route103_EventScript_Fighter::
# 176 "data/maps/Route103/scripts.pory"
	lock
# 177 "data/maps/Route103/scripts.pory"
	faceplayer
# 178 "data/maps/Route103/scripts.pory"
	goto_if_set FLAG_TEMP_1, Route103_EventScript_Fighter_2
# 182 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ImAFighter, MSGBOX_YESNO
# 183 "data/maps/Route103/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route103_EventScript_Fighter_5
# 192 "data/maps/Route103/scripts.pory"
	closemessage
Route103_EventScript_Fighter_1:
# 195 "data/maps/Route103/scripts.pory"
	release
	return

Route103_EventScript_Fighter_2:
# 179 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_HaveYouSeenMilotic, MSGBOX_DEFAULT
# 180 "data/maps/Route103/scripts.pory"
	closemessage
	goto Route103_EventScript_Fighter_1

Route103_EventScript_Fighter_5:
# 184 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LetsDoOurBest, MSGBOX_DEFAULT
# 185 "data/maps/Route103/scripts.pory"
	closemessage
# 186 "data/maps/Route103/scripts.pory"
	playbgm MUS_VS_WILD, FALSE
# 187 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_FIGHTER_SARAH, Route103_Text_IAcceptMyDefeat
# 188 "data/maps/Route103/scripts.pory"
	setflag FLAG_TEMP_1
# 189 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IWasHopingToWin, MSGBOX_DEFAULT
# 190 "data/maps/Route103/scripts.pory"
	closemessage
	goto Route103_EventScript_Fighter_1


Route103_EventScript_Breeder::
# 234 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_BREEDER_LEO, Route103_Text_LookWhatMyPokemonCanDo, Route103_Text_PrettyCool
# 235 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IfYouCouldFly, MSGBOX_AUTOCLOSE
	return


Route103_Text_Milotic::
# 34 "data/maps/Route103/scripts.pory"
	.string "Wow!\n"
	.string "This Pokémon is gorgeous!\p"
	.string "…\p"
	.string "Oh no!\n"
	.string "It's hostile!$"

Route103_Text_DoYouNeedRepels::
# 92 "data/maps/Route103/scripts.pory"
	.string "Oh, a traveler!\n"
	.string "How are you doing?\p"
	.string "Moving through the temple can feel like\n"
	.string "a slog, am I right?\p"
	.string "I can help you a little.\n"
	.string "How about some Repels? I'm selling\l"
	.string "5 bottles for ¥2,000. Deal?$"

Route103_Text_SmartChoice::
# 102 "data/maps/Route103/scripts.pory"
	.string "Well, then. Here you are.\n"
	.string "A smart choice, if I do say so myself!$"

Route103_Text_YouDontHaveMoney::
# 107 "data/maps/Route103/scripts.pory"
	.string "Oh, what a shame! You're broke.\n"
	.string "I'm sorry, but I can't give you\l"
	.string "these Repels for free.$"

Route103_Text_YouDontHaveRoom::
# 113 "data/maps/Route103/scripts.pory"
	.string "Not so fast!\n"
	.string "Your bag has no room for these Repels.\l"
	.string "Make some space and come back!$"

Route103_Text_ComeBackIfYouChangeYourMind::
# 119 "data/maps/Route103/scripts.pory"
	.string "Oh, well.\n"
	.string "Come back if you change your mind!$"

Route103_Text_ThanksForThePurchase::
# 124 "data/maps/Route103/scripts.pory"
	.string "Thank you for the purchase!\n"
	.string "I hope these make your journey easier!\p"
	.string "What do you do if you run of of them?\n"
	.string "Well… good question.\p"
	.string "A buddy of mine is hanging around\n"
	.string "in the Easter Wing of the temple\l"
	.string "hoping to start a business selling\l"
	.string "more Repels.\p"
	.string "But I think he told me he needs some\n"
	.string "specific ingredients.\l"
	.string "I can't help you with that,\l"
	.string "but I can still try doing\l"
	.string "something useful for you. You see,\l"
	.string "I've been on the lookout for rumors\l"
	.string "about legendary Pokémon!$"

Route103_Text_ISpottedYou::
# 160 "data/maps/Route103/scripts.pory"
	.string "I spotted you, weakling!$"

Route103_Text_IJustHadToOpenMyMouth::
# 164 "data/maps/Route103/scripts.pory"
	.string "I just had to open my mouth, huh?$"

Route103_Text_IHaveAWaterStone::
# 168 "data/maps/Route103/scripts.pory"
	.string "I used a Water Stone on one of my\n"
	.string "Lombre and it turned into a Ludicolo.\l"
	.string "I wish I had a Staryu and a Feebas\l"
	.string "as well!$"

Route103_Text_ImAFighter::
# 198 "data/maps/Route103/scripts.pory"
	.string "I'm a Fighter, guess what I like doing\n"
	.string "the most.\l"
	.string "Battling, of course!\p"
	.string "Would you accept my challenge?$"

Route103_Text_LetsDoOurBest::
# 205 "data/maps/Route103/scripts.pory"
	.string "Perfect!\n"
	.string "Let's both do our best!$"

Route103_Text_IAcceptMyDefeat::
# 210 "data/maps/Route103/scripts.pory"
	.string "I accept my defeat with dignity.\n"
	.string "That's the way of us Fighters!$"

Route103_Text_IWasHopingToWin::
# 215 "data/maps/Route103/scripts.pory"
	.string "I won't lie, I was hoping to win\n"
	.string "this one.\p"
	.string "But it doesn't matter, I'm always\n"
	.string "in the mood for another battle.$"

Route103_Text_HaveYouSeenMilotic::
# 222 "data/maps/Route103/scripts.pory"
	.string "Have you seen the majestic creature\n"
	.string "on the pond's surface?\l"
	.string "It's very tanky, a damage sponge,\l"
	.string "if you will.\p"
	.string "If it had a Flame Orb along, it could\n"
	.string "become brutal!\p"
	.string "Oh, by the way, we should battle again\n"
	.string "in the future!$"

Route103_Text_LookWhatMyPokemonCanDo::
# 238 "data/maps/Route103/scripts.pory"
	.string "Look what my Pokémon can do!$"

Route103_Text_PrettyCool::
# 242 "data/maps/Route103/scripts.pory"
	.string "See? Pretty cool, huh?$"

Route103_Text_IfYouCouldFly::
# 246 "data/maps/Route103/scripts.pory"
	.string "If you could fly, you could reach\n"
	.string "the top of the temple and see\l"
	.string "what's there.\l"
	.string "Maybe… a legendary Pokémon?$"
