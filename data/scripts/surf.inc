EventScript_UseSurf::
# 2 "data/scripts/surf.pory"
	lockall
# 3 "data/scripts/surf.pory"
	checkpartymove MOVE_SURF
# 4 "data/scripts/surf.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_UseSurf_2
# 13 "data/scripts/surf.pory"
	call EventScript_PrepareSurf
EventScript_UseSurf_1:
# 15 "data/scripts/surf.pory"
	releaseall
	return

EventScript_UseSurf_2:
# 5 "data/scripts/surf.pory"
	checkpartylearnable MOVE_SURF
# 6 "data/scripts/surf.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_UseSurf_5
# 10 "data/scripts/surf.pory"
	call EventScript_PrepareSurf
	goto EventScript_UseSurf_1

EventScript_UseSurf_5:
# 7 "data/scripts/surf.pory"
	msgbox gText_CantUseSurf, MSGBOX_DEFAULT
# 8 "data/scripts/surf.pory"
	closemessage
	goto EventScript_UseSurf_1


EventScript_PrepareSurf::
# 19 "data/scripts/surf.pory"
	setfieldeffectargument 0, VAR_RESULT
# 20 "data/scripts/surf.pory"
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
# 21 "data/scripts/surf.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PrepareSurf_1
# 25 "data/scripts/surf.pory"
	closemessage
	return

EventScript_PrepareSurf_1:
# 22 "data/scripts/surf.pory"
	closemessage
# 23 "data/scripts/surf.pory"
	dofieldeffect FLDEFF_USE_SURF
	return


EventScript_CannotUseSurf::
# 30 "data/scripts/surf.pory"
	lockall
# 31 "data/scripts/surf.pory"
	msgbox gText_CantUseSurf, MSGBOX_DEFAULT
# 32 "data/scripts/surf.pory"
	closemessage
# 33 "data/scripts/surf.pory"
	releaseall
	return

