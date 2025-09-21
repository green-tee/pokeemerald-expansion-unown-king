Route102_MapScripts::
	.byte 0


Route102_EventScript_Scoundrel::
# 4 "data/maps/Route102/scripts.pory"
	lock
# 5 "data/maps/Route102/scripts.pory"
	faceplayer
# 6 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_TEMP_1, Route102_EventScript_Scoundrel_2
# 10 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_WantToHaveAFight, MSGBOX_YESNO
# 11 "data/maps/Route102/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route102_EventScript_Scoundrel_5
# 21 "data/maps/Route102/scripts.pory"
	closemessage
Route102_EventScript_Scoundrel_1:
# 24 "data/maps/Route102/scripts.pory"
	release
	return

Route102_EventScript_Scoundrel_2:
# 7 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_WeCanBattleAgain, MSGBOX_DEFAULT
# 8 "data/maps/Route102/scripts.pory"
	closemessage
	goto Route102_EventScript_Scoundrel_1

Route102_EventScript_Scoundrel_5:
# 12 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_DontFallDown, MSGBOX_DEFAULT
# 13 "data/maps/Route102/scripts.pory"
	closemessage
# 14 "data/maps/Route102/scripts.pory"
	playbgm MUS_VS_WILD, FALSE
# 15 "data/maps/Route102/scripts.pory"
	trainerbattle_no_intro TRAINER_SCOUNDREL_MORPHEUS, Route102_Text_ScoundrelDefeated
# 16 "data/maps/Route102/scripts.pory"
	setflag FLAG_TEMP_1
# 17 "data/maps/Route102/scripts.pory"
	lock
# 18 "data/maps/Route102/scripts.pory"
	faceplayer
# 19 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_ItsATerrifyingFall, MSGBOX_DEFAULT
	goto Route102_EventScript_Scoundrel_1


Route102_Text_WeCanBattleAgain::
# 27 "data/maps/Route102/scripts.pory"
	.string "If you feel like it, we can battle\n"
	.string "again sometimes.$"

Route102_Text_WantToHaveAFight::
# 32 "data/maps/Route102/scripts.pory"
	.string "Hehehe…\n"
	.string "Wanna have a battle on this cliff?$"

Route102_Text_DontFallDown::
# 37 "data/maps/Route102/scripts.pory"
	.string "Don't fall down!\n"
	.string "Hahaha!$"

Route102_Text_ScoundrelDefeated::
# 42 "data/maps/Route102/scripts.pory"
	.string "…\n"
	.string "… Huh…$"

Route102_Text_ItsATerrifyingFall::
# 47 "data/maps/Route102/scripts.pory"
	.string "It's a terrifying fall from here, but\n"
	.string "that didn't indimidate you, did it?$"
