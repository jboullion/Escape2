// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Components/AudioComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw += CurrentYaw;

	FindAudioComponent();
	GetPressurePlate();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (TotalMassOfActors() > TriggerMass) {
		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld()->GetTimeSeconds();
	}
	else 
	{
		// Close door if player is outside the rigger for DoorClosedDelay seconds
		if ( DoorClosedDelay < GetWorld()->GetTimeSeconds() - DoorLastOpened) {
			CloseDoor(DeltaTime);
		}
	}
}


float UOpenDoor::TotalMassOfActors() const {
	float TotalMass = 0.f;

	if (!PressurePlate) return TotalMass;

	TArray<AActor*> OverlappingActors;

	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	if (OverlappingActors.Num() == 0) return TotalMass;

	for (AActor* Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	return TotalMass;
}

void UOpenDoor::GetPressurePlate() const {

	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("%s OpenDoor Actor has no PressurePlate Set!"), *GetOwner()->GetName());
	}
}

void UOpenDoor::FindAudioComponent() {

	AudioComponent = GetOwner()->FindComponentByClass<UAudioComponent>();
	if (! AudioComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("AudioComponent MISSING: %s"),
			*GetOwner()->GetName()
		);

	}
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());

	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, DeltaTime * 1.f);

	//if (CurrentYaw < TargetYaw - 0.1f) {
		FRotator DoorRotation = GetOwner()->GetActorRotation();
		DoorRotation.Yaw = CurrentYaw;
		GetOwner()->SetActorRotation(DoorRotation);
	//}

	if (AudioComponent && ! DoorOpen) {
		AudioComponent->Play();
		DoorOpen = true;
	}
	

	/*
		float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
		FRotator NewRotation(0.f, 0.f, 0.f);

		// CurrentRotation.Yaw += TargetYaw;

		//FRotator CurrentRotation(0.f, TargetYaw, 0.f);
		if (CurrentYaw < TargetYaw) {
			NewRotation.Yaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 2);

			GetOwner()->SetActorRotation(NewRotation);
		}
	*/
}



void UOpenDoor::CloseDoor(float DeltaTime)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());

	CurrentYaw = FMath::Lerp(CurrentYaw, InitialYaw, DeltaTime * 1.5f);

	if (AudioComponent && DoorOpen) {
		AudioComponent->Play();
		DoorOpen = false;
	}
	

	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}