// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HEscapers.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class HESCAPERS_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

private:
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		USpotLightComponent* FlashLight;

	FVector CurrentVelocity;
	bool bFlash;

private:
	void Move_XAxis(float AxisValue);
	void Move_YAxis(float AxisValue);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void FlashLightSwitch();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
