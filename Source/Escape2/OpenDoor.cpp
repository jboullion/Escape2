// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"


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

	if (! PressurePlate )
	{
		UE_LOG(LogTemp, Error, TEXT("%s OpenDoor Actor has no PressurePlate Set!"), *GetOwner()->GetName() );
	}

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld()->GetTimeSeconds();
	}
	else 
	{
		if ( DoorClosedDelay < GetWorld()->GetTimeSeconds() - DoorLastOpened) {
			CloseDoor(DeltaTime);
		}
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

	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}