// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/FlagActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlagActor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
MYPROJECT_API UClass* Z_Construct_UClass_AFlagActor();
MYPROJECT_API UClass* Z_Construct_UClass_AFlagActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_MyProject();
// End Cross Module References

// Begin Class AFlagActor
void AFlagActor::StaticRegisterNativesAFlagActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFlagActor);
UClass* Z_Construct_UClass_AFlagActor_NoRegister()
{
	return AFlagActor::StaticClass();
}
struct Z_Construct_UClass_AFlagActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "FlagActor.h" },
		{ "ModuleRelativePath", "FlagActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerPlayer_MetaData[] = {
		{ "Category", "Flag" },
		{ "ModuleRelativePath", "FlagActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_OwnerPlayer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFlagActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFlagActor_Statics::NewProp_OwnerPlayer = { "OwnerPlayer", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFlagActor, OwnerPlayer), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerPlayer_MetaData), NewProp_OwnerPlayer_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFlagActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFlagActor_Statics::NewProp_OwnerPlayer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFlagActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AFlagActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFlagActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFlagActor_Statics::ClassParams = {
	&AFlagActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AFlagActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AFlagActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFlagActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AFlagActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFlagActor()
{
	if (!Z_Registration_Info_UClass_AFlagActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFlagActor.OuterSingleton, Z_Construct_UClass_AFlagActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFlagActor.OuterSingleton;
}
template<> MYPROJECT_API UClass* StaticClass<AFlagActor>()
{
	return AFlagActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFlagActor);
AFlagActor::~AFlagActor() {}
// End Class AFlagActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_FlagActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFlagActor, AFlagActor::StaticClass, TEXT("AFlagActor"), &Z_Registration_Info_UClass_AFlagActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFlagActor), 1626720513U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_FlagActor_h_4292096555(TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_FlagActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_FlagActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
