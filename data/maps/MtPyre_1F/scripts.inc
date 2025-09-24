MtPyre_1F_MapScripts::
	.byte 0


MtPyre_1F_EventScript_Inscription::
# 4 "data/maps/MtPyre_1F/scripts.pory"
	lock
# 5 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_UnownKingImprisoned, MSGBOX_UNOWNCRYPT
# 6 "data/maps/MtPyre_1F/scripts.pory"
	closemessage
# 7 "data/maps/MtPyre_1F/scripts.pory"
	release
	return


MtPyre_1F_EventScript_WalkingGal::
# 16 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_ImLookingForRarePokemon, MSGBOX_NPC
	return


MtPyre_1F_EventScript_PokeBallMerchant::
# 26 "data/maps/MtPyre_1F/scripts.pory"
	lockall
# 27 "data/maps/MtPyre_1F/scripts.pory"
	applymovement LOCALID_BALL_MERCHANT, Common_Movement_FacePlayer
# 28 "data/maps/MtPyre_1F/scripts.pory"
	waitmovement 0
# 29 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_EventScript_BuySomePokeBall, MSGBOX_DEFAULT
# 30 "data/maps/MtPyre_1F/scripts.pory"
	pokemart MtPyre_1F_Mart_PokeBalls
# 31 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_SeeYouAgain, MSGBOX_DEFAULT
# 32 "data/maps/MtPyre_1F/scripts.pory"
	closemessage
# 33 "data/maps/MtPyre_1F/scripts.pory"
	releaseall
	return


	.align 2
# 45 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_Mart_PokeBalls:
# 46 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_POKE_BALL
# 47 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 48 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 49 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_NONE

MtPyre_1F_EventScript_RemediesMerchant::
# 53 "data/maps/MtPyre_1F/scripts.pory"
	lockall
# 54 "data/maps/MtPyre_1F/scripts.pory"
	applymovement LOCALID_REMEDIES_MERCHANT, Common_Movement_FacePlayer
# 55 "data/maps/MtPyre_1F/scripts.pory"
	waitmovement 0
# 56 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_BuySomeRemedies, MSGBOX_DEFAULT
# 57 "data/maps/MtPyre_1F/scripts.pory"
	pokemart MtPyre_1F_Mart_Remedies
# 58 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_SeeYouAgain, MSGBOX_DEFAULT
# 59 "data/maps/MtPyre_1F/scripts.pory"
	closemessage
# 60 "data/maps/MtPyre_1F/scripts.pory"
	releaseall
	return


	.align 2
# 68 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_Mart_Remedies:
# 69 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_FRESH_WATER
# 70 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_LEMONADE
# 71 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_MOOMOO_MILK
# 72 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 73 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 74 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 75 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 76 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 77 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_PERSIM_BERRY
# 78 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_RAGE_CANDY_BAR
# 79 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_REVIVE
# 80 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_RARE_CANDY
# 81 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_X_ATTACK
# 82 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 83 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_X_SP_ATK
# 84 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_X_SP_DEF
# 85 "data/maps/MtPyre_1F/scripts.pory"
	.2byte ITEM_X_SPEED
	.2byte ITEM_NONE

MtPyre_1F_Text_UnownKingImprisoned::
# 10 "data/maps/MtPyre_1F/scripts.pory"
	.string "This temple keeps the Unown King\n"
	.string "imprisoned.$"

MtPyre_1F_Text_ImLookingForRarePokemon::
# 19 "data/maps/MtPyre_1F/scripts.pory"
	.string "I'm looking for rare Pokémon to catch,\n"
	.string "but I'm not in the mood to battle\l"
	.string "other Trainers.$"

MtPyre_1F_EventScript_BuySomePokeBall::
# 36 "data/maps/MtPyre_1F/scripts.pory"
	.string "Hello, traveler.\n"
	.string "Will you buy some Poké Balls?$"

MtPyre_1F_Text_SeeYouAgain::
# 41 "data/maps/MtPyre_1F/scripts.pory"
	.string "See you again!$"

MtPyre_1F_Text_BuySomeRemedies::
# 63 "data/maps/MtPyre_1F/scripts.pory"
	.string "Hello, traveler.\n"
	.string "Are you interested in some of my merch?$"
