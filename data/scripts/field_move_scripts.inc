# 1 "data/scripts/field_move_scripts.pory"

# 2 "data/scripts/field_move_scripts.pory"
@ Interact with cuttable tree
# 3 "data/scripts/field_move_scripts.pory"
EventScript_CutTree::
# 4 "data/scripts/field_move_scripts.pory"
	lockall
# 5 "data/scripts/field_move_scripts.pory"
	goto_if_unset FLAG_BADGE01_GET, EventScript_CheckTreeCantCut
# 6 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_CUT
# 7 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
# 8 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 9 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 10 "data/scripts/field_move_scripts.pory"
	buffermovename STR_VAR_2, MOVE_CUT
# 11 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToCut, MSGBOX_YESNO
# 12 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
# 13 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 14 "data/scripts/field_move_scripts.pory"
	closemessage
# 15 "data/scripts/field_move_scripts.pory"
EventScript_CutTreeCommon:
# 16 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 17 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
# 18 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
# 19 "data/scripts/field_move_scripts.pory"
	waitstate
# 20 "data/scripts/field_move_scripts.pory"
EventScript_CutTreeDown:: @ fallthrough
# 21 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 22 "data/scripts/field_move_scripts.pory"
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
# 23 "data/scripts/field_move_scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
# 24 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 25 "data/scripts/field_move_scripts.pory"
	removeobject VAR_LAST_TALKED
# 26 "data/scripts/field_move_scripts.pory"
	releaseall
# 27 "data/scripts/field_move_scripts.pory"
	end
# 28 "data/scripts/field_move_scripts.pory"

# 29 "data/scripts/field_move_scripts.pory"
@ Use cut from party menu
# 30 "data/scripts/field_move_scripts.pory"
EventScript_UseCut::
# 31 "data/scripts/field_move_scripts.pory"
	lockall
# 32 "data/scripts/field_move_scripts.pory"
	goto EventScript_CutTreeCommon
# 33 "data/scripts/field_move_scripts.pory"

# 34 "data/scripts/field_move_scripts.pory"
Movement_CutTreeDown:
# 35 "data/scripts/field_move_scripts.pory"
	cut_tree
# 36 "data/scripts/field_move_scripts.pory"
	step_end
# 37 "data/scripts/field_move_scripts.pory"

# 38 "data/scripts/field_move_scripts.pory"
EventScript_CheckTreeCantCut::
# 39 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantCut, MSGBOX_DEFAULT
# 40 "data/scripts/field_move_scripts.pory"
	releaseall
# 41 "data/scripts/field_move_scripts.pory"
	end
# 42 "data/scripts/field_move_scripts.pory"

# 43 "data/scripts/field_move_scripts.pory"
EventScript_CancelCut::
# 44 "data/scripts/field_move_scripts.pory"
	closemessage
# 45 "data/scripts/field_move_scripts.pory"
	releaseall
# 46 "data/scripts/field_move_scripts.pory"
	end
# 47 "data/scripts/field_move_scripts.pory"

# 48 "data/scripts/field_move_scripts.pory"
Text_WantToCut:
# 49 "data/scripts/field_move_scripts.pory"
	.string "This tree looks like it can be\n"
# 50 "data/scripts/field_move_scripts.pory"
	.string "CUT down!\p"
# 51 "data/scripts/field_move_scripts.pory"
	.string "Would you like to CUT it?$"
# 52 "data/scripts/field_move_scripts.pory"

# 53 "data/scripts/field_move_scripts.pory"
Text_MonUsedFieldMove:
# 54 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used {STR_VAR_2}!$"
# 55 "data/scripts/field_move_scripts.pory"

# 56 "data/scripts/field_move_scripts.pory"
Text_CantCut:
# 57 "data/scripts/field_move_scripts.pory"
	.string "This tree looks like it can be\n"
# 58 "data/scripts/field_move_scripts.pory"
	.string "CUT down!$"
# 59 "data/scripts/field_move_scripts.pory"

# 60 "data/scripts/field_move_scripts.pory"
@ Use rock smash from party menu
# 61 "data/scripts/field_move_scripts.pory"
EventScript_UseRockSmash::
# 62 "data/scripts/field_move_scripts.pory"
	lockall
# 63 "data/scripts/field_move_scripts.pory"
	goto EventScript_RockSmashCommon
# 64 "data/scripts/field_move_scripts.pory"

# 65 "data/scripts/field_move_scripts.pory"
@ Interact with smashable rock
# 66 "data/scripts/field_move_scripts.pory"
EventScript_RockSmash::
# 67 "data/scripts/field_move_scripts.pory"
	lockall
# 68 "data/scripts/field_move_scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, EventScript_CantSmashRock
# 69 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_ROCK_SMASH
# 70 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
# 71 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 72 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 73 "data/scripts/field_move_scripts.pory"
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
# 74 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToSmash, MSGBOX_YESNO
# 75 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
# 76 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 77 "data/scripts/field_move_scripts.pory"
	closemessage
# 78 "data/scripts/field_move_scripts.pory"
EventScript_RockSmashCommon:
# 79 "data/scripts/field_move_scripts.pory"
	@ check if follower should use the field move
# 80 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 81 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
# 82 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_ROCK_SMASH
# 83 "data/scripts/field_move_scripts.pory"
	waitstate
# 84 "data/scripts/field_move_scripts.pory"
EventScript_SmashRock:: @ fallthrough
# 85 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 86 "data/scripts/field_move_scripts.pory"
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
# 87 "data/scripts/field_move_scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_SmashRock
# 88 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 89 "data/scripts/field_move_scripts.pory"
	removeobject VAR_LAST_TALKED
# 90 "data/scripts/field_move_scripts.pory"
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
# 91 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
# 92 "data/scripts/field_move_scripts.pory"
	special RockSmashWildEncounter
# 93 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
# 94 "data/scripts/field_move_scripts.pory"
	waitstate
# 95 "data/scripts/field_move_scripts.pory"
	releaseall
# 96 "data/scripts/field_move_scripts.pory"
	end
# 97 "data/scripts/field_move_scripts.pory"

# 98 "data/scripts/field_move_scripts.pory"
EventScript_FollowerFieldMove:
# 99 "data/scripts/field_move_scripts.pory"
	getdirectiontoface VAR_0x8005, OBJ_EVENT_ID_FOLLOWER, OBJ_EVENT_ID_PLAYER
# 100 "data/scripts/field_move_scripts.pory"
	specialvar VAR_0x8006, GetPlayerFacingDirection
# 101 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_0x8005, DIR_NONE, EventScript_FollowerFieldMoveEnd
# 102 "data/scripts/field_move_scripts.pory"
	@ Swap follower and player
# 103 "data/scripts/field_move_scripts.pory"
	call EventScript_FollowerSwap
# 104 "data/scripts/field_move_scripts.pory"
	@ Face follower in direction and jump
# 105 "data/scripts/field_move_scripts.pory"
	switch VAR_0x8006
# 106 "data/scripts/field_move_scripts.pory"
	case DIR_NORTH, EventScript_FollowerJumpNorth
# 107 "data/scripts/field_move_scripts.pory"
	case DIR_EAST, EventScript_FollowerJumpEast
# 108 "data/scripts/field_move_scripts.pory"
	case DIR_SOUTH, EventScript_FollowerJumpSouth
# 109 "data/scripts/field_move_scripts.pory"
	case DIR_WEST, EventScript_FollowerJumpWest
# 110 "data/scripts/field_move_scripts.pory"
EventScript_FollowerFieldMoveEnd:
# 111 "data/scripts/field_move_scripts.pory"
	return
# 112 "data/scripts/field_move_scripts.pory"

# 113 "data/scripts/field_move_scripts.pory"
EventScript_FollowerSwap:
# 114 "data/scripts/field_move_scripts.pory"
	switch VAR_0x8005
# 115 "data/scripts/field_move_scripts.pory"
	case DIR_NORTH, EventScript_FollowerMoveNorth
# 116 "data/scripts/field_move_scripts.pory"
	case DIR_EAST, EventScript_FollowerMoveEast
# 117 "data/scripts/field_move_scripts.pory"
	case DIR_SOUTH, EventScript_FollowerMoveSouth
# 118 "data/scripts/field_move_scripts.pory"
	case DIR_WEST, EventScript_FollowerMoveWest
# 119 "data/scripts/field_move_scripts.pory"
	return
# 120 "data/scripts/field_move_scripts.pory"

# 121 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveNorth:
# 122 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkDown
# 123 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 124 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 125 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 126 "data/scripts/field_move_scripts.pory"
	return
# 127 "data/scripts/field_move_scripts.pory"

# 128 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveEast:
# 129 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkLeft
# 130 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 131 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 132 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 133 "data/scripts/field_move_scripts.pory"
	return
# 134 "data/scripts/field_move_scripts.pory"

# 135 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveSouth:
# 136 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp
# 137 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 138 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 139 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 140 "data/scripts/field_move_scripts.pory"
	return
# 141 "data/scripts/field_move_scripts.pory"

# 142 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveWest:
# 143 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkRight
# 144 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 145 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 146 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 147 "data/scripts/field_move_scripts.pory"
	return
# 148 "data/scripts/field_move_scripts.pory"

# 149 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpNorth:
# 150 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpUp
# 151 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 152 "data/scripts/field_move_scripts.pory"
	return
# 153 "data/scripts/field_move_scripts.pory"

# 154 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpEast:
# 155 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpRight
# 156 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 157 "data/scripts/field_move_scripts.pory"
	return
# 158 "data/scripts/field_move_scripts.pory"

# 159 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpSouth:
# 160 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpDown
# 161 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 162 "data/scripts/field_move_scripts.pory"
	return
# 163 "data/scripts/field_move_scripts.pory"

# 164 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpWest:
# 165 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpLeft
# 166 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 167 "data/scripts/field_move_scripts.pory"
	return
# 168 "data/scripts/field_move_scripts.pory"

# 169 "data/scripts/field_move_scripts.pory"
EventScript_EndSmash::
# 170 "data/scripts/field_move_scripts.pory"
	releaseall
# 171 "data/scripts/field_move_scripts.pory"
	end
# 172 "data/scripts/field_move_scripts.pory"

# 173 "data/scripts/field_move_scripts.pory"
Movement_WalkUp:
# 174 "data/scripts/field_move_scripts.pory"
	walk_up
# 175 "data/scripts/field_move_scripts.pory"
	step_end
# 176 "data/scripts/field_move_scripts.pory"

# 177 "data/scripts/field_move_scripts.pory"
Movement_JumpUp:
# 178 "data/scripts/field_move_scripts.pory"
	jump_in_place_up
# 179 "data/scripts/field_move_scripts.pory"
	step_end
# 180 "data/scripts/field_move_scripts.pory"

# 181 "data/scripts/field_move_scripts.pory"
Movement_WalkRight:
# 182 "data/scripts/field_move_scripts.pory"
	walk_right
# 183 "data/scripts/field_move_scripts.pory"
	step_end
# 184 "data/scripts/field_move_scripts.pory"

# 185 "data/scripts/field_move_scripts.pory"
Movement_JumpRight:
# 186 "data/scripts/field_move_scripts.pory"
	jump_in_place_right
# 187 "data/scripts/field_move_scripts.pory"
	step_end
# 188 "data/scripts/field_move_scripts.pory"

# 189 "data/scripts/field_move_scripts.pory"
Movement_WalkDown:
# 190 "data/scripts/field_move_scripts.pory"
	walk_down
# 191 "data/scripts/field_move_scripts.pory"
	step_end
# 192 "data/scripts/field_move_scripts.pory"

# 193 "data/scripts/field_move_scripts.pory"
Movement_JumpDown:
# 194 "data/scripts/field_move_scripts.pory"
	jump_in_place_down
# 195 "data/scripts/field_move_scripts.pory"
	step_end
# 196 "data/scripts/field_move_scripts.pory"

# 197 "data/scripts/field_move_scripts.pory"
Movement_WalkLeft:
# 198 "data/scripts/field_move_scripts.pory"
	walk_left
# 199 "data/scripts/field_move_scripts.pory"
	step_end
# 200 "data/scripts/field_move_scripts.pory"

# 201 "data/scripts/field_move_scripts.pory"
Movement_JumpLeft:
# 202 "data/scripts/field_move_scripts.pory"
	jump_in_place_left
# 203 "data/scripts/field_move_scripts.pory"
	step_end
# 204 "data/scripts/field_move_scripts.pory"

# 205 "data/scripts/field_move_scripts.pory"
Movement_SmashRock:
# 206 "data/scripts/field_move_scripts.pory"
	rock_smash_break
# 207 "data/scripts/field_move_scripts.pory"
	step_end
# 208 "data/scripts/field_move_scripts.pory"

# 209 "data/scripts/field_move_scripts.pory"
EventScript_CantSmashRock::
# 210 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantSmash, MSGBOX_DEFAULT
# 211 "data/scripts/field_move_scripts.pory"
	releaseall
# 212 "data/scripts/field_move_scripts.pory"
	end
# 213 "data/scripts/field_move_scripts.pory"

# 214 "data/scripts/field_move_scripts.pory"
EventScript_CancelSmash::
# 215 "data/scripts/field_move_scripts.pory"
	closemessage
# 216 "data/scripts/field_move_scripts.pory"
	releaseall
# 217 "data/scripts/field_move_scripts.pory"
	end
# 218 "data/scripts/field_move_scripts.pory"

# 219 "data/scripts/field_move_scripts.pory"
Text_WantToSmash:
# 220 "data/scripts/field_move_scripts.pory"
	.string "This rock appears to be breakable.\n"
# 221 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use ROCK SMASH?$"
# 222 "data/scripts/field_move_scripts.pory"

# 223 "data/scripts/field_move_scripts.pory"
Text_CantSmash:
# 224 "data/scripts/field_move_scripts.pory"
	.string "It's a rugged rock, but a POKéMON\n"
# 225 "data/scripts/field_move_scripts.pory"
	.string "may be able to smash it.$"
# 226 "data/scripts/field_move_scripts.pory"

# 227 "data/scripts/field_move_scripts.pory"
EventScript_CantStrength::
# 228 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantStrength, MSGBOX_DEFAULT
# 229 "data/scripts/field_move_scripts.pory"
	releaseall
# 230 "data/scripts/field_move_scripts.pory"
	end
# 231 "data/scripts/field_move_scripts.pory"

# 232 "data/scripts/field_move_scripts.pory"
EventScript_CheckActivatedBoulder::
# 233 "data/scripts/field_move_scripts.pory"
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
# 234 "data/scripts/field_move_scripts.pory"
	releaseall
# 235 "data/scripts/field_move_scripts.pory"
	end
# 236 "data/scripts/field_move_scripts.pory"

# 237 "data/scripts/field_move_scripts.pory"
Text_WantToStrength:
# 238 "data/scripts/field_move_scripts.pory"
	.string "It's a big boulder, but a POKéMON\n"
# 239 "data/scripts/field_move_scripts.pory"
	.string "may be able to push it aside.\p"
# 240 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use STRENGTH?$"
# 241 "data/scripts/field_move_scripts.pory"

# 242 "data/scripts/field_move_scripts.pory"
Text_MonUsedStrength:
# 243 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used STRENGTH!\p"
# 244 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1}'s STRENGTH made it\n"
# 245 "data/scripts/field_move_scripts.pory"
	.string "possible to move boulders around!$"
# 246 "data/scripts/field_move_scripts.pory"

# 247 "data/scripts/field_move_scripts.pory"
Text_CantStrength:
# 248 "data/scripts/field_move_scripts.pory"
	.string "It's a big boulder, but a POKéMON\n"
# 249 "data/scripts/field_move_scripts.pory"
	.string "may be able to push it aside.$"
# 250 "data/scripts/field_move_scripts.pory"

# 251 "data/scripts/field_move_scripts.pory"
Text_StrengthActivated:
# 252 "data/scripts/field_move_scripts.pory"
	.string "STRENGTH made it possible to move\n"
# 253 "data/scripts/field_move_scripts.pory"
	.string "boulders around.$"
# 254 "data/scripts/field_move_scripts.pory"

# 255 "data/scripts/field_move_scripts.pory"
EventScript_UseWaterfall::
# 256 "data/scripts/field_move_scripts.pory"
	lockall
# 257 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_WATERFALL
# 258 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWaterfall
# 259 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 260 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 261 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
# 262 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
# 263 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
# 264 "data/scripts/field_move_scripts.pory"
	hidefollowernpc
# 265 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_WATERFALL
# 266 "data/scripts/field_move_scripts.pory"
	callnative FollowerNPC_WarpSetEnd
# 267 "data/scripts/field_move_scripts.pory"
	goto EventScript_EndWaterfall
# 268 "data/scripts/field_move_scripts.pory"

# 269 "data/scripts/field_move_scripts.pory"
EventScript_CannotUseWaterfall::
# 270 "data/scripts/field_move_scripts.pory"
	lockall
# 271 "data/scripts/field_move_scripts.pory"

# 272 "data/scripts/field_move_scripts.pory"
EventScript_CantWaterfall::
# 273 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT
# 274 "data/scripts/field_move_scripts.pory"

# 275 "data/scripts/field_move_scripts.pory"
EventScript_EndWaterfall::
# 276 "data/scripts/field_move_scripts.pory"
	releaseall
# 277 "data/scripts/field_move_scripts.pory"
	end
# 278 "data/scripts/field_move_scripts.pory"

# 279 "data/scripts/field_move_scripts.pory"
Text_CantWaterfall:
# 280 "data/scripts/field_move_scripts.pory"
	.string "A wall of water is crashing down with\n"
# 281 "data/scripts/field_move_scripts.pory"
	.string "a mighty roar.$"
# 282 "data/scripts/field_move_scripts.pory"

# 283 "data/scripts/field_move_scripts.pory"
Text_WantToWaterfall:
# 284 "data/scripts/field_move_scripts.pory"
	.string "It's a large waterfall.\n"
# 285 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use WATERFALL?$"
# 286 "data/scripts/field_move_scripts.pory"

# 287 "data/scripts/field_move_scripts.pory"
Text_MonUsedWaterfall:
# 288 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used WATERFALL.$"
# 289 "data/scripts/field_move_scripts.pory"

# 290 "data/scripts/field_move_scripts.pory"
EventScript_UseDive::
# 291 "data/scripts/field_move_scripts.pory"
	lockall
# 292 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_DIVE
# 293 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
# 294 "data/scripts/field_move_scripts.pory"
	copyvar 0x8004 VAR_RESULT
# 295 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 296 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 297 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 1, 1
# 298 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToDive, MSGBOX_YESNO
# 299 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
# 300 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
# 301 "data/scripts/field_move_scripts.pory"
	hidefollowernpc
# 302 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_0x8004
# 303 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 1, 1
# 304 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_DIVE
# 305 "data/scripts/field_move_scripts.pory"
	goto EventScript_EndDive
# 306 "data/scripts/field_move_scripts.pory"
	end
# 307 "data/scripts/field_move_scripts.pory"

# 308 "data/scripts/field_move_scripts.pory"
EventScript_CantDive::
# 309 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantDive, MSGBOX_DEFAULT
# 310 "data/scripts/field_move_scripts.pory"
	releaseall
# 311 "data/scripts/field_move_scripts.pory"
	end
# 312 "data/scripts/field_move_scripts.pory"

# 313 "data/scripts/field_move_scripts.pory"
EventScript_EndDive::
# 314 "data/scripts/field_move_scripts.pory"
	releaseall
# 315 "data/scripts/field_move_scripts.pory"
	end
# 316 "data/scripts/field_move_scripts.pory"

# 317 "data/scripts/field_move_scripts.pory"
EventScript_UseDiveUnderwater::
# 318 "data/scripts/field_move_scripts.pory"
	lockall
# 319 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_DIVE
# 320 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
# 321 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 322 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 323 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 1, 1
# 324 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToSurface, MSGBOX_YESNO
# 325 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_NoSurface
# 326 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
# 327 "data/scripts/field_move_scripts.pory"
	hidefollowernpc
# 328 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_DIVE
# 329 "data/scripts/field_move_scripts.pory"
	goto EventScript_EndSurface
# 330 "data/scripts/field_move_scripts.pory"
	end
# 331 "data/scripts/field_move_scripts.pory"

# 332 "data/scripts/field_move_scripts.pory"
EventScript_CantSurface::
# 333 "data/scripts/field_move_scripts.pory"
	lockall
# 334 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantSurface, MSGBOX_DEFAULT
# 335 "data/scripts/field_move_scripts.pory"
	goto EventScript_EndSurface
# 336 "data/scripts/field_move_scripts.pory"
	end
# 337 "data/scripts/field_move_scripts.pory"

# 338 "data/scripts/field_move_scripts.pory"
EventScript_EndSurface::
# 339 "data/scripts/field_move_scripts.pory"
	callnative SetFollowerNPCSurfSpriteAfterDive
# 340 "data/scripts/field_move_scripts.pory"
EventScript_NoSurface::
# 341 "data/scripts/field_move_scripts.pory"
	releaseall
# 342 "data/scripts/field_move_scripts.pory"
	end
# 343 "data/scripts/field_move_scripts.pory"

# 344 "data/scripts/field_move_scripts.pory"
EventScript_DigCommon:
# 345 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 346 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
# 347 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_DIG
# 348 "data/scripts/field_move_scripts.pory"
	waitstate
# 349 "data/scripts/field_move_scripts.pory"
EventScript_DigSealedChamber:: @ fallthrough
# 350 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 351 "data/scripts/field_move_scripts.pory"
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
# 352 "data/scripts/field_move_scripts.pory"
	callnative DoBrailleDigEffect
# 353 "data/scripts/field_move_scripts.pory"
	releaseall
# 354 "data/scripts/field_move_scripts.pory"
	end
# 355 "data/scripts/field_move_scripts.pory"

# 356 "data/scripts/field_move_scripts.pory"
@ Use Dig from party menu
# 357 "data/scripts/field_move_scripts.pory"
EventScript_UseDig::
# 358 "data/scripts/field_move_scripts.pory"
	lockall
# 359 "data/scripts/field_move_scripts.pory"
	goto EventScript_DigCommon
# 360 "data/scripts/field_move_scripts.pory"

# 361 "data/scripts/field_move_scripts.pory"

# 362 "data/scripts/field_move_scripts.pory"
EventScript_CutGrassCommon:
# 363 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 364 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
# 365 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_CUT_ON_GRASS
# 366 "data/scripts/field_move_scripts.pory"
	waitstate
# 367 "data/scripts/field_move_scripts.pory"

# 368 "data/scripts/field_move_scripts.pory"
@ Use Cut grass from party menu
# 369 "data/scripts/field_move_scripts.pory"
EventScript_UseCutGrass::
# 370 "data/scripts/field_move_scripts.pory"
	lockall
# 371 "data/scripts/field_move_scripts.pory"
	goto EventScript_CutGrassCommon
# 372 "data/scripts/field_move_scripts.pory"

# 373 "data/scripts/field_move_scripts.pory"
Text_CantDive:
# 374 "data/scripts/field_move_scripts.pory"
	.string "The sea is deep here. A POKéMON\n"
# 375 "data/scripts/field_move_scripts.pory"
	.string "may be able to go underwater.$"
# 376 "data/scripts/field_move_scripts.pory"

# 377 "data/scripts/field_move_scripts.pory"
Text_WantToDive:
# 378 "data/scripts/field_move_scripts.pory"
	.string "The sea is deep here.\n"
# 379 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use DIVE?$"
# 380 "data/scripts/field_move_scripts.pory"

# 381 "data/scripts/field_move_scripts.pory"
Text_MonUsedDive:
# 382 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used DIVE.$"
# 383 "data/scripts/field_move_scripts.pory"

# 384 "data/scripts/field_move_scripts.pory"
Text_CantSurface:
# 385 "data/scripts/field_move_scripts.pory"
	.string "Light is filtering down from above.\n"
# 386 "data/scripts/field_move_scripts.pory"
	.string "A POKéMON may be able to surface.$"
# 387 "data/scripts/field_move_scripts.pory"

# 388 "data/scripts/field_move_scripts.pory"
Text_WantToSurface:
# 389 "data/scripts/field_move_scripts.pory"
	.string "Light is filtering down from above.\n"
# 390 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use DIVE?$"
# 391 "data/scripts/field_move_scripts.pory"

# 392 "data/scripts/field_move_scripts.pory"
EventScript_FailSweetScent::
# 393 "data/scripts/field_move_scripts.pory"
	msgbox Text_FailSweetScent, MSGBOX_SIGN
# 394 "data/scripts/field_move_scripts.pory"
	end
# 395 "data/scripts/field_move_scripts.pory"

# 396 "data/scripts/field_move_scripts.pory"
Text_FailSweetScent:
# 397 "data/scripts/field_move_scripts.pory"
	.string "Looks like there's nothing here…$"
# 398 "data/scripts/field_move_scripts.pory"

# 399 "data/scripts/field_move_scripts.pory"
EventScript_UseDefog::
# 400 "data/scripts/field_move_scripts.pory"
	lockall
# 401 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 402 "data/scripts/field_move_scripts.pory"
	buffermovename STR_VAR_2, MOVE_DEFOG
# 403 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 404 "data/scripts/field_move_scripts.pory"
	closemessage
# 405 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 406 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
# 407 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 408 "data/scripts/field_move_scripts.pory"
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
# 409 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 410 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 411 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_DEFOG
# 412 "data/scripts/field_move_scripts.pory"
	waitstate
# 413 "data/scripts/field_move_scripts.pory"
	releaseall
# 414 "data/scripts/field_move_scripts.pory"
	end

EventScript_StrengthBoulder::
# 419 "data/scripts/field_move_scripts.pory"
	lockall
# 420 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_BADGE04_GET, EventScript_StrengthBoulder_2
# 439 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantStrength, MSGBOX_DEFAULT
# 440 "data/scripts/field_move_scripts.pory"
	closemessage
EventScript_StrengthBoulder_1:
# 442 "data/scripts/field_move_scripts.pory"
	releaseall
	return

EventScript_StrengthBoulder_2:
# 421 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_StrengthBoulder_5
# 425 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_STRENGTH
# 426 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_StrengthBoulder_8
# 435 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareStrength
	goto EventScript_StrengthBoulder_1

EventScript_StrengthBoulder_5:
# 422 "data/scripts/field_move_scripts.pory"
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
# 423 "data/scripts/field_move_scripts.pory"
	closemessage
	goto EventScript_StrengthBoulder_1

EventScript_StrengthBoulder_8:
# 427 "data/scripts/field_move_scripts.pory"
	checkpartylearnable MOVE_STRENGTH
# 428 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_StrengthBoulder_11
# 432 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareStrength
	goto EventScript_StrengthBoulder_1

EventScript_StrengthBoulder_11:
# 429 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantStrength, MSGBOX_DEFAULT
# 430 "data/scripts/field_move_scripts.pory"
	closemessage
	goto EventScript_StrengthBoulder_1


EventScript_PrepareStrength::
# 446 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 447 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToStrength, MSGBOX_YESNO
# 448 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PrepareStrength_1
# 454 "data/scripts/field_move_scripts.pory"
	closemessage
	return

EventScript_PrepareStrength_1:
# 449 "data/scripts/field_move_scripts.pory"
	closemessage
# 450 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_STRENGTH
# 451 "data/scripts/field_move_scripts.pory"
	waitstate
# 452 "data/scripts/field_move_scripts.pory"
	call EventScript_ActivateStrength
	return


EventScript_UseStrength::
# 459 "data/scripts/field_move_scripts.pory"
	lockall
# 460 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_STRENGTH
# 461 "data/scripts/field_move_scripts.pory"
	waitstate
# 462 "data/scripts/field_move_scripts.pory"
	call EventScript_ActivateStrength
# 463 "data/scripts/field_move_scripts.pory"
	releaseall
	return


EventScript_ActivateStrength::
# 467 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SYS_USE_STRENGTH
# 468 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	return

