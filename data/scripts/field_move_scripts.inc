# 1 "data/scripts/field_move_scripts.pory"

# 2 "data/scripts/field_move_scripts.pory"

# 3 "data/scripts/field_move_scripts.pory"
Movement_CutTreeDown:
# 4 "data/scripts/field_move_scripts.pory"
	cut_tree
# 5 "data/scripts/field_move_scripts.pory"
	step_end
# 6 "data/scripts/field_move_scripts.pory"

# 7 "data/scripts/field_move_scripts.pory"
Text_WantToCut:
# 8 "data/scripts/field_move_scripts.pory"
	.string "This tree looks like it can be\n"
# 9 "data/scripts/field_move_scripts.pory"
	.string "CUT down!\p"
# 10 "data/scripts/field_move_scripts.pory"
	.string "Would you like to CUT it?$"
# 11 "data/scripts/field_move_scripts.pory"

# 12 "data/scripts/field_move_scripts.pory"
Text_MonUsedFieldMove:
# 13 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used {STR_VAR_2}!$"
# 14 "data/scripts/field_move_scripts.pory"

# 15 "data/scripts/field_move_scripts.pory"
Text_CantCut:
# 16 "data/scripts/field_move_scripts.pory"
	.string "This tree looks like it can be\n"
# 17 "data/scripts/field_move_scripts.pory"
	.string "CUT down!$"
# 18 "data/scripts/field_move_scripts.pory"

# 19 "data/scripts/field_move_scripts.pory"
EventScript_FollowerFieldMove:
# 20 "data/scripts/field_move_scripts.pory"
	getdirectiontoface VAR_0x8005, OBJ_EVENT_ID_FOLLOWER, OBJ_EVENT_ID_PLAYER
# 21 "data/scripts/field_move_scripts.pory"
	specialvar VAR_0x8006, GetPlayerFacingDirection
# 22 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_0x8005, DIR_NONE, EventScript_FollowerFieldMoveEnd
# 23 "data/scripts/field_move_scripts.pory"
	@ Swap follower and player
# 24 "data/scripts/field_move_scripts.pory"
	call EventScript_FollowerSwap
# 25 "data/scripts/field_move_scripts.pory"
	@ Face follower in direction and jump
# 26 "data/scripts/field_move_scripts.pory"
	switch VAR_0x8006
# 27 "data/scripts/field_move_scripts.pory"
	case DIR_NORTH, EventScript_FollowerJumpNorth
# 28 "data/scripts/field_move_scripts.pory"
	case DIR_EAST, EventScript_FollowerJumpEast
# 29 "data/scripts/field_move_scripts.pory"
	case DIR_SOUTH, EventScript_FollowerJumpSouth
# 30 "data/scripts/field_move_scripts.pory"
	case DIR_WEST, EventScript_FollowerJumpWest
# 31 "data/scripts/field_move_scripts.pory"
EventScript_FollowerFieldMoveEnd:
# 32 "data/scripts/field_move_scripts.pory"
	return
# 33 "data/scripts/field_move_scripts.pory"

# 34 "data/scripts/field_move_scripts.pory"
EventScript_FollowerSwap:
# 35 "data/scripts/field_move_scripts.pory"
	switch VAR_0x8005
# 36 "data/scripts/field_move_scripts.pory"
	case DIR_NORTH, EventScript_FollowerMoveNorth
# 37 "data/scripts/field_move_scripts.pory"
	case DIR_EAST, EventScript_FollowerMoveEast
# 38 "data/scripts/field_move_scripts.pory"
	case DIR_SOUTH, EventScript_FollowerMoveSouth
# 39 "data/scripts/field_move_scripts.pory"
	case DIR_WEST, EventScript_FollowerMoveWest
# 40 "data/scripts/field_move_scripts.pory"
	return
# 41 "data/scripts/field_move_scripts.pory"

# 42 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveNorth:
# 43 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkDown
# 44 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 45 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 46 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 47 "data/scripts/field_move_scripts.pory"
	return
# 48 "data/scripts/field_move_scripts.pory"

# 49 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveEast:
# 50 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkLeft
# 51 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 52 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 53 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 54 "data/scripts/field_move_scripts.pory"
	return
# 55 "data/scripts/field_move_scripts.pory"

# 56 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveSouth:
# 57 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp
# 58 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 59 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 60 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 61 "data/scripts/field_move_scripts.pory"
	return
# 62 "data/scripts/field_move_scripts.pory"

# 63 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveWest:
# 64 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkRight
# 65 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 66 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 67 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 68 "data/scripts/field_move_scripts.pory"
	return
# 69 "data/scripts/field_move_scripts.pory"

# 70 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpNorth:
# 71 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpUp
# 72 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 73 "data/scripts/field_move_scripts.pory"
	return
# 74 "data/scripts/field_move_scripts.pory"

# 75 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpEast:
# 76 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpRight
# 77 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 78 "data/scripts/field_move_scripts.pory"
	return
# 79 "data/scripts/field_move_scripts.pory"

# 80 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpSouth:
# 81 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpDown
# 82 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 83 "data/scripts/field_move_scripts.pory"
	return
# 84 "data/scripts/field_move_scripts.pory"

# 85 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpWest:
# 86 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpLeft
# 87 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 88 "data/scripts/field_move_scripts.pory"
	return
# 89 "data/scripts/field_move_scripts.pory"

# 90 "data/scripts/field_move_scripts.pory"
Movement_WalkUp:
# 91 "data/scripts/field_move_scripts.pory"
	walk_up
# 92 "data/scripts/field_move_scripts.pory"
	step_end
# 93 "data/scripts/field_move_scripts.pory"

# 94 "data/scripts/field_move_scripts.pory"
Movement_JumpUp:
# 95 "data/scripts/field_move_scripts.pory"
	jump_in_place_up
# 96 "data/scripts/field_move_scripts.pory"
	step_end
# 97 "data/scripts/field_move_scripts.pory"

# 98 "data/scripts/field_move_scripts.pory"
Movement_WalkRight:
# 99 "data/scripts/field_move_scripts.pory"
	walk_right
# 100 "data/scripts/field_move_scripts.pory"
	step_end
# 101 "data/scripts/field_move_scripts.pory"

# 102 "data/scripts/field_move_scripts.pory"
Movement_JumpRight:
# 103 "data/scripts/field_move_scripts.pory"
	jump_in_place_right
# 104 "data/scripts/field_move_scripts.pory"
	step_end
# 105 "data/scripts/field_move_scripts.pory"

# 106 "data/scripts/field_move_scripts.pory"
Movement_WalkDown:
# 107 "data/scripts/field_move_scripts.pory"
	walk_down
# 108 "data/scripts/field_move_scripts.pory"
	step_end
# 109 "data/scripts/field_move_scripts.pory"

# 110 "data/scripts/field_move_scripts.pory"
Movement_JumpDown:
# 111 "data/scripts/field_move_scripts.pory"
	jump_in_place_down
# 112 "data/scripts/field_move_scripts.pory"
	step_end
# 113 "data/scripts/field_move_scripts.pory"

# 114 "data/scripts/field_move_scripts.pory"
Movement_WalkLeft:
# 115 "data/scripts/field_move_scripts.pory"
	walk_left
# 116 "data/scripts/field_move_scripts.pory"
	step_end
# 117 "data/scripts/field_move_scripts.pory"

# 118 "data/scripts/field_move_scripts.pory"
Movement_JumpLeft:
# 119 "data/scripts/field_move_scripts.pory"
	jump_in_place_left
# 120 "data/scripts/field_move_scripts.pory"
	step_end
# 121 "data/scripts/field_move_scripts.pory"

# 122 "data/scripts/field_move_scripts.pory"
Movement_SmashRock:
# 123 "data/scripts/field_move_scripts.pory"
	rock_smash_break
# 124 "data/scripts/field_move_scripts.pory"
	step_end
# 125 "data/scripts/field_move_scripts.pory"

# 126 "data/scripts/field_move_scripts.pory"
Text_WantToSmash:
# 127 "data/scripts/field_move_scripts.pory"
	.string "This rock appears to be breakable.\n"
# 128 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use ROCK SMASH?$"
# 129 "data/scripts/field_move_scripts.pory"

# 130 "data/scripts/field_move_scripts.pory"
Text_CantSmash:
# 131 "data/scripts/field_move_scripts.pory"
	.string "It's a rugged rock, but a POKéMON\n"
# 132 "data/scripts/field_move_scripts.pory"
	.string "may be able to smash it.$"
# 133 "data/scripts/field_move_scripts.pory"

# 134 "data/scripts/field_move_scripts.pory"
EventScript_CantStrength::
# 135 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantStrength, MSGBOX_DEFAULT
# 136 "data/scripts/field_move_scripts.pory"
	releaseall
# 137 "data/scripts/field_move_scripts.pory"
	end
# 138 "data/scripts/field_move_scripts.pory"

# 139 "data/scripts/field_move_scripts.pory"
EventScript_CheckActivatedBoulder::
# 140 "data/scripts/field_move_scripts.pory"
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
# 141 "data/scripts/field_move_scripts.pory"
	releaseall
# 142 "data/scripts/field_move_scripts.pory"
	end
# 143 "data/scripts/field_move_scripts.pory"

# 144 "data/scripts/field_move_scripts.pory"
Text_WantToStrength:
# 145 "data/scripts/field_move_scripts.pory"
	.string "It's a big boulder, but a POKéMON\n"
# 146 "data/scripts/field_move_scripts.pory"
	.string "may be able to push it aside.\p"
# 147 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use STRENGTH?$"
# 148 "data/scripts/field_move_scripts.pory"

# 149 "data/scripts/field_move_scripts.pory"
Text_MonUsedStrength:
# 150 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used STRENGTH!\p"
# 151 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1}'s STRENGTH made it\n"
# 152 "data/scripts/field_move_scripts.pory"
	.string "possible to move boulders around!$"
# 153 "data/scripts/field_move_scripts.pory"

# 154 "data/scripts/field_move_scripts.pory"
Text_CantStrength:
# 155 "data/scripts/field_move_scripts.pory"
	.string "It's a big boulder, but a POKéMON\n"
# 156 "data/scripts/field_move_scripts.pory"
	.string "may be able to push it aside.$"
# 157 "data/scripts/field_move_scripts.pory"

# 158 "data/scripts/field_move_scripts.pory"
Text_StrengthActivated:
# 159 "data/scripts/field_move_scripts.pory"
	.string "STRENGTH made it possible to move\n"
# 160 "data/scripts/field_move_scripts.pory"
	.string "boulders around.$"
# 161 "data/scripts/field_move_scripts.pory"

# 162 "data/scripts/field_move_scripts.pory"
Text_CantWaterfall:
# 163 "data/scripts/field_move_scripts.pory"
	.string "A wall of water is crashing down with\n"
# 164 "data/scripts/field_move_scripts.pory"
	.string "a mighty roar.$"
# 165 "data/scripts/field_move_scripts.pory"

# 166 "data/scripts/field_move_scripts.pory"
Text_WantToWaterfall:
# 167 "data/scripts/field_move_scripts.pory"
	.string "It's a large waterfall.\n"
# 168 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use WATERFALL?$"
# 169 "data/scripts/field_move_scripts.pory"

# 170 "data/scripts/field_move_scripts.pory"
Text_MonUsedWaterfall:
# 171 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used WATERFALL.$"
# 172 "data/scripts/field_move_scripts.pory"

# 173 "data/scripts/field_move_scripts.pory"
EventScript_DigCommon:
# 174 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 175 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
# 176 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_DIG
# 177 "data/scripts/field_move_scripts.pory"
	waitstate
# 178 "data/scripts/field_move_scripts.pory"
EventScript_DigSealedChamber:: @ fallthrough
# 179 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 180 "data/scripts/field_move_scripts.pory"
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
# 181 "data/scripts/field_move_scripts.pory"
	callnative DoBrailleDigEffect
# 182 "data/scripts/field_move_scripts.pory"
	releaseall
# 183 "data/scripts/field_move_scripts.pory"
	end
# 184 "data/scripts/field_move_scripts.pory"

# 185 "data/scripts/field_move_scripts.pory"
@ Use Dig from party menu
# 186 "data/scripts/field_move_scripts.pory"
EventScript_UseDig::
# 187 "data/scripts/field_move_scripts.pory"
	lockall
# 188 "data/scripts/field_move_scripts.pory"
	goto EventScript_DigCommon
# 189 "data/scripts/field_move_scripts.pory"

# 190 "data/scripts/field_move_scripts.pory"

# 191 "data/scripts/field_move_scripts.pory"
EventScript_CutGrassCommon:
# 192 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 193 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
# 194 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_CUT_ON_GRASS
# 195 "data/scripts/field_move_scripts.pory"
	waitstate
# 196 "data/scripts/field_move_scripts.pory"

# 197 "data/scripts/field_move_scripts.pory"
@ Use Cut grass from party menu
# 198 "data/scripts/field_move_scripts.pory"
EventScript_UseCutGrass::
# 199 "data/scripts/field_move_scripts.pory"
	lockall
# 200 "data/scripts/field_move_scripts.pory"
	goto EventScript_CutGrassCommon
# 201 "data/scripts/field_move_scripts.pory"

# 202 "data/scripts/field_move_scripts.pory"
Text_CantDive:
# 203 "data/scripts/field_move_scripts.pory"
	.string "The sea is deep here. A POKéMON\n"
# 204 "data/scripts/field_move_scripts.pory"
	.string "may be able to go underwater.$"
# 205 "data/scripts/field_move_scripts.pory"

# 206 "data/scripts/field_move_scripts.pory"
Text_WantToDive:
# 207 "data/scripts/field_move_scripts.pory"
	.string "The sea is deep here.\n"
# 208 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use DIVE?$"
# 209 "data/scripts/field_move_scripts.pory"

# 210 "data/scripts/field_move_scripts.pory"
Text_MonUsedDive:
# 211 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used DIVE.$"
# 212 "data/scripts/field_move_scripts.pory"

# 213 "data/scripts/field_move_scripts.pory"
Text_CantSurface:
# 214 "data/scripts/field_move_scripts.pory"
	.string "Light is filtering down from above.\n"
# 215 "data/scripts/field_move_scripts.pory"
	.string "A POKéMON may be able to surface.$"
# 216 "data/scripts/field_move_scripts.pory"

# 217 "data/scripts/field_move_scripts.pory"
Text_WantToSurface:
# 218 "data/scripts/field_move_scripts.pory"
	.string "Light is filtering down from above.\n"
# 219 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use DIVE?$"
# 220 "data/scripts/field_move_scripts.pory"

# 221 "data/scripts/field_move_scripts.pory"
EventScript_FailSweetScent::
# 222 "data/scripts/field_move_scripts.pory"
	msgbox Text_FailSweetScent, MSGBOX_SIGN
# 223 "data/scripts/field_move_scripts.pory"
	end
# 224 "data/scripts/field_move_scripts.pory"

# 225 "data/scripts/field_move_scripts.pory"
Text_FailSweetScent:
# 226 "data/scripts/field_move_scripts.pory"
	.string "Looks like there's nothing here…$"
# 227 "data/scripts/field_move_scripts.pory"

# 228 "data/scripts/field_move_scripts.pory"
EventScript_UseDefog::
# 229 "data/scripts/field_move_scripts.pory"
	lockall
# 230 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 231 "data/scripts/field_move_scripts.pory"
	buffermovename STR_VAR_2, MOVE_DEFOG
# 232 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 233 "data/scripts/field_move_scripts.pory"
	closemessage
# 234 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 235 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
# 236 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 237 "data/scripts/field_move_scripts.pory"
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
# 238 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 239 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 240 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_DEFOG
# 241 "data/scripts/field_move_scripts.pory"
	waitstate
# 242 "data/scripts/field_move_scripts.pory"
	releaseall
# 243 "data/scripts/field_move_scripts.pory"
	end

EventScript_CutTree::
# 253 "data/scripts/field_move_scripts.pory"
	lockall
# 254 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_BADGE01_GET, EventScript_CutTree_2
# 268 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantCut, MSGBOX_DEFAULT
# 269 "data/scripts/field_move_scripts.pory"
	closemessage
EventScript_CutTree_1:
# 271 "data/scripts/field_move_scripts.pory"
	releaseall
	return

EventScript_CutTree_2:
# 255 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_CUT
# 256 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_CutTree_5
# 265 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareCut
	goto EventScript_CutTree_1

EventScript_CutTree_5:
# 257 "data/scripts/field_move_scripts.pory"
	checkpartylearnable MOVE_CUT
# 258 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_CutTree_8
# 262 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareCut
	goto EventScript_CutTree_1

EventScript_CutTree_8:
# 259 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantCut, MSGBOX_DEFAULT
# 260 "data/scripts/field_move_scripts.pory"
	closemessage
	goto EventScript_CutTree_1


EventScript_PrepareCut::
# 276 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 277 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToCut, MSGBOX_YESNO
# 278 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PrepareCut_1
# 282 "data/scripts/field_move_scripts.pory"
	closemessage
	return

EventScript_PrepareCut_1:
# 279 "data/scripts/field_move_scripts.pory"
	closemessage
# 280 "data/scripts/field_move_scripts.pory"
	call EventScript_CutTreeCommon
	return


EventScript_CutTreeCommon::
# 288 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, FALSE
# 289 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
# 290 "data/scripts/field_move_scripts.pory"
	waitstate
# 291 "data/scripts/field_move_scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
# 292 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 293 "data/scripts/field_move_scripts.pory"
	removeobject VAR_LAST_TALKED
	return


EventScript_UseCut::
# 298 "data/scripts/field_move_scripts.pory"
	lockall
# 299 "data/scripts/field_move_scripts.pory"
	call EventScript_CutTreeCommon
# 300 "data/scripts/field_move_scripts.pory"
	releaseall
	return


EventScript_RockSmash::
# 310 "data/scripts/field_move_scripts.pory"
	lockall
# 311 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_BADGE03_GET, EventScript_RockSmash_2
# 325 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantSmash, MSGBOX_DEFAULT
# 326 "data/scripts/field_move_scripts.pory"
	closemessage
EventScript_RockSmash_1:
# 328 "data/scripts/field_move_scripts.pory"
	releaseall
	return

EventScript_RockSmash_2:
# 312 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_ROCK_SMASH
# 313 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_RockSmash_5
# 322 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareRockSmash
	goto EventScript_RockSmash_1

EventScript_RockSmash_5:
# 314 "data/scripts/field_move_scripts.pory"
	checkpartylearnable MOVE_ROCK_SMASH
# 315 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_RockSmash_8
# 319 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareRockSmash
	goto EventScript_RockSmash_1

EventScript_RockSmash_8:
# 316 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantSmash, MSGBOX_DEFAULT
# 317 "data/scripts/field_move_scripts.pory"
	closemessage
	goto EventScript_RockSmash_1


EventScript_PrepareRockSmash::
# 333 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 334 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToSmash, MSGBOX_YESNO
# 335 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PrepareRockSmash_1
# 339 "data/scripts/field_move_scripts.pory"
	closemessage
	return

EventScript_PrepareRockSmash_1:
# 336 "data/scripts/field_move_scripts.pory"
	closemessage
# 337 "data/scripts/field_move_scripts.pory"
	call EventScript_RockSmashCommon
	return


EventScript_RockSmashCommon::
# 345 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, FALSE
# 346 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_ROCK_SMASH
# 347 "data/scripts/field_move_scripts.pory"
	waitstate
# 348 "data/scripts/field_move_scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_SmashRock
# 349 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 350 "data/scripts/field_move_scripts.pory"
	removeobject VAR_LAST_TALKED
# 351 "data/scripts/field_move_scripts.pory"
	special RockSmashWildEncounter
# 352 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_RockSmashCommon_1
	return

EventScript_RockSmashCommon_1:
# 353 "data/scripts/field_move_scripts.pory"
	waitstate
	return


EventScript_UseRockSmash::
# 359 "data/scripts/field_move_scripts.pory"
	lockall
# 360 "data/scripts/field_move_scripts.pory"
	call EventScript_RockSmashCommon
# 361 "data/scripts/field_move_scripts.pory"
	releaseall
	return


EventScript_StrengthBoulder::
# 371 "data/scripts/field_move_scripts.pory"
	lockall
# 372 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_BADGE04_GET, EventScript_StrengthBoulder_2
# 391 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantStrength, MSGBOX_DEFAULT
# 392 "data/scripts/field_move_scripts.pory"
	closemessage
EventScript_StrengthBoulder_1:
# 394 "data/scripts/field_move_scripts.pory"
	releaseall
	return

EventScript_StrengthBoulder_2:
# 373 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_StrengthBoulder_5
# 377 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_STRENGTH
# 378 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_StrengthBoulder_8
# 387 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareStrength
	goto EventScript_StrengthBoulder_1

EventScript_StrengthBoulder_5:
# 374 "data/scripts/field_move_scripts.pory"
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
# 375 "data/scripts/field_move_scripts.pory"
	closemessage
	goto EventScript_StrengthBoulder_1

EventScript_StrengthBoulder_8:
# 379 "data/scripts/field_move_scripts.pory"
	checkpartylearnable MOVE_STRENGTH
# 380 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_StrengthBoulder_11
# 384 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareStrength
	goto EventScript_StrengthBoulder_1

EventScript_StrengthBoulder_11:
# 381 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantStrength, MSGBOX_DEFAULT
# 382 "data/scripts/field_move_scripts.pory"
	closemessage
	goto EventScript_StrengthBoulder_1


EventScript_PrepareStrength::
# 399 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 400 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToStrength, MSGBOX_YESNO
# 401 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PrepareStrength_1
# 407 "data/scripts/field_move_scripts.pory"
	closemessage
	return

EventScript_PrepareStrength_1:
# 402 "data/scripts/field_move_scripts.pory"
	closemessage
# 403 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_STRENGTH
# 404 "data/scripts/field_move_scripts.pory"
	waitstate
# 405 "data/scripts/field_move_scripts.pory"
	call EventScript_ActivateStrength
	return


EventScript_UseStrength::
# 413 "data/scripts/field_move_scripts.pory"
	lockall
# 414 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_STRENGTH
# 415 "data/scripts/field_move_scripts.pory"
	waitstate
# 416 "data/scripts/field_move_scripts.pory"
	call EventScript_ActivateStrength
# 417 "data/scripts/field_move_scripts.pory"
	releaseall
	return


EventScript_ActivateStrength::
# 422 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SYS_USE_STRENGTH
# 423 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	return


EventScript_FakeBoulder::
# 428 "data/scripts/field_move_scripts.pory"
	lockall
# 429 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_BADGE04_GET, EventScript_FakeBoulder_2
# 449 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantStrength, MSGBOX_DEFAULT
# 450 "data/scripts/field_move_scripts.pory"
	closemessage
EventScript_FakeBoulder_1:
# 452 "data/scripts/field_move_scripts.pory"
	releaseall
	return

EventScript_FakeBoulder_2:
# 430 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_FakeBoulder_5
# 435 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_STRENGTH
# 436 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_FakeBoulder_8
# 445 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareStrengthFake
	goto EventScript_FakeBoulder_1

EventScript_FakeBoulder_5:
# 431 "data/scripts/field_move_scripts.pory"
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
# 432 "data/scripts/field_move_scripts.pory"
	closemessage
# 433 "data/scripts/field_move_scripts.pory"
	call EventScript_FakeBoulderBattle
	goto EventScript_FakeBoulder_1

EventScript_FakeBoulder_8:
# 437 "data/scripts/field_move_scripts.pory"
	checkpartylearnable MOVE_STRENGTH
# 438 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_FakeBoulder_11
# 442 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareStrengthFake
	goto EventScript_FakeBoulder_1

EventScript_FakeBoulder_11:
# 439 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantStrength, MSGBOX_DEFAULT
# 440 "data/scripts/field_move_scripts.pory"
	closemessage
	goto EventScript_FakeBoulder_1


EventScript_PrepareStrengthFake::
# 457 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 458 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToStrength, MSGBOX_YESNO
# 459 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PrepareStrengthFake_1
# 466 "data/scripts/field_move_scripts.pory"
	closemessage
	return

EventScript_PrepareStrengthFake_1:
# 460 "data/scripts/field_move_scripts.pory"
	closemessage
# 461 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_STRENGTH
# 462 "data/scripts/field_move_scripts.pory"
	waitstate
# 463 "data/scripts/field_move_scripts.pory"
	call EventScript_ActivateStrength
# 464 "data/scripts/field_move_scripts.pory"
	call EventScript_FakeBoulderBattle
	return


EventScript_FakeBoulderBattle::
# 472 "data/scripts/field_move_scripts.pory"
	playse SE_PIN
# 473 "data/scripts/field_move_scripts.pory"
	applymovement VAR_LAST_TALKED, MovementEmoteExclamation
# 474 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 475 "data/scripts/field_move_scripts.pory"
	waitse
# 476 "data/scripts/field_move_scripts.pory"
	playmoncry SPECIES_CRUSTLE, CRY_MODE_NORMAL
# 477 "data/scripts/field_move_scripts.pory"
	waitmoncry
# 478 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 479 "data/scripts/field_move_scripts.pory"
	setwildbattle SPECIES_CRUSTLE, 34, item = ITEM_FOCUS_SASH
# 480 "data/scripts/field_move_scripts.pory"
	dowildbattle
# 481 "data/scripts/field_move_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	return


# 485 "data/scripts/field_move_scripts.pory"
MovementEmoteExclamation:
# 486 "data/scripts/field_move_scripts.pory"
	emote_exclamation_mark
	step_end

EventScript_UseDive::
# 496 "data/scripts/field_move_scripts.pory"
	lockall
# 497 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_DIVE
# 498 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_UseDive_2
# 507 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareDive
EventScript_UseDive_1:
# 509 "data/scripts/field_move_scripts.pory"
	releaseall
	return

EventScript_UseDive_2:
# 499 "data/scripts/field_move_scripts.pory"
	checkpartylearnable MOVE_DIVE
# 500 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_UseDive_5
# 504 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareDive
	goto EventScript_UseDive_1

EventScript_UseDive_5:
# 501 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantDive, MSGBOX_DEFAULT
# 502 "data/scripts/field_move_scripts.pory"
	closemessage
	goto EventScript_UseDive_1


EventScript_PrepareDive::
# 514 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 515 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 1, 1
# 516 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToDive, MSGBOX_YESNO
# 517 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PrepareDive_1
# 523 "data/scripts/field_move_scripts.pory"
	closemessage
	return

EventScript_PrepareDive_1:
# 518 "data/scripts/field_move_scripts.pory"
	closemessage
# 521 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_DIVE
	return


EventScript_CannotUseDive::
# 529 "data/scripts/field_move_scripts.pory"
	lockall
# 530 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantDive, MSGBOX_DEFAULT
# 531 "data/scripts/field_move_scripts.pory"
	closemessage
# 532 "data/scripts/field_move_scripts.pory"
	releaseall
	return


EventScript_UseDiveUnderwater::
# 537 "data/scripts/field_move_scripts.pory"
	lockall
# 538 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_DIVE
# 539 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_UseDiveUnderwater_2
# 548 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareDiveUnderwater
EventScript_UseDiveUnderwater_1:
# 550 "data/scripts/field_move_scripts.pory"
	releaseall
	return

EventScript_UseDiveUnderwater_2:
# 540 "data/scripts/field_move_scripts.pory"
	checkpartylearnable MOVE_DIVE
# 541 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_UseDiveUnderwater_5
# 545 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareDiveUnderwater
	goto EventScript_UseDiveUnderwater_1

EventScript_UseDiveUnderwater_5:
# 542 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantSurface, MSGBOX_DEFAULT
# 543 "data/scripts/field_move_scripts.pory"
	closemessage
	goto EventScript_UseDiveUnderwater_1


EventScript_PrepareDiveUnderwater::
# 555 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 556 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 1, 1
# 557 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToSurface, MSGBOX_YESNO
# 558 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PrepareDiveUnderwater_1
# 562 "data/scripts/field_move_scripts.pory"
	closemessage
	return

EventScript_PrepareDiveUnderwater_1:
# 559 "data/scripts/field_move_scripts.pory"
	closemessage
# 560 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_DIVE
	return


EventScript_CannotUseDiveUnderwater::
# 568 "data/scripts/field_move_scripts.pory"
	lockall
# 569 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantSurface, MSGBOX_DEFAULT
# 570 "data/scripts/field_move_scripts.pory"
	closemessage
# 571 "data/scripts/field_move_scripts.pory"
	releaseall
	return


EventScript_UseWaterfall::
# 581 "data/scripts/field_move_scripts.pory"
	lockall
# 582 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_WATERFALL
# 583 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_UseWaterfall_2
# 592 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareWaterfall
EventScript_UseWaterfall_1:
# 594 "data/scripts/field_move_scripts.pory"
	releaseall
	return

EventScript_UseWaterfall_2:
# 584 "data/scripts/field_move_scripts.pory"
	checkpartylearnable MOVE_WATERFALL
# 585 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_UseWaterfall_5
# 589 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareWaterfall
	goto EventScript_UseWaterfall_1

EventScript_UseWaterfall_5:
# 586 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT
# 587 "data/scripts/field_move_scripts.pory"
	closemessage
	goto EventScript_UseWaterfall_1


EventScript_PrepareWaterfall::
# 599 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 600 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
# 601 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PrepareWaterfall_1
# 605 "data/scripts/field_move_scripts.pory"
	closemessage
	return

EventScript_PrepareWaterfall_1:
# 602 "data/scripts/field_move_scripts.pory"
	closemessage
# 603 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_WATERFALL
	return


EventScript_CannotUseWaterfall::
# 611 "data/scripts/field_move_scripts.pory"
	lockall
# 612 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT
# 613 "data/scripts/field_move_scripts.pory"
	closemessage
# 614 "data/scripts/field_move_scripts.pory"
	releaseall
	return

