_veh = _this select 0;
_pl = _this select 1;
_shellClass = _this select 2;
_mags = getText (configFile >> "CfgVehicles" >> typeOf _veh >> "lex_avail_mags_HE");

if (someAmmo _veh) exitWith {hint localize "STR_LEX_ARTY_LOADED";};
//если в инвентаре у игрока
if (_shellClass in magazines _pl) then
{
	_pl playAction "Gear";
	[1, [_veh, _pl, _mags, _shellClass],
	{
	_params = _this select 0;
	if !(someAmmo (_params select 0)) then
	{
		[_params select 0, _params select 1, _params select 2] remoteExec ["arty_ammo_fnc_remoteLoadID", 2, false];
		//[[_params select 0, _params select 1], "arty_ammo_fnc_remoteLoad", _params select 1, true, true] call BIS_fnc_MP;
		//(_params select 0) removeMagazinesTurret [(_params select 2), [0]];
		//(_params select 0) addMagazineTurret [(_params select 2), [0], 1];
		(_params select 1) removeItem (_params select 3);
	};
	}, {hint localize "STR_LEX_ARTY_CANCELED";}, localize "STR_LEX_ARTY_LOADING", {true},["isNotInside"]] call ace_common_fnc_progressBar;
} else //если рядом на земле
{
	_nearby = nearestObjects [_pl, ['GroundWeaponHolder'], 3];
	_holder = objNull;
	{
		if (_shellClass in (magazineCargo _x)) exitWith {_holder = _x;};
	} forEach _nearby;
	if (!isNull _holder) then
	{
		_pl playAction "Gear";
		[1, [_veh, _pl, _holder, _mags, _pl, _shellClass],
		{
		_params = _this select 0;
		if !(someAmmo (_params select 0)) then
		{
			_hold = _params select 2;
			_old_mags = magazinesAmmoCargo _hold;
			_i = _old_mags find [_params select 5, 1];
			_old_mags set [_i, 'usedRound'];
			_old_mags = _old_mags - ['usedRound'];
			
			if (count (weaponCargo _hold) == 0) then {_hold addWeaponCargoGlobal ['FakeWeapon',1];};
			clearMagazineCargoGlobal (_hold);
			{_hold addMagazineAmmoCargo [_x select 0, 1, _x select 1]} forEach _old_mags;
			if (count (weaponCargo _hold - ['FakeWeapon']) == 0) then {clearWeaponCargoGlobal _hold};
			
			//[[_params select 0, _params select 3], "arty_ammo_fnc_remoteLoad", _params select 1, true, true] call BIS_fnc_MP;
			[_params select 0, _params select 1, _params select 3] remoteExec ["arty_ammo_fnc_remoteLoadID", 2, false];
			//(_params select 0) removeMagazinesTurret [(_params select 3), [0]];
			//(_params select 0) addMagazineTurret [(_params select 3), [0], 1];
		};
		}, {hint localize "STR_LEX_ARTY_CANCELED";}, localize "STR_LEX_ARTY_LOADING", {true},["isNotInside"]] call ace_common_fnc_progressBar;
	} else {hint localize "STR_LEX_ARTY_MISSED_AMMO";};
};