// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"


#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	FindPhysicsHandle();
	SetInputComponent();
	
}


void UGrabber::FindPhysicsHandle()
{
	//Check for physics handle component
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (!PhysicsHandle)
	{
		UE_LOG(LogTemp, Error, TEXT("PhysicsHandle component missing: %s"),
			*GetOwner()->GetName()
		);
	}

}


void UGrabber::SetInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		/*UE_LOG(LogTemp, Warning, TEXT("InputComponent component found: %s"),
			*GetOwner()->GetName()
		);*/

		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}

}


void UGrabber::Grab()
{
	FHitResult HitResult = GetFirstPhysicsBodyInReach();
	AActor* ActorHit = HitResult.GetActor();

	// If we grabbed something, attach to physics handle
	if (ActorHit) 
	{
		if (!PhysicsHandle) return;

		UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent();

		PhysicsHandle->GrabComponentAtLocation(
			ComponentToGrab,
			NAME_None,
			GetPlayerReach()
		);
	}
}


void UGrabber::Release()
{
	if (!PhysicsHandle) return;

	PhysicsHandle->ReleaseComponent();
}


FVector UGrabber::GetPlayerReach() const {

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach; // FVector(0.f, Reach, 0.f);

}



FVector UGrabber::GetPlayerPosition() const {

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	return PlayerViewPointLocation;

}



FHitResult UGrabber::GetFirstPhysicsBodyInReach() const
{
	FHitResult Hit;
	FCollisionQueryParams TraceParams(
		FName(TEXT("")),
		false,
		GetOwner()
	);

	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		GetPlayerPosition(),
		GetPlayerReach(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);

	/*AActor* HitActor = Hit.GetActor();

	if (HitActor) {

		FString HitObjectName = HitActor->GetName();

		UE_LOG(LogTemp, Warning, TEXT("HitObjectName: %s"),
			*HitObjectName
		);
	}*/

	return Hit;
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PhysicsHandle) return;

	if (PhysicsHandle->GrabbedComponent) {
		PhysicsHandle->SetTargetLocation(
			GetPlayerReach()
		);
	}

	/*UE_LOG(LogTemp, Warning, TEXT("PlayerViewPointLocation: %s, PlayerViewPointRotation: %s, "), 
		*PlayerViewPointLocation.ToString(), 
		*PlayerViewPointRotation.ToString()
	);*/

	//DrawDebugLine(
	//	GetWorld(),
	//	PlayerViewPointLocation,
	//	LineTraceEnd,
	//	FColor(0, 255, 0),
	//	false,
	//	0.f,
	//	0,
	//	4.f
	//);
	
}