#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CostumPhysics")
	float Size = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CostumPhysics")
	float Weight = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CostumPhysics")
	float SurfaceRoughness = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CostumPhysics")
	float MaterialDensity = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CostumPhysics")
	FVector MassDistribution = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CostumPhysics")
	float Mass = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CostumPhysics")
	float Friction = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CostumPhysics")
	float Restitution = 0.8f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CostumPhysics")
	float AngularDamping = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CostumPhysics")
	TEnumAsByte<EFrictionCombineMode::Type> FrictionCombineMode = EFrictionCombineMode::Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CostumPhysics")
	TEnumAsByte<EFrictionCombineMode::Type> RestitutionCombineMode = EFrictionCombineMode::Max;

	
	void UpdatePhysicsProperties();
	UPhysicalMaterial* CreatePhysicsMaterial();
	// void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
