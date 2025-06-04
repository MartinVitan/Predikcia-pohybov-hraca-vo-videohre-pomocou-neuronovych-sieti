// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/AProjectileClass.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAProjectileClass() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
MYPROJECT_API UClass* Z_Construct_UClass_AAProjectileClass();
MYPROJECT_API UClass* Z_Construct_UClass_AAProjectileClass_NoRegister();
UPackage* Z_Construct_UPackage__Script_MyProject();
// End Cross Module References

// Begin Class AAProjectileClass
void AAProjectileClass::StaticRegisterNativesAAProjectileClass()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAProjectileClass);
UClass* Z_Construct_UClass_AAProjectileClass_NoRegister()
{
	return AAProjectileClass::StaticClass();
}
struct Z_Construct_UClass_AAProjectileClass_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AProjectileClass.h" },
		{ "ModuleRelativePath", "AProjectileClass.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAProjectileClass>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AAProjectileClass_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAProjectileClass_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAProjectileClass_Statics::ClassParams = {
	&AAProjectileClass::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAProjectileClass_Statics::Class_MetaDataParams), Z_Construct_UClass_AAProjectileClass_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AAProjectileClass()
{
	if (!Z_Registration_Info_UClass_AAProjectileClass.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAProjectileClass.OuterSingleton, Z_Construct_UClass_AAProjectileClass_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAProjectileClass.OuterSingleton;
}
template<> MYPROJECT_API UClass* StaticClass<AAProjectileClass>()
{
	return AAProjectileClass::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AAProjectileClass);
AAProjectileClass::~AAProjectileClass() {}
// End Class AAProjectileClass

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_AProjectileClass_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAProjectileClass, AAProjectileClass::StaticClass, TEXT("AAProjectileClass"), &Z_Registration_Info_UClass_AAProjectileClass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAProjectileClass), 376628266U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_AProjectileClass_h_1096283819(TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_AProjectileClass_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_AProjectileClass_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
