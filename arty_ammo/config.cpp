
class CfgPatches {
    class lex_arty_ammo {
        units[] = {"lex_82mm_ammobox",
				   "lex_2b11_120mm_msv_forest",
				   "lex_2b11_120mm_msv_desert",
				   "lex_120mm_ammobox"};
		magazines[] = {"lex_82mm_HE_round",
					   "lex_120mm_HE_round"};
        requiredVersion = 0.1;
        requiredAddons[] = {"A3_Static_F_Mortar_01", "ace_interaction", "ace_mk6mortar", "rhs_c_heavyweapons", "rhsusf_c_statics"};
        author = "[SW]Lex";
		authorUrl = "https://github.com/TheLexDev/";
    };
};

#include "particles.hpp"
#include "cfgWeapons.hpp"

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

class CfgVehicles
{
	class NATO_Box_Base;
	
/*	class lex_122mm_mortar: NATO_Box_Base
	{
		scope = 2;
		scopeCurator = 2;
		accuracy = 1000;
		displayName = "2B11 122-мм миномет";
		model = "arty_ammo\data\2b11_model.p3d";
		author = "Lex, Lichrus";
		class textureSources
		{
			class Default
			{
				displayName = "Лесной (РФ)";
				author = "Lichrus";
				textures[] =
				{
					"arty_ammo\data\2c12_co.paa";
				};
			};
			
			class Desert
			{
				displayName = "Пустынный";
				author = "Lichrus";
				textures[] =
				{
					"arty_ammo\data\des_2c12_co.paa";
				};
			};
			
			class CDF
			{
				displayName = "CDF";
				author = "Lichrus";
				textures[] =
				{
					"arty_ammo\data\2c12_cdf_co.paa";
				};
			};
		};
	};
	*/
	class lex_82mm_ammobox: NATO_Box_Base
	{
		scope = 2;
        scopeCurator = 2;
        accuracy = 1000;
        displayName = "$STR_lex_arty_ammo_82mm_ammobox";
        model = "arty_ammo\data\82mm_ammobox.p3d";
        author = "Lex";
		ace_cargo_size = 0.5;
		ace_cargo_canLoad = 1;
		editorPreview="\arty_ammo\data\120mm\UI\lex_82mm_ammobox.jpg";
		icon="\arty_ammo\data\120mm\UI\icon_box_ca.paa";
		
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
						displayName = "$STR_lex_arty_Open_box";
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
				displayName = "$STR_lex_arty_Close_box";
				condition = "_target getVariable ['isOpened', true]";
				statement = "_target animate [""BoxLidRotation"", 0]; _target setVariable [""isOpened"", false, true];";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
				
			};
			
			class ACE_Round_1_Take
			{
				displayName = "$STR_lex_arty_Take";
				selection = "round_1_action_point";
				distance = 2;
				condition = "(_target getVariable ['round_1', true]) && (_target getVariable ['isOpened', true])";
				statement = "_target animate ['round_1_hide', 1]; _target setVariable ['round_1', false, true]; [_player, 'lex_82mm_HE_round'] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_take_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_1_Put
			{
				displayName = "$STR_lex_arty_Put";
				selection = "round_1_action_point";
				distance = 2;
				condition = "(!(_target getVariable ['round_1', true]) && (_target getVariable ['isOpened', true]))";
				statement = "[_player, _target, 1, 'lex_82mm_HE_round'] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_put_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_2_Take
			{
				displayName = "$STR_lex_arty_Take";
				selection = "round_2_action_point";
				distance = 2;
				condition = "(_target getVariable ['round_2', true]) && (_target getVariable ['isOpened', true])";
				statement = "_target animate ['round_2_hide', 1]; _target setVariable ['round_2', false, true]; [_player, 'lex_82mm_HE_round'] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_take_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_2_Put
			{
				displayName = "$STR_lex_arty_Put";
				selection = "round_2_action_point";
				distance = 2;
				condition = "(!(_target getVariable ['round_2', true]) && (_target getVariable ['isOpened', true]))";
				statement = "[_player, _target, 2, 'lex_82mm_HE_round'] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_put_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_3_Take
			{
				displayName = "$STR_lex_arty_Take";
				selection = "round_3_action_point";
				distance = 2;
				condition = "(_target getVariable ['round_3', true]) && (_target getVariable ['isOpened', true])";
				statement = "_target animate ['round_3_hide', 1]; _target setVariable ['round_3', false, true]; [_player, 'lex_82mm_HE_round'] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_take_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_3_Put
			{
				displayName = "$STR_lex_arty_Put";
				selection = "round_3_action_point";
				distance = 2;
				condition = "(!(_target getVariable ['round_3', true]) && (_target getVariable ['isOpened', true]))";
				statement = "[_player, _target, 3, 'lex_82mm_HE_round'] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_put_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_4_Take
			{
				displayName = "$STR_lex_arty_Take";
				selection = "round_4_action_point";
				distance = 2;
				condition = "(_target getVariable ['round_4', true]) && (_target getVariable ['isOpened', true])";
				statement = "_target animate ['round_4_hide', 1]; _target setVariable ['round_4', false, true]; [_player, 'lex_82mm_HE_round'] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_take_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_4_Put
			{
				displayName = "$STR_lex_arty_Put";
				selection = "round_4_action_point";
				distance = 2;
				condition = "(!(_target getVariable ['round_4', true]) && (_target getVariable ['isOpened', true]))";
				statement = "[_player, _target, 4, 'lex_82mm_HE_round'] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_put_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_5_Take
			{
				displayName = "$STR_lex_arty_Take";
				selection = "round_5_action_point";
				distance = 2;
				condition = "(_target getVariable ['round_5', true]) && (_target getVariable ['isOpened', true])";
				statement = "_target animate ['round_5_hide', 1]; _target setVariable ['round_5', false, true]; [_player, 'lex_82mm_HE_round'] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_take_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_5_Put
			{
				displayName = "$STR_lex_arty_Put";
				selection = "round_5_action_point";
				distance = 2;
				condition = "(!(_target getVariable ['round_5', true]) && (_target getVariable ['isOpened', true]))";
				statement = "[_player, _target, 5, 'lex_82mm_HE_round'] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_put_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
		};
	};
	
	class lex_120mm_ammobox: NATO_Box_Base
	{
		scope = 2;
        scopeCurator = 2;
        accuracy = 1000;
        displayName = "$STR_lex_arty_ammo_120mm_ammobox";
        model = "arty_ammo\data\120mm\120mm_ammobox.p3d";
        author = "Lex";
		ace_cargo_size = 0.5;
		ace_cargo_canLoad = 1;
		editorPreview="\arty_ammo\data\120mm\UI\lex_120mm_ammobox.jpg";
		icon="\arty_ammo\data\120mm\UI\icon_box_ca.paa";
		
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
			class desk_front_hide
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			class desk_back_hide
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
						displayName = "$STR_lex_arty_Open_box";
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
				selection = "boxlid_action_point";
				distance = 2;
				displayName = "$STR_lex_arty_Close_box";
				condition = "_target getVariable ['isOpened', true]";
				statement = "_target animate [""BoxLidRotation"", 0]; _target setVariable [""isOpened"", false, true];";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
				
			};
			
			class ACE_Round_1_Take
			{
				displayName = "$STR_lex_arty_Take";
				selection = "round_1_action_point";
				distance = 2;
				condition = "(_target getVariable ['round_1', true]) && (_target getVariable ['isOpened', true])";
				statement = "_target animate ['round_1_hide', 1]; _target setVariable ['round_1', false, true]; [_player, 'lex_120mm_HE_round'] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_take_shell.sqf'; _target animate ['desk_front_hide', 1]; _target animate ['desk_back_hide', 1];";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_1_Put
			{
				displayName = "$STR_lex_arty_Put";
				selection = "round_1_action_point";
				distance = 2;
				condition = "(!(_target getVariable ['round_1', true]) && (_target getVariable ['isOpened', true]))";
				statement = "[_player, _target, 1, 'lex_120mm_HE_round'] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_put_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_2_Take
			{
				displayName = "$STR_lex_arty_Take";
				selection = "round_2_action_point";
				distance = 2;
				condition = "(_target getVariable ['round_2', true]) && (_target getVariable ['isOpened', true])";
				statement = "_target animate ['round_2_hide', 1]; _target setVariable ['round_2', false, true]; [_player, 'lex_120mm_HE_round'] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_take_shell.sqf'; _target animate ['desk_front_hide', 1]; _target animate ['desk_back_hide', 1];";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
			
			class ACE_Round_2_Put
			{
				displayName = "$STR_lex_arty_Put";
				selection = "round_2_action_point";
				distance = 2;
				condition = "(!(_target getVariable ['round_2', true]) && (_target getVariable ['isOpened', true]))";
				statement = "[_player, _target, 2, 'lex_120mm_HE_round'] call compile preprocessFileLineNumbers 'arty_ammo\functions\fnc_put_shell.sqf';";
				showDisabled = 0;
				exceptions[] = {};
				priority = 5;
			};
		};
	};
	
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		class Turrets;
		class MainTurret;
	};
	class StaticMortar: StaticWeapon
	{
		/*
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
			};
		};
		*/
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
				displayName = "$STR_lex_arty_Load";
				selection = "usti hlavne";
				distance = 2.5;
				statement = " 0 = [_target, _player, 'lex_82mm_HE_round'] execVM 'arty_ammo\functions\fnc_load.sqf';";
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
				displayName = "$STR_lex_arty_Load";
				selection = "usti hlavne";
				distance = 2.5;
				statement = " 0 = [_target, _player, 'lex_82mm_HE_round'] execVM 'arty_ammo\functions\fnc_load.sqf';";
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
				displayName = "$STR_lex_arty_Load";
				selection = "usti hlavne";
				distance = 2.5;
				statement = " 0 = [_target, _player, 'lex_82mm_HE_round'] execVM 'arty_ammo\functions\fnc_load.sqf';";
				condition = "alive _target";
				showDisabled = 1;
				exceptions[] = {};
				priority = 5;
				icon = "arty_ammo\ui\icon_load_interact.paa";
			};
		};
	};

	class lex_2b11_120mm_Base: StaticMortar
	{
		dlc = "RHS_AFRF";
		availableForSupportTypes[]={"Artillery"};
		displayname= "2B11 120mm Mortar";
		lex_avail_mags_HE = "lex_10Rnd_120mm_HE_shells";
		vehicleClass = "rhs_vehclass_artillery";
		editorSubcategory = "rhs_EdSubcat_artillery";
		
		class Library
		{
			libTextDesc="$STR_rhs_LIB_2B14";
		};
		
		model="\arty_ammo\data\2b11_model";
		icon="rhsafrf\addons\rhs_heavyweapons\data\mapico\icomap_podnos_2b14_CA.paa";
		picture="\rhsafrf\addons\rhs_heavyweapons\data\ico\podnos_2b14_ca.paa";
		
		UiPicture="\rhsafrf\addons\rhs_heavyweapons\data\ico\podnos_2b14_ca.paa";
		
		transportSoldier=1;
		cargoAction[]=
		{
			"rhs_D30_Cargo"
		};
		mapSize=1.5;
		
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
				//animationSourceElevation = "mainGun";
				gunnerAction="rhs_D30_Cargo";
				turretInfoType="rhs_gui_optic_mortar";
				gunnerOpticsModel = "\rhsafrf\addons\rhs_heavyweapons\data\2Dscope_D30";
				gunEnd = "gun_chamber";
				gunBeg = "gun_muzzle";
				//selectionFireAnim = "gun_muzzle";
				
				//discreteDistance[]={};
				//discreteDistanceInitIndex=0;

				weapons[]=
				{
					"lex_weap_2b11"
				};
				/*
				magazines[]=
				{
					"lex_10Rnd_120mm_HE_shells", //120-мм осколочная мина
					"lex_10Rnd_120mm_HE_shells", //120-мм осколочная мина
					"lex_10Rnd_120mm_HE_shells", //120-мм осколочная мина
					"lex_10Rnd_120mm_HE_shells" //120-мм осколочная мина
				};
				*/
				magazines[] = {};
				cameraDir = "usti hlavne";
				memoryPointGunnerOptics = "gunnerview";
				elevationMode = 1;
				initCamElev = 0;
				minCamElev = -15;
				maxCamElev = 35;
				initElev=0;
				initTurn=0;
				minElev=-20;
				maxElev=15;
				minTurn=-180;
				maxTurn=180;
				maxHorizontalRotSpeed = 0.5;
				
				/*class ViewOptics : ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.17399999;
					minFov = 0.0077777999;
					maxFov = 0.14;
				};
				*/
			};
		};
		htMin = 1;
		htMax = 480;
		afMax = 0;
		mfMax = 0;
		mFact = 1;
		tBody = 100;
		artilleryScanner = 1;
		
		class assembleInfo
		{
		    primary = 0;
			base = "";
			assembleTo = "";
			dissasembleTo[] = {"rhs_Podnos_Gun_Bag", "rhs_Podnos_Bipod_Bag"};
			displayName = "";
		};
		
		hiddenSelections[] = {"Camo"};
		
		class textureSources
		{
			class msv_default
			{
				displayName = "MSV (Default)";
				author = "Lichrus";
				textures[] =
				{
					"arty_ammo\data\2c12_co.paa"
				};
			};
			
			class desert
			{
				displayName = "Desert";
				author = "Lichrus";
				textures[] =
				{
					"arty_ammo\data\des_2c12_co.paa"
				};
			};
		};
		
		class ACE_Actions: ACE_Actions
		{
			class ACE_LoadRound
			{
				displayName = "$STR_lex_arty_Load";
				selection = "usti hlavne";
				distance = 2.5;
				statement = " 0 = [_target, _player, 'lex_120mm_HE_round'] execVM 'arty_ammo\functions\fnc_load.sqf';";
				condition = "alive _target";
				showDisabled = 1;
				exceptions[] = {};
				priority = 5;
				icon = "arty_ammo\ui\icon_load_interact.paa";
			};
		};
	};
	
	class lex_2b11_120mm_msv_forest: lex_2b11_120mm_Base
	{
		//EdPrev(rhs_2b14_82mm_msv)
		scope=2;
		side=0;
		displayname = "$STR_lex_arty_2b11_mortar_forest";
		author="Lex, Lichrus";
		faction= "rhs_faction_msv";
		crew= "rhs_msv_rifleman";
		typicalCargo[]= {"rhs_msv_rifleman"};
		editorPreview="\arty_ammo\data\120mm\UI\lex_2b11_120mm_msv_forest.jpg";
		icon="\arty_ammo\data\120mm\UI\icon_120mm_ca.paa";
		picture="\arty_ammo\data\120mm\UI\picture_120mm_ca.paa";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] =
		{
			"arty_ammo\data\2c12_co.paa"
		};
	};
	
	class lex_2b11_120mm_msv_desert: lex_2b11_120mm_Base
	{
		scope=2;
		side=0;
		author="Lex, Lichrus";
		faction= "rhs_faction_msv";
		crew= "rhs_msv_rifleman";
		typicalCargo[]= {"rhs_msv_rifleman"};
		editorPreview="\arty_ammo\data\120mm\UI\lex_2b11_120mm_msv_desert.jpg";
		icon="\arty_ammo\data\120mm\UI\icon_120mm_ca.paa";
		picture="\arty_ammo\data\120mm\UI\picture_120mm_ca.paa";
		displayname = "$STR_lex_arty_2b11_mortar_desert";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] =
		{
			"arty_ammo\data\des_2c12_co.paa"
		};
	};
	//class rhs_2b14_82mm_Base;
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
        displayName = "$STR_lex_arty_82mm_HE_round";
        displayNameShort = "82mm HE round";
        descriptionShort = "82mm HE round";
        model = "\arty_ammo\data\82mm_shell";
        picture = "\arty_ammo\ui\ui_he_round";
        mass = 50;
    };
	
	class lex_120mm_HE_round: lex_82mm_HE_round
	{
		displayName = "$STR_lex_arty_120mm_HE_round";
		displayNameShort = "120mm HE round";
		descriptionShort = "120mm HE round";
		model = "\arty_ammo\data\120mm\120mm_shell";
		picture="\arty_ammo\data\120mm\UI\icon_shell_ca.paa";
	};
	class 32Rnd_155mm_Mo_shells;
	class lex_10Rnd_120mm_HE_shells: 32Rnd_155mm_Mo_shells
	{
		scope = 2;
		displayName = "$STR_lex_arty_120mm_HE_round_ammo";
		displayNameShort = "$STR_lex_arty_120mm_HE_round_ammo";
		ammo = "lex_ammo_53of843b";
		count = 10;
		initSpeed = 265.409; //  m/s
	};
};

class CfgAmmo
{
	class Sh_155mm_AMOS;
	class lex_ammo_53of843b: Sh_155mm_AMOS
	{
		hit = 220;
		indirectHit = 100;
		indirectHitRange = 20;
		whistleDist = 300;
		ace_frag_enabled = 1;
		ace_frag_classes[] = {"ACE_frag_large","ACE_frag_large_HD","ACE_frag_large","ACE_frag_huge","ACE_frag_huge_HD"};
		ace_frag_metal = 15000;
		ace_frag_charge = 3000;
		ace_frag_gurney_c = 2440;
		ace_frag_gurney_k = "1/2";
	};
};