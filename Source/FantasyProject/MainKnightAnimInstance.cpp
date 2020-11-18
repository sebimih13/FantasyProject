#include "MainKnightAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MainKnight.h"


void UMainKnightAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();

		MainKnight = Cast<AMainKnight>(Pawn);
	}
}

void UMainKnightAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}

	if (MainKnight == nullptr)
	{
		MainKnight = Cast<AMainKnight>(Pawn);
	}
	
	if (Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.0f);
		MovementSpeed = LateralSpeed.Size();

		bIsInAir = Pawn->GetMovementComponent()->IsFalling();
	}
}

