// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Bewegungstyp auf Fliegen setzen
	GetCharacterMovement()->DefaultLandMovementMode = EMovementMode::MOVE_Flying;
	GetCharacterMovement()->SetMovementMode(MOVE_Flying);

	GetCharacterMovement()->BrakingDecelerationFlying = 99999.0f;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (PC)
	{
		PC->bShowMouseCursor = true;
		PC->bEnableClickEvents = true;
		PC->bEnableMouseOverEvents = true;
		PC->SetInputMode(FInputModeGameAndUI());
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &APlayerCharacter::MoveUp);

	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUpAtRate);

	PlayerInputComponent->BindAction("RightMouseRotate", IE_Pressed, this, &APlayerCharacter::StartMouseRotation);
	PlayerInputComponent->BindAction("RightMouseRotate", IE_Released, this, &APlayerCharacter::StopMouseRotation);
}

void APlayerCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0.0f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0.0f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::MoveUp(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(FVector::UpVector, Value);
	}
}

void APlayerCharacter::StartMouseRotation()
{
	bIsRotatingWithMouse = true;
}

void APlayerCharacter::StopMouseRotation()
{
	bIsRotatingWithMouse = false;
}

void APlayerCharacter::TurnAtRate(float Rate)
{
	if (bIsRotatingWithMouse)
	{
		AddControllerYawInput(Rate);
	}
}

void APlayerCharacter::LookUpAtRate(float Rate)
{
	if (bIsRotatingWithMouse)
	{
		AddControllerPitchInput(Rate);
	}
}

