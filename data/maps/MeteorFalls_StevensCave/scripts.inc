MeteorFalls_StevensCave_MapScripts::
# 2 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MeteorFalls_StevensCave_TryRemoveTornadus
	.byte 0


MeteorFalls_StevensCave_TryRemoveTornadus::
# 6 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, MeteorFalls_StevensCave_TryRemoveTornadus_1
	return

MeteorFalls_StevensCave_TryRemoveTornadus_1:
# 7 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 8 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MeteorFalls_StevensCave_TryRemoveTornadus_3
	return

MeteorFalls_StevensCave_TryRemoveTornadus_3:
# 9 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	removeobject VAR_LAST_TALKED
	return


MeteorFalls_StevensCave_EventScript_Tornadus::
# 15 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	lock
# 16 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	faceplayer
# 17 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	playmoncry SPECIES_TORNADUS, CRY_MODE_NORMAL
# 20 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	msgbox MeteorFalls_StevensCave_Text_Tornadus, MSGBOX_DEFAULT
# 21 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	waitmoncry
# 22 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	closemessage
# 23 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 24 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	createmon 1, 0, SPECIES_TORNADUS, 45, move1 = MOVE_SWAGGER, move2 = MOVE_AIR_SLASH, move3 = MOVE_CRUNCH, move4 = MOVE_EXTRASENSORY, abilityNum = 0, isShiny = FALSE
# 25 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	special BattleSetup_StartBossBattle
# 26 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	waitstate
# 27 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 28 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	finditem ITEM_HM_FLY, 1
# 29 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	setflag FLAG_BADGE06_GET
# 30 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	clearflag FLAG_HIDE_LUGIA
# 31 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	release
	return


MeteorFalls_StevensCave_EventScript_Inscription::
# 43 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	lock
# 44 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	msgbox MeteorFalls_StevensCave_Text_NeedFly, MSGBOX_UNOWNCRYPT
# 45 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	release
	return


MeteorFalls_StevensCave_Text_Tornadus::
# 34 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "This Pokémon looks annoyed.\n"
	.string "Did the flute lure it here?\p"
	.string "…\p"
	.string "Oh!\n"
	.string "It's about to attack!$"

MeteorFalls_StevensCave_Text_NeedFly::
# 48 "data/maps/MeteorFalls_StevensCave/scripts.pory"
	.string "Those who can soar will reach\n"
	.string "the place where the Unown King\l"
	.string "is imprisoned.\p"
	.string "The master of flight appears\n"
	.string "when the Melody of Awakening is heard.$"
