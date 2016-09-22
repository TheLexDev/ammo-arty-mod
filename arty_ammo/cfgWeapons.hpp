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
	class CannonCore;
	class mortar_155mm_AMOS: CannonCore
	{
		class Single1;
		class Single2;
		class Single3;
		class Single4;
		class Single5;
		class Burst1;
		class Burst2;
		class Burst3;
		class Burst4;
		class Burst5;
		class GunParticles;
	};
	class lex_weap_2b11: mortar_155mm_AMOS
	{
		displayName = "$STR_lex_arty_2b11_mortar_weap";
		magazineReloadTime = 0;
		
		class Single1: Single1
		{
			displayName = "Charge 0";
			reloadTime = 4;
			artilleryDispersion = 0.5;
			artilleryCharge = 0.4432;  //117.799 m/s
			
			class StandardSound
			{
				begin1[]=
				{
					"arty_ammo\sounds\2b11_shot1",
					5.51189,
					1,
					750
				};
				soundBegin[] = {"begin1",1};
			};
		};
		class Single2: Single2
		{
			displayName = "Charge 1";
			reloadTime = 4;
			artilleryDispersion = 0.5;
			artilleryCharge = 0.583;  //154.761 m/s
			
			class StandardSound
			{
				begin1[]=
				{
					"arty_ammo\sounds\2b11_shot1",
					5.51189,
					1,
					750
				};
				soundBegin[] = {"begin1",1};
			};
		};
		class Single3: Single3
		{
			displayName = "Charge 2";
			reloadTime = 4;
			artilleryDispersion = 0.5;
			artilleryCharge = 0.6672;  //177.08 m/s
			
			class StandardSound
			{
				begin1[]=
				{
					"arty_ammo\sounds\2b11_shot1",
					5.51189,
					1,
					750
				};
				soundBegin[] = {"begin1",1};
			};
		};
		class Single4: Single4
		{
			displayName = "Charge 3";
			reloadTime = 4;
			artilleryDispersion = 0.5;
			artilleryCharge = 0.7656;  //203.21 m/s
			
			class StandardSound
			{
				begin1[]=
				{
					"arty_ammo\sounds\2b11_shot1",
					5.51189,
					1,
					750
				};
				soundBegin[] = {"begin1",1};
			};
		};
		class Single5: Single5
		{
			displayName = "Charge 4";
			reloadTime = 4;
			artilleryDispersion = 0.5;
			artilleryCharge = 0.8377;  //222.287 m/s
			
			class StandardSound
			{
				begin1[]=
				{
					"arty_ammo\sounds\2b11_shot1",
					5.51189,
					1,
					750
				};
				soundBegin[] = {"begin1",1};
			};
		};
		class Single6: Single1
		{
			displayName = "Charge 5";
			reloadTime = 4;
			artilleryDispersion = 0.5;
			artilleryCharge = 0.9014;  //239.232 m/s
			
			class StandardSound
			{
				begin1[]=
				{
					"arty_ammo\sounds\2b11_shot1",
					5.51189,
					1,
					750
				};
				soundBegin[] = {"begin1",1};
			};
		};
		class Single7: Single1
		{
			displayName = "Charge 6";
			reloadTime = 4;
			artilleryDispersion = 0.5;
			artilleryCharge = 1.0001;  //265.409 m/s
			
			class StandardSound
			{
				begin1[]=
				{
					"arty_ammo\sounds\2b11_shot1",
					5.51189,
					1,
					750
				};
				soundBegin[] = {"begin1",1};
			};
		};
		class Burst1: Burst1
		{
			displayName = "Charge 0";
			reloadTime = 4;
			artilleryDispersion = 0.5;
			artilleryCharge = 0.4432;
			
			class StandardSound
			{
				begin1[]=
				{
					"arty_ammo\sounds\2b11_shot1",
					5.51189,
					1,
					750
				};
				soundBegin[] = {"begin1",1};
			};
		};
		class Burst2: Burst2
		{
			displayName = "Charge 1";
			reloadTime = 4;
			artilleryDispersion = 0.5;
			artilleryCharge = 0.583;
			
			class StandardSound
			{
				begin1[]=
				{
					"arty_ammo\sounds\2b11_shot1",
					5.51189,
					1,
					750
				};
				soundBegin[] = {"begin1",1};
			};
		};
		class Burst3: Burst3
		{
			displayName = "Charge 2";
			reloadTime = 4;
			artilleryDispersion = 0.5;
			artilleryCharge = 0.6672;
			
			class StandardSound
			{
				begin1[]=
				{
					"arty_ammo\sounds\2b11_shot1",
					5.51189,
					1,
					750
				};
				soundBegin[] = {"begin1",1};
			};
		};
		class Burst4: Burst4
		{
			displayName = "Charge 3";
			reloadTime = 4;
			artilleryDispersion = 0.5;
			artilleryCharge = 0.7656;
			
			class StandardSound
			{
				begin1[]=
				{
					"arty_ammo\sounds\2b11_shot1",
					5.51189,
					1,
					750
				};
				soundBegin[] = {"begin1",1};
			};
		};
		class Burst5: Burst5
		{
			displayName = "Charge 4";
			reloadTime = 4;
			artilleryDispersion = 0.5;
			artilleryCharge = 0.8377;
			
			class StandardSound
			{
				begin1[]=
				{
					"arty_ammo\sounds\2b11_shot1",
					5.51189,
					1,
					750
				};
				soundBegin[] = {"begin1",1};
			};
		};
		class Burst6: Burst1
		{
			displayName = "Charge 5";
			reloadTime = 4;
			artilleryDispersion = 0.5;
			artilleryCharge = 0.9014;
			
			class StandardSound
			{
				begin1[]=
				{
					"arty_ammo\sounds\2b11_shot1",
					5.51189,
					1,
					750
				};
				soundBegin[] = {"begin1",1};
			};
		};
		class Burst7: Burst1
		{
			displayName = "Charge 6";
			reloadTime = 4;
			artilleryDispersion = 0.5;
			artilleryCharge = 1.0001;
			
			class StandardSound
			{
				begin1[]=
				{
					"arty_ammo\sounds\2b11_shot1",
					5.51189,
					1,
					750
				};
				soundBegin[] = {"begin1",1};
			};
		};
		
		class GunParticles: GunParticles
		{
			class lex_BarrelRefract
			{
				positionName="usti hlavne";
				directionName="usti hlavne up";
				effectName="lex_BarrelRefract";
			};
		};
		
		class StandardSound
		{
			begin1[] = {"arty_ammo\sounds\2b11_shot1",5.51189,1,750};
			soundBegin[] = {"begin1",1};
		};
		
		magazines[] = {"lex_10Rnd_120mm_HE_shells"};
		modes[] = {"Single1","Single2","Single3","Single4","Single5","Single6","Single7","Burst1","Burst2","Burst3","Burst4","Burst5","Burst6","Burst7"};
		reloadSound[] = {"A3\Sounds_F\arsenal\weapons_static\Mortar\reload_mortar",1,1,20};
	};
};