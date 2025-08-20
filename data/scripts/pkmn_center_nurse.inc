# 1 "data/scripts/pkmn_center_nurse.pory"

# 2 "data/scripts/pkmn_center_nurse.pory"
Common_EventScript_PkmnCenterNurse::
# 3 "data/scripts/pkmn_center_nurse.pory"
	lock
# 4 "data/scripts/pkmn_center_nurse.pory"
	faceplayer
# 5 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_0x8004, 0
# 6 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, CountPlayerTrainerStars
# 7 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, 4, EventScript_PkmnCenterNurse_GoldCard
# 8 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_YESNO
# 9 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
# 10 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
# 11 "data/scripts/pkmn_center_nurse.pory"
	end
# 12 "data/scripts/pkmn_center_nurse.pory"

# 13 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_Goodbye::
# 14 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain
# 15 "data/scripts/pkmn_center_nurse.pory"
	return
# 16 "data/scripts/pkmn_center_nurse.pory"

# 17 "data/scripts/pkmn_center_nurse.pory"
@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
# 18 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_HealPkmn::
# 19 "data/scripts/pkmn_center_nurse.pory"
	incrementgamestat GAME_STAT_USED_POKECENTER
# 20 "data/scripts/pkmn_center_nurse.pory"
	call_if_eq VAR_0x8004, 0, EventScript_PkmnCenterNurse_IllTakeYourPkmn
# 21 "data/scripts/pkmn_center_nurse.pory"
	call_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_IllTakeYourPkmn2
# 22 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 23 "data/scripts/pkmn_center_nurse.pory"
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
# 24 "data/scripts/pkmn_center_nurse.pory"
	goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
# 25 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
# 26 "data/scripts/pkmn_center_nurse.pory"
	end
# 27 "data/scripts/pkmn_center_nurse.pory"

# 28 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_IllTakeYourPkmn::
# 29 "data/scripts/pkmn_center_nurse.pory"
	message gText_IllTakeYourPkmn
# 30 "data/scripts/pkmn_center_nurse.pory"
	return
# 31 "data/scripts/pkmn_center_nurse.pory"

# 32 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_IllTakeYourPkmn2::
# 33 "data/scripts/pkmn_center_nurse.pory"
	message gText_IllTakeYourPkmn2
# 34 "data/scripts/pkmn_center_nurse.pory"
	return
# 35 "data/scripts/pkmn_center_nurse.pory"

# 36 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_TakeAndHealPkmn::
# 37 "data/scripts/pkmn_center_nurse.pory"
	hidefollower 0
# 38 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Turn
# 39 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 40 "data/scripts/pkmn_center_nurse.pory"
	dofieldeffect FLDEFF_POKECENTER_HEAL
# 41 "data/scripts/pkmn_center_nurse.pory"
.if OW_UNION_DISABLE_CHECK == FALSE && OW_FLAG_MOVE_UNION_ROOM_CHECK != 0
# 42 "data/scripts/pkmn_center_nurse.pory"
	setflag OW_FLAG_MOVE_UNION_ROOM_CHECK
# 43 "data/scripts/pkmn_center_nurse.pory"
	call CableClub_OnResume
# 44 "data/scripts/pkmn_center_nurse.pory"
	clearflag OW_FLAG_MOVE_UNION_ROOM_CHECK
# 45 "data/scripts/pkmn_center_nurse.pory"
.endif
# 46 "data/scripts/pkmn_center_nurse.pory"
	waitfieldeffect FLDEFF_POKECENTER_HEAL
# 47 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
# 48 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 49 "data/scripts/pkmn_center_nurse.pory"
	special HealPlayerParty
# 50 "data/scripts/pkmn_center_nurse.pory"
	callnative UpdateFollowingPokemon
# 51 "data/scripts/pkmn_center_nurse.pory"
	return
# 52 "data/scripts/pkmn_center_nurse.pory"

# 53 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
# 54 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
# 55 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterNurse_ReturnPkmn
# 56 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
# 57 "data/scripts/pkmn_center_nurse.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 58 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn
# 59 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
# 60 "data/scripts/pkmn_center_nurse.pory"
	end
# 61 "data/scripts/pkmn_center_nurse.pory"

# 62 "data/scripts/pkmn_center_nurse.pory"
@ VAR_0x8004 is 1 when player has Gold Card
# 63 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_ReturnPkmn::
# 64 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_ReturnPkmn2
# 65 "data/scripts/pkmn_center_nurse.pory"
	message gText_RestoredPkmnToFullHealth
# 66 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 67 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
# 68 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 69 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain
# 70 "data/scripts/pkmn_center_nurse.pory"
	return
# 71 "data/scripts/pkmn_center_nurse.pory"

# 72 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_ReturnPkmn2::
# 73 "data/scripts/pkmn_center_nurse.pory"
	message gText_ThankYouForWaiting
# 74 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 75 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
# 76 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 77 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain2
# 78 "data/scripts/pkmn_center_nurse.pory"
	return
# 79 "data/scripts/pkmn_center_nurse.pory"

# 80 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
# 81 "data/scripts/pkmn_center_nurse.pory"
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
# 82 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
# 83 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
# 84 "data/scripts/pkmn_center_nurse.pory"
	message CableClub_Text_PlayerIsWaiting
# 85 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 86 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
# 87 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 88 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain
# 89 "data/scripts/pkmn_center_nurse.pory"
	return
# 90 "data/scripts/pkmn_center_nurse.pory"

# 91 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_CheckPokerus::
# 92 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, IsPokerusInParty
# 93 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ExplainPokerus
# 94 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
# 95 "data/scripts/pkmn_center_nurse.pory"
	end
# 96 "data/scripts/pkmn_center_nurse.pory"

# 97 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_ExplainPokerus::
# 98 "data/scripts/pkmn_center_nurse.pory"
	message gText_PokerusExplanation
# 99 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_POKERUS_EXPLAINED
# 100 "data/scripts/pkmn_center_nurse.pory"
	return
# 101 "data/scripts/pkmn_center_nurse.pory"

# 102 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_GoldCard::
# 103 "data/scripts/pkmn_center_nurse.pory"
	goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
# 104 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_NURSE_MENTIONS_GOLD_CARD
# 105 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
# 106 "data/scripts/pkmn_center_nurse.pory"
	playse SE_PIN
# 107 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
# 108 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 109 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_Delay48
# 110 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 111 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_NoticesGoldCard, MSGBOX_YESNO
# 112 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
# 113 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain2
# 114 "data/scripts/pkmn_center_nurse.pory"
	return
# 115 "data/scripts/pkmn_center_nurse.pory"

# 116 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_AskForUsual::
# 117 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_YouWantTheUsual, MSGBOX_YESNO
# 118 "data/scripts/pkmn_center_nurse.pory"
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
# 119 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain2
# 120 "data/scripts/pkmn_center_nurse.pory"
	return
# 121 "data/scripts/pkmn_center_nurse.pory"

# 122 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_GoldCardHealPkmn::
# 123 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_0x8004, 1
# 124 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_HealPkmn
# 125 "data/scripts/pkmn_center_nurse.pory"
	end
# 126 "data/scripts/pkmn_center_nurse.pory"

# 127 "data/scripts/pkmn_center_nurse.pory"
Movement_PkmnCenterNurse_Bow:
# 128 "data/scripts/pkmn_center_nurse.pory"
	nurse_joy_bow
# 129 "data/scripts/pkmn_center_nurse.pory"
	delay_4
# 130 "data/scripts/pkmn_center_nurse.pory"
	step_end
# 131 "data/scripts/pkmn_center_nurse.pory"

# 132 "data/scripts/pkmn_center_nurse.pory"
Movement_PkmnCenterNurse_Turn:
# 133 "data/scripts/pkmn_center_nurse.pory"
	walk_in_place_faster_left
# 134 "data/scripts/pkmn_center_nurse.pory"
	step_end

EventScript_CrystalHeal::
# 139 "data/scripts/pkmn_center_nurse.pory"
	lock
# 140 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_CrystalHeal, MSGBOX_DEFAULT
# 141 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 142 "data/scripts/pkmn_center_nurse.pory"
	playfanfare MUS_HEAL
# 143 "data/scripts/pkmn_center_nurse.pory"
	waitfanfare
# 144 "data/scripts/pkmn_center_nurse.pory"
	special HealPlayerParty
# 145 "data/scripts/pkmn_center_nurse.pory"
	closemessage
# 146 "data/scripts/pkmn_center_nurse.pory"
	release
	return

