# 1 "data/scripts/pc.pory"

# 2 "data/scripts/pc.pory"
EventScript_PC::
# 3 "data/scripts/pc.pory"
	lockall
# 4 "data/scripts/pc.pory"
	setvar VAR_0x8004, PC_LOCATION_OTHER
# 5 "data/scripts/pc.pory"
	special DoPCTurnOnEffect
# 6 "data/scripts/pc.pory"
	playse SE_PC_ON
# 7 "data/scripts/pc.pory"
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
# 8 "data/scripts/pc.pory"
	goto EventScript_PCMainMenu
# 9 "data/scripts/pc.pory"
	end
# 10 "data/scripts/pc.pory"

# 11 "data/scripts/pc.pory"
EventScript_PCMainMenu::
# 12 "data/scripts/pc.pory"
	message gText_WhichPCShouldBeAccessed
# 13 "data/scripts/pc.pory"
	waitmessage
# 14 "data/scripts/pc.pory"
	special ScriptMenu_CreatePCMultichoice
# 15 "data/scripts/pc.pory"
	waitstate
# 16 "data/scripts/pc.pory"
	goto EventScript_AccessPC
# 17 "data/scripts/pc.pory"
	end
# 18 "data/scripts/pc.pory"

# 19 "data/scripts/pc.pory"
EventScript_AccessPC::
# 20 "data/scripts/pc.pory"
	switch VAR_RESULT
# 21 "data/scripts/pc.pory"
	case 0, EventScript_AccessPokemonStorage
# 22 "data/scripts/pc.pory"
	case 1, EventScript_AccessPlayersPC
# 23 "data/scripts/pc.pory"
	case 2, EventScript_AccessHallOfFame
# 24 "data/scripts/pc.pory"
	case 3, EventScript_TurnOffPC
# 25 "data/scripts/pc.pory"
	case MULTI_B_PRESSED, EventScript_TurnOffPC
# 26 "data/scripts/pc.pory"
	end
# 27 "data/scripts/pc.pory"

# 28 "data/scripts/pc.pory"
EventScript_AccessPlayersPC::
# 29 "data/scripts/pc.pory"
	playse SE_PC_LOGIN
# 30 "data/scripts/pc.pory"
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
# 31 "data/scripts/pc.pory"
	special PlayerPC
# 32 "data/scripts/pc.pory"
	waitstate
# 33 "data/scripts/pc.pory"
	goto EventScript_PCMainMenu
# 34 "data/scripts/pc.pory"
	end
# 35 "data/scripts/pc.pory"

# 36 "data/scripts/pc.pory"
EventScript_AccessPokemonStorage::
# 37 "data/scripts/pc.pory"
	playse SE_PC_LOGIN
# 38 "data/scripts/pc.pory"
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_AccessSomeonesPC
# 39 "data/scripts/pc.pory"
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessLanettesPC
# 40 "data/scripts/pc.pory"
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
# 41 "data/scripts/pc.pory"
	special ShowPokemonStorageSystemPC
# 42 "data/scripts/pc.pory"
	waitstate
# 43 "data/scripts/pc.pory"
	goto EventScript_PCMainMenu
# 44 "data/scripts/pc.pory"
	end
# 45 "data/scripts/pc.pory"

# 46 "data/scripts/pc.pory"
EventScript_AccessSomeonesPC::
# 47 "data/scripts/pc.pory"
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
# 48 "data/scripts/pc.pory"
	return
# 49 "data/scripts/pc.pory"

# 50 "data/scripts/pc.pory"
EventScript_AccessLanettesPC::
# 51 "data/scripts/pc.pory"
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
# 52 "data/scripts/pc.pory"
	return
# 53 "data/scripts/pc.pory"

# 54 "data/scripts/pc.pory"
EventScript_TurnOffPC::
# 55 "data/scripts/pc.pory"
	setvar VAR_0x8004, PC_LOCATION_OTHER
# 56 "data/scripts/pc.pory"
	playse SE_PC_OFF
# 57 "data/scripts/pc.pory"
	special DoPCTurnOffEffect
# 58 "data/scripts/pc.pory"
	releaseall
# 59 "data/scripts/pc.pory"
	end
# 60 "data/scripts/pc.pory"

# 61 "data/scripts/pc.pory"
EventScript_AccessHallOfFame::
# 62 "data/scripts/pc.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_TurnOffPC
# 63 "data/scripts/pc.pory"
	playse SE_PC_LOGIN
# 64 "data/scripts/pc.pory"
	special AccessHallOfFamePC
# 65 "data/scripts/pc.pory"
	waitstate
# 66 "data/scripts/pc.pory"
	goto EventScript_AccessPC
# 67 "data/scripts/pc.pory"
	end
# 68 "data/scripts/pc.pory"

# 69 "data/scripts/pc.pory"
EventScript_AccessPokemonBoxLink::
# 70 "data/scripts/pc.pory"
	playse SE_PC_LOGIN
# 71 "data/scripts/pc.pory"
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
# 72 "data/scripts/pc.pory"
	special ShowPokemonStorageSystemPC
# 73 "data/scripts/pc.pory"
	waitstate
# 74 "data/scripts/pc.pory"
	goto EventScript_TurnOffPC
# 75 "data/scripts/pc.pory"
	end

EventScript_CrystalPC::
# 80 "data/scripts/pc.pory"
	lock
# 81 "data/scripts/pc.pory"
	msgbox Text_CrystalPC, MSGBOX_DEFAULT
# 82 "data/scripts/pc.pory"
	closemessage
# 83 "data/scripts/pc.pory"
	special ShowPokemonStorageSystemPC
# 84 "data/scripts/pc.pory"
	waitstate
# 85 "data/scripts/pc.pory"
	release
	return

