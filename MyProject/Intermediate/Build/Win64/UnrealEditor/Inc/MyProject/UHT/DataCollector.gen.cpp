// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/DataCollector.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDataCollector() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
MYPROJECT_API UClass* Z_Construct_UClass_ADataCollector();
MYPROJECT_API UClass* Z_Construct_UClass_ADataCollector_NoRegister();
UPackage* Z_Construct_UPackage__Script_MyProject();
// End Cross Module References

// Begin Class ADataCollector Function GetAIInput
struct Z_Construct_UFunction_ADataCollector_GetAIInput_Statics
{
	struct DataCollector_eventGetAIInput_Parms
	{
		bool bUp;
		bool bDown;
		bool bLeft;
		bool bRight;
		bool bDiagLeft;
		bool bDiagRight;
		bool bShoot;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "DataCollector.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bUp_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUp;
	static void NewProp_bDown_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDown;
	static void NewProp_bLeft_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLeft;
	static void NewProp_bRight_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRight;
	static void NewProp_bDiagLeft_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDiagLeft;
	static void NewProp_bDiagRight_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDiagRight;
	static void NewProp_bShoot_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShoot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bUp_SetBit(void* Obj)
{
	((DataCollector_eventGetAIInput_Parms*)Obj)->bUp = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bUp = { "bUp", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DataCollector_eventGetAIInput_Parms), &Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bUp_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bDown_SetBit(void* Obj)
{
	((DataCollector_eventGetAIInput_Parms*)Obj)->bDown = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bDown = { "bDown", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DataCollector_eventGetAIInput_Parms), &Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bDown_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bLeft_SetBit(void* Obj)
{
	((DataCollector_eventGetAIInput_Parms*)Obj)->bLeft = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bLeft = { "bLeft", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DataCollector_eventGetAIInput_Parms), &Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bLeft_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bRight_SetBit(void* Obj)
{
	((DataCollector_eventGetAIInput_Parms*)Obj)->bRight = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bRight = { "bRight", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DataCollector_eventGetAIInput_Parms), &Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bRight_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bDiagLeft_SetBit(void* Obj)
{
	((DataCollector_eventGetAIInput_Parms*)Obj)->bDiagLeft = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bDiagLeft = { "bDiagLeft", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DataCollector_eventGetAIInput_Parms), &Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bDiagLeft_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bDiagRight_SetBit(void* Obj)
{
	((DataCollector_eventGetAIInput_Parms*)Obj)->bDiagRight = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bDiagRight = { "bDiagRight", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DataCollector_eventGetAIInput_Parms), &Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bDiagRight_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bShoot_SetBit(void* Obj)
{
	((DataCollector_eventGetAIInput_Parms*)Obj)->bShoot = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bShoot = { "bShoot", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DataCollector_eventGetAIInput_Parms), &Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bShoot_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bUp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bDown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bLeft,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bRight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bDiagLeft,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bDiagRight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::NewProp_bShoot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADataCollector, nullptr, "GetAIInput", nullptr, nullptr, Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::DataCollector_eventGetAIInput_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::DataCollector_eventGetAIInput_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADataCollector_GetAIInput()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADataCollector_GetAIInput_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADataCollector::execGetAIInput)
{
	P_GET_UBOOL_REF(Z_Param_Out_bUp);
	P_GET_UBOOL_REF(Z_Param_Out_bDown);
	P_GET_UBOOL_REF(Z_Param_Out_bLeft);
	P_GET_UBOOL_REF(Z_Param_Out_bRight);
	P_GET_UBOOL_REF(Z_Param_Out_bDiagLeft);
	P_GET_UBOOL_REF(Z_Param_Out_bDiagRight);
	P_GET_UBOOL_REF(Z_Param_Out_bShoot);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GetAIInput(Z_Param_Out_bUp,Z_Param_Out_bDown,Z_Param_Out_bLeft,Z_Param_Out_bRight,Z_Param_Out_bDiagLeft,Z_Param_Out_bDiagRight,Z_Param_Out_bShoot);
	P_NATIVE_END;
}
// End Class ADataCollector Function GetAIInput

// Begin Class ADataCollector
void ADataCollector::StaticRegisterNativesADataCollector()
{
	UClass* Class = ADataCollector::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetAIInput", &ADataCollector::execGetAIInput },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADataCollector);
UClass* Z_Construct_UClass_ADataCollector_NoRegister()
{
	return ADataCollector::StaticClass();
}
struct Z_Construct_UClass_ADataCollector_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DataCollector.h" },
		{ "ModuleRelativePath", "DataCollector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Root_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "DataCollector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InferenceModelType_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "DataCollector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Player1_MetaData[] = {
		{ "ModuleRelativePath", "DataCollector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Player2_MetaData[] = {
		{ "ModuleRelativePath", "DataCollector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseAIForP2_MetaData[] = {
		{ "Category", "AI Mode" },
		{ "ModuleRelativePath", "DataCollector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Flags_MetaData[] = {
		{ "ModuleRelativePath", "DataCollector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlagStates_MetaData[] = {
		{ "ModuleRelativePath", "DataCollector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastKnownOwners_MetaData[] = {
		{ "ModuleRelativePath", "DataCollector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastKnownFlagStates_MetaData[] = {
		{ "ModuleRelativePath", "DataCollector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveProjectiles_MetaData[] = {
		{ "ModuleRelativePath", "DataCollector.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Root;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InferenceModelType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Player1;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Player2;
	static void NewProp_bUseAIForP2_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseAIForP2;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Flags_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Flags;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FlagStates_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FlagStates;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LastKnownOwners_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_LastKnownOwners;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LastKnownFlagStates_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_LastKnownFlagStates;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveProjectiles_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ActiveProjectiles;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADataCollector_GetAIInput, "GetAIInput" }, // 428369415
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADataCollector>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_Root = { "Root", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADataCollector, Root), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Root_MetaData), NewProp_Root_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_InferenceModelType = { "InferenceModelType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADataCollector, InferenceModelType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InferenceModelType_MetaData), NewProp_InferenceModelType_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_Player1 = { "Player1", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADataCollector, Player1), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Player1_MetaData), NewProp_Player1_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_Player2 = { "Player2", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADataCollector, Player2), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Player2_MetaData), NewProp_Player2_MetaData) };
void Z_Construct_UClass_ADataCollector_Statics::NewProp_bUseAIForP2_SetBit(void* Obj)
{
	((ADataCollector*)Obj)->bUseAIForP2 = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_bUseAIForP2 = { "bUseAIForP2", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ADataCollector), &Z_Construct_UClass_ADataCollector_Statics::NewProp_bUseAIForP2_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseAIForP2_MetaData), NewProp_bUseAIForP2_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_Flags_Inner = { "Flags", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_Flags = { "Flags", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADataCollector, Flags), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Flags_MetaData), NewProp_Flags_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_FlagStates_Inner = { "FlagStates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_FlagStates = { "FlagStates", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADataCollector, FlagStates), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlagStates_MetaData), NewProp_FlagStates_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_LastKnownOwners_Inner = { "LastKnownOwners", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_LastKnownOwners = { "LastKnownOwners", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADataCollector, LastKnownOwners), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastKnownOwners_MetaData), NewProp_LastKnownOwners_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_LastKnownFlagStates_Inner = { "LastKnownFlagStates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_LastKnownFlagStates = { "LastKnownFlagStates", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADataCollector, LastKnownFlagStates), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastKnownFlagStates_MetaData), NewProp_LastKnownFlagStates_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_ActiveProjectiles_Inner = { "ActiveProjectiles", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ADataCollector_Statics::NewProp_ActiveProjectiles = { "ActiveProjectiles", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADataCollector, ActiveProjectiles), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveProjectiles_MetaData), NewProp_ActiveProjectiles_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADataCollector_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_Root,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_InferenceModelType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_Player1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_Player2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_bUseAIForP2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_Flags_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_Flags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_FlagStates_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_FlagStates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_LastKnownOwners_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_LastKnownOwners,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_LastKnownFlagStates_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_LastKnownFlagStates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_ActiveProjectiles_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADataCollector_Statics::NewProp_ActiveProjectiles,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADataCollector_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ADataCollector_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADataCollector_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADataCollector_Statics::ClassParams = {
	&ADataCollector::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ADataCollector_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ADataCollector_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADataCollector_Statics::Class_MetaDataParams), Z_Construct_UClass_ADataCollector_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADataCollector()
{
	if (!Z_Registration_Info_UClass_ADataCollector.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADataCollector.OuterSingleton, Z_Construct_UClass_ADataCollector_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADataCollector.OuterSingleton;
}
template<> MYPROJECT_API UClass* StaticClass<ADataCollector>()
{
	return ADataCollector::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADataCollector);
ADataCollector::~ADataCollector() {}
// End Class ADataCollector

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_DataCollector_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADataCollector, ADataCollector::StaticClass, TEXT("ADataCollector"), &Z_Registration_Info_UClass_ADataCollector, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADataCollector), 1873494516U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_DataCollector_h_64715102(TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_DataCollector_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_DataCollector_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
