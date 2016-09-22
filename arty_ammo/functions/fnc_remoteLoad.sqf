(_this select 0) removeMagazinesTurret [(_this select 2), [0]];
(_this select 0) addMagazineTurret [(_this select 2), [0], 1];
playSound3D ["A3\Sounds_F\arsenal\weapons_static\Mortar\reload_mortar.wss", _this select 0, false, getPosASL (_this select 0), 1, 1, 20];