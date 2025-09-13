GraniteCave_StevensRoom_MapScripts::
# 2 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_StevensRoom_EventScript_TryHideStaticEncounter
# 3 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, GraniteCave_StevensRoom_EventScript_TryShowLugia
	.byte 0


GraniteCave_StevensRoom_EventScript_TryHideStaticEncounter::
# 7 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, GraniteCave_StevensRoom_EventScript_TryHideStaticEncounter_1
	return

GraniteCave_StevensRoom_EventScript_TryHideStaticEncounter_1:
# 8 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 9 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq GraniteCave_StevensRoom_EventScript_TryHideStaticEncounter_3
# 9 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GraniteCave_StevensRoom_EventScript_TryHideStaticEncounter_3
	return

GraniteCave_StevensRoom_EventScript_TryHideStaticEncounter_3:
# 10 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	removeobject VAR_LAST_TALKED
	return


GraniteCave_StevensRoom_EventScript_TryShowLugia::
# 16 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_FLUTE, GraniteCave_StevensRoom_EventScript_TryShowLugia_3
	return

GraniteCave_StevensRoom_EventScript_TryShowLugia_1:
# 17 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	clearflag FLAG_HIDE_LUGIA
	return

GraniteCave_StevensRoom_EventScript_TryShowLugia_2:
# 16 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	goto_if_unset FLAG_CAUGHT_LUGIA, GraniteCave_StevensRoom_EventScript_TryShowLugia_1
	return

GraniteCave_StevensRoom_EventScript_TryShowLugia_3:
# 16 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	goto_if_set FLAG_HIDE_LUGIA, GraniteCave_StevensRoom_EventScript_TryShowLugia_2
	return


GraniteCave_StevensRoom_EventScript_Bagon1::
# 22 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	lock
# 23 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	faceplayer
# 24 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	playmoncry SPECIES_BAGON, CRY_MODE_NORMAL
# 25 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitmoncry
# 26 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 27 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setwildbattle SPECIES_BAGON, 21, item = ITEM_LUCKY_EGG
# 28 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	dowildbattle
# 29 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 30 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	release
	return


GraniteCave_StevensRoom_EventScript_Bagon2::
# 34 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	lock
# 35 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	faceplayer
# 36 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	playmoncry SPECIES_BAGON, CRY_MODE_NORMAL
# 37 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitmoncry
# 38 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 39 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setwildbattle SPECIES_BAGON, 22, item = ITEM_X_DEFENSE
# 40 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	dowildbattle
# 41 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 42 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	release
	return


GraniteCave_StevensRoom_EventScript_Bagon3::
# 46 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	lock
# 47 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	faceplayer
# 48 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	playmoncry SPECIES_BAGON, CRY_MODE_NORMAL
# 49 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitmoncry
# 50 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 51 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setwildbattle SPECIES_BAGON, 23, item = ITEM_POKE_DOLL
# 52 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	dowildbattle
# 53 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 54 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	release
	return


GraniteCave_StevensRoom_EventScript_Bagon4::
# 58 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	lock
# 59 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	faceplayer
# 60 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	playmoncry SPECIES_BAGON, CRY_MODE_NORMAL
# 61 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitmoncry
# 62 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 63 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setwildbattle SPECIES_BAGON, 24, item = ITEM_RARE_CANDY
# 64 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	dowildbattle
# 65 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 66 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	release
	return


GraniteCave_StevensRoom_EventScript_Bagon5::
# 70 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	lock
# 71 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	faceplayer
# 72 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	playmoncry SPECIES_BAGON, CRY_MODE_NORMAL
# 73 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitmoncry
# 74 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 75 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setwildbattle SPECIES_BAGON, 25, item = ITEM_FULL_RESTORE
# 76 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	dowildbattle
# 77 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 78 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	release
	return


GraniteCave_StevensRoom_EventScript_Lugia::
# 82 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	lock
# 83 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	faceplayer
# 84 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_NORMAL
# 85 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	msgbox GraniteCave_StevensRoom_Text_FightLugia, MSGBOX_YESNO
# 86 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq GraniteCave_StevensRoom_EventScript_Lugia_2
# 99 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	closemessage
GraniteCave_StevensRoom_EventScript_Lugia_1:
# 101 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	release
	return

GraniteCave_StevensRoom_EventScript_Lugia_2:
# 87 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	closemessage
# 88 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 89 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setwildbattle SPECIES_LUGIA, 45, item = ITEM_MAX_REVIVE
# 90 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 91 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	waitstate
# 92 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 93 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 94 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq GraniteCave_StevensRoom_EventScript_Lugia_5
	goto GraniteCave_StevensRoom_EventScript_Lugia_1

GraniteCave_StevensRoom_EventScript_Lugia_5:
# 95 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	setflag FLAG_CAUGHT_LUGIA
# 96 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	giveitem ITEM_SACRED_ASH, 1
	goto GraniteCave_StevensRoom_EventScript_Lugia_1


GraniteCave_StevensRoom_Text_FightLugia::
# 104 "data/maps/GraniteCave_StevensRoom/scripts.pory"
	.string "This Pokémon is staring at you calmly.\n"
	.string "Will you fight it?$"
