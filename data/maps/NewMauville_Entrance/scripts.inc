NewMauville_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Entrance_OnTransition
	.byte 0

NewMauville_Entrance_OnTransition:
	setflag FLAG_LANDMARK_NEW_MAUVILLE
	end

NewMauville_Entrance_EventScript_DontOpenDoor::
	releaseall
	end

NewMauville_Entrance_Text_DoorIsLocked:
	.string "The door is locked.$"

NewMauville_Entrance_Text_UseBasementKey:
	.string "Use the BASEMENT KEY?$"

NewMauville_Entrance_Text_UsedBasementKey:
	.string "{PLAYER} used the BASEMENT KEY.\p"
	.string "The door opened!$"

