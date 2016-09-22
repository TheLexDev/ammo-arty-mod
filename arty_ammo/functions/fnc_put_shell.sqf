_magArray = magazines (_this select 0);
_shellClass = _this select 3;
if (_shellClass in _magArray) then
{
	(_this select 0) removeItem _shellClass;
	_roundAnim = format ["round_%1_hide", _this select 2];
	_roundVar = format ["round_%1", _this select 2];
	(_this select 1) animate [_roundAnim, 0];
	(_this select 1) setVariable [_roundVar, true, true];
} else
{
	_nearby = nearestObjects [_this select 0, ['GroundWeaponHolder'], 3];
	_holder = objNull;
	{
		if (_shellClass in (magazineCargo _x)) exitWith {_holder = _x};
	} forEach _nearby;
	if (!isNull _holder) then
	{
		_old_mags = magazinesAmmoCargo _holder;
		_i = _old_mags find [_shellClass, 1];
		_old_mags set [_i, 'usedRound'];
		_old_mags = _old_mags - ['usedRound'];
		
		if (count (weaponCargo _holder) == 0) then {_holder addWeaponCargoGlobal ['FakeWeapon',1];};
		clearMagazineCargoGlobal (_holder);
		{_holder addMagazineAmmoCargo [_x select 0, 1, _x select 1]} forEach _old_mags;
		if (count (weaponCargo _holder - ['FakeWeapon']) == 0) then {clearWeaponCargoGlobal _holder};
		_roundAnim = format ["round_%1_hide", _this select 2];
		_roundVar = format ["round_%1", _this select 2];
		(_this select 1) animate [_roundAnim, 0];
		(_this select 1) setVariable [_roundVar, true, true];
		if (_shellClass == "lex_120mm_HE_round") then
		{
			if (((_this select 1) getVariable ['round_1', true]) && ((_this select 1) getVariable ['round_2', true])) then
			{
				(_this select 1) animate ["desk_front_hide", 0];
				(_this select 1) animate ["desk_back_hide", 0];
			};
		};
	} else {hint localize "STR_LEX_ARTY_MISSED_AMMO";};
};