# 1 "data/scripts/move_tutors.pory"

# 2 "data/scripts/move_tutors.pory"
SlateportCity_PokemonFanClub_EventScript_SwaggerTutor::
# 3 "data/scripts/move_tutors.pory"
	lock
# 4 "data/scripts/move_tutors.pory"
	faceplayer
# 5 "data/scripts/move_tutors.pory"
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SWAGGER, MoveTutor_EventScript_SwaggerTaught
# 6 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SwaggerTeach, MSGBOX_YESNO
# 7 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SwaggerDeclined
# 8 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 9 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SwaggerDeclined
# 10 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SwaggerWhichMon, MSGBOX_DEFAULT
# 11 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_SWAGGER
# 12 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 13 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SwaggerDeclined
# 14 "data/scripts/move_tutors.pory"
	setflag FLAG_MOVE_TUTOR_TAUGHT_SWAGGER
# 15 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_SwaggerTaught
# 16 "data/scripts/move_tutors.pory"
	end
# 17 "data/scripts/move_tutors.pory"

# 18 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_SwaggerDeclined::
# 19 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SwaggerDeclined, MSGBOX_DEFAULT
# 20 "data/scripts/move_tutors.pory"
	release
# 21 "data/scripts/move_tutors.pory"
	end
# 22 "data/scripts/move_tutors.pory"

# 23 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_SwaggerTaught::
# 24 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SwaggerTaught, MSGBOX_DEFAULT
# 25 "data/scripts/move_tutors.pory"
	release
# 26 "data/scripts/move_tutors.pory"
	end
# 27 "data/scripts/move_tutors.pory"

# 28 "data/scripts/move_tutors.pory"
MauvilleCity_EventScript_RolloutTutor::
# 29 "data/scripts/move_tutors.pory"
	lock
# 30 "data/scripts/move_tutors.pory"
	faceplayer
# 31 "data/scripts/move_tutors.pory"
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_ROLLOUT, MoveTutor_EventScript_RolloutTaught
# 32 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_RolloutTeach, MSGBOX_YESNO
# 33 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RolloutDeclined
# 34 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 35 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RolloutDeclined
# 36 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_RolloutWhichMon, MSGBOX_DEFAULT
# 37 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_ROLLOUT
# 38 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 39 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_RolloutDeclined
# 40 "data/scripts/move_tutors.pory"
	setflag FLAG_MOVE_TUTOR_TAUGHT_ROLLOUT
# 41 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_RolloutTaught
# 42 "data/scripts/move_tutors.pory"
	end
# 43 "data/scripts/move_tutors.pory"

# 44 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_RolloutDeclined::
# 45 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_RolloutDeclined, MSGBOX_DEFAULT
# 46 "data/scripts/move_tutors.pory"
	release
# 47 "data/scripts/move_tutors.pory"
	end
# 48 "data/scripts/move_tutors.pory"

# 49 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_RolloutTaught::
# 50 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_RolloutTaught, MSGBOX_DEFAULT
# 51 "data/scripts/move_tutors.pory"
	release
# 52 "data/scripts/move_tutors.pory"
	end
# 53 "data/scripts/move_tutors.pory"

# 54 "data/scripts/move_tutors.pory"
VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor::
# 55 "data/scripts/move_tutors.pory"
	lock
# 56 "data/scripts/move_tutors.pory"
	faceplayer
# 57 "data/scripts/move_tutors.pory"
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER, MoveTutor_EventScript_FuryCutterTaught
# 58 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_FuryCutterTeach, MSGBOX_YESNO
# 59 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FuryCutterDeclined
# 60 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 61 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FuryCutterDeclined
# 62 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_FuryCutterWhichMon, MSGBOX_DEFAULT
# 63 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_FURY_CUTTER
# 64 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 65 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_FuryCutterDeclined
# 66 "data/scripts/move_tutors.pory"
	setflag FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER
# 67 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_FuryCutterTaught
# 68 "data/scripts/move_tutors.pory"
	end
# 69 "data/scripts/move_tutors.pory"

# 70 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_FuryCutterDeclined::
# 71 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
# 72 "data/scripts/move_tutors.pory"
	release
# 73 "data/scripts/move_tutors.pory"
	end
# 74 "data/scripts/move_tutors.pory"

# 75 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_FuryCutterTaught::
# 76 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_FuryCutterTaught, MSGBOX_DEFAULT
# 77 "data/scripts/move_tutors.pory"
	release
# 78 "data/scripts/move_tutors.pory"
	end
# 79 "data/scripts/move_tutors.pory"

# 80 "data/scripts/move_tutors.pory"
LavaridgeTown_House_EventScript_MimicTutor::
# 81 "data/scripts/move_tutors.pory"
	lock
# 82 "data/scripts/move_tutors.pory"
	faceplayer
# 83 "data/scripts/move_tutors.pory"
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_MIMIC, MoveTutor_EventScript_MimicTaught
# 84 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_MimicTeach, MSGBOX_YESNO
# 85 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MimicDeclined
# 86 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 87 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MimicDeclined
# 88 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_MimicWhichMon, MSGBOX_DEFAULT
# 89 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_MIMIC
# 90 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 91 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MimicDeclined
# 92 "data/scripts/move_tutors.pory"
	setflag FLAG_MOVE_TUTOR_TAUGHT_MIMIC
# 93 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_MimicTaught
# 94 "data/scripts/move_tutors.pory"
	end
# 95 "data/scripts/move_tutors.pory"

# 96 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_MimicDeclined::
# 97 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_MimicDeclined, MSGBOX_DEFAULT
# 98 "data/scripts/move_tutors.pory"
	release
# 99 "data/scripts/move_tutors.pory"
	end
# 100 "data/scripts/move_tutors.pory"

# 101 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_MimicTaught::
# 102 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_MimicTaught, MSGBOX_DEFAULT
# 103 "data/scripts/move_tutors.pory"
	release
# 104 "data/scripts/move_tutors.pory"
	end
# 105 "data/scripts/move_tutors.pory"

# 106 "data/scripts/move_tutors.pory"
FallarborTown_Mart_EventScript_MetronomeTutor::
# 107 "data/scripts/move_tutors.pory"
	lock
# 108 "data/scripts/move_tutors.pory"
	faceplayer
# 109 "data/scripts/move_tutors.pory"
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_METRONOME, MoveTutor_EventScript_MetronomeTaught
# 110 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_MetronomeTeach, MSGBOX_YESNO
# 111 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MetronomeDeclined
# 112 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 113 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MetronomeDeclined
# 114 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_MetronomeWhichMon, MSGBOX_DEFAULT
# 115 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_METRONOME
# 116 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 117 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MetronomeDeclined
# 118 "data/scripts/move_tutors.pory"
	setflag FLAG_MOVE_TUTOR_TAUGHT_METRONOME
# 119 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_MetronomeTaught
# 120 "data/scripts/move_tutors.pory"
	end
# 121 "data/scripts/move_tutors.pory"

# 122 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_MetronomeDeclined::
# 123 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_MetronomeDeclined, MSGBOX_DEFAULT
# 124 "data/scripts/move_tutors.pory"
	release
# 125 "data/scripts/move_tutors.pory"
	end
# 126 "data/scripts/move_tutors.pory"

# 127 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_MetronomeTaught::
# 128 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_MetronomeTaught, MSGBOX_DEFAULT
# 129 "data/scripts/move_tutors.pory"
	release
# 130 "data/scripts/move_tutors.pory"
	end
# 131 "data/scripts/move_tutors.pory"

# 132 "data/scripts/move_tutors.pory"
FortreeCity_House2_EventScript_SleepTalkTutor::
# 133 "data/scripts/move_tutors.pory"
	lock
# 134 "data/scripts/move_tutors.pory"
	faceplayer
# 135 "data/scripts/move_tutors.pory"
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK, MoveTutor_EventScript_SleepTalkTaught
# 136 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SleepTalkTeach, MSGBOX_YESNO
# 137 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SleepTalkDeclined
# 138 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 139 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SleepTalkDeclined
# 140 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SleepTalkWhichMon, MSGBOX_DEFAULT
# 141 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_SLEEP_TALK
# 142 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 143 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SleepTalkDeclined
# 144 "data/scripts/move_tutors.pory"
	setflag FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK
# 145 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_SleepTalkTaught
# 146 "data/scripts/move_tutors.pory"
	end
# 147 "data/scripts/move_tutors.pory"

# 148 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_SleepTalkDeclined::
# 149 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SleepTalkDeclined, MSGBOX_DEFAULT
# 150 "data/scripts/move_tutors.pory"
	release
# 151 "data/scripts/move_tutors.pory"
	end
# 152 "data/scripts/move_tutors.pory"

# 153 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_SleepTalkTaught::
# 154 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SleepTalkTaught, MSGBOX_DEFAULT
# 155 "data/scripts/move_tutors.pory"
	release
# 156 "data/scripts/move_tutors.pory"
	end
# 157 "data/scripts/move_tutors.pory"

# 158 "data/scripts/move_tutors.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor::
# 159 "data/scripts/move_tutors.pory"
	lock
# 160 "data/scripts/move_tutors.pory"
	faceplayer
# 161 "data/scripts/move_tutors.pory"
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SUBSTITUTE, MoveTutor_EventScript_SubstituteTaught
# 162 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SubstituteTeach, MSGBOX_YESNO
# 163 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SubstituteDeclined
# 164 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 165 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SubstituteDeclined
# 166 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SubstituteWhichMon, MSGBOX_DEFAULT
# 167 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_SUBSTITUTE
# 168 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 169 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SubstituteDeclined
# 170 "data/scripts/move_tutors.pory"
	setflag FLAG_MOVE_TUTOR_TAUGHT_SUBSTITUTE
# 171 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_SubstituteTaught
# 172 "data/scripts/move_tutors.pory"
	end
# 173 "data/scripts/move_tutors.pory"

# 174 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_SubstituteDeclined::
# 175 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SubstituteDeclined, MSGBOX_DEFAULT
# 176 "data/scripts/move_tutors.pory"
	release
# 177 "data/scripts/move_tutors.pory"
	end
# 178 "data/scripts/move_tutors.pory"

# 179 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_SubstituteTaught::
# 180 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SubstituteTaught, MSGBOX_DEFAULT
# 181 "data/scripts/move_tutors.pory"
	release
# 182 "data/scripts/move_tutors.pory"
	end
# 183 "data/scripts/move_tutors.pory"

# 184 "data/scripts/move_tutors.pory"
MossdeepCity_EventScript_DynamicPunchTutor::
# 185 "data/scripts/move_tutors.pory"
	lock
# 186 "data/scripts/move_tutors.pory"
	faceplayer
# 187 "data/scripts/move_tutors.pory"
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH, MoveTutor_EventScript_DynamicPunchTaught
# 188 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DynamicPunchTeach, MSGBOX_YESNO
# 189 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DynamicPunchDeclined
# 190 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 191 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DynamicPunchDeclined
# 192 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DynamicPunchWhichMon, MSGBOX_DEFAULT
# 193 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_DYNAMIC_PUNCH
# 194 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 195 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DynamicPunchDeclined
# 196 "data/scripts/move_tutors.pory"
	setflag FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH
# 197 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_DynamicPunchTaught
# 198 "data/scripts/move_tutors.pory"
	end
# 199 "data/scripts/move_tutors.pory"

# 200 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_DynamicPunchDeclined::
# 201 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DynamicPunchDeclined, MSGBOX_DEFAULT
# 202 "data/scripts/move_tutors.pory"
	release
# 203 "data/scripts/move_tutors.pory"
	end
# 204 "data/scripts/move_tutors.pory"

# 205 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_DynamicPunchTaught::
# 206 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DynamicPunchTaught, MSGBOX_DEFAULT
# 207 "data/scripts/move_tutors.pory"
	release
# 208 "data/scripts/move_tutors.pory"
	end
# 209 "data/scripts/move_tutors.pory"

# 210 "data/scripts/move_tutors.pory"
SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor::
# 211 "data/scripts/move_tutors.pory"
	lock
# 212 "data/scripts/move_tutors.pory"
	faceplayer
# 213 "data/scripts/move_tutors.pory"
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_DOUBLE_EDGE, MoveTutor_EventScript_DoubleEdgeTaught
# 214 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DoubleEdgeTeach, MSGBOX_YESNO
# 215 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DoubleEdgeDeclined
# 216 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 217 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DoubleEdgeDeclined
# 218 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DoubleEdgeWhichMon, MSGBOX_DEFAULT
# 219 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_DOUBLE_EDGE
# 220 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 221 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DoubleEdgeDeclined
# 222 "data/scripts/move_tutors.pory"
	setflag FLAG_MOVE_TUTOR_TAUGHT_DOUBLE_EDGE
# 223 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_DoubleEdgeTaught
# 224 "data/scripts/move_tutors.pory"
	end
# 225 "data/scripts/move_tutors.pory"

# 226 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_DoubleEdgeDeclined::
# 227 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DoubleEdgeDeclined, MSGBOX_DEFAULT
# 228 "data/scripts/move_tutors.pory"
	release
# 229 "data/scripts/move_tutors.pory"
	end
# 230 "data/scripts/move_tutors.pory"

# 231 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_DoubleEdgeTaught::
# 232 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DoubleEdgeTaught, MSGBOX_DEFAULT
# 233 "data/scripts/move_tutors.pory"
	release
# 234 "data/scripts/move_tutors.pory"
	end
# 235 "data/scripts/move_tutors.pory"

# 236 "data/scripts/move_tutors.pory"
PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor::
# 237 "data/scripts/move_tutors.pory"
	lock
# 238 "data/scripts/move_tutors.pory"
	faceplayer
# 239 "data/scripts/move_tutors.pory"
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_EXPLOSION, MoveTutor_EventScript_ExplosionTaught
# 240 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_ExplosionTeach, MSGBOX_YESNO
# 241 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_ExplosionDeclined
# 242 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 243 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_ExplosionDeclined
# 244 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_ExplosionWhichMon, MSGBOX_DEFAULT
# 245 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_EXPLOSION
# 246 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 247 "data/scripts/move_tutors.pory"
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExplosionDeclined
# 248 "data/scripts/move_tutors.pory"
	setflag FLAG_MOVE_TUTOR_TAUGHT_EXPLOSION
# 249 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_ExplosionTaught
# 250 "data/scripts/move_tutors.pory"
	end
# 251 "data/scripts/move_tutors.pory"

# 252 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_ExplosionDeclined::
# 253 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_ExplosionDeclined, MSGBOX_DEFAULT
# 254 "data/scripts/move_tutors.pory"
	release
# 255 "data/scripts/move_tutors.pory"
	end
# 256 "data/scripts/move_tutors.pory"

# 257 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_ExplosionTaught::
# 258 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_ExplosionTaught, MSGBOX_DEFAULT
# 259 "data/scripts/move_tutors.pory"
	release
# 260 "data/scripts/move_tutors.pory"
	end
# 261 "data/scripts/move_tutors.pory"

# 262 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_OpenPartyMenu::
# 263 "data/scripts/move_tutors.pory"
	special ChooseMonForMoveTutor
# 264 "data/scripts/move_tutors.pory"
	waitstate
# 265 "data/scripts/move_tutors.pory"
	lock
# 266 "data/scripts/move_tutors.pory"
	faceplayer
# 267 "data/scripts/move_tutors.pory"
	return
# 268 "data/scripts/move_tutors.pory"

# 269 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_CanOnlyBeLearnedOnce::
# 270 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnce, MSGBOX_YESNO
# 271 "data/scripts/move_tutors.pory"
	return

MoveTutor_EventScript_ProtectThiefTutor::
# 276 "data/scripts/move_tutors.pory"
	lockall
# 277 "data/scripts/move_tutors.pory"
	applymovement LOCALID_PROTECT_THIEF_TUTOR, Common_Movement_FacePlayer
# 278 "data/scripts/move_tutors.pory"
	waitmovement 0
# 279 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_TeachSomeMove, MSGBOX_YESNO
# 280 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, YES
	goto_if_eq MoveTutor_EventScript_ProtectThiefTutor_2
# 297 "data/scripts/move_tutors.pory"
	closemessage
MoveTutor_EventScript_ProtectThiefTutor_1:
# 299 "data/scripts/move_tutors.pory"
	releaseall
	return

MoveTutor_EventScript_ProtectThiefTutor_2:
# 281 "data/scripts/move_tutors.pory"
	closemessage
# 282 "data/scripts/move_tutors.pory"
	message MoveTutor_Text_WhichMove
# 283 "data/scripts/move_tutors.pory"
	waitmessage
# 284 "data/scripts/move_tutors.pory"
	dynmultichoice 16, 6, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, MoveTutor_EventScript_ProtectThiefTutor_Text_0, MoveTutor_EventScript_ProtectThiefTutor_Text_1, Multichoice_Option_NoMove
# 285 "data/scripts/move_tutors.pory"
	switch VAR_RESULT
# 286 "data/scripts/move_tutors.pory"
	case 0, MoveTutor_EventScript_ProtectThiefTutor_6
# 289 "data/scripts/move_tutors.pory"
	case 1, MoveTutor_EventScript_ProtectThiefTutor_7
# 293 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_ComeBackIfYouNeedMe, MSGBOX_DEFAULT
# 294 "data/scripts/move_tutors.pory"
	closemessage
	goto MoveTutor_EventScript_ProtectThiefTutor_1

MoveTutor_EventScript_ProtectThiefTutor_6:
# 287 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_PROTECT
# 288 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_SelectMon
	goto MoveTutor_EventScript_ProtectThiefTutor_1

MoveTutor_EventScript_ProtectThiefTutor_7:
# 290 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_THIEF
# 291 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_SelectMon
	goto MoveTutor_EventScript_ProtectThiefTutor_1


MoveTutor_EventScript_WeatherTutor::
# 303 "data/scripts/move_tutors.pory"
	lockall
# 304 "data/scripts/move_tutors.pory"
	applymovement LOCALID_WEATHER_TUTOR, Common_Movement_FacePlayer
# 305 "data/scripts/move_tutors.pory"
	waitmovement 0
# 306 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_TeachSomeMove, MSGBOX_YESNO
# 307 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, YES
	goto_if_eq MoveTutor_EventScript_WeatherTutor_2
# 330 "data/scripts/move_tutors.pory"
	closemessage
MoveTutor_EventScript_WeatherTutor_1:
# 332 "data/scripts/move_tutors.pory"
	releaseall
	return

MoveTutor_EventScript_WeatherTutor_2:
# 308 "data/scripts/move_tutors.pory"
	closemessage
# 309 "data/scripts/move_tutors.pory"
	message MoveTutor_Text_WhichMove
# 310 "data/scripts/move_tutors.pory"
	waitmessage
# 311 "data/scripts/move_tutors.pory"
	dynmultichoice 16, 2, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, MoveTutor_EventScript_WeatherTutor_Text_0, MoveTutor_EventScript_WeatherTutor_Text_1, MoveTutor_EventScript_WeatherTutor_Text_2, MoveTutor_EventScript_WeatherTutor_Text_3, Multichoice_Option_NoMove
# 312 "data/scripts/move_tutors.pory"
	switch VAR_RESULT
# 313 "data/scripts/move_tutors.pory"
	case 0, MoveTutor_EventScript_WeatherTutor_6
# 316 "data/scripts/move_tutors.pory"
	case 1, MoveTutor_EventScript_WeatherTutor_7
# 319 "data/scripts/move_tutors.pory"
	case 2, MoveTutor_EventScript_WeatherTutor_8
# 322 "data/scripts/move_tutors.pory"
	case 3, MoveTutor_EventScript_WeatherTutor_9
# 326 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_ComeBackIfYouNeedMe, MSGBOX_DEFAULT
# 327 "data/scripts/move_tutors.pory"
	closemessage
	goto MoveTutor_EventScript_WeatherTutor_1

MoveTutor_EventScript_WeatherTutor_6:
# 314 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_HAIL
# 315 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_SelectMon
	goto MoveTutor_EventScript_WeatherTutor_1

MoveTutor_EventScript_WeatherTutor_7:
# 317 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_SUNNY_DAY
# 318 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_SelectMon
	goto MoveTutor_EventScript_WeatherTutor_1

MoveTutor_EventScript_WeatherTutor_8:
# 320 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_RAIN_DANCE
# 321 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_SelectMon
	goto MoveTutor_EventScript_WeatherTutor_1

MoveTutor_EventScript_WeatherTutor_9:
# 323 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_SANDSTORM
# 324 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_SelectMon
	goto MoveTutor_EventScript_WeatherTutor_1


MoveTutor_EventScript_OverpoweredTutor::
# 336 "data/scripts/move_tutors.pory"
	lockall
# 337 "data/scripts/move_tutors.pory"
	applymovement LOCALID_OVERPOWERED_TUTOR, Common_Movement_FacePlayer
# 338 "data/scripts/move_tutors.pory"
	waitmovement 0
# 339 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_TeachSomeMove, MSGBOX_YESNO
# 340 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, YES
	goto_if_eq MoveTutor_EventScript_OverpoweredTutor_2
# 363 "data/scripts/move_tutors.pory"
	closemessage
MoveTutor_EventScript_OverpoweredTutor_1:
# 365 "data/scripts/move_tutors.pory"
	releaseall
	return

MoveTutor_EventScript_OverpoweredTutor_2:
# 341 "data/scripts/move_tutors.pory"
	closemessage
# 342 "data/scripts/move_tutors.pory"
	message MoveTutor_Text_WhichMove
# 343 "data/scripts/move_tutors.pory"
	waitmessage
# 344 "data/scripts/move_tutors.pory"
	dynmultichoice 16, 2, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, MoveTutor_EventScript_OverpoweredTutor_Text_0, MoveTutor_EventScript_OverpoweredTutor_Text_1, MoveTutor_EventScript_OverpoweredTutor_Text_2, MoveTutor_EventScript_OverpoweredTutor_Text_3, Multichoice_Option_NoMove
# 345 "data/scripts/move_tutors.pory"
	switch VAR_RESULT
# 346 "data/scripts/move_tutors.pory"
	case 0, MoveTutor_EventScript_OverpoweredTutor_6
# 349 "data/scripts/move_tutors.pory"
	case 1, MoveTutor_EventScript_OverpoweredTutor_7
# 352 "data/scripts/move_tutors.pory"
	case 2, MoveTutor_EventScript_OverpoweredTutor_8
# 355 "data/scripts/move_tutors.pory"
	case 3, MoveTutor_EventScript_OverpoweredTutor_9
# 359 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_ComeBackIfYouNeedMe, MSGBOX_DEFAULT
# 360 "data/scripts/move_tutors.pory"
	closemessage
	goto MoveTutor_EventScript_OverpoweredTutor_1

MoveTutor_EventScript_OverpoweredTutor_6:
# 347 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_HYDRO_CANNON
# 348 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_SelectMon
	goto MoveTutor_EventScript_OverpoweredTutor_1

MoveTutor_EventScript_OverpoweredTutor_7:
# 350 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_BLAST_BURN
# 351 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_SelectMon
	goto MoveTutor_EventScript_OverpoweredTutor_1

MoveTutor_EventScript_OverpoweredTutor_8:
# 353 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_FRENZY_PLANT
# 354 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_SelectMon
	goto MoveTutor_EventScript_OverpoweredTutor_1

MoveTutor_EventScript_OverpoweredTutor_9:
# 356 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, MOVE_DRACO_METEOR
# 357 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_SelectMon
	goto MoveTutor_EventScript_OverpoweredTutor_1


MoveTutor_EventScript_SelectMon:
# 369 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_WhichMon, MSGBOX_DEFAULT
# 370 "data/scripts/move_tutors.pory"
	closemessage
# 371 "data/scripts/move_tutors.pory"
	special ChooseMonForMoveTutor
# 372 "data/scripts/move_tutors.pory"
	waitstate
# 373 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_SelectMon_1
# 377 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DoneComeBackIfYouNeedMe, MSGBOX_DEFAULT
# 378 "data/scripts/move_tutors.pory"
	closemessage
	return

MoveTutor_EventScript_SelectMon_1:
# 374 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_ComeBackIfYouNeedMe, MSGBOX_DEFAULT
# 375 "data/scripts/move_tutors.pory"
	closemessage
	return


MoveTutor_EventScript_ProtectThiefTutor_Text_0:
# 284 "data/scripts/move_tutors.pory"
	.string "Protect$"

MoveTutor_EventScript_ProtectThiefTutor_Text_1:
# 284 "data/scripts/move_tutors.pory"
	.string "Thief$"

MoveTutor_EventScript_WeatherTutor_Text_0:
# 311 "data/scripts/move_tutors.pory"
	.string "Hail$"

MoveTutor_EventScript_WeatherTutor_Text_1:
# 311 "data/scripts/move_tutors.pory"
	.string "Sunny Day$"

MoveTutor_EventScript_WeatherTutor_Text_2:
# 311 "data/scripts/move_tutors.pory"
	.string "Rain Dance$"

MoveTutor_EventScript_WeatherTutor_Text_3:
# 311 "data/scripts/move_tutors.pory"
	.string "Sandstorm$"

MoveTutor_EventScript_OverpoweredTutor_Text_0:
# 344 "data/scripts/move_tutors.pory"
	.string "Hydro Cannon$"

MoveTutor_EventScript_OverpoweredTutor_Text_1:
# 344 "data/scripts/move_tutors.pory"
	.string "Blast Burn$"

MoveTutor_EventScript_OverpoweredTutor_Text_2:
# 344 "data/scripts/move_tutors.pory"
	.string "Frenzy Plant$"

MoveTutor_EventScript_OverpoweredTutor_Text_3:
# 344 "data/scripts/move_tutors.pory"
	.string "Draco Meteor$"

MoveTutor_Text_TeachSomeMove::
# 382 "data/scripts/move_tutors.pory"
	.string "Hello, traveler.\n"
	.string "Would you like to teach a move to\l"
	.string "one of your Pokémon?\l"
	.string "I'm not going to charge you for it.$"

MoveTutor_Text_WhichMove::
# 389 "data/scripts/move_tutors.pory"
	.string "Okay, which one?$"

Multichoice_Option_NoMove::
# 393 "data/scripts/move_tutors.pory"
	.string "I've changed my mind.$"

MoveTutor_Text_WhichMon::
# 397 "data/scripts/move_tutors.pory"
	.string "Which Pokémon should learn this move?$"

MoveTutor_Text_ComeBackIfYouNeedMe::
# 401 "data/scripts/move_tutors.pory"
	.string "Nevermind then.\n"
	.string "Come back if you need me.$"

MoveTutor_Text_DoneComeBackIfYouNeedMe::
# 406 "data/scripts/move_tutors.pory"
	.string "Cool, isn't it?\n"
	.string "Come back if you need me again!$"
