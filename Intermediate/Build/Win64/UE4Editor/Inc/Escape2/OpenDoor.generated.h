// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ESCAPE2_OpenDoor_generated_h
#error "OpenDoor.generated.h already included, missing '#pragma once' in OpenDoor.h"
#endif
#define ESCAPE2_OpenDoor_generated_h

#define Escape2_Source_Escape2_OpenDoor_h_17_SPARSE_DATA
#define Escape2_Source_Escape2_OpenDoor_h_17_RPC_WRAPPERS
#define Escape2_Source_Escape2_OpenDoor_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#define Escape2_Source_Escape2_OpenDoor_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOpenDoor(); \
	friend struct Z_Construct_UClass_UOpenDoor_Statics; \
public: \
	DECLARE_CLASS(UOpenDoor, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Escape2"), NO_API) \
	DECLARE_SERIALIZER(UOpenDoor)


#define Escape2_Source_Escape2_OpenDoor_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUOpenDoor(); \
	friend struct Z_Construct_UClass_UOpenDoor_Statics; \
public: \
	DECLARE_CLASS(UOpenDoor, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Escape2"), NO_API) \
	DECLARE_SERIALIZER(UOpenDoor)


#define Escape2_Source_Escape2_OpenDoor_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOpenDoor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOpenDoor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOpenDoor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOpenDoor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOpenDoor(UOpenDoor&&); \
	NO_API UOpenDoor(const UOpenDoor&); \
public:


#define Escape2_Source_Escape2_OpenDoor_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOpenDoor(UOpenDoor&&); \
	NO_API UOpenDoor(const UOpenDoor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOpenDoor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOpenDoor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOpenDoor)


#define Escape2_Source_Escape2_OpenDoor_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TargetYaw() { return STRUCT_OFFSET(UOpenDoor, TargetYaw); } \
	FORCEINLINE static uint32 __PPO__PressurePlate() { return STRUCT_OFFSET(UOpenDoor, PressurePlate); } \
	FORCEINLINE static uint32 __PPO__ActorThatOpens() { return STRUCT_OFFSET(UOpenDoor, ActorThatOpens); } \
	FORCEINLINE static uint32 __PPO__DoorClosedDelay() { return STRUCT_OFFSET(UOpenDoor, DoorClosedDelay); }


#define Escape2_Source_Escape2_OpenDoor_h_14_PROLOG
#define Escape2_Source_Escape2_OpenDoor_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Escape2_Source_Escape2_OpenDoor_h_17_PRIVATE_PROPERTY_OFFSET \
	Escape2_Source_Escape2_OpenDoor_h_17_SPARSE_DATA \
	Escape2_Source_Escape2_OpenDoor_h_17_RPC_WRAPPERS \
	Escape2_Source_Escape2_OpenDoor_h_17_INCLASS \
	Escape2_Source_Escape2_OpenDoor_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Escape2_Source_Escape2_OpenDoor_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Escape2_Source_Escape2_OpenDoor_h_17_PRIVATE_PROPERTY_OFFSET \
	Escape2_Source_Escape2_OpenDoor_h_17_SPARSE_DATA \
	Escape2_Source_Escape2_OpenDoor_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	Escape2_Source_Escape2_OpenDoor_h_17_INCLASS_NO_PURE_DECLS \
	Escape2_Source_Escape2_OpenDoor_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ESCAPE2_API UClass* StaticClass<class UOpenDoor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Escape2_Source_Escape2_OpenDoor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
