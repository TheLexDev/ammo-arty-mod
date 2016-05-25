
class CfgPatches {
    class lex_arty_ammo {
        units[] = {"lex_82mm_ammobox"};
		magazines[] = {"lex_82mm_HE_round"};
        requiredVersion = 0.1;
        requiredAddons[] = {"A3_Static_F_Mortar_01", "ace_interaction", "ace_mk6mortar", "rhs_c_heavyweapons", "rhsusf_c_statics"};
        author[] = {"Lex"};
    };
};

class CfgFunctions
{
	class arty_ammo
	{
		class myCategory
		{
			class addToCargo
			{
				file = "\arty_ammo\functions\fnc_addToCargo.sqf";
			};
			
			class remoteLoad
			{
				file = "\arty_ammo\functions\fnc_remoteLoad.sqf";
			};
			class remoteLoadID
			{
				file = "\arty_ammo\functions\fnc_remoteLoadID.sqf";
			};
		};
	};
};

class CfgWeapons
{
	class mortar_82mm;
	class lex_mortar_82mm: mortar_82mm
	{
		magazineReloadTime = 0;
	};
	
	class rhs_weap_2b14;
	class lex_rhs_weap_2b14: rhs_weap_2b14
	{
		magazineReloadTime = 0;
	};
};

class CfgVehicles
{
	class NATO_Box_Base;
	class lex_82mm_ammobox: NATO_Box_Base
	{
		scope = 2;
        scopeCurator = 2;
        accuracy = 1000;
        displayName = "Ящик с 82-мм ОФ минами";
        model = "arty_ammo\data\82mm_ammobox.p3d";
        author = "Lex";
		ace_cargo_size = 0.5;
		ace_cargo_canLoad = 1;
		
		class eventHandlers
		{
			init = "_this call compile preProcessFileLineNumbers ""arty_ammo\functions\fnc_init.sqf"";";
		};
		class AnimationSources
		{
			class BoxLidRotation
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1.5;
			};
			
			class round_1_hide
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			
			class round_2_hide
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			
			class round_3_hide
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			
			class round_4_hide
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			
			class round_5_hide
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
		};
		
		class ACE_Actions
		{
			class ACE_MainActions
			{
				selection = "";
				distance = 3;
				condition = "!(_target getVariable ['isOpened', false])";
				
				class ACE_OpenLid
					{
						displayName = "Открыть ящик";
						distance = 2;
						condition = "!(_target getVariable ['isOpened', false])";
						statement = "_target animate [""BoxLidRotation"", 1]; _target setVariable [""isOpened"", true, true];";
						showDisabled = 0;
						exceptions[] = {};
						priority = 5;
					};
			};
			
			class ACE_CloseLid
			{
				selection = "rotation_action_point";
				distance = 2;
				displayName = "Закрыть ящик";
				condition = "_target getVariable ['isOpened', true]";
				statement = "_target animate [""BoxLidRotation"", 0]; _target setVariable [""isOpened"", false, true];";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
				
			};
			
			class ACE_Round_1_Take
			{
				displayName = "Взять";
				selection = "round_1_action_point";
				distance = 2;
				condition = "(_target getVariable ['round_1', true]) && (_target getVariable ['isOpened', true])";
				statement = "_target animate ['round_1_hide', 1]; _target setVariable ['round_1', false, true]; [_player] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_take_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_1_Put
			{
				displayName = "Положить";
				selection = "round_1_action_point";
				distance = 2;
				condition = "(!(_target getVariable ['round_1', true]) && (_target getVariable ['isOpened', true]))";
				statement = "[_player, _target, 1] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_put_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_2_Take
			{
				displayName = "Взять";
				selection = "round_2_action_point";
				distance = 2;
				condition = "(_target getVariable ['round_2', true]) && (_target getVariable ['isOpened', true])";
				statement = "_target animate ['round_2_hide', 1]; _target setVariable ['round_2', false, true]; [_player] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_take_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_2_Put
			{
				displayName = "Положить";
				selection = "round_2_action_point";
				distance = 2;
				condition = "(!(_target getVariable ['round_2', true]) && (_target getVariable ['isOpened', true]))";
				statement = "[_player, _target, 2] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_put_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_3_Take
			{
				displayName = "Взять";
				selection = "round_3_action_point";
				distance = 2;
				condition = "(_target getVariable ['round_3', true]) && (_target getVariable ['isOpened', true])";
				statement = "_target animate ['round_3_hide', 1]; _target setVariable ['round_3', false, true]; [_player] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_take_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_3_Put
			{
				displayName = "Положить";
				selection = "round_3_action_point";
				distance = 2;
				condition = "(!(_target getVariable ['round_3', true]) && (_target getVariable ['isOpened', true]))";
				statement = "[_player, _target, 3] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_put_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_4_Take
			{
				displayName = "Взять";
				selection = "round_4_action_point";
				distance = 2;
				condition = "(_target getVariable ['round_4', true]) && (_target getVariable ['isOpened', true])";
				statement = "_target animate ['round_4_hide', 1]; _target setVariable ['round_4', false, true]; [_player] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_take_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_4_Put
			{
				displayName = "Положить";
				selection = "round_4_action_point";
				distance = 2;
				condition = "(!(_target getVariable ['round_4', true]) && (_target getVariable ['isOpened', true]))";
				statement = "[_player, _target, 4] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_put_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_5_Take
			{
				displayName = "Взять";
				selection = "round_5_action_point";
				distance = 2;
				condition = "(_target getVariable ['round_5', true]) && (_target getVariable ['isOpened', true])";
				statement = "_target animate ['round_5_hide', 1]; _target setVariable ['round_5', false, true]; [_player] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_take_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_5_Put
			{
				displayName = "Положить";
				selection = "round_5_action_point";
				distance = 2;
				condition = "(!(_target getVariable ['round_5', true]) && (_target getVariable ['isOpened', true]))";
				statement = "[_player, _target, 5] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_put_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
		};
	};
	
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
	};
	class StaticMortar: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret {};
		};
		class ACE_Actions;
	};
	
	class Mortar_01_base_F: StaticMortar
	{
		lex_avail_mags_HE = "8Rnd_82mm_Mo_shells";
		
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"lex_mortar_82mm"};
				magazines[] = {};
			};
		};
		
		class ACE_Actions: ACE_Actions
		{
			class ACE_LoadRound
			{
				displayName = "Зарядить";
				selection = "usti hlavne";
				distance = 2.5;
				statement = " 0 = [_target, _player] execVM 'arty_ammo\functions\fnc_load.sqf';";
				condition = "alive _target";
				showDisabled = 1;
				exceptions[] = {};
				priority = 5;
				icon = "arty_ammo\ui\icon_load_interact.paa";
			};
		};
	};
	
	class rhs_2b14_82mm_Base: StaticMortar
	{
		lex_avail_mags_HE = "rhs_mag_3vo18_10";
		
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"lex_rhs_weap_2b14"};
				magazines[] = {};
			};
		};
		
		class ACE_Actions: ACE_Actions
		{
			class ACE_LoadRound
			{
				displayName = "Зарядить";
				selection = "usti hlavne";
				distance = 2.5;
				statement = " 0 = [_target, _player] execVM 'arty_ammo\functions\fnc_load.sqf';";
				condition = "alive _target";
				showDisabled = 1;
				exceptions[] = {};
				priority = 5;
				icon = "arty_ammo\ui\icon_load_interact.paa";
			};
		};
	};
	
	class RHS_M252_Base: StaticMortar
	{
		lex_avail_mags_HE = "8Rnd_82mm_Mo_shells";
		
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"lex_mortar_82mm"};
				magazines[] = {};
			};
		};
		
		class ACE_Actions: ACE_Actions
		{
			class ACE_LoadRound
			{
				displayName = "Зарядить";
				selection = "usti hlavne";
				distance = 2.5;
				statement = " 0 = [_target, _player] execVM 'arty_ammo\functions\fnc_load.sqf';";
				condition = "alive _target";
				showDisabled = 1;
				exceptions[] = {};
				priority = 5;
				icon = "arty_ammo\ui\icon_load_interact.paa";
			};
		};
	};
};

class CfgMagazines
{
	class 8Rnd_82mm_Mo_shells;
    class lex_82mm_HE_round: 8Rnd_82mm_Mo_shells
	{
        count = 1;
        scope = 2;
        scopeCurator = 2;
        author = "Lex";
        displayName = "82мм ОФ минометная мина";
        displayNameShort = "82mm HE round";
        descriptionShort = "82mm HE round";
        model = "\arty_ammo\data\82mm_shell";
        picture = "\arty_ammo\ui\ui_he_round";
        mass = 50;
    };
};