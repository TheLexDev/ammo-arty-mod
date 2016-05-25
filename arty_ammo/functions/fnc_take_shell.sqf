if (((_this select 0) canAddItemToVest "lex_82mm_HE_round") || ((_this select 0) canAddItemToBackpack "lex_82mm_HE_round")) then
{
	if ((_this select 0) canAddItemToVest "lex_82mm_HE_round") then
	{
		(_this select 0) addItemToVest "lex_82mm_HE_round";
	} else
	{
		(_this select 0) addItemToBackpack "lex_82mm_HE_round";
	};
} else
{
	_nearby = nearestObjects [_this select 0, ['GroundWeaponHolder'], 3];
	_holder = objNull;
	if (count _nearby > 0) then {_holder = _nearby select 0};
	 if (isNull _holder) then {
		_holder = 'GroundWeaponHolder' createVehicle (getPosATL (_this select 0));
	};
	_holder setPosATL [(getPosATL (_this select 0)) select 0, (getPosATL (_this select 0)) select 1, (getPosATL (_this select 0)) select 2];
	_holder addMagazineCargoGlobal ["lex_82mm_HE_round", 1];
};