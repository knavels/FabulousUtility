﻿#include "TargetData/FuAbilityTargetData_Float.h"

#include "FuMacros.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FuAbilityTargetData_Float)

UScriptStruct* FFuAbilityTargetData_Float::GetScriptStruct() const
{
	return StaticStruct();
}

FString FFuAbilityTargetData_Float::ToString() const
{
	return FString{FU_GET_TYPE_STRING(FFuAbilityTargetData_Float)};
}

bool FFuAbilityTargetData_Float::NetSerialize(FArchive& Archive, UPackageMap* Map, bool& bSuccess)
{
	Archive << Value;

	bSuccess = true;
	return true;
}

FGameplayAbilityTargetDataHandle UFuFloatTargetDataUtility::MakeFloatTargetData(const FFuAbilityTargetData_Float& TargetData)
{
	FGameplayAbilityTargetDataHandle TargetDataHandle;
	TargetDataHandle.Data.Emplace(MakeShared<FFuAbilityTargetData_Float>(TargetData));

	return TargetDataHandle;
}

FFuAbilityTargetData_Float UFuFloatTargetDataUtility::GetFloatTargetData(const FGameplayAbilityTargetDataHandle& TargetDataHandle,
                                                                         const int32 Index)
{
	if (!TargetDataHandle.Data.IsValidIndex(Index) ||
	    !FU_ENSURE(TargetDataHandle.Data[Index].Get()->GetScriptStruct()->IsChildOf(FFuAbilityTargetData_Float::StaticStruct())))
	{
		return {};
	}

	return *static_cast<FFuAbilityTargetData_Float*>(TargetDataHandle.Data[Index].Get());
}
