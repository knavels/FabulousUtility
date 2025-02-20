using UnrealBuildTool;

public class FabulousAbilitySystem : ModuleRules
{
	public FabulousAbilitySystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;

		bEnableNonInlinedGenCppWarnings = true;

		PrivateDependencyModuleNames.AddRange(new[]
		{
			"Core", "CoreUObject", "Engine", "EnhancedInput", "NetCore", "GameplayTags",
			"GameplayTasks", "GameplayAbilities", "NavigationSystem", "FabulousUtility"
		});
	}
}