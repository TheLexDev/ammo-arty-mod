if !(isServer) exitWith {};

params ["_veh", "_amount", ["_boxType", "82mm", [""]]];
private "_boxClassName";
switch (_boxType) do
{
	case "82mm" : {_boxClassName = "lex_82mm_ammobox"};
	case "120mm" : {_boxClassName = "lex_120mm_ammobox"};
	default {_boxClassName = "lex_82mm_ammobox"};
};
_spaceLeft = [_veh] call ace_cargo_fnc_getCargoSpaceLeft;
_spaceLeft = _spaceLeft - 1;
if ((_amount * 0.5) >= _spaceLeft) then
{
	_amount = floor (_spaceLeft / 0.5);
};
if (_amount == 0) exitWith {};

[_boxClassName, _veh, _amount] call ace_cargo_fnc_addCargoItem;