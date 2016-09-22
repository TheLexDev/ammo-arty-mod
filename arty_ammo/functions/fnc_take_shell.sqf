_shellClass = _this select 1;
if (((_this select 0) canAddItemToVest _shellClass) || ((_this select 0) canAddItemToBackpack _shellClass)) then
{
	if ((_this select 0) canAddItemToVest _shellClass) then
	{
		(_this select 0) addItemToVest _shellClass;
	} else
	{
		(_this select 0) addItemToBackpack _shellClass;
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
	_holder addMagazineCargoGlobal [_shellClass, 1];
};