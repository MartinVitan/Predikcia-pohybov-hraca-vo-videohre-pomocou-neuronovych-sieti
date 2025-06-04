// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/AProjectileBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAProjectileBase() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
MYPROJECT_API UClass* Z_Construct_UClass_AAProjectileBase();
MYPROJECT_API UClass* Z_Construct_UClass_AAProjectileBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_MyProject();
// End Cross Module References

// Begin Class AAProjectileBase
void AAProjectileBase::StaticRegisterNativesAAProjectileBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAProjectileBase);
UClass* Z_Construct_UClass_AAProjectileBase_NoRegister()
{
	return AAProjectileBase::StaticClass();
}
struct Z_Construct_UClass_AAProjectileBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AProjectileBase.h" },
		{ "ModuleRelativePath", "AProjectileBase.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAProjectileBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AAProjectileBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAProjectileBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAProjectileBase_Statics::ClassParams = {
	&AAProjectileBase::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAProjectileBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AAProjectileBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AAProjectileBase()
{
	if (!Z_Registration_Info_UClass_AAProjectileBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAProjectileBase.OuterSingleton, Z_Construct_UClass_AAProjectileBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAProjectileBase.OuterSingleton;
}
template<> MYPROJECT_API UClass* StaticClass<AAProjectileBase>()
{
	return AAProjectileBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AAProjectileBase);
AAProjectileBase::~AAProjectileBase() {}
// End Class AAProjectileBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_AProjectileBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAProjectileBase, AAProjectileBase::StaticClass, TEXT("AAProjectileBase"), &Z_Registration_Info_UClass_AAProjectileBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAProjectileBase), 1986633328U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_AProjectileBase_h_2897478412(TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_AProjectileBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_AProjectileBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
