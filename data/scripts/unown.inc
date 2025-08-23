EventScript_FoundUnownCommon:
# 2 "data/scripts/unown.pory"
	lock
# 3 "data/scripts/unown.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 4 "data/scripts/unown.pory"
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
# 5 "data/scripts/unown.pory"
	bufferunownform STR_VAR_1, VAR_0x8004
# 6 "data/scripts/unown.pory"
	msgbox Text_FoundUnownForm, MSGBOX_DEFAULT
# 7 "data/scripts/unown.pory"
	closemessage
# 8 "data/scripts/unown.pory"
	fadescreen FADE_TO_BLACK
# 9 "data/scripts/unown.pory"
	removeobject VAR_LAST_TALKED
# 10 "data/scripts/unown.pory"
	fadescreen FADE_FROM_BLACK
# 11 "data/scripts/unown.pory"
	release
	return


EventScript_FoundUnown_A::
# 19 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_A
# 20 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_B::
# 24 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_B
# 25 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_C::
# 29 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_C
# 30 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_D::
# 34 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_D
# 35 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_E::
# 39 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_E
# 40 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_F::
# 44 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_F
# 45 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_G::
# 49 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_G
# 50 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_H::
# 54 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_H
# 55 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_I::
# 59 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_I
# 60 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_J::
# 64 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_J
# 65 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_K::
# 69 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_K
# 70 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_L::
# 74 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_L
# 75 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_M::
# 79 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_M
# 80 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_N::
# 84 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_N
# 85 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_O::
# 89 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_O
# 90 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_P::
# 94 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_P
# 95 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_Q::
# 99 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_Q
# 100 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_R::
# 104 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_R
# 105 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_S::
# 109 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_S
# 110 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_T::
# 114 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_T
# 115 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_U::
# 119 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_U
# 120 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_V::
# 124 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_V
# 125 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_W::
# 129 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_W
# 130 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_X::
# 134 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_X
# 135 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_Y::
# 139 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_Y
# 140 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


EventScript_FoundUnown_Z::
# 144 "data/scripts/unown.pory"
	setvar VAR_0x8004, UNOWN_FORM_Z
# 145 "data/scripts/unown.pory"
	call EventScript_FoundUnownCommon
	return


Text_FoundUnownForm::
# 14 "data/scripts/unown.pory"
	.string "You found an Unown: form {STR_VAR_1}.$"
