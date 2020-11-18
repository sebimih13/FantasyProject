#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainKnight.generated.h"

/** Forward Declarations */
class USpringArmComponent;
class UCameraComponent;

/** Movement Status Enum */
UENUM(BlueprintType)
enum class EMovementStatus : uint8
{
	EMS_Normal			UMETA(DisplayName = "Normal"),
	EMS_Sprinting		UMETA(DisplayName = "Sprinting")
};

/** Stamina Status Enum */
UENUM(BlueprintType)
enum class EStaminaStatus : uint8
{
	ESS_Normal				 UMETA(DisplayName = "Normal"),
	ESS_BelowMinimum		 UMETA(DisplayName = "BelowMinimum"),
	ESS_Exhausted            UMETA(DisplayName = "Exhausted"),
	ESS_ExhaustedRecovering  UMETA(DisplayName = "ExhaustedRecovering")
};

UCLASS()
class FANTASYPROJECT_API AMainKnight : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainKnight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

public:
	/**										 Player Movement										*/

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	EMovementStatus MovementStatus;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Enums")
	EStaminaStatus StaminaStatus;

	/** Set Movement Status and Running Speed */
	void SetMovementStatus(EMovementStatus Status);

	FORCEINLINE void SetStaminaStatus(EStaminaStatus Status) { StaminaStatus = Status; }

	/** Properties for Stamina */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float StaminaDrainRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MinSprintStamina;

	void DrainStamina(float DeltaTime);

	/** Called for forward/backwards input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	bool bIsMovingForward;
	bool bIsMovingRight;

	/** Sprinting Functionality */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	bool bShiftKeyDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float WalkingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float SprintingSpeed;

	void ShiftKeyDown();
	void ShiftKeyUp();

	/**										 Player Stats										*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	float MaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	float Stamina;
};

