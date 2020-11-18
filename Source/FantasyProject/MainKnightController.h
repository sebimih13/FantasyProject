#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainKnightController.generated.h"

/** Forward Declarations */
class UUserWidget;

UCLASS()
class FANTASYPROJECT_API AMainKnightController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:
	/** Reference to the UMG asset in the editor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> HUDOverlayAsset;

	/** Variable to hold the widget after creating it */
	UUserWidget* HUDOverlay;


};

