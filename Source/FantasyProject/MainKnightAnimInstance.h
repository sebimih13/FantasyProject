#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainKnightAnimInstance.generated.h"

/** Forward Declarations */
class APawn;
class AMainKnight;

UCLASS()
class FANTASYPROJECT_API UMainKnightAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;

	// Called every frame
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	bool bIsInAir;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	APawn* Pawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	AMainKnight* MainKnight;
};

