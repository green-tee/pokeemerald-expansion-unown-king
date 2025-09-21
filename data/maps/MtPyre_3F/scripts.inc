MtPyre_3F_MapScripts::
	.byte 0


MtPyre_3F_EventScript_Inscription::
# 4 "data/maps/MtPyre_3F/scripts.pory"
	lock
# 5 "data/maps/MtPyre_3F/scripts.pory"
	msgbox MtPyre_3F_Text_TruthRevealed, MSGBOX_UNOWNCRYPT
# 6 "data/maps/MtPyre_3F/scripts.pory"
	closemessage
# 7 "data/maps/MtPyre_3F/scripts.pory"
	release
	return


MtPyre_3F_EventScript_MaidenHermione::
# 20 "data/maps/MtPyre_3F/scripts.pory"
	lock
# 21 "data/maps/MtPyre_3F/scripts.pory"
	faceplayer
# 22 "data/maps/MtPyre_3F/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MtPyre_3F_EventScript_MaidenHermione_2
# 26 "data/maps/MtPyre_3F/scripts.pory"
	msgbox MtPyre_3F_Text_ImOneOfTheFourMaidens, MSGBOX_YESNO
# 27 "data/maps/MtPyre_3F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MtPyre_3F_EventScript_MaidenHermione_5
# 42 "data/maps/MtPyre_3F/scripts.pory"
	closemessage
# 43 "data/maps/MtPyre_3F/scripts.pory"
	msgbox MtPyre_3F_Text_ComeBackWhenReady, MSGBOX_DEFAULT
# 44 "data/maps/MtPyre_3F/scripts.pory"
	closemessage
MtPyre_3F_EventScript_MaidenHermione_1:
# 47 "data/maps/MtPyre_3F/scripts.pory"
	release
	return

MtPyre_3F_EventScript_MaidenHermione_2:
# 23 "data/maps/MtPyre_3F/scripts.pory"
	msgbox MtPyre_3F_Text_WithRockSmashYouCanExplore, MSGBOX_DEFAULT
# 24 "data/maps/MtPyre_3F/scripts.pory"
	closemessage
	goto MtPyre_3F_EventScript_MaidenHermione_1

MtPyre_3F_EventScript_MaidenHermione_5:
# 28 "data/maps/MtPyre_3F/scripts.pory"
	closemessage
# 29 "data/maps/MtPyre_3F/scripts.pory"
	playbgm MUS_VS_GYM_LEADER, FALSE
# 30 "data/maps/MtPyre_3F/scripts.pory"
	msgbox MtPyre_3F_Text_LetUsBegin, MSGBOX_DEFAULT
# 31 "data/maps/MtPyre_3F/scripts.pory"
	closemessage
# 32 "data/maps/MtPyre_3F/scripts.pory"
	trainerbattle_no_intro TRAINER_MAIDEN1, MtPyre_3F_Text_MaidenHermioneDefeated
# 33 "data/maps/MtPyre_3F/scripts.pory"
	lock
# 34 "data/maps/MtPyre_3F/scripts.pory"
	faceplayer
# 35 "data/maps/MtPyre_3F/scripts.pory"
	msgbox MtPyre_3F_Text_NicelyDone, MSGBOX_DEFAULT
# 36 "data/maps/MtPyre_3F/scripts.pory"
	closemessage
# 37 "data/maps/MtPyre_3F/scripts.pory"
	giveitem ITEM_HM_ROCK_SMASH
# 38 "data/maps/MtPyre_3F/scripts.pory"
	setflag FLAG_BADGE03_GET
# 39 "data/maps/MtPyre_3F/scripts.pory"
	msgbox MtPyre_3F_Text_ThisIsAHiddenMachine, MSGBOX_DEFAULT
# 40 "data/maps/MtPyre_3F/scripts.pory"
	closemessage
	goto MtPyre_3F_EventScript_MaidenHermione_1


MtPyre_3F_EventScript_ExpertBeforeChamber::
# 116 "data/maps/MtPyre_3F/scripts.pory"
	lock
# 117 "data/maps/MtPyre_3F/scripts.pory"
	faceplayer
# 118 "data/maps/MtPyre_3F/scripts.pory"
	msgbox MtPyre_3F_ThereIsAStrongTrainer, MSGBOX_DEFAULT
# 119 "data/maps/MtPyre_3F/scripts.pory"
	closemessage
# 120 "data/maps/MtPyre_3F/scripts.pory"
	release
	return


MtPyre_3F_Text_TruthRevealed::
# 10 "data/maps/MtPyre_3F/scripts.pory"
	.string "In this room, the truth about\n"
	.string "the Unown King is unveiled.\p"
	.string "Humans came into existence in its\n"
	.string "shape after its wish.\p"
	.string "Oh, how much we, the Imprisoners,\n"
	.string "pity what has become of it!$"

MtPyre_3F_Text_ImOneOfTheFourMaidens::
# 50 "data/maps/MtPyre_3F/scripts.pory"
	.string "Welcome, traveler!\p"
	.string "My name is Hermione, I'm one of the\n"
	.string "four Maidens of this temple.\p"
	.string "My purpose is to aid the worthy ones\n"
	.string "who wish to explore this place to the\l"
	.string "very last corner.\p"
	.string "Have you seen any cracked rocks\n"
	.string "lying around?\p"
	.string "Those rocks can be shattered by those\n"
	.string "with the required power.\p"
	.string "I can lend you such power, but first\n"
	.string "you need to prove yourself in battle.\l"
	.string "Are you up to the challenge?$"

MtPyre_3F_Text_ComeBackWhenReady::
# 66 "data/maps/MtPyre_3F/scripts.pory"
	.string "If you're looking for the power to\n"
	.string "destroy rocks, come back when you're\l"
	.string "ready to fight.$"

MtPyre_3F_Text_LetUsBegin::
# 72 "data/maps/MtPyre_3F/scripts.pory"
	.string "Very well, traveler.\n"
	.string "I want to see the best you can do.\p"
	.string "Let us begin!$"

MtPyre_3F_Text_MaidenHermioneDefeated::
# 78 "data/maps/MtPyre_3F/scripts.pory"
	.string "You passed the trial, traveler!$"

MtPyre_3F_Text_NicelyDone::
# 82 "data/maps/MtPyre_3F/scripts.pory"
	.string "Nicely done, traveler!\n"
	.string "You deserve the power I was\l"
	.string "talking about.\l"
	.string "I'll hand it to you right now.$"

MtPyre_3F_Text_ThisIsAHiddenMachine::
# 89 "data/maps/MtPyre_3F/scripts.pory"
	.string "This is called a Hidden Maneuver.\n"
	.string "If a Pokémon is exposed to its\l"
	.string "presence, it can immediately learn\l"
	.string "a new move, as long as it's in its\l"
	.string "nature.\p"
	.string "This Hidden Maneuver contains\n"
	.string "the power of Rock Smash, which,\l"
	.string "admittedly, isn't that strong of a move.\p"
	.string "However, you don't have to teach this\n"
	.string "move to any of your Pokémon.\p"
	.string "As long as a Pokémon can learn it,\n"
	.string "it can break the cracked rocks\l"
	.string "that are in your way.\p"
	.string "Now, go! Explore this temple\n"
	.string "to your heart's content!$"

MtPyre_3F_Text_WithRockSmashYouCanExplore::
# 107 "data/maps/MtPyre_3F/scripts.pory"
	.string "With the power of Rock Smash\n"
	.string "by your side, you are able to explore\l"
	.string "most of this temple.\p"
	.string "Now, go!\n"
	.string "Explore to your heart's content!$"

MtPyre_3F_ThereIsAStrongTrainer::
# 123 "data/maps/MtPyre_3F/scripts.pory"
	.string "Careful!\n"
	.string "There's a very strong Trainer inside!$"
