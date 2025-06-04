// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DataCollector.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYPROJECT_DataCollector_generated_h
#error "DataCollector.generated.h already included, missing '#pragma once' in DataCollector.h"
#endif
#define MYPROJECT_DataCollector_generated_h

#define FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_DataCollector_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetAIInput);


#define FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_DataCollector_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADataCollector(); \
	friend struct Z_Construct_UClass_ADataCollector_Statics; \
public: \
	DECLARE_CLASS(ADataCollector, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(ADataCollector)


#define FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_DataCollector_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADataCollector(ADataCollector&&); \
	ADataCollector(const ADataCollector&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADataCollector); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADataCollector); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADataCollector) \
	NO_API virtual ~ADataCollector();


#define FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_DataCollector_h_9_PROLOG
#define FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_DataCollector_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_DataCollector_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_DataCollector_h_12_INCLASS_NO_PURE_DECLS \
	FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_DataCollector_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MYPROJECT_API UClass* StaticClass<class ADataCollector>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_marti_OneDrive_Dokumenty_Unreal_Projects_MyProject_Source_MyProject_DataCollector_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
