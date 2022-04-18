// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SpotLightComponent.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Create Components What I need
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	FlashLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Flash"));
	
	//init Heiarchy in Character
	Camera->SetupAttachment(RootComponent);
	FlashLight->SetupAttachment(Camera);

	//init Detail Options
	Camera->SetRelativeLocation(FVector(0.0f, 0.0f, GetCapsuleComponent()->GetScaledCapsuleHalfHeight() - 10));

	//Init Varaiable
	bFlash = false;
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Flash", IE_Pressed, this, &AMainCharacter::FlashLightSwitch);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMainCharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMainCharacter::StopJumping);


	InputComponent->BindAxis("MoveForward", this, &AMainCharacter::Move_XAxis);
	InputComponent->BindAxis("MoveRight", this, &AMainCharacter::Move_YAxis);
	InputComponent->BindAxis("Turn", this, &AMainCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AMainCharacter::AddControllerPitchInput);
}

#pragma region Movable Input
void AMainCharacter::Move_XAxis(float AxisValue) {
	AddMovementInput(GetActorForwardVector(), AxisValue);
}

void AMainCharacter::Move_YAxis(float AxisValue) {
	AddMovementInput(GetActorRightVector(), AxisValue);
}
#pragma endregion

void AMainCharacter::FlashLightSwitch() {
	bFlash = !bFlash;
	FlashLight->SetActive(bFlash);
}