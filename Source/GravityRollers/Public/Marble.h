#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Marble.generated.h"

UCLASS()
class GRAVITYROLLERS_API AMarble : public AActor
{
	GENERATED_BODY()
	
public:
	AMarble();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* MarbleMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* InnerCore;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UParticleSystemComponent* TrailEffect;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Physics")
	float Size = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Physics")
	float Weight = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Physics")
	float SurfaceRoughness = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Physics")
	float MaterialDensity = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Physics")
	FVector MassDistribution = FVector(0.0f, 0.0f, 0.0f);
	
	void UpdatePhysicsProperties();
};
