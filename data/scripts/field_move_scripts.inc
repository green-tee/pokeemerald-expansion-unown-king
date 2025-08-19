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
@ Use rock smash from party menu
# 20 "data/scripts/field_move_scripts.pory"
EventScript_UseRockSmash::
# 21 "data/scripts/field_move_scripts.pory"
	lockall
# 22 "data/scripts/field_move_scripts.pory"
	goto EventScript_RockSmashCommon
# 23 "data/scripts/field_move_scripts.pory"

# 24 "data/scripts/field_move_scripts.pory"
@ Interact with smashable rock
# 25 "data/scripts/field_move_scripts.pory"
EventScript_RockSmash::
# 26 "data/scripts/field_move_scripts.pory"
	lockall
# 27 "data/scripts/field_move_scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, EventScript_CantSmashRock
# 28 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_ROCK_SMASH
# 29 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
# 30 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 31 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 32 "data/scripts/field_move_scripts.pory"
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
# 33 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToSmash, MSGBOX_YESNO
# 34 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
# 35 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 36 "data/scripts/field_move_scripts.pory"
	closemessage
# 37 "data/scripts/field_move_scripts.pory"
EventScript_RockSmashCommon:
# 38 "data/scripts/field_move_scripts.pory"
	@ check if follower should use the field move
# 39 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 40 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
# 41 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_ROCK_SMASH
# 42 "data/scripts/field_move_scripts.pory"
	waitstate
# 43 "data/scripts/field_move_scripts.pory"
EventScript_SmashRock:: @ fallthrough
# 44 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 45 "data/scripts/field_move_scripts.pory"
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
# 46 "data/scripts/field_move_scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_SmashRock
# 47 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 48 "data/scripts/field_move_scripts.pory"
	removeobject VAR_LAST_TALKED
# 49 "data/scripts/field_move_scripts.pory"
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
# 50 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
# 51 "data/scripts/field_move_scripts.pory"
	special RockSmashWildEncounter
# 52 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
# 53 "data/scripts/field_move_scripts.pory"
	waitstate
# 54 "data/scripts/field_move_scripts.pory"
	releaseall
# 55 "data/scripts/field_move_scripts.pory"
	end
# 56 "data/scripts/field_move_scripts.pory"

# 57 "data/scripts/field_move_scripts.pory"
EventScript_FollowerFieldMove:
# 58 "data/scripts/field_move_scripts.pory"
	getdirectiontoface VAR_0x8005, OBJ_EVENT_ID_FOLLOWER, OBJ_EVENT_ID_PLAYER
# 59 "data/scripts/field_move_scripts.pory"
	specialvar VAR_0x8006, GetPlayerFacingDirection
# 60 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_0x8005, DIR_NONE, EventScript_FollowerFieldMoveEnd
# 61 "data/scripts/field_move_scripts.pory"
	@ Swap follower and player
# 62 "data/scripts/field_move_scripts.pory"
	call EventScript_FollowerSwap
# 63 "data/scripts/field_move_scripts.pory"
	@ Face follower in direction and jump
# 64 "data/scripts/field_move_scripts.pory"
	switch VAR_0x8006
# 65 "data/scripts/field_move_scripts.pory"
	case DIR_NORTH, EventScript_FollowerJumpNorth
# 66 "data/scripts/field_move_scripts.pory"
	case DIR_EAST, EventScript_FollowerJumpEast
# 67 "data/scripts/field_move_scripts.pory"
	case DIR_SOUTH, EventScript_FollowerJumpSouth
# 68 "data/scripts/field_move_scripts.pory"
	case DIR_WEST, EventScript_FollowerJumpWest
# 69 "data/scripts/field_move_scripts.pory"
EventScript_FollowerFieldMoveEnd:
# 70 "data/scripts/field_move_scripts.pory"
	return
# 71 "data/scripts/field_move_scripts.pory"

# 72 "data/scripts/field_move_scripts.pory"
EventScript_FollowerSwap:
# 73 "data/scripts/field_move_scripts.pory"
	switch VAR_0x8005
# 74 "data/scripts/field_move_scripts.pory"
	case DIR_NORTH, EventScript_FollowerMoveNorth
# 75 "data/scripts/field_move_scripts.pory"
	case DIR_EAST, EventScript_FollowerMoveEast
# 76 "data/scripts/field_move_scripts.pory"
	case DIR_SOUTH, EventScript_FollowerMoveSouth
# 77 "data/scripts/field_move_scripts.pory"
	case DIR_WEST, EventScript_FollowerMoveWest
# 78 "data/scripts/field_move_scripts.pory"
	return
# 79 "data/scripts/field_move_scripts.pory"

# 80 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveNorth:
# 81 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkDown
# 82 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 83 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 84 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 85 "data/scripts/field_move_scripts.pory"
	return
# 86 "data/scripts/field_move_scripts.pory"

# 87 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveEast:
# 88 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkLeft
# 89 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 90 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 91 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 92 "data/scripts/field_move_scripts.pory"
	return
# 93 "data/scripts/field_move_scripts.pory"

# 94 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveSouth:
# 95 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp
# 96 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 97 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 98 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 99 "data/scripts/field_move_scripts.pory"
	return
# 100 "data/scripts/field_move_scripts.pory"

# 101 "data/scripts/field_move_scripts.pory"
EventScript_FollowerMoveWest:
# 102 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkRight
# 103 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 104 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 105 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 106 "data/scripts/field_move_scripts.pory"
	return
# 107 "data/scripts/field_move_scripts.pory"

# 108 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpNorth:
# 109 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpUp
# 110 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 111 "data/scripts/field_move_scripts.pory"
	return
# 112 "data/scripts/field_move_scripts.pory"

# 113 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpEast:
# 114 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpRight
# 115 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 116 "data/scripts/field_move_scripts.pory"
	return
# 117 "data/scripts/field_move_scripts.pory"

# 118 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpSouth:
# 119 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpDown
# 120 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 121 "data/scripts/field_move_scripts.pory"
	return
# 122 "data/scripts/field_move_scripts.pory"

# 123 "data/scripts/field_move_scripts.pory"
EventScript_FollowerJumpWest:
# 124 "data/scripts/field_move_scripts.pory"
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpLeft
# 125 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 126 "data/scripts/field_move_scripts.pory"
	return
# 127 "data/scripts/field_move_scripts.pory"

# 128 "data/scripts/field_move_scripts.pory"
EventScript_EndSmash::
# 129 "data/scripts/field_move_scripts.pory"
	releaseall
# 130 "data/scripts/field_move_scripts.pory"
	end
# 131 "data/scripts/field_move_scripts.pory"

# 132 "data/scripts/field_move_scripts.pory"
Movement_WalkUp:
# 133 "data/scripts/field_move_scripts.pory"
	walk_up
# 134 "data/scripts/field_move_scripts.pory"
	step_end
# 135 "data/scripts/field_move_scripts.pory"

# 136 "data/scripts/field_move_scripts.pory"
Movement_JumpUp:
# 137 "data/scripts/field_move_scripts.pory"
	jump_in_place_up
# 138 "data/scripts/field_move_scripts.pory"
	step_end
# 139 "data/scripts/field_move_scripts.pory"

# 140 "data/scripts/field_move_scripts.pory"
Movement_WalkRight:
# 141 "data/scripts/field_move_scripts.pory"
	walk_right
# 142 "data/scripts/field_move_scripts.pory"
	step_end
# 143 "data/scripts/field_move_scripts.pory"

# 144 "data/scripts/field_move_scripts.pory"
Movement_JumpRight:
# 145 "data/scripts/field_move_scripts.pory"
	jump_in_place_right
# 146 "data/scripts/field_move_scripts.pory"
	step_end
# 147 "data/scripts/field_move_scripts.pory"

# 148 "data/scripts/field_move_scripts.pory"
Movement_WalkDown:
# 149 "data/scripts/field_move_scripts.pory"
	walk_down
# 150 "data/scripts/field_move_scripts.pory"
	step_end
# 151 "data/scripts/field_move_scripts.pory"

# 152 "data/scripts/field_move_scripts.pory"
Movement_JumpDown:
# 153 "data/scripts/field_move_scripts.pory"
	jump_in_place_down
# 154 "data/scripts/field_move_scripts.pory"
	step_end
# 155 "data/scripts/field_move_scripts.pory"

# 156 "data/scripts/field_move_scripts.pory"
Movement_WalkLeft:
# 157 "data/scripts/field_move_scripts.pory"
	walk_left
# 158 "data/scripts/field_move_scripts.pory"
	step_end
# 159 "data/scripts/field_move_scripts.pory"

# 160 "data/scripts/field_move_scripts.pory"
Movement_JumpLeft:
# 161 "data/scripts/field_move_scripts.pory"
	jump_in_place_left
# 162 "data/scripts/field_move_scripts.pory"
	step_end
# 163 "data/scripts/field_move_scripts.pory"

# 164 "data/scripts/field_move_scripts.pory"
Movement_SmashRock:
# 165 "data/scripts/field_move_scripts.pory"
	rock_smash_break
# 166 "data/scripts/field_move_scripts.pory"
	step_end
# 167 "data/scripts/field_move_scripts.pory"

# 168 "data/scripts/field_move_scripts.pory"
EventScript_CantSmashRock::
# 169 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantSmash, MSGBOX_DEFAULT
# 170 "data/scripts/field_move_scripts.pory"
	releaseall
# 171 "data/scripts/field_move_scripts.pory"
	end
# 172 "data/scripts/field_move_scripts.pory"

# 173 "data/scripts/field_move_scripts.pory"
EventScript_CancelSmash::
# 174 "data/scripts/field_move_scripts.pory"
	closemessage
# 175 "data/scripts/field_move_scripts.pory"
	releaseall
# 176 "data/scripts/field_move_scripts.pory"
	end
# 177 "data/scripts/field_move_scripts.pory"

# 178 "data/scripts/field_move_scripts.pory"
Text_WantToSmash:
# 179 "data/scripts/field_move_scripts.pory"
	.string "This rock appears to be breakable.\n"
# 180 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use ROCK SMASH?$"
# 181 "data/scripts/field_move_scripts.pory"

# 182 "data/scripts/field_move_scripts.pory"
Text_CantSmash:
# 183 "data/scripts/field_move_scripts.pory"
	.string "It's a rugged rock, but a POKéMON\n"
# 184 "data/scripts/field_move_scripts.pory"
	.string "may be able to smash it.$"
# 185 "data/scripts/field_move_scripts.pory"

# 186 "data/scripts/field_move_scripts.pory"
EventScript_CantStrength::
# 187 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantStrength, MSGBOX_DEFAULT
# 188 "data/scripts/field_move_scripts.pory"
	releaseall
# 189 "data/scripts/field_move_scripts.pory"
	end
# 190 "data/scripts/field_move_scripts.pory"

# 191 "data/scripts/field_move_scripts.pory"
EventScript_CheckActivatedBoulder::
# 192 "data/scripts/field_move_scripts.pory"
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
# 193 "data/scripts/field_move_scripts.pory"
	releaseall
# 194 "data/scripts/field_move_scripts.pory"
	end
# 195 "data/scripts/field_move_scripts.pory"

# 196 "data/scripts/field_move_scripts.pory"
Text_WantToStrength:
# 197 "data/scripts/field_move_scripts.pory"
	.string "It's a big boulder, but a POKéMON\n"
# 198 "data/scripts/field_move_scripts.pory"
	.string "may be able to push it aside.\p"
# 199 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use STRENGTH?$"
# 200 "data/scripts/field_move_scripts.pory"

# 201 "data/scripts/field_move_scripts.pory"
Text_MonUsedStrength:
# 202 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used STRENGTH!\p"
# 203 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1}'s STRENGTH made it\n"
# 204 "data/scripts/field_move_scripts.pory"
	.string "possible to move boulders around!$"
# 205 "data/scripts/field_move_scripts.pory"

# 206 "data/scripts/field_move_scripts.pory"
Text_CantStrength:
# 207 "data/scripts/field_move_scripts.pory"
	.string "It's a big boulder, but a POKéMON\n"
# 208 "data/scripts/field_move_scripts.pory"
	.string "may be able to push it aside.$"
# 209 "data/scripts/field_move_scripts.pory"

# 210 "data/scripts/field_move_scripts.pory"
Text_StrengthActivated:
# 211 "data/scripts/field_move_scripts.pory"
	.string "STRENGTH made it possible to move\n"
# 212 "data/scripts/field_move_scripts.pory"
	.string "boulders around.$"
# 213 "data/scripts/field_move_scripts.pory"

# 214 "data/scripts/field_move_scripts.pory"
EventScript_UseWaterfall::
# 215 "data/scripts/field_move_scripts.pory"
	lockall
# 216 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_WATERFALL
# 217 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWaterfall
# 218 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 219 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 220 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
# 221 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
# 222 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
# 223 "data/scripts/field_move_scripts.pory"
	hidefollowernpc
# 224 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_WATERFALL
# 225 "data/scripts/field_move_scripts.pory"
	callnative FollowerNPC_WarpSetEnd
# 226 "data/scripts/field_move_scripts.pory"
	goto EventScript_EndWaterfall
# 227 "data/scripts/field_move_scripts.pory"

# 228 "data/scripts/field_move_scripts.pory"
EventScript_CannotUseWaterfall::
# 229 "data/scripts/field_move_scripts.pory"
	lockall
# 230 "data/scripts/field_move_scripts.pory"

# 231 "data/scripts/field_move_scripts.pory"
EventScript_CantWaterfall::
# 232 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT
# 233 "data/scripts/field_move_scripts.pory"

# 234 "data/scripts/field_move_scripts.pory"
EventScript_EndWaterfall::
# 235 "data/scripts/field_move_scripts.pory"
	releaseall
# 236 "data/scripts/field_move_scripts.pory"
	end
# 237 "data/scripts/field_move_scripts.pory"

# 238 "data/scripts/field_move_scripts.pory"
Text_CantWaterfall:
# 239 "data/scripts/field_move_scripts.pory"
	.string "A wall of water is crashing down with\n"
# 240 "data/scripts/field_move_scripts.pory"
	.string "a mighty roar.$"
# 241 "data/scripts/field_move_scripts.pory"

# 242 "data/scripts/field_move_scripts.pory"
Text_WantToWaterfall:
# 243 "data/scripts/field_move_scripts.pory"
	.string "It's a large waterfall.\n"
# 244 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use WATERFALL?$"
# 245 "data/scripts/field_move_scripts.pory"

# 246 "data/scripts/field_move_scripts.pory"
Text_MonUsedWaterfall:
# 247 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used WATERFALL.$"
# 248 "data/scripts/field_move_scripts.pory"

# 249 "data/scripts/field_move_scripts.pory"
EventScript_UseDive::
# 250 "data/scripts/field_move_scripts.pory"
	lockall
# 251 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_DIVE
# 252 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
# 253 "data/scripts/field_move_scripts.pory"
	copyvar 0x8004 VAR_RESULT
# 254 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 255 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 256 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 1, 1
# 257 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToDive, MSGBOX_YESNO
# 258 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
# 259 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
# 260 "data/scripts/field_move_scripts.pory"
	hidefollowernpc
# 261 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_0x8004
# 262 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 1, 1
# 263 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_DIVE
# 264 "data/scripts/field_move_scripts.pory"
	goto EventScript_EndDive
# 265 "data/scripts/field_move_scripts.pory"
	end
# 266 "data/scripts/field_move_scripts.pory"

# 267 "data/scripts/field_move_scripts.pory"
EventScript_CantDive::
# 268 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantDive, MSGBOX_DEFAULT
# 269 "data/scripts/field_move_scripts.pory"
	releaseall
# 270 "data/scripts/field_move_scripts.pory"
	end
# 271 "data/scripts/field_move_scripts.pory"

# 272 "data/scripts/field_move_scripts.pory"
EventScript_EndDive::
# 273 "data/scripts/field_move_scripts.pory"
	releaseall
# 274 "data/scripts/field_move_scripts.pory"
	end
# 275 "data/scripts/field_move_scripts.pory"

# 276 "data/scripts/field_move_scripts.pory"
EventScript_UseDiveUnderwater::
# 277 "data/scripts/field_move_scripts.pory"
	lockall
# 278 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_DIVE
# 279 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
# 280 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 281 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 282 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 1, 1
# 283 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToSurface, MSGBOX_YESNO
# 284 "data/scripts/field_move_scripts.pory"
	goto_if_eq VAR_RESULT, NO, EventScript_NoSurface
# 285 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
# 286 "data/scripts/field_move_scripts.pory"
	hidefollowernpc
# 287 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_DIVE
# 288 "data/scripts/field_move_scripts.pory"
	goto EventScript_EndSurface
# 289 "data/scripts/field_move_scripts.pory"
	end
# 290 "data/scripts/field_move_scripts.pory"

# 291 "data/scripts/field_move_scripts.pory"
EventScript_CantSurface::
# 292 "data/scripts/field_move_scripts.pory"
	lockall
# 293 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantSurface, MSGBOX_DEFAULT
# 294 "data/scripts/field_move_scripts.pory"
	goto EventScript_EndSurface
# 295 "data/scripts/field_move_scripts.pory"
	end
# 296 "data/scripts/field_move_scripts.pory"

# 297 "data/scripts/field_move_scripts.pory"
EventScript_EndSurface::
# 298 "data/scripts/field_move_scripts.pory"
	callnative SetFollowerNPCSurfSpriteAfterDive
# 299 "data/scripts/field_move_scripts.pory"
EventScript_NoSurface::
# 300 "data/scripts/field_move_scripts.pory"
	releaseall
# 301 "data/scripts/field_move_scripts.pory"
	end
# 302 "data/scripts/field_move_scripts.pory"

# 303 "data/scripts/field_move_scripts.pory"
EventScript_DigCommon:
# 304 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 305 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
# 306 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_DIG
# 307 "data/scripts/field_move_scripts.pory"
	waitstate
# 308 "data/scripts/field_move_scripts.pory"
EventScript_DigSealedChamber:: @ fallthrough
# 309 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 310 "data/scripts/field_move_scripts.pory"
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
# 311 "data/scripts/field_move_scripts.pory"
	callnative DoBrailleDigEffect
# 312 "data/scripts/field_move_scripts.pory"
	releaseall
# 313 "data/scripts/field_move_scripts.pory"
	end
# 314 "data/scripts/field_move_scripts.pory"

# 315 "data/scripts/field_move_scripts.pory"
@ Use Dig from party menu
# 316 "data/scripts/field_move_scripts.pory"
EventScript_UseDig::
# 317 "data/scripts/field_move_scripts.pory"
	lockall
# 318 "data/scripts/field_move_scripts.pory"
	goto EventScript_DigCommon
# 319 "data/scripts/field_move_scripts.pory"

# 320 "data/scripts/field_move_scripts.pory"

# 321 "data/scripts/field_move_scripts.pory"
EventScript_CutGrassCommon:
# 322 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 323 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
# 324 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_CUT_ON_GRASS
# 325 "data/scripts/field_move_scripts.pory"
	waitstate
# 326 "data/scripts/field_move_scripts.pory"

# 327 "data/scripts/field_move_scripts.pory"
@ Use Cut grass from party menu
# 328 "data/scripts/field_move_scripts.pory"
EventScript_UseCutGrass::
# 329 "data/scripts/field_move_scripts.pory"
	lockall
# 330 "data/scripts/field_move_scripts.pory"
	goto EventScript_CutGrassCommon
# 331 "data/scripts/field_move_scripts.pory"

# 332 "data/scripts/field_move_scripts.pory"
Text_CantDive:
# 333 "data/scripts/field_move_scripts.pory"
	.string "The sea is deep here. A POKéMON\n"
# 334 "data/scripts/field_move_scripts.pory"
	.string "may be able to go underwater.$"
# 335 "data/scripts/field_move_scripts.pory"

# 336 "data/scripts/field_move_scripts.pory"
Text_WantToDive:
# 337 "data/scripts/field_move_scripts.pory"
	.string "The sea is deep here.\n"
# 338 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use DIVE?$"
# 339 "data/scripts/field_move_scripts.pory"

# 340 "data/scripts/field_move_scripts.pory"
Text_MonUsedDive:
# 341 "data/scripts/field_move_scripts.pory"
	.string "{STR_VAR_1} used DIVE.$"
# 342 "data/scripts/field_move_scripts.pory"

# 343 "data/scripts/field_move_scripts.pory"
Text_CantSurface:
# 344 "data/scripts/field_move_scripts.pory"
	.string "Light is filtering down from above.\n"
# 345 "data/scripts/field_move_scripts.pory"
	.string "A POKéMON may be able to surface.$"
# 346 "data/scripts/field_move_scripts.pory"

# 347 "data/scripts/field_move_scripts.pory"
Text_WantToSurface:
# 348 "data/scripts/field_move_scripts.pory"
	.string "Light is filtering down from above.\n"
# 349 "data/scripts/field_move_scripts.pory"
	.string "Would you like to use DIVE?$"
# 350 "data/scripts/field_move_scripts.pory"

# 351 "data/scripts/field_move_scripts.pory"
EventScript_FailSweetScent::
# 352 "data/scripts/field_move_scripts.pory"
	msgbox Text_FailSweetScent, MSGBOX_SIGN
# 353 "data/scripts/field_move_scripts.pory"
	end
# 354 "data/scripts/field_move_scripts.pory"

# 355 "data/scripts/field_move_scripts.pory"
Text_FailSweetScent:
# 356 "data/scripts/field_move_scripts.pory"
	.string "Looks like there's nothing here…$"
# 357 "data/scripts/field_move_scripts.pory"

# 358 "data/scripts/field_move_scripts.pory"
EventScript_UseDefog::
# 359 "data/scripts/field_move_scripts.pory"
	lockall
# 360 "data/scripts/field_move_scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_RESULT
# 361 "data/scripts/field_move_scripts.pory"
	buffermovename STR_VAR_2, MOVE_DEFOG
# 362 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 363 "data/scripts/field_move_scripts.pory"
	closemessage
# 364 "data/scripts/field_move_scripts.pory"
	isfollowerfieldmoveuser VAR_0x8004
# 365 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
# 366 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 367 "data/scripts/field_move_scripts.pory"
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
# 368 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 369 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 370 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_DEFOG
# 371 "data/scripts/field_move_scripts.pory"
	waitstate
# 372 "data/scripts/field_move_scripts.pory"
	releaseall
# 373 "data/scripts/field_move_scripts.pory"
	end

EventScript_CutTree::
# 378 "data/scripts/field_move_scripts.pory"
	lockall
# 379 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_BADGE01_GET, EventScript_CutTree_2
# 393 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantCut, MSGBOX_DEFAULT
# 394 "data/scripts/field_move_scripts.pory"
	closemessage
EventScript_CutTree_1:
# 396 "data/scripts/field_move_scripts.pory"
	releaseall
	return

EventScript_CutTree_2:
# 380 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_CUT
# 381 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_CutTree_5
# 390 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareCut
	goto EventScript_CutTree_1

EventScript_CutTree_5:
# 382 "data/scripts/field_move_scripts.pory"
	checkpartylearnable MOVE_CUT
# 383 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_CutTree_8
# 387 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareCut
	goto EventScript_CutTree_1

EventScript_CutTree_8:
# 384 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantCut, MSGBOX_DEFAULT
# 385 "data/scripts/field_move_scripts.pory"
	closemessage
	goto EventScript_CutTree_1


EventScript_PrepareCut::
# 401 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 402 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToCut, MSGBOX_YESNO
# 403 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PrepareCut_1
# 407 "data/scripts/field_move_scripts.pory"
	closemessage
	return

EventScript_PrepareCut_1:
# 404 "data/scripts/field_move_scripts.pory"
	closemessage
# 405 "data/scripts/field_move_scripts.pory"
	call EventScript_CutTreeCommon
	return


EventScript_CutTreeCommon::
# 413 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 3, FALSE
# 414 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
# 415 "data/scripts/field_move_scripts.pory"
	waitstate
# 416 "data/scripts/field_move_scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
# 417 "data/scripts/field_move_scripts.pory"
	waitmovement 0
# 418 "data/scripts/field_move_scripts.pory"
	removeobject VAR_LAST_TALKED
	return


EventScript_UseCut::
# 423 "data/scripts/field_move_scripts.pory"
	lockall
# 424 "data/scripts/field_move_scripts.pory"
	call EventScript_CutTreeCommon
# 425 "data/scripts/field_move_scripts.pory"
	releaseall
	return


EventScript_StrengthBoulder::
# 430 "data/scripts/field_move_scripts.pory"
	lockall
# 431 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_BADGE04_GET, EventScript_StrengthBoulder_2
# 450 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantStrength, MSGBOX_DEFAULT
# 451 "data/scripts/field_move_scripts.pory"
	closemessage
EventScript_StrengthBoulder_1:
# 453 "data/scripts/field_move_scripts.pory"
	releaseall
	return

EventScript_StrengthBoulder_2:
# 432 "data/scripts/field_move_scripts.pory"
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_StrengthBoulder_5
# 436 "data/scripts/field_move_scripts.pory"
	checkpartymove MOVE_STRENGTH
# 437 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_StrengthBoulder_8
# 446 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareStrength
	goto EventScript_StrengthBoulder_1

EventScript_StrengthBoulder_5:
# 433 "data/scripts/field_move_scripts.pory"
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
# 434 "data/scripts/field_move_scripts.pory"
	closemessage
	goto EventScript_StrengthBoulder_1

EventScript_StrengthBoulder_8:
# 438 "data/scripts/field_move_scripts.pory"
	checkpartylearnable MOVE_STRENGTH
# 439 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_StrengthBoulder_11
# 443 "data/scripts/field_move_scripts.pory"
	call EventScript_PrepareStrength
	goto EventScript_StrengthBoulder_1

EventScript_StrengthBoulder_11:
# 440 "data/scripts/field_move_scripts.pory"
	msgbox Text_CantStrength, MSGBOX_DEFAULT
# 441 "data/scripts/field_move_scripts.pory"
	closemessage
	goto EventScript_StrengthBoulder_1


EventScript_PrepareStrength::
# 458 "data/scripts/field_move_scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 459 "data/scripts/field_move_scripts.pory"
	msgbox Text_WantToStrength, MSGBOX_YESNO
# 460 "data/scripts/field_move_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PrepareStrength_1
# 466 "data/scripts/field_move_scripts.pory"
	closemessage
	return

EventScript_PrepareStrength_1:
# 461 "data/scripts/field_move_scripts.pory"
	closemessage
# 462 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_STRENGTH
# 463 "data/scripts/field_move_scripts.pory"
	waitstate
# 464 "data/scripts/field_move_scripts.pory"
	call EventScript_ActivateStrength
	return


EventScript_UseStrength::
# 472 "data/scripts/field_move_scripts.pory"
	lockall
# 473 "data/scripts/field_move_scripts.pory"
	dofieldeffect FLDEFF_USE_STRENGTH
# 474 "data/scripts/field_move_scripts.pory"
	waitstate
# 475 "data/scripts/field_move_scripts.pory"
	call EventScript_ActivateStrength
# 476 "data/scripts/field_move_scripts.pory"
	releaseall
	return


EventScript_ActivateStrength::
# 481 "data/scripts/field_move_scripts.pory"
	setflag FLAG_SYS_USE_STRENGTH
# 482 "data/scripts/field_move_scripts.pory"
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	return

