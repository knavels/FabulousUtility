#pragma once

#include "Abilities/GameplayAbilityTargetTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FuAbilityTargetData_Vector.generated.h"

USTRUCT(BlueprintType, DisplayName = "Fu Vector Target Data")
struct FABULOUSABILITYSYSTEM_API FFuAbilityTargetData_Vector : public FGameplayAbilityTargetData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fabulous Utility")
	FVector Vector{ForceInit};

public:
	virtual bool HasOrigin() const override;

	virtual FTransform GetOrigin() const override;

	virtual UScriptStruct* GetScriptStruct() const override;

	virtual FString ToString() const override;

	bool NetSerialize(FArchive& Archive, UPackageMap* Map, bool& bSuccess);
};

template <>
struct TStructOpsTypeTraits<FFuAbilityTargetData_Vector> : public TStructOpsTypeTraitsBase2<FFuAbilityTargetData_Vector>
{
	enum
	{
		WithNetSerializer = true
	};
};

UCLASS()
class FABULOUSABILITYSYSTEM_API UFuVectorTargetDataUtility : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Fabulous Utility|Vector Target Data Utility",
		Meta = (AutoCreateRefTerm = "TargetData", ReturnDisplayName = "Target Data Handle"))
	static FGameplayAbilityTargetDataHandle MakeVectorTargetData(const FFuAbilityTargetData_Vector& TargetData);

	UFUNCTION(BlueprintPure, Category = "Fabulous Utility|Vector Target Data Utility",
		Meta = (ReturnDisplayName = "Target Data"))
	static FFuAbilityTargetData_Vector GetVectorTargetData(const FGameplayAbilityTargetDataHandle& TargetDataHandle, int32 Index);
};
