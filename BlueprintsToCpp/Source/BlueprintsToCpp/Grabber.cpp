// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	UE_LOG(LogTemp, Warning, TEXT("grabber constructor"));
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UE_LOG(LogTemp, Warning, TEXT("grabber begin play"));
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	UE_LOG(LogTemp, Warning, TEXT("grabber tick"));
}

//UFUNCTION
FVector UGrabber::GetMaxGrabLocation() const
{
	return GetComponentLocation() +  UKismetMathLibrary::GetForwardVector(GetComponentRotation())* MaxGrabDistance; 

}

FVector UGrabber::GetHoldLocation() const
{
	return GetComponentLocation() + UKismetMathLibrary::GetForwardVector(GetComponentRotation()) * HoldDistance;
}

//BLUEPRINT IMPLEMENTABLE EVENT
UPhysicsHandleComponent* UGrabber::GetPhysicsComponent() const
{
	return GetOwner()->FindComponentByClass<UPhysicsHandleComponent>(); 
}

//BLUEPRINT NATIVE EVENT
bool UGrabber::TraceForPhysicsBodies_Implementation(AActor*& HitActor, UPrimitiveComponent*& HitComponent)
{
	return false;
}